#include "iron_docks.h"

DoorData static const doorData[] =
{
  //{GOB_DOOR,              DATA_BOSS,                      DOOR_TYPE,          BOUNDARY_NONE }
    { 0,                    0,                              DOOR_TYPE_ROOM,     BOUNDARY_NONE }
};

typedef std::unordered_map<uint32, ObjectGuid> GUIDMap;
typedef std::set<ObjectGuid> GUIDSet;
typedef std::unordered_map<uint32, uint32> DataMap;

struct instance_iron_docks_InstanceMapScript : public InstanceScript
{
    instance_iron_docks_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
    {
    }

    DataMap data32;

    void Initialize() override
    {
        SetHeaders(DataHeader);
        SetBossNumber(EncounterCount);
        LoadDoorData(doorData);
    }

    void OnCreatureCreate(Creature* pCreature) override
    {
        switch (pCreature->GetEntry())
        {
            case BOSS_FLESHRENDER_NOKGAR:
            case NPC_DREADFANG_MOUNTED:
            case NPC_DREADFANG:
            case BOSS_GRIMRAIL_ENFORCERS:
            case NPC_AHRIOK_DUGRU:
            case NPC_MAKOGG_EMBERBLADE:
            case NPC_NEESA_NOX:
            case BOSS_OSHIR:
            case BOSS_SKULLOC:
            case NPC_KORAMAR:
            case NPC_ZOGGOSH:
                break;
            default:
                return;
        }

        AddObject(pCreature, true);
    }

    //void OnGameObjectCreate(GameObject* pGameObject) override
    //{
    //    switch (pGameObject->GetEntry())
    //    {
    //        case GOB_DOOR:
    //            AddDoor(pGameObject, true);
    //        case GOB_SOMETHING:
    //            break;
    //        default:
    //            return;
    //    }
    //
    //    AddObject(pGameObject, true);
    //}

    //void OnGameObjectRemove(GameObject* pGameObject) override
    //{
    //    switch (pGameObject->GetEntry())
    //    {
    //        case GOB_DOOR:
    //            AddDoor(pGameObject, false);
    //            return;
    //    }
    //}

    bool CheckRequiredBosses(uint32 bossType, Player const* /*pPlayer*/ = NULL) const override
    {
        switch (bossType)
        {
            // Descending check order, no breaks
            case DATA_SKULLOC:
            case DATA_OSHIR:
            case DATA_GRIMRAIL_ENFORCERS:
            case DATA_FLESHRENDER_NOKGAR:
                return false;

            default:
                return true;
        }
    }

    bool SetBossState(uint32 data, EncounterState state) override
    {
        switch (data)
        {
            case DATA_FLESHRENDER_NOKGAR:
            case DATA_GRIMRAIL_ENFORCERS:
            case DATA_OSHIR:
            case DATA_SKULLOC:
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

void AddSC_instance_iron_docks()
{
    new InstanceScriptLoaderEx<instance_iron_docks_InstanceMapScript>(IDScriptName, IDMapId);
}
