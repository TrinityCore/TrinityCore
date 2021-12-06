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
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventProcessor.h"
#include "firelands.h"
#include "InstanceScript.h"
#include "Map.h"

ObjectData const creatureData[] =
{
    { BOSS_BETHTILAC,                           DATA_BETHTILAC                          },
    { BOSS_SHANNOX,                             DATA_SHANNOX,                           },
    { BOSS_LORD_RHYOLITH,                       DATA_LORD_RHYOLITH                      },
    { BOSS_ALYSRAZOR,                           DATA_ALYSRAZOR                          },
    { BOSS_BALEROC,                             DATA_BALEROC                            },
    { BOSS_MAJORDOMO_STAGHELM,                  DATA_MAJORDOMO_STAGHELM                 },
    { BOSS_RAGNAROS,                            DATA_RAGNAROS                           },
    { NPC_MOVEMENT_CONTROLLER_LORD_RHYOLITH,    DATA_LORD_RHYOLITH_MOVEMENT_CONTROLLER  },
    { NPC_LEFT_FOOT,                            DATA_LEFT_FOOT                          },
    { NPC_RIGHT_FOOT,                           DATA_RIGHT_FOOT                         },
    { NPC_SULFURAS_SMASH_2,                     DATA_SULFURAS_SMASH                     },
    { NPC_SULFURAS_HAND_OF_RAGNAROS,            DATA_SULFURAS_HAND_OF_RAGNAROS          },
    { NPC_ARCHDRUID_HAMUUL_RUNETOTEM,           DATA_ARCHDRUID_HAMUUL_RUNETOTEM         },
    { NPC_DREADFLAME,                           DATA_DREADFLAME_CONTROLLER              },
    { NPC_CENARIUS,                             DATA_CENARIUS                           },
    { 0,                                        0,                                      } // END
};

ObjectData const gameObjectData[] =
{
    { GO_RAGNAROS_PLATFORM,     DATA_RAGNAROS_PLATFORM },
    { 0,                        0                       } // END
};

DoorData const doorData[] =
{
    { GO_LORD_RHYOLITH_BRIDGE,  DATA_LORD_RHYOLITH,         DOOR_TYPE_ROOM      },
    { GO_BETH_TILAC_DOOR,       DATA_BETHTILAC,             DOOR_TYPE_ROOM      },
    //{GO_BALEROC_FIREWALL,      DATA_BALEROC,               DOOR_TYPE_ROOM      },
    { GO_MAJORDOMO_FIREWALL,    DATA_MAJORDOMO_STAGHELM,    DOOR_TYPE_PASSAGE   },
    { GO_RAGNAROS_DOOR,         DATA_RAGNAROS,              DOOR_TYPE_ROOM      },
    { 0,                        0,                          DOOR_TYPE_ROOM      }, //END
};

enum Spells
{
    SPELL_MAGMA = 108773
};

BossBoundaryData const boundaries =
{
    { DATA_LORD_RHYOLITH,  new CircleBoundary(Position(-371.577393f, -318.680725f), 60.f) }
};

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
            instance_firelands_InstanceScript(InstanceMap* map) : InstanceScript(map), _firstRagnarosSpawn(true)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameObjectData);
                LoadDoorData(doorData);
                LoadBossBoundaries(boundaries);
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
                    case NPC_SULFURAS_SMASH_1:
                    case NPC_LAVA_WAVE:
                    case NPC_SULFURAS_HAND_OF_RAGNAROS:
                    case NPC_MOLTEN_ELEMENTAL:
                    case NPC_BLAZING_HEAT:
                    case NPC_ENTRAPPING_ROOTS:
                    case NPC_CLOUDBURST:
                    case NPC_BREADTH_OF_FROST:
                        if (Creature* ragnaros = GetCreature(DATA_RAGNAROS))
                            if (CreatureAI* ai = ragnaros->AI())
                                ai->JustSummoned(creature);
                        break;
                    case NPC_SPLITTING_BLOW:
                        _splittingBlowGUIDs.push_back(creature->GetGUID());
                        break;
                    case NPC_MAGMA:
                        _magmaGUIDs.push_back(creature->GetGUID());
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
                            if (majordomo->IsAIEnabled())
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
                                if (majordomo->IsAIEnabled())
                                    majordomo->AI()->DoAction(ACTION_BALEROC_DIED);
                        break;
                    case DATA_MAJORDOMO_STAGHELM:
                        if (state == FAIL)
                            _events.ScheduleEvent(EVENT_RESPAWN_MAJORDOMO_STAGHELM, 30s);
                        break;
                    case DATA_RAGNAROS:
                        if (state == FAIL)
                        {
                            _splittingBlowGUIDs.clear();
                            _magmaGUIDs.clear();
                        }
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

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_FIRST_RAGNAROS_SPAWN:
                        return uint8(_firstRagnarosSpawn);
                }

                return 0;
            }

            void SetData(uint32 type, uint32 value) override
            {
                switch (type)
                {
                    case DATA_FIRST_RAGNAROS_SPAWN:
                        _firstRagnarosSpawn = value != 0;
                        break;
                    case DATA_MAGMA_KNOCKBACK:
                        for (ObjectGuid const& guid : _magmaGUIDs)
                        {
                            if (Creature* magma = instance->GetCreature(guid))
                            {
                                magma->CastSpell(magma, SPELL_MAGMA);
                                magma->DespawnOrUnsummon(100ms);
                            }
                        }
                        break;
                    default:
                        break;
                }
            }


            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_RANDOM_SPLITTING_BLOW_GUID:
                        return Trinity::Containers::SelectRandomContainerElement(_splittingBlowGUIDs);
                    default:
                        return InstanceScript::GetGuidData(type);
                }
            }

        private:
            bool _firstRagnarosSpawn;
            EventMap _events;
            GuidVector _splittingBlowGUIDs;
            GuidVector _magmaGUIDs;
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
