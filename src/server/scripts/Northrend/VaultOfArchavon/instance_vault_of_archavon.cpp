/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "vault_of_archavon.h"

#define ENCOUNTERS  4

/* Vault of Archavon encounters:
1 - Archavon the Stone Watcher event
2 - Emalon the Storm Watcher event
3 - Koralon the Flame Watcher event
4 - Toravon the Ice Watcher event
*/

class instance_archavon : public InstanceMapScript
{
public:
    instance_archavon() : InstanceMapScript("instance_archavon", 624) { }

    InstanceScript* GetInstanceScript(InstanceMap* pMap) const
    {
        return new instance_archavon_InstanceMapScript(map);
    }

    struct instance_archavon_InstanceMapScript : public InstanceScript
    {
        instance_archavon_InstanceMapScript(Map *Map) : InstanceScript(Map) {};

        uint32 uiEncounters[ENCOUNTERS];

        uint64 uiArchavon;
        uint64 uiEmalon;
        uint64 uiKoralon;
        uint64 uiToravon;

        void Initialize()
        {
            uiArchavon = 0;
            uiEmalon = 0;
            uiKoralon = 0;
            uiToravon = 0;

            for (uint8 i = 0; i < ENCOUNTERS; i++)
                uiEncounters[i] = NOT_STARTED;
        }

        bool IsEncounterInProgress() const
        {
            for (uint8 i = 0; i < ENCOUNTERS; i++)
                if (uiEncounters[i] == IN_PROGRESS)
                    return true;

            return false;
        }

        void OnCreatureCreate(Creature *creature, bool /*add*/)
        {
            switch(creature->GetEntry())
            {
                case CREATURE_ARCHAVON: uiArchavon  = creature->GetGUID(); break;
                case CREATURE_EMALON:   uiEmalon    = creature->GetGUID(); break;
                case CREATURE_KORALON:  uiKoralon   = creature->GetGUID(); break;
                case CREATURE_TORAVON:  uiToravon   = creature->GetGUID(); break;
            }
        }

        uint32 GetData(uint32 type)
        {
            switch(type)
            {
                case DATA_ARCHAVON_EVENT:   return uiEncounters[0];
                case DATA_EMALON_EVENT:     return uiEncounters[1];
                case DATA_KORALON_EVENT:    return uiEncounters[2];
                case DATA_TORAVON_EVENT:    return uiEncounters[3];
            }
            return 0;
        }

        uint64 GetData64(uint32 identifier)
        {
            switch(identifier)
            {
                case DATA_ARCHAVON: return uiArchavon;
                case DATA_EMALON:   return uiEmalon;
                case DATA_KORALON:  return uiKoralon;
                case DATA_TORAVON:  return uiToravon;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 data)
        {
            switch(type)
            {
                case DATA_ARCHAVON_EVENT:   uiEncounters[0] = data; break;
                case DATA_EMALON_EVENT:     uiEncounters[1] = data; break;
                case DATA_KORALON_EVENT:    uiEncounters[2] = data; break;
                case DATA_TORAVON_EVENT:    uiEncounters[3] = data; break;
            }

            if (data == DONE)
                SaveToDB();
        }

        std::string GetSaveData()
        {
            OUT_SAVE_INST_DATA;
            std::ostringstream stream;
            stream << uiEncounters[0] << " " << uiEncounters[1] << " " << uiEncounters[2] << " " << uiEncounters[3];

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
            stream >> uiEncounters[0] >> uiEncounters[1] >> uiEncounters[2] >> uiEncounters[3];

            for (uint8 i = 0; i < ENCOUNTERS; ++i)
                if (uiEncounters[i] == IN_PROGRESS)
                    uiEncounters[i] = NOT_STARTED;

            OUT_LOAD_INST_DATA_COMPLETE;
        }
    };

};


void AddSC_instance_archavon()
{
    new instance_archavon();
}
