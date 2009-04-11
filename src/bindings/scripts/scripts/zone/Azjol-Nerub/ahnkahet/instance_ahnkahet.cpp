#include "precompiled.h"
#include "def_ahnkahet.h"

struct TRINITY_DLL_DECL instance_ahn_kahet : public ScriptedInstance
{
    instance_ahn_kahet(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_ahn_kahet(Map* map)
{
    return new instance_ahn_kahet(map);
}

void AddSC_instance_ahn_kahet()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_ahn_kahet";
    newscript->GetInstanceData = GetInstanceData_instance_ahn_kahet;
    newscript->RegisterSelf();
}
