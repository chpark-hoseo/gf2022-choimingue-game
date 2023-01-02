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
                //idle ����
                case MonsterState.Idle:
                    nvAgent.isStopped = true;                       // ������ ���߰�

                    animator.SetBool("IsTrace", false);             // IsTrace ������ false�� �����.
                    animator.SetBool("IsAttack", false);
                    break;

                // trace����
                case MonsterState.Trace:
                    nvAgent.isStopped = false;                      // ������ �����ϸ�
                    nvAgent.destination = playerTr.position;        // ������ �������� �÷��̾��� ��ġ�� �ΰ�

                    animator.SetBool("IsTrace", true);              // IsTrace ������ true�� �����.
                    animator.SetBool("IsAttack", false);            // IsAttack ������ false�� �����.
                    break;

                // attack����
                case MonsterState.Attack:
                    nvAgent.isStopped = true;                       // ������ ���߰�

                    animator.SetBool("IsAttack", true);             // isAttack ������ true�� �����.
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
