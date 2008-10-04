/* Copyright (C) 2006,2007 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

/* ScriptData
SDName: Instance_Zulaman
SD%Complete: 80
SDComment:
SDCategory: Zul'Aman
EndScriptData */

#include "precompiled.h"
#include "def_zulaman.h"

#define ENCOUNTERS     1
#define RAND_VENDOR    2

struct MANGOS_DLL_DECL instance_zulaman : public ScriptedInstance
{
    instance_zulaman(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 janalai;
    uint32 janalai_eggs_l;
    uint32 janalai_eggs_r;

    uint32 Encounters[ENCOUNTERS];
    uint32 RandVendor[RAND_VENDOR];

    void Initialize()
    {
        janalai = 0;
        janalai_eggs_l = 20;
        janalai_eggs_r = 20;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounters[i] = NOT_STARTED;
        for(uint8 i = 0; i < RAND_VENDOR; i++)
            RandVendor[i] = NOT_STARTED;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i] == IN_PROGRESS) return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 23578:
                janalai = creature->GetGUID();
                break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        if(identifier  == DATA_JANALAI && janalai)
            return janalai;

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_JANALAIEVENT:
                if(data == 0)
                {
                    janalai_eggs_l = 20;
                    janalai_eggs_r = 20;
                }
                Encounters[0] = data;
                break;
            case DATA_J_HATCHLEFT:
                janalai_eggs_l -= data;
                break;
            case DATA_J_HATCHRIGHT:
                janalai_eggs_r -= data;
                break;
            case TYPE_RAND_VENDOR_1:
                RandVendor[0] = data;
                break;
            case TYPE_RAND_VENDOR_2:
                RandVendor[1] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_JANALAIEVENT:
                return Encounters[0];
            case DATA_J_EGGSLEFT:
                return janalai_eggs_l;
            case DATA_J_EGGSRIGHT:
                return janalai_eggs_r;
            case TYPE_RAND_VENDOR_1:
                return RandVendor[0];
            case TYPE_RAND_VENDOR_2:
                return RandVendor[1];
        }
        return 0;
    }
};

InstanceData* GetInstanceData_instance_zulaman(Map* map)
{
    return new instance_zulaman(map);
}

void AddSC_instance_zulaman()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_zulaman";
    newscript->GetInstanceData = GetInstanceData_instance_zulaman;
    m_scripts[nrscripts++] = newscript;
}
