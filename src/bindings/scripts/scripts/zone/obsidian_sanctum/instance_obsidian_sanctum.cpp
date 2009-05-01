#include "precompiled.h"
#include "def_obsidian_sanctum.h"

struct TRINITY_DLL_DECL instance_obsidian_sanctum : public ScriptedInstance
{
    instance_obsidian_sanctum(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_obsidian_sanctum(Map* map)
{
    return new instance_obsidian_sanctum(map);
}

void AddSC_instance_obsidian_sanctum()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_obsidian_sanctum";
    newscript->GetInstanceData = &GetInstanceData_instance_obsidian_sanctum;
    newscript->RegisterSelf();
}
