using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class WallCtrl : MonoBehaviour
{
    public GameObject BoomEffect;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {
        
    }

    private void OnTriggerEnter(Collider coll)
    {
        if (coll.gameObject.tag == "CANNON")
        {
            GameObject Boom = (GameObject)Instantiate(BoomEffect, coll.transform.position, Quaternion.identity);
            Destroy(Boom, Boom.GetComponent<ParticleSystem>().duration + 0.2f);
            Destroy(coll.gameObject);
        }
    }

    private void OnCollisionEnter(Collision coll)
    {
        if (coll.collider.tag == "BULLET")
        {
            Destroy(coll.gameObject);
        }
    }
}
