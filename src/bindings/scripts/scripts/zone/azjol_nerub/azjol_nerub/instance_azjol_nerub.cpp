/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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
SDName: Instance_Azjol_Nerub
SD%Complete: 0
SDComment: Placeholder
SDCategory: Azjol Nerub
EndScriptData */

#include "precompiled.h"
#include "def_azjol_nerub.h"

#define ENCOUNTERS     3

/* Azjol Nerub encounters:
0 - Krik'thir the Gatewatcher
1 - Hadronox
2 - Anub'arak
*/

struct TRINITY_DLL_DECL instance_azjol_nerub : public ScriptedInstance
{
    instance_azjol_nerub(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 Krikthir;
    uint64 Hadronox;
    uint64 Anubarak;

    uint32 Encounters[ENCOUNTERS];

   void Initialize()
   {
        Krikthir = 0;
        Hadronox = 0;
        Anubarak =0;


        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS) return true;

        return false;
    }


    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 28684:    Krikthir = creature->GetGUID();  break;
            case 28921:    Hadronox = creature->GetGUID();  break;
            case 29120:    Anubarak = creature->GetGUID();  break;

        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_KRIKTHIR_THE_GATEWATCHER:     return Krikthir;
            case DATA_HADRONOX:                     return Hadronox;
            case DATA_ANUBARAK:                     return Anubarak;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:
            Encounters[0] = data;break;
        case DATA_HADRONOX_EVENT:
            Encounters[1] = data; break;
        case DATA_ANUBARAK_EVENT:
            Encounters[2] = data; break;
        }

        if (data == DONE)
        {
            SaveToDB();
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_KRIKTHIR_THE_GATEWATCHER_EVENT:   return Encounters[0];
            case DATA_HADRONOX_EVENT:                   return Encounters[1];
            case DATA_ANUBARAK_EVENT:                   return Encounters[2];
        }

        return 0;
    }

   std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "A N " << Encounters[0] << " " << Encounters[1] << " "
            << Encounters[2];

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
        uint16 data0,data1,data2;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2;

        if( dataHead1 == 'A' && dataHead2 == 'N')
        {
            Encounters[0] = data0;
            Encounters[1] = data1;
            Encounters[2] = data2;

            for(uint8 i = 0; i < ENCOUNTERS; ++i)
                if (Encounters[i] == IN_PROGRESS)
                    Encounters[i] = NOT_STARTED;

        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_azjol_nerub(Map* map)
{
   return new instance_azjol_nerub(map);
}

void AddSC_instance_azjol_nerub()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_azjol_nerub";
   newscript->GetInstanceData = &GetInstanceData_instance_azjol_nerub;
   newscript->RegisterSelf();
}
