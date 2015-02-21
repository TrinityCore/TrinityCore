/*
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460010;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460011;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460012;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460013;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=113735;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=113563;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460020;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460021;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460022;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460023;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460024;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460025;
UPDATE gameobject_template SET ScriptName='door_lever' WHERE entry=460026;
*/

enum DoorLever{
    max_now       =  15
};

int32 lever[max_now] = 
{
126091,
126092,
126093,
126094,
126095,
126096,
126097,
126098,
126099,
126100,
126101,
126102,
126103,
126104,
126105
};

int32 door[max_now] = 
{
225945,
225944,
233920,
227851,
231933,
231932,
233921,
231938,
236211,
236212,
236213,
236214,
236033,
230848,
230849
};

class bossdoor_levers1 : public GameObjectScript
{
public:
    bossdoor_levers1() : GameObjectScript("bossdoor_levers1") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Door = go->FindNearestGameObject(door[i], 100.0f))
        {
                Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_bossdoor_levers1()
{
	new bossdoor_levers1();
}
