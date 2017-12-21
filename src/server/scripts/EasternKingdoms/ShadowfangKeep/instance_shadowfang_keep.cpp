/*
 * Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "shadowfang_keep.h"
#include "TemporarySummon.h"
#include "Player.h"

ObjectData const creatureData[] =
{
    { BOSS_BARON_ASHBURY,               DATA_BARON_ASHBURY          },
    { BOSS_BARON_SILVERLAINE,           DATA_BARON_SILVERLAINE      },
    { BOSS_COMMANDER_SPRINGVALE,        DATA_COMMANDER_SPRINGVALE   },
    { BOSS_LORD_WALDEN,                 DATA_LORD_WALDEN            },
    { BOSS_LORD_GODFREY,                DATA_LORD_GODFREY           },
    { NPC_PACKLEADER_IVAR,              DATA_PACKLEADER_IVAR        },
    { NPC_DEATHSTALKER_BELMONT,         DATA_DEATHSTALKER_BELMONT   },
    { NPC_HIGH_WARLORD_CROMUSH,         DATA_HIGH_WARLORD_CROMUSH   },
    { 0,                                0                           } // END
};

ObjectData const gameobjectData[] =
{
    { GO_COURTYARD_DOOR,                DATA_COURTYARD_DOOR,        },
    { GO_SORCERER_DOOR,                 DATA_SORCERER_GATE,         },
    { GO_ARUGAL_DOOR,                   DATA_ARUGAL_DOOR,           },
    { 0,                                0                           } // END
};

DoorData const doorData[] =
{
    { GO_ARUGAL_DOOR,                    DATA_LORD_GODFREY,              DOOR_TYPE_ROOM    },
    { 0,                                 0,                              DOOR_TYPE_ROOM    }, // END
};

BossBoundaryData const boundaries =
{
    { DATA_COMMANDER_SPRINGVALE,  new ParallelogramBoundary(Position(-222.75f, 2269.03f), Position(-217.60f, 2249.65f), Position(-267.47f, 2256.10f)) },
    { DATA_LORD_WALDEN,  new CircleBoundary(Position(-146.58f, 2173.037f), 17.0) },
};

class instance_shadowfang_keep : public InstanceMapScript
{
public:
    instance_shadowfang_keep() : InstanceMapScript(SKScriptName, 33) { }

    struct instance_shadowfang_keep_InstanceMapScript : public InstanceScript
    {
        instance_shadowfang_keep_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);
            SetBossNumber(EncounterCount);
            LoadDoorData(doorData);
            LoadBossBoundaries(boundaries);
            LoadObjectData(creatureData, gameobjectData);
            _teamInInstance = 0;
            _courtyardDoorState = 0;
            _sorcererGateState = 0;
            _instanceSpawned = false;
        }

        void OnPlayerEnter(Player* player) override
        {
            if (!_teamInInstance)
            {
                _teamInInstance = player->GetTeam();
                SetData(DATA_TEAM_IN_INSTANCE, _teamInInstance);
            }

            if (!_instanceSpawned)
            {
                SetupInstance();
                _instanceSpawned = true;
            }

            if (GetData(DATA_GODFREY_INTRO) != DONE)
                if (GameObject* door = GetGameObject(DATA_ARUGAL_DOOR))
                    door->SetGoState(GO_STATE_READY);
        }

        void SetupInstance() // set up instance state depending on the progression within the instance after unloading the instance for some reason (eg. crash)
        {
            switch (_teamInInstance) // the following code is a tempfix
            {
                case ALLIANCE:
                    if (GetBossState(DATA_BARON_ASHBURY) != DONE)
                    {
                        if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[0]))
                            for (uint8 i = 0; i < 6; i++)
                                ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]);
                    }
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) != DONE)
                        HandleAshburyDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) != DONE)
                        HandleSilverlaineDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) == DONE && GetBossState(DATA_LORD_WALDEN) != DONE)
                        HandleSpringvaleDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) == DONE && GetBossState(DATA_LORD_WALDEN) == DONE
                        && GetBossState(DATA_LORD_GODFREY) != DONE)
                        HandleWaldenDeath();
                    break;
                case HORDE:
                    if (_teamInInstance == HORDE)
                        instance->SummonCreatureGroup(0);

                    if (GetBossState(DATA_BARON_ASHBURY) != DONE)
                    {
                        if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[0]))
                        {
                            for (uint8 i = 0; i < 4; i++)
                                belmont->SummonCreature(NPC_VETERAN_FORSAKEN_TROOPER, SKHordeSpawnPositions[i]);
                            for (uint8 i = 4; i < 6; i++)
                                belmont->SummonCreature(NPC_FORSAKEN_BLIGHTSPREADER, SKHordeSpawnPositions[i]);
                        }
                    }
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) != DONE)
                        HandleAshburyDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) != DONE)
                        HandleSilverlaineDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) == DONE && GetBossState(DATA_LORD_WALDEN) != DONE)
                        HandleSpringvaleDeath();
                    else if (GetBossState(DATA_BARON_ASHBURY) == DONE && GetBossState(DATA_BARON_SILVERLAINE) == DONE
                        && GetBossState(DATA_COMMANDER_SPRINGVALE) == DONE && GetBossState(DATA_LORD_WALDEN) == DONE
                        &&  GetBossState(DATA_LORD_GODFREY) != DONE)
                        HandleWaldenDeath();
                    break;
                default:
                    break;
            }
        }

        void HandleAshburyDeath()
        {
            if (_teamInInstance == ALLIANCE)
            {
                if (Creature* oldIvar = GetCreature(DATA_PACKLEADER_IVAR))
                    oldIvar->AI()->DoAction(ACTION_DESPAWN);

                if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[1]))
                {
                    ivar->AI()->DoAction(ACTION_ASHBURY_DEAD);
                    for (uint8 i = 6; i < 12; i++)
                        if (Creature* worgen = ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]))
                            worgen->AI()->DoAction(i);
                }
            }
            else
            {
                if (Creature* oldBelmont = GetCreature(DATA_DEATHSTALKER_BELMONT))
                    oldBelmont->AI()->DoAction(ACTION_DESPAWN);

                if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[1]))
                {
                    belmont->AI()->DoAction(ACTION_ASHBURY_DEAD);
                    for (uint8 i = 6; i < 10; i++)
                        belmont->SummonCreature(NPC_VETERAN_FORSAKEN_TROOPER, SKHordeSpawnPositions[i]);
                    for (uint8 i = 10; i < 12; i++)
                        belmont->SummonCreature(NPC_FORSAKEN_BLIGHTSPREADER, SKHordeSpawnPositions[i]);

                }
            }
        }

        void HandleSilverlaineDeath()
        {
            if (_teamInInstance == ALLIANCE)
            {
                if (Creature* oldIvar = GetCreature(DATA_PACKLEADER_IVAR))
                    oldIvar->AI()->DoAction(ACTION_DESPAWN);
                if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[2]))
                {
                    ivar->AI()->DoAction(ACTION_SILVERLAINE_DEAD);
                    for (uint8 i = 12; i < 18; i++)
                        if (Creature* worgen = ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]))
                            worgen->AI()->DoAction(i);
                }
            }
            else
            {
                if (Creature* oldBelmont = GetCreature(DATA_DEATHSTALKER_BELMONT))
                    oldBelmont->AI()->DoAction(ACTION_DESPAWN);
                if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[2]))
                {
                    belmont->AI()->DoAction(ACTION_SILVERLAINE_DEAD);
                    for (uint8 i = 12; i < 16; i++)
                        belmont->SummonCreature(NPC_VETERAN_FORSAKEN_TROOPER, SKHordeSpawnPositions[i]);
                    for (uint8 i = 16; i < 18; i++)
                        belmont->SummonCreature(NPC_FORSAKEN_BLIGHTSPREADER, SKHordeSpawnPositions[i]);
                }
            }
        }

        void HandleSpringvaleDeath()
        {
            if (_teamInInstance == ALLIANCE)
            {
                if (Creature* ivar = GetCreature(DATA_PACKLEADER_IVAR))
                {
                    ivar->AI()->DoAction(ACTION_DESPAWN_BERSERKERS);
                    for (uint8 i = 18; i < 21; i++)
                        if (Creature* worgen = ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]))
                            worgen->AI()->DoAction(i);
                }
            }
            else
            {
                if (Creature* oldBelmont = GetCreature(DATA_DEATHSTALKER_BELMONT))
                    oldBelmont->AI()->DoAction(ACTION_DESPAWN);
                if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[3]))
                    belmont->AI()->DoAction(ACTION_SPRINGVALE_DEAD);
            }
        }

        void HandleWaldenDeath()
        {
            if (_teamInInstance == ALLIANCE)
            {
                if (Creature* oldIvar = GetCreature(DATA_PACKLEADER_IVAR))
                    oldIvar->AI()->DoAction(ACTION_DESPAWN);
                if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[4]))
                {
                    ivar->AI()->DoAction(ACTION_WALDEN_DEAD);
                    for (uint8 i = 21; i < 28; i++)
                        if (Creature* worgen = ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]))
                            worgen->AI()->DoAction(i);
                }
            }
            else
            {
                if (Creature* oldBelmont = GetCreature(DATA_DEATHSTALKER_BELMONT))
                    oldBelmont->AI()->DoAction(ACTION_DESPAWN);

                if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[4]))
                {
                    belmont->AI()->DoAction(ACTION_WALDEN_DEAD);
                    for (uint8 i = 18; i < 22; i++)
                        if (Creature* trooper = belmont->SummonCreature(NPC_VETERAN_FORSAKEN_TROOPER, SKHordeSpawnPositions[i]))
                            trooper->AI()->DoAction(ACTION_CHEER);

                    for (uint8 i = 22; i < 24; i++)
                        if (Creature* spreader = belmont->SummonCreature(NPC_FORSAKEN_BLIGHTSPREADER, SKHordeSpawnPositions[i]))
                            spreader->AI()->DoAction(ACTION_CHEER);
                }
                if (Creature* oldCromush = GetCreature(DATA_HIGH_WARLORD_CROMUSH))
                    oldCromush->DespawnOrUnsummon(0);
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            InstanceScript::OnCreatureCreate(creature);

            switch (creature->GetEntry())
            {
                case NPC_DISEASE_BUNNY:
                    creature->CastSpell(creature, SPELL_DISEASE_CLOUD, true);
                    break;
                case NPC_FORSAKEN_BLIGHTSPREADER:
                    creature->SetDisplayId(creature->GetCreatureTemplate()->Modelid1);
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
                case DATA_BARON_ASHBURY:
                    if (state == DONE)
                    {
                        if (_teamInInstance == HORDE)
                            instance->SummonCreatureGroup(SUMMON_GROUP_BLIGHT_ASHBURY);
                        HandleAshburyDeath();
                    }
                    break;
                case DATA_BARON_SILVERLAINE:
                    if (state == DONE)
                        HandleSilverlaineDeath();
                    break;
                case DATA_COMMANDER_SPRINGVALE:
                    if (state == DONE)
                    {
                        if (_teamInInstance == HORDE)
                            instance->SummonCreatureGroup(SUMMON_GROUP_BLIGHT_SPRINGVALE);
                        HandleSpringvaleDeath();
                    }
                    break;
                case DATA_LORD_WALDEN:
                    if (state == DONE)
                    {
                        if (_teamInInstance == HORDE)
                            instance->SummonCreatureGroup(SUMMON_GROUP_BLIGHT_WALDEN);
                        HandleWaldenDeath();
                    }
                    break;
                default:
                    break;
            }

            return true;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    return _teamInInstance;
                default:
                    break;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
                case DATA_TEAM_IN_INSTANCE:
                    _teamInInstance = data;
                    SaveToDB();
                    break;
                case DATA_ASHBURY_OUTRO:
                    _courtyardDoorState = data;
                    if (GameObject* door = GetGameObject(DATA_COURTYARD_DOOR))
                        door->SetGoState(data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    SaveToDB();
                    break;
                case DATA_WALDEN_INTRO:
                    _waldenIntroState = data;
                    if (_teamInInstance == ALLIANCE)
                    {
                        if (Creature* oldIvar = GetCreature(DATA_PACKLEADER_IVAR))
                            oldIvar->AI()->DoAction(ACTION_DESPAWN);
                        if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[3]))
                            ivar->AI()->DoAction(ACTION_WALDEN_INTRO);
                    }
                    SaveToDB();
                    break;
                case DATA_WALDEN_OUTRO:
                    _sorcererGateState = data;
                    if (GameObject* door = GetGameObject(DATA_SORCERER_GATE))
                        door->SetGoState(data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    if (_teamInInstance == HORDE && data == DONE)
                    {
                        for (uint8 i = 24; i < 28; i++)
                            if (Creature* trooper = instance->SummonCreature(NPC_VETERAN_FORSAKEN_TROOPER, SKHordeSpawnPositions[i]))
                                trooper->AddAura(SPELL_PERMANENT_FEIGN_DEATH, trooper);

                        for (uint8 i = 28; i < 30; i++)
                            if (Creature* spreader = instance->SummonCreature(NPC_FORSAKEN_BLIGHTSPREADER, SKHordeSpawnPositions[i]))
                                spreader->AddAura(SPELL_PERMANENT_FEIGN_DEATH, spreader);
                    }
                    SaveToDB();
                    break;
                case DATA_GODFREY_INTRO:
                    _arugalDoorState = data;
                    if (data == IN_PROGRESS)
                    {
                        if (_teamInInstance == ALLIANCE)
                        {
                            if (Creature* oldIvar = GetCreature(DATA_PACKLEADER_IVAR))
                                oldIvar->AI()->DoAction(ACTION_DESPAWN);
                            if (Creature* ivar = instance->SummonCreature(NPC_PACKLEADER_IVAR, SKIvarSpawnPositions[5]))
                            {
                                ivar->AI()->DoAction(ACTION_GODFREY_INTRO);
                                for (uint8 i = 28; i < 32; i++)
                                    if (Creature* worgen = ivar->SummonCreature(NPC_BLOODFANG_BERSERKER, SKAllianceSpawnPositions[i]))
                                        worgen->AddAura(SPELL_PERMANENT_FEIGN_DEATH, worgen);
                            }
                        }
                        else
                        {
                            if (Creature* oldBelmont = GetCreature(DATA_DEATHSTALKER_BELMONT))
                                oldBelmont->AI()->DoAction(ACTION_DESPAWN);
                            if (Creature* belmont = instance->SummonCreature(NPC_DEATHSTALKER_BELMONT, SKBelmontSpawnPositions[5]))
                            {
                                belmont->AI()->DoAction(ACTION_GODFREY_INTRO);
                                if (Creature* cromush = belmont->SummonCreature(NPC_HIGH_WARLORD_CROMUSH, SKCromushSpawnPos3))
                                    cromush->AI()->DoAction(ACTION_CROMUSH_SUMMONED_3);
                            }
                        }
                    }
                    if (GameObject* door = GetGameObject(DATA_ARUGAL_DOOR))
                        door->SetGoState(data == DONE ? GO_STATE_ACTIVE : GO_STATE_READY);
                    SaveToDB();
                    break;
                default:
                    break;
            }
        }

        void WriteSaveDataMore(std::ostringstream& data) override
        {
            data << _teamInInstance << ' '
                << _courtyardDoorState << ' '
                << _waldenIntroState << ' '
                << _sorcererGateState << ' '
                << _arugalDoorState;
        }

        void ReadSaveDataMore(std::istringstream& data) override
        {
            data >> _teamInInstance;

            uint32 temp = 0;
            data >> temp;

            if (temp)
                SetData(DATA_ASHBURY_OUTRO, temp);

            temp = 0;
            data >> temp;
            if (temp)
                SetData(DATA_WALDEN_INTRO, temp);

            temp = 0;
            data >> temp;
            if (temp)
                SetData(DATA_WALDEN_OUTRO, temp);

            temp = 0;
            data >> temp;
            if (temp)
                SetData(DATA_GODFREY_INTRO, temp);
        }

        protected:
            EventMap events;

            uint32 _teamInInstance;
            uint32 _courtyardDoorState;
            uint32 _waldenIntroState;
            uint32 _sorcererGateState;
            uint32 _arugalDoorState;
            bool _instanceSpawned;
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_shadowfang_keep_InstanceMapScript(map);
    }
};

void AddSC_instance_shadowfang_keep()
{
    new instance_shadowfang_keep();
}
