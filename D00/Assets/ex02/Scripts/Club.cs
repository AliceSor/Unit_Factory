using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Club : MonoBehaviour
{
    public Ball ball;
    public float startSpeed;
    public float maxSpeed = 20;
    public bool isClubUnder = true;

    float startPressSpace;
    public enum ClubState { IDLE, PRESSING, MOVING, HITTED}
    public ClubState state = ClubState.IDLE;

    public void Update()
    {
        switch (state)
        {
            case ClubState.IDLE:
                {
                    // idle - waiting for user input
                    //.....
                    if (Input.GetKey("space"))
                    {
                        state = ClubState.PRESSING;
                        startPressSpace = Time.time;
                    }
                    break;
                }
            case ClubState.PRESSING:
                {
                    //user press space, check if button up
                    //...
                    if (!Input.GetKey("space"))
                    {
                        state = ClubState.MOVING;
                        float delta = (Time.time - startPressSpace) * 5;
                        startSpeed = (delta < maxSpeed) ? delta : maxSpeed;
                        isClubUnder = transform.position.y < ball.transform.position.y;
                    }
                    break;
                }
            case ClubState.MOVING:
                {
                    //Club moving to the ball
                    //..
                    if (isClubUnder && transform.position.y < ball.transform.position.y) //still under ball
                    {
                        transform.Translate(Vector3.up * startSpeed * Time.deltaTime);
                    }
                    else if (!isClubUnder && transform.position.y > ball.transform.position.y) //still above
                    {
                        transform.Translate(Vector3.down * startSpeed * Time.deltaTime);
                    }
                    else
                    {
                        state = ClubState.HITTED; //club hitted ball
                        ball.Hit(startSpeed, (isClubUnder) ? 1 : -1);
                    }
                    break;
                }
            case ClubState.HITTED:
                {

                    //Club hit ball, ball moving
                    //..
                    break;
                }

                //Ball stoped moved and club have new position
                //.. -> idle
        }
    }

}
