using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CannonCtrl : MonoBehaviour
{
    public int damage = 5;
    public float speed = 700.0f;


    // Start is called before the first frame update
    void Start()
    {
        GetComponent<Rigidbody>().AddForce(transform.forward * speed);
    }

    // Update is called once per frame
    void Update()
    {
        transform.Rotate(Vector3.forward * 720 * Time.deltaTime);
    }
}
