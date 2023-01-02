using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    //��� ����--------------------------------------------------------
    public Transform targetTr;      //������ Ÿ�� ���ӿ�����Ʈ�� Transform ����

    public float dist = 20.0f;                //ī�޶���� ���� �Ÿ�
    public const float height = 2.0f;        //ī�޶��� ���� ����

    public float dampTrace = 20.0f;          //�ε巯�� ������ ���� ����

    private Transform Mytr;           //ī�޶� �ڽ��� Transform ����

    //��� �Լ� ---------------------------------------------------------------
    //�� ��ũ��Ʈ�� ����ɶ� ó�� �ѹ� ȣ���
    void Start()
    {
        DontDestroyOnLoad(this);

        //ī�޶� �ڽ��� Transform ������Ʈ�� tr�� �Ҵ�
        Mytr = GetComponent<Transform>();
        targetTr = GameObject.Find("Player").transform;
    }

    // LateUpdate = Update() �Լ� ȣ�� ���� �ѹ��� ȣ��Ǵ� �Լ��� LateUpdate ���
    // ������ Ÿ���� �̵��� ����� ���Ŀ� ī�޶� �����ϱ� ���� LateUpdate ���
    void LateUpdate()
    {
        //ī�޶��� ��ġ�� ���� ����� dist ���� ��ŭ �������� ��ġ��(height ���� ��ŭ ���� �ø�)
        Mytr.position = Vector3.Lerp(Mytr.position, //���� ��ġ
                                   targetTr.position - (targetTr.forward * dist) + (Vector3.up * height), //���� ��ġ
                                   Time.deltaTime * dampTrace); //���� �ð�

        //ī�޶� Ÿ�� ���ӿ�����Ʈ�� �ٶ󺸰� ����
        Mytr.LookAt(targetTr.position);
    }
}
