using JetBrains.Annotations;
using System.Collections;
using System.Collections.Generic;
using Unity.VisualScripting;
using UnityEditor.SearchService;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UIElements;

public class MobSpawner : MonoBehaviour
{
    public GameObject[] monsters;

    private BoxCollider area;
    private int count;
    private int selection;

    private List<GameObject> gameObjects = new List<GameObject>();

    private Transform playerPos;

    void Start()
    {
        area = GetComponent<BoxCollider>();
        playerPos = GameObject.FindGameObjectWithTag("Player").GetComponent<Transform>();

        if (SceneManager.GetActiveScene().name == "scRound1-1")
        {
            count = 8;
            selection = 1;
        }else if(SceneManager.GetActiveScene().name == "scRound1-2")
        {
            count = 14;
            selection = 2;
        }else if(SceneManager.GetActiveScene().name == "scRound2-1")
        {
            count = 20;
            selection = 3;
        }else if(SceneManager.GetActiveScene().name == "scRound2-2")
        {
            count = 25;
            selection = 3;
        }
    }

    // Update is called once per frame
    void Update()
    {
        
        float distance = Vector3.Distance(playerPos.position, transform.position);
        if (distance <= 20)
        {

            for (int i = 0; i < count; ++i)//count 수 만큼 생성한다
            {
                Spawn();//생성 + 스폰위치를 포함하는 함수
            }

            GameManager gameManager = GameObject.Find("GameManager").GetComponent<GameManager>();
            gameManager.StartCoroutine(gameManager.StageCheck());

            area.enabled = false;
            Destroy(gameObject); gameObjects.Clear();
        }
    }

    private Vector3 GetRandomPosition()
    {
        Vector3 basePosition = transform.position;
        Vector3 size = area.size;

        float posX = basePosition.x + Random.Range(-size.x / 2f, size.x / 2f);
        float posZ = basePosition.z + Random.Range(-size.z / 2f, size.z / 2f);

        Vector3 spawnPos = new Vector3(posX, transform.position.y, posZ);

        return spawnPos;
    }

    void Spawn()
    {
        int ranCount = Random.Range(0, selection);
        GameObject selectedPrefab = monsters[ranCount];

        Vector3 spawnPos = GetRandomPosition();//랜덤위치함수

        GameObject instance = Instantiate(selectedPrefab, spawnPos, Quaternion.identity);
        gameObjects.Add(instance);
    }
}
