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
#include "the_stonecore.h"

#define MAX_ENCOUNTER     4

class instance_the_stonecore : public InstanceMapScript
{
public:
    instance_the_stonecore() : InstanceMapScript("instance_the_stonecore", 725) { }

    InstanceScript* GetInstanceScript(InstanceMap* map) const
    {
        return new instance_the_stonecore_InstanceMapScript(map);
    }

    struct instance_the_stonecore_InstanceMapScript : public InstanceScript
    {
        instance_the_stonecore_InstanceMapScript(Map* map) : InstanceScript(map) {};

        uint64 Corborus;
        uint64 Slabhide;
        uint64 Ozruk;
        uint64 HighPriestessAzil;
        uint32 TeamInInstance;
        uint32 Encounter[MAX_ENCOUNTER];

        void Initialize()
        {
             for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                 Encounter[i] = NOT_STARTED;

             Corborus = 0;
             Slabhide = 0;
             Ozruk = 0;
             HighPriestessAzil = 0;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                if (Encounter[i] == IN_PROGRESS)
                    return true;

             return false;
        }

        void OnCreatureCreate(Creature* creature, bool /*add*/)
        {
            Map::PlayerList const &players = instance->GetPlayers();

            if (!players.isEmpty())
            {
                if (Player* player = players.begin()->getSource())
                    TeamInInstance = player->GetTeam();
            }

            switch (creature->GetEntry())
            {
                case BOSS_CORBORUS:
                    Corborus = creature->GetGUID();
                    break;
                case BOSS_SLABHIDE:
                    Slabhide = creature->GetGUID();
                    break;
                case BOSS_OZRUK:
                    Ozruk = creature->GetGUID();
                    break;
                case BOSS_HIGH_PRIESTESS_AZIL:
                    HighPriestessAzil = creature->GetGUID();
                    break;
            }
        }

        uint64 GetData64(uint32 identifier)
        {
            switch (identifier)
            {
                case DATA_CORBORUS:                    return Corborus;
                case DATA_SLABHIDE:                    return Slabhide;
                case DATA_OZRUK:                       return Ozruk;
                case DATA_HIGH_PRIESTESS_AZIL:         return HighPriestessAzil;
            }

            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch (type)
            {
                case DATA_CORBORUS_EVENT:
                    Encounter[0] = data;
                    break;
                case DATA_SLABHIDE_EVENT:
                    Encounter[1] = data;
                    break;
                case DATA_OZRUK_EVENT:
                    Encounter[2] = data;
                    break;
                case DATA_HIGH_PRIESTESS_AZIL_EVENT:
                    Encounter[3] = data;
                    break;
            }

            if (data == DONE)
               SaveToDB();
        }

        uint32 GetData(uint32 type)
        {
            switch (type)
            {
                case DATA_CORBORUS_EVENT:                  return Encounter[0];
                case DATA_SLABHIDE_EVENT:                  return Encounter[1];
                case DATA_OZRUK_EVENT:                     return Encounter[2];
                case DATA_HIGH_PRIESTESS_AZIL_EVENT:       return Encounter[3];
            }

            return 0;
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;

            std::string str_data;

            std::ostringstream saveStream;
            saveStream << "P S " << Encounter[0] << " " << Encounter[1]  << " " << Encounter[2]  << " " << Encounter[3];

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
            uint16 data0, data1, data2, data3;

            std::istringstream loadStream(in);
            loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3;

            if (dataHead1 == 'P' && dataHead2 == 'S')
            {
                Encounter[0] = data0;
                Encounter[1] = data1;
                Encounter[2] = data2;
                Encounter[3] = data3;

                for (uint8 i = 0; i < MAX_ENCOUNTER; ++i)
                    if (Encounter[i] == IN_PROGRESS)
                        Encounter[i] = NOT_STARTED;
            }
            else OUT_LOAD_INST_DATA_FAIL;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };
};

void AddSC_instance_the_stonecore()
{
    new instance_the_stonecore();
}