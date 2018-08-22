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
#include "Creature.h"
#include "CreatureGroups.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "stonecore.h"

#define MAX_ENCOUNTER 4

/* Stonecore encounters:
0 - Corborus
1 - Slabhide
2 - Ozruk
3 - High Priestess Azil
*/

ObjectData const creatureData[] =
{
    { NPC_MILLHOUSE_MANASTORM,      DATA_MILLHOUSE_MANASTORM    },
    { BOSS_CORBORUS,                DATA_CORBORUS               },
    { BOSS_SLABHIDE,                DATA_SLABHIDE               },
    { BOSS_OZRUK,                   DATA_OZRUK,                 },
    { BOSS_HIGH_PRIESTESS_AZIL,     DATA_HIGH_PRIESTESS_AZIL    },
    { NPC_STONECORE_TELEPORTER,     DATA_STONECORE_TELEPORTER   },
    { NPC_STONECORE_TELEPORTER_2,   DATA_STONECORE_TELEPORTER_2 },
    { 0,                            0                           } // END
};

class instance_stonecore : public InstanceMapScript
{
    public:
        instance_stonecore() : InstanceMapScript(SCScriptName, 725) { }

        struct instance_stonecore_InstanceScript : public InstanceScript
        {
            instance_stonecore_InstanceScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
                LoadObjectData(creatureData, nullptr);
                Initialize();
            }

            void Initialize()
            {
                _initialSetupDone = false;
                _eventIndex = EVENT_INDEX_NONE;
            }

            void OnPlayerEnter(Player* /*player*/) override
            {
                if (!_initialSetupDone)
                {
                    if (_eventIndex >= EVENT_INDEX_CORBORUS_INTRO && GetBossState(DATA_CORBORUS) != DONE)
                        instance->SummonCreature(BOSS_CORBORUS, CorborusRespawnPos);
                    else if (GetBossState(DATA_CORBORUS) != DONE)
                        instance->SummonCreature(BOSS_CORBORUS, CorborusSpawnPos);

                    if (_eventIndex == EVENT_INDEX_SLABHIDE_INTRO && GetBossState(DATA_SLABHIDE) != DONE)
                        instance->SummonCreature(BOSS_SLABHIDE, SlabhideRespawnPos);
                    else if (GetBossState(DATA_SLABHIDE) != DONE)
                        instance->SummonCreature(BOSS_SLABHIDE, SlabhideSpawnPos);

                    _initialSetupDone = true;
                }
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GAMEOBJECT_CORBORUS_ROCKDOOR:
                        _corborusRockDoorGUID = go->GetGUID();
                        if (_eventIndex >= EVENT_INDEX_CORBORUS_INTRO)
                            go->SetGoState(GO_STATE_ACTIVE);
                        break;
                    case GAMEOBJECT_SLABHIDE_ROCK_WALL:
                        _slabhideRockWallGUIDs.push_back(go->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_EVENT_PROGRESS:
                        return _eventIndex;
                }
                return 0;
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_STONECORE_TELEPORTER:
                    case NPC_STONECORE_TELEPORTER_2:
                        if (GetBossState(DATA_SLABHIDE) == DONE)
                            ActivateTeleporter(creature);
                        break;
                    default:
                        break;
                }

                // Check if creature is part of Millhouse event
                creature->SearchFormation();
                if (CreatureGroup* group = creature->GetFormation())
                {
                    switch (group->GetId())
                    {
                        case CREATURE_FORMATION_MILLHOUSE_EVENT_TRASH:
                            _millhouseTrashGUIDs.push_back(creature->GetGUID());
                            break;
                        case CREATURE_FORMATION_MILLHOUSE_EVENT_LAST_GROUP:
                            _millhouseLastGroupGUIDs.push_back(creature->GetGUID());
                            creature->SetReactState(REACT_PASSIVE);
                            creature->SetMeleeAnimKitId(ANIM_READY2H);
                            break;
                        default:
                            break;
                    }
                }

                InstanceScript::OnCreatureCreate(creature);
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                switch (type)
                {
                    case DATA_CORBORUS:
                        if (state == FAIL)
                            _events.ScheduleEvent(EVENT_RESPAWN_CORBORUS, 30s);
                        break;
                    case DATA_SLABHIDE:
                        // Open rock walls (Slabhide AI handles closing because it must be delayed)
                        if (state != IN_PROGRESS)
                            SetData(DATA_SLABHIDE_ROCK_WALL, true);

                        // Activate teleporters
                        if (state == DONE)
                        {
                            ActivateTeleporter(GetCreature(DATA_STONECORE_TELEPORTER));
                            ActivateTeleporter(GetCreature(DATA_STONECORE_TELEPORTER_2));
                        }

                        if (state == FAIL)
                            _events.ScheduleEvent(EVENT_RESPAWN_SLABHIDE, 30s);
                        break;
                    default:
                        break;
                }

                return InstanceScript::SetBossState(type, state);
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_HANDLE_CORBORUS_ROCKDOOR:
                        HandleGameObject(_corborusRockDoorGUID, true);
                        break;
                    case DATA_MILLHOUSE_EVENT_FACE:
                        MillhouseEvent_Face();
                        break;
                    case DATA_MILLHOUSE_EVENT_KNOCKBACK:
                        MillhouseEvent_Knockback();
                        break;
                    case DATA_MILLHOUSE_EVENT_DESPAWN:
                        MillhouseEvent_Despawn();
                        break;
                    case DATA_SLABHIDE_ROCK_WALL: // Handles rock walls
                        for (ObjectGuid guid : _slabhideRockWallGUIDs)
                            HandleGameObject((guid), data ? true : false);
                        break;
                    case DATA_EVENT_PROGRESS:
                        if (data == EVENT_INDEX_CORBORUS_INTRO)
                        {
                            if (Creature* corborus = GetCreature(DATA_CORBORUS))
                                corborus->AI()->DoAction(ACTION_CORBORUS_INTRO);
                        }
                        else if (data == EVENT_INDEX_SLABHIDE_INTRO)
                        {
                            if (Creature* slabhide = GetCreature(DATA_SLABHIDE))
                                slabhide->AI()->DoAction(ACTION_SLABHIDE_INTRO);
                        }

                        _eventIndex = data;
                        SaveToDB();
                        break;
                    default:
                        break;
                }
            }

            void Update(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_RESPAWN_CORBORUS:
                            instance->SummonCreature(BOSS_CORBORUS, CorborusRespawnPos);
                            break;
                        case EVENT_RESPAWN_SLABHIDE:
                            instance->SummonCreature(BOSS_SLABHIDE, SlabhideRespawnPos);
                            break;
                        default:
                            break;
                    }
                }
            }

            void WriteSaveDataMore(std::ostringstream& data) override
            {
                data << _eventIndex;
            }

            void ReadSaveDataMore(std::istringstream& data) override
            {
                data >> _eventIndex;
            }

        private:
            // Face Millhouse and other nearby mobs to Corborus
            void MillhouseEvent_Face()
            {
                if (Creature* Millhouse = GetCreature(DATA_MILLHOUSE_MANASTORM))
                    Millhouse->SetFacingTo(1.570796f);
                for (ObjectGuid guid : _millhouseLastGroupGUIDs)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->SetFacingTo(1.570796f);
            }

            // Knock back Millhouse and other mobs
            void MillhouseEvent_Knockback()
            {
                if (Creature* Millhouse = GetCreature(DATA_MILLHOUSE_MANASTORM))
                    Millhouse->CastSpell(Millhouse, SPELL_RING_WYRM_KNOCKBACK, true);
                for (ObjectGuid guid : _millhouseLastGroupGUIDs)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->CastSpell(creature, SPELL_RING_WYRM_KNOCKBACK, true);
            }

            // Despawn all mobs
            void MillhouseEvent_Despawn()
            {
                if (Creature* Millhouse = GetCreature(DATA_MILLHOUSE_MANASTORM))
                    Millhouse->DespawnOrUnsummon(Seconds(3));
                for (ObjectGuid guid : _millhouseTrashGUIDs)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->DespawnOrUnsummon(Seconds(3));
                for (ObjectGuid guid : _millhouseLastGroupGUIDs)
                    if (Creature* creature = instance->GetCreature(guid))
                        creature->DespawnOrUnsummon(Seconds(3));
            }

            void ActivateTeleporter(Creature* teleporter)
            {
                if (!teleporter)
                    return;

                teleporter->CastSpell(teleporter, SPELL_TELEPORTER_ACTIVE_VISUAL, true);
                teleporter->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
            }

            EventMap _events;
            GuidVector _millhouseTrashGUIDs;
            GuidVector _millhouseLastGroupGUIDs;
            ObjectGuid _corborusRockDoorGUID;
            GuidVector _slabhideRockWallGUIDs;
            uint8 _eventIndex;
            bool _initialSetupDone;
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_stonecore_InstanceScript(map);
        }
};

void AddSC_instance_stonecore()
{
    new instance_stonecore();
}
