using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Wave : MonoBehaviour {

    public  float       _speed;
    private float       _direction;
    private Vector3     _vect;

	// Use this for initialization
	void Start ()
    {
        _vect = new Vector3(_speed * Time.deltaTime, -_speed * Time.deltaTime, 0);
	}
	
	// Update is called once per frame
	void Update ()
    {
        transform.Translate(_vect);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.transform.tag == "Player")
            //Ici enlever de la vie au joueur
            Debug.Log("Collision  T R I G G E R");
    }

    private void OnCollisionExit2D(Collision2D collision)
    {
        if (collision.transform.tag == "Plateform")
            Destroy(this.gameObject);
    }
}
