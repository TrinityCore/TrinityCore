#include "precompiled.h"
#include "def_halls_of_stone.h"

struct TRINITY_DLL_DECL instance_halls_of_stone : public ScriptedInstance
{
    instance_halls_of_stone(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
};

InstanceData* GetInstanceData_instance_halls_of_stone(Map* pMap)
{
    return new instance_halls_of_stone(pMap);
}

void AddSC_instance_halls_of_stone()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_halls_of_stone";
    newscript->GetInstanceData = &GetInstanceData_instance_halls_of_stone;
    newscript->RegisterSelf();
}
