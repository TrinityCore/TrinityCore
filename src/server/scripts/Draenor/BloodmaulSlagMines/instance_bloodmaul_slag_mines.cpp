#include "bloodmaul_slag_mines.h"

DoorData static const doorData[] =
{
  //{GOB_DOOR,              DATA_BOSS,                      DOOR_TYPE,          BOUNDARY_NONE }
    { 0,                    0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE }
};

typedef std::unordered_map<uint32, ObjectGuid> GUIDMap;
typedef std::set<ObjectGuid> GUIDSet;
typedef std::unordered_map<uint32, uint32> DataMap;

struct instance_bloodmaul_slag_mines_InstanceMapScript : public InstanceScript
{
    instance_bloodmaul_slag_mines_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
    {
    }

    GUIDMap guids;
    DataMap data32;

    void Initialize()
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
        LoadDoorData(doorData);
    }

    void OnCreatureCreate(Creature* creature)
    {
        switch (creature->GetEntry())
        {
            case BOSS_SLAVE_WATCHER_CRUSHTO:
            case BOSS_FORGEMASTER_GOG_DUH:
            case BOSS_ROLTALL:
            case BOSS_GUG_ROKK:
                break;
            default:
                return;
        }

        guids[creature->GetEntry()] = creature->GetGUID();
    }

    //void OnGameObjectCreate(GameObject* go)
    //{
    //    switch (go->GetEntry())
    //    {
    //        case GOB_DOOR:
    //            AddDoor(go, true);
    //        case GOB_SOMETHING:
    //            break;
    //        default:
    //            return;
    //    }
    //
    //    guids[go->GetEntry()] = go->GetGUID();
    //}

    //void OnGameObjectRemove(GameObject* go)
    //{
    //    switch (go->GetEntry())
    //    {
    //        case GOB_DOOR:
    //            AddDoor(go, false);
    //            return;
    //    }
    //}

    bool CheckRequiredBosses(uint32 bossType, Player const* /*player*/ = NULL) const override
    {
        switch (bossType)
        {
            case DATA_SLAVE_WATCHER_CRUSHTO:
            case DATA_FORGEMASTER_GOG_DUH:
            case DATA_ROLTALL:
            case DATA_GUG_ROKK:
            default:
                return true;
        }
    }

    ObjectGuid GetGuidData(uint32 entry) const override
    {
        GUIDMap::const_iterator itr = guids.find(entry);

        if (itr != guids.end())
            return itr->second;

        return ObjectGuid::Empty;
    }

    bool SetBossState(uint32 data, EncounterState state) override
    {
        switch (data)
        {
            case DATA_SLAVE_WATCHER_CRUSHTO:
            case DATA_FORGEMASTER_GOG_DUH:
            case DATA_ROLTALL:
            case DATA_GUG_ROKK:
                break;
        }

        return InstanceScript::SetBossState(data, state);
    }

    uint32 GetData(uint32 entry) const override
    {
        DataMap::const_iterator itr = data32.find(entry);

        if (itr != data32.end())
            return itr->second;

        return 0;
    }

    void SetData(uint32 type, uint32 data) override
    {
        data32[type] = data;
    }
};

void AddSC_instance_bloodmaul_slag_mines()
{
    new InstanceScriptLoaderEx<instance_bloodmaul_slag_mines_InstanceMapScript>(BSMScriptName, 0);
}
