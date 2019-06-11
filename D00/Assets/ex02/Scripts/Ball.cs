using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Ball : MonoBehaviour
{
    public Club club;
    public float acceleration = -10;
    public float speed = 0;
    public float startSpeed;
    public int isUp;
    
    public void Hit(float _startSpeed, int _isUp)
    {
        speed = _startSpeed;
        startSpeed = _startSpeed;
        isUp = _isUp;
    }

    private void Update()
    {
        if (startSpeed > 0)
        {
            // speed += acceleration * Time.deltaTime;
            speed = startSpeed + acceleration * Time.time;
            transform.Translate(isUp *Vector3.up * speed * Time.deltaTime);
        }
    }

}
