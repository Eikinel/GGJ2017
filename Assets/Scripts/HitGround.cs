using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HitGround : MonoBehaviour {

    public  GameObject  _wave;
    private float       _direction;
    private Vector3     _wave_pos;

    // Use this for initialization
    void Start ()
    {
        if (transform.tag == "Left Fist")
            _direction = -1;
        else if (transform.tag == "Right Fist")
            _direction = 1;
    }

    private void OnCollisionEnter2D(Collision2D collision)
    {
        if (collision.collider.tag == "Plateform")
        {
            _wave_pos.x = this.transform.position.x + this.GetComponent<BoxCollider2D>().bounds.size.x * -_direction;
            _wave_pos.y = GameObject.Find("plateform").GetComponent<BoxCollider2D>().transform.position.y + this.GetComponent<BoxCollider2D>().bounds.size.y / 2;
            _wave_pos.z = 1f;
            Instantiate(_wave, _wave_pos, new Quaternion(0, (_direction + 1) / 2, 0, 0), this.transform);
        }
    }
}
