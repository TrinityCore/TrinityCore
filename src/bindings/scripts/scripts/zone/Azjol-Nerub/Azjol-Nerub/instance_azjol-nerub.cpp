#include "precompiled.h"
#include "def_azjol-nerub.h"

struct TRINITY_DLL_DECL instance_azjol_nerub : public ScriptedInstance
{
    instance_azjol_nerub(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_azjol_nerub(Map* map)
{
    return new instance_azjol_nerub(map);
}

void AddSC_instance_azjol_nerub()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_azjol_nerub";
    newscript->GetInstanceData = GetInstanceData_instance_azjol_nerub;
    newscript->RegisterSelf();
}
