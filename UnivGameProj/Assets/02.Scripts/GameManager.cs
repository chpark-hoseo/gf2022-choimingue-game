using System.Collections;
using System.Collections.Generic;
using UnityEditor.SearchService;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class GameManager : MonoBehaviour
{
    public GameObject Player;
    Transform PlayerTr;
    GameObject[] MonsterArray;

    public bool isBattle = false;

    public int stage;
    public float playTime;

    public int enemyCountMelee;
    public int enemyCountCharge;
    public int enemyCountRanged;

    public GameObject gamePanel;
    public Text stageTxt;
    public Text playTimeTxt;
    public Text playerHpTxt;
    public Text enemyRangedTxt;

    // Start is called before the first frame update
    void Start()
    {
        DontDestroyOnLoad(this);

        Player = GameObject.FindGameObjectWithTag("Player");
    }

    // Update is called once per frame
    void Update()
    {
        playTime += Time.deltaTime;
    }

    private void LateUpdate()
    {
        switch (SceneManager.GetActiveScene().name)
        {
            case "scRound1-1":
                stageTxt.text = "STAGE 1-1";
                break;
            case "scRound1-2":
                stageTxt.text = "STAGE 1-2";
                break;
            case "scRound2-1":
                stageTxt.text = "STAGE 2-1";
                break;
            case "scRound2-2":
                stageTxt.text = "STAGE 2-2";
                break;
            default:
                break;
        }

        var pla = Player.GetComponent<playerCtrl>();
        playerHpTxt.text = pla.PlayerCurHP + " / " + pla.PlayerMaxHP;

        int hour = (int)(playTime / 3600);
        int min = (int)((playTime - hour * 3600) / 60);
        int sec = (int)((playTime % 60));

        playTimeTxt.text = string.Format("{0:00}", hour) + ":" + string.Format("{0:00}", min) + ":" + string.Format("{0:00}", sec);

        var enemyCountCharge = GameObject.FindGameObjectsWithTag("MONSTER");
        enemyRangedTxt.text = "x " + enemyCountCharge.Length;
        
    }

    public void CheckStart()
    {
        
    }

    public IEnumerator StageCheck()
    {
        while(true)
        {
            yield return new WaitForSeconds(1.0f);

            PlayerTr = Player.GetComponent<Transform>();
            MonsterArray = GameObject.FindGameObjectsWithTag("MONSTER");
            Debug.Log("SEX " + MonsterArray.Length);

            if (MonsterArray.Length <= 0)
            {
                switch (SceneManager.GetActiveScene().name)
                {
                    case "scRound1-1":
                        PlayerTr.position = new Vector3(0, 0.45f, 0);
                        SceneManager.LoadScene("scRound1-2");
                        StopAllCoroutines();
                        break;
                    case "scRound1-2":
                        PlayerTr.position = new Vector3(-50, 0.45f, 0);
                        SceneManager.LoadScene("scRound2-1");
                        StopAllCoroutines();
                        break;
                    case "scRound2-1":
                        PlayerTr.position = new Vector3(-50, 0.45f, 0);
                        SceneManager.LoadScene("scRound2-2");
                        StopAllCoroutines();
                        break;
                    case "scRound2-2":
                        PlayerTr.position = new Vector3(-50, 0.45f, 0);
                        SceneManager.LoadScene("Clear");
                        break;
                    default:
                        break;
                }
            }
        }
    }

}
