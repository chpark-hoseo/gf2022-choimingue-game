using System.Collections;
using System.Collections.Generic;
using UnityEditor.SearchService;
using UnityEngine;
using UnityEngine.SceneManagement;

public class playerCtrl : MonoBehaviour
{
    public int PlayerMaxHP = 100;
    public int PlayerCurHP;
    public bool IsHit = false;

    public GameObject BoomEffect;

    public enum Gun{ DefaultGun = 1, GrenadeGun =2, LaserGun =3 }
    public int GunType = 1;

    public GameObject Default_Gun;
    public GameObject Grenade_Gun;
    public GameObject Laser_Gun;

    public int Get_GunType() { return GunType; }

    private float h = 0.0f;
    private float v = 0.0f;

    private Transform Mytr;              //�����ؾ� �ϴ� ������Ʈ�� �ݵ�� ������ �Ҵ� �� �� ���
    private Rigidbody Myrigid;

    public float moveSpeed = 5.0f;     //�̵��ӵ� ����
    public float speedChange = 1.0f;   //�̵��ӵ� ���� ����
    public float rotSpeed = 500.0f;    //ȸ���ӵ� ����

    private Animator anim;

    private int KnockB_Count = 0;


    // Start is called before the first frame update
    void Start()
    {
        DontDestroyOnLoad(this);

        PlayerCurHP = PlayerMaxHP;

        //��ũ��Ʈ ó���� Transform ������Ʈ �Ҵ�
        Mytr = GetComponent<Transform>();
        Myrigid = GetComponent<Rigidbody>();
        anim = GetComponentInChildren<Animator>();

        // �ʱ� ���̿ܿ��� ��� ��Ȱ��ȭ
        Default_Gun.SetActive(true);
        Grenade_Gun.SetActive(false);
        Laser_Gun.SetActive(false);

        // ������ �Լ�
        if (false)
        {
            SetThrowTrigger();
            SetIsShootTrigger();
        }
    }

    // Update is called once per frame
    void Update()
    {
        Move();
        Rotate();

        Get_GunType();
        Gun_KeySetting();

        if(PlayerCurHP <= 0)
        {
#if UNITY_EDITOR
            UnityEditor.EditorApplication.isPlaying = false;
#elif UNITY_WEBPLAYER
         Application.OpenURL(webplayerQuitURL);
#else
         Application.Quit();
#endif
        }
    }

    public void Move()
    {
        h = Input.GetAxis("Horizontal");    //A, D, Left, Right �� ��������
        v = Input.GetAxis("Vertical");      //W, D, Up, Down Ű�� ��������

        //�� �� �� �� �̵� ���� ���� ���
        Vector3 moveDir = (Vector3.forward * v) + (Vector3.right * h);

        if (Input.GetKey(KeyCode.LeftControl))
        {
            speedChange = 1.5f;
        }

        else if (Input.GetKey(KeyCode.LeftShift))
        {
            speedChange = 0.5f;
        }

        else
        {
            speedChange = 1.0f;
        }

        AniCtrl();

        //Translate(�̵� ���� * �ӵ� * ������ * Time.deltaTime, ���� ��ǥ)
        Mytr.Translate(moveDir.normalized * Time.deltaTime * moveSpeed * speedChange, Space.Self);

    }

    public void Rotate()
    {
        //Vector3.up ���� �������� rotSpeed��ŭ�� �ӵ��� ȸ��
        Mytr.Rotate(Vector3.up * Time.deltaTime * rotSpeed * Input.GetAxis("Mouse X"));
    }

    public void AniCtrl()
    {
        //�ִϸ��̼� ����--
        if (h == 0 && v == 0)
        {
            anim.SetBool("IsWalk", false);
            anim.SetBool("IsRun", false);
        }

        else
        {
            if (speedChange < 1.5)
            {
                anim.SetBool("IsWalk", true);
                anim.SetBool("IsRun", false);
            }

            else
            {
                anim.SetBool("IsRun", true);
            }
        }
    }

    public void Gun_KeySetting()
    {
        if(Input.GetKey(KeyCode.Alpha1))
        {
            GunType = (int)Gun.DefaultGun;
        }

        else if (Input.GetKey(KeyCode.Alpha2))
        {
            GunType = (int)Gun.GrenadeGun;
        }

        else if (Input.GetKey(KeyCode.Alpha3))
        {
            GunType = (int)Gun.LaserGun;
        }

        SelectGun();
    }

    public void SelectGun()
    {
        if (GunType == (int)Gun.DefaultGun)
        {
            Default_Gun.SetActive(true);
            Grenade_Gun.SetActive(false);
            Laser_Gun.SetActive(false);
        }
        else if (GunType == (int)Gun.GrenadeGun)
        {
            Default_Gun.SetActive(false);
            Laser_Gun.SetActive(false);
            Grenade_Gun.SetActive(true);
        }
        else if(GunType == (int)Gun.LaserGun)
        {
            Default_Gun.SetActive(false);
            Grenade_Gun.SetActive(false);
            Laser_Gun.SetActive(true);
        }
    }

    public void SetThrowTrigger()
    {
        anim.SetTrigger("IsThrow");
    }

    public void SetIsShootTrigger()
    {
        anim.SetTrigger("IsShooting");
    }

    // <���� ��ü�� ���� ��ġ��>
    private void OnTriggerEnter(Collider coll)
    {
        DamgeByMonster(coll);
    }

    private void OnTriggerStay(Collider coll)
    {
        DamgeByMonster(coll);
    }

    void DamgeByMonster(Collider coll)
    {
        if (coll.gameObject.tag == "MONSTER")
        {
            while (++KnockB_Count < 10)
                Mytr.Translate(-Vector3.forward.normalized * Time.deltaTime, Space.Self);
            

            KnockB_Count = 0;

            if (!IsHit)
            {
                switch (coll.gameObject.GetComponent<DumyMonster>().monsterType)
                {
                    case DumyMonster.MonsterType.ChargeMonster:
                        PlayerCurHP -= coll.gameObject.GetComponent<GreenMonster>().Damage;
                        break;

                    case DumyMonster.MonsterType.MeleeMonster:
                        PlayerCurHP -= coll.gameObject.GetComponent<BlueMonster>().Damage;
                        break;

                    default:
                        print("���� �߻�!");
                        break;
                }
            }
        }
        else if (coll.gameObject.tag == "CANNON")
        {

            PlayerCurHP -= coll.gameObject.GetComponent<CannonCtrl>().damage;
            print(PlayerCurHP);

            GameObject Boom = (GameObject)Instantiate(BoomEffect, coll.transform.position, Quaternion.identity);
            Destroy(Boom, Boom.GetComponent<ParticleSystem>().duration + 0.2f);
            Destroy(coll.gameObject);
        }

        StartCoroutine(this.OnDamge());
    }

    public IEnumerator OnDamge()
    {
        IsHit = true;

        yield return new WaitForSeconds(1f);

        IsHit = false;
    }
}
