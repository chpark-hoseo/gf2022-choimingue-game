using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FollowCam : MonoBehaviour
{
    //멤버 변수--------------------------------------------------------
    public Transform targetTr;      //추적할 타깃 게임오브젝트의 Transform 변수

    public float dist = 20.0f;                //카메라와의 일정 거리
    public const float height = 2.0f;        //카메라의 높이 설정

    public float dampTrace = 20.0f;          //부드러운 추적을 위한 변수

    private Transform Mytr;           //카메라 자신의 Transform 변수

    //멤버 함수 ---------------------------------------------------------------
    //이 스크립트가 실행될때 처음 한번 호출됨
    void Start()
    {
        DontDestroyOnLoad(this);

        //카메라 자신의 Transform 컴포넌트를 tr에 할당
        Mytr = GetComponent<Transform>();
        targetTr = GameObject.Find("Player").transform;
    }

    // LateUpdate = Update() 함수 호출 이후 한번씩 호출되는 함수인 LateUpdate 사용
    // 추적할 타깃의 이동이 종료된 이후에 카메라가 추적하기 위해 LateUpdate 사용
    void LateUpdate()
    {
        //카메라의 위치를 추적 대상의 dist 변수 만큼 뒤쪽으로 배치함(height 변수 만큼 위로 올림)
        Mytr.position = Vector3.Lerp(Mytr.position, //시작 위치
                                   targetTr.position - (targetTr.forward * dist) + (Vector3.up * height), //종료 위치
                                   Time.deltaTime * dampTrace); //보간 시간

        //카메라가 타깃 게임오브젝트를 바라보게 설정
        Mytr.LookAt(targetTr.position);
    }
}
