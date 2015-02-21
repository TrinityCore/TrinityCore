/*
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460010;
*/

enum DoorLever{
    max_now       =  3
};

int32 Bonemaw_lever[max_now] = 
{
126071,
126072,
126073
};

int32 Bonemaw_door[max_now] = 
{
233988,
233989,
233990
};

class Bonemaw_doorlevers : public GameObjectScript
{
public:
    Bonemaw_doorlevers() : GameObjectScript("Bonemaw_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Bonemaw_Door = go->FindNearestGameObject(Bonemaw_door[i], 100.0f))
        {
                Bonemaw_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_Bonemaw_doorlevers()
{
	new Bonemaw_doorlevers();
}
