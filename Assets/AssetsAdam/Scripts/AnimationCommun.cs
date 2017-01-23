using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AnimationCommun : MonoBehaviour
{
    private Vector3     _ia_pos;
    private Animator    _anim;
    private bool[]      _cond = new bool[4]; 

    void Start()
    {
        _anim = GetComponent<Animator>();
        _ia_pos = this.GetComponent<MoveIA>()._bite;
        _cond[0] = false;
        _cond[1] = false;
        _cond[2] = false;
        _cond[3] = false;
    }

    void Update()
    {
        _ia_pos = this.GetComponent<MoveIA>()._bite;
        UpdateAnimation();
    }

    void UpdateAnimation()
    {
        if (_ia_pos.y > 0)
        {
            _cond[0] = true;
            _cond[1] = false;
            _cond[2] = false;
            _cond[3] = false;
            if (_ia_pos.x < 0)
            {
                _cond[2] = true;
            }
            else if (_ia_pos.x > 0)
            {
                _cond[3] = true;
            }
        }
        else if (_ia_pos.y < 0)
        {
            _cond[1] = true;
            _cond[0] = false;
            _cond[2] = false;
            _cond[3] = false;
            if (_ia_pos.x < 0)
            {
                _cond[2] = true;
            }
            else if (_ia_pos.x > 0)
            {
                _cond[3] = true;
            }
        }
        else
        {
            _cond[0] = false;
            _cond[1] = false;
            _cond[2] = false;
            _cond[3] = false;
            if (_ia_pos.x < 0)
            {
                _cond[2] = true;
            }
            else
            {
                _cond[3] = true;
            }
        }
        _anim.SetBool("IsBack", _cond[0]);
        _anim.SetBool("IsDown", _cond[1]);
        _anim.SetBool("IsLeft", _cond[2]);
        _anim.SetBool("IsRight", _cond[3]);
    }
}
