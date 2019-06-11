using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class CubeSpawner : MonoBehaviour
{
    public GameObject[] letters;
    public Transform[] spawnPosinions;
    public float spawnPeriod = 1f;

    float lastSpawnTime = 0;
    GameObject go;
    Transform tr;

    private void Update()
    {
        if (Time.time > lastSpawnTime + spawnPeriod)
        {
            lastSpawnTime = Time.time;
            Spawn();
        }
    }

    public void Spawn()
    {
        tr = spawnPosinions[Random.Range(0, spawnPosinions.Length)];
        GameObject.Instantiate(letters[Random.Range(0, letters.Length)], tr.position, tr.rotation);
    }
}
