using System.Collections;
using System.Collections.Generic;
using UnityEngine;


public class Effect_Raycast_Laser : MonoBehaviour
{
    public int Dist = 200;
    public int damage = 4;
    public float Scale = 0.3f;
    private void OnTriggerEnter(Collider coll)
    {
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
}