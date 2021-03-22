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
#include "EventMap.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Log.h"
#include "Map.h"
#include "Player.h"
#include "stratholme.h"
#include <sstream>

enum InstanceEvents
{
    EVENT_BARON_RUN         = 1,
    EVENT_SLAUGHTER_SQUARE  = 2
};

Position const timmyTheCruelSpawnPosition = { 3625.358f, -3188.108f, 130.3985f, 4.834562f };
EllipseBoundary const beforeScarletGate(Position(3671.158f, -3181.79f), 60.0f, 40.0f);

class instance_stratholme : public InstanceMapScript
{
    public:
        instance_stratholme() : InstanceMapScript(StratholmeScriptName, 329) { }

        struct instance_stratholme_InstanceMapScript : public InstanceScript
        {
            instance_stratholme_InstanceMapScript(InstanceMap* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    EncounterState[i] = NOT_STARTED;

                for (uint8 i = 0; i < 5; ++i)
                    IsSilverHandDead[i] = false;

                timmySpawned = false;
                scarletsKilled = 0;
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

            ObjectGuid baronGUID;
            ObjectGuid ysidaTriggerGUID;
            GuidSet crystalsGUID;
            GuidSet abomnationGUID;
            EventMap events;

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
                }
            }

            bool StartSlaugtherSquare()
            {
                //change to DONE when crystals implemented
                if (EncounterState[1] == IN_PROGRESS && EncounterState[2] == IN_PROGRESS && EncounterState[3] == IN_PROGRESS)
                {
                    HandleGameObject(portGauntletGUID, true);
                    HandleGameObject(portSlaugtherGUID, true);
                    return true;
                }

                TC_LOG_DEBUG("scripts", "Instance Stratholme: Cannot open slaugther square yet.");
                return false;
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
                        crystalsGUID.insert(creature->GetGUID());
                        break;
                    case NPC_ABOM_BILE:
                    case NPC_ABOM_VENOM:
                        abomnationGUID.insert(creature->GetGUID());
                        break;
                }
            }

            void OnCreatureRemove(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case NPC_CRYSTAL:
                        crystalsGUID.erase(creature->GetGUID());
                        break;
                    case NPC_ABOM_BILE:
                    case NPC_ABOM_VENOM:
                        abomnationGUID.erase(creature->GetGUID());
                        break;
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
                        go->AddFlag(GO_FLAG_LOCKED);
                        gauntletGate1GUID = go->GetGUID();
                        break;
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
                                EncounterState[0] = data;
                                break;
                            case DONE:
                                EncounterState[0] = data;
                                if (Creature* ysidaTrigger = instance->GetCreature(ysidaTriggerGUID))
                                {
                                    Position ysidaPos = ysidaTrigger->GetPosition();
                                    ysidaTrigger->SummonCreature(NPC_YSIDA, ysidaPos, TEMPSUMMON_TIMED_DESPAWN, 1800000);
                                }
                                events.CancelEvent(EVENT_BARON_RUN);
                                break;
                        }
                        break;
                    case TYPE_BARONESS:
                        EncounterState[1] = data;
                        if (data == IN_PROGRESS)
                        {
                            HandleGameObject(ziggurat1GUID, true);
                            //change to DONE when crystals implemented
                            StartSlaugtherSquare();
                        }
                        break;
                    case TYPE_NERUB:
                        EncounterState[2] = data;
                        if (data == IN_PROGRESS)
                        {
                            HandleGameObject(ziggurat2GUID, true);
                            //change to DONE when crystals implemented
                            StartSlaugtherSquare();
                        }
                        break;
                    case TYPE_PALLID:
                        EncounterState[3] = data;
                        if (data == IN_PROGRESS)
                        {
                            HandleGameObject(ziggurat3GUID, true);
                            //change to DONE when crystals implemented
                            StartSlaugtherSquare();
                        }
                        break;
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
                                //a bit itchy, it should close the door after 10 secs, but it doesn't. skipping it for now.
                                //UpdateGoState(ziggurat4GUID, 0, true);
                                if (Creature* pBaron = instance->GetCreature(baronGUID))
                                    pBaron->SummonCreature(NPC_RAMSTEIN, 4032.84f, -3390.24f, 119.73f, 4.71f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);
                                TC_LOG_DEBUG("scripts", "Instance Stratholme: Ramstein spawned.");
                            }
                            else
                                TC_LOG_DEBUG("scripts", "Instance Stratholme: %u Abomnation left to kill.", count);
                        }

                        if (data == NOT_STARTED)
                            HandleGameObject(portGauntletGUID, true);

                        if (data == DONE)
                        {
                            events.ScheduleEvent(EVENT_SLAUGHTER_SQUARE, 60000);
                            TC_LOG_DEBUG("scripts", "Instance Stratholme: Slaugther event will continue in 1 minute.");
                        }
                        EncounterState[4] = data;
                        break;
                    case TYPE_BARON:
                        if (data == IN_PROGRESS)
                        {
                            HandleGameObject(ziggurat4GUID, false);
                            HandleGameObject(ziggurat5GUID, false);
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
                            {
                                DoRemoveAurasDueToSpellOnPlayers(SPELL_BARON_ULTIMATUM);
                                Map::PlayerList const& players = instance->GetPlayers();
                                if (!players.isEmpty())
                                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                        if (Player* player = itr->GetSource())
                                            if (player->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE)
                                            {
                                                player->AreaExploredOrEventHappens(QUEST_DEAD_MAN_PLEA);
                                                player->KilledMonsterCredit(NPC_YSIDA);
                                            }
                                SetData(TYPE_BARON_RUN, DONE);
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
                }
                return ObjectGuid::Empty;
            }

            void Update(uint32 diff) override
            {
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
                            if (Creature* baron = instance->GetCreature(baronGUID))
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                    baron->SummonCreature(NPC_BLACK_GUARD, 4032.84f, -3390.24f, 119.73f, 4.71f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);

                                HandleGameObject(ziggurat4GUID, true);
                                HandleGameObject(ziggurat5GUID, true);
                                TC_LOG_DEBUG("scripts", "Instance Stratholme: Black guard sentries spawned. Opening gates to baron.");
                            }
                            break;
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

void AddSC_instance_stratholme()
{
    new instance_stratholme();
}
