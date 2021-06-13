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
#include "GameObject.h"
#include "InstanceScript.h"
#include "MapManager.h"
#include "Transport.h"
#include "EventMap.h"
#include "CreatureAI.h"
#include "TemporarySummon.h"
#include "WorldStatePackets.h"
#include "blackwing_descent.h"

ObjectData const creatureData[] =
{
    { BOSS_MAGMAW,                              DATA_MAGMAW                             },
    { BOSS_OMNOTRON,                            DATA_OMNOTRON_DEFENSE_SYSTEM            },
    { BOSS_ATRAMEDES,                           DATA_ATRAMEDES                          },
    { BOSS_CHIMAERON,                           DATA_CHIMAERON                          },
    { BOSS_MALORIAK,                            DATA_MALORIAK                           },
    { BOSS_NEFARIAN,                            DATA_NEFARIANS_END                      },
    { NPC_ELECTRON,                             DATA_ELECTRON                           },
    { NPC_MAGMATRON,                            DATA_MAGMATRON                          },
    { NPC_TOXITRON,                             DATA_TOXITRON                           },
    { NPC_ARCANOTRON,                           DATA_ARCANOTRON                         },
    { NPC_NEFARIAN_MAGMAW,                      DATA_NEFARIAN_MAGMAW                    },
    { NPC_LORD_VICTOR_NEFARIUS_OMNOTRON,        DATA_LORD_VICTOR_NEFARIUS_OMNOTRON      },
    { NPC_COLUMN_OF_LIGHT,                      DATA_COLUMN_OF_LIGHT                    },
    { NPC_LORD_VICTOR_NEFARIUS_ATRAMEDES,       DATA_LORD_VICTOR_NEFARIUS_ATRAMEDES     },
    { NPC_BILE_O_TRON_800,                      DATA_BILE_O_TRON_800                    },
    { NPC_FINKLE_EINHORN,                       DATA_FINKLE_EINHORN                     },
    { NPC_CAULDRON_TRIGGER,                     DATA_CAULDRON_TRIGGER                   },
    { NPC_LORD_VICTOR_NEFARIUS_MALORIAK,        DATA_LORD_VICTOR_NEFARIUS_MALORIAK      },
    { NPC_LORD_VICTOR_NEFARIUS_GENERIC,         DATA_LORD_VICTOR_NEFARIUS_GENERIC       },
    { NPC_LORD_VICTOR_NEFARIUS_NEFARIANS_END,   DATA_LORD_VICTOR_NEFARIUS_NEFARIANS_END },
    { NPC_INVISIBLE_STALKER,                    DATA_INVISIBLE_STALKER                  },
    { NPC_NEFARIANS_LIGHTNING_MACHINE,          DATA_NEFARIANS_LIGHTNING_MACHINE        },
    { NPC_ONYXIA,                               DATA_ONYXIA                             },
    { NPC_CONTROLLER_STALKER,                   DATA_CONTROLLER_STALKER                 },
    { 0,                                        0                                       } // END
};

ObjectData const gameobjectData[] =
{
    { GO_ANCIENT_BELL,                              DATA_ANCIENT_BELL               },
    { GO_ATHENAEUM_DOOR,                            DATA_ATHENAEUM_DOOR             },
    { GO_DOODAD_BLACKROCKV2_LABROOM_CAULDRON_01,    DATA_CAULDRON                   },
    { GO_DOODAD_BLACKWINGV2_ELEVATOR_ONYXIA,        DATA_BLACKWING_ELEVATOR_ONYXIA  },
    { 0,                                            0                               }  // END
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
Position const AtramedesIntroSummonPosition     = { 288.325f,  -222.438f,  96.61964f, 3.089233f };
Position const AtramedesRespawnPosition         = { 220.0347f, -224.3125f, 74.88777f, 3.141593f };
Position const LordVictorNefariusIntroPosition  = { -290.4809f, -224.5955f, 191.6532f, 3.124139f };
Position const NefarianRespawnPosition          = { -184.12674f, -224.5573f, 97.70717f, 5.217541f };

enum Events
{
    EVENT_MAKE_ANCIENT_BELL_SELECTABLE = 1,
    EVENT_RESPAWN_ATRAMEDES,
    EVENT_RESPAWN_NEFARIAN,
    EVENT_RAISE_ELEVATOR,
    EVENT_RESPAWN_LEFT_DWARVEN_GROUP,
    EVENT_RESPAWN_RIGHT_DWARVEN_GROUP
};

enum Actions
{
    // Instance Actions
    ACTION_START_ATRAMEDES_INTRO = 0
};

enum SpawnGroup
{
    SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS = 400,
    SPAWN_GROUP_NEFARIANS_END           = 402,
    SPAWN_GROUP_DWARVEN_SPIRITS_LEFT    = 435,
    SPAWN_GROUP_DWARVEN_SPIRITS_RIGHT   = 436
};

enum SummonGroups
{
    SUMMON_GROUP_ATRAMEDES_INTRO = 0
};

enum Spells
{
    SPELL_EMOTE_MAGMA_LAVA_SPLASH = 79461
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
                _deadDwarfSpiritsLeft = 0;
                _deadDwarfSpiritsRight = 0;
                _atramedesIntroState = NOT_STARTED;
                _nefarianAchievementEligible = true;
                _nefariansEndIntroDone = false;
            }

            void Create() override
            {
                instance->SpawnGroupSpawn(SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS, true);
                instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_LEFT, true);
                instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_RIGHT, true);
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
                        _roomStalkerGUIDs.push_back(creature->GetGUID());

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
                    case NPC_SONAR_PULSE:
                    case NPC_TRACKING_FLAMES:
                    case NPC_SONAR_PULSE_BOMB:
                    case NPC_REVERBERATING_FLAME:
                    case NPC_OBNOXIOUS_FIEND:
                        if (Creature* atramedes = GetCreature(DATA_ATRAMEDES))
                            atramedes->AI()->JustSummoned(creature);
                        break;
                    case NPC_FLASH_FREEZE:
                    case NPC_VILE_SWILL:
                        if (Creature* maloriak = GetCreature(DATA_MALORIAK))
                            maloriak->AI()->JustSummoned(creature);
                        break;
                    case NPC_DOMINION_STALKER:
                        if (Creature* nefarian = GetCreature(DATA_NEFARIANS_END))
                            nefarian->AI()->JustSummoned(creature);
                        break;
                    case NPC_DRAKONID_DRUDGE:
                        creature->ApplySpellImmune(SPELL_EMOTE_MAGMA_LAVA_SPLASH, IMMUNITY_ID, SPELL_EMOTE_MAGMA_LAVA_SPLASH, true);
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

                            if (state == DONE)
                                if (Creature* nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS_GENERIC))
                                    if (nefarius->IsAIEnabled)
                                        nefarius->AI()->SetData(DATA_BOSS_DEFEATED, type);

                            _roomStalkerGUIDs.clear();
                        }
                        break;
                    case DATA_OMNOTRON_DEFENSE_SYSTEM:
                    case DATA_CHIMAERON:
                    case DATA_MALORIAK:
                        if (state == DONE)
                            if (Creature* nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS_GENERIC))
                                if (nefarius->IsAIEnabled)
                                    nefarius->AI()->SetData(DATA_BOSS_DEFEATED, type);
                        break;
                    case DATA_ATRAMEDES:
                        if (state == FAIL)
                        {
                            _events.ScheduleEvent(EVENT_RESPAWN_ATRAMEDES, 30s);
                            instance->SpawnGroupDespawn(SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS, false);
                        }
                        else if (state == DONE)
                        {
                            instance->SpawnGroupDespawn(SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS, false);
                            if (Creature* nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS_GENERIC))
                                if (nefarius->IsAIEnabled)
                                    nefarius->AI()->SetData(DATA_BOSS_DEFEATED, type);
                        }
                        break;
                    case DATA_NEFARIANS_END:
                        if (state == FAIL)
                        {
                            instance->SpawnGroupDespawn(SPAWN_GROUP_NEFARIANS_END, false);
                            _events.ScheduleEvent(EVENT_RESPAWN_NEFARIAN, 30s);
                        }
                        break;
                    default:
                        break;
                }

                if (type != DATA_NEFARIANS_END)
                    if (IsNefarianAvailable())
                        instance->SpawnGroupSpawn(SPAWN_GROUP_NEFARIANS_END, true);

                return true;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_DWARVEN_SPIRIT_DIED:
                        if (data == DWARVEN_SPIRIT_GROUP_LEFT)
                            ++_deadDwarfSpiritsLeft;
                        else
                            ++_deadDwarfSpiritsRight;

                        if ((_deadDwarfSpiritsLeft + _deadDwarfSpiritsRight) == 8)
                        {
                            _atramedesIntroState = DONE;
                            SaveToDB();

                            std::list<TempSummon*> summoned;
                            instance->SummonCreatureGroup(SUMMON_GROUP_ATRAMEDES_INTRO, &summoned);
                            for (TempSummon* summon : summoned)
                                _atramedesIntroGUIDs.push_back(summon->GetGUID());

                            instance->SummonCreature(NPC_COLUMN_OF_LIGHT, ColumnOfLightPosition);
                            _events.ScheduleEvent(EVENT_MAKE_ANCIENT_BELL_SELECTABLE, 4s + 500ms);
                        }
                        break;
                    case DATA_RESET_DWARVEN_SPIRIT_GROUP:
                        if (data == DWARVEN_SPIRIT_GROUP_LEFT)
                        {
                            _deadDwarfSpiritsLeft = 0;
                            _events.RescheduleEvent(EVENT_RESPAWN_LEFT_DWARVEN_GROUP, 30s);
                            instance->SpawnGroupDespawn(SPAWN_GROUP_DWARVEN_SPIRITS_LEFT);
                        }
                        else
                        {
                            _deadDwarfSpiritsRight = 0;
                            _events.RescheduleEvent(EVENT_RESPAWN_RIGHT_DWARVEN_GROUP, 30s);
                            instance->SpawnGroupDespawn(SPAWN_GROUP_DWARVEN_SPIRITS_RIGHT);
                        }

                        break;
                    case DATA_ATRAMEDES_INTRO:
                        if (!GetCreature(DATA_ATRAMEDES))
                        {
                            if (Creature* atramedes = instance->SummonCreature(BOSS_ATRAMEDES, AtramedesIntroSummonPosition))
                            {
                                for (ObjectGuid guid : _atramedesIntroGUIDs)
                                    if (Creature* intro = instance->GetCreature(guid))
                                        intro->DespawnOrUnsummon();

                                atramedes->SetDisableGravity(true);
                                atramedes->SetReactState(REACT_PASSIVE);
                                atramedes->SendSetPlayHoverAnim(true);

                                if (atramedes->IsAIEnabled)
                                    atramedes->AI()->DoAction(ACTION_START_ATRAMEDES_INTRO);
                            }
                        }
                        break;
                    case DATA_ENTRANCE_INTRO:
                    {
                        Creature* nefarius = nullptr;
                        if (instance->IsHeroic())
                            nefarius = instance->SummonCreature(NPC_LORD_VICTOR_NEFARIUS_GENERIC, LordVictorNefariusIntroPosition);
                        else
                            nefarius = GetCreature(DATA_LORD_VICTOR_NEFARIUS_GENERIC);

                        if (nefarius && nefarius->IsAIEnabled)
                            nefarius->AI()->SetData(DATA_HEROES_ENTERED_HALLS, DONE);
                        break;
                    }
                    case DATA_NEFARIAN_ACHIEVEMENT_STATE:
                        _nefarianAchievementEligible = uint8(data);
                        DoUpdateWorldState(WS_KEEPING_IT_IN_THE_FAMILY, uint8(_nefarianAchievementEligible));
                        break;
                    case DATA_NEFARIANS_END_INTRO_DONE:
                        _nefariansEndIntroDone = uint8(data);
                        break;
                    case DATA_RESET_ELEVATOR:
                        _events.ScheduleEvent(EVENT_RAISE_ELEVATOR, data);
                        break;
                    default:
                        break;
                }
            }

            void FillInitialWorldStates(WorldPackets::WorldState::InitWorldStates& data) override
            {
                data.Worldstates.emplace_back(uint32(WS_KEEPING_IT_IN_THE_FAMILY), uint32(_nefarianAchievementEligible));
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_ATRAMEDES_INTRO:
                        return _atramedesIntroState;
                    case DATA_NEFARIAN_ACHIEVEMENT_STATE:
                        return uint8(_nefarianAchievementEligible);
                    case DATA_NEFARIANS_END_INTRO_DONE:
                        return uint8(_nefariansEndIntroDone);
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
                    default:
                        break;
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
                        case EVENT_RESPAWN_ATRAMEDES:
                            instance->SpawnGroupSpawn(SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS, true);
                            instance->SummonCreature(BOSS_ATRAMEDES, AtramedesRespawnPosition);
                            break;
                        case EVENT_RESPAWN_NEFARIAN:
                            instance->SummonCreature(BOSS_NEFARIAN, NefarianRespawnPosition);
                            break;
                        case EVENT_RAISE_ELEVATOR:
                            if (GameObject* gameobject = GetGameObject(DATA_BLACKWING_ELEVATOR_ONYXIA))
                                if (Transport* transport = gameobject->ToTransport())
                                    transport->SetTransportState(GO_STATE_TRANSPORT_STOPPED, 1);
                            break;
                        case EVENT_RESPAWN_LEFT_DWARVEN_GROUP:
                            instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_LEFT, true);
                            break;
                        case EVENT_RESPAWN_RIGHT_DWARVEN_GROUP:
                            instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_RIGHT, true);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _atramedesIntroState;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _atramedesIntroState;

                if (GetBossState(DATA_ATRAMEDES) != DONE)
                {
                    instance->SpawnGroupSpawn(SPAWN_GROUP_ANCIENT_DWARVEN_SHIELDS, true);

                    if (_atramedesIntroState == DONE)
                        instance->SummonCreature(BOSS_ATRAMEDES, AtramedesRespawnPosition);
                    else
                    {
                        instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_LEFT, true);
                        instance->SpawnGroupSpawn(SPAWN_GROUP_DWARVEN_SPIRITS_RIGHT, true);
                    }
                }

                if (IsNefarianAvailable())
                    instance->SpawnGroupSpawn(SPAWN_GROUP_NEFARIANS_END, true);
            }

        private:
            EventMap _events;
            ObjectGuid _massiveCrashLeftDummyGUID;
            ObjectGuid _massiveCrashRightDummyGUID;
            ObjectGuid _roomStalkerTargetDummyLeftGuid;
            ObjectGuid _roomStalkerTargetDummyRightGuid;
            GuidVector _roomStalkerGUIDs;
            GuidVector _atramedesIntroGUIDs;
            uint8 _deadDwarfSpiritsLeft;
            uint8 _deadDwarfSpiritsRight;
            uint8 _atramedesIntroState;
            bool _nefarianAchievementEligible;
            bool _nefariansEndIntroDone;

            bool IsNefarianAvailable() const
            {
                if (GetBossState(DATA_NEFARIANS_END) == DONE)
                    return false;

                for (BWDDataTypes data : { DATA_MAGMAW, DATA_OMNOTRON_DEFENSE_SYSTEM, DATA_CHIMAERON, DATA_ATRAMEDES, DATA_MALORIAK })
                    if (GetBossState(data) != DONE)
                        return false;

                return true;
            }
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
