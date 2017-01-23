using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveIA : MonoBehaviour
{
    public float _Speed;
    private MovePlayer Player;
    public new Vector3 p;

    // Use this for initialization
    void Start()
    {
        Player = GameObject.Find("player").GetComponent<MovePlayer>();
    }
    
    // Update is called once per frame
    void Update()
    {
        p = Vector3.MoveTowards(transform.position, Player.PosPlayer, _Speed * Time.deltaTime);
        transform.position = p;
    }
}
