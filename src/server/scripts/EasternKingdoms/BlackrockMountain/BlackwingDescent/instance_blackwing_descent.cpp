/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "GameObject.h"
#include "InstanceScript.h"
#include "blackwing_descent.h"

ObjectData const creatureData[] =
{
    { BOSS_MAGMAW,                          DATA_MAGMAW                         },
    { BOSS_OMNOTRON,                        DATA_OMNOTRON_DEFENSE_SYSTEM        },
    { NPC_ELECTRON,                         DATA_ELECTRON                       },
    { NPC_MAGMATRON,                        DATA_MAGMATRON                      },
    { NPC_TOXITRON,                         DATA_TOXITRON                       },
    { NPC_ARCANOTRON,                       DATA_ARCANOTRON                     },
    { NPC_NEFARIAN_MAGMAW,                  DATA_NEFARIAN_MAGMAW                },
    { NPC_LORD_VICTOR_NEFARIUS_OMNOTRON,    DATA_LORD_VICTOR_NEFARIUS_OMNOTRON  },
    { NPC_COLUMN_OF_LIGHT,                  DATA_COLUMN_OF_LIGHT                },
    { 0,                                    0                                   } // END
};

ObjectData const gameobjectData[] =
{
    { GO_ANCIENT_BELL,          DATA_ANCIENT_BELL       },
    { 0,                        0                       }  // END
};

DoorData const doorData[] =
{
    { GO_INNER_CHAMBER_DOOR,        DATA_MAGMAW,                    DOOR_TYPE_PASSAGE   },
    { GO_INNER_CHAMBER_DOOR,        DATA_OMNOTRON_DEFENSE_SYSTEM,   DOOR_TYPE_PASSAGE   },
    { 0,                            0,                              DOOR_TYPE_ROOM      }  // END
};

Position const MassiveCrashRightSpawnPosition   = { -288.59f,  -14.8472f,  211.2573f };
Position const MassiveCrashTargetPositionLeft   = { -304.181f, -90.1806f,  214.1653f };
Position const MassiveCrashTargetPositionRight  = { -337.375f, -43.6615f,  212.0853f };
Position const ColumnOfLightPosition            = { 231.3559f, -224.3038f, 74.95496f, 3.193953f };

enum Events
{
    EVENT_MAKE_ANCIENT_BELL_SELECTABLE = 1
};

class instance_blackwing_descent : public InstanceMapScript
{
    public:
        instance_blackwing_descent() : InstanceMapScript(BWDScriptName, 669) { }

        struct instance_blackwing_descent_InstanceMapScript : public InstanceScript
        {
            instance_blackwing_descent_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);
                LoadObjectData(creatureData, gameobjectData);
                LoadDoorData(doorData);
                Initialize();
            }

            void Initialize()
            {
                _deadDwarfSpirits = 0;
                _atramedesIntro = NOT_STARTED;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_PILLAR_OF_FLAME:
                    case NPC_LAVA_PARASITE_1:
                    case NPC_LAVA_PARASITE_2:
                    case NPC_BLAZING_BONE_CONSTRUCT:
                    case NPC_IGNITION:
                        if (Creature* magmaw = GetCreature(DATA_MAGMAW))
                            magmaw->AI()->JustSummoned(creature);
                        break;
                    case NPC_MASSIVE_CRASH:
                        if (creature->GetExactDist2d(MassiveCrashRightSpawnPosition) < 1.0f)
                            _massiveCrashRightDummyGUID = creature->GetGUID();
                        else
                            _massiveCrashLeftDummyGUID = creature->GetGUID();

                        break;
                    case NPC_ROOM_STALKER:
                        _roomStalkerGUIDs.insert(creature->GetGUID());

                        if (creature->GetExactDist2d(MassiveCrashTargetPositionLeft) < 1.0f)
                            _roomStalkerTargetDummyLeftGuid = creature->GetGUID();
                        else if (creature->GetExactDist2d(MassiveCrashTargetPositionRight) < 1.0f)
                            _roomStalkerTargetDummyRightGuid = creature->GetGUID();
                        break;
                    case NPC_CHEMICAL_CLOUD:
                    case NPC_POISON_BOMB:
                    case NPC_POISON_PUDDLE:
                    case NPC_POWER_GENERATOR:
                        if (Creature* omnotron = GetCreature(DATA_OMNOTRON_DEFENSE_SYSTEM))
                            omnotron->AI()->JustSummoned(creature);

                        if (Creature* nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS_OMNOTRON))
                            nefarius->AI()->JustSummoned(creature);
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
                    case GO_INNER_CHAMBER_DOOR:
                        if (GetBossState(DATA_MAGMAW) == DONE && GetBossState(DATA_OMNOTRON_DEFENSE_SYSTEM) == DONE)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GO_ANCIENT_BELL:
                        if (_deadDwarfSpirits == 8 && _atramedesIntro != DONE)
                        {
                            go->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            if (Creature* column = instance->SummonCreature(NPC_COLUMN_OF_LIGHT, ColumnOfLightPosition))
                                column->CastSpell(column, SPELL_COLUMN_OF_LIGHT);
                        }
                        break;
                    default:
                        break;
                }
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetTypeId() != TYPEID_UNIT)
                    return;

                switch (unit->GetEntry())
                {
                    case NPC_SPIRIT_OF_MOLTENFIST:
                    case NPC_SPIRIT_OF_ANVILRAGE:
                    case NPC_SPIRIT_OF_SHADOWFORGE:
                    case NPC_SPIRIT_OF_COREHAMMER:
                    case NPC_SPIRIT_OF_ANGERFORGE:
                    case NPC_SPIRIT_OF_IRONSTAR:
                    case NPC_SPIRIT_OF_THAURISSAN:
                    case NPC_SPIRIT_OF_BURNINGEYE:
                        SetData(DATA_DEAD_DWARF_SPIRITS, DONE);
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
                    case DATA_MAGMAW:
                        if (state == FAIL || state == DONE)
                        {
                            if (Creature* dummy = instance->GetCreature(_massiveCrashRightDummyGUID))
                                dummy->DespawnOrUnsummon(0s, 30s);

                            if (Creature* dummy = instance->GetCreature(_massiveCrashLeftDummyGUID))
                                dummy->DespawnOrUnsummon(0s, 30s);

                            for (ObjectGuid guid : _roomStalkerGUIDs)
                            {
                                if (Creature* stalker = instance->GetCreature(guid))
                                    stalker->DespawnOrUnsummon(0s, 30s);
                            }

                            _roomStalkerGUIDs.clear();
                        }
                        break;
                    default:
                        break;
                }

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_DEAD_DWARF_SPIRITS:
                        _deadDwarfSpirits++;
                        SaveToDB();

                        if (_deadDwarfSpirits == 8)
                        {
                            instance->SummonCreatureGroup(SUMMON_GROUP_ATRAMEDES_INTRO);
                            instance->SummonCreature(NPC_COLUMN_OF_LIGHT, ColumnOfLightPosition);
                            _events.ScheduleEvent(EVENT_MAKE_ANCIENT_BELL_SELECTABLE, 4s + 500ms);
                        }
                        break;
                    case DATA_ATRAMEDES_INTRO:
                        _atramedesIntro = data;
                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ATRAMEDES_INTRO:
                        return _atramedesIntro;
                }
                return 0;
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_PREPARE_MASSIVE_CRASH_AND_GET_TARGET_GUID:
                    {
                        Creature* massiveCrashStalker = nullptr;
                        uint8 sideIndex = MASSIVE_CRASH_SIDE_LEFT;
                        switch (urand(MASSIVE_CRASH_SIDE_LEFT, MASSIVE_CRASH_SIDE_RIGHT))
                        {
                            case MASSIVE_CRASH_SIDE_LEFT:
                                massiveCrashStalker = instance->GetCreature(_massiveCrashLeftDummyGUID);
                                break;
                            case MASSIVE_CRASH_SIDE_RIGHT:
                                massiveCrashStalker = instance->GetCreature(_massiveCrashRightDummyGUID);
                                sideIndex = MASSIVE_CRASH_SIDE_RIGHT;
                                break;
                            default:
                                break;
                        }

                        if (!massiveCrashStalker)
                            return ObjectGuid::Empty;

                        for (ObjectGuid guid : _roomStalkerGUIDs)
                        {
                            if (Creature* stalker = instance->GetCreature(guid))
                            {
                                if (massiveCrashStalker->HasInArc(float(M_PI / 4.0f), stalker))
                                {
                                    stalker->CastSpell(stalker, SPELL_LIGHT_SHOW);
                                    stalker->m_Events.AddEventAtOffset([stalker]()
                                    {
                                        stalker->RemoveAurasDueToSpell(SPELL_LIGHT_SHOW);
                                    }, 7s);
                                }
                            }
                        }

                        massiveCrashStalker->m_Events.AddEventAtOffset([massiveCrashStalker]()
                        {
                            massiveCrashStalker->CastSpell(massiveCrashStalker, SPELL_MASSIVE_CRASH_DAMAGE);
                        }, 6s);

                        if (sideIndex == MASSIVE_CRASH_SIDE_LEFT)
                            return _roomStalkerTargetDummyLeftGuid;
                        else
                            return _roomStalkerTargetDummyRightGuid;

                        break;
                    }
                }

                return ObjectGuid::Empty;
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_MAKE_ANCIENT_BELL_SELECTABLE:
                            if (GameObject* bell = GetGameObject(DATA_ANCIENT_BELL))
                                bell->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            if (Creature* column = GetCreature(DATA_COLUMN_OF_LIGHT))
                                column->CastSpell(column, SPELL_COLUMN_OF_LIGHT);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _deadDwarfSpirits << ' '
                    << _atramedesIntro;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _deadDwarfSpirits;
                data >> _atramedesIntro;
            }

        private:
            EventMap _events;
            ObjectGuid _massiveCrashLeftDummyGUID;
            ObjectGuid _massiveCrashRightDummyGUID;
            ObjectGuid _roomStalkerTargetDummyLeftGuid;
            ObjectGuid _roomStalkerTargetDummyRightGuid;
            GuidSet _roomStalkerGUIDs;

            uint8 _deadDwarfSpirits;
            uint8 _atramedesIntro;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_blackwing_descent_InstanceMapScript(map);
        }
};

void AddSC_instance_blackwing_descent()
{
    new instance_blackwing_descent();
}
