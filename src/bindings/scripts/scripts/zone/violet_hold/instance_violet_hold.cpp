#include "precompiled.h"
#include "def_violet_hold.h"

struct TRINITY_DLL_DECL instance_violet_hold : public ScriptedInstance
{
    instance_violet_hold(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_violet_hold(Map* map)
{
    return new instance_violet_hold(map);
}

void AddSC_instance_violet_hold()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_violet_hold";
    newscript->GetInstanceData = GetInstanceData_instance_violet_hold;
    newscript->RegisterSelf();
}
