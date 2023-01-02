using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FirePos : MonoBehaviour
{
    public GameObject CannonBall;
    private Transform MyTr;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        Instantiate(CannonBall, MyTr.position, MyTr.rotation);
    }
}
