using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GranadeCtrl : MonoBehaviour
{
    public int damage = 6;

    public float speed = 3000.0f;
    public float UpSpeed = 1000.0f;

    public GameObject expEffect;                // 폭발 효과
    private const int expTime = 1020;            // 폭발하기까지 걸리는 시간 (3초)
    private int expCount = 0;                   // 폭발 시간을 재는 변수

    private const float expRadius = 8f;        // 폭발 반경 = 10
    private const float expForce = 1000f;       // 폭발 힘 = 1000

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
        GameObject explosion =  Instantiate(expEffect, transform.position, Quaternion.identity);                 // 폭발 이팩트 생성

        Collider[] colls = Physics.OverlapSphere(transform.position, expRadius);         // 범위내에 모든 오브젝트를 가져옴

        foreach(Collider coll in colls)
        {
            Rigidbody rbody = coll.GetComponent<Rigidbody>();                            // 범위내 모든 리지드 바디를 가져옴

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
                        print("버그 발생!");
                        break;
                }
            }
        }

        expCount = 0;
        Destroy(explosion, explosion.GetComponent<ParticleSystem>().duration);
        Destroy(gameObject);
    }
}
