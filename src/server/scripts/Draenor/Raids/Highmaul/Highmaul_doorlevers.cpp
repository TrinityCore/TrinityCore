/*
//Add Lever
*/

enum DoorLever{
    max_now       =  7
};

int32 Highmaul_lever[max_now] = 
{
126060,
126061,
126062,
126063,
126064,
126065,
126066
};

int32 Highmaul_door[max_now] = 
{
231780,
231781,
239124,
239125,
239126,
239127,
239128,
};

class Highmaul_doorlevers : public GameObjectScript
{
public:
    Highmaul_doorlevers() : GameObjectScript("Highmaul_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Highmaul_Door = go->FindNearestGameObject(Highmaul_door[i], 100.0f))
        {
                Highmaul_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_Highmaul_doorlevers()
{
	new Highmaul_doorlevers();
}
