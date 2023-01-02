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
        // ���콺 ������ �ٶ������, �ö󰡴� �ӵ�
        float xDelta = rotSpeed * Time.deltaTime * Input.GetAxis("Mouse Y");
        float xCurrent = tr.transform.eulerAngles.x;            // ���� x����

        // x�� �⺻ ������ 360�� �̹Ƿ�, -360������, 0���� �����ؾ���
        if (xCurrent > 180f)
            xCurrent -= 360f;

        float xNext = xCurrent + xDelta;    // ���� �ö� ����

        // ���� ���� ���� õõ�� ��������.
        if (xNext > minrot) xDelta = minrot - xCurrent;
        if (xNext < maxrot) xDelta = maxrot - xCurrent;

        tr.Rotate(Vector3.right * xDelta);
    }
}