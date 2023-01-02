using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class FireCtrl : MonoBehaviour
{
    public enum Gun { DefaultGun = 1, GrenadeGun = 2, LaserGun = 3 }

    public GameObject Player;                    // 플레이어 오브젝트의 총의 종류를 가져오기 위함
    int Player_GunType = 1;                      // 플레이어의 총 정보

    public GameObject User_Grenade;              // 유저가 들고있는 수류탄

    public GameObject bullet;                    // 총알 오브젝트
    public GameObject grenade;                   // 유탄 오브젝트
    public GameObject laser;                     // 레이저 오브젝트

    public GameObject laserScale;                // 레이저 생성 위치 (Dumy)

    public int Dist = 200;

    public float Scale = 0.3f;
    
    public Transform MyTr;                            // 발사 위치

    private const int BulletReFireTime = 60;          // 총알을 발사하기까지 걸리는 시간 (1초)
    private const int GrenadeReFireTime = 640;        // 유탄을 발사하기까지 걸리는 시간 (6초)
    private const int LaserReFireTime = 240;          // 레이지를 발사하기까지 걸리는 시간 (4초)

    private const int GrandeDelayTime = 180;          // 수류탄이 폭발하기 까지의 시간 4초

    private const int LaserDelayTime = 120;            // 레이저가 나가기까지의 시간 (0초 ~ 2초)
    private const int ActiveLaserTime = 180;           // 레이저가 출력되는 시간 (2초 ~ 3초)

    private int LDealayCount = 0;                      // 레이저가 나가기까지의 시간을 카운팅
    private int GDealayCount = 0;                      // 수류탄이 나가기까지의 시간을 카운팅

    private int ReFire_Count = 0;                     // 재장전을 기다리는 시간
    private bool IsFire = true;                       // 시간이 되면, 발사 가능한지 알려줌

    private bool IsGrandeThrow = false;               // 수류탄이 던져졌는지 확인
    private bool IsLaserFire = false;                // 레이저를 발사했는지 확인


    private void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        SelectFire();
    }

    void SelectFire()
    {
        Player_GunType = Player.GetComponent<playerCtrl>().Get_GunType();

        // 총알
        if (Player_GunType == (int)Gun.DefaultGun)
        {
            laser.SetActive(false);

            // 재사용 대기시간을 기다림
            if (ReFire_Count >= BulletReFireTime)
            {
                IsFire = true;
            }

            if (Input.GetMouseButtonDown(0) && IsFire)
            {
                Player.GetComponent<playerCtrl>().SetIsShootTrigger();
                CreateBullet();
                ReFire_Count = 0;
                IsFire = false;
            }
        }

        // 수류탄
        else if (Player_GunType == (int)Gun.GrenadeGun)
        {
            laser.SetActive(false);

            // 재사용 대기시간을 기다림
            if (ReFire_Count >= GrenadeReFireTime)
            {
                IsFire = true;
            }

            if (IsFire)
            {
                // 수류탄을 던질 수 있다면, 유저의 손에 들려진 수류탄을 활성화
                User_Grenade.SetActive(true);

                if (Input.GetMouseButtonDown(0))
                {
                    Player.GetComponent<playerCtrl>().SetThrowTrigger();
                    User_Grenade.SetActive(false);
                    IsGrandeThrow = true;
                }
            }

            // 던지는 모션 후, 발사하는 코드
            if (IsGrandeThrow)
            {
                GDealayCount++;

                if (GDealayCount >= GrandeDelayTime)
                {
                    CreateGrenade();

                    ReFire_Count = 0;
                    IsFire = false;

                    IsGrandeThrow = false;
                    GDealayCount = 0;
                }
            }

        }

        // 레이저
        else if (Player_GunType == (int)Gun.LaserGun)
        {

            // 재사용 대기시간을 기다리는 코드
            if (ReFire_Count >= LaserReFireTime)
            {
                IsFire = true;
            }

            if (Input.GetMouseButtonDown(0) && IsFire)
            {
                IsLaserFire = true;
            }

            // 발사 버튼을 눌렀을때, 활성화만 진행
            if (IsLaserFire)
            {
                LDealayCount++;

                if (LDealayCount < LaserDelayTime)
                {
                    Player.GetComponent<playerCtrl>().SetIsShootTrigger();
                }

                // 지연시간 동안에는 
                else if (LDealayCount >= LaserDelayTime
                    && LDealayCount < ActiveLaserTime)
                {
                    CreateLaser();
                    laser.SetActive(true);

                    Debug.Log("GG");
                }

                else if (LDealayCount >= ActiveLaserTime)
                {
                    laser.SetActive(false);
                    IsLaserFire = false;

                    IsFire = false;
                    ReFire_Count = 0;
                    LDealayCount = 0;
                }
            }

        }

        ReFire_Count++;
    }

    void CreateBullet()
    {
        Instantiate(bullet, MyTr.position, MyTr.rotation);
    }

    void CreateGrenade()
    {
        Instantiate(grenade, MyTr.position, MyTr.rotation);
        Debug.Log("Gran");
    }

    void CreateLaser()
    {
        Debug.Log("Laser");

        RaycastHit hit;
        int layMask = 1 << LayerMask.NameToLayer("Wall");
        if (Physics.Raycast(transform.position, transform.forward, out hit, Mathf.Infinity, layMask))
        {
            print("벽 명중!");
            laserScale.transform.localScale = new Vector3(Scale, hit.distance, Scale);
            laserScale.transform.localPosition = new Vector3(0, 0, hit.distance / 2);
        }
        else
        {
            print("몬스터 명중!");
        }
        laser.SetActive(true);
    }

}
