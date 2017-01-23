using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class MoveIA : MonoBehaviour
{
    public  float       _speed;
    private MovePlayer  _player;
    public  Vector3     _bite;

    // Use this for initialization
    void Start()
    {
        _player = GameObject.Find("hero").GetComponent<MovePlayer>();
    }
    
    // Update is called once per frame
    void Update()
    {
        _bite = Vector3.MoveTowards(transform.position, _player._pos_player, _speed * Time.deltaTime);
        transform.position = _bite;
    }
}
