/*
UPDATE gameobject_template SET ScriptName='karabor_doorlevers' WHERE entry=460010;
*/

enum DoorLever{
    max_now       =  4
};

int32 karabor_lever[max_now] = 
{
126067,
126068,
126069,
126070
};

int32 karabor_door[max_now] = 
{
236081,
236082,
236083,
236084
};

class karabor_doorlevers : public GameObjectScript
{
public:
    karabor_doorlevers() : GameObjectScript("karabor_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * karabor_Door = go->FindNearestGameObject(karabor_door[i], 100.0f))
        {
                karabor_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_karabor_doorlevers()
{
	new karabor_doorlevers();
}
