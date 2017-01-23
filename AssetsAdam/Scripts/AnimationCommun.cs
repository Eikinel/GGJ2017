using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimationCommun : MonoBehaviour
{
    private MoveIA _move;
    private Animator anim;
    private bool[] cond = new bool[4]; 

    void Start()
    {
        anim = GetComponent<Animator>();
        _move = GameObject.Find("Commun").GetComponent<MoveIA>();
    }

    void Update()
    {
        UpdateAnimation();
    }

    void UpdateAnimation()
    {
        if (_move.p.y > 0)
        {
            cond[0] = true;
            cond[1] = false;
            cond[2] = false;
            cond[3] = false;
            if (_move.p.x < 0)
            {
                cond[2] = true;
            }
            else if (_move.p.x > 0)
            {
                cond[3] = true;
            }
        }
        else if (_move.p.y < 0)
        {
            cond[1] = true;
            cond[0] = false;
            cond[2] = false;
            cond[3] = false;
            if (_move.p.x < 0)
            {
                cond[2] = true;
            }
            else if (_move.p.x > 0)
            {
                cond[3] = true;
            }
        }
        else
        {
            cond[0] = false;
            cond[1] = false;
            cond[2] = false;
            cond[3] = false;
            if (_move.p.x < 0)
            {
                cond[2] = true;
            }
            else
            {
                cond[3] = true;
            }
        }
        anim.SetBool("IsBack", cond[0]);
        anim.SetBool("IsDown", cond[1]);
        anim.SetBool("IsLeft", cond[2]);
        anim.SetBool("IsRight", cond[3]);
    }
}
