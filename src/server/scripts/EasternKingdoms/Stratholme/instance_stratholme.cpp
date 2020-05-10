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

 /* ScriptData
 SDName: instance_stratholme
 SD%Complete: 50
 SDComment: In progress. Undead side 75% implemented. Save/load not implemented.
 SDCategory: Stratholme
 EndScriptData */

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "Creature.h"
#include "CreatureAI.h"
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "MotionMaster.h"
#include "Player.h"
#include "stratholme.h"
#include "ObjectMgr.h"
#include "GridNotifiers.h"
#include "ScriptedGossip.h"

enum InstanceEvents
{
    EVENT_BARON_RUN = 1,
    EVENT_SLAUGHTER_SQUARE = 2,
    EVENT_SUMMON_RAMSTEIN = 3,
    EVENT_OPEN_DOOR_4_0 = 4,
    EVENT_RAMSTEIN_LINE = 5,
    EVENT_RAMSTEIN_MOVE = 6,
    EVENT_CLOSE_DOOR_4_0 = 7,
    EVENT_SUMMON_BLACK_GUARD = 8,
    EVENT_OPEN_DOOR_4_1 = 9,
    EVENT_BLACK_GUARD_LINE = 10,
    EVENT_BLACK_GUARD_MOVE = 11,
    EVENT_OPEN_DOOR_5 = 12,
};

enum StratholmeMisc
{
    SAY_YSIDA_SAVED = 0
};

Position const timmyTheCruelSpawnPosition = { 3625.358f, -3188.108f, 130.3985f, 4.834562f };
EllipseBoundary const beforeScarletGate(Position(3671.158f, -3181.79f), 60.0f, 40.0f);

class instance_stratholme : public InstanceMapScript
{
public:
    instance_stratholme() : InstanceMapScript(StratholmeScriptName, 329) { }

    struct instance_stratholme_InstanceMapScript : public InstanceScript
    {
        instance_stratholme_InstanceMapScript(Map* map) : InstanceScript(map)
        {
            SetHeaders(DataHeader);

            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                EncounterState[i] = NOT_STARTED;

            for (uint8 i = 0; i < 5; ++i)
                IsSilverHandDead[i] = false;

            timmySpawned = false;
            scarletsKilled = 0;
            guardsmanActionDelay0 = urand(30000, 60000);
            guardsmanActionDelay1 = urand(30000, 60000);
            guardsmanActionDelay2 = 10000;
            guardsmanLine0 = false;
            guardsmanLine1 = false;
            guardsmanLine2 = false;
            crystalDestroyed0 = false;
            crystalDestroyed1 = false;
            crystalDestroyed2 = false;
            slauterOpened = false;
            crystalMap.clear();
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_0);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_1);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_2);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_3);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_0_4);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_0);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_1);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_2);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_3);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_1_4);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_0);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_1);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_2);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_3);
            crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].insert(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_THUZADIN_ACOLYTE_2_4);

            barthilasLine0 = false;
            barthilasLine0CheckDelay = 1000;
        }

        uint32 EncounterState[MAX_ENCOUNTER];
        uint8 scarletsKilled;

        bool IsSilverHandDead[5];
        bool timmySpawned;

        ObjectGuid serviceEntranceGUID;
        ObjectGuid gauntletGate1GUID;
        ObjectGuid ziggurat1GUID;
        ObjectGuid ziggurat2GUID;
        ObjectGuid ziggurat3GUID;
        ObjectGuid ziggurat4GUID;
        ObjectGuid ziggurat5GUID;
        ObjectGuid portGauntletGUID;
        ObjectGuid portSlaugtherGUID;
        ObjectGuid portElderGUID;
        ObjectGuid ysidaCageGUID;

        ObjectGuid baronGUID;
        ObjectGuid ysidaGUID;
        ObjectGuid ysidaTriggerGUID;
        GuidSet abomnationGUID;
        EventMap events;

        ObjectGuid OGGauntletGate2;
        ObjectGuid OGAurius;
        ObjectGuid OGBossMagistrateBarthilas;
        ObjectGuid OGBossRamstein;
        ObjectGuid OGBlackGuard0;
        ObjectGuid OGBlackGuard1;
        ObjectGuid OGBlackGuard2;
        ObjectGuid OGBlackGuard3;
        std::unordered_map<uint32, std::unordered_set<uint32>> crystalMap;

        int guardsmanActionDelay0;
        int guardsmanActionDelay1;
        int guardsmanActionDelay2;
        bool guardsmanLine0;
        bool guardsmanLine1;
        bool guardsmanLine2;

        bool crystalDestroyed0;
        bool crystalDestroyed1;
        bool crystalDestroyed2;
        bool slauterOpened;
        bool barthilasLine0;
        int barthilasLine0CheckDelay;        

        void OnUnitDeath(Unit* who) override
        {
            switch (who->GetEntry())
            {
            case NPC_CRIMSON_GUARDSMAN:
            case NPC_CRIMSON_CONJUROR:
            case NPC_CRIMSON_INITATE:
            case NPC_CRIMSON_GALLANT:
            {
                if (!timmySpawned)
                {
                    Position pos = who->ToCreature()->GetHomePosition();
                    // check if they're in front of the entrance
                    if (beforeScarletGate.IsWithinBoundary(pos))
                    {
                        if (++scarletsKilled >= TIMMY_THE_CRUEL_CRUSADERS_REQUIRED)
                        {
                            instance->SummonCreature(NPC_TIMMY_THE_CRUEL, timmyTheCruelSpawnPosition);
                            timmySpawned = true;
                        }
                    }
                }
                break;
            }
            case STRCreatureIds::NPC_MANGLED_CADAVER:
            {
                instance->SummonCreature(STRCreatureIds::NPC_BROKEN_CADAVER, who->GetPosition());
                break;
            }
            default:
            {
                break;
            }
            }
        }

        bool StartSlaugtherSquare()
        {
            EncounterState[1] = EncounterState::DONE;
            EncounterState[2] = EncounterState::DONE;
            EncounterState[3] = EncounterState::DONE;
            if (GameObject* goGate = instance->GetGameObject(portGauntletGUID))
            {
                goGate->SetGoState(GOState::GO_STATE_ACTIVE);
            }
            if (GameObject* goGate = instance->GetGameObject(portSlaugtherGUID))
            {
                goGate->SetGoState(GOState::GO_STATE_ACTIVE);
            }
            slauterOpened = true;

            return true;
        }

        //if withRestoreTime true, then newState will be ignored and GO should be restored to original state after 10 seconds
        void UpdateGoState(ObjectGuid goGuid, uint32 newState, bool withRestoreTime)
        {
            if (!goGuid)
                return;

            if (GameObject* go = instance->GetGameObject(goGuid))
            {
                if (withRestoreTime)
                    go->UseDoorOrButton(10);
                else
                    go->SetGoState((GOState)newState);
            }
        }

        void OnCreatureCreate(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_BARON:
                baronGUID = creature->GetGUID();
                break;
            case NPC_YSIDA_TRIGGER:
                ysidaTriggerGUID = creature->GetGUID();
                break;
            case NPC_CRYSTAL:
            {
                // EJ todo spawn acolytes when crystal spawned
                break;
            }
            case NPC_ABOM_BILE:
            case NPC_ABOM_VENOM:
                abomnationGUID.insert(creature->GetGUID());
                break;
            case NPC_YSIDA:
                ysidaGUID = creature->GetGUID();
                creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                break;            
            case STRCreatureIds::NPC_RAMSTEIN:
            {
                OGBossRamstein = creature->GetGUID();
                break;
            }
            case STRCreatureIds::NPC_AURIUS:
            {
                OGAurius = creature->GetGUID();
                break;
            }
            case STRCreatureIds::NPC_MAGISTRATE_BARTHILAS:
            {
                OGBossMagistrateBarthilas = creature->GetGUID();
                break;
            }
            case 10411:
            {
                // EJ eye of nax will not spawn
                creature->DespawnOrUnsummon(0, 24h * 7);
                break;
            }
            default:
            {
                break;
            }
            }
        }

        void OnCreatureRemove(Creature* creature) override
        {
            switch (creature->GetEntry())
            {
            case NPC_CRYSTAL:
                break;
            case NPC_ABOM_BILE:
            case NPC_ABOM_VENOM:
                abomnationGUID.erase(creature->GetGUID());
                break;
            }
        }

        void OnCreatureDied(Creature* creature) override
        {
            if (creature->GetEntry() == STRCreatureIds::NPC_BLACK_GUARD)
            {
                bool allDead = true;
                if (Creature* checkC = instance->GetCreature(OGBlackGuard0))
                {
                    if (checkC->IsAlive())
                    {
                        allDead = false;
                    }
                }
                if (Creature* checkC = instance->GetCreature(OGBlackGuard1))
                {
                    if (checkC->IsAlive())
                    {
                        allDead = false;
                    }
                }
                if (Creature* checkC = instance->GetCreature(OGBlackGuard2))
                {
                    if (checkC->IsAlive())
                    {
                        allDead = false;
                    }
                }
                if (Creature* checkC = instance->GetCreature(OGBlackGuard3))
                {
                    if (checkC->IsAlive())
                    {
                        allDead = false;
                    }
                }
                if (allDead)
                {
                    events.ScheduleEvent(InstanceEvents::EVENT_OPEN_DOOR_5, 1s);
                }
            }
            else if (creature->GetEntry() == STRCreatureIds::NPC_THUZADIN_ACOLYTE)
            {
                if (crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].find(creature->GetSpawnId()) != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].end())
                {
                    bool allDead = true;
                    for (std::unordered_set<uint32>::iterator taIT = crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].begin(); taIT != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0].end(); taIT++)
                    {
                        if (*taIT == creature->GetSpawnId())
                        {
                            continue;
                        }
                        if (Creature* checkTA = instance->GetCreatureBySpawnId(*taIT))
                        {
                            if (checkTA->IsAlive())
                            {
                                allDead = false;
                                break;
                            }
                        }
                    }
                    if (allDead)
                    {
                        if (Creature* checkCrystal = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_0))
                        {
                            checkCrystal->DespawnOrUnsummon(500, 2h);
                        }
                        crystalDestroyed0 = true;
                        int destroyedCount = 0;
                        if (crystalDestroyed0)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed1)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed2)
                        {
                            destroyedCount++;
                        }
                        if (destroyedCount == 1)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_0);
                        }
                        else if (destroyedCount == 2)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_1);
                        }
                        else if (destroyedCount == 3)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_2);
                            StartSlaugtherSquare();
                        }
                    }
                }

                if (crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].find(creature->GetSpawnId()) != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].end())
                {
                    bool allDead = true;
                    for (std::unordered_set<uint32>::iterator taIT = crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].begin(); taIT != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1].end(); taIT++)
                    {
                        if (*taIT == creature->GetSpawnId())
                        {
                            continue;
                        }
                        if (Creature* checkTA = instance->GetCreatureBySpawnId(*taIT))
                        {
                            if (checkTA->IsAlive())
                            {
                                allDead = false;
                                break;
                            }
                        }
                    }
                    if (allDead)
                    {
                        if (Creature* checkCrystal = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_1))
                        {
                            checkCrystal->DespawnOrUnsummon(500, 2h);
                        }
                        crystalDestroyed1 = true;
                        int destroyedCount = 0;
                        if (crystalDestroyed0)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed1)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed2)
                        {
                            destroyedCount++;
                        }
                        if (destroyedCount == 1)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_0);
                        }
                        else if (destroyedCount == 2)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_1);
                        }
                        else if (destroyedCount == 3)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_2);
                            StartSlaugtherSquare();
                        }
                    }
                }

                if (crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].find(creature->GetSpawnId()) != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].end())
                {
                    bool allDead = true;
                    for (std::unordered_set<uint32>::iterator taIT = crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].begin(); taIT != crystalMap[STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2].end(); taIT++)
                    {
                        if (*taIT == creature->GetSpawnId())
                        {
                            continue;
                        }
                        if (Creature* checkTA = instance->GetCreatureBySpawnId(*taIT))
                        {
                            if (checkTA->IsAlive())
                            {
                                allDead = false;
                                break;
                            }
                        }
                    }
                    if (allDead)
                    {
                        if (Creature* checkCrystal = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_ASHARI_CRYSTAL_2))
                        {
                            checkCrystal->DespawnOrUnsummon(500, 2h);
                        }
                        crystalDestroyed2 = true;
                        int destroyedCount = 0;
                        if (crystalDestroyed0)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed1)
                        {
                            destroyedCount++;
                        }
                        if (crystalDestroyed2)
                        {
                            destroyedCount++;
                        }
                        if (destroyedCount == 1)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_0);
                        }
                        else if (destroyedCount == 2)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_1);
                        }
                        else if (destroyedCount == 3)
                        {
                            creature->AI()->Talk(STRATHOLME_LINE_THUZADIN_ACOLYTE::LINE_THUZADIN_ACOLYTE_2);
                            StartSlaugtherSquare();
                        }
                    }
                }
            }
        }

        void OnGameObjectCreate(GameObject* go) override
        {
            switch (go->GetEntry())
            {
            case GO_SERVICE_ENTRANCE:
                serviceEntranceGUID = go->GetGUID();
                break;
            case GO_GAUNTLET_GATE1:
                //weird, but unless flag is set, client will not respond as expected. DB bug?
                go->SetFlag(GAMEOBJECT_FLAGS, GO_FLAG_LOCKED);
                gauntletGate1GUID = go->GetGUID();
                break;
            case STRGameobjectIds::GO_GAUNTLET_GATE2:
            {
                OGGauntletGate2 = go->GetGUID();
                break;
            }
            case GO_ZIGGURAT1:
                ziggurat1GUID = go->GetGUID();
                if (GetData(TYPE_BARONESS) == IN_PROGRESS)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_ZIGGURAT2:
                ziggurat2GUID = go->GetGUID();
                if (GetData(TYPE_NERUB) == IN_PROGRESS)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_ZIGGURAT3:
                ziggurat3GUID = go->GetGUID();
                if (GetData(TYPE_PALLID) == IN_PROGRESS)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_ZIGGURAT4:
                ziggurat4GUID = go->GetGUID();
                if (GetData(TYPE_BARON) == DONE || GetData(TYPE_RAMSTEIN) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_ZIGGURAT5:
                ziggurat5GUID = go->GetGUID();
                if (GetData(TYPE_BARON) == DONE || GetData(TYPE_RAMSTEIN) == DONE)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_PORT_GAUNTLET:
                portGauntletGUID = go->GetGUID();
                if (GetData(TYPE_BARONESS) == IN_PROGRESS && GetData(TYPE_NERUB) == IN_PROGRESS && GetData(TYPE_PALLID) == IN_PROGRESS)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_PORT_SLAUGTHER:
                portSlaugtherGUID = go->GetGUID();
                if (GetData(TYPE_BARONESS) == IN_PROGRESS && GetData(TYPE_NERUB) == IN_PROGRESS && GetData(TYPE_PALLID) == IN_PROGRESS)
                    HandleGameObject(ObjectGuid::Empty, true, go);
                break;
            case GO_PORT_ELDERS:
                portElderGUID = go->GetGUID();
                break;
            case GO_YSIDA_CAGE:
                ysidaCageGUID = go->GetGUID();
                break;
            }
        }

        void SetData(uint32 type, uint32 data) override
        {
            switch (type)
            {
            case TYPE_BARON_RUN:
                switch (data)
                {
                case IN_PROGRESS:
                    if (EncounterState[0] == IN_PROGRESS || EncounterState[0] == FAIL)
                        break;
                    EncounterState[0] = data;
                    events.ScheduleEvent(EVENT_BARON_RUN, 2700000);
                    TC_LOG_DEBUG("scripts", "Instance Stratholme: Baron run in progress.");
                    break;
                case FAIL:
                    DoRemoveAurasDueToSpellOnPlayers(SPELL_BARON_ULTIMATUM);
                    if (Creature* ysida = instance->GetCreature(ysidaGUID))
                    {                        
                        ysida->CastSpell(ysida, SPELL_PERM_FEIGN_DEATH, true);
                        // EJ fix ysida can not talk when dead
                        ysida->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                        ysida->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                    }
                    EncounterState[0] = data;
                    break;
                case DONE:
                    EncounterState[0] = data;

                    if (Creature* ysida = instance->GetCreature(ysidaGUID))
                    {
                        if (ysida->IsAlive())
                        {
                            if (GameObject* cage = instance->GetGameObject(ysidaCageGUID))
                                cage->UseDoorOrButton();

                            float x, y, z;
                            //! This spell handles the Dead man's plea quest completion
                            ysida->CastSpell(nullptr, SPELL_YSIDA_SAVED, true);
                            ysida->SetWalk(true);
                            ysida->AI()->Talk(SAY_YSIDA_SAVED);
                            ysida->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_QUESTGIVER);
                            ysida->GetClosePoint(x, y, z, ysida->GetObjectScale() / 3, 4.0f);
                            ysida->GetMotionMaster()->MovePoint(1, x, y, z);

                            Map::PlayerList const& players = instance->GetPlayers();

                            for (auto const& i : players)
                            {
                                if (Player* player = i.GetSource())
                                {
                                    if (player->IsGameMaster())
                                        continue;

                                    //! im not quite sure what this one is supposed to do
                                    //! this is server-side spell
                                    player->CastSpell(ysida, SPELL_YSIDA_CREDIT_EFFECT, true);
                                }
                            }
                        }                        
                    }
                    events.CancelEvent(EVENT_BARON_RUN);
                    break;
                }
                break;
            case TYPE_BARONESS:
            {
                EncounterState[1] = data;
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(ziggurat1GUID, true);
                }
                break;
            }
            case TYPE_NERUB:
            {
                EncounterState[2] = data;
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(ziggurat2GUID, true);
                }
                break;
            }
            case TYPE_PALLID:
            {
                EncounterState[3] = data;
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(ziggurat3GUID, true);
                }
                break;
            }
            case TYPE_RAMSTEIN:
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(portGauntletGUID, false);

                    uint32 count = abomnationGUID.size();
                    for (GuidSet::const_iterator i = abomnationGUID.begin(); i != abomnationGUID.end(); ++i)
                    {
                        if (Creature* pAbom = instance->GetCreature(*i))
                            if (!pAbom->IsAlive())
                                --count;
                    }

                    if (!count)
                    {
                        events.ScheduleEvent(InstanceEvents::EVENT_SUMMON_RAMSTEIN, 2s);
                        events.ScheduleEvent(InstanceEvents::EVENT_OPEN_DOOR_4_0, 6s);
                        events.ScheduleEvent(InstanceEvents::EVENT_RAMSTEIN_LINE, 7s);
                        events.ScheduleEvent(InstanceEvents::EVENT_RAMSTEIN_MOVE, 8s);
                        events.ScheduleEvent(InstanceEvents::EVENT_CLOSE_DOOR_4_0, 10s);
                        TC_LOG_DEBUG("scripts", "Instance Stratholme: Ramstein spawned.");
                    }
                    else
                        TC_LOG_DEBUG("scripts", "Instance Stratholme: %u Abomnation left to kill.", count);
                }

                if (data == NOT_STARTED)
                    HandleGameObject(portGauntletGUID, true);

                if (data == DONE)
                {
                    events.ScheduleEvent(EVENT_SLAUGHTER_SQUARE, 20s);
                    TC_LOG_DEBUG("scripts", "Instance Stratholme: Slaugther event will continue in 1 minute.");
                }
                EncounterState[4] = data;
                break;
            case TYPE_BARON:
                if (data == IN_PROGRESS)
                {
                    HandleGameObject(ziggurat4GUID, false);
                    HandleGameObject(ziggurat5GUID, false);
                    if (Creature* aurius = instance->GetCreature(OGAurius))
                    {
                        aurius->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                        aurius->RemoveFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_QUESTGIVER);
                        aurius->NearTeleportTo(4024.22f, -3355.63f, 115.1f, 0.36f);
                        aurius->AI()->SetData(AURIUS_DATA_TYPE::DATA_TYPE_ENGAGE, 0);
                    }
                }
                if (data == DONE || data == NOT_STARTED)
                {
                    HandleGameObject(ziggurat4GUID, true);
                    HandleGameObject(ziggurat5GUID, true);
                }
                if (data == DONE)
                {
                    HandleGameObject(portGauntletGUID, true);
                    if (GetData(TYPE_BARON_RUN) == IN_PROGRESS)
                        DoRemoveAurasDueToSpellOnPlayers(SPELL_BARON_ULTIMATUM);

                    if (GetData(TYPE_BARON_RUN) != FAIL)
                    {
                        SetData(TYPE_BARON_RUN, DONE);
                    }
                    if (Creature* aurius = instance->GetCreature(OGAurius))
                    {
                        aurius->AI()->SetData(AURIUS_DATA_TYPE::DATA_TYPE_VICTORY, 0);
                    }
                }
                EncounterState[5] = data;
                break;
            case TYPE_SH_AELMAR:
                IsSilverHandDead[0] = (data) ? true : false;
                break;
            case TYPE_SH_CATHELA:
                IsSilverHandDead[1] = (data) ? true : false;
                break;
            case TYPE_SH_GREGOR:
                IsSilverHandDead[2] = (data) ? true : false;
                break;
            case TYPE_SH_NEMAS:
                IsSilverHandDead[3] = (data) ? true : false;
                break;
            case TYPE_SH_VICAR:
                IsSilverHandDead[4] = (data) ? true : false;
                break;
            default:
            {
                break;
            }
            }

            if (data == DONE)
                SaveToDB();
        }

        std::string GetSaveData() override
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << EncounterState[0] << ' ' << EncounterState[1] << ' ' << EncounterState[2] << ' '
                << EncounterState[3] << ' ' << EncounterState[4] << ' ' << EncounterState[5];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void Load(char const* in) override
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            std::istringstream loadStream(in);
            loadStream >> EncounterState[0] >> EncounterState[1] >> EncounterState[2] >> EncounterState[3]
                >> EncounterState[4] >> EncounterState[5];

            // Do not reset 1, 2 and 3. they are not set to done, yet .
            if (EncounterState[0] == IN_PROGRESS)
                EncounterState[0] = NOT_STARTED;
            if (EncounterState[4] == IN_PROGRESS)
                EncounterState[4] = NOT_STARTED;
            if (EncounterState[5] == IN_PROGRESS)
                EncounterState[5] = NOT_STARTED;

            OUT_LOAD_INST_DATA_COMPLETE;
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case TYPE_SH_QUEST:
                if (IsSilverHandDead[0] && IsSilverHandDead[1] && IsSilverHandDead[2] && IsSilverHandDead[3] && IsSilverHandDead[4])
                    return 1;
                return 0;
            case TYPE_BARON_RUN:
                return EncounterState[0];
            case TYPE_BARONESS:
                return EncounterState[1];
            case TYPE_NERUB:
                return EncounterState[2];
            case TYPE_PALLID:
                return EncounterState[3];
            case TYPE_RAMSTEIN:
                return EncounterState[4];
            case TYPE_BARON:
                return EncounterState[5];
            }
            return 0;
        }

        ObjectGuid GetGuidData(uint32 data) const override
        {
            switch (data)
            {
            case DATA_BARON:
                return baronGUID;
            case DATA_YSIDA_TRIGGER:
                return ysidaTriggerGUID;
            case NPC_YSIDA:
                return ysidaGUID;
            }
            return ObjectGuid::Empty;
        }

        void Update(uint32 diff) override
        {
            if (!barthilasLine0)
            {
                barthilasLine0CheckDelay -= diff;
                if (barthilasLine0CheckDelay < 0)
                {
                    barthilasLine0CheckDelay = 1000;
                    if (GameObject* goServiceDoor = instance->GetGameObject(serviceEntranceGUID))
                    {
                        if (goServiceDoor->GetGoState() == GOState::GO_STATE_ACTIVE)
                        {
                            if (Creature* checkC = instance->GetCreature(OGBossMagistrateBarthilas))
                            {
                                if (checkC->IsAlive())
                                {
                                    checkC->AI()->Talk(STRATHOLME_LINE_MAGISTRATE_BARTHILAS::LINE_MAGISTRATE_BARTHILAS_0);
                                }
                                barthilasLine0 = true;
                            }
                        }
                    }
                }
            }

            if (!guardsmanLine0)
            {
                guardsmanActionDelay0 -= diff;
                if (guardsmanActionDelay0 < 0)
                {
                    guardsmanActionDelay0 = urand(10000, 20000);
                    if (Creature* checkGuardsman = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_CRIMSON_GUARDSMAN_0))
                    {
                        if (checkGuardsman->IsAlive())
                        {
                            if (Player* checkP = checkGuardsman->SelectNearestPlayer(100.0f))
                            {
                                checkGuardsman->AI()->Talk(STRATHOLME_LINE_CRIMSON_GUARDSMAN::LINE_CRIMSON_GUARDSMAN_0);
                                guardsmanLine0 = true;
                            }
                        }
                    }
                }
            }

            if (!guardsmanLine1)
            {
                guardsmanActionDelay1 -= diff;
                if (guardsmanActionDelay1 < 0)
                {
                    guardsmanActionDelay1 = urand(10000, 20000);
                    if (Creature* checkGuardsman = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_CRIMSON_GUARDSMAN_1))
                    {
                        if (checkGuardsman->IsAlive())
                        {
                            if (Player* checkP = checkGuardsman->SelectNearestPlayer(100.0f))
                            {
                                checkGuardsman->AI()->Talk(STRATHOLME_LINE_CRIMSON_GUARDSMAN::LINE_CRIMSON_GUARDSMAN_1);
                                guardsmanLine1 = true;
                            }
                        }
                    }
                }
            }

            if (!guardsmanLine2)
            {
                guardsmanActionDelay2 -= diff;
                if (guardsmanActionDelay2 < 0)
                {
                    guardsmanActionDelay2 = 10000;
                    if (Creature* checkGuardsman = instance->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_CRIMSON_GUARDSMAN_2))
                    {
                        if (checkGuardsman->IsAlive())
                        {
                            if (checkGuardsman->SelectNearestPlayer(5.0f))
                            {
                                checkGuardsman->AI()->Talk(STRATHOLME_LINE_CRIMSON_GUARDSMAN::LINE_CRIMSON_GUARDSMAN_2);
                                guardsmanLine2 = true;
                            }
                        }
                    }
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_BARON_RUN:
                    if (GetData(TYPE_BARON_RUN) != DONE)
                        SetData(TYPE_BARON_RUN, FAIL);
                    TC_LOG_DEBUG("scripts", "Instance Stratholme: Baron run event reached end. Event has state %u.", GetData(TYPE_BARON_RUN));
                    break;
                case EVENT_SLAUGHTER_SQUARE:
                {
                    events.ScheduleEvent(InstanceEvents::EVENT_SUMMON_BLACK_GUARD, 1s);
                    events.ScheduleEvent(InstanceEvents::EVENT_OPEN_DOOR_4_1, 2s);
                    events.ScheduleEvent(InstanceEvents::EVENT_BLACK_GUARD_LINE, 4s);
                    events.ScheduleEvent(InstanceEvents::EVENT_BLACK_GUARD_MOVE, 5s);
                    break;
                }
                case InstanceEvents::EVENT_SUMMON_RAMSTEIN:
                {
                    if (Creature* pBaron = instance->GetCreature(baronGUID))
                    {
                        pBaron->SummonCreature(NPC_RAMSTEIN, 4032.65f, -3385.51f, 119.75f, 4.71f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);
                        pBaron->AI()->Talk(STRATHOLME_LINE_BARON_RIVENDARE::LINE_BARON_RIVENDARE_3);
                    }
                    break;
                }
                case InstanceEvents::EVENT_OPEN_DOOR_4_0:
                {
                    if (GameObject* goGate4 = instance->GetGameObject(ziggurat4GUID))
                    {
                        goGate4->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case InstanceEvents::EVENT_RAMSTEIN_LINE:
                {
                    if (Creature* checkC = instance->GetCreature(OGBossRamstein))
                    {
                        checkC->AI()->Talk(STRATHOLME_LINE_RAMSTEIN::LINE_RAMSTEIN_0);
                    }
                    break;
                }
                case InstanceEvents::EVENT_RAMSTEIN_MOVE:
                {
                    if (Creature* checkC = instance->GetCreature(OGBossRamstein))
                    {
                        checkC->GetMotionMaster()->MovePoint(0, 4032.54f, -3421.40f, 116.57f, true, 4.7f);
                    }
                    break;
                }
                case InstanceEvents::EVENT_CLOSE_DOOR_4_0:
                {
                    if (GameObject* goGate4 = instance->GetGameObject(ziggurat4GUID))
                    {
                        goGate4->SetGoState(GOState::GO_STATE_READY);
                    }
                    break;
                }
                case InstanceEvents::EVENT_SUMMON_BLACK_GUARD:
                {
                    if (Creature* pBaron = instance->GetCreature(baronGUID))
                    {
                        if (TempSummon* tsBG = pBaron->SummonCreature(NPC_BLACK_GUARD, 4028.02f, -3379.48f, 120.0f, 4.6f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                        {
                            OGBlackGuard0 = tsBG->GetGUID();
                        }
                        if (TempSummon* tsBG = pBaron->SummonCreature(NPC_BLACK_GUARD, 4031.15f, -3379.58f, 120.0f, 4.6f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                        {
                            OGBlackGuard1 = tsBG->GetGUID();
                        }
                        if (TempSummon* tsBG = pBaron->SummonCreature(NPC_BLACK_GUARD, 4033.95f, -3379.68f, 120.0f, 4.6f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                        {
                            OGBlackGuard2 = tsBG->GetGUID();
                        }
                        if (TempSummon* tsBG = pBaron->SummonCreature(NPC_BLACK_GUARD, 4035.93f, -3378.92f, 120.0f, 4.6f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000))
                        {
                            OGBlackGuard3 = tsBG->GetGUID();
                        }
                    }
                    break;
                }
                case InstanceEvents::EVENT_OPEN_DOOR_4_1:
                {
                    if (GameObject* goGate4 = instance->GetGameObject(ziggurat4GUID))
                    {
                        goGate4->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                case InstanceEvents::EVENT_BLACK_GUARD_LINE:
                {
                    if (Creature* checkC = instance->GetCreature(OGBlackGuard0))
                    {
                        checkC->AI()->Talk(STRATHOLME_LINE_BLACK_GUARD::LINE_BLACK_GUARD_0);
                    }
                    break;
                }
                case InstanceEvents::EVENT_BLACK_GUARD_MOVE:
                {
                    if (Creature* checkC = instance->GetCreature(OGBlackGuard0))
                    {
                        checkC->GetMotionMaster()->MovePoint(0, 4026.53f, -3402.27f, 115.4f, true, 3.6f);
                    }
                    if (Creature* checkC = instance->GetCreature(OGBlackGuard1))
                    {
                        checkC->GetMotionMaster()->MovePoint(0, 4031.23f, -3403.17f, 115.4f, true, 4.6f);
                    }
                    if (Creature* checkC = instance->GetCreature(OGBlackGuard2))
                    {
                        checkC->GetMotionMaster()->MovePoint(0, 4034.80f, -3403.04f, 115.4f, true, 4.6f);
                    }
                    if (Creature* checkC = instance->GetCreature(OGBlackGuard3))
                    {
                        checkC->GetMotionMaster()->MovePoint(0, 4039.00f, -3401.15f, 115.1f, true, 5.6f);
                    }
                    break;
                }
                case InstanceEvents::EVENT_OPEN_DOOR_5:
                {
                    if (Creature* pBaron = instance->GetCreature(baronGUID))
                    {
                        pBaron->AI()->Talk(STRATHOLME_LINE_BARON_RIVENDARE::LINE_BARON_RIVENDARE_4);
                    }
                    if (GameObject* goGate5 = instance->GetGameObject(ziggurat5GUID))
                    {
                        goGate5->SetGoState(GOState::GO_STATE_ACTIVE);
                    }
                    break;
                }
                default:
                    break;
                }
            }
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const override
    {
        return new instance_stratholme_InstanceMapScript(map);
    }
};

class npc_aurius : public CreatureScript
{
public:
    npc_aurius() : CreatureScript("npc_aurius") { }

    struct npc_auriusAI : public ScriptedAI
    {
        npc_auriusAI(Creature* creature) : ScriptedAI(creature)
        {
            victory = false;
        }

        bool GossipHello(Player* player) override
        {
            if (player->GetQuestStatus(STRATHOLME_QUEST::QUEST_THE_MEDALLION_OF_FAITH) == QuestStatus::QUEST_STATUS_REWARDED)
            {
                if (victory)
                {
                    player->PrepareQuestMenu(me->GetGUID());
                    SendGossipMenuFor(player, AURIUS_GOSSIP_ID::GOSSIP_ID_2, me);
                }
                else
                {
                    SendGossipMenuFor(player, AURIUS_GOSSIP_ID::GOSSIP_ID_1, me);
                }
            }
            else
            {
                player->PrepareQuestMenu(me->GetGUID());
                SendGossipMenuFor(player, AURIUS_GOSSIP_ID::GOSSIP_ID_0, me);
            }

            return true;
        }

        void SetData(uint32 type, uint32 data) override
        {
            if (type == AURIUS_DATA_TYPE::DATA_TYPE_ENGAGE)
            {
                events.ScheduleEvent(AURIUS_EVENT::EVENT_ENGAGE, 1s);
            }
            else if (type == AURIUS_DATA_TYPE::DATA_TYPE_VICTORY)
            {
                if (me->IsAlive())
                {
                    Talk(STRATHOLME_LINE_AURIUS::LINE_AURIUS_1);
                    me->SetStandState(UnitStandStateType::UNIT_STAND_STATE_KNEEL);
                    me->SetFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_GOSSIP);
                    me->SetFlag(EUnitFields::UNIT_NPC_FLAGS, NPCFlags::UNIT_NPC_FLAG_QUESTGIVER);
                    victory = true;
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (victory)
            {
                return;
            }
            events.Update(diff);
            if (me->IsNonMeleeSpellCast(false))
            {
                return;
            }
            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case AURIUS_EVENT::EVENT_ENGAGE:
                {
                    if (Map* currentMap = me->GetMap())
                    {
                        if (Creature* pBaron = currentMap->GetCreatureBySpawnId(STRATHOLME_NPC_SPAWN_ID::NPC_SPAWN_ID_BARON_RIVENDARE))
                        {
                            if (Player* checkP = me->SelectNearestPlayer(50.0f))
                            {
                                //me->SetFaction(checkP->GetFaction());
                                Talk(STRATHOLME_LINE_AURIUS::LINE_AURIUS_0);
                                me->SetFaction(checkP->GetFaction());
                                me->GetThreatManager().AddThreat(pBaron, 100);
                                pBaron->GetThreatManager().AddThreat(me, 100);
                                AttackStart(pBaron);
                                events.ScheduleEvent(AURIUS_EVENT::EVENT_CRUSADER_STRIKE, 1s);
                                events.ScheduleEvent(AURIUS_EVENT::EVENT_EXORCISM, 3s);
                                events.ScheduleEvent(AURIUS_EVENT::EVENT_DIVINE_SHIELD, 5s);
                                events.ScheduleEvent(AURIUS_EVENT::EVENT_HOLY_LIGHT, 5s);
                            }
                        }
                    }
                    break;
                }
                case AURIUS_EVENT::EVENT_CRUSADER_STRIKE:
                {
                    if (Unit* victim = me->GetVictim())
                    {
                        DoCast(victim, STRSpellIds::SPELL_AURIUS_CRUSADER_STRIKE);
                    }
                    events.Repeat(5s);
                    break;
                }
                case AURIUS_EVENT::EVENT_EXORCISM:
                {
                    if (Unit* victim = me->GetVictim())
                    {
                        DoCast(victim, STRSpellIds::SPELL_AURIUS_EXORCISM);
                    }
                    events.Repeat(15s);
                    break;
                }
                case AURIUS_EVENT::EVENT_DIVINE_SHIELD:
                {
                    if (me->GetHealthPct() < 50.0f)
                    {
                        DoCast(me, STRSpellIds::SPELL_AURIUS_DIVINE_SHIELD);
                    }
                    else
                    {
                        events.Repeat(5s);
                    }
                    break;
                }
                case AURIUS_EVENT::EVENT_HOLY_LIGHT:
                {
                    if (me->GetHealthPct() < 50.0f)
                    {
                        DoCast(me, STRSpellIds::SPELL_AURIUS_HOLY_LIGHT);
                        events.Repeat(10s);
                        return;
                    }
                    else
                    {
                        std::list<Player*> players;
                        Trinity::AnyPlayerInObjectRangeCheck checker(me, 20.0f);
                        Trinity::PlayerListSearcher<Trinity::AnyPlayerInObjectRangeCheck> searcher(me, players, checker);
                        Cell::VisitWorldObjects(me, searcher, 20.0f);
                        for (std::list<Player*>::iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if ((*itr)->GetHealthPct() < 50.0f)
                            {
                                DoCast((*itr), STRSpellIds::SPELL_AURIUS_HOLY_LIGHT);
                                events.Repeat(10s);
                                return;
                            }
                        }
                    }
                    events.Repeat(2s);
                    break;
                }
                default:
                {
                    break;
                }
                }
                DoMeleeAttackIfReady();
            }
        }

        EventMap events;
        bool victory;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_auriusAI(creature);
    }
};

void AddSC_instance_stratholme()
{
    new instance_stratholme();
    new npc_aurius();
}
