#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "crucible_of_storms.h"

class instance_crucible_of_storms : public InstanceMapScript
{
public:
    instance_crucible_of_storms() : InstanceMapScript("instance_crucible_of_storms", 2096) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_crucible_of_storms_InstanceScript(map);
    }
     // later to do, PH atm #Rageless
    struct instance_crucible_of_storms_InstanceScript : public InstanceScript
    {
        instance_crucible_of_storms_InstanceScript(InstanceMap* map) : InstanceScript(map)
        {
        }
    };
};

void AddSC_instance_crucible_of_storms()
{
    new instance_crucible_of_storms();
}