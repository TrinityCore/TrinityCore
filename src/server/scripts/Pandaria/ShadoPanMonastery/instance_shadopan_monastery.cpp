/*
Dungeon : Shandopan Monastery 87-89
Instance General Script
*/

#include "shadopan_monastery.h"
#include "InstanceScript.h"

Position snowdriftCenterPos = {3659.08f, 3015.38f, 804.74f};

class instance_shadopan_monastery : public InstanceMapScript
{
public:
    instance_shadopan_monastery() : InstanceMapScript("instance_shadopan_monastery", 959) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_shadopan_monastery_InstanceMapScript(map);
    }

    struct instance_shadopan_monastery_InstanceMapScript : public InstanceScript
    {
        uint8 aliveNoviceCount;
        uint8 aliveMinibossCount;

        uint64 guCloudstikeGuid;
        uint64 masterSnowdriftGuid;
        uint64 shaViolenceGuid;
        uint64 taranZhuGuid;

        uint64 azureSerpentGuid;

        uint64 cloudstikeEntranceGuid;
        uint64 cloudstikeExitGuid;
        uint64 snowdriftEntranceGuid;
        uint64 snowdriftPossessionsGuid;
        uint64 snowdriftFirewallGuid;
        uint64 snowdriftDojoDoorGuid;
        uint64 snowdriftExitGuid;

        uint64 shaEntranceGuid;
        uint64 shaExitGuid;

        uint64 taranzhuPossessionsGuid;

        std::list<uint64> minibossPositionsGuid;
        std::list<uint64> firstDefeatedNovicePositionsGuid;
        std::list<uint64> secondDefeatedNovicePositionsGuid;

        std::list<uint64> firstArcherySet;
        std::list<uint64> secondArcherySet;
        std::list<uint64> archeryTargetGuids;

        uint32 dataStorage[MAX_DATA];

        instance_shadopan_monastery_InstanceMapScript(Map* map) : InstanceScript(map)
        {}

        void Initialize()
        {
            SetBossNumber(EncounterCount);

            aliveNoviceCount            = MAX_NOVICE;
            aliveMinibossCount          = 2;

            guCloudstikeGuid            = 0;
            masterSnowdriftGuid         = 0;
            shaViolenceGuid             = 0;
            taranZhuGuid                = 0;

            azureSerpentGuid            = 0;

            cloudstikeEntranceGuid      = 0;
            cloudstikeExitGuid          = 0;
            snowdriftEntranceGuid       = 0;
            snowdriftEntranceGuid       = 0;
            snowdriftPossessionsGuid    = 0;
            snowdriftFirewallGuid       = 0;
            snowdriftDojoDoorGuid       = 0;
            snowdriftExitGuid           = 0;

            shaEntranceGuid             = 0;
            shaExitGuid                 = 0;

            taranzhuPossessionsGuid     = 0;

            firstArcherySet.clear();
            secondArcherySet.clear();

            memset(dataStorage, 0, MAX_DATA * sizeof(uint32));
        }

        bool IsInTable(Position pos, Position posTable[], uint8 tableSize)
        {
            for (uint8 i = 0; i < tableSize; ++i)
                if (pos == posTable[i])
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_GU_CLOUDSTRIKE:    guCloudstikeGuid    = creature->GetGUID().GetEntry();          return;
            case NPC_MASTER_SNOWDRIFT:  masterSnowdriftGuid = creature->GetGUID().GetEntry();          return;
            case NPC_SHA_VIOLENCE:      shaViolenceGuid     = creature->GetGUID().GetEntry();          return;
            case NPC_TARAN_ZHU:         taranZhuGuid        = creature->GetGUID().GetEntry();          return;
            case NPC_AZURE_SERPENT:     azureSerpentGuid    = creature->GetGUID().GetEntry();          return;
            case NPC_ARCHERY_TARGET:    archeryTargetGuids.push_back(creature->GetGUID().GetEntry());  return;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
            case GO_CLOUDSTRIKE_ENTRANCE:
                cloudstikeEntranceGuid = go->GetGUID().GetEntry();
                HandleGameObject(GetObjectGuid(0), true, go);
                break;
            case GO_CLOUDSTRIKE_EXIT:
                cloudstikeExitGuid = go->GetGUID().GetEntry();
                break;
            case GO_SNOWDRIFT_ENTRANCE:
                snowdriftEntranceGuid = go->GetGUID().GetEntry();
                HandleGameObject(GetObjectGuid(0), true, go);
                break;
            case GO_SNOWDRIFT_POSSESSIONS:
                go->SetPhaseMask(2, true);
                snowdriftPossessionsGuid = go->GetGUID().GetEntry();
                break;
            case GO_SNOWDRIFT_FIRE_WALL:
                snowdriftFirewallGuid = go->GetGUID().GetEntry();
                break;
            case GO_SNOWDRIFT_DOJO_DOOR:
                snowdriftDojoDoorGuid = go->GetGUID().GetEntry();
                break;
            case GO_SNOWDRIFT_EXIT:
                snowdriftExitGuid = go->GetGUID().GetEntry();
                break;
            case GO_SHA_ENTRANCE:
                shaEntranceGuid = go->GetGUID().GetEntry();
                HandleGameObject(GetObjectGuid(0), true, go);
                break;
            case GO_SHA_EXIT:
                shaExitGuid = go->GetGUID().GetEntry();
                break;
            case GO_TARANZHU_POSSESSIONS:
                go->SetPhaseMask(2, true);
                taranzhuPossessionsGuid = go->GetGUID().GetEntry();
                break;
            default:
                return;
            }
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
            case DATA_GU_CLOUDSTRIKE:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case FAIL:
                        {
                            HandleGameObject(GetObjectGuid(cloudstikeEntranceGuid), true);
                            HandleGameObject(GetObjectGuid(cloudstikeExitGuid),     false);
                            break;
                        }
                    case IN_PROGRESS:
                        {
                            HandleGameObject(GetObjectGuid(cloudstikeEntranceGuid), false);
                            HandleGameObject(GetObjectGuid(cloudstikeExitGuid),     false);
                            break;
                        }
                    case DONE:
                        {
                            HandleGameObject(GetObjectGuid(cloudstikeEntranceGuid), true);
                            HandleGameObject(GetObjectGuid(cloudstikeExitGuid),     true);
                            HandleGameObject(GetObjectGuid(snowdriftEntranceGuid),  true);
                            break;
                        }
                    default:
                        break;
                    }
                    break;
                }
            case DATA_MASTER_SNOWDRIFT:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case FAIL:
                        aliveNoviceCount = MAX_NOVICE;
                        aliveMinibossCount = 2;
                        minibossPositionsGuid.clear();
                        firstDefeatedNovicePositionsGuid.clear();
                        secondDefeatedNovicePositionsGuid.clear();

                        HandleGameObject(GetObjectGuid(snowdriftEntranceGuid), true);
                        HandleGameObject(GetObjectGuid(snowdriftFirewallGuid), false);
                        HandleGameObject(GetObjectGuid(snowdriftDojoDoorGuid), false);
                        HandleGameObject(GetObjectGuid(snowdriftExitGuid), false);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(GetObjectGuid(snowdriftEntranceGuid), false);
                        HandleGameObject(GetObjectGuid(snowdriftDojoDoorGuid), false);
                        break;
                    case DONE:
                        if (GameObject* possessions = instance->GetGameObject(GetObjectGuid(snowdriftPossessionsGuid)))
                            possessions->SetPhaseMask(1, true);

                        HandleGameObject(GetObjectGuid(snowdriftEntranceGuid), true);
                        HandleGameObject(GetObjectGuid(snowdriftFirewallGuid), true);
                        HandleGameObject(GetObjectGuid(snowdriftDojoDoorGuid), true);
                        HandleGameObject(GetObjectGuid(snowdriftExitGuid),     true);
                        HandleGameObject(GetObjectGuid(shaEntranceGuid),       true);
                        break;
                    default:
                        break;
                    }
                    break;
                }
            case DATA_SHA_VIOLENCE:
                {
                    switch (state)
                    {
                    case NOT_STARTED:
                    case FAIL:
                        HandleGameObject(GetObjectGuid(shaEntranceGuid),   true);
                        HandleGameObject(GetObjectGuid(shaExitGuid),       false);
                        break;
                    case IN_PROGRESS:
                        HandleGameObject(GetObjectGuid(shaEntranceGuid),   false);
                        break;
                    case DONE:
                        HandleGameObject(GetObjectGuid(shaEntranceGuid),   true);
                        HandleGameObject(GetObjectGuid(shaExitGuid),       true);
                        break;
                    default:
                        break;
                    }
                    break;
                }
            case DATA_TARAN_ZHU:
                {
                    if (state == IN_PROGRESS)
                        DoCastSpellOnPlayers(SPELL_HATE);
                    else
                    {
                        Map::PlayerList const &PlayerList = instance->GetPlayers();

                        if (!PlayerList.isEmpty())
                            for (Map::PlayerList::const_iterator i = PlayerList.begin(); i != PlayerList.end(); ++i)
                                if (Player* player = i->GetSource())
                                {
                                    player->RemoveAurasDueToSpell(SPELL_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE);
                                    player->RemoveAurasDueToSpell(SPELL_HAZE_OF_HATE_VISUAL);
                                }
                    }

                    if (state == DONE)
                        if (GameObject* possessions = instance->GetGameObject(GetObjectGuid(taranzhuPossessionsGuid)))
                            possessions->SetPhaseMask(1, true);
                    break;
                }
            default:
                break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
            case DATA_DEFEATED_NOVICE:
                {
                    if (!--aliveNoviceCount)
                        if (Creature* snowdrift = instance->GetCreature(GetObjectGuid(masterSnowdriftGuid)))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_NOVICE_DONE);
                    break;
                }
            case DATA_DEFEATED_MINIBOSS:
                {
                    if (!--aliveMinibossCount)
                    {
                        if (Creature* snowdrift = instance->GetCreature(GetObjectGuid(masterSnowdriftGuid)))
                            if (snowdrift->IsAIEnabled)
                                snowdrift->AI()->DoAction(ACTION_MINIBOSS_DONE);
                    }
                    break;
                }
            case DATA_OPEN_DOORS:
                {
                    HandleGameObject(GetObjectGuid(snowdriftFirewallGuid), true);
                    HandleGameObject(GetObjectGuid(snowdriftDojoDoorGuid), true);
                    break;
                }
            default:
                {
                    if (type < MAX_DATA)
                        dataStorage[type] = data;
                    break;
                }
            }
        }

        uint32 GetData(uint32 type) const override
        {
            if (type < MAX_DATA)
                return dataStorage[type];

            return 0;
        }

        uint64 GetData64(uint32 type) const override
        {
            switch (type)
            {
            case NPC_GU_CLOUDSTRIKE:        return guCloudstikeGuid;
            case NPC_MASTER_SNOWDRIFT:      return masterSnowdriftGuid;
            case NPC_SHA_VIOLENCE:          return shaViolenceGuid;
            case NPC_TARAN_ZHU:             return taranZhuGuid;
            case NPC_AZURE_SERPENT:         return azureSerpentGuid;
            case NPC_ARCHERY_TARGET:        return Trinity::Containers::SelectRandomContainerElement(archeryTargetGuids);
            case DATA_RANDOM_FIRST_POS:
                {
                    if (firstDefeatedNovicePositionsGuid.empty())
                        return 0;

                    return Trinity::Containers::SelectRandomContainerElement(firstDefeatedNovicePositionsGuid);
                }
            case DATA_RANDOM_SECOND_POS:
                {
                    if (secondDefeatedNovicePositionsGuid.empty())
                        return 0;

                    return Trinity::Containers::SelectRandomContainerElement(secondDefeatedNovicePositionsGuid);
                }
            case DATA_RANDOM_MINIBOSS_POS:
                {
                    if (minibossPositionsGuid.empty())
                        return 0;

                    return Trinity::Containers::SelectRandomContainerElement(minibossPositionsGuid);
                }
            }

            return 0;
        }

        void SetData64(uint32 type, uint64 value)
        {
            switch (type)
            {
            case DATA_ADD_FIRST_POS:
                firstDefeatedNovicePositionsGuid.push_back(value);
                break;
            case DATA_ADD_SECOND_POS:
                secondDefeatedNovicePositionsGuid.push_back(value);
                break;
            case DATA_ADD_MINIBOSS_POS:
                minibossPositionsGuid.push_back(value);
                break;
            case DATA_DELETE_FIRST_POS:
                firstDefeatedNovicePositionsGuid.remove(value);
                break;
            case DATA_DELETE_SECOND_POS:
                secondDefeatedNovicePositionsGuid.remove(value);
                break;
            case DATA_DELETE_MINIBOSS_POS:
                minibossPositionsGuid.remove(value);
                break;
            default:
                break;
            }
        }
    };

};

void AddSC_instance_shadopan_monastery()
{
    new instance_shadopan_monastery();
}
