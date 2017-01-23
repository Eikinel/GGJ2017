using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class AudioContinue : MonoBehaviour {

    static bool AudioBegin = false;

    void Awake()
    {
        if (!AudioBegin)
        {
            this.GetComponent<AudioSource>().Play();
            DontDestroyOnLoad(gameObject);
            AudioBegin = true;
        }
    }

    void Update()
    {
        if (Application.loadedLevelName == "GameScreen")
        {
            this.GetComponent<AudioSource>().Stop();
            AudioBegin = false;
        }
    }
}
