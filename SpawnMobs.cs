using UnityEngine;
using System.Collections;

public class SpawnMobs : MonoBehaviour {
    // Variable pour définir Position Item,SpawnTime et le Gameobject
    public Transform[] _spawn_spot;
    private float _spawn_time = 2f;
    public GameObject Mobs;

	void Start () {
        // fonction qui répete la fonction SpawnBox avec SpawnTime pour intervalle
        InvokeRepeating("SpawnMob", _spawn_time, _spawn_time);
	}
	
	// Update is called once per frame
	void Update () {
	
	}
    void SpawnMob()
    {
        // crée une variable qui prend une valeur aléatoire entre 0 et SpawnItem max
        int _spawn_index = Random.Range(0, _spawn_spot.Length);
        // instancie le GameObject en jeux
        Instantiate(Mobs, _spawn_spot[_spawn_index].position, _spawn_spot[_spawn_index].rotation);
    }

}
