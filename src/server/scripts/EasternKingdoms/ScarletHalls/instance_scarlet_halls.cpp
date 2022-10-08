#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "GameObject.h"
#include "scarlet_halls.h"

ObjectGuid HoundmasterBraunGUID;
ObjectGuid ArmsmasterHarlanGUID;
ObjectGuid FlameweaverKoeglerGUID;

struct instance_scarlet_halls : public InstanceScript
{
    instance_scarlet_halls(InstanceMap* map) : InstanceScript(map) { }

    void Initialize()
    {
        SetBossNumber(MAX_ENCOUNTER);
    }

    void OnCreatureCreate(Creature* creature)
    {
        switch (creature->GetEntry())
        {
        case NPC_HOUNDMASTER_BRAUN:
            HoundmasterBraunGUID = creature->GetGUID();
            break;
        case NPC_ARMSMASTER_HARLAN:
            ArmsmasterHarlanGUID = creature->GetGUID();
            break;
        case NPC_FLAMEWEAVER_KOEGLER:
            FlameweaverKoeglerGUID = creature->GetGUID();
            break;
        }
        if (instance->IsNormal())
            if (creature->GetEntry() != NPC_HOUNDMASTER_BRAUN || NPC_ARMSMASTER_HARLAN || NPC_FLAMEWEAVER_KOEGLER)
                creature->SetLevel(RAND(21, 30));
        if (instance->IsHeroic())
            if (creature->GetEntry() != NPC_HOUNDMASTER_BRAUN || NPC_ARMSMASTER_HARLAN || NPC_FLAMEWEAVER_KOEGLER)
                creature->SetLevel(RAND(90, 91));
    }
};

void AddSC_instance_scarlet_halls()
{
    RegisterInstanceScript(instance_scarlet_halls, 1001);
}

