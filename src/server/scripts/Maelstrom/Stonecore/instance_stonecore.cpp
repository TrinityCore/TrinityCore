/*
* Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
* Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
#include "Player.h"
#include "CreatureGroups.h"
#include "InstanceScript.h"
#include "stonecore.h"

#define MAX_ENCOUNTER 4

/* Stonecore encounters:
0 - Corborus
1 - Slabhide
2 - Ozruk
3 - High Priestess Azil
*/

// TO-DO:
// - Find out spell IDs for both Stonecore Teleporters (spellclick).

class instance_stonecore : public InstanceMapScript
{
    public:
        instance_stonecore() : InstanceMapScript(SCScriptName, 725) { }

        struct instance_stonecore_InstanceScript : public InstanceScript
        {
            instance_stonecore_InstanceScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(MAX_ENCOUNTER);
            }

            void OnGameObjectCreate(GameObject* go) override
            {
                switch (go->GetEntry())
                {
                    case GAMEOBJECT_CORBORUS_ROCKDOOR:
                        corborusRockDoorGUID = go->GetGUID();
                        go->SetGoState(GetBossState(DATA_CORBORUS) != DONE ? GO_STATE_READY : GO_STATE_ACTIVE);
                        break;
                    case GAMEOBJECT_SLABHIDE_ROCK_WALL:
                        slabhideRockWallGUIDs.push_back(go->GetGUID());
                        break;
                    default:
                        break;
                }
            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_MILLHOUSE_MANASTORM:
                        millhouseGUID = creature->GetGUID();
                        break;
                    case NPC_CORBORUS:
                        corobrusGUID = creature->GetGUID();
                        break;
                    case NPC_SLABHIDE:
                        slabhideGUID = creature->GetGUID();
                        break;
                    case NPC_HIGH_PRIESTESS_AZIL:
                        highPriestessAzilGUID = creature->GetGUID();
                        break;
                    case NPC_STONECORE_TELEPORTER:
                    case NPC_STONECORE_TELEPORTER_2:
                        if (GetBossState(DATA_SLABHIDE) != DONE)
                            stonecoreTeleporterGUID[creature->GetEntry() - NPC_STONECORE_TELEPORTER] = creature->GetGUID();
                        else // If Slabhide is already dead, no need to store teleporter guids
                        {
                            creature->CastSpell(creature, SPELL_TELEPORTER_ACTIVE_VISUAL, true);
                            creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                        }
                        break;
                    default:
                        break;
                }

                // Check if creature is part of Millhouse event
                creature->SearchFormation();
                if (CreatureGroup* group = creature->GetFormation()) // TO-DO: Fix formations
                {
                    switch (group->GetId())
                    {
                        case CREATURE_FORMATION_MILLHOUSE_EVENT_TRASH:
                            millhouseTrashGUIDs.push_back(creature->GetGUID());
                            break;
                        case CREATURE_FORMATION_MILLHOUSE_EVENT_LAST_GROUP:
                            millhouseLastGroupGUIDs.push_back(creature->GetGUID());
                            creature->SetReactState(REACT_PASSIVE);
                            creature->SetMeleeAnimKitId(ANIM_READY2H);
                            break;
                    }
                }
            }

            bool SetBossState(uint32 type, EncounterState state) override
            {
                switch (type)
                {
                    case DATA_SLABHIDE:
                        // Open rock walls (Slabhide AI handles closing because it must be delayed)
                        if (state != IN_PROGRESS)
                            SetData(DATA_SLABHIDE_ROCK_WALL, true);

                        // Activate teleporters
                        if (state == DONE)
                        {
                            for (int8 i = 0; i < MAX_STONECORE_TELEPORTERS; i++)
                            {
                                if (Creature* teleporter = instance->GetCreature(stonecoreTeleporterGUID[i]))
                                {
                                    teleporter->CastSpell(teleporter, SPELL_TELEPORTER_ACTIVE_VISUAL, true);
                                    teleporter->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_SPELLCLICK);
                                }
                            }
                        }

                        break;
                    default:
                        break;
                }

                return InstanceScript::SetBossState(type, state);
            }

            uint32 GetData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_SLABHIDE_INTRO:
                        return slabhideIntro;
                    default:
                        break;
                }

                return 0;
            }

            void SetData(uint32 type, uint32 data) override
            {
                switch (type)
                {
                    case DATA_MILLHOUSE_EVENT_FACE:
                        MillhouseEvent_Face();
                        break;
                    case DATA_MILLHOUSE_EVENT_KNOCKBACK:
                        MillhouseEvent_Knockback();
                        break;
                    case DATA_MILLHOUSE_EVENT_DESPAWN:
                        MillhouseEvent_Despawn();
                        break;
                    case DATA_SLABHIDE_INTRO:
                        slabhideIntro = EncounterState(data);
                        break;
                    case DATA_SLABHIDE_ROCK_WALL: // Handles rock walls
                        for (std::vector<ObjectGuid>::iterator itr = slabhideRockWallGUIDs.begin(); itr != slabhideRockWallGUIDs.end(); ++itr)
                            HandleGameObject((*itr), data ? true : false);
                        break;
                    default:
                        break;
                }
            }

            ObjectGuid GetGuidData(uint32 type) const override
            {
                switch (type)
                {
                    case DATA_MILLHOUSE_MANASTORM:
                        return millhouseGUID;
                    case GAMEOBJECT_CORBORUS_ROCKDOOR:
                        return corborusRockDoorGUID;
                    case DATA_CORBORUS:
                        return corobrusGUID;
                    case DATA_SLABHIDE:
                        return slabhideGUID;
                    case DATA_HIGH_PRIESTESS_AZIL:
                        return highPriestessAzilGUID;
                    case NPC_STONECORE_TELEPORTER:
                    case NPC_STONECORE_TELEPORTER_2:
                        return stonecoreTeleporterGUID[type - NPC_STONECORE_TELEPORTER];
                    default:
                        break;
                }

                return ObjectGuid::Empty;
            }

        private:
            // Face Millhouse and other nearby mobs to Corborus
            void MillhouseEvent_Face()
            {
                if (Creature* Millhouse = instance->GetCreature(millhouseGUID))
                    Millhouse->SetFacingTo(1.570796f);
                for (GuidVector::const_iterator i = millhouseLastGroupGUIDs.begin(); i != millhouseLastGroupGUIDs.end(); ++i)
                    if (Creature* creature = instance->GetCreature(*i))
                        creature->SetFacingTo(1.570796f);
            }

            // Knock back Millhouse and other mobs
            void MillhouseEvent_Knockback()
            {
                if (Creature* Millhouse = instance->GetCreature(millhouseGUID))
                    Millhouse->CastSpell(Millhouse, SPELL_RING_WYRM_KNOCKBACK, true);
                for (GuidVector::const_iterator itr = millhouseLastGroupGUIDs.begin(); itr != millhouseLastGroupGUIDs.end(); ++itr)
                    if (Creature* creature = instance->GetCreature(*itr))
                        creature->CastSpell(creature, SPELL_RING_WYRM_KNOCKBACK, true);
            }

            // Despawn all mobs
            void MillhouseEvent_Despawn()
            {
                if (Creature* Millhouse = instance->GetCreature(millhouseGUID))
                    Millhouse->DespawnOrUnsummon(3000);
                for (GuidVector::const_iterator itr = millhouseTrashGUIDs.begin(); itr != millhouseTrashGUIDs.end(); ++itr)
                    if (Creature* creature = instance->GetCreature(*itr))
                        creature->DespawnOrUnsummon(3000);
                for (GuidVector::const_iterator itr = millhouseLastGroupGUIDs.begin(); itr != millhouseLastGroupGUIDs.end(); ++itr)
                    if (Creature* creature = instance->GetCreature(*itr))
                        creature->DespawnOrUnsummon(3000);
            }

            ObjectGuid millhouseGUID;
            GuidVector millhouseTrashGUIDs;
            GuidVector millhouseLastGroupGUIDs;
            ObjectGuid corborusRockDoorGUID;
            ObjectGuid corobrusGUID;
            ObjectGuid slabhideGUID;
            ObjectGuid highPriestessAzilGUID;
            ObjectGuid stonecoreTeleporterGUID[2];
            GuidVector slabhideRockWallGUIDs;

            EncounterState slabhideIntro;
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
