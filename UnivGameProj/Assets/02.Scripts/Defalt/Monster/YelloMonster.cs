using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class YelloMonster : DumyMonster
{
    public GameObject Player;

    public GameObject CannonBall;
    public GameObject MissilePos;

    private int ReRoadCount = 0;

    // Start is called before the first frame update
    void Start()
    {
        Player = GameObject.FindGameObjectWithTag("Player");

        monsterType = MonsterType.ADMonster;

        Hp = 8;

        traceDist = 40.0f;
        attackDist = 25.0f;

        Damage = 5;

        base.Start();
    }

    // Update is called once per frame
    protected override IEnumerator CheckMonsterState()
    {
        while (!IsDie)
        {
            yield return new WaitForSeconds(0.2f);

            float dist = Vector3.Distance(playerTr.position, monsterTr.position);

            if (dist <= attackDist)
            {
                monsterState = MonsterState.Attack;
            }
            else if (dist <= traceDist)
            {
                monsterState = MonsterState.Trace;
            }
            else
            {
                monsterState = MonsterState.Idle;
            }
        }
    }

    protected override IEnumerator MonsterAction()
    {
        while (!IsDie)
        {
            switch (monsterState)
            {
                //idle 상태
                case MonsterState.Idle:
                    nvAgent.isStopped = true;                       // 추적을 멈추고

                    animator.SetBool("IsTrace", false);             // IsTrace 변수를 false로 만든다.
                    break;

                // trace상태
                case MonsterState.Trace:
                    nvAgent.isStopped = false;                      // 추적을 시작하며
                    nvAgent.destination = playerTr.position;        // 추적의 목적지를 플레이어의 위치로 두고

                    animator.SetBool("IsTrace", true);              // IsTrace 변수를 true로 만든다.
                    break;

                // attack상태
                case MonsterState.Attack:
                    nvAgent.isStopped = true;
                    animator.SetTrigger("YellowAtt");

                    if (++ReRoadCount >= 120)
                    {
                        yield return new WaitForSeconds(0.8f);
                        CreateCannon();
                        ReRoadCount = 0;
                    }

                    break;
            }

            yield return null;
        }
    }

    private void Update()
    {
        print("Monster Hp : ");
        print(Hp);

        if( monsterState == MonsterState.Attack)
        {
            transform.LookAt(Player.transform);
        }
    }

    void CreateCannon()
    {
        Instantiate(CannonBall, MissilePos.transform.position, MissilePos.transform.rotation);
    }

    private void OnCollisionEnter(Collision collision)
    {
        base.GetDamage_AD(collision);
    }

}
