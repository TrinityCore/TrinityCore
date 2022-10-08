#include "ScriptMgr.h"
#include "Player.h"
#include "InstanceScript.h"
#include "temple_of_sethraliss.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    { 292551, DATA_ADDERIS_AND_ASPIX, DOOR_TYPE_ROOM },
    { 290906, DATA_MEREKTHA, DOOR_TYPE_ROOM },
    { 292414, DATA_GALVAZZT, DOOR_TYPE_ROOM },
};

struct instance_temple_of_sethraliss : public InstanceScript
{
    instance_temple_of_sethraliss(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
    }

    void Initialize() override
    {
        LoadDoorData(doorData);
    }

    void OnGameObjectCreate(GameObject* go) override
    {
        switch (go->GetEntry())
        {
        case GO_SETHRALISS_TREASURE:
            go->SetFlags(GO_FLAG_LOCKED);
            break;
        }
    }
};

void AddSC_instance_temple_of_sethraliss()
{
    RegisterInstanceScript(instance_temple_of_sethraliss, 1877);
}
