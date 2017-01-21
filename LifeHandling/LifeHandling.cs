using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerLife : MonoBehaviour
{
    public int _player_start_life = 100;
    public int _player_current_life;

    Animator Anim; //Animation.
    bool _dead; //Signal the player is DEAD.
    bool _hurt; //True when player is hurt.

    void Set ()
    {
        Anim = GetComponent <Animator> ();
        _player_movement = GetComponent<PlayerMovment>();
        _player_shooting = GetComponentInChildren<PlayerShooting>();
        _player_current_life = _player_start_life;
    }

    void UpDate()
    {
        GetComponent<_damage>();
        if (_hurt)
            _player_current_life -= _damage;
        if (_player_current_life <= 0)
            Dead();
    }

    void Dead()
    {
        _dead = true;
        //Tell to send animation player is dead.
        Anim.SetTrigger("Dead");
        Detroy(GameObject);
    }
}

public class EnemiLife : MonoBehavior
{
    public int _enemy_life;
    public int _enemy_curent_life;
    public int _damage;

    EnemyType _enemy_type;
    bool _hurt;
    bool _dead;

    void SetEnemy()
    {
        GetComponent<_enemy_type>();
        if (_enemy_type == 1) //minion
        {
            _enemy_life = 50;
            _damage = 15;
        }
        if (_enemy_type == 2) //comander
        {
            _enemy_life = 100;
            _damage = 25;
        }
        if (_enemy_life == 3) //legender
        {
            _enemy_life = 250;
            _damage = 50;
        }
        if (_enemy_life == 4) //boss
        {
            _enemy_life = 150;
            _damage = 50;
        }
        _enemy_curent_life = _enemy_life;
    }

    void ShootEnemy()
    {
        if (_hurt)
            _enemy_current_life -= 50;
        if (_enemy_current_life <= 0)
            Dead(); 
    }

    void EnemyDead()
    {
        _dead = true;
        Anim.SetTrigger("Dead"); 
    }
}