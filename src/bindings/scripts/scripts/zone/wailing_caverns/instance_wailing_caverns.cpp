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
SDName: Instance_Wailing_Caverns
SD%Complete: 90
SDComment: Most of the event done, still need some polishing
SDCategory: Wailing Caverns
EndScriptData */

#include "precompiled.h"
#include "def_wailing_caverns.h"

#define ENCOUNTERS   9

struct TRINITY_DLL_DECL instance_wailing_caverns : public ScriptedInstance
{
    instance_wailing_caverns(Map *map) : ScriptedInstance(map) {Initialize();};

    uint32 Encounter[ENCOUNTERS];

    uint64 NaralexGUID;

    void Initialize()
    {
        NaralexGUID = 0;

        for (uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
    }

    void OnCreatureCreate(Creature *creature, bool add)
    {
        if (creature->GetEntry() == DATA_NARALEX)
            NaralexGUID = creature->GetGUID();
    }

    void SetData(uint32 type, uint32 data)
    {
        switch (type)
        {
            case TYPE_LORD_COBRAHN:Encounter[0] = data;break;
            case TYPE_LORD_PYTHAS:Encounter[1] = data;break;
            case TYPE_LADY_ANACONDRA:Encounter[2] = data;break;
            case TYPE_LORD_SERPENTIS:Encounter[3] = data;break;
            case TYPE_NARALEX_EVENT:  Encounter[4] = data;break;
            case TYPE_NARALEX_PART1:Encounter[5] = data;break;
            case TYPE_NARALEX_PART2: Encounter[6] = data;break;
            case TYPE_NARALEX_PART3:Encounter[7] = data;break;
            case TYPE_MUTANUS_THE_DEVOURER:Encounter[8] = data;break;
        }
        if(data == DONE)SaveToDB();
    }

    uint32 GetData(uint32 type)
    {
        switch (type)
        {
            case TYPE_LORD_COBRAHN:         return Encounter[0];
            case TYPE_LORD_PYTHAS:          return Encounter[1];
            case TYPE_LADY_ANACONDRA:       return Encounter[2];
            case TYPE_LORD_SERPENTIS:       return Encounter[3];
            case TYPE_NARALEX_EVENT:        return Encounter[4];
            case TYPE_NARALEX_PART1:        return Encounter[5];
            case TYPE_NARALEX_PART2:        return Encounter[6];
            case TYPE_NARALEX_PART3:        return Encounter[7];
            case TYPE_MUTANUS_THE_DEVOURER: return Encounter[8];
        }
        return 0;
    }

    uint64 GetData64(uint32 data)
    {
        if (data == DATA_NARALEX)return NaralexGUID;
        return 0;
    }

    std::string GetSaveData()
    {
        OUT_SAVE_INST_DATA;

        std::ostringstream saveStream;
        saveStream << Encounter[0] << " " << Encounter[1] << " " << Encounter[2] << " "
            << Encounter[3] << " " << Encounter[4] << " " << Encounter[5] << " "
            << Encounter[6] << " " << Encounter[7] << " " << Encounter[8];
      
        OUT_SAVE_INST_DATA_COMPLETE;
        return saveStream.str();
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
        loadStream >> Encounter[0] >> Encounter[1] >> Encounter[2] >> Encounter[3]
        >> Encounter[4] >> Encounter[5] >> Encounter[6] >> Encounter[7] >> Encounter[8];

        for(uint8 i = 0; i < ENCOUNTERS; ++i)
            if (Encounter[i] != DONE)
                Encounter[i] = NOT_STARTED;

        OUT_LOAD_INST_DATA_COMPLETE;
    }

};

InstanceData* GetInstanceData_instance_wailing_caverns(Map* map)
{
    return new instance_wailing_caverns(map);
}

void AddSC_instance_wailing_caverns()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_wailing_caverns";
    newscript->GetInstanceData = &GetInstanceData_instance_wailing_caverns;
    newscript->RegisterSelf();
}