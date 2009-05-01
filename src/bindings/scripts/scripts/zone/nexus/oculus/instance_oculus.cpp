#include "precompiled.h"
#include "def_oculus.h"

struct TRINITY_DLL_DECL instance_oculus : public ScriptedInstance
{
    instance_oculus(Map *Map) : ScriptedInstance(Map) {Initialize();};
};

InstanceData* GetInstanceData_instance_oculus(Map* map)
{
    return new instance_oculus(map);
}

void AddSC_instance_oculus()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_oculus";
    newscript->GetInstanceData = &GetInstanceData_instance_oculus;
    newscript->RegisterSelf();
}
