/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Instance_Gruuls_Lair
SD%Complete: 100
SDComment:
SDCategory: Gruul's Lair
EndScriptData */

#include "ScriptPCH.h"
#include "gruuls_lair.h"

#define MAX_ENCOUNTER 2

/* Gruuls Lair encounters:
1 - High King Maulgar event
2 - Gruul event
*/
class instance_gruuls_lair : public InstanceMapScript
{
public:
    instance_gruuls_lair() : InstanceMapScript("instance_gruuls_lair") { }

    InstanceScript* GetInstanceData_InstanceMapScript(Map* pMap)
    {
        return new instance_gruuls_lair_InstanceMapScript(pMap);
    }

    struct instance_gruuls_lair_InstanceMapScript : public InstanceScript
    {
        instance_gruuls_lair_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {Initialize();};

        uint32 m_auiEncounter[MAX_ENCOUNTER];

        uint64 MaulgarEvent_Tank;
        uint64 KigglerTheCrazed;
        uint64 BlindeyeTheSeer;
        uint64 OlmTheSummoner;
        uint64 KroshFirehand;
        uint64 Maulgar;

        uint64 MaulgarDoor;
        uint64 GruulDoor;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            MaulgarEvent_Tank = 0;
            KigglerTheCrazed = 0;
            BlindeyeTheSeer = 0;
            OlmTheSummoner = 0;
            KroshFirehand = 0;
            Maulgar = 0;

            MaulgarDoor = 0;
            GruulDoor = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS) return true;

            return false;
        }

        void OnCreatureCreate(Creature* pCreature, bool /*add*/)
        {
            switch(pCreature->GetEntry())
            {
                case 18835: KigglerTheCrazed = pCreature->GetGUID(); break;
                case 18836: BlindeyeTheSeer = pCreature->GetGUID();  break;
                case 18834: OlmTheSummoner = pCreature->GetGUID();   break;
                case 18832: KroshFirehand = pCreature->GetGUID();    break;
                case 18831: Maulgar = pCreature->GetGUID();          break;
            }
        }

        void OnGameObjectCreate(GameObject* pGo, bool /*add*/)
        {
            switch(pGo->GetEntry())
            {
                case 184468:
                    MaulgarDoor = pGo->GetGUID();
                    if (m_auiEncounter[0] == DONE) HandleGameObject(NULL, true, pGo);
                    break;
                case 184662: GruulDoor = pGo->GetGUID(); break;
            }
        }

        void SetData64(uint32 type, uint64 data)
        {
            if (type == DATA_MAULGAREVENT_TANK)
                MaulgarEvent_Tank = data;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_MAULGAREVENT_TANK:    return MaulgarEvent_Tank;
                case DATA_KIGGLERTHECRAZED:     return KigglerTheCrazed;
                case DATA_BLINDEYETHESEER:      return BlindeyeTheSeer;
                case DATA_OLMTHESUMMONER:       return OlmTheSummoner;
                case DATA_KROSHFIREHAND:        return KroshFirehand;
                case DATA_MAULGARDOOR:          return MaulgarDoor;
                case DATA_GRUULDOOR:            return GruulDoor;
                case DATA_MAULGAR:              return Maulgar;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_MAULGAREVENT:
                    if (data == DONE) HandleGameObject(MaulgarDoor, true);
                    m_auiEncounter[0] = data; break;
                case DATA_GRUULEVENT:
                    if (data == IN_PROGRESS) HandleGameObject(GruulDoor, false);
                    else HandleGameObject(GruulDoor, true);
                    m_auiEncounter[1] = data; break;
            }

            if (data == DONE)
                SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_MAULGAREVENT: return m_auiEncounter[0];
                case DATA_GRUULEVENT:   return m_auiEncounter[1];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;
            std::ostringstream stream;
            stream << m_auiEncounter[0] << " " << m_auiEncounter[1];
            char* out = new char[stream.str().length() + 1];
            strcpy(out, stream.str().c_str());
            if (out)
            {
                OUT_SAVE_INST_DATA_COMPLETE;
                return out;
            }

            return NULL;
        }

        void Load(const char* in)
        {
            if (!in)
            {
                OUT_LOAD_INST_DATA_FAIL;
                return;
            }

            OUT_LOAD_INST_DATA(in);
            std::istringstream stream(in);
            stream >> m_auiEncounter[0] >> m_auiEncounter[1];
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                    m_auiEncounter[i] = NOT_STARTED;
            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};


void AddSC_instance_gruuls_lair()
{
    new instance_gruuls_lair();
}
