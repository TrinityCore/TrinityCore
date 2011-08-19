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
SDName: Instance_Magisters_Terrace
SD%Complete: 60
SDComment:  Designed only for Selin Fireheart
SDCategory: Magister's Terrace
EndScriptData */

#include "ScriptPCH.h"
#include "magisters_terrace.h"

#define MAX_ENCOUNTER      4

/*
0  - Selin Fireheart
1  - Vexallus
2  - Priestess Delrissa
3  - Kael'thas Sunstrider
*/

class instance_magisters_terrace : public InstanceMapScript
{
public:
    instance_magisters_terrace() : InstanceMapScript("instance_magisters_terrace", 585) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_magisters_terrace_InstanceMapScript(pMap);
    }

    struct instance_magisters_terrace_InstanceMapScript : public InstanceScript
    {
        instance_magisters_terrace_InstanceMapScript(Map* pMap) : InstanceScript(pMap) {}

        uint32 m_auiEncounter[MAX_ENCOUNTER];
        uint32 DelrissaDeathCount;

        std::list<uint64> FelCrystals;
        std::list<uint64>::const_iterator CrystalItr;

        uint64 SelinGUID;
        uint64 DelrissaGUID;
        uint64 VexallusDoorGUID;
        uint64 SelinDoorGUID;
        uint64 SelinEncounterDoorGUID;
        uint64 DelrissaDoorGUID;
        uint64 KaelDoorGUID;
        uint64 KaelStatue[2];

        bool InitializedItr;

        void Initialize()
        {
            memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

            FelCrystals.clear();

            DelrissaDeathCount = 0;

            SelinGUID = 0;
            DelrissaGUID = 0;
            VexallusDoorGUID = 0;
            SelinDoorGUID = 0;
            SelinEncounterDoorGUID = 0;
            DelrissaDoorGUID = 0;
            KaelDoorGUID = 0;
            KaelStatue[0] = 0;
            KaelStatue[1] = 0;

            InitializedItr = false;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (m_auiEncounter[i] == IN_PROGRESS)
                    return true;
            return false;
        }

        uint32 GetData(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_SELIN_EVENT:          return m_auiEncounter[0];
                case DATA_VEXALLUS_EVENT:       return m_auiEncounter[1];
                case DATA_DELRISSA_EVENT:       return m_auiEncounter[2];
                case DATA_KAELTHAS_EVENT:       return m_auiEncounter[3];
                case DATA_DELRISSA_DEATH_COUNT: return DelrissaDeathCount;
                case DATA_FEL_CRYSTAL_SIZE:     return FelCrystals.size();
            }
            return 0;
        }

        void SetData(uint32 identifier, uint32 data)
        {
            switch(identifier)
            {
                case DATA_SELIN_EVENT:       m_auiEncounter[0] = data;  break;
                case DATA_VEXALLUS_EVENT:
                    if (data == DONE)
                        DoUseDoorOrButton(VexallusDoorGUID);
                    m_auiEncounter[1] = data;
                    break;
                case DATA_DELRISSA_EVENT:
                    if (data == DONE)
                        DoUseDoorOrButton(DelrissaDoorGUID);
                    if (data == IN_PROGRESS)
                        DelrissaDeathCount = 0;
                    m_auiEncounter[2] = data;
                    break;
                case DATA_KAELTHAS_EVENT:    m_auiEncounter[3] = data;  break;

                case DATA_DELRISSA_DEATH_COUNT:
                    if (data == SPECIAL)
                        ++DelrissaDeathCount;
                    else
                        DelrissaDeathCount = 0;
                    break;
            }
        }

        void OnCreatureCreate(Creature* creature)
        {
            switch(creature->GetEntry())
            {
                case 24723: SelinGUID = creature->GetGUID(); break;
                case 24560: DelrissaGUID = creature->GetGUID(); break;
                case 24722: FelCrystals.push_back(creature->GetGUID()); break;
            }
        }

        void OnGameObjectCreate(GameObject* go)
        {
            switch(go->GetEntry())
            {
                case 187896:  VexallusDoorGUID = go->GetGUID();       break;
                //SunwellRaid Gate 02
                case 187979:  SelinDoorGUID = go->GetGUID();          break;
                //Assembly Chamber Door
                case 188065:  SelinEncounterDoorGUID = go->GetGUID(); break;
                case 187770:  DelrissaDoorGUID = go->GetGUID();       break;
                case 188064:  KaelDoorGUID = go->GetGUID();           break;
                case 188165:  KaelStatue[0] = go->GetGUID();          break;
                case 188166:  KaelStatue[1] = go->GetGUID();          break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_SELIN:                return SelinGUID;
                case DATA_DELRISSA:             return DelrissaGUID;
                case DATA_VEXALLUS_DOOR:        return VexallusDoorGUID;
                case DATA_SELIN_DOOR:           return SelinDoorGUID;
                case DATA_SELIN_ENCOUNTER_DOOR: return SelinEncounterDoorGUID;
                case DATA_DELRISSA_DOOR:        return DelrissaDoorGUID;
                case DATA_KAEL_DOOR:            return KaelDoorGUID;
                case DATA_KAEL_STATUE_LEFT:     return KaelStatue[0];
                case DATA_KAEL_STATUE_RIGHT:    return KaelStatue[1];

                case DATA_FEL_CRYSTAL:
                {
                    if (FelCrystals.empty())
                    {
                        sLog->outError("TSCR: Magisters Terrace: No Fel Crystals loaded in Inst Data");
                        return 0;
                    }

                    if (!InitializedItr)
                    {
                        CrystalItr = FelCrystals.begin();
                        InitializedItr = true;
                    }

                    uint64 guid = *CrystalItr;
                    ++CrystalItr;
                    return guid;
                }
            }
            return 0;
        }
    };

};

void AddSC_instance_magisters_terrace()
{
    new instance_magisters_terrace();
}
