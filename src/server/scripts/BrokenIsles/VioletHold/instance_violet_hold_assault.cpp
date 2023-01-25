#include "GameObject.h"
#include "ScriptMgr.h"
#include "violet_hold_assault.h"

class instance_violet_hold_legion : public InstanceMapScript
{
public:
    instance_violet_hold_legion() : InstanceMapScript("instance_violet_hold_legion", 1544) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_violet_hold_legion_InstanceMapScript(map);
    }

    struct instance_violet_hold_legion_InstanceMapScript : public InstanceScript
    {
        instance_violet_hold_legion_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
        }
    };
};

void AddSC_instance_violet_hold_assault()
{
    new instance_violet_hold_legion();
}
