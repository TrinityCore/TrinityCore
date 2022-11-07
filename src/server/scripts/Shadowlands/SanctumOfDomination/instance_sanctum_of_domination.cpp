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

#include "Creature.h"
#include "CreatureAI.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "Player.h"
#include "ScriptMgr.h"
#include "sanctum_of_domination.h"

ObjectData const creatureData[] =
{
    { BOSS_SYLVANAS_WINDRUNNER,        DATA_SYLVANAS_WINDRUNNER         },
    { NPC_BOLVAR_FORDRAGON_PINNACLE,   DATA_BOLVAR_FORDRAGON_PINNACLE   },
    { NPC_JAINA_PROUDMOORE_PINNACLE,   DATA_JAINA_PROUDMOORE_PINNACLE   },
    { NPC_THRALL_PINNACLE,             DATA_THRALL_PINNACLE             },
    { NPC_ANDUIN_CRUCIBLE,             DATA_ANDUIN_CRUCIBLE             },
    { NPC_SYLVANAS_SHADOWCOPY_RIDING,  DATA_SYLVANAS_SHADOWCOPY_RIDING  },
    { 0,                               0                                } // END
};

class instance_sanctum_of_domination : public InstanceMapScript
{
public:
    instance_sanctum_of_domination() : InstanceMapScript(SDScriptName, 2450) { }

    struct instance_sanctum_of_domination_InstanceMapScript : public InstanceScript
    {
        instance_sanctum_of_domination_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadObjectData(creatureData, nullptr);
        }

        void OnPlayerEnter(Player* /*player*/) override
        {
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case BOSS_SYLVANAS_WINDRUNNER:
                    SylvanasGUID = creature->GetGUID();
                    break;

                case NPC_SYLVANAS_SHADOWCOPY_RIDING:
                    SylvanasShadowcopyRidingGUID = creature->GetGUID();
                    break;

                case NPC_SYLVANAS_SHADOWCOPY_FIGHTER:
                    SylvanasShadowcopyGUID.push_back(creature->GetGUID());
                    break;

                case NPC_BOLVAR_FORDRAGON_PINNACLE:
                    BolvarPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_JAINA_PROUDMOORE_PINNACLE:
                    JainaPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_THRALL_PINNACLE:
                    ThrallPinnacleGUID = creature->GetGUID();
                    break;

                case NPC_ANDUIN_CRUCIBLE:
                    AnduinCrucibleGUID = creature->GetGUID();
                    break;

                default:
                    break;
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
                case GAMEOBJECT_TORGHAST_SPIKE_01:
                case GAMEOBJECT_TORGHAST_SPIKE_02:
                case GAMEOBJECT_TORGHAST_SPIKE_03:
                case GAMEOBJECT_TORGHAST_SPIKE_04:
                case GAMEOBJECT_TORGHAST_SPIKE_05:
                case GAMEOBJECT_TORGHAST_SPIKE_06:
                case GAMEOBJECT_TORGHAST_SPIKE_07:
                case GAMEOBJECT_TORGHAST_SPIKE_08:
                case GAMEOBJECT_TORGHAST_SPIKE_09:
                case GAMEOBJECT_TORGHAST_SPIKE_10:
                case GAMEOBJECT_TORGHAST_SPIKE_11:
                case GAMEOBJECT_TORGHAST_SPIKE_12:
                    TorghastSpikeGUID.push_back(go->GetGUID());
                    break;

                case GAMEOBJECT_INVISIBLE_WALL_PHASE_2:
                    InvisibleWallPhaseTwoGUID.push_back(go->GetGUID());
                    break;

                default:
                    break;
            }
        }

        ObjectGuid GetGuidData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_SYLVANAS_WINDRUNNER:
                    return SylvanasGUID;
                case DATA_SYLVANAS_SHADOWCOPY_RIDING:
                    return SylvanasShadowcopyRidingGUID;
                case DATA_SYLVANAS_SHADOWCOPY_00:
                    return SylvanasShadowcopyGUID[0];
                case DATA_SYLVANAS_SHADOWCOPY_01:
                    return SylvanasShadowcopyGUID[1];
                case DATA_SYLVANAS_SHADOWCOPY_02:
                    return SylvanasShadowcopyGUID[2];
                case DATA_SYLVANAS_SHADOWCOPY_03:
                    return SylvanasShadowcopyGUID[3];
                case DATA_SYLVANAS_SHADOWCOPY_04:
                    return SylvanasShadowcopyGUID[4];
                case DATA_SYLVANAS_SHADOWCOPY_05:
                    return SylvanasShadowcopyGUID[5];
                case DATA_SYLVANAS_SHADOWCOPY_06:
                    return SylvanasShadowcopyGUID[6];
                case DATA_SYLVANAS_SHADOWCOPY_07:
                    return SylvanasShadowcopyGUID[7];
                case DATA_SYLVANAS_SHADOWCOPY_08:
                    return SylvanasShadowcopyGUID[8];
                case DATA_SYLVANAS_SHADOWCOPY_09:
                    return SylvanasShadowcopyGUID[9];
                case DATA_SYLVANAS_SHADOWCOPY_10:
                    return SylvanasShadowcopyGUID[10];
                case DATA_SYLVANAS_SHADOWCOPY_11:
                    return SylvanasShadowcopyGUID[11];
                case DATA_BOLVAR_FORDRAGON_PINNACLE:
                    return BolvarPinnacleGUID;
                case DATA_JAINA_PROUDMOORE_PINNACLE:
                    return JainaPinnacleGUID;
                case DATA_THRALL_PINNACLE:
                    return ThrallPinnacleGUID;
                case DATA_ANDUIN_CRUCIBLE:
                    return AnduinCrucibleGUID;
                default:
                    break;
            }

            return ObjectGuid::Empty;
        }

        bool SetBossState(uint32 id, EncounterState state) override
        {
            if (!InstanceScript::SetBossState(id, state))
                return false;

            switch (id)
            {
                case DATA_SYLVANAS_WINDRUNNER:
                {
                    switch (state)
                    {
                        case NOT_STARTED:
                            DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_STARTED, 0);
                            for (ObjectGuid const& spikeGUID : TorghastSpikeGUID)
                                if (GameObject* torghastSpike = instance->GetGameObject(spikeGUID))
                                    torghastSpike->SetSpellVisualId(0);
                            for (ObjectGuid const& invisibleWallGUID : InvisibleWallPhaseTwoGUID)
                                if (GameObject* invisibleWall = instance->GetGameObject(invisibleWallGUID))
                                    invisibleWall->Respawn();
                            break;

                        case IN_PROGRESS:
                        {
                            Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER);
                            if (!sylvanas)
                                return false;

                            DoUpdateWorldState(WORLD_STATE_SYLVANAS_ENCOUNTER_STARTED, 1);

                            if (Creature* bolvar = GetCreature(DATA_BOLVAR_FORDRAGON_PINNACLE))
                            {
                                bolvar->CastSpell(bolvar, SPELL_SYLVANAS_MODIFY_CHAMPIONS_FACTION, true);

                                if (bolvar->IsAIEnabled())
                                    bolvar->AI()->JustEngagedWith(sylvanas);
                            }

                            if (Creature* thrall = GetCreature(DATA_THRALL_PINNACLE))
                            {
                                thrall->CastSpell(thrall, SPELL_SYLVANAS_MODIFY_CHAMPIONS_FACTION, true);

                                if (thrall->IsAIEnabled())
                                    thrall->AI()->JustEngagedWith(sylvanas);
                            }

                            if (Creature* jaina = GetCreature(DATA_JAINA_PROUDMOORE_PINNACLE))
                            {
                                jaina->CastSpell(jaina, SPELL_SYLVANAS_MODIFY_CHAMPIONS_FACTION, true);

                                if (jaina->IsAIEnabled())
                                    jaina->AI()->JustEngagedWith(sylvanas);
                            }
                            break;
                        }

                        case FAIL:
                            SylvanasShadowcopyGUID.clear();
                            Events.ScheduleEvent(EVENT_RESET_PLAYERS_ON_SYLVANAS, 1s);
                            break;

                        default:
                            break;
                    }

                    break;
                }

                default:
                    break;
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_SYLVANAS_INTRO:
                {
                    switch (data)
                    {
                        case NOT_STARTED:
                        {
                            /*
                            if (GetBossState(DATA_SYLVANAS_WINDRUNNER) != DONE)
                            {
                                if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                {
                                    sylvanas->SetUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                    sylvanas->SetImmuneToAll(true);

                                    sylvanas->SetSpeed(UnitMoveType::MOVE_RUN, 4.0f);
                                }
                            }
                            */
                            break;
                        }

                        case DONE:
                        {
                            if (GetBossState(DATA_SYLVANAS_WINDRUNNER) != DONE)
                            {
                                if (Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER))
                                {
                                    sylvanas->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
                                    sylvanas->SetImmuneToAll(false);

                                    sylvanas->SetSpeed(UnitMoveType::MOVE_RUN, 14.0f);
                                }
                            }
                            break;
                        }

                        default:
                            break;
                    }
                    break;
                }
                default:
                    break;
            }
        }

        void Update(uint32 diff) override
        {
            DoCheckEvadeForSylvanasEncounter();

            Events.Update(diff);

            while (uint32 eventId = Events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_RESET_PLAYERS_ON_SYLVANAS:
                    {
                        Map::PlayerList const& playerList = instance->GetPlayers();

                        for (Map::PlayerList::const_iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
                        {
                            if (Player* player = itr->GetSource())
                            {
                                if (player->GetAreaId() != AREA_PINNACLE_OF_DOMINANCE)
                                    player->NearTeleportTo(SylvanasPlatformRevivePos, false);
                            }
                        }

                        break;
                    }

                    default:
                        break;
                }
            }
        }

        void DoCheckEvadeForSylvanasEncounter()
        {
            if (GetBossState(DATA_SYLVANAS_WINDRUNNER) != IN_PROGRESS)
                return;

            Creature* sylvanas = GetCreature(DATA_SYLVANAS_WINDRUNNER);

            if (sylvanas && DoCheckEvadeForBossIfNoPlayerIsEngaged(sylvanas))
            {
                if (sylvanas->IsAIEnabled())
                    sylvanas->AI()->EnterEvadeMode(CreatureAI::EvadeReason::EVADE_REASON_NO_HOSTILES);
            }
        }

        bool DoCheckEvadeForBossIfNoPlayerIsEngaged(Creature* boss)
        {
            for (ThreatReference const* ref : boss->GetThreatManager().GetUnsortedThreatList())
                if (ref->GetVictim()->GetTypeId() == TYPEID_PLAYER)
                    return false;
            return true;
        }

        protected:
            EventMap Events;
            ObjectGuid SylvanasGUID;
            ObjectGuid SylvanasShadowcopyRidingGUID;
            std::vector<ObjectGuid> SylvanasShadowcopyGUID;
            ObjectGuid BolvarPinnacleGUID;
            ObjectGuid JainaPinnacleGUID;
            ObjectGuid ThrallPinnacleGUID;
            ObjectGuid AnduinCrucibleGUID;
            std::vector<ObjectGuid> TorghastSpikeGUID;
            std::vector<ObjectGuid> InvisibleWallPhaseTwoGUID;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_sanctum_of_domination_InstanceMapScript(map);
    }
};

void AddSC_instance_sanctum_of_domination()
{
    new instance_sanctum_of_domination();
}
