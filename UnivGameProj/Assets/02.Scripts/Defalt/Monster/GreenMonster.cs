using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GreenMonster : DumyMonster
{
    private float ChargeDist;                               // 돌진 사거리

    private float defaultAccel;                             // 초반 가속도
    private float defaultMaxSpeed;                          // 초반 최대 속도

    private float ChargeAccel;                              // 돌진 속도
    private float ChargeMaxSpeed;                           // 돌진 최대 속도

    private int Count;

    private void Start()
    {
        monsterType = MonsterType.ChargeMonster;

        Count = 0;

        // <몬스터의 기본 스탯>
        Hp = 15;

        defaultAccel = 8.0f;
        defaultMaxSpeed = 10.0f;

        ChargeAccel = 35.0f;
        ChargeMaxSpeed = 60.0f;

        traceDist = 30.0f;
        ChargeDist = 15.0f;
        attackDist = 2f;

        Damage = 3;

        base.Start();
    }

    protected override IEnumerator CheckMonsterState()
    {
        while (!IsDie)
        {
            yield return new WaitForSeconds(0.2f);

            float dist = Vector3.Distance(playerTr.position, monsterTr.position);

            if (dist <= attackDist)
            {
            }
            else if (dist <= ChargeDist)
            {
                monsterState = MonsterState.Charge;
                nvAgent.acceleration = ChargeAccel;
                nvAgent.speed = ChargeMaxSpeed;
            }
            else if (dist <= traceDist)
            {
                monsterState = MonsterState.Trace;
                nvAgent.acceleration = defaultAccel;
                nvAgent.speed = defaultMaxSpeed;
            }
            else
            {
                monsterState = MonsterState.Idle;
                nvAgent.acceleration = defaultAccel;
                nvAgent.speed = defaultMaxSpeed;
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
                    animator.SetBool("IsAttack", false);
                    break;

                // trace상태
                case MonsterState.Trace:
                    nvAgent.isStopped = false;                      // 추적을 시작하며
                    nvAgent.destination = playerTr.position;        // 추적의 목적지를 플레이어의 위치로 두고

                    animator.SetBool("IsTrace", true);              // IsTrace 변수를 true로 만든다.
                    animator.SetBool("IsAttack", false);            // IsAttack 변수를 false로 만든다.
                    break;

                case MonsterState.Charge:

                    nvAgent.isStopped = false;                      // 추적을 시작하며
                    nvAgent.destination = playerTr.position;        // 추적의 목적지를 플레이어의 위치로 두고

                    animator.SetBool("IsTrace", true);              // IsTrace 변수를 true로 만든다.
                    animator.SetBool("IsAttack", false);            // IsAttack 변수를 false로 만든다.

                    if (++Count >= 180)
                    {
                        monsterState = MonsterState.Idle;
                        nvAgent.isStopped = true;
                        Count = 0;
                        yield return new WaitForSeconds(1.0f);
                    }
                    break;
            }

            yield return null;
        }
    }

    private void OnTriggerEnter(Collider coll)
    {
        base.GetDamage_Melee(coll);
    }
}
