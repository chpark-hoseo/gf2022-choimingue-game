using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireCtrl : MonoBehaviour
{
    public enum Gun { DefaultGun = 1, GrenadeGun = 2, LaserGun = 3 }

    public GameObject Player;                    // �÷��̾� ������Ʈ�� ���� ������ �������� ����
    int Player_GunType = 1;                      // �÷��̾��� �� ����

    public GameObject User_Grenade;              // ������ ����ִ� ����ź

    public GameObject bullet;                    // �Ѿ� ������Ʈ
    public GameObject grenade;                   // ��ź ������Ʈ
    public GameObject laser;                     // ������ ������Ʈ

    public GameObject laserScale;                // ������ ���� ��ġ (Dumy)

    public int Dist = 200;

    public float Scale = 0.3f;
    
    public Transform MyTr;                            // �߻� ��ġ

    private const int BulletReFireTime = 60;          // �Ѿ��� �߻��ϱ���� �ɸ��� �ð� (1��)
    private const int GrenadeReFireTime = 640;        // ��ź�� �߻��ϱ���� �ɸ��� �ð� (6��)
    private const int LaserReFireTime = 240;          // �������� �߻��ϱ���� �ɸ��� �ð� (4��)

    private const int GrandeDelayTime = 180;          // ����ź�� �����ϱ� ������ �ð� 4��

    private const int LaserDelayTime = 120;            // �������� ����������� �ð� (0�� ~ 2��)
    private const int ActiveLaserTime = 180;           // �������� ��µǴ� �ð� (2�� ~ 3��)

    private int LDealayCount = 0;                      // �������� ����������� �ð��� ī����
    private int GDealayCount = 0;                      // ����ź�� ����������� �ð��� ī����

    private int ReFire_Count = 0;                     // �������� ��ٸ��� �ð�
    private bool IsFire = true;                       // �ð��� �Ǹ�, �߻� �������� �˷���

    private bool IsGrandeThrow = false;               // ����ź�� ���������� Ȯ��
    private bool IsLaserFire = false;                // �������� �߻��ߴ��� Ȯ��


    private void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        SelectFire();
    }

    void SelectFire()
    {
        Player_GunType = Player.GetComponent<playerCtrl>().Get_GunType();

        // �Ѿ�
        if (Player_GunType == (int)Gun.DefaultGun)
        {
            laser.SetActive(false);

            // ���� ���ð��� ��ٸ�
            if (ReFire_Count >= BulletReFireTime)
            {
                IsFire = true;
            }

            if (Input.GetMouseButtonDown(0) && IsFire)
            {
                Player.GetComponent<playerCtrl>().SetIsShootTrigger();
                CreateBullet();
                ReFire_Count = 0;
                IsFire = false;
            }
        }

        // ����ź
        else if (Player_GunType == (int)Gun.GrenadeGun)
        {
            laser.SetActive(false);

            // ���� ���ð��� ��ٸ�
            if (ReFire_Count >= GrenadeReFireTime)
            {
                IsFire = true;
            }

            if (IsFire)
            {
                // ����ź�� ���� �� �ִٸ�, ������ �տ� ����� ����ź�� Ȱ��ȭ
                User_Grenade.SetActive(true);

                if (Input.GetMouseButtonDown(0))
                {
                    Player.GetComponent<playerCtrl>().SetThrowTrigger();
                    User_Grenade.SetActive(false);
                    IsGrandeThrow = true;
                }
            }

            // ������ ��� ��, �߻��ϴ� �ڵ�
            if (IsGrandeThrow)
            {
                GDealayCount++;

                if (GDealayCount >= GrandeDelayTime)
                {
                    CreateGrenade();

                    ReFire_Count = 0;
                    IsFire = false;

                    IsGrandeThrow = false;
                    GDealayCount = 0;
                }
            }

        }

        // ������
        else if (Player_GunType == (int)Gun.LaserGun)
        {

            // ���� ���ð��� ��ٸ��� �ڵ�
            if (ReFire_Count >= LaserReFireTime)
            {
                IsFire = true;
            }

            if (Input.GetMouseButtonDown(0) && IsFire)
            {
                IsLaserFire = true;
            }

            // �߻� ��ư�� ��������, Ȱ��ȭ�� ����
            if (IsLaserFire)
            {
                LDealayCount++;

                if (LDealayCount < LaserDelayTime)
                {
                    Player.GetComponent<playerCtrl>().SetIsShootTrigger();
                }

                // �����ð� ���ȿ��� 
                else if (LDealayCount >= LaserDelayTime
                    && LDealayCount < ActiveLaserTime)
                {
                    CreateLaser();
                    laser.SetActive(true);

                    Debug.Log("GG");
                }

                else if (LDealayCount >= ActiveLaserTime)
                {
                    laser.SetActive(false);
                    IsLaserFire = false;

                    IsFire = false;
                    ReFire_Count = 0;
                    LDealayCount = 0;
                }
            }

        }

        ReFire_Count++;
    }

    void CreateBullet()
    {
        Instantiate(bullet, MyTr.position, MyTr.rotation);
    }

    void CreateGrenade()
    {
        Instantiate(grenade, MyTr.position, MyTr.rotation);
        Debug.Log("Gran");
    }

    void CreateLaser()
    {
        Debug.Log("Laser");

        RaycastHit hit;
        int layMask = 1 << LayerMask.NameToLayer("Wall");
        if (Physics.Raycast(transform.position, transform.forward, out hit, Mathf.Infinity, layMask))
        {
            print("�� ����!");
            laserScale.transform.localScale = new Vector3(Scale, hit.distance, Scale);
            laserScale.transform.localPosition = new Vector3(0, 0, hit.distance / 2);
        }
        else
        {
            print("���� ����!");
        }
        laser.SetActive(true);
    }

}
