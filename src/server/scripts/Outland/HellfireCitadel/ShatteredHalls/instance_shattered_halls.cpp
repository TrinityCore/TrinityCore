/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Shattered_Halls
SD%Complete: 50
SDComment: currently missing info about door. instance not complete
SDCategory: Hellfire Citadel, Shattered Halls
EndScriptData */

#include "ScriptPCH.h"
#include "shattered_halls.h"

#define MAX_ENCOUNTER  2

#define DOOR_NETHEKURSE_ENTRANCE     182539
#define DOOR_NETHEKURSE_EXIT         182540

class instance_shattered_halls : public InstanceMapScript
{
public:
    instance_shattered_halls() : InstanceMapScript("instance_shattered_halls", 540) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_shattered_halls_InstanceMapScript(pMap);
    }

    struct instance_shattered_halls_InstanceMapScript : public InstanceScript
    {
            instance_shattered_halls_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint64 nethekurseGUID;
        uint64 nethekurseDoorGUID;
        uint64 nethekurseDoor2GUID;
        bool nethekurskilled;

        uint32 timer_state;
        uint32 timer_tick;
        uint32 execution_phase; // 0 1 2 3
        uint32 execution_timer;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            nethekurseGUID = 0;
            nethekurseDoorGUID = 0;

            nethekurskilled = 1;

            execution_phase = 3;
            timer_tick = 0;
            timer_state = TIMER_NOTSTARTED;
            execution_timer = 0;
        }

        void OnGameObjectCreate(GameObject* pGo)
        {
            switch( pGo->GetEntry() )
            {
                case DOOR_NETHEKURSE_ENTRANCE: 
                    nethekurseDoorGUID = pGo->GetGUID();
                    pGo->SetGoState((GOState)nethekurskilled);
                    break;
                case DOOR_NETHEKURSE_EXIT: 
                    nethekurseDoor2GUID = pGo->GetGUID();
                    pGo->SetGoState((GOState)nethekurskilled);
                    break;
            }
        }

        void OnCreatureCreate(Creature* pCreature)
        {
            switch(pCreature->GetEntry())
            {
                case 16807: 
                    nethekurseGUID = pCreature->GetGUID();
                    break;
            }
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case TYPE_NETHEKURSE:
                    m_auiEncounter[0] = data;
                    if(data == DONE)
                    {
                        nethekurskilled = 0;
                        HandleGameObject(nethekurseDoor2GUID,nethekurskilled == 0 ? true : false);
                        HandleGameObject(nethekurseDoorGUID,nethekurskilled == 0 ? true : false);
                        SetData(EXECUTION_PHASE,3);
                    }
                    break;
                case TYPE_OMROGG:
                    m_auiEncounter[1] = data;
                    break;
                //case TIMER_STATE:
                //    timer_state = data;
                //    break;
                case EXECUTION_PHASE:
                    if(timer_state == TIMER_ENDED)
                        return;

                    execution_phase = data;

                    switch(execution_phase)
                    {
                    case 3:
                        execution_timer = 55;
                        timer_tick = 60000;
                        timer_state = TIMER_STARTED;
                        break;
                    case 2:
                        execution_timer = 10;
                        timer_tick = 60000;
                        timer_state = TIMER_STARTED;
                        break;
                    case 1:
                        execution_timer = 15;
                        timer_tick = 60000;
                        timer_state = TIMER_STARTED;
                        break;
                    case 0:
                        execution_timer = 0;
                        timer_state = TIMER_ENDED;
                        break;
                    }
                    break;
            }

            SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case TYPE_NETHEKURSE:
                    return m_auiEncounter[0];
                case TYPE_OMROGG:
                    return m_auiEncounter[1];
                case TIMER_STATE:
                    return timer_state;
                case EXECUTION_PHASE:
                    return execution_phase;
            }
            return 0;
        }

        uint64 GetData64(uint32 data)
        {
            switch(data)
            {
                case DATA_NETHEKURSE:
                    return nethekurseGUID;
                case DATA_NETHEKURSE_DOOR_ENTRANCE:
                    return nethekurseDoorGUID;
                case DATA_NETHEKURSE_DOOR_EXIT:
                    return nethekurseDoor2GUID;
            }
            return 0;
        }

        void Update(uint32 diff)
        {
            if( timer_state == TIMER_STARTED)
            {
                if(execution_timer)
                {
                    if(timer_tick <= diff)
                    {
                        execution_timer--;
                        timer_tick = 60000;

                        if(execution_timer <= 0)
                        {
                            if(execution_phase > 0)
                                timer_state = TIMER_NEXTPHASE;
                            else
                                timer_state = TIMER_ENDED;
                        }

                        SaveToDB();
                    }
                    timer_tick -= diff;
                }
            }
        }

        std::string GetSaveData()
        {
            std::ostringstream ss;
            ss << "S H " << nethekurskilled << " " << timer_state << " " << execution_timer << " " << execution_phase;
            std::string data = ss.str();

            return data.c_str();
        }

        void Load(const char* load)
        {
            if(!load) return;
            std::istringstream ss(load);
            char dataHead1, dataHead2; // S H
            uint32 data1,data2,data3,data4;
            ss >> dataHead1 >> dataHead2 >> data1 >> data2 >> data3 >> data4;
            if(dataHead1 == 'S' && dataHead2 == 'H')
            {
                nethekurskilled = data1;
                timer_state = data2;
                execution_timer = data3;
                execution_phase = data4;

            }else sLog->outError("Shattered Halls: corrupted save data.");
        }
    };
};

void AddSC_instance_shattered_halls()
{
    new instance_shattered_halls();

}

