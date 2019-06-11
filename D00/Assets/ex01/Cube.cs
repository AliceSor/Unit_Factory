using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Cube : MonoBehaviour
{

    public string letter = "a";

    float maxSpeed = 8;
    float minSpeed = 2;

    float lineY = -3;

    float speed;

	void Start ()
    {
        speed = Random.Range(minSpeed, maxSpeed);
	}
	
	void Update ()
    {
        if (lineY >= transform.position.y)
            Destroy(gameObject);
        transform.Translate(0, -1 * Time.deltaTime * speed, 0);
        if (Input.GetKeyDown(letter))
            Pressed();
	}

    void Pressed()
    {
        float res = transform.position.y - lineY;
        Debug.Log((res > 0) ? res : -res );
        Destroy(gameObject);
    }
}
