/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_Serpent_Shrine
SD%Complete: 0
SDComment: VERIFY SCRIPT
SDCategory: Coilfang Resevoir, Serpent Shrine Cavern
EndScriptData */

#include "precompiled.h"
#include "def_serpent_shrine.h"

#define ENCOUNTERS 6

/* Serpentshrine cavern encounters:
0 - Hydross The Unstable event
1 - Leotheras The Blind Event
2 - The Lurker Below Event
3 - Fathom-Lord Karathress Event
4 - Morogrim Tidewalker Event
5 - Lady Vashj Event
*/

struct TRINITY_DLL_DECL instance_serpentshrine_cavern : public ScriptedInstance
{
    instance_serpentshrine_cavern(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 Sharkkis;
    uint64 Tidalvess;
    uint64 Caribdis;
    uint64 LadyVashj;
    uint64 Karathress;
    uint64 KarathressEvent_Starter;

    bool ShieldGeneratorDeactivated[4];

    bool Encounters[ENCOUNTERS];

    void Initialize()
    {
        Sharkkis = 0;
        Tidalvess = 0;
        Caribdis = 0;
        LadyVashj = 0;
        Karathress = 0;
        KarathressEvent_Starter = 0;

        ShieldGeneratorDeactivated[0] = false;
        ShieldGeneratorDeactivated[1] = false;
        ShieldGeneratorDeactivated[2] = false;
        ShieldGeneratorDeactivated[3] = false;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounters[i] = false;
    }

    bool IsEncounterInProgress() const
    {
        for(uint8 i = 0; i < ENCOUNTERS; i++)
            if(Encounters[i]) return true;

        return false;
    }

    void OnCreatureCreate(Creature *creature, uint32 creature_entry)
    {
        switch(creature_entry)
        {
            case 21212: LadyVashj = creature->GetGUID(); break;
            case 21214: Karathress = creature->GetGUID(); break;
            case 21966: Sharkkis = creature->GetGUID(); break;
            case 21965: Tidalvess = creature->GetGUID(); break;
            case 21964: Caribdis = creature->GetGUID(); break;
        }
    }

    void SetData64(uint32 type, uint64 data)
    {
        if(type == DATA_KARATHRESSEVENT_STARTER)
            KarathressEvent_Starter = data;
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_SHARKKIS:
                return Sharkkis;
            case DATA_TIDALVESS:
                return Tidalvess;
            case DATA_CARIBDIS:
                return Caribdis;
            case DATA_LADYVASHJ:
                return LadyVashj;
            case DATA_KARATHRESS:
                return Karathress;
            case DATA_KARATHRESSEVENT_STARTER:
                return KarathressEvent_Starter;
        }
        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_HYDROSSTHEUNSTABLEEVENT:
                Encounters[0] = (data) ? true : false;
                break;

            case DATA_LEOTHERASTHEBLINDEVENT:
                Encounters[1] = (data) ? true : false;
                break;

            case DATA_THELURKERBELOWEVENT:
                Encounters[2] = (data) ? true : false;
                break;

            case DATA_KARATHRESSEVENT:
                Encounters[3] = (data) ? true : false;
                break;

            case DATA_MOROGRIMTIDEWALKEREVENT:
                Encounters[4] = (data) ? true : false;
                break;
                //Lady Vashj
            case DATA_LADYVASHJEVENT:
                if(data == 0)
                {
                    ShieldGeneratorDeactivated[0] = false;
                    ShieldGeneratorDeactivated[1] = false;
                    ShieldGeneratorDeactivated[2] = false;
                    ShieldGeneratorDeactivated[3] = false;
                }
                Encounters[5] = (data) ? true : false;
                break;

            case DATA_SHIELDGENERATOR1:
                ShieldGeneratorDeactivated[0] = (data) ? true : false;
                break;

            case DATA_SHIELDGENERATOR2:
                ShieldGeneratorDeactivated[1] = (data) ? true : false;
                break;

            case DATA_SHIELDGENERATOR3:
                ShieldGeneratorDeactivated[2] = (data) ? true : false;
                break;

            case DATA_SHIELDGENERATOR4:
                ShieldGeneratorDeactivated[3] = (data) ? true : false;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_HYDROSSTHEUNSTABLEEVENT:
                return Encounters[0];

            case DATA_LEOTHERASTHEBLINDEVENT:
                return Encounters[1];

            case DATA_THELURKERBELOWEVENT:
                return Encounters[2];

            case DATA_KARATHRESSEVENT:
                return Encounters[3];

            case DATA_MOROGRIMTIDEWALKEREVENT:
                return Encounters[4];

                //Lady Vashj
            case DATA_LADYVASHJEVENT:
                return Encounters[5];

            case DATA_SHIELDGENERATOR1:
                return ShieldGeneratorDeactivated[0];

            case DATA_SHIELDGENERATOR2:
                return ShieldGeneratorDeactivated[1];

            case DATA_SHIELDGENERATOR3:
                return ShieldGeneratorDeactivated[2];

            case DATA_SHIELDGENERATOR4:
                return ShieldGeneratorDeactivated[3];

            case DATA_CANSTARTPHASE3:
                if(ShieldGeneratorDeactivated[0] && ShieldGeneratorDeactivated[1] && ShieldGeneratorDeactivated[2] && ShieldGeneratorDeactivated[3])
                    return 1;
                break;
        }

        return 0;
    }
};

InstanceData* GetInstanceData_instance_serpentshrine_cavern(Map* map)
{
    return new instance_serpentshrine_cavern(map);
}

void AddSC_instance_serpentshrine_cavern()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_serpent_shrine";
    newscript->GetInstanceData = GetInstanceData_instance_serpentshrine_cavern;
    m_scripts[nrscripts++] = newscript;
}
