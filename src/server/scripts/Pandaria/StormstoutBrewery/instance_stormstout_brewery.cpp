#include "stormstout_brewery.h"

// Max number of positions where barrels can be summoned
#define MAX_SUMMONING_BARRELS_POSITIONS 6

const Position SummonBarrelsPositions[MAX_SUMMONING_BARRELS_POSITIONS] =
{
    {-743.304077f, 1375.518555f, 146.718872f, 2.957428f},
    {-740.545471f, 1371.434692f, 146.772308f, 3.337561f},
    {-737.850037f, 1356.394775f, 146.784271f, 4.484246f},
    {-778.435669f, 1355.596191f, 146.778900f, 0.289437f},
    {-776.798279f, 1348.759399f, 146.768616f, 5.531971f},
    {-778.306885f, 1354.755127f, 146.779831f, 0.981375f}
};

const WorldLocation TeleportLocation(961, 0.0f, 0.0f, 0.0f, 0.0f);

// Generic Script
class instance_stormstout_brewery : public InstanceMapScript
{
public :
    // Constructor
    instance_stormstout_brewery() : InstanceMapScript("instance_stormstout_brewery", 961)
    {

    }

    // Instance Script
    class instance_stormstout_brewery_InstanceScript : public InstanceScript
    {
    public :
        // Constructor
        instance_stormstout_brewery_InstanceScript(Map* map) : InstanceScript(map)
        {

        }

        // Initialize everything
        void Initialize()
        {
            memset(&m_auiEncounter, NOT_STARTED, sizeof(m_auiEncounter));

            // Guids
            m_uiOokOokGuid                     = 0;
            m_uiHoptallusGuid                 = 0;
            m_uiYanZhuGuid                     = 0;

            m_uiChenGuid                     = 0;

            m_uiOokOokEntranceGuid             = 0;
            m_uiOokOokExitGuid                 = 0;
            m_uiHoptallusEntranceGuid         = 0;
            m_uiHoptallusExitGuid             = 0;
            m_uiYanZhuEntranceGuid             = 0;

            // Ook Ook Event
            m_uiKilledHozens                 = 0;
            // m_bNextWaveFull = true;
            // m_uiBarrelsTimer = 1000;

            // Hoptallus Event
            m_uiHoptallusTrashSummonTimer     = 1000;
            m_uiKilledHoptallusTrash         = 0;
            m_bHoptallusActive                 = false;
            b_allSummoned                     = false;
        }

        // Update timers when world ticks
        void Update(uint32 uiDiff)
        {
            // Quite simple; instead of using a stalker, we handle this here;
            // Update is called at each world's tick

            // Summoning barrels timer
            /*if(GetData(INSTANCE_DATA_OOK_OOK_STATUS) != DONE)
            {
                if(m_uiBarrelsTimer <= uiDiff)
                {
                    //sLog->outDebug(LOG_FILTER_NETWORKIO, "Instance Stormstout Brewery : summoning %u barrel !",  m_bNextWaveFull ? 6 : 1);
                    if(m_bNextWaveFull)
                    {
                        SummonAllBarrels();
                        m_bNextWaveFull = false; // We assume there will not be the need to summon all the barrels twice in a row
                    }
                    else
                        SummonBarrel(urand(0, MAX_SUMMONING_BARRELS_POSITIONS - 1));

                    m_uiBarrelsTimer = 7500;
                }
                else
                    m_uiBarrelsTimer -= uiDiff;
            }*/
            if((GetData(INSTANCE_DATA_OOK_OOK_STATUS) == DONE) && (GetData(INSTANCE_DATA_HOPTALLUS_STATUS) == NOT_STARTED) && !m_bHoptallusActive)
            {
                if(m_uiHoptallusTrashSummonTimer <= uiDiff)
                {
                    uint32 entry;
                    double x = rand()/static_cast<double>(RAND_MAX+1);
                    int that = 1 + static_cast<int>( x * (3 - 1) );

                    switch(that){
                    case 1:
                        entry = 56718;
                        break;
                    case 2:
                        entry = 59426;
                        break;
                    case 3:
                        entry = 56631;
                        break;
                    }

                    Position const summonPosition = {-697.519836f, 1267.453369f, 162.775665f, 1.974109f}; // Summon

                    if(Creature* trash = instance->SummonCreature(entry, summonPosition))
                    {
                        //Position const movePosition = {-710.459900f, 1310.748657f, 162.627029f, 2.754009f}; // Aka, pos 0 (Motion Master)
                        //trash->GetMotionMaster()->MovePoint(0, movePosition);
                        ++m_uiSummonedHoptallusTrash;
                    }
                    m_uiHoptallusTrashSummonTimer = instance->GetDifficultyID() == DIFFICULTY_NORMAL ? 6000 : 4000;
                }
                else
                    m_uiHoptallusTrashSummonTimer -= uiDiff;
            }
        }

        // Better than CAST_AI with stalker
        void ProcessEvent(WorldObject *source, uint32 eventId)
        {
            // Summoning a random barrel
            if(eventId <= INSTANCE_EVENT_SUMMON_BARREL_5)
                SummonBarrel(eventId);
            else if(eventId == INSTANCE_EVENT_SUMMON_ALL)
                SummonAllBarrels();
        }

        void OnPlayerEnter(Player *player)
        {
            if(!b_allSummoned) 
            {
                SummonAllBarrels();
                b_allSummoned = true;
            }

            if(player)
            {
                if(m_uiKilledHozens < 40)
                {
                    player->CastSpell(player, 107297, true);
                    player->SetMaxPower(POWER_ALTERNATE_POWER, 40);
                    player->SetPower(POWER_ALTERNATE_POWER, m_uiKilledHozens);
                }
            }

            if(Creature* chen = instance->GetCreature(GetObjectGuid(m_uiChenGuid)))
                chen->AI()->DoAction(1);
        }

        void OnCreatureCreate(Creature *creature)
        {
            if(creature)
            {
                uint64 guid = creature->GetEntry();
                switch(creature->GetEntry())
                {
                case BOSS_OOK_OOK :
                    m_uiOokOokGuid = guid;
                    break;

                case BOSS_HOPTALLUS :
                    m_uiHoptallusGuid = guid;
                    break;

                case BOSS_YAN_ZHU :
                    m_uiYanZhuGuid = guid;
                    break;

                case NPC_CHEN_STORMSTOUT :
                    m_uiChenGuid = guid;
                    break;

                default :
                    break;
                }
            }
        }

        void OnGameObjectCreate(GameObject *gameObject)
        {
            if(gameObject)
            {
                uint64 guid = gameObject->GetEntry();
                switch(gameObject->GetEntry())
                {
                case GOB_OOK_OOK_ENTRANCE :
                    m_uiOokOokEntranceGuid = guid;
                    gameObject->SetGoState(GO_STATE_ACTIVE);
                    break;
                    
                case GOB_OOK_OOK_EXIT :
                    m_uiOokOokExitGuid = guid;
                    gameObject->SetGoState(GO_STATE_READY);
                    
                    if(GetData(INSTANCE_DATA_OOK_OOK_STATUS) == DONE)
                        gameObject->SetGoState(GO_STATE_ACTIVE);
                        
                    break;

                case GOB_HOPTALLUS_ENTRANCE :
                    m_uiHoptallusEntranceGuid = guid;
                    gameObject->SetGoState(GO_STATE_ACTIVE);
                    break;

                case GOB_HOPTALLUS_EXIT :
                    m_uiHoptallusExitGuid = guid;
                    
                    if(GetData(INSTANCE_DATA_HOPTALLUS_STATUS) == DONE)
                        gameObject->RemoveFromWorld();
                        
                    break;

                case GOB_YAN_ZHU_ENTRANCE :
                    m_uiYanZhuEntranceGuid = guid;
                    gameObject->SetGoState(GO_STATE_ACTIVE);
                    break;

                default :
                    break;
                }
            }
        }

        void SetData(uint32 uiData, uint32 uiStatus)
        {
            // Warning
            if(uiData >= MAX_ENCOUNTERS)
                return;

            m_auiEncounter[uiData] = uiStatus;
            SaveToDB();
        }

        uint32 GetData(uint32 uiData) const
        {
            // Warning
            if(uiData >= MAX_ENCOUNTERS)
                return 0;

            return m_auiEncounter[uiData];
        }

        uint64 GetData64(uint32 uiData) const
        {
            switch(uiData)
            {
            case INSTANCE_DATA64_OOK_OOK_GUID :
                return m_uiOokOokGuid;

            case INSTANCE_DATA64_HOPTALLUS_GUID :
                return m_uiHoptallusGuid;

            case INSTANCE_DATA64_YAN_ZHU_GUID :
                return m_uiYanZhuGuid;

            case INSTANCE_DATA64_OOK_OOK_ENTRANCE_GUID :
                return m_uiOokOokEntranceGuid;

            case INSTANCE_DATA64_HOPTALLUS_ENTRANCE_GUID :
                return m_uiHoptallusEntranceGuid;

            case INSTANCE_DATA64_HOPTALLUS_EXIT_GUID :
                return m_uiHoptallusExitGuid;

            case INSTANCE_DATA64_YAN_ZHU_ENTRANCE_GUID :
                return m_uiYanZhuEntranceGuid;

            case INSTANCE_DATA64_KILLED_HOZENS :
                return m_uiKilledHozens;
                
            case INSTANCE_DATA64_OOK_OOK_EXIT_GUID :
                return m_uiOokOokExitGuid;
                
            default:
                return 0;
            }

            return 0;
        }

        void SetData64(uint32 uiData, uint64 uiValue)
        {
            if(uiData == INSTANCE_DATA64_KILLED_HOZENS)
            {
                m_uiKilledHozens += uiValue;
                if(m_uiKilledHozens == 40)
                {
                    Map::PlayerList const& playerList = instance->GetPlayers();
                    if(!playerList.isEmpty())
                    {
                        for(Map::PlayerList::const_iterator iter = playerList.begin(); iter != playerList.end(); ++iter)
                            if(Player* p = iter->GetSource())
                                p->RemoveAurasByType(SPELL_AURA_ENABLE_ALT_POWER);
                    }
                    DoStartOokOok();
                }
            }
            else if(uiData == INSTANCE_DATA64_SUMMONED_HOPTALLUS_TRASH)
            {
                m_uiSummonedHoptallusTrash += uiValue;
            }
            else if(uiData == INSTANCE_DATA64_KILLED_HOPTALLUS_TRASH)
            {
                m_uiKilledHoptallusTrash += uiValue;
                if(m_uiKilledHoptallusTrash >= m_uiSummonedHoptallusTrash)
                {
                    m_bHoptallusActive = true;
                    // DoStartHoptallus();
                }
            }
        }

        void Load(const char *data)
        {
            if(!data)
            {
                // Do not load if no save data available
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(data);

            char dataHead1, dataHead2;

            std::istringstream loadStream(data);
            loadStream >> dataHead1 >> dataHead2;

            if(dataHead1 == 'S' && dataHead2 == 'B') // Check that the save is correct
            {
                for(uint8 i = 0; i < MAX_ENCOUNTERS; ++i)
                {
                    uint32 data;
                    loadStream >> data;
                    SetData(i, data);

                    if(m_auiEncounter[i] == IN_PROGRESS) // Do not load encounter as "IN PROGRESS"
                        m_auiEncounter[i] = NOT_STARTED;
                }
            }
            else
                OUT_LOAD_INST_DATA_FAIL; // Do not load if save incorrect

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;

            saveStream << "S B" << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        // Summon a barrel using uiIndex as the key inside the array SummonBarrelsPositions;
        // Then, assign this barrel the index as the value to be used when JustDied() is called
        // And make it move to his point (MotionMaster()->MovePoint())
        void SummonBarrel(uint32 uiIndex)
        {
            const Position pos = SummonBarrelsPositions[uiIndex];
            Creature* barrel = instance->SummonCreature(NPC_ROLLING_BARREL, pos, NULL, 0, NULL, 0, VEHICLE_ROLLING_BARREL);
            if(barrel)
            {
                barrel->AI()->SetData(NPC_ROLLING_BARREL_DATA_SUMMONING_ID, uiIndex);
                barrel->AI()->DoAction(0);
            }
        }

        // Just summon all the barrels
        void SummonAllBarrels()
        {
            for(uint8 i = 0; i < MAX_SUMMONING_BARRELS_POSITIONS; ++i)
                SummonBarrel(uint32(i));
        }
        
        // Events starting functions
        
        void DoStartOokOok()
        {
            if(Creature* ookOok = instance->GetCreature(GetObjectGuid(m_uiOokOokGuid)))
                ookOok->AI()->DoAction(0);
        }

        void DoStartHoptallus()
        {
            if(Creature* hoptallus = instance->GetCreature(GetObjectGuid(m_uiHoptallusGuid)))
                hoptallus->AI()->DoAction(0);
        }

    private :
        // Guids of boss
        uint64 m_uiOokOokGuid; // Ook Ook Guid
        uint64 m_uiHoptallusGuid; // Hoptallus Guid
        uint64 m_uiYanZhuGuid; // YanZhu Guid
        
        // Guids of doors
        uint64 m_uiOokOokEntranceGuid; // Big barrel guid (ook ook entrance "door")
        uint64 m_uiOokOokExitGuid; // Standart door
        uint64 m_uiHoptallusEntranceGuid; // Standart door
        uint64 m_uiHoptallusExitGuid; // Big carrot
        uint64 m_uiYanZhuEntranceGuid; // Standart door
        
        // Miscllanous guids
        uint64 m_uiChenGuid; // Chen Stormstout (RP sequence)

        uint32 m_auiEncounter[MAX_ENCOUNTERS]; // Stores status of the encounters
        
        // Miscellanous datas
        uint32 m_uiKilledHozens; // Stores the number of hozen killed; when it reaches 40, start Ook Ook
        uint32 m_uiTeamInInstance; // Alliance or Horde ?
        uint32 m_uiBarrelsTimer; // Timer before next barrel summoning
        uint32 m_uiHoptallusTrashSummonTimer; // Timer before summoning next trash;
        uint32 m_uiSummonedHoptallusTrash; // Each time we summon one, increase this
        uint32 m_uiKilledHoptallusTrash; // Each time one is killed, increse this; when this becomes higher than the summoned number, start Hoptallus

        bool m_bNextWaveFull; // If true, summon all the barrels at one time; else, summon only one
        bool m_bHoptallusActive; // If true, stop summoning npcs
        bool b_allSummoned; // Should we summon all the barrels on player enter ?
    };

    // Get instance script
    InstanceScript* GetInstanceScript(InstanceMap *instance) const
    {
        return new instance_stormstout_brewery_InstanceScript(instance);
    }
};

void AddSC_instance_stormstout_brewery()
{
    new instance_stormstout_brewery();
}
