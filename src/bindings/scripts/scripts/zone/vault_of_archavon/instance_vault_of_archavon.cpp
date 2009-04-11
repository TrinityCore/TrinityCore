#include "precompiled.h"
#include "def_vault_of_archavon.h"

struct TRINITY_DLL_DECL instance_archavon : public ScriptedInstance
{
    instance_archavon(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_archavon(Map* map)
{
    return new instance_archavon(map);
}

void AddSC_instance_archavon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_archavon";
    newscript->GetInstanceData = GetInstanceData_instance_archavon;
    newscript->RegisterSelf();
}
