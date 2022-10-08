#include "Creature.h"
#include "GameObject.h"
#include "Map.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "hellfire_citadel.h"

DoorData const doorData[] =
{
    { GO_SIEGEMASTER_MARTAK_DOOR_1,     DATA_SIEGEMASTER_MARTAK,   DOOR_TYPE_PASSAGE },
    { GO_SIEGEMASTER_MARTAK_DOOR_2,     DATA_SIEGEMASTER_MARTAK,   DOOR_TYPE_PASSAGE },
    { GO_FEL_LORD_ZAKUUN_DOOR_1,        DATA_FEL_LORD_ZAKUUN,   DOOR_TYPE_ROOM },
    { GO_FEL_LORD_ZAKUUN_DOOR_2,        DATA_FEL_LORD_ZAKUUN,   DOOR_TYPE_PASSAGE },
    { GO_SOULBOUND_CONSTRUCT_DOOR_1,    DATA_SOULBOUND_CONSTRUCT,   DOOR_TYPE_ROOM },
    { GO_SOULBOUND_CONSTRUCT_DOOR_2,    DATA_SOULBOUND_CONSTRUCT,   DOOR_TYPE_ROOM },
    { GO_SOULBOUND_CONSTRUCT_DOOR_3,    DATA_SOULBOUND_CONSTRUCT,   DOOR_TYPE_ROOM },
    { GO_SOULBOUND_CONSTRUCT_DOOR_4,    DATA_SOULBOUND_CONSTRUCT,   DOOR_TYPE_ROOM },
    { GO_SHADOW_LORD_ISKAR_DOOR_1,      DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_SHADOW_LORD_ISKAR_DOOR_2,      DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_SHADOW_LORD_ISKAR_DOOR_3,      DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_SHADOW_LORD_ISKAR_DOOR_4,      DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_TYRANT_VELHARI_DOOR_1,         DATA_TYRANT_VELHARI,   DOOR_TYPE_PASSAGE },
    { GO_TYRANT_VELHARI_DOOR_2,         DATA_TYRANT_VELHARI,   DOOR_TYPE_PASSAGE },
    { GO_TYRANT_VELHARI_DOOR_3,         DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_TYRANT_VELHARI_DOOR_4,         DATA_TYRANT_VELHARI,   DOOR_TYPE_ROOM },
    { GO_HELLFIRE_ARCHIMONDE_DOOR_1,    DATA_HELLFIRE_ARCHIMONDE,   DOOR_TYPE_ROOM },
    
};

struct instance_hellfire_citadel : public InstanceScript
{
    instance_hellfire_citadel(InstanceMap* map) : InstanceScript(map)
    {
        SetHeaders(DataHeader);
        SetBossNumber(DATA_MAX_ENCOUNTERS);
        LoadDoorData(doorData);
        m_SIEGEMASTER_MARTAKGuid = ObjectGuid::Empty;
    }

    void OnCreatureCreate(Creature* creature) override
    {
        InstanceScript::OnCreatureCreate(creature);
        if (creature)
        {
            switch (creature->GetEntry())
            {
            case NPC_SIEGEMASTER_MARTAK:
                m_SIEGEMASTER_MARTAKGuid = creature->GetGUID();
                break;
            }
        }
    }

/*
    bool SetBossState(uint32 type, EncounterState state) override
    {
        if (!InstanceScript::SetBossState(type, state))
            return false;

        switch (type)
        {
        case DATA_SIEGEMASTER_MARTAK:
        {
            if (state == DONE)
              
            break;
        }
        default:
          break;
        }
    }
*/
    void OnUnitDeath(Unit* p_Unit) override
    {
        if (!instance)
            return;

        Creature* p_Creature = p_Unit->ToCreature();
        if (!p_Creature)
            return;

        switch (p_Creature->GetEntry())
        {
        case 93858:
        case 90409:
        case 93830:
        case 94604:
        case 93813:
        case 94663:
        case 94697:
        case 94563:
        {
            _fisrtCount++;
            if (_fisrtCount == 30)
            {
                if (Creature* martak = instance->GetCreature(m_SIEGEMASTER_MARTAKGuid))
                {
                    martak->SetHomePosition({ 3949.256f, -680.2031f, 30.94324f, 5.101f });
                    martak->GetMotionMaster()->MovePoint(1, { 3949.256f, -680.2031f, 30.94324f, 5.101f }, true);
                    martak->Say(95206);
                }                
            }
            break;
        }
        case NPC_SIEGEMASTER_MARTAK:
            if (Creature* martak = instance->GetCreature(m_SIEGEMASTER_MARTAKGuid))
            {
                SetBossState(DATA_SIEGEMASTER_MARTAK, DONE);
                SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, martak);
                instance->SummonCreature(NPC_IRON_REAVER, Position(3945.16f, -531.89f, 36.87f, 4.83239f));
            } 
            break;
        }
    }

    uint32 _fisrtCount = 0;
    ObjectGuid  m_SIEGEMASTER_MARTAKGuid;
};

void AddSC_instance_hellfire_citadel()
{
    RegisterInstanceScript(instance_hellfire_citadel, 1448);
}
