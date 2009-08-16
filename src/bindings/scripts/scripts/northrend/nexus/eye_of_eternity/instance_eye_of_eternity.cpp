#include "precompiled.h"
#include "def_eye_of_eternity.h"

struct TRINITY_DLL_DECL instance_eye_of_eternity : public ScriptedInstance
{
    instance_eye_of_eternity(Map* pMap) : ScriptedInstance(pMap) {Initialize();};
};

InstanceData* GetInstanceData_instance_eye_of_eternity(Map* pMap)
{
    return new instance_eye_of_eternity(pMap);
}

void AddSC_instance_eye_of_eternity()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_eye_of_eternity";
    newscript->GetInstanceData = &GetInstanceData_instance_eye_of_eternity;
    newscript->RegisterSelf();
}
