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
SDName: Instance_The_Eye
SD%Complete: 100
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "the_eye.h"

#define MAX_ENCOUNTER 5

/* The Eye encounters:
0 - Kael'thas event
1 - Al' ar event
2 - Solarian Event
3 - Void Reaver event
*/

class instance_the_eye : public InstanceMapScript
{
    public:
        instance_the_eye()
            : InstanceMapScript("instance_the_eye", 550)
        {
        }

        struct instance_the_eye_InstanceMapScript : public InstanceScript
        {
            instance_the_eye_InstanceMapScript(Map* map) : InstanceScript(map) {}

            uint64 ThaladredTheDarkener;
            uint64 LordSanguinar;
            uint64 GrandAstromancerCapernian;
            uint64 MasterEngineerTelonicus;
            uint64 Kaelthas;
            uint64 Astromancer;
            uint64 Alar;
            uint8 KaelthasEventPhase;
            uint8 AlarEventPhase;

            uint32 m_auiEncounter[MAX_ENCOUNTER];

            void Initialize()
            {
                memset(&m_auiEncounter, 0, sizeof(m_auiEncounter));

                ThaladredTheDarkener = 0;
                LordSanguinar = 0;
                GrandAstromancerCapernian = 0;
                MasterEngineerTelonicus = 0;
                Kaelthas = 0;
                Astromancer = 0;
                Alar = 0;

                KaelthasEventPhase = 0;
                AlarEventPhase = 0;
            }

            bool IsEncounterInProgress() const
            {
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)
                        return true;

                return false;
            }

            void OnCreatureCreate(Creature* creature)
            {
                switch (creature->GetEntry())
                {
                case 20064:
                    ThaladredTheDarkener = creature->GetGUID();
                    break;
                case 20063:
                    MasterEngineerTelonicus = creature->GetGUID();
                    break;
                case 20062:
                    GrandAstromancerCapernian = creature->GetGUID();
                    break;
                case 20060:
                    LordSanguinar = creature->GetGUID();
                    break;
                case 19622:
                    Kaelthas = creature->GetGUID();
                    break;
                case 18805:
                    Astromancer = creature->GetGUID();
                    break;
                case 19514:
                    Alar = creature->GetGUID();
                    break;
                }
            }

            uint64 GetData64(uint32 identifier) const
            {
                switch (identifier)
                {
                case DATA_THALADREDTHEDARKENER:         return ThaladredTheDarkener;
                case DATA_LORDSANGUINAR:                return LordSanguinar;
                case DATA_GRANDASTROMANCERCAPERNIAN:    return GrandAstromancerCapernian;
                case DATA_MASTERENGINEERTELONICUS:      return MasterEngineerTelonicus;
                case DATA_KAELTHAS:                     return Kaelthas;
                case DATA_ASTROMANCER:                  return Astromancer;
                case DATA_ALAR:                         return Alar;
                }
                return 0;
            }

            void SetData(uint32 type, uint32 data)
            {
                switch (type)
                {
                case DATA_ALAREVENT:
                    AlarEventPhase = data;
                    m_auiEncounter[0] = data;
                    break;
                case DATA_HIGHASTROMANCERSOLARIANEVENT:
                    m_auiEncounter[1] = data;
                    break;
                case DATA_VOIDREAVEREVENT:
                    m_auiEncounter[2] = data;
                    break;
                case DATA_KAELTHASEVENT:
                    KaelthasEventPhase = data;
                    m_auiEncounter[3] = data;
                    break;
                }
                if (data == DONE)
                    SaveToDB();
            }

            uint32 GetData(uint32 type) const
            {
                switch (type)
                {
                case DATA_ALAREVENT:                        return AlarEventPhase;
                case DATA_HIGHASTROMANCERSOLARIANEVENT:     return m_auiEncounter[1];
                case DATA_VOIDREAVEREVENT:                  return m_auiEncounter[2];
                case DATA_KAELTHASEVENT:                    return KaelthasEventPhase;
                }
                return 0;
            }

            std::string GetSaveData()
            {
                OUT_SAVE_INST_DATA;

                std::ostringstream stream;
                stream << m_auiEncounter[0] << ' ' << m_auiEncounter[1] << ' ' << m_auiEncounter[2] << ' ' << m_auiEncounter[3];

                OUT_SAVE_INST_DATA_COMPLETE;
                return stream.str();
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
                stream >> m_auiEncounter[0] >> m_auiEncounter[1] >> m_auiEncounter[2] >> m_auiEncounter[3];
                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (m_auiEncounter[i] == IN_PROGRESS)                // Do not load an encounter as "In Progress" - reset it instead.
                        m_auiEncounter[i] = NOT_STARTED;
                OUT_LOAD_INST_DATA_COMPLETE;
            }
        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const
        {
            return new instance_the_eye_InstanceMapScript(map);
        }
};
void AddSC_instance_the_eye()
{
    new instance_the_eye;
}

