/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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
 
#include "ScriptPCH.h"
#include "lost_city_of_the_tolvir.h"

#define ENCOUNTERS 5

/* Boss Encounters
   General Husam
   High Prophet Barim
   Lockmaw
   Augh
   Siamat
 */

class instance_lost_city_of_the_tolvir : public InstanceMapScript
{
public:
    instance_lost_city_of_the_tolvir() : InstanceMapScript("instance_lost_city_of_the_tolvir", 755) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_lost_city_of_the_tolvir_InstanceMapScript(map);
    }

    struct instance_lost_city_of_the_tolvir_InstanceMapScript: public InstanceScript
    {
        instance_lost_city_of_the_tolvir_InstanceMapScript(InstanceMap* map) : InstanceScript(map) {}

        uint32 Encounter[ENCOUNTERS];

        uint64 GeneralHusam;
        uint64 HighProphetBarim;
        uint64 Lockmaw;
        uint64 Augh;
        uint64 Siamat;
        uint64 TeamInInstance;

        void Initialize()
        {
            GeneralHusam           = 0;
            HighProphetBarim       = 0;
            Lockmaw                = 0;
            Augh                   = 0;
            Siamat                 = 0;

            for (uint8 i=0 ; i<ENCOUNTERS; ++i)
                Encounter[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i=0; i<ENCOUNTERS; ++i)
            {
                if (Encounter[i] == IN_PROGRESS)
                    return true;
            }
            return false;
        }

        void OnCreatureCreate(Creature* creature, bool )
        {
            switch (creature->GetEntry())
            {
                 case BOSS_GENERAL_HUSAM:
                     GeneralHusam = creature->GetGUID();
                     break;
                 case BOSS_HIGH_PROPHET_BARIM:
                     HighProphetBarim = creature->GetGUID();
                     break;
                 case BOSS_LOCKMAW:
                     Lockmaw = creature->GetGUID();
                     break;
                 case BOSS_AUGH:
                     Augh = creature->GetGUID();
                     break;
                 case BOSS_SIAMAT:
                     Siamat = creature->GetGUID();
                     break;
            }
        }

        uint64 getData64(uint32 identifier)
        {
            switch (identifier)
            {
                case DATA_GENERAL_HUSAM:
                    return GeneralHusam;
                case DATA_HIGH_PROPHET_BARIM:
                    return HighProphetBarim;
                case DATA_LOCKMAW:
                    return Lockmaw;
                case DATA_AUGH:
                    return Augh;
                case DATA_SIAMAT:
                    return Siamat;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_GENERAL_HUSAM_EVENT:
                    Encounter[0] = data;
                    break;
                case DATA_HIGH_PROPHET_BARIM_EVENT:
                    Encounter[1] = data;
                    break;
                case DATA_LOCKMAW_EVENT:
                    Encounter[2] = data;
                    break;
                case DATA_AUGH_EVENT:
                    Encounter[3] = data;
                    break;
                case DATA_SIAMAT_EVENT:
                    Encounter[4] = data;
                    break;
            }

           if (data == DONE)
               SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_GENERAL_HUSAM_EVENT:
                    return Encounter[0];
                case DATA_HIGH_PROPHET_BARIM_EVENT:
                    return Encounter[1];
                case DATA_LOCKMAW_EVENT:
                    return Encounter[2];
                case DATA_AUGH_EVENT:
                    return Encounter[3];
                case DATA_SIAMAT_EVENT:
                    return Encounter[4];
            }
            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;
            std::ostringstream saveStream;
            saveStream << "L V" << Encounter[0] << " " << Encounter[1]  << " " << Encounter[2]  << " " << Encounter[3] << " " << Encounter[4];
            str_data = saveStream.str();

            OUT_SAVE_INST_DATA_COMPLETE;
            return str_data;
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
            uint16 data0, data1, data2, data3, data4;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;

            if (dataHead1 == 'L' && dataHead2 == 'V')
            {
                Encounter[0] = data0;
                Encounter[1] = data1;
                Encounter[2] = data2;
                Encounter[3] = data3;
                Encounter[4] = data4;

                for (uint8 i=0; i<ENCOUNTERS; ++i)
                    if (Encounter[i] == IN_PROGRESS)
                        Encounter[i] = NOT_STARTED;
            }
            else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_lost_city_of_the_tolvir()
{
    new instance_lost_city_of_the_tolvir();
}