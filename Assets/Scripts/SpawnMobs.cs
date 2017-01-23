using UnityEngine;
using System.Collections;

public class SpawnMobs : MonoBehaviour {
    // Variable pour définir Position Item,SpawnTime et le Gameobject
    //public Transform[] _spawn_spot;
    public GameObject[]     _mobs;
    public Vector3[]        _spawn_spots;
    private float           _spawn_time;
    private GameObject[]    _count_mob;

	void Start ()
    {
        // fonction qui répete la fonction SpawnBox avec SpawnTime pour intervalle
        _spawn_time = Random.Range(3, 8);
        _count_mob = GameObject.FindGameObjectsWithTag("Monster");
        InvokeRepeating("SpawnMob", _spawn_time, _spawn_time);
	}
	
	// Update is called once per frame
	void Update ()
    {
    }
    void SpawnMob()
    {
        _count_mob = GameObject.FindGameObjectsWithTag("Monster");
        if (_count_mob.Length < 10)
        {
            // crée une variable qui prend une valeur aléatoire entre 0 et SpawnItem max

            int _spawn_index = Random.Range(0, _mobs.Length);
            int _spawn_loc = Random.Range(0, _spawn_spots.Length);
            // instancie le GameObject en jeux
            Instantiate(_mobs[_spawn_index], _spawn_spots[_spawn_loc], new Quaternion(0, 0, 0, 0));
        }
        else
            Debug.Log("Too much monsters");
    }
}
