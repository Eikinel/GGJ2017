using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MovePlayer : MonoBehaviour
{
    public float    _speed;
    public Vector3  _pos_player;

    // Use this for initialization
    void Start()
    {
    }

    // Update is called once per frame
    void Update()
    {
        float _movex = Input.GetAxisRaw("Horizontal");
        float _movey = Input.GetAxisRaw("Vertical");
        _pos_player = transform.position;
        GetComponent<Rigidbody2D>().velocity = new Vector3(_movex * _speed, _movey * _speed, 0);
    }
}
