/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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

/* ScriptData
SDName: instance_stratholme
SD%Complete: 50
SDComment: In progress. Undead side 75% implemented. Save/load not implemented.
SDCategory: Stratholme
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "stratholme.h"
#include "Player.h"

enum Misc
{
    MAX_ENCOUNTER           = 6
};

enum InstanceEvents
{
    EVENT_BARON_RUN         = 1,
    EVENT_SLAUGHTER_SQUARE  = 2
};

class instance_stratholme : public InstanceMapScript
{
    public:
        instance_stratholme() : InstanceMapScript("instance_stratholme", 329) { }

        struct instance_stratholme_InstanceMapScript : public InstanceScript
        {
            instance_stratholme_InstanceMapScript(Map* map) : InstanceScript(map)
            {
            }

            uint32 EncounterState[MAX_ENCOUNTER];

            bool IsSilverHandDead[5];

            uint64 serviceEntranceGUID;
            uint64 gauntletGate1GUID;
            uint64 ziggurat1GUID;
            uint64 ziggurat2GUID;
            uint64 ziggurat3GUID;
            uint64 ziggurat4GUID;
            uint64 ziggurat5GUID;
            uint64 portGauntletGUID;
            uint64 portSlaugtherGUID;
            uint64 portElderGUID;

            uint64 baronGUID;
            uint64 ysidaTriggerGUID;
            std::set<uint64> crystalsGUID;
            std::set<uint64> abomnationGUID;
            EventMap events;

            void Initialize()
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    EncounterState[i] = NOT_STARTED;

                for (uint8 i = 0; i < 5; ++i)
                    IsSilverHandDead[i] = false;

                serviceEntranceGUID = 0;
                gauntletGate1GUID = 0;
                ziggurat1GUID = 0;
                ziggurat2GUID = 0;
                ziggurat3GUID = 0;
                ziggurat4GUID = 0;
                ziggurat5GUID = 0;
                portGauntletGUID = 0;
                portSlaugtherGUID = 0;
                portElderGUID = 0;

                baronGUID = 0;
                ysidaTriggerGUID = 0;
                crystalsGUID.clear();
                abomnationGUID.clear();
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

                TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Cannot open slaugther square yet.");
                return false;
            }

            //if withRestoreTime true, then newState will be ignored and GO should be restored to original state after 10 seconds
            void UpdateGoState(uint64 goGuid, uint32 newState, bool withRestoreTime)
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

            void OnCreatureCreate(Creature* creature)
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

            void OnCreatureRemove(Creature* creature)
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

            void OnGameObjectCreate(GameObject* go)
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
                    case GO_ZIGGURAT1:
                        ziggurat1GUID = go->GetGUID();
                        if (GetData(TYPE_BARONESS) == IN_PROGRESS)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_ZIGGURAT2:
                        ziggurat2GUID = go->GetGUID();
                        if (GetData(TYPE_NERUB) == IN_PROGRESS)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_ZIGGURAT3:
                        ziggurat3GUID = go->GetGUID();
                        if (GetData(TYPE_PALLID) == IN_PROGRESS)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_ZIGGURAT4:
                        ziggurat4GUID = go->GetGUID();
                        if (GetData(TYPE_BARON) == DONE || GetData(TYPE_RAMSTEIN) == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_ZIGGURAT5:
                        ziggurat5GUID = go->GetGUID();
                        if (GetData(TYPE_BARON) == DONE || GetData(TYPE_RAMSTEIN) == DONE)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_PORT_GAUNTLET:
                        portGauntletGUID = go->GetGUID();
                        if (GetData(TYPE_BARONESS) == IN_PROGRESS && GetData(TYPE_NERUB) == IN_PROGRESS && GetData(TYPE_PALLID) == IN_PROGRESS)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_PORT_SLAUGTHER:
                        portSlaugtherGUID = go->GetGUID();
                        if (GetData(TYPE_BARONESS) == IN_PROGRESS && GetData(TYPE_NERUB) == IN_PROGRESS && GetData(TYPE_PALLID) == IN_PROGRESS)
                            HandleGameObject(0, true, go);
                        break;
                    case GO_PORT_ELDERS:
                        portElderGUID = go->GetGUID();
                        break;
                }
            }

            void SetData(uint32 type, uint32 data) OVERRIDE
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
                                TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Baron run in progress.");
                                break;
                            case FAIL:
                                DoRemoveAurasDueToSpellOnPlayers(SPELL_BARON_ULTIMATUM);
                                EncounterState[0] = data;
                                break;
                            case DONE:
                                EncounterState[0] = data;
                                if (Creature* ysidaTrigger = instance->GetCreature(ysidaTriggerGUID))
                                {
                                    Position ysidaPos;
                                    ysidaTrigger->GetPosition(&ysidaPos);
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
                            for (std::set<uint64>::const_iterator i = abomnationGUID.begin(); i != abomnationGUID.end(); ++i)
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
                                TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Ramstein spawned.");
                            }
                            else
                                TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: %u Abomnation left to kill.", count);
                        }

                        if (data == NOT_STARTED)
                            HandleGameObject(portGauntletGUID, true);

                        if (data == DONE)
                        {
                            events.ScheduleEvent(EVENT_SLAUGHTER_SQUARE, 60000);
                            TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Slaugther event will continue in 1 minute.");
                        }
                        EncounterState[4] = data;
                        break;
                    case TYPE_BARON:
                        if (data == IN_PROGRESS)
                        {
                            HandleGameObject(ziggurat4GUID, false);
                            HandleGameObject(ziggurat5GUID, false);
                            if (GetData(TYPE_BARON_RUN) == IN_PROGRESS)
                            {
                                DoRemoveAurasDueToSpellOnPlayers(SPELL_BARON_ULTIMATUM);
                                Map::PlayerList const& players = instance->GetPlayers();
                                if (!players.isEmpty())
                                    for (Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                                        if (Player* player = itr->GetSource())
                                            if (player->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE)
                                                player->AreaExploredOrEventHappens(QUEST_DEAD_MAN_PLEA);

                                SetData(TYPE_BARON_RUN, DONE);
                            }
                        }
                        if (data == DONE || data == NOT_STARTED)
                        {
                            HandleGameObject(ziggurat4GUID, true);
                            HandleGameObject(ziggurat5GUID, true);
                        }
                        if (data == DONE)
                            HandleGameObject(portGauntletGUID, true);
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

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream saveStream;
                saveStream << EncounterState[0] << ' ' << EncounterState[1] << ' ' << EncounterState[2] << ' '
                    << EncounterState[3] << ' ' << EncounterState[4] << ' ' << EncounterState[5];

                OUT_SAVE_INST_DATA_COMPLETE;
                return saveStream.str();
            }

            void Load(const char* in)
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

            uint32 GetData(uint32 type) const OVERRIDE
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

            uint64 GetData64(uint32 data) const OVERRIDE
            {
                switch (data)
                {
                    case DATA_BARON:
                        return baronGUID;
                    case DATA_YSIDA_TRIGGER:
                        return ysidaTriggerGUID;
                }
                return 0;
            }

            void Update(uint32 diff)
            {
                events.Update(diff);

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BARON_RUN:
                            if (GetData(TYPE_BARON_RUN) != DONE)
                                SetData(TYPE_BARON_RUN, FAIL);
                            TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Baron run event reached end. Event has state %u.", GetData(TYPE_BARON_RUN));
                            break;
                        case EVENT_SLAUGHTER_SQUARE:
                            if (Creature* baron = instance->GetCreature(baronGUID))
                            {
                                for (uint8 i = 0; i < 4; ++i)
                                    baron->SummonCreature(NPC_BLACK_GUARD, 4032.84f, -3390.24f, 119.73f, 4.71f, TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 1800000);

                                HandleGameObject(ziggurat4GUID, true);
                                HandleGameObject(ziggurat5GUID, true);
                                TC_LOG_DEBUG(LOG_FILTER_TSCR, "Instance Stratholme: Black guard sentries spawned. Opening gates to baron.");
                            }
                            break;
                        default:
                            break;
                    }
                }
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
        {
            return new instance_stratholme_InstanceMapScript(map);
        }
};

void AddSC_instance_stratholme()
{
    new instance_stratholme();
}
