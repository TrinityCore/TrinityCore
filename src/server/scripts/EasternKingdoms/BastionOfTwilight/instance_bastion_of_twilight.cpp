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
    { BOSS_HALFUS_WYRMBREAKER,          DATA_HALFUS_WYRMBREAKER             },
    { BOSS_THERALION,                   DATA_THERALION                      },
    { BOSS_VALIONA,                     DATA_VALIONA                        },
    { BOSS_IGNACIOUS,                   DATA_IGNACIOUS                      },
    { BOSS_FELUDIUS,                    DATA_FELUDIUS                       },
    { BOSS_TERRASTRA,                   DATA_TERRASTRA                      },
    { BOSS_ARION,                       DATA_ARION                          },
    { BOSS_ELEMENTIUM_MONSTROSITY,      DATA_ELEMENTIUM_MONSTROSITY         },
    { BOSS_CHOGALL,                     DATA_CHOGALL                        },
    { BOSS_SINESTRA,                    DATA_SINESTRA                       },
    { NPC_PROTO_BEHEMOTH,               DATA_PROTO_BEHEMOTH                 },
    { NPC_ASCENDANT_COUNCIL_CONTROLLER, DATA_ASCENDANT_COUNCIL_CONTROLLER   },
    { NPC_CORRUPTION,                   DATA_CORRUPTION                     },
    { 0,                                0                                   } // END
};

ObjectData const gameobjectData[] =
{
    { GO_GRIM_BATOL_RAID_TRAP_DOOR, DATA_GRIM_BATOL_RAID_TRAP_DOOR  },
    { 0,                            0                               } // END
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

Position const BreathFlightTargetStalkerSortPos = { -740.677f, -592.328f, 859.455f };

class instance_bastion_of_twilight : public InstanceMapScript
{
    public:
        instance_bastion_of_twilight() : InstanceMapScript(BoTScriptName, 671) { }

        struct instance_bastion_of_twilight_InstanceMapScript : public InstanceScript
        {
            instance_bastion_of_twilight_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(!map->IsHeroic() ? EncounterCountNormal : EncounterCountHeroic); // Sinestra only in heroic mode
                LoadDoorData(doorData);
                LoadObjectData(creatureData, gameobjectData);
                _unresponsiveDragonEntryFirst = 0;
                _unresponsiveDragonEntrySecond = 0;
                _deadOrphanedEmeraldWhelps = 0;
                _lastAreatriggerIndex = 0;
                _fullHeroicId = instance->IsHeroic();
                _valionaAuraDummyGUID = ObjectGuid::Empty;
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
                        if (Creature* halfus = GetCreature(DATA_HALFUS_WYRMBREAKER))
                            halfus->AI()->JustSummoned(creature);
                    case NPC_ORPHANED_EMERALD_WELP:
                    case NPC_SPIKE:
                        _halfusEncounterGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_INVISIBLE_STALKER:
                        if (creature->GetPositionZ() < 850.0f)
                            _dancingFlamesInvisibleStalkerGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_COLLAPSING_TWILIGHT_PORTAL:
                        if (Creature* valiona = GetCreature(DATA_VALIONA))
                            valiona->AI()->JustSummoned(creature);

                        _collapsingTwilightPortalGUIDs.insert(creature->GetGUID());
                        break;
                    case NPC_CONVECTIVE_FLAMES:
                    case NPC_TWILIGHT_SENTRY:
                    case NPC_TWILIGHT_RIFT:
                        if (Creature* valiona = GetCreature(DATA_VALIONA))
                            valiona->AI()->JustSummoned(creature);
                        break;
                    case NPC_DAZZLING_DESTRUCTION_STALKER:
                    case NPC_FABULOUS_FLAMES:
                        if (Creature* theralion = GetCreature(DATA_THERALION))
                            theralion->AI()->JustSummoned(creature);
                        break;
                    case NPC_VALIONA_DUMMY:
                        _valionaDummyGUIDs.insert(creature->GetGUID());
                        if (creature->GetOrientation() == 0.0f) // Blizzard uses a single dummy with 0.0f orientation as aura target dummy
                            _valionaAuraDummyGUID = creature->GetGUID();
                        break;
                    case NPC_UNSTABLE_TWILIGHT:
                        _unstableTwilightGUIDs.insert(creature->GetGUID());
                        break;
                    case BOSS_FELUDIUS:
                    case BOSS_IGNACIOUS:
                    case BOSS_ARION:
                    case BOSS_TERRASTRA:
                        if (creature->isDead() && GetBossState(DATA_ASCENDANT_COUNCIL) != DONE)
                            creature->Respawn();
                        break;
                    case NPC_SPIKED_TENTACLE_TRIGGER:
                        if (Creature* chogall = GetCreature(DATA_CHOGALL))
                            chogall->AI()->JustSummoned(creature);
                        break;
                    default:
                        break;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                InstanceScript::OnGameObjectCreate(go);

                if (go->GetEntry() == GO_GRIM_BATOL_RAID_TRAP_DOOR && instance->IsHeroic() && _fullHeroicId && GetBossState(DATA_CHOGALL) == DONE)
                    go->SetGoState(GO_STATE_ACTIVE);
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
                            _halfusEncounterGUIDs.clear();
                            _deadOrphanedEmeraldWhelps = 0;
                            events.CancelEvent(EVENT_CAST_DANCING_FLAMES);
                        }
                        else if (state == DONE)
                            events.CancelEvent(EVENT_CAST_DANCING_FLAMES);
                        break;
                    case DATA_THERALION_AND_VALIONA:
                        if (state == FAIL)
                        {
                            for (ObjectGuid guid : _valionaDummyGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(Milliseconds(0), Seconds(30));

                            for (ObjectGuid guid : _unstableTwilightGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon(Milliseconds(0), Seconds(30));

                            _collapsingTwilightPortalGUIDs.clear();
                        }
                        else if (state == DONE)
                        {
                            for (ObjectGuid guid : _valionaDummyGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon();

                            for (ObjectGuid guid : _unstableTwilightGUIDs)
                                if (Creature* creature = instance->GetCreature(guid))
                                    creature->DespawnOrUnsummon();

                            events.ScheduleEvent(EVENT_CHOGALL_TALK_THERALION_AND_VALIONA_DEAD, 6s);
                        }
                        break;
                    default:
                        break;
                }

                if (state == DONE && !instance->IsHeroic())
                    _fullHeroicId = 0;
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
                                        events.RescheduleEvent(EVENT_CAST_DANCING_FLAMES, 500ms, 1s);
                                    }
                                }
                            }
                        }
                        break;
                    case DATA_OPEN_ORPHANED_EMERALD_WHELP_CAGE:
                        for (ObjectGuid guid : _halfusEncounterGUIDs)
                            if (Creature* orphanedEmeraldWhelp = instance->GetCreature(guid))
                                if (orphanedEmeraldWhelp->GetEntry() == NPC_ORPHANED_EMERALD_WELP)
                                    orphanedEmeraldWhelp->AI()->DoAction(ACTION_MOVE_OUT_OF_CAGE);
                        break;
                    case DATA_AT_HALFUS_INTRO:
                        if (_lastAreatriggerIndex < AT_INDEX_HALFUS_WYRMBREAKER_INTRO)
                        {
                            _lastAreatriggerIndex = AT_INDEX_HALFUS_WYRMBREAKER_INTRO;
                            SaveToDB();
                        }
                        break;
                    case DATA_AT_THERALION_AND_VALIONA_INTRO:
                        if (_lastAreatriggerIndex < AT_INDEX_THERALION_AND_VALIONA_INTRO)
                        {
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_THERALION_AND_VALIONA_INTRO);

                            if (Creature* theralion = GetCreature(DATA_THERALION))
                                theralion->AI()->DoAction(ACTION_START_ARGUMENT_INTRO);

                            if (Creature* valiona = GetCreature(DATA_VALIONA))
                                valiona->AI()->DoAction(ACTION_START_ARGUMENT_INTRO);

                            _lastAreatriggerIndex = AT_INDEX_THERALION_AND_VALIONA_INTRO;
                            SaveToDB();
                        }
                        break;
                    case DATA_AT_ASCENDANT_COUNCIL_INTRO_1:
                        if (_lastAreatriggerIndex < AT_INDEX_ASCENDANT_COUNCIL_INTRO_1)
                        {
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_ASCENDANT_COUNCIL_INTRO_1);

                            _lastAreatriggerIndex = AT_INDEX_ASCENDANT_COUNCIL_INTRO_1;
                            SaveToDB();
                        }
                        break;
                    case DATA_AT_ASCENDANT_COUNCIL_INTRO_2:
                        if (_lastAreatriggerIndex < AT_INDEX_ASCENDANT_COUNCIL_INTRO_2)
                        {
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_ASCENDANT_COUNCIL_INTRO_2);

                            _lastAreatriggerIndex = AT_INDEX_ASCENDANT_COUNCIL_INTRO_2;
                            SaveToDB();
                        }
                        break;
                    case DATA_AT_ASCENDANT_COUNCIL_INTRO_3:
                        if (_lastAreatriggerIndex < AT_INDEX_ASCENDANT_COUNCIL_INTRO_3)
                        {
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_ASCENDANT_COUNCIL_INTRO_3);

                            _lastAreatriggerIndex = AT_INDEX_ASCENDANT_COUNCIL_INTRO_3;
                            SaveToDB();
                        }
                        break;
                    case DATA_AT_CHOGALL_INTRO:
                        if (_lastAreatriggerIndex < AT_INDEX_CHOGALL_INTRO)
                        {
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_CHOGALL_INTRO);

                            _lastAreatriggerIndex = AT_INDEX_CHOGALL_INTRO;
                            SaveToDB();
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
                    case DATA_RANDOM_VALIONA_DUMMY:
                        return Trinity::Containers::SelectRandomContainerElement(_valionaDummyGUIDs);
                    case DATA_VALIONA_AURA_DUMMY:
                        return _valionaAuraDummyGUID;
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_UNRESPONSIVE_DRAGON_FIRST:
                        return _unresponsiveDragonEntryFirst;
                    case DATA_UNRESPONSIVE_DRAGON_SECOND:
                        return _unresponsiveDragonEntrySecond;
                    case DATA_DRAGON_CAGE_ENABLED:
                        return uint8((instance->IsHeroic() || HasActiveOrphanedEmeraldWhelps()));
                    case DATA_COLLAPSING_TWILIGHT_PORTAL_COUNT:
                    {
                        uint8 portalCount = 0;
                        for (ObjectGuid guid : _collapsingTwilightPortalGUIDs)
                            if (instance->GetCreature(guid))
                                portalCount++;
                        return portalCount;
                    }
                    case DATA_FULL_HEROIC_ID:
                        return _fullHeroicId;
                    default:
                        return 0;
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

                            events.Repeat(500ms, 1s);
                            break;
                        case EVENT_CHOGALL_TALK_THERALION_AND_VALIONA_DEAD:
                            if (Creature* chogall = GetCreature(DATA_CHOGALL))
                                chogall->AI()->DoAction(ACTION_TALK_THERALION_AND_VALIONA_DEAD);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _unresponsiveDragonEntryFirst << ' '
                    << _unresponsiveDragonEntrySecond << ' '
                    << _lastAreatriggerIndex << ' '
                    << _fullHeroicId;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _unresponsiveDragonEntryFirst;
                data >> _unresponsiveDragonEntrySecond;
                data >> _lastAreatriggerIndex;
                data >> _fullHeroicId;

                if (_unresponsiveDragonEntryFirst && _unresponsiveDragonEntrySecond)
                {
                    // Clear default generated unresponsive dragon selection and replace it with our saved data
                    _activeDragonEntries.clear();
                    for (uint8 i = 0; i < 5; i++)
                        _activeDragonEntries.insert(HalfusDragonEntries[i]);

                    _activeDragonEntries.erase(_unresponsiveDragonEntryFirst);
                    _activeDragonEntries.erase(_unresponsiveDragonEntrySecond);
                }
            }

            bool HasActiveOrphanedEmeraldWhelps() const
            {
                return (_unresponsiveDragonEntryFirst != NPC_ORPHANED_EMERALD_WELP
                    && _unresponsiveDragonEntrySecond != NPC_ORPHANED_EMERALD_WELP);
            }

        private:
            EventMap events;
            GuidSet _halfusEncounterGUIDs;
            GuidSet _dancingFlamesInvisibleStalkerGUIDs;
            GuidSet _valionaDummyGUIDs;
            GuidSet _unstableTwilightGUIDs;
            GuidSet _collapsingTwilightPortalGUIDs;
            ObjectGuid _valionaAuraDummyGUID;
            std::set<uint32> _activeDragonEntries;
            uint32 _unresponsiveDragonEntryFirst;
            uint32 _unresponsiveDragonEntrySecond;
            uint8 _deadOrphanedEmeraldWhelps;
            uint8 _lastAreatriggerIndex;
            uint8 _fullHeroicId;
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
