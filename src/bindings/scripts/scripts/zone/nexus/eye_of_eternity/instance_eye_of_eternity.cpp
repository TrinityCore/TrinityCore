#include "precompiled.h"
#include "def_eye_of_eternity.h"

struct TRINITY_DLL_DECL instance_eye_of_eternity : public ScriptedInstance
{
    instance_eye_of_eternity(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_eye_of_eternity(Map* map)
{
    return new instance_eye_of_eternity(map);
}

void AddSC_instance_eye_of_eternity()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_eye_of_eternity";
    newscript->GetInstanceData = &GetInstanceData_instance_eye_of_eternity;
    newscript->RegisterSelf();
}
