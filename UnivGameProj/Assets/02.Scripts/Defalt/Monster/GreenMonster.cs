using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class GreenMonster : DumyMonster
{
    private float ChargeDist;                               // ���� ��Ÿ�

    private float defaultAccel;                             // �ʹ� ���ӵ�
    private float defaultMaxSpeed;                          // �ʹ� �ִ� �ӵ�

    private float ChargeAccel;                              // ���� �ӵ�
    private float ChargeMaxSpeed;                           // ���� �ִ� �ӵ�

    private int Count;

    private void Start()
    {
        monsterType = MonsterType.ChargeMonster;

        Count = 0;

        // <������ �⺻ ����>
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

                case MonsterState.Charge:

                    nvAgent.isStopped = false;                      // ������ �����ϸ�
                    nvAgent.destination = playerTr.position;        // ������ �������� �÷��̾��� ��ġ�� �ΰ�

                    animator.SetBool("IsTrace", true);              // IsTrace ������ true�� �����.
                    animator.SetBool("IsAttack", false);            // IsAttack ������ false�� �����.

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
