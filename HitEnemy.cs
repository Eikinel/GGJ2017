using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class EnemiLife : MonoBehaviour
{
    void ShootEnemy(Collision col)
    {
        col.gameObject.GetComponent<SetLife>()._enemy_life -= 50;
        if (col.gameObject.GetComponent<SetLife>()._enemy_life <= 0)
            EnemyDead(col); 
    }

    void EnemyDead(Collision col)
    {
        Anim.SetTrigger("Dead");
        Destroy(col); 
    }
}