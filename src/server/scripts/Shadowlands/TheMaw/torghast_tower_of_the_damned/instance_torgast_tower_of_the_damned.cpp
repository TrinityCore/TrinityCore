#include "ScriptMgr.h"
#include "Player.h"
#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "torghast_tower_of_the_damned.h"

//2162
struct instance_torgast_tower_of_the_damned : public InstanceScript
{
    instance_torgast_tower_of_the_damned(InstanceMap* map) : InstanceScript(map) { }
};
