#include "precompiled.h"
#include "def_drak_tharon_keep.h"

struct TRINITY_DLL_DECL instance_drak_tharon : public ScriptedInstance
{
    instance_drak_tharon(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_drak_tharon(Map* map)
{
    return new instance_drak_tharon(map);
}

void AddSC_instance_drak_tharon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_drak_tharon";
    newscript->GetInstanceData = &GetInstanceData_instance_drak_tharon;
    newscript->RegisterSelf();
}
