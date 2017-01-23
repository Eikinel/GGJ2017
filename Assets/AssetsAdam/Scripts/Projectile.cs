using System.Collections;
using System.Collections.Generic;
using UnityEngine;
/*
public class Projectile : MonoBehaviour {

    public GameObject projectile;
    //Prefab du projectile à invoquer

    public float ProjectileSpeed = 20.0f;
    //Vitesse du projectile

    private Vector3 PlayerPos;
    //position du joueur

    private Vector3 SummonPoint;
    //point d'apparition du projectile (en fonction de playerpos)

    public float CooldownPower = 2;
    //Temps de Cooldown

    private bool CooldownStart = false;
    // Cooldown Lancé ? 

    public float CooldownMemory;

    public bool shoot = true;
    //true: le player à le droit de tirer, false: !

    // Use this for initialization
    void Start () {
		
	}

	void FixedUpdate()
    {
        if (CooldownStart)
        {
            CooldownMemory -= Time.deltaTime;
            if (CooldownMemory <= 0)
            //Si le timer arrive à 0, on réactive les scripts et on détruit la plateforme
            {
                shoot = true;
                CooldownStart = false;
            }
        }
    }
	// Update is called once per frame
	void Update () {
		
	}
}
*/