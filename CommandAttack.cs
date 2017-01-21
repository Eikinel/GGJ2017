using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CommandAttack : MonoBehaviour {
    public GameObject ZoneDmg1;
    private new Vector3 _pos = Transform.position;
    private new Vector3 _rot = Transform.rotation;
    // Use this for initialization
    void Start () {
		
	}
	
	// Update is called once per frame
	void Update () {
        if (Input.GetKeyDown(KeyCode.Mouse0)) //La zone pop puis tant que tout les ennemis en contact n'ont pas pris un dmg rest puis destroy
        {
            Instantiate(ZoneDmg1, _pos, _rot);
        }
        else if (Input.GetKeyDown(KeyCode.Mouse1))
        {
            Projectile();
        }
	}

    void    OnCollisionEnter2D(Collision col)
    {
        ShootEnemy(col);
        Destroy(ZoneDmg1);
    }
}
