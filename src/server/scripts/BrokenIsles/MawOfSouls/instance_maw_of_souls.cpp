#include "maw_of_souls.h"
#include "WorldPacket.h"
#include "InstancePackets.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_HARBARON_DOOR,      DATA_HARBARON,       DOOR_TYPE_PASSAGE,       BOUNDARY_NONE},
    {GO_HARBARON_DOOR_2,    DATA_HARBARON,       DOOR_TYPE_ROOM,          BOUNDARY_NONE},
    {GO_SKJAL_INVIS_DOOR,   DATA_SKJAL,          DOOR_TYPE_PASSAGE,       BOUNDARY_NONE},
    {GO_SKJAL_DOOR_1,       DATA_SKJAL,          DOOR_TYPE_PASSAGE,       BOUNDARY_NONE},
    {GO_SKJAL_DOOR_2,       DATA_SKJAL,          DOOR_TYPE_PASSAGE,       BOUNDARY_NONE},
};

class instance_maw_of_souls : public InstanceMapScript
{
public:
    instance_maw_of_souls() : InstanceMapScript("instance_maw_of_souls", 1492) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_maw_of_souls_InstanceMapScript(map);
    }

    struct instance_maw_of_souls_InstanceMapScript : public InstanceScript
    {
        instance_maw_of_souls_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        WorldLocation loc_res_pla;

        ObjectGuid YmironGUID;
        ObjectGuid YmironGornGUID;
        ObjectGuid helyaGUID;
        ObjectGuid shipGUID;
        ObjectGuid helyaChestGUID;
        ObjectGuid SkjalGUID;

        void Initialize() override
        {
            LoadDoorData(doorData);
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_YMIRON:
                YmironGUID = creature->GetGUID();
                break;
            case NPC_SKJAL:
                SkjalGUID = creature->GetGUID();
                break;
            case NPC_HELYA:
                helyaGUID = creature->GetGUID();
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_YMIRON_GORN:
                YmironGornGUID = go->GetGUID();
                go->SetFlags(GO_FLAG_NOT_SELECTABLE);
                break;
            case GO_SHIP:
                shipGUID = go->GetGUID();
                break;
            case GO_HELYA_CHEST:
                helyaChestGUID = go->GetGUID();
                break;
            case GO_HARBARON_DOOR:
            case GO_HARBARON_DOOR_2:
            case GO_SKJAL_INVIS_DOOR:
            case GO_SKJAL_DOOR_1:
            case GO_SKJAL_DOOR_2:
                AddDoor(go, true);
                break;
            default:
                break;
            }
        }

        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (type)
            {
            case DATA_HELYA:
            {
                if (state == DONE && instance->GetDifficultyID() != DIFFICULTY_MYTHIC_KEYSTONE)
                {
                    if (GameObject* chest = instance->GetGameObject(helyaChestGUID))
                        chest->SetRespawnTime(86400);
                }
                break;
            }
            default:
                break;
            }
            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            /* switch (type)
            {
                case DATA_:
                    break;
                default:
                    break;
            } */
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_YMIRON:
                return YmironGUID;
            case DATA_YMIRON_GORN:
                return YmironGornGUID;
            case DATA_SKJAL:
                return SkjalGUID;
            case DATA_HELYA:
                return helyaGUID;
            case DATA_SHIP:
                return shipGUID;
            }
            return ObjectGuid::Empty;
        }

        uint32 GetData(uint32 type) const override
        {
            return 0;
        }

        void Update(uint32 diff) override {}
    };
};

void AddSC_instance_maw_of_souls()
{
    new instance_maw_of_souls();
}
