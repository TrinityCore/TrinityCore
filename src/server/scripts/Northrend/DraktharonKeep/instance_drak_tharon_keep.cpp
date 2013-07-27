/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "InstanceScript.h"
#include "drak_tharon_keep.h"

#define MAX_ENCOUNTER     4

/* Drak'Tharon Keep encounters:
0 - Trollgore
1 - Novos
2 - King Dred
3 - Tharon Ja
*/

enum Creatures
{
    NPC_TROLLGORE                               = 26630,
    NPC_NOVOS                                   = 26631,
    NPC_KING_DRED                               = 27483,
    NPC_THARON_JA                               = 26632,
    NPC_CRYSTAL_CHANNEL_TARGET                  = 26712,
    NPC_CRYSTAL_HANDLER                         = 26627
};
enum GameObjects
{
    GO_NOVOS_CRYSTAL_1                          = 189299,
    GO_NOVOS_CRYSTAL_2                          = 189300,
    GO_NOVOS_CRYSTAL_3                          = 189301,
    GO_NOVOS_CRYSTAL_4                          = 189302
};
enum Achievements
{
    ACM_CRITERIA_OH_NOVOS                       = 7361
};

class instance_drak_tharon : public InstanceMapScript
{
public:
    instance_drak_tharon() : InstanceMapScript("instance_drak_tharon", 600) { }

    struct instance_drak_tharon_InstanceScript : public InstanceScript
    {
        instance_drak_tharon_InstanceScript(Map* map) : InstanceScript(map) {}

        uint8 dredAchievCounter;

        uint64 trollgoreGUID;
        uint64 novosGUID;
        uint64 dredGUID;
        uint64 tharonJaGUID;

        uint64 novosCrystalGUID1;
        uint64 novosCrystalGUID2;
        uint64 novosCrystalGUID3;
        uint64 novosCrystalGUID4;

        uint64 novosSummonerGUID1;
        uint64 novosSummonerGUID2;
        uint64 novosSummonerGUID3;
        uint64 novosSummonerGUID4;

        uint16 m_auiEncounter[MAX_ENCOUNTER];

        std::string str_data;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            dredAchievCounter = 0;

            trollgoreGUID = 0;
            novosGUID = 0;
            dredGUID = 0;
            tharonJaGUID = 0;

            novosCrystalGUID1 = 0;
            novosCrystalGUID2 = 0;
            novosCrystalGUID3 = 0;
            novosCrystalGUID4 = 0;

            novosSummonerGUID1 = 0;
            novosSummonerGUID2 = 0;
            novosSummonerGUID3 = 0;
            novosSummonerGUID4 = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch (go->GetEntry())
            {
                case GO_NOVOS_CRYSTAL_1:
                    novosCrystalGUID1 = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_NOVOS_CRYSTAL_2:
                    novosCrystalGUID2 = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_NOVOS_CRYSTAL_3:
                    novosCrystalGUID3 = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
                case GO_NOVOS_CRYSTAL_4:
                    novosCrystalGUID4 = go->GetGUID();
                    go->SetGoState(GO_STATE_READY);
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch (creature->GetEntry())
            {
                case NPC_TROLLGORE:
                    trollgoreGUID = creature->GetGUID();
                    break;
                case NPC_NOVOS:
                    novosGUID = creature->GetGUID();
                    break;
                case NPC_KING_DRED:
                    dredGUID = creature->GetGUID();
                    break;
                case NPC_THARON_JA:
                    tharonJaGUID = creature->GetGUID();
                    break;
                case NPC_CRYSTAL_CHANNEL_TARGET:
                    InitializeNovosSummoner(creature);
                    break;
            }
        }

        void InitializeNovosSummoner(Creature* creature)
        {
            float x = creature->GetPositionX();
            float y = creature->GetPositionY();
            float z = creature->GetPositionZ();

            if (x < -374.0f && x > -379.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                novosSummonerGUID1 = creature->GetGUID();
            else if (x < -379.0f && x > -385.0f && y > -820.0f && y < -815.0f && z < 60.0f && z > 58.0f)
                novosSummonerGUID2 = creature->GetGUID();
            else if (x < -374.0f && x > -385.0f && y > -827.0f && y < -820.0f && z < 60.0f && z > 58.0f)
                novosSummonerGUID3 = creature->GetGUID();
            else if (x < -338.0f && x > -344.0f && y > -727.0f && y < 721.0f && z < 30.0f && z > 26.0f)
                novosSummonerGUID4 = creature->GetGUID();
        }

        uint64 GetData64(uint32 identifier) const OVERRIDE
        {
            switch (identifier)
            {
                case DATA_TROLLGORE:          return trollgoreGUID;
                case DATA_NOVOS:              return novosGUID;
                case DATA_DRED:               return dredGUID;
                case DATA_THARON_JA:          return tharonJaGUID;
                case DATA_NOVOS_CRYSTAL_1:    return novosCrystalGUID1;
                case DATA_NOVOS_CRYSTAL_2:    return novosCrystalGUID2;
                case DATA_NOVOS_CRYSTAL_3:    return novosCrystalGUID3;
                case DATA_NOVOS_CRYSTAL_4:    return novosCrystalGUID4;
                case DATA_NOVOS_SUMMONER_1:   return novosSummonerGUID1;
                case DATA_NOVOS_SUMMONER_2:   return novosSummonerGUID2;
                case DATA_NOVOS_SUMMONER_3:   return novosSummonerGUID3;
                case DATA_NOVOS_SUMMONER_4:   return novosSummonerGUID4;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data) OVERRIDE
        {
            switch (type)
            {
                case DATA_TROLLGORE_EVENT:
                    m_auiEncounter[0] = data;
                    break;
                case DATA_NOVOS_EVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_DRED_EVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_THARON_JA_EVENT:
                    m_auiEncounter[3] = data;
                    break;

                case DATA_KING_DRED_ACHIEV:
                    dredAchievCounter = data;
                    break;
            }

            if (data == DONE)
            {
                SaveToDB();
            }
        }

        uint32 GetData(uint32 type) const OVERRIDE
        {
            switch (type)
            {
                case DATA_TROLLGORE_EVENT:    return m_auiEncounter[0];
                case DATA_NOVOS_EVENT:        return m_auiEncounter[1];
                case DATA_DRED_EVENT:         return m_auiEncounter[2];
                case DATA_THARON_JA_EVENT:    return m_auiEncounter[3];
                case DATA_KING_DRED_ACHIEV:   return dredAchievCounter;
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << "D K " << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' '
                << m_auiEncounter[2] << ' ' << m_auiEncounter[3];

            OUT_SAVE_INST_DATA_COMPLETE;
            return saveStream.str();
        }

        void OnUnitDeath(Unit* unit)
        {
            if (unit->GetEntry() == NPC_CRYSTAL_HANDLER)
                if (novosGUID)
                    if (Creature* novos = instance->GetCreature(novosGUID))
                        novos->AI()->DoAction(ACTION_CRYSTAL_HANDLER_DIED);
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);

            char dataHead1, dataHead2;
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'D' && dataHead2 == 'K')
            {
                m_auiEncounter[0] = data0;
                m_auiEncounter[1] = data1;
                m_auiEncounter[2] = data2;
                m_auiEncounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        m_auiEncounter[i] = NOT_STARTED;
            } else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

    InstanceScript* GetInstanceScript(InstanceMap* map) const OVERRIDE
    {
        return new instance_drak_tharon_InstanceScript(map);
    }
};

void AddSC_instance_drak_tharon()
{
    new instance_drak_tharon;
}
