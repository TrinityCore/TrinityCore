#include "precompiled.h"
#include "def_halls_of_lightning.h"

struct TRINITY_DLL_DECL instance_halls_of_lightning : public ScriptedInstance
{
    instance_halls_of_lightning(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_halls_of_lightning(Map* map)
{
    return new instance_halls_of_lightning(map);
}

void AddSC_instance_halls_of_lightning()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_halls_of_lightning";
    newscript->GetInstanceData = &GetInstanceData_instance_halls_of_lightning;
    newscript->RegisterSelf();
}
