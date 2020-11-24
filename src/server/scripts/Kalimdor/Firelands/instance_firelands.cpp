/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptMgr.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventProcessor.h"
#include "firelands.h"
#include "InstanceScript.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_BETHTILAC,           DATA_BETHTILAC          },
    { BOSS_SHANNOX,             DATA_SHANNOX,           },
    { BOSS_LORD_RHYOLITH,       DATA_LORD_RHYOLITH      },
    { BOSS_ALYSRAZOR,           DATA_ALYSRAZOR          },
    { BOSS_BALEROC,             DATA_BALEROC            },
    { BOSS_MAJORDOMO_STAGHELM,  DATA_MAJORDOMO_STAGHELM },
    { BOSS_RAGNAROS,            DATA_RAGNAROS           },
    { 0,                        0,                      } // END
};

DoorData const doorData[] =
{
    {GO_LORD_RHYOLITH_BRIDGE,    DATA_LORD_RHYOLITH,      DOOR_TYPE_ROOM},
    {GO_BETH_TILAC_DOOR,         DATA_BETHTILAC,          DOOR_TYPE_ROOM},
    //{GO_BALEROC_FIREWALL,        DATA_BALEROC,            DOOR_TYPE_ROOM},
    {GO_MAJORDOMO_FIREWALL,      DATA_MAJORDOMO_STAGHELM, DOOR_TYPE_PASSAGE},
    {GO_RAGNAROS_DOOR,           DATA_RAGNAROS,           DOOR_TYPE_ROOM},
    {0,                          0,                       DOOR_TYPE_ROOM}, //END
}; //Baleroc door is special, it depends on the health status of the other bosses in the instance

class DelayedAttackStartEvent : public BasicEvent
{
public:
    DelayedAttackStartEvent(Creature* owner) : _owner(owner) {}

    bool Execute(uint64 /*e_time*/, uint32 /*p_time*/) override
    {
        _owner->AI()->DoZoneInCombat(_owner);
        return true;
    }

private:
    Creature* _owner;
};

enum MajordomoStaghelmActions
{
    ACTION_BALEROC_DIED             = 2, // Action 0 and 1 used by encounter
    ACTION_DRUID_OF_THE_FLAME_DIED  = 3
};

enum Events
{
    EVENT_RESPAWN_MAJORDOMO_STAGHELM = 1
};

Position const MajordomoStaghelmSpawnPosition   = { 570.2274f, -61.82986f,  90.42272f, 3.1415927f };
Position const MajordomoStaghelmRespawnPosition = { 523.4965f, -61.987846f, 83.94701f, 3.1415927f };

class instance_firelands : public InstanceMapScript
{
    public:
        instance_firelands() : InstanceMapScript(FirelandsScriptName, 720) { }

        struct instance_firelands_InstanceScript : public InstanceScript
        {
            instance_firelands_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadDoorData(doorData);
                LoadObjectData(creatureData, nullptr);
            }

            void Create() override
            {
                InstanceScript::Create();
                instance->SummonCreature(BOSS_MAJORDOMO_STAGHELM, MajordomoStaghelmSpawnPosition);
            }

            void Load(char const* data) override
            {
                InstanceScript::Load(data);
                if (GetBossState(DATA_MAJORDOMO_STAGHELM) != DONE)
                    instance->SummonCreature(BOSS_MAJORDOMO_STAGHELM, MajordomoStaghelmSpawnPosition);
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_SMOULDERING_HATCHLING:
                        // Cannot directly start attacking here as the creature is not yet on map
                        creature->m_Events.AddEvent(new DelayedAttackStartEvent(creature), creature->m_Events.CalculateTime(500));
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (!unit->IsCreature())
                    return;

                switch (unit->GetEntry())
                {
                    case NPC_DRUID_OF_THE_FLAME:
                        if (Creature* majordomo = GetCreature(DATA_MAJORDOMO_STAGHELM))
                            if (majordomo->IsAIEnabled)
                                majordomo->AI()->DoAction(ACTION_DRUID_OF_THE_FLAME_DIED);
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
                    case DATA_BALEROC:
                        if (state == DONE)
                            if (Creature* majordomo = GetCreature(DATA_MAJORDOMO_STAGHELM))
                                if (majordomo->IsAIEnabled)
                                    majordomo->AI()->DoAction(ACTION_BALEROC_DIED);
                        break;
                    case DATA_MAJORDOMO_STAGHELM:
                        if (state == FAIL)
                            _events.ScheduleEvent(EVENT_RESPAWN_MAJORDOMO_STAGHELM, 30s);
                        break;
                    default:
                        break;
                }

                return true;
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESPAWN_MAJORDOMO_STAGHELM:
                            instance->SummonCreature(BOSS_MAJORDOMO_STAGHELM, MajordomoStaghelmRespawnPosition);
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_firelands_InstanceScript(map);
        }
};

void AddSC_instance_firelands()
{
    new instance_firelands();
}
