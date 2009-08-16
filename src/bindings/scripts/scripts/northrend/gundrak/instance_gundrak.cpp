#include "precompiled.h"
#include "def_gundrak.h"

struct TRINITY_DLL_DECL instance_gundrak : public ScriptedInstance
{
    instance_gundrak(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
};

InstanceData* GetInstanceData_instance_gundrak(Map* pMap)
{
    return new instance_gundrak(pMap);
}

void AddSC_instance_gundrak()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_gundrak";
    newscript->GetInstanceData = &GetInstanceData_instance_gundrak;
    newscript->RegisterSelf();
}
