using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlayer : MonoBehaviour
{
    public float _Speed;
    public Vector3 PosPlayer;

    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        float _movex = Input.GetAxisRaw("Horizontal");
        float _movey = Input.GetAxisRaw("Vertical");
        PosPlayer = transform.position;
        GetComponent<Rigidbody2D>().velocity = new Vector3(_movex * _Speed, _movey * _Speed, 0);
    }
}
