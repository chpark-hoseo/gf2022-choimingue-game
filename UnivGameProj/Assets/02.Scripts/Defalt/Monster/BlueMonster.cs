using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class BlueMonster : DumyMonster
{
    // Start is called before the first frame update
    void Start()
    {
        monsterType = MonsterType.MeleeMonster;

        Hp = 10;

        traceDist = 30.0f;
        attackDist = 0.2f;

        Damage = 2;

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
                    animator.SetBool("IsAttack", false);
                    break;

                // trace상태
                case MonsterState.Trace:
                    nvAgent.isStopped = false;                      // 추적을 시작하며
                    nvAgent.destination = playerTr.position;        // 추적의 목적지를 플레이어의 위치로 두고

                    animator.SetBool("IsTrace", true);              // IsTrace 변수를 true로 만든다.
                    animator.SetBool("IsAttack", false);            // IsAttack 변수를 false로 만든다.
                    break;

                // attack상태
                case MonsterState.Attack:
                    nvAgent.isStopped = true;                       // 추적을 멈추고

                    animator.SetBool("IsAttack", true);             // isAttack 변수를 true로 만든다.
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
