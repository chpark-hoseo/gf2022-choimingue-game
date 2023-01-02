using System.Collections;
using System.Collections.Generic;
using UnityEngine;
public class CamTg : MonoBehaviour
{
    private Transform tr;
    private const float rotSpeed = -300.0f;
    private float minrot = 40.0f;
    private float maxrot = -40.0f;

    // Start is called before the first frame update
    void Start()
    {
        tr = GetComponent<Transform>();
    }

    // Update is called once per frame
    void Update()
    {
        // 마우스 위쪽을 바라봤을때, 올라가는 속도
        float xDelta = rotSpeed * Time.deltaTime * Input.GetAxis("Mouse Y");
        float xCurrent = tr.transform.eulerAngles.x;            // 현재 x각도

        // x의 기본 각도는 360도 이므로, -360을빼서, 0으로 진행해야함
        if (xCurrent > 180f)
            xCurrent -= 360f;

        float xNext = xCurrent + xDelta;    // 다음 올라갈 각도

        // 다음 값을 구해 천천히 내려간다.
        if (xNext > minrot) xDelta = minrot - xCurrent;
        if (xNext < maxrot) xDelta = maxrot - xCurrent;

        tr.Rotate(Vector3.right * xDelta);
    }
}