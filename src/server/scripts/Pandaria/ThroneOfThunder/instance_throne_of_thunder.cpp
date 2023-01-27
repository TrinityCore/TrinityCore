#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "throne_of_thunder.h"

DoorData const doorData[] =
{
    { GOB_JIN_ROKH_ENTRANCE, DATA_JINROKH, DOOR_TYPE_ROOM, BOUNDARY_NONE },
    { GOB_JIN_ROKH_EXIT, DATA_JINROKH, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GOB_HORRIDON_ENTRANCE, DATA_HORRIDON, DOOR_TYPE_ROOM, BOUNDARY_NONE },
    { GOB_HORRIDON_EXIT, DATA_HORRIDON, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GOB_COUNCIL_ENTRANCE1, DATA_COUNCIL_OF_ELDERS, DOOR_TYPE_ROOM, BOUNDARY_NONE },
    { GOB_COUNCIL_ENTRANCE2, DATA_COUNCIL_OF_ELDERS, DOOR_TYPE_ROOM, BOUNDARY_NONE },
    { GOB_COUNCIL_EXIT, DATA_COUNCIL_OF_ELDERS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GOB_TORTOS_DOOR, DATA_TORTOS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GOB_TORTOS_COLLISION, DATA_TORTOS, DOOR_TYPE_SPAWN_HOLE, BOUNDARY_NONE },
    { GOB_MEGAERA_EXIT, DATA_MEGAERA, DOOR_TYPE_PASSAGE, BOUNDARY_NONE },
    { GOB_PRIMORDIUS_ENTRANCE, DATA_PRIMORDIUS, DOOR_TYPE_ROOM, BOUNDARY_S },
    { GOB_PRIMORDIUS_EXIT, DATA_PRIMORDIUS, DOOR_TYPE_PASSAGE, BOUNDARY_NONE }
};

typedef std::unordered_map<uint32, uint64> EntryGuidMap;

class instance_throne_of_thunder : public InstanceMapScript
{
public:
    instance_throne_of_thunder() : InstanceMapScript("instance_throne_of_thunder", 1098) { }


    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_throne_of_thunder_InstanceScript(map);
    }

    struct instance_throne_of_thunder_InstanceScript : public InstanceScript
    {
        instance_throne_of_thunder_InstanceScript(InstanceMap* map) : InstanceScript(map)
        {
        }

        EntryGuidMap m_mNpcGuidStorage;
        EntryGuidMap m_mGoGuidStorage;
        EventMap m_mEvents;

        uint64 horridonHelperGuid;
        uint64 megaeraChestGuid;

        uint32 m_auiEncounter[MAX_TYPES];
        std::string strSaveData;
        std::list<uint64> m_lMoguBellGuids;


        void Initialize() override
        {
            SetBossNumber(MAX_DATA);
            LoadDoorData(doorData);

            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));
        }

        bool SetBossState(uint32 uiId, EncounterState eState) override
        {
            //TC_LOG_ERROR("scripts", "SetBossState called type%u, state %u, instance id %u", uiId, (uint32)eState, instance->GetInstanceId());
            if (!InstanceScript::SetBossState(uiId, eState))
                return false;

            if (uiId >= MAX_DATA)
                return false;

            switch (uiId)
            {
            case DATA_JINROKH:
            case DATA_HORRIDON:
            case DATA_COUNCIL_OF_ELDERS:
            case DATA_TORTOS:
            case DATA_MEGAERA:
            case DATA_JI_KUN:
            case DATA_DURUMU_THE_FORGOTTEN:
            case DATA_PRIMORDIUS:
            case DATA_DARK_ANIMUS:
            case DATA_IRON_QON:
            case DATA_TWIN_CONSORTS:
            case DATA_LEI_SHEN:
            case DATA_RA_DEN:
                SetData(uiId, (uint32)eState);
                break;
            default:
                break;
            }

            return true;
        }


        void SetData64(uint32 uiType, uint64 uiData) override
        {
            switch (uiType)
            {
            case MOB_GARA_JALS_SOUL:
                m_mNpcGuidStorage[MOB_GARA_JALS_SOUL] = uiData;
                break;
            default:
                break;
            }
        }

        uint64 GetData64(uint32 uiType) const
        {
            switch (uiType)
            {
                // Creatures here
            case BOSS_JINROKH:
            case BOSS_HORRIDON:
            case BOSS_COUNCIL_KAZRAJIN:
            case BOSS_COUNCIL_SUL_THE_SANDCRAWLER:
            case BOSS_COUNCIL_FROST_KING_MALAKK:
            case BOSS_COUNCIL_HIGH_PRIESTESS_MARLI:
            case BOSS_TORTOS:
            case BOSS_MEGAERA:
            case BOSS_JI_KUN:
            case BOSS_DURUMU_THE_FORGOTTEN:
            case BOSS_PRIMORDIUS:
            case BOSS_DARK_ANIMUS:
            case BOSS_IRON_QON:
            case BOSS_LULIN:
            case BOSS_SUEN:
            case BOSS_LEI_SHEN:
            case BOSS_RA_DEN:
            case MOB_GARA_JAL:
            case MOB_GARA_JALS_SOUL:
            case MOB_WAR_GOD_JALAK:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(uiType);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_JINROKH:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_JINROKH);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_HORRIDON:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_HORRIDON);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_COUNCIL_OF_ELDERS:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(MOB_GARA_JAL);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_TORTOS:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_TORTOS);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_MEGAERA:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_MEGAERA);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_JI_KUN:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_JI_KUN);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_DURUMU_THE_FORGOTTEN:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_DURUMU_THE_FORGOTTEN);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_PRIMORDIUS:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_PRIMORDIUS);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_DARK_ANIMUS:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(NPC_AREATRIGGER_ANIMA);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_IRON_QON:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(NPC_IRON_QON);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_TWIN_CONSORTS:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(NPC_LULIN);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_LEI_SHEN:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(NPC_LEI_SHEN);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case DATA_RA_DEN:
            {
                EntryGuidMap::const_iterator find = m_mNpcGuidStorage.find(BOSS_RA_DEN);
                if (find != m_mNpcGuidStorage.cend())
                    return find->second;
                return 0;
                break;
            }
            case NPC_HORRIDON_EVENT_HELPER:
                return horridonHelperGuid;
                // Gameobjects below here #####
                // ############################
                // ############################
            case GOB_JIN_ROKH_ENTRANCE:
            case GOB_JIN_ROKH_PREDOOR:
            case GOB_JIN_ROKH_EXIT:
            case GOB_HORRIDON_ENTRANCE:
            case GOB_HORRIDON_EXIT:
            case GOB_COUNCIL_ENTRANCE1:
            case GOB_COUNCIL_ENTRANCE2:
            case GOB_COUNCIL_EXIT:
            case GOB_TORTOS_DOOR:
            case GOB_TORTOS_COLLISION:
            case GOB_MEGAERA_EXIT:
            case GOB_TRIBAL_DOOR_FARRAKI:
            case GOB_TRIBAL_DOOR_GURUBASHI:
            case GOB_TRIBAL_DOOR_DRAKKARI:
            case GOB_TRIBAL_DOOR_AMANI:
            case GOB_MOGU_STATUE_1:
            case GOB_MOGU_STATUE_2:
            case GOB_MOGU_STATUE_3: 
            case GOB_MOGU_STATUE_4:
            case GOB_JIKUN_FEATHER:
            case GOB_PRIMORDIUS_ENTRANCE:
            case GOB_PRIMORDIUS_EXIT:
            {
                EntryGuidMap::const_iterator find = m_mGoGuidStorage.find(uiType);
                if (find != m_mGoGuidStorage.cend())
                    return find->second;
                return 0;
            }
            case GOB_MEGAERA_CHEST:
                return megaeraChestGuid;
            default:
                return 0;
            }

            return 0;
        }

        std::string GetSaveData() override
        {
            return strSaveData;
        }
    };
};

void AddSC_instance_throne_of_thunder()
{
    new instance_throne_of_thunder();
}
