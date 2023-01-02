using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

public class MonsterCtrl : MonoBehaviour
{
    public enum MonsterState { Idle, Trace, Attack, Die };
    public MonsterState monsterState = MonsterState.Idle;                       // 초기값을 idle로 만들어줌

    private Transform monsterTr;
    private Transform playerTr;
    private UnityEngine.AI.NavMeshAgent nvAgent;
    private Animator animator;

    public float traceDist = 10.0f;                                             // 추적 사거리 10
    public float attackDist = 2f;                                               // 공격 사거리
    private bool IsDie = false;

    public int Hp = 100;

    // Start is called before the first frame update
    void Start()
    {
        monsterTr = this.gameObject.GetComponent<Transform>();
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();                      // 플레이어 태그를 사용해 위치를 추적
        
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
}
