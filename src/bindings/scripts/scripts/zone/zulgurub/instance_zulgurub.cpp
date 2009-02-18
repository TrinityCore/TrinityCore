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
SDName: Instance_ZulGurub
SD%Complete: 80
SDComment: Missing reset function after killing a boss for Ohgan, Thekal.
SDCategory: Zul'Gurub
EndScriptData */

#include "precompiled.h"
#include "def_zulgurub.h"

struct TRINITY_DLL_DECL instance_zulgurub : public ScriptedInstance
{
    instance_zulgurub(Map *map) : ScriptedInstance(map) {Initialize();};

    //If all High Priest bosses were killed. Lorkhan, Zath and Ohgan are added too.
    bool IsBossDied[9];

    //Storing Lorkhan, Zath and Thekal because we need to cast on them later. Jindo is needed for healfunction too.
    uint64 LorKhanGUID;
    uint64 ZathGUID;
    uint64 ThekalGUID;
    uint64 JindoGUID;

    void OnCreatureCreate (Creature *creature, uint32 creature_entry)
    {
        switch (creature_entry)
        {
            case 11347:
                LorKhanGUID = creature->GetGUID();
                break;

            case 11348:
                ZathGUID = creature->GetGUID();
                break;

            case 14509:
                ThekalGUID = creature->GetGUID();
                break;

            case 11380:
                JindoGUID = creature->GetGUID();
                break;
        }
    }

    void Initialize()
    {
        IsBossDied[0] = false;
        IsBossDied[1] = false;
        IsBossDied[2] = false;
        IsBossDied[3] = false;
        IsBossDied[4] = false;
        IsBossDied[5] = false;
        IsBossDied[6] = false;

        IsBossDied[7] = false;
        IsBossDied[8] = false;
    }

    bool IsEncounterInProgress() const
    {
        //not active in Zul'Gurub
        return false;
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_JEKLIKISDEAD:
                if(IsBossDied[0])
                    return 1;
                break;

            case DATA_VENOXISISDEAD:
                if(IsBossDied[1])
                    return 1;
                break;

            case DATA_MARLIISDEAD:
                if(IsBossDied[2])
                    return 1;
                break;

            case DATA_THEKALISDEAD:
                if(IsBossDied[3])
                    return 1;
                break;

            case DATA_ARLOKKISDEAD:
                if(IsBossDied[4])
                    return 1;
                break;

            case DATA_LORKHANISDEAD:
                if(IsBossDied[5])
                    return 1;
                break;

            case DATA_ZATHISDEAD:
                if(IsBossDied[6])
                    return 1;
                break;

            case DATA_THEKALISFAKEDEAD:
                if(IsBossDied[7])
                    return 1;
                break;

            case DATA_OHGANISDEAD:
                if(IsBossDied[8])
                    return 1;
                break;

                //Boss is not dead. Resetting function for some bosses after killing them but whiping at the complete encounter.

            case DATA_THEKALISALIVE:
                if(IsBossDied[3])
                    return 0;
                break;

            case DATA_LORKHANISALIVE:
                if(IsBossDied[5])
                    return 0;
                break;

            case DATA_ZATHISALIVE:
                if(IsBossDied[6])
                    return 0;
                break;
        }

        return 0;
    }

    uint64 GetData64 (uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_LORKHAN:
                return LorKhanGUID;

            case DATA_ZATH:
                return ZathGUID;

            case DATA_THEKAL:
                return ThekalGUID;

            case DATA_JINDO:
                return JindoGUID;
        }
        return 0;
    }                                                       // end GetData64

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_JEKLIK_DEATH:
                IsBossDied[0] = true;
                break;

            case DATA_VENOXIS_DEATH:
                IsBossDied[1] = true;
                break;

            case DATA_MARLI_DEATH:
                IsBossDied[2] = true;
                break;

            case DATA_THEKAL_DEATH:
                IsBossDied[3] = true;
                break;

            case DATA_ARLOKK_DEATH:
                IsBossDied[4] = true;
                break;

            case DATA_LORKHAN_DEATH:
                IsBossDied[5] = true;
                break;

            case DATA_ZATH_DEATH:
                IsBossDied[6] = true;
                break;

            case DATA_THEKALFAKE_DEATH:
                IsBossDied[7] = true;
                break;

            case DATA_OHGAN_DEATH:
                IsBossDied[8] = true;
                break;

            case DATA_LORKHAN_ALIVE:
                IsBossDied[5] = false;
                break;

            case DATA_ZATH_ALIVE:
                IsBossDied[6] = false;
                break;

            case DATA_THEKAL_ALIVE:
                IsBossDied[7] = false;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_zulgurub(Map* map)
{
    return new instance_zulgurub(map);
}

void AddSC_instance_zulgurub()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_zulgurub";
    newscript->GetInstanceData = &GetInstanceData_instance_zulgurub;
    newscript->RegisterSelf();
}

