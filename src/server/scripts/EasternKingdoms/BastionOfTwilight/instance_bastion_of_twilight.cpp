/*
* Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "CreatureAI.h"
#include "bastion_of_twilight.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "TemporarySummon.h"
#include "VehicleDefines.h"
#include "WorldPacket.h"

ObjectData const creatureData[] =
{
    { BOSS_HALFUS_WYRMBREAKER,          DATA_HALFUS_WYRMBREAKER     },
    { BOSS_THERALION,                   DATA_THERALION              },
    { BOSS_VALIONA,                     DATA_VALIONA                },
    { BOSS_IGNACIOUS,                   DATA_IGNACIOUS              },
    { BOSS_FELUDIUS,                    DATA_FELUDIUS               },
    { BOSS_TERRASTRA,                   DATA_TERRASTRA              },
    { BOSS_ARION,                       DATA_ARION                  },
    { BOSS_ELEMENTIUM_MONSTROSITY,      DATA_ELEMENTIUM_MONSTROSITY },
    { BOSS_CHOGALL,                     DATA_CHOGALL                },
    { BOSS_SINESTRA,                    DATA_SINESTRA               },
    { NPC_PROTO_BEHEMOTH,               DATA_PROTO_BEHEMOTH         },
    { 0,                                0                           } // END
};

ObjectData const gameobjectData[] =
{
    { GO_WHELP_CAGE,    DATA_WHELP_CAGE },
    { 0,                0               } // END
};

DoorData const doorData[] =
{
    { GO_HALFUS_ENTRANCE,                   DATA_HALFUS_WYRMBREAKER,        DOOR_TYPE_ROOM      },
    { GO_HALFUS_EXIT,                       DATA_HALFUS_WYRMBREAKER,        DOOR_TYPE_PASSAGE   },
    { GO_DRAGON_SIBLINGS_DOOR_ENTRANCE,     DATA_THERALION_AND_VALIONA,     DOOR_TYPE_ROOM      },
    { GO_DRAGON_SIBLINGS_DOOR_EXIT,         DATA_THERALION_AND_VALIONA,     DOOR_TYPE_PASSAGE   },
    { GO_ASCENDANT_COUNCIL_ENTRANCE,        DATA_ASCENDANT_COUNCIL,         DOOR_TYPE_ROOM      },
    { GO_ASCENDANT_COUNCIL_EXIT,            DATA_ASCENDANT_COUNCIL,         DOOR_TYPE_PASSAGE   },
    { GO_CHOGALL_ENTRANCE,                  DATA_CHOGALL,                   DOOR_TYPE_ROOM      },
    { 0,                                    0,                              DOOR_TYPE_ROOM      } // END
};

uint32 HalfusDragonEntries[] =
{
    NPC_NETHER_SCION,
    NPC_SLATE_DRAGON,
    NPC_STORM_RIDER,
    NPC_TIME_WARDEN,
    NPC_ORPHANED_EMERALD_WELP
};

class instance_bastion_of_twilight : public InstanceMapScript
{
    public:
        instance_bastion_of_twilight() : InstanceMapScript(BoTScriptName, 671) { }

        struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
        {
            instance_bastion_of_twilight_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(!map->IsHeroic() ? EncounterCountNormal : EncounterCountHeroic); // Sinestra only in heroic mode
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameobjectData);
                _unresponsiveDragonEntryFirst = 0;
                _unresponsiveDragonEntrySecond = 0;
                _dragonToBindEntry = 0;
                _deadOrphanedEmeraldWhelps = 0;
                GenerateHalfusDragonData();
            }

            void GenerateHalfusDragonData()
            {
                for (uint8 i = 0; i < 5; i++)
                    _activeDragonEntries.insert(HalfusDragonEntries[i]);

                if (!instance->IsHeroic())
                {
                    for (uint8 i = 0; i < 2; i++)
                    {
                        uint32 entry = Trinity::Containers::SelectRandomContainerElement(_activeDragonEntries);
                        _activeDragonEntries.erase(entry);
                        if (i == 0)
                            _unresponsiveDragonEntryFirst = entry;
                        else
                            _unresponsiveDragonEntrySecond = entry;
                    }
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                InstanceScript::OnCreatureCreate(creature);

                switch (creature->GetEntry())
                {
                    case NPC_NETHER_SCION:
                    case NPC_SLATE_DRAGON:
                    case NPC_STORM_RIDER:
                    case NPC_TIME_WARDEN:
                    case NPC_ORPHANED_EMERALD_WELP:
                    case NPC_SPIKE:
                        _halfusEncounterGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_INVISIBLE_STALKER:
                        if (creature->GetPositionZ() < 850.0f)
                            _dancingFlamesInvisibleStalkerGUIDs.insert(creature->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                switch (type)
                {
                    case DATA_HALFUS_WYRMBREAKER:
                        if (state == IN_PROGRESS)
                        {
                            if (instance->IsHeroic() || HasActiveOrphanedEmeraldWhelps())
                                if (GameObject* cage = GetGameObject(DATA_WHELP_CAGE))
                                    cage->RemoveFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            for (ObjectGuid guid : _halfusEncounterGUIDs)
                            {
                                if (Creature* creature = instance->GetCreature(guid))
                                {
                                    if (creature->GetEntry() != NPC_SPIKE
                                        && creature->GetEntry() != _unresponsiveDragonEntryFirst
                                        && creature->GetEntry() != _unresponsiveDragonEntrySecond)
                                    {
                                        switch (creature->GetEntry())
                                        {
                                            case NPC_NETHER_SCION:
                                                creature->UpdateEntry(NPC_NETHER_SCION_ENCOUNTER);
                                                break;
                                            case NPC_SLATE_DRAGON:
                                                creature->UpdateEntry(NPC_SLATE_DRAGON_ENCOUNTER);
                                                break;
                                            case NPC_STORM_RIDER:
                                                creature->UpdateEntry(NPC_STORM_RIDER_ENCOUNTER);
                                                break;
                                            case NPC_TIME_WARDEN:
                                                creature->UpdateEntry(NPC_TIME_WARDEN_ENCOUNTER);
                                                break;
                                            default:
                                                break;
                                        }

                                        creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                                        if (creature->GetEntry() != NPC_ORPHANED_EMERALD_WELP)
                                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                                    }
                                }
                            }
                        }
                        else if (state == FAIL)
                        {
                            if (Creature* protoBehemoth = GetCreature(DATA_PROTO_BEHEMOTH))
                                protoBehemoth->DespawnOrUnsummon(Milliseconds(0), Seconds(30));

                            for (ObjectGuid guid : _halfusEncounterGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(Milliseconds(0), Seconds(30));

                            if (GameObject* cage = GetGameObject(DATA_WHELP_CAGE))
                            {
                                cage->SetGoState(GO_STATE_READY);
                                cage->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);
                            }

                            _deadOrphanedEmeraldWhelps = 0;
                            events.CancelEvent(EVENT_CAST_DANCING_FLAMES);
                        }
                        else if (state == DONE)
                        {
                            if (Creature* protoBehemoth = GetCreature(DATA_PROTO_BEHEMOTH))
                                protoBehemoth->DespawnOrUnsummon(Milliseconds(0));

                            for (ObjectGuid guid : _halfusEncounterGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(Milliseconds(0));

                            if (GameObject* cage = GetGameObject(DATA_WHELP_CAGE))
                                cage->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_NOT_SELECTABLE);

                            events.CancelEvent(EVENT_CAST_DANCING_FLAMES);
                        }
                        break;
                    default:
                        break;
                }
                return true;
            }

            void OnUnitDeath(Unit* unit) override
            {
                if (unit->GetEntry() == NPC_ORPHANED_EMERALD_WELP)
                {
                    _deadOrphanedEmeraldWhelps++;
                    if (_deadOrphanedEmeraldWhelps == 8)
                        if (Creature* protoBehemoth = GetCreature(DATA_PROTO_BEHEMOTH))
                            protoBehemoth->AI()->DoAction(ACTION_CAST_DRAGONS_VENGEANCE);
                }
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_CAST_DRAGON_BUFFS:
                        if (data == DRAGON_BUFFS_HALFUS_WYRMBREAKER)
                        {
                            if (Creature* halfus = GetCreature(DATA_HALFUS_WYRMBREAKER))
                            {
                                for (uint32 entry : _activeDragonEntries)
                                {
                                    if (entry == NPC_SLATE_DRAGON)
                                        halfus->AI()->DoAction(ACTION_ENABLE_MALEVOLENT_STRIKES);
                                    if (entry == NPC_NETHER_SCION)
                                        halfus->AI()->DoAction(ACTION_ENABLE_FRENZIED_ASSAULT);
                                    if (entry == NPC_STORM_RIDER)
                                        halfus->AI()->DoAction(ACTION_ENABLE_SHADOW_NOVA);
                                }
                            }
                        }
                        else if (data == DRAGON_BUFFS_PROTO_BEHEMOTH)
                        {
                            if (Creature* protoBehemoth = GetCreature(DATA_PROTO_BEHEMOTH))
                            {
                                for (uint32 entry : _activeDragonEntries)
                                {
                                    if (entry == NPC_ORPHANED_EMERALD_WELP)
                                        protoBehemoth->AI()->DoAction(ACTION_ENABLE_SCORCHING_BREATH);
                                    if (entry == NPC_TIME_WARDEN)
                                    {
                                        protoBehemoth->AI()->DoAction(ACTION_ENABLE_FIREBALL_BARRAGE);
                                        events.RescheduleEvent(EVENT_CAST_DANCING_FLAMES, Milliseconds(500), Seconds(1));
                                    }
                                }
                            }
                        }
                        break;
                    case DATA_DRAGON_TO_BIND:
                        _dragonToBindEntry = data;
                        break;
                    case DATA_OPEN_ORPHANED_EMERALD_WHELP_CAGE:
                        for (ObjectGuid guid : _halfusEncounterGUIDs)
                            if (Creature* orphanedEmeraldWhelp = instance->GetCreature(guid))
                                if (orphanedEmeraldWhelp->GetEntry() == NPC_ORPHANED_EMERALD_WELP)
                                    orphanedEmeraldWhelp->AI()->DoAction(ACTION_MOVE_OUT_OF_CAGE);
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_UNRESPONSIVE_DRAGON_FIRST:
                        return _unresponsiveDragonEntryFirst;
                    case DATA_UNRESPONSIVE_DRAGON_SECOND:
                        return _unresponsiveDragonEntrySecond;
                    case DATA_DRAGON_TO_BIND:
                        return _dragonToBindEntry;
                }
                return 0;
            }

            void Update(uint32 diff) override
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_CAST_DANCING_FLAMES:
                            if (ObjectGuid guid = Trinity::Containers::SelectRandomContainerElement(_dancingFlamesInvisibleStalkerGUIDs))
                                if (Creature* cataclysmStalker = instance->GetCreature(guid))
                                    cataclysmStalker->CastSpell(cataclysmStalker, SPELL_DANCING_FLAMES_VISUAL, true);

                            events.Repeat(Milliseconds(500), Seconds(1));
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _unresponsiveDragonEntryFirst << ' '
                    << _unresponsiveDragonEntrySecond;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _unresponsiveDragonEntryFirst;
                data >> _unresponsiveDragonEntrySecond;
            }

            bool HasActiveOrphanedEmeraldWhelps() const
            {
                return (_unresponsiveDragonEntryFirst != NPC_ORPHANED_EMERALD_WELP
                    && _unresponsiveDragonEntrySecond != NPC_ORPHANED_EMERALD_WELP);
            }

        protected:
            EventMap events;
            GuidSet _halfusEncounterGUIDs;
            GuidSet _spikeGUIDs;
            GuidSet _dancingFlamesInvisibleStalkerGUIDs;
            std::set<uint32> _activeDragonEntries;
            uint32 _unresponsiveDragonEntryFirst;
            uint32 _unresponsiveDragonEntrySecond;
            uint32 _dragonToBindEntry;
            uint8 _deadOrphanedEmeraldWhelps;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_bastion_of_twilight_InstanceMapScript(map);
        }
};

void AddSC_instance_bastion_of_twilight()
{
    new instance_bastion_of_twilight();
}
