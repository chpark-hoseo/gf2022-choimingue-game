using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GranadeCtrl : MonoBehaviour
{
    public int damage = 6;

    public float speed = 3000.0f;
    public float UpSpeed = 1000.0f;

    public GameObject expEffect;                // ���� ȿ��
    private const int expTime = 1020;            // �����ϱ���� �ɸ��� �ð� (3��)
    private int expCount = 0;                   // ���� �ð��� ��� ����

    private const float expRadius = 8f;        // ���� �ݰ� = 10
    private const float expForce = 1000f;       // ���� �� = 1000

    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Rigidbody>().AddForce(transform.forward * speed + transform.up * UpSpeed);
    }

    // Update is called once per frame
    void Update()
    {
        if (++expCount == expTime)
        {
            ExpGrande();
        }
    }

    void ExpGrande()
    {   
        GameObject explosion =  Instantiate(expEffect, transform.position, Quaternion.identity);                 // ���� ����Ʈ ����

        Collider[] colls = Physics.OverlapSphere(transform.position, expRadius);         // �������� ��� ������Ʈ�� ������

        foreach(Collider coll in colls)
        {
            Rigidbody rbody = coll.GetComponent<Rigidbody>();                            // ������ ��� ������ �ٵ� ������

            if (coll.gameObject.tag != "Player")
            {
                if (rbody != null)
                {
                    rbody.mass = 1f;
                    rbody.AddExplosionForce(expForce, transform.position, expRadius, 300f);
                }
            }

            if (coll.gameObject.tag == "MONSTER")
            {
                switch (coll.gameObject.GetComponent<DumyMonster>().monsterType)
                {
                    case DumyMonster.MonsterType.ChargeMonster:
                        coll.gameObject.GetComponent<GreenMonster>().SetHp(damage);
                        break;

                    case DumyMonster.MonsterType.MeleeMonster:
                        coll.gameObject.GetComponent<BlueMonster>().SetHp(damage);
                        break;

                    case DumyMonster.MonsterType.ADMonster:
                        coll.gameObject.GetComponent<YelloMonster>().SetHp(damage);
                        break;

                    default:
                        print("���� �߻�!");
                        break;
                }
            }
        }

        expCount = 0;
        Destroy(explosion, explosion.GetComponent<ParticleSystem>().duration);
        Destroy(gameObject);
    }
}
