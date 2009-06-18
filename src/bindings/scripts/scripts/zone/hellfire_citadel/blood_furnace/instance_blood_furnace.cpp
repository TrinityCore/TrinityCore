/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Blood_Furnace
SD%Complete: 85
SDComment:
SDCategory: Hellfire Citadel, Blood Furnace
EndScriptData */

#include "precompiled.h"
#include "def_blood_furnace.h"

#define ENTRY_SEWER1                 181823
#define ENTRY_SEWER2                 181766
#define ENCOUNTERS                   3

struct TRINITY_DLL_DECL instance_blood_furnace : public ScriptedInstance
{
    instance_blood_furnace(Map *map) : ScriptedInstance(map) {Initialize();};

    uint64 The_MakerGUID;
    uint64 BroggokGUID;
    uint64 Kelidan_The_BreakerGUID;

    uint64 Door1GUID;
    uint64 Door2GUID;
    uint64 Door3GUID;
    uint64 Door4GUID;
    uint64 Door5GUID;
    uint64 Door6GUID;

    uint64 PrisonCell1GUID;
    uint64 PrisonCell2GUID;
    uint64 PrisonCell3GUID;
    uint64 PrisonCell4GUID;
    uint64 PrisonCell5GUID;
    uint64 PrisonCell6GUID;
    uint64 PrisonCell7GUID;
    uint64 PrisonCell8GUID;

    uint32 Encounter[ENCOUNTERS];
    std::string str_data;

    void Initialize()
    {
        The_MakerGUID = 0;
        BroggokGUID = 0;
        Kelidan_The_BreakerGUID = 0;

        Door1GUID = 0;
        Door2GUID = 0;
        Door3GUID = 0;
        Door4GUID = 0;
        Door5GUID = 0;
        Door6GUID = 0;

        PrisonCell1GUID = 0;
        PrisonCell2GUID = 0;
        PrisonCell3GUID = 0;
        PrisonCell4GUID = 0;
        PrisonCell5GUID = 0;
        PrisonCell6GUID = 0;
        PrisonCell7GUID = 0;
        PrisonCell8GUID = 0;
        
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
    }


    void OnCreatureCreate(Creature *creature, bool add)
    {
        if(!add)
            return;

        switch(creature->GetEntry())
        {
             case 17381: The_MakerGUID = creature->GetGUID(); break;
             case 17380: BroggokGUID = creature->GetGUID(); break;
             case 17377: Kelidan_The_BreakerGUID = creature->GetGUID(); break;
        }
    }

    void OnGameObjectCreate(GameObject *go, bool add)
    {
        if(!add)
            return;

     if (go->GetEntry() == 181766)                //Final exit door
         Door1GUID = go->GetGUID();
     if (go->GetEntry() == 181811)               //The Maker Front door
         Door2GUID = go->GetGUID();
     if (go->GetEntry() == 181812)                //The Maker Rear door
         Door3GUID = go->GetGUID();
     if (go->GetEntry() == 181822)               //Broggok Front door
         Door4GUID = go->GetGUID();
     if (go->GetEntry() == 181819)               //Broggok Rear door
         Door5GUID = go->GetGUID();
     if (go->GetEntry() == 181823)               //Kelidan exit door
         Door6GUID = go->GetGUID();

     if (go->GetEntry() == 181813)               //The Maker prison cell front right
         PrisonCell1GUID = go->GetGUID();
     if (go->GetEntry() == 181814)               //The Maker prison cell back right
         PrisonCell2GUID = go->GetGUID();
     if (go->GetEntry() == 181816)               //The Maker prison cell front left
         PrisonCell3GUID = go->GetGUID();
     if (go->GetEntry() == 181815)               //The Maker prison cell back left
         PrisonCell4GUID = go->GetGUID();
     if (go->GetEntry() == 181821)               //Broggok prison cell front right
         PrisonCell5GUID = go->GetGUID();
     if (go->GetEntry() == 181818)               //Broggok prison cell back right
         PrisonCell6GUID = go->GetGUID();
     if (go->GetEntry() == 181820)               //Broggok prison cell front left
         PrisonCell7GUID = go->GetGUID();
     if (go->GetEntry() == 181817)               //Broggok prison cell back left
         PrisonCell8GUID = go->GetGUID();
    }

    uint64 GetData64(uint32 data)
    {
        switch(data)
        {
             case DATA_THE_MAKER:            return The_MakerGUID;
             case DATA_BROGGOK:              return BroggokGUID;
             case DATA_KELIDAN_THE_MAKER:    return Kelidan_The_BreakerGUID;
             case DATA_DOOR1:                return Door1GUID;
             case DATA_DOOR2:                return Door2GUID;
             case DATA_DOOR3:                return Door3GUID;
             case DATA_DOOR4:                return Door4GUID;
             case DATA_DOOR5:                return Door5GUID;
             case DATA_DOOR6:                return Door6GUID;
             case DATA_PRISON_CELL1:         return PrisonCell1GUID;
             case DATA_PRISON_CELL2:         return PrisonCell2GUID;
             case DATA_PRISON_CELL3:         return PrisonCell3GUID;
             case DATA_PRISON_CELL4:         return PrisonCell4GUID;
             case DATA_PRISON_CELL5:         return PrisonCell5GUID;
             case DATA_PRISON_CELL6:         return PrisonCell6GUID;
             case DATA_PRISON_CELL7:         return PrisonCell7GUID;
             case DATA_PRISON_CELL8:         return PrisonCell8GUID;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
         switch(data)
         {
             case TYPE_THE_MAKER_EVENT:             Encounter[0] = data;     break;
             case TYPE_BROGGOK_EVENT:               Encounter[1] = data;     break;
             case TYPE_KELIDAN_THE_BREAKER_EVENT:   Encounter[2] = data;     break;
         }

        if (data == DONE)
        {
            OUT_SAVE_INST_DATA;

            std::ostringstream saveStream;
            saveStream << Encounter[0] << " " << Encounter[1] << " " << Encounter[2];

            str_data = saveStream.str();

            SaveToDB();
            OUT_SAVE_INST_DATA_COMPLETE;
        }
    }

    uint32 GetData(uint32 data)
    {
        switch(data)
        {
            case TYPE_THE_MAKER_EVENT:             return Encounter[0];
            case TYPE_BROGGOK_EVENT:               return Encounter[1];
            case TYPE_KELIDAN_THE_BREAKER_EVENT:   return Encounter[2];
        }

        return 0;
    }

    const char* Save()
    {
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

        std::istringstream loadStream(in);
        loadStream >> Encounter[0] >> Encounter[1] >> Encounter[2];

        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if (Encounter[i] == IN_PROGRESS || Encounter[i] == FAIL)
                Encounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }
};


InstanceData* GetInstanceData_instance_blood_furnace(Map* map)
{
    return new instance_blood_furnace(map);
}

void AddSC_instance_blood_furnace()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_blood_furnace";
    newscript->GetInstanceData = &GetInstanceData_instance_blood_furnace;
    newscript->RegisterSelf();
}

