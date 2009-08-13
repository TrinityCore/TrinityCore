#include "precompiled.h"
#include "def_pinnacle.h"

struct TRINITY_DLL_DECL instance_pinnacle : public ScriptedInstance
{
    instance_pinnacle(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
};

InstanceData* GetInstanceData_instance_pinnacle(Map* pMap)
{
    return new instance_pinnacle(pMap);
}

void AddSC_instance_pinnacle()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_pinnacle";
    newscript->GetInstanceData = &GetInstanceData_instance_pinnacle;
    newscript->RegisterSelf();
}
