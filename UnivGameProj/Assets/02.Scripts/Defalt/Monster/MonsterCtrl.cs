using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class MonsterCtrl : MonoBehaviour
{
    public enum MonsterState { Idle, Trace, Attack, Die };
    public MonsterState monsterState = MonsterState.Idle;                       // �ʱⰪ�� idle�� �������

    private Transform monsterTr;
    private Transform playerTr;
    private UnityEngine.AI.NavMeshAgent nvAgent;
    private Animator animator;

    public float traceDist = 10.0f;                                             // ���� ��Ÿ� 10
    public float attackDist = 2f;                                               // ���� ��Ÿ�
    private bool IsDie = false;

    public int Hp = 100;

    // Start is called before the first frame update
    void Start()
    {
        monsterTr = this.gameObject.GetComponent<Transform>();
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();                      // �÷��̾� �±׸� ����� ��ġ�� ����
        
        nvAgent = this.gameObject.GetComponent<NavMeshAgent>();

        animator = this.gameObject.GetComponent<Animator>();
        StartCoroutine(this.CheckMonsterState());
        StartCoroutine(this.MonsterAction());
    }
    IEnumerator CheckMonsterState()
    {
        while(!IsDie)
        {
            yield return new WaitForSeconds(0.2f);

            float dist = Vector3.Distance(playerTr.position, monsterTr.position);

            if(dist <= attackDist)
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

    IEnumerator MonsterAction()
    {
        while(!IsDie)
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
}
