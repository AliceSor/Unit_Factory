using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CameraController : MonoBehaviour {

    public float speed = 10;
    public float angleSpeed = 30;
    public float xLimit = 30;
    public float zLimit = 30;

	void Update ()
    {
        CheckInput();

    }

    private void CheckInput()
    {
        Vector3 dir;
        if (Input.GetKeyDown("w") || Input.GetKey("w"))
        {
            dir = transform.forward;
            dir.y = 0;
            transform.position += dir.normalized * Time.deltaTime * speed;
        }
        else if (Input.GetKeyDown("s") || Input.GetKey("s"))
        {
            dir = transform.forward;
            dir.y = 0;
            transform.position -= dir.normalized * Time.deltaTime * speed;
        }
        else if (Input.GetKeyDown("a") || Input.GetKey("a"))
        {
            transform.Rotate(0, angleSpeed * Time.deltaTime, 0, Space.World);
        }
        else if (Input.GetKeyDown("d") || Input.GetKey("d"))
        {
            transform.Rotate(0, -angleSpeed * Time.deltaTime, 0, Space.World);
        }
        else if (Input.GetKeyDown("e") || Input.GetKey("e"))
        {
            transform.position += Vector3.up * speed * Time.deltaTime / 2;
        }
        else if (Input.GetKeyDown("q") || Input.GetKey("q"))
        {
            transform.position -= Vector3.up * speed * Time.deltaTime / 2;
        }
        ClampPos();
    }

    private void ClampPos()
    {
        var pos = transform.position;
        pos.x = Mathf.Clamp(transform.position.x, -xLimit, xLimit);
        pos.z = Mathf.Clamp(transform.position.z, -zLimit, zLimit);
        pos.y = Mathf.Clamp(transform.position.y, -4.0f, 20.0f);

        transform.position = pos;
    }
}
