using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class HitGround : MonoBehaviour
{
    public GameObject   _wave;
    private Vector3     _fist_pos;
    private Vector3     _wave_pos;
    private float       _direction;
    private float       _twist_up_and_down;

    // Use this for initialization
    void Start ()
    {
        _fist_pos.y = 3 * Time.deltaTime * _twist_up_and_down;
        if (transform.tag == "Left Fist")
            _direction = -1;
        else if (transform.tag == "Right Fist")
            _direction = 1;
        _twist_up_and_down = -1;
    }

    private void Update()
    {
        _fist_pos.y = 3 * Time.deltaTime * _twist_up_and_down;
        if (this.transform.position.y <= 0.1)
        {
            _twist_up_and_down = 1;
            _wave_pos.x = this.transform.position.x + this.GetComponent<BoxCollider2D>().bounds.size.x / 2 * -_direction;
            //_wave_pos.y = GameObject.Find("plateform").GetComponent<BoxCollider2D>().transform.position.y + this.GetComponent<BoxCollider2D>().bounds.size.y / 2;
            _wave_pos.y = this.transform.position.y;// - this.GetComponent<BoxCollider2D>().bounds.size.y;
            _wave_pos.z = -5f;
            Instantiate(_wave, _wave_pos, new Quaternion(0, (_direction + 1) / 2, 0, 0));
        }
        if (this.transform.position.y >= 1.5)
            _twist_up_and_down = -1;
        transform.Translate(_fist_pos);
    }
}
