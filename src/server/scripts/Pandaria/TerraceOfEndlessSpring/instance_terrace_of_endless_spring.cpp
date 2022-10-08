#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "VMapFactory.h"
#include "terrace_of_endless_spring.h"
#include "Log.h"
#include "SpellAuras.h"

class isProtectorDeadPredicate
{
public:
    bool operator()(Unit* target) const
    {
        return target && !target->IsAlive();
    }
};

class instance_terrace_of_endless_spring : public InstanceMapScript
{
public:
    instance_terrace_of_endless_spring() : InstanceMapScript("instance_terrace_of_endless_spring", 996) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_terrace_of_endless_spring_InstanceMapScript(map);
    }

    struct instance_terrace_of_endless_spring_InstanceMapScript : public InstanceScript
    {
        instance_terrace_of_endless_spring_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
        }

        EventMap m_mEvents;
        uint32 m_auiEncounter[MAX_TYPES];
        std::string strSaveData;

        std::list<Unit*> protectorList;
        std::vector<uint64> animatedList;
        std::vector<uint64> returnTerraceList;

        bool ritualOfPurification;
        bool introDone;

        // Protectors of the Endless
        ObjectGuid ancientRegailGuid;
        ObjectGuid ancientAsaniGuid;
        ObjectGuid protectorKaolanGuid;
        ObjectGuid minionOfFearControllerGuid;

        // Tsulong
        ObjectGuid tsulongGuid;

        // Lei Shi
        ObjectGuid leiShiGuid;
        ObjectGuid leiShiReflectionGuid;

        // Sha of Fear
        ObjectGuid shaOfFearGuid;
        ObjectGuid pureLightTerraceGuid;

        ObjectGuid shaVortexGuid;
        ObjectGuid shaVortexWallGuid;

        // Council's Vortex
        ObjectGuid wallOfCouncilsVortexGuid;
        ObjectGuid councilsVortexGuid;

        // Lei Shi's Vortex
        ObjectGuid wallOfLeiShisVortexGuid;
        ObjectGuid leiShisVortexGuid;

        ObjectGuid tsulongChestGUID;
        ObjectGuid leishiChestsGUID;

        void Initialize()
        {
            SetBossNumber(DATA_MAX_BOSS_DATA);

            // 5.2
            ritualOfPurification = false;
            introDone = false;

            ancientRegailGuid = ObjectGuid::Empty;
            ancientAsaniGuid = ObjectGuid::Empty;
            protectorKaolanGuid = ObjectGuid::Empty;
            minionOfFearControllerGuid = ObjectGuid::Empty;

            tsulongGuid = ObjectGuid::Empty;

            leiShiGuid = ObjectGuid::Empty;
            leiShiReflectionGuid = ObjectGuid::Empty;

            shaOfFearGuid = ObjectGuid::Empty;
            pureLightTerraceGuid = ObjectGuid::Empty;

            wallOfCouncilsVortexGuid = ObjectGuid::Empty;
            councilsVortexGuid = ObjectGuid::Empty;

            wallOfLeiShisVortexGuid = ObjectGuid::Empty;
            leiShisVortexGuid = ObjectGuid::Empty;

            tsulongChestGUID = ObjectGuid::Empty;
            leishiChestsGUID = ObjectGuid::Empty;

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            m_mEvents.ScheduleEvent(8, 100);
            //printf("Scheduled event 8 Check Lei Shi Protectors \n");
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_RETURN_TO_TERRACE:
                //returnTerraceList.push_back(creature->GetGUID());
                break;
            case NPC_ANCIENT_ASANI:
                ancientAsaniGuid = creature->GetGUID();
                break;
            case NPC_ANCIENT_REGAIL:
                ancientRegailGuid = creature->GetGUID();
                break;
            case NPC_PROTECTOR_KAOLAN:
                protectorKaolanGuid = creature->GetGUID();
                break;
            case NPC_MINION_OF_FEAR_CONTROLLER:
                minionOfFearControllerGuid = creature->GetGUID();
                break;
            case NPC_TSULONG:
                tsulongGuid = creature->GetGUID();
                break;
            case NPC_LEI_SHI:
                leiShiGuid = creature->GetGUID();
                instance->LoadGrid(creature->GetPositionX(), creature->GetPositionY());
                break;
            case NPC_SHA_OF_FEAR:
                shaOfFearGuid = creature->GetGUID();
                break;
            case NPC_PURE_LIGHT_TERRACE:
                pureLightTerraceGuid = creature->GetGUID();
                break;
            case NPC_CORRUPTED_PROTECTOR:
                if (creature->IsAlive())
                    protectorList.push_back(creature);
                break;
            case NPC_ANIMATED_PROTECTOR:
               //animatedList.push_back(creature->GetGUID());
                break;
            case NPC_REFLECTION_OF_LEI_SHI:
                leiShiReflectionGuid = creature->GetGUID();
            default:
                break;
            }
        }

        void RewardCurrencyForPlayers(Creature* creature)
        {
            Map::PlayerList const& lPlayers = instance->GetPlayers();
            for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                if (Player* const player = itr->GetSource())
                    player->ModifyCurrency(CURRENCY_TYPE_VALOR_POINTS, 4000);

            // armory feed
            /*if (creature)
                for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    if (Player * const player = itr->GetSource())
                        if (!player->IsGameMaster())
                            FREAKZ_WriteWowArmoryDatabaseLog(player, FREAKZ_ARMORY_ACTION_BOSS_KILLED, creature);*/
        }

        bool SetBossState(uint32 id, EncounterState state)
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            if (id == DATA_PROTECTORS && state == DONE)
            {
                if (Creature* c = instance->GetCreature(tsulongGuid))
                {
                    instance->LoadGrid(c->GetPositionX(), c->GetPositionY());
                    c->AI()->DoAction(ACTION_START_TSULONG_WAYPOINT);
                }

                RewardCurrencyForPlayers(instance->GetCreature(protectorKaolanGuid));
            }

            if (id == DATA_TSULONG && state == DONE)
            {
                DoRespawnGameObject(tsulongChestGUID, DAY);
                RewardCurrencyForPlayers(instance->GetCreature(tsulongGuid));

                m_mEvents.ScheduleEvent(8, 200);
            }

            if (id == DATA_LEI_SHI && state == DONE)
            {
                DoRespawnGameObject(leishiChestsGUID, DAY);
                RewardCurrencyForPlayers(instance->GetCreature(leiShiGuid));
            }

            if (id == DATA_SHA_OF_FEAR && state == DONE)
                RewardCurrencyForPlayers(instance->GetCreature(shaOfFearGuid));

            if (id < MAX_TYPES && state == DONE)
                SetData(id, (uint32)state);

            return true;
        }

        void Update(uint32 uiDiff)
        {
            m_mEvents.Update(uiDiff);

            while (uint32 eventId = m_mEvents.ExecuteEvent())
            {
                switch (eventId)
                {
                case 1: // Start Tsulong Movement
                    if (Creature* c = instance->GetCreature(tsulongGuid))
                    {
                        instance->LoadGrid(c->GetPositionX(), c->GetPositionY());
                        c->AI()->DoAction(ACTION_START_TSULONG_WAYPOINT);
                    }
                    break;
                case 3: // Set Tsulong Invisible
                    break;
                case 4: // Make Lei Shi accessible
                    if (Creature* c = instance->GetCreature(leiShiGuid))
                    {
                        instance->LoadGrid(c->GetPositionX(), c->GetPositionY());
                        c->AI()->DoAction(ACTION_LEISHI_INTRO);
                    }
                    break;
                case 5: // 
                    break;
                case 6:
                    if (Creature* asani = instance->GetCreature(ancientAsaniGuid))
                        asani->AI()->DoAction(ACTION_INTRO_FINISHED);

                    if (Creature* regail = instance->GetCreature(ancientRegailGuid))
                        regail->AI()->DoAction(ACTION_INTRO_FINISHED);

                    if (Creature* kaolan = instance->GetCreature(protectorKaolanGuid))
                        kaolan->AI()->DoAction(ACTION_INTRO_FINISHED);
                    break;
                case 7:
                    if (Creature* leiShi = instance->GetCreature(leiShiGuid))
                    {
                        leiShi->SetFaction(35);
                        leiShi->SetVisible(false);

                        if (Creature* leiShiReflection = instance->GetCreature(leiShiReflectionGuid))
                        {
                            leiShiReflection->SetVisible(false);
                        }
                    }

                    if (Creature* c = instance->GetCreature(shaOfFearGuid))
                    {
                        instance->LoadGrid(c->GetPositionX(), c->GetPositionY());
                        c->AI()->DoAction(ACTION_SHA_INTRO);

                    }
                    break;
                case 8:
                    if (GetData(TYPE_LEI_INTRO) == DONE)
                    {
                        //printf("Lei intro tried to double call data. Aborting.");
                        return;
                    }
                    m_mEvents.ScheduleEvent(8, 4000);
                    if (protectorList.empty())
                        if (GetData(TYPE_TSULONG) == DONE)
                            SetData(TYPE_LEI_INTRO, DONE);

                    //printf("Size of list is %u", protectorList.size());
                    protectorList.remove_if(isProtectorDeadPredicate());
                    break;
                case 9:
                    break;
                case 2:
                    Map::PlayerList const& lPlayers = instance->GetPlayers();

                    for (Map::PlayerList::const_iterator itr = lPlayers.begin(); itr != lPlayers.end(); ++itr)
                    {
                        if (Player* pPlayer = itr->GetSource())
                        {
                            if (!pPlayer->HasAura(SPELL_LEIS_HOPE))
                            {
                                if (Aura* pAura = pPlayer->AddAura(SPELL_LEIS_HOPE, pPlayer))
                                {
                                    pAura->SetMaxDuration(3 * HOUR);
                                    pAura->SetDuration(3 * HOUR);
                                }
                            }
                        }
                    }

                    m_mEvents.ScheduleEvent(2, 40000);
                    break;
                }
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            //printf("SetData Called, type %u, data %u \n", type, data);

            if (type >= MAX_TYPES)
            {
                switch (type)
                {
                case SPELL_RITUAL_OF_PURIFICATION:
                    ritualOfPurification = data;
                    break;
                default:
                    break;
                }
            }
            else
            {
                switch (type)
                {
                case TYPE_PROTECTORS:
                case TYPE_TSULONG:
                    m_auiEncounter[type] = data;
                    break;
                case TYPE_SHA:
                    m_auiEncounter[type] = data;
                    break;
                case TYPE_LEI_SHI:
                    if (m_auiEncounter[type] == data)
                        return;
                    m_auiEncounter[type] = data;
                    break;
                case TYPE_LEIS_HOPE:
                    if (data == DONE)
                        m_mEvents.ScheduleEvent(2, 200);
                    m_auiEncounter[type] = data;
                    break;
                case TYPE_LEI_INTRO:
                    if (GetData(TYPE_LEI_INTRO) == DONE)
                        return;

                    if (data == DONE)
                    {
                        if (Creature* pReflection = instance->GetCreature(leiShiReflectionGuid))
                        {
                            if (pReflection->AI())
                                pReflection->AI()->DoAction(ACTION_LEISHI_INTRO);
                        }
                        m_mEvents.CancelEvent(8);
                    }
                    m_auiEncounter[type] = data;
                    break;
                case INTRO_DONE:
                    if (data == DONE)
                    {
                        Creature* asani = instance->GetCreature(ancientAsaniGuid);
                        if (asani)
                            asani->AI()->DoAction(ACTION_INTRO_FINISHED);

                        Creature* regail = instance->GetCreature(ancientRegailGuid);
                        if (regail)
                            regail->AI()->DoAction(ACTION_INTRO_FINISHED);

                        Creature* kaolan = instance->GetCreature(protectorKaolanGuid);
                        if (kaolan)
                            kaolan->AI()->DoAction(ACTION_INTRO_FINISHED);
                    }

                    introDone = data == DONE;
                    m_auiEncounter[type] = data;
                    break;
                }

                if (data >= DONE)
                {
                    OUT_SAVE_INST_DATA;

                    std::ostringstream saveStream;
                    saveStream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' '
                        << m_auiEncounter[3] << ' ' << m_auiEncounter[4] << ' ' << m_auiEncounter[5] << ' ' << m_auiEncounter[6];

                    strSaveData = saveStream.str();

                    SaveToDB();
                    OUT_SAVE_INST_DATA_COMPLETE;
                }
            }
        }

        void Load(const char* chrIn)
        {
            if (!chrIn)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(chrIn);
            std::istringstream loadStream(chrIn);

            loadStream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3] >> m_auiEncounter[4] >> m_auiEncounter[5] >> m_auiEncounter[6];
            for (uint8 i = 0; i < MAX_TYPES; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;

            if (m_auiEncounter[TYPE_PROTECTORS] == DONE)
            {
                if (m_auiEncounter[TYPE_TSULONG] == DONE)
                    m_mEvents.ScheduleEvent(3, 200); // Set Tsulong Invisible
                else
                    m_mEvents.ScheduleEvent(1, 200); // Reactivate Tsulong
            }

            if (m_auiEncounter[TYPE_LEIS_HOPE] == DONE && instance->IsHeroic())
            {
                m_mEvents.ScheduleEvent(2, 200); // Reapply Lei's Hope
                //printf("Scheduled event 2 Reapply Lei's Hope \n");
            }

            if (m_auiEncounter[TYPE_LEI_INTRO] == DONE && m_auiEncounter[TYPE_LEI_SHI] != DONE)
            {
                m_mEvents.ScheduleEvent(4, 200); // Activate Lei Shi
                //printf("Scheduled event 4 Activate Lei Shi \n");
            }

            if (m_auiEncounter[INTRO_DONE] == DONE)
            {
                m_mEvents.ScheduleEvent(5, 200); // Deactivate Protectors Vortex
                //printf("Scheduled event 5 Deactivate Protectors vortex \n");

                if (m_auiEncounter[TYPE_PROTECTORS] != DONE)
                    m_mEvents.ScheduleEvent(6, 200); // Activate Protectors
            }

            if (m_auiEncounter[TYPE_LEI_SHI] == DONE)
            {
                m_mEvents.ScheduleEvent(7, 200); // Deactivate Sha of Fear Vortex
                //printf("Scheduled event 7 Deactivate Sha Vortex \n");
            }

            if (m_auiEncounter[TYPE_SHA] == DONE)
            {
                m_mEvents.ScheduleEvent(9, 200); // Activate return to terrace;
            }

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        std::string GetSaveData()
        {
            return strSaveData;
        }


        bool IsWipe()
        {
            Map::PlayerList const& PlayerList = instance->GetPlayers();

            if (PlayerList.isEmpty())
                return true;

            return false;
        }

        bool CheckRequiredBosses(uint32 bossId, Player const* player = NULL) const
        {
            if (!InstanceScript::CheckRequiredBosses(bossId, player))
                return false;

            switch (bossId)
            {
            case DATA_TSULONG:
            case DATA_LEI_SHI:
            case DATA_SHA_OF_FEAR:
                if (GetBossState(bossId - 1) != DONE)
                    return false;
            default:
                break;
            }

            return true;
        }
    };
};

void AddSC_instance_terrace_of_endless_spring()
{
    new instance_terrace_of_endless_spring();
}
