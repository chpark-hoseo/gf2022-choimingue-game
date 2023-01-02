using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.AI;

abstract public class DumyMonster : MonoBehaviour
{
    public enum MonsterState { Idle, Trace, Charge, Attack, Die };
    public MonsterState monsterState = MonsterState.Idle;                       // �ʱⰪ�� idle�� �������

    public enum MonsterType { ChargeMonster, MeleeMonster, ADMonster};
    public MonsterType monsterType;

    protected Transform monsterTr;
    protected Transform playerTr;
    protected UnityEngine.AI.NavMeshAgent nvAgent;
    protected Animator animator;

    // <���� �⺻ ����>
    public int Hp = 10;
    public int Damage;
    protected float traceDist;                                             // ���� ��Ÿ� 10
    protected float attackDist;                                            // ���� ��Ÿ�

    protected bool IsDie = false;

    // Start is called before the first frame update
    protected void Start()
    {
        monsterTr = this.gameObject.GetComponent<Transform>();
        playerTr = GameObject.FindWithTag("Player").GetComponent<Transform>();                      // �÷��̾� �±׸� ����� ��ġ�� ����

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
            print("�¾��� ���ڳ�!");
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
