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
SDComment:
SDCategory: Azjol Nerub
EndScriptData */

#include "precompiled.h"
#include "def_ahnkahet.h"

#define ENCOUNTERS     5

/* Ahn'kahet encounters:
0 - Elder Nadox
1 - Prince Taldaram
2 - Jedoga Shadowseeker
3 - Herald Volazj
4 - Amanitar (Heroic only)
*/

struct TRINITY_DLL_DECL instance_ahnkahet : public ScriptedInstance
{
    instance_ahnkahet(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 Elder_Nadox;
    uint64 Prince_Taldaram;
    uint64 Jedoga_Shadowseeker;
    uint64 Herald_Volazj;
    uint64 Amanitar;

    uint32 Encounters[ENCOUNTERS];

   void Initialize()
   {
        Elder_Nadox =0;
        Prince_Taldaram =0;
        Jedoga_Shadowseeker =0;
        Herald_Volazj =0;
        Amanitar =0;

        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            Encounters[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if(Encounters[i] == IN_PROGRESS) return true;

        return false;
    }


    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 29309:    Elder_Nadox = creature->GetGUID();                   break;
            case 29308:    Prince_Taldaram = creature->GetGUID();               break;
            case 29310:    Jedoga_Shadowseeker = creature->GetGUID();   break;
            case 29311:    Herald_Volazj = creature->GetGUID();                 break;
            case 30258:    Amanitar = creature->GetGUID();                      break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_ELDER_NADOX:          return Elder_Nadox;
            case DATA_PRINCE_TALDARAM:      return Prince_Taldaram;
            case DATA_JEDOGA_SHADOWSEEKER:  return Jedoga_Shadowseeker;
            case DATA_HERALD_VOLAZJ:        return Herald_Volazj;
            case DATA_AMANITAR:             return Amanitar;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
        case DATA_ELDER_NADOX_EVENT:
            Encounters[0] = data;break;
        case DATA_PRINCE_TALDARAM_EVENT:
            Encounters[1] = data; break;
        case DATA_JEDOGA_SHADOWSEEKER_EVENT:
            Encounters[2] = data; break;
        case DATA_HERALD_VOLAZJ:
            Encounters[3] = data; break;
        case DATA_AMANITAR:
            Encounters[4] = data; break;
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
            case DATA_ELDER_NADOX_EVENT:            return Encounters[0];
            case DATA_PRINCE_TALDARAM_EVENT:        return Encounters[1];
            case DATA_JEDOGA_SHADOWSEEKER_EVENT:    return Encounters[2];
            case DATA_HERALD_VOLAZJ:                return Encounters[3];
            case DATA_AMANITAR:                     return Encounters[4];
        }
        return 0;
    }

   std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::string str_data;

        std::ostringstream saveStream;
        saveStream << "A K " << Encounters[0] << " " << Encounters[1] << " "
            << Encounters[2] << Encounters[3] << Encounters[4];

        str_data = saveStream.str();

        OUT_SAVE_INST_DATA_COMPLETE;
        return str_data.c_str();
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
        uint16 data0,data1,data2,data3,data4;

        std::istringstream loadStream(in);
        loadStream >> dataHead1 >> dataHead2 >> data0 >> data1 >> data2 >> data3 >> data4;

        if( dataHead1 == 'A' && dataHead2 == 'K')
        {
            Encounters[0] = data0;
            Encounters[1] = data1;
            Encounters[2] = data2;
            Encounters[3] = data3;
            Encounters[4] = data4;

            for(uint8 i = 0; i < ENCOUNTERS; ++i)
                if (Encounters[i] == IN_PROGRESS)
                    Encounters[i] = NOT_STARTED;

        }else OUT_LOAD_INST_DATA_FAIL;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};

InstanceData* GetInstanceData_instance_ahnkahet(Map* map)
{
   return new instance_ahnkahet(map);
}

void AddSC_instance_ahnkahet()
{
   Script *newscript;
   newscript = new Script;
   newscript->Name = "instance_ahnkahet";
   newscript->GetInstanceData = &GetInstanceData_instance_ahnkahet;
   newscript->RegisterSelf();
}
