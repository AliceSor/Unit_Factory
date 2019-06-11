using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Balloon : MonoBehaviour {

    public int maxGrow = 15;
    public float breathe = 20;
    public float maxBreathe = 20;

    public float delta = 0.5f;
    public float breatheDelta = 5;

    public Slider slider;
    public Text text;

    Vector3 scale;
    bool youWin = false;

    private void Start()
    {
        scale = transform.localScale;
        if (slider != null)
        {
            slider.maxValue = maxBreathe;
            slider.value = maxBreathe;
        }
    }

    void Update ()
    {
		
     if (!youWin)
        {
            if (Input.GetKeyDown("space") && breathe > 0)
            {
                IfPress();
            }

            else
            {
                IfNotPress();
            }
            if (slider != null)
                slider.value = breathe;
            if (scale.x >= maxGrow * 2 / 3)
            {
                if (text != null && !youWin)
                    text.text = "More!!!";
            }
        }

	}

    private void IfPress()
    {
        breathe -= breatheDelta;
        scale.x += delta;
        scale.y += delta;
        transform.localScale = scale;
        if (scale.x > maxGrow)
            EndGame();
    }

    private void IfNotPress()
    {
        if (scale.x > 1)
        {
            scale.x -= 0.01f;
            scale.y -= 0.01f;
            transform.localScale = scale;
        }
        if (breathe < maxBreathe)
            breathe += 1f;
    }

    private void EndGame()
    {
        if (text != null)
            text.text = "Congratulations! You win ^^";
        Debug.Log(Mathf.RoundToInt(Time.realtimeSinceStartup) + "s");
        youWin = true;
        Destroy(gameObject);
    }
}
