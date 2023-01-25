#include "thenighthold.h"
#include "GameObject.h"

DoorData const doorData[] =
{
    {GO_SCORPYRON_DOOR_1,           DATA_SKORPYRON,         DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_SCORPYRON_DOOR_2,           DATA_SKORPYRON,         DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_ANOMALY_DOOR_1,             DATA_ANOMALY,           DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_ANOMALY_DOOR_2,             DATA_ANOMALY,           DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_TRILLIAX_DOOR_1,            DATA_TRILLIAX,          DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_TRILLIAX_DOOR_2,            DATA_TRILLIAX,          DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_STAR_AUGUR_ETRAEUS_DOOR,    DATA_ETRAEUS,           DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_BOTANIST_LEFT_DOOR,         DATA_TELARN,            DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_BOTANIST_RIGHT_DOOR,        DATA_TELARN,            DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_ALURIEL_DOOR_PORTAL,        DATA_ALURIEL,           DOOR_TYPE_PASSAGE,      BOUNDARY_NONE},
    {GO_TICHONDRIUS_DOOR_1,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_TICHONDRIUS_DOOR_2,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_TICHONDRIUS_DOOR_3,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_TICHONDRIUS_DOOR_4,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_TICHONDRIUS_DOOR_5,         DATA_TICHONDRIUS,       DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_ELISANDE_DOOR_1,            DATA_ELISANDE,          DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_ELISANDE_DOOR_2,            DATA_ELISANDE,          DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {GO_ELISANDE_DOOR_3,            DATA_ELISANDE,          DOOR_TYPE_ROOM,         BOUNDARY_NONE},
    {0,                             0,                      DOOR_TYPE_ROOM,         BOUNDARY_NONE} // END
};

ObjectData const creatureData[] =
{
    { NPC_SKORPYRON,            DATA_SKORPYRON },
    { NPC_CHRONOMATIC_ANOMALY,  DATA_ANOMALY },
    { NPC_TRILLIAX,             DATA_TRILLIAX },

    { NPC_SPELLBLADE_ALURIEL,   DATA_ALURIEL },
    { NPC_STAR_AUGUR_ETRAEUS,   DATA_ETRAEUS },
    { NPC_TELARN,               DATA_TELARN },

    { NPC_KROSUS,               DATA_KROSUS },
    { NPC_IMGAGE_OF_KADGNAR,    DATA_IMAGE_OF_KADGHAR },
    { NPC_CHAOS_MAGE_BELORN,    DATA_CHAOS_MAGE_BELORN },
    { NPC_SUMMONER_XIV,         DATA_SUMMONER_XIV },
    { NPC_FELWEAVER_PHARAMERE,  DATA_FELWEAVER_PHARAMERE },

    { NPC_TICHONDRIUS,          DATA_TICHONDRIUS },

    { NPC_ELISANDE,             DATA_ELISANDE },
    { NPC_GULDAN,               DATA_GULDAN },
    { NPC_CRYSTALL_OF_ILLIDAN,  NPC_CRYSTALL_OF_ILLIDAN },
    { 0,                        0 } // END
};

ObjectData const objectData[] =
{
    { GO_ANOMALY_PRE,       GO_ANOMALY_PRE          },
    { GO_KROSUS_PLATFORM1,  DATA_KROSUS_PLATFORM1   },
    { GO_KROSUS_PLATFORM2,  DATA_KROSUS_PLATFORM2   },
    { GO_KROSUS_PLATFORM3,  DATA_KROSUS_PLATFORM3   },
    { GO_KROSUS_PLATFORM4,  DATA_KROSUS_PLATFORM4   },
    { GO_EYE_OF_AMANTUL,    GO_EYE_OF_AMANTUL       },
    { GO_STATUE_1,          GO_STATUE_1             },
    { GO_STATUE_2,          GO_STATUE_2             },
    { GO_STATUE_3,          GO_STATUE_3             },
    { GO_STATUE_4,          GO_STATUE_4             },
    { GO_ROOM,              GO_ROOM             },
    { 0,                    0,                      }
};

class instance_the_nightnold : public InstanceMapScript
{
public:
    instance_the_nightnold() : InstanceMapScript(NightholdScriptName, 1530) {}

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_the_nightnold_InstanceMapScript(map);
    }

    struct instance_the_nightnold_InstanceMapScript : InstanceScript
    {
        explicit instance_the_nightnold_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetBossNumber(MAX_ENCOUNTER);
        }

        std::vector<ObjectGuid> talysraGUID;
        WorldLocation loc_res_pla;
        ObjectGuid trilliaxImprintDoorGUID[2];
        ObjectGuid KrosusChest;
        ObjectGuid GuldanChest;
        uint32 trilliaxIntro{};
        uint32 checkTimer{};
        uint8 StarAugurEtraeusPhaseID{};
        uint8 StarAugurEtraeusGravityPullCounter{};
        uint8 KrosusIntroTrash{};
        uint8 KrosusIntroTrashAlives{};

        std::vector<ObjectGuid> addsDeleteAfterAlurielGUID{};
        std::vector<ObjectGuid> visibleAfterGuldanGUID{};
        bool introDone{};

        void Initialize() override
        {
            LoadDoorData(doorData);
            LoadObjectData(creatureData, objectData);
        }

        void OnPlayerEnter(Player* player) override
        {

            introDone = true;
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            if (creature->GetDistance(557.93f, 3409.94f, 109.45f) <= 40.0f)
            {
                if (GetBossState(DATA_ALURIEL) != DONE)
                    addsDeleteAfterAlurielGUID.push_back(creature->GetGUID());
                else
                    creature->DespawnOrUnsummon(5000); // permanent despawn
            }

            switch (creature->GetEntry())
            {
            case NPC_TALYSRA:
                talysraGUID.push_back(creature->GetGUID());
                break;
            case NPC_IMGAGE_OF_KADGNAR:
                if (GetBossState(DATA_KROSUS) != DONE)
                    creature->SetVisible(false);
                break;
            case NPC_KROSUS:
                if (GetData(DATA_KROSUS_INTRO_TRASH) != DONE && KrosusIntroTrashAlives != 0)
                    creature->SetVisible(false);
                break;
            case NPC_FELWEAVER_PHARAMERE:
            case NPC_SUMMONER_XIV:
            case NPC_CHAOS_MAGE_BELORN:
                if (!creature->isDead())
                    KrosusIntroTrashAlives++;
                break;

            case 114838:
            case 115499:
            case 116372:
            case 115840:
            case 114883:
            case 114841:
            case 116146:
            case 106522:
                if (creature->GetPositionZ() >= 460.0f)
                {
                    creature->SetVisible(false);
                    visibleAfterGuldanGUID.push_back(creature->GetGUID());
                }
                break;
            case NPC_TALYSRA_ADDS:
            case NPC_TALYSRA_ADDS_1:
                creature->SetReactState(REACT_PASSIVE);
                creature->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
                creature->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
                creature->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
                creature->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
                break;
            default:
                break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            InstanceScript::OnGameObjectCreate(go);

            switch (go->GetEntry())
            {
            case GO_TRILLIAX_DOOR_3:
                trilliaxImprintDoorGUID[0] = go->GetGUID();
                break;
            case GO_TRILLIAX_DOOR_4:
                trilliaxImprintDoorGUID[1] = go->GetGUID();
                break;
            case GO_KROSUS_CHEST:
                KrosusChest = go->GetGUID();
                break;
            case GO_GULDAN_CHEST:
                GuldanChest = go->GetGUID();
                break;
            case GO_STATUE_2:
            case GO_STATUE_3:
            case GO_STATUE_4:
                break;
            default:
                break;
            }
        }

        void OnGameObjectRemove(GameObject* go) override
        {
            InstanceScript::OnGameObjectRemove(go);
        }


        bool SetBossState(uint32 type, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(type, state))
                return false;

            switch (state)
            {
            case NOT_STARTED:
            {
                switch (type)
                {
                case DATA_GULDAN:
                    if (GameObject* go = instance->GetGameObject(GetGuidData(GO_ROOM)))
                        go->SetDestructibleState(GO_DESTRUCTIBLE_INTACT);
                    break;
                }
                break;
            }
            case DONE:
            {
                switch (type)
                {
                case DATA_KROSUS:
                    if (auto kadghar = GetCreature(DATA_IMAGE_OF_KADGHAR))
                    {
                        kadghar->SetVisible(true);
                        kadghar->CastSpell(kadghar, 220061);
                    }
                    if (GameObject* chest = instance->GetGameObject(KrosusChest))
                        chest->SetRespawnTime(86400);
                    break;
                case DATA_ALURIEL:
                    for (auto guid : addsDeleteAfterAlurielGUID)
                        if (auto creature = instance->GetCreature(guid))
                            creature->DespawnOrUnsummon(5000);
                    break;
                case DATA_GULDAN:
                    if (!instance->IsMythic())
                        if (GameObject* chest = instance->GetGameObject(GuldanChest))
                            chest->SetRespawnTime(86400);
                    for (auto guid : visibleAfterGuldanGUID)
                        if (auto creature = instance->GetCreature(guid))
                            creature->SetVisible(true);
                    break;
                default:
                    break;
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
            switch (type)
            {
            case DATA_TRILLIAX_INTRO:
                trilliaxIntro = data;
                SaveToDB();
                break;
            case DATA_TRILLIAX_IMPRINT_DOOR:
            {
                switch (data)
                {
                case 0:
                    HandleGameObject(trilliaxImprintDoorGUID[0], false);
                    break;
                case 1:
                    HandleGameObject(trilliaxImprintDoorGUID[0], true);
                    break;
                case 2:
                    HandleGameObject(trilliaxImprintDoorGUID[1], false);
                    break;
                case 3:
                    HandleGameObject(trilliaxImprintDoorGUID[1], true);
                    break;
                }
                break;
            }
            case DATA_STAR_AUGUR_ETRAEUS_PHASE:
                StarAugurEtraeusPhaseID = data;
                break;
            case DATA_STAR_AUGUR_ETRAEUS_GRAVITY_PULL_COUNTER:
                StarAugurEtraeusGravityPullCounter = data;
                break;
            case DATA_KROSUS_INTRO_TRASH:
                KrosusIntroTrash = data;
                if (data == DONE)
                    if (auto krosus = GetCreature(DATA_KROSUS))
                    {
                        krosus->SetVisible(true);
                        krosus->CastSpell(krosus, 208495);
                    }
                break;
            default:
                break;
            }
        }


        void Load(const char* data) override
        {

            char dataHead1, dataHead2;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2;

            if (dataHead1 == 'N' && dataHead2 == 'H')
            {
                for (uint32 i = 0; i < MAX_ENCOUNTER; ++i)
                {
                    uint32 tmpState;
                    loadStream >> tmpState;
                    if (tmpState == IN_PROGRESS || tmpState > SPECIAL)
                        tmpState = NOT_STARTED;
                    SetBossState(i, EncounterState(tmpState));
                }
                loadStream >> trilliaxIntro >> KrosusIntroTrash;
            }

        }

        void Update(uint32 diff) override
        {
            if (checkTimer <= diff)
            {
                checkTimer = 3000;

                DoOnPlayers([](Player* player)
                {
                    if (player->IsWithinBox({ -108.188f, 2798.724f, 3.162f }, 200.f, 200.f, 10.f) && player->IsInWater())
                        player->CastSpell(player, 27965, true);
                });
            }
            else
                checkTimer -= diff;
        }
    };
};

void AddSC_instance_the_nighthold()
{
    new instance_the_nightnold();
}
