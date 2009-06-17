/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
* This program is free software; you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation; either version 2 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
*/

/* ScriptData
SDName: instance_stratholme
SD%Complete: 50
SDComment: In progress. Undead side 75% implemented. Save/load not implemented.
SDCategory: Stratholme
EndScriptData */

#include "precompiled.h"
#include "def_stratholme.h"

#define GO_SERVICE_ENTRANCE     175368
#define GO_GAUNTLET_GATE1       175357
#define GO_ZIGGURAT1            175380                      //baroness
#define GO_ZIGGURAT2            175379                      //nerub'enkan
#define GO_ZIGGURAT3            175381                      //maleki
#define GO_ZIGGURAT4            175405                      //rammstein
#define GO_ZIGGURAT5            175796                      //baron
#define GO_PORT_GAUNTLET        175374                      //port from gauntlet to slaugther
#define GO_PORT_SLAUGTHER       175373                      //port at slaugther
#define GO_PORT_ELDERS          175377                      //port at elders square

#define C_CRYSTAL               10415                       //three ziggurat crystals
#define C_BARON                 10440
#define C_YSIDA_TRIGGER         16100

#define C_RAMSTEIN              10439
#define C_ABOM_BILE             10416
#define C_ABOM_VENOM            10417
#define C_BLACK_GUARD           10394
#define C_YSIDA                 16031

#define ENCOUNTERS              6

struct TRINITY_DLL_DECL instance_stratholme : public ScriptedInstance
{
    instance_stratholme(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];

    bool IsSilverHandDead[5];

    uint32 BaronRun_Timer;
    uint32 SlaugtherSquare_Timer;

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

    void Initialize()
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;

        for(uint8 i = 0; i < 5; i++)
            IsSilverHandDead[5] = false;

        BaronRun_Timer = 0;
        SlaugtherSquare_Timer = 0;

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
        if (Encounter[1] == IN_PROGRESS && Encounter[2] == IN_PROGRESS && Encounter[3] == IN_PROGRESS)
        {
            UpdateGoState(portGauntletGUID,0,false);
            UpdateGoState(portSlaugtherGUID,0,false);
            return true;
        }

        debug_log("TSCR: Instance Stratholme: Cannot open slaugther square yet.");
        return false;
    }

    //if withRestoreTime true, then newState will be ignored and GO should be restored to original state after 10 seconds
    void UpdateGoState(uint64 goGuid, uint32 newState, bool withRestoreTime)
    {
        if (!goGuid)
            return;

        if (GameObject *go = instance->GetGameObject(goGuid))
        {
            if (withRestoreTime)
                go->UseDoorOrButton(10);
            else
                go->SetGoState((GOState)newState);
        }
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
        case C_BARON:           baronGUID = creature->GetGUID(); break;
        case C_YSIDA_TRIGGER:   ysidaTriggerGUID = creature->GetGUID(); break;
        case C_CRYSTAL:         crystalsGUID.insert(creature->GetGUID()); break;
        case C_ABOM_BILE:
        case C_ABOM_VENOM:      abomnationGUID.insert(creature->GetGUID()); break;
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        switch(go->GetEntry())
        {
        case GO_SERVICE_ENTRANCE:   serviceEntranceGUID = go->GetGUID(); break;
        case GO_GAUNTLET_GATE1:
            //weird, but unless flag is set, client will not respond as expected. DB bug?
            go->SetFlag(GAMEOBJECT_FLAGS,GO_FLAG_LOCKED);
            gauntletGate1GUID = go->GetGUID();
            break;
        case GO_ZIGGURAT1:          ziggurat1GUID = go->GetGUID(); break;
        case GO_ZIGGURAT2:          ziggurat2GUID = go->GetGUID(); break;
        case GO_ZIGGURAT3:          ziggurat3GUID = go->GetGUID(); break;
        case GO_ZIGGURAT4:          ziggurat4GUID = go->GetGUID(); break;
        case GO_ZIGGURAT5:          ziggurat5GUID = go->GetGUID(); break;
        case GO_PORT_GAUNTLET:      portGauntletGUID = go->GetGUID(); break;
        case GO_PORT_SLAUGTHER:     portSlaugtherGUID = go->GetGUID(); break;
        case GO_PORT_ELDERS:        portElderGUID = go->GetGUID(); break;
        }
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case TYPE_BARON_RUN:
            switch(data)
            {
            case IN_PROGRESS:
                if (Encounter[0] == IN_PROGRESS || Encounter[0] == FAIL)
                    break;
                BaronRun_Timer = 2700000;
                debug_log("TSCR: Instance Stratholme: Baron run in progress.");
                break;
            case FAIL:
                //may add code to remove aura from players, but in theory the time should be up already and removed.
                break;
            case DONE:
                if (Creature* pYsidaT = instance->GetCreature(ysidaTriggerGUID))
                    pYsidaT->SummonCreature(C_YSIDA,
                    pYsidaT->GetPositionX(),pYsidaT->GetPositionY(),pYsidaT->GetPositionZ(),pYsidaT->GetOrientation(),
                    TEMPSUMMON_TIMED_DESPAWN,1800000);
                BaronRun_Timer = 0;
                break;
            }
            Encounter[0] = data;
            break;
        case TYPE_BARONESS:
            Encounter[1] = data;
            if (data == IN_PROGRESS)
                UpdateGoState(ziggurat1GUID,0,false);
            if (data == IN_PROGRESS)                    //change to DONE when crystals implemented
                StartSlaugtherSquare();
            break;
        case TYPE_NERUB:
            Encounter[2] = data;
            if (data == IN_PROGRESS)
                UpdateGoState(ziggurat2GUID,0,false);
            if (data == IN_PROGRESS)                    //change to DONE when crystals implemented
                StartSlaugtherSquare();
            break;
        case TYPE_PALLID:
            Encounter[3] = data;
            if (data == IN_PROGRESS)
                UpdateGoState(ziggurat3GUID,0,false);
            if (data == IN_PROGRESS)                    //change to DONE when crystals implemented
                StartSlaugtherSquare();
            break;
        case TYPE_RAMSTEIN:
            if (data == IN_PROGRESS)
            {
                if (Encounter[4] != IN_PROGRESS)
                    UpdateGoState(portGauntletGUID,1,false);

                uint32 count = abomnationGUID.size();
                for(std::set<uint64>::iterator i = abomnationGUID.begin(); i != abomnationGUID.end(); ++i)
                {
                    if (Creature* pAbom = instance->GetCreature(*i))
                    {
                        if (!pAbom->isAlive())
                            --count;
                    }
                }

                if (!count)
                {
                    //a bit itchy, it should close the door after 10 secs, but it doesn't. skipping it for now.
                    //UpdateGoState(ziggurat4GUID,0,true);
                    if (Creature* pBaron = instance->GetCreature(baronGUID))
                        pBaron->SummonCreature(C_RAMSTEIN,4032.84,-3390.24,119.73,4.71,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,1800000);
                    debug_log("TSCR: Instance Stratholme: Ramstein spawned.");
                }
                else
                    debug_log("TSCR: Instance Stratholme: %u Abomnation left to kill.",count);
            }
            if (data == DONE)
            {
                SlaugtherSquare_Timer = 300000;
                debug_log("TSCR: Instance Stratholme: Slaugther event will continue in 5 minutes.");
            }
            Encounter[4] = data;
            break;
        case TYPE_BARON:
            if (data == IN_PROGRESS)
            {
                if (GetData(TYPE_BARON_RUN) == IN_PROGRESS)
                {
                    Map::PlayerList const& players = instance->GetPlayers();

                    if (!players.isEmpty())
                    {
                        for(Map::PlayerList::const_iterator itr = players.begin(); itr != players.end(); ++itr)
                        {
                            if (Player* pPlayer = itr->getSource())
                            {
                                if (pPlayer->HasAura(SPELL_BARON_ULTIMATUM))
                                    pPlayer->RemoveAurasDueToSpell(SPELL_BARON_ULTIMATUM);

                                if (pPlayer->GetQuestStatus(QUEST_DEAD_MAN_PLEA) == QUEST_STATUS_INCOMPLETE)
                                    pPlayer->AreaExploredOrEventHappens(QUEST_DEAD_MAN_PLEA);
                            }
                        }
                    }

                    SetData(TYPE_BARON_RUN,DONE);
                }
            }
            Encounter[5] = data;
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
    }

    uint32 GetData(uint32 type)
    {
          switch(type)
          {
          case TYPE_SH_QUEST:
              if(IsSilverHandDead[0] && IsSilverHandDead[1] && IsSilverHandDead[2] && IsSilverHandDead[3] && IsSilverHandDead[4])
                  return 1;
              return 0;
          case TYPE_BARON_RUN:
              return Encounter[0];
          case TYPE_BARONESS:
              return Encounter[1];
          case TYPE_NERUB:
              return Encounter[2];
          case TYPE_PALLID:
              return Encounter[3];
          case TYPE_RAMSTEIN:
              return Encounter[4];
          case TYPE_BARON:
              return Encounter[5];
          }
          return 0;
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
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
        if (BaronRun_Timer)
        {
            if (BaronRun_Timer <= diff)
            {
                if (GetData(TYPE_BARON_RUN) != DONE)
                    SetData(TYPE_BARON_RUN, FAIL);
                BaronRun_Timer = 0;
                debug_log("TSCR: Instance Stratholme: Baron run event reached end. Event has state %u.",GetData(TYPE_BARON_RUN));
            }else BaronRun_Timer -= diff;
        }

        if (SlaugtherSquare_Timer)
        {
            if (SlaugtherSquare_Timer <= diff)
            {
                if (Creature* pBaron = instance->GetCreature(baronGUID))
                {
                    for(uint8 i = 0; i < 4; i++)
                        pBaron->SummonCreature(C_BLACK_GUARD,4032.84,-3390.24,119.73,4.71,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,1800000);

                    UpdateGoState(ziggurat4GUID,0,false);
                    UpdateGoState(ziggurat5GUID,0,false);
                    debug_log("TSCR: Instance Stratholme: Black guard sentries spawned. Opening gates to baron.");
                }
                SlaugtherSquare_Timer = 0;
            }else SlaugtherSquare_Timer -= diff;
        }
    }
};

InstanceData* GetInstanceData_instance_stratholme(Map* map)
{
    return new instance_stratholme(map);
}

void AddSC_instance_stratholme()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_stratholme";
    newscript->GetInstanceData = &GetInstanceData_instance_stratholme;
    newscript->RegisterSelf();
}

