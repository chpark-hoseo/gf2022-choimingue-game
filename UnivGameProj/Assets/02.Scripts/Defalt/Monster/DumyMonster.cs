using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

abstract public class DumyMonster : MonoBehaviour
{
    public enum MonsterState { Idle, Trace, Charge, Attack, Die };
    public MonsterState monsterState = MonsterState.Idle;                       // 초기값을 idle로 만들어줌

    public enum MonsterType { ChargeMonster, MeleeMonster, ADMonster};
    public MonsterType monsterType;

    protected Transform monsterTr;
    protected Transform playerTr;
    protected UnityEngine.AI.NavMeshAgent nvAgent;
    protected Animator animator;

    // <몬스터 기본 스탯>
    public int Hp = 10;
    public int Damage;
    protected float traceDist;                                             // 추적 사거리 10
    protected float attackDist;                                            // 공격 사거리

    protected bool IsDie = false;

    // Start is called before the first frame update
    protected void Start()
    {
        monsterTr = this.gameObject.GetComponent<Transform>();
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();                      // 플레이어 태그를 사용해 위치를 추적

        nvAgent = this.gameObject.GetComponent<NavMeshAgent>();

        animator = this.gameObject.GetComponent<Animator>();

        StartCoroutine(this.CheckMonsterState());
        StartCoroutine(this.MonsterAction());
    }

    abstract protected IEnumerator CheckMonsterState();

    abstract protected IEnumerator MonsterAction();

    public void SetHp(int Damage)
    {
        Hp -= Damage;

        if(Hp <= 0)
        {
            MonsterDie();
        }
    }

    protected void GetDamage_AD(Collision coll)
    {
        if (coll.gameObject.tag == "BULLET")
        {
            SetHp(coll.gameObject.GetComponent<BulletCtrl>().damage);
            Destroy(coll.gameObject);
        }
    }
    protected void GetDamage_Melee(Collider coll)
    {
        if (coll.gameObject.tag == "BULLET")
        {
            SetHp(coll.gameObject.GetComponent<BulletCtrl>().damage);
            Destroy(coll.gameObject);
            print("맞았음 좋겠네!");
        }
    }

    protected void OnCollisionEnter(Collision coll)
    {
        if (coll.gameObject.tag == "BULLET")
        {
            SetHp(coll.gameObject.GetComponent<BulletCtrl>().damage);
            Destroy(coll.gameObject);
        }
    }

    protected void MonsterDie()
    {
        StopAllCoroutines();

        IsDie= true;
        monsterState = MonsterState.Idle;
        nvAgent.isStopped = true;
        animator.SetTrigger("IsDie");

        gameObject.GetComponentInChildren<BoxCollider>().enabled = false;

        Destroy(gameObject, 5.0f);
    }
}
