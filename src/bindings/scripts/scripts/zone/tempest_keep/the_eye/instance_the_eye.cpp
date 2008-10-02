/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Instance_The_Eye
SD%Complete: 100
SDComment:
SDCategory: Tempest Keep, The Eye
EndScriptData */

#include "precompiled.h"
#include "def_the_eye.h"

#define ENCOUNTERS 5

/* The Eye encounters:
0 - Kael'thas event
1 - Al' ar event
2 - Solarian Event
3 - Void Reaver event
*/

struct MANGOS_DLL_DECL instance_the_eye : public ScriptedInstance
{
    instance_the_eye(Map *Map) : ScriptedInstance(Map) {Initialize();};

    uint64 ThaladredTheDarkener;
    uint64 LordSanguinar;
    uint64 GrandAstromancerCapernian;
    uint64 MasterEngineerTelonicus;
    uint64 Kaelthas;
    uint64 Astromancer;

    uint8 KaelthasEventPhase;

    bool Encounters[ENCOUNTERS];

    void Initialize()
    {
        ThaladredTheDarkener = 0;
        LordSanguinar = 0;
        GrandAstromancerCapernian = 0;
        MasterEngineerTelonicus = 0;
        Kaelthas = 0;
        Astromancer = 0;

        KaelthasEventPhase = 0;

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
            case 20064: ThaladredTheDarkener = creature->GetGUID(); break;
            case 20063: MasterEngineerTelonicus = creature->GetGUID(); break;
            case 20062: GrandAstromancerCapernian = creature->GetGUID(); break;
            case 20060: LordSanguinar = creature->GetGUID(); break;
            case 19622: Kaelthas = creature->GetGUID(); break;
            case 18805: Astromancer = creature->GetGUID(); break;
        }
    }

    uint64 GetData64(uint32 identifier)
    {
        switch(identifier)
        {
            case DATA_THALADREDTHEDARKENER:
                return ThaladredTheDarkener;

            case DATA_LORDSANGUINAR:
                return LordSanguinar;

            case DATA_GRANDASTROMANCERCAPERNIAN:
                return GrandAstromancerCapernian;

            case DATA_MASTERENGINEERTELONICUS:
                return MasterEngineerTelonicus;

            case DATA_KAELTHAS:
                return Kaelthas;

            case DATA_ASTROMANCER:
                return Astromancer;
        }

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_ALAREVENT:
                Encounters[0] = (data) ? true : false;
                break;

            case DATA_SOLARIANEVENT:
                Encounters[1] = (data) ? true : false;
                break;

            case DATA_VOIDREAVEREVENT:
                Encounters[2] = (data) ? true : false;
                break;

                //Kael'thas
            case DATA_KAELTHASEVENT:
                KaelthasEventPhase = data;
                Encounters[3] = (data) ? true : false;
                break;

            case DATA_HIGHASTROMANCERSOLARIANEVENT:
                Encounters[4] = (data) ? true : false;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        switch(type)
        {
            case DATA_ALAREVENT:
                return Encounters[0];

            case DATA_SOLARIANEVENT:
                return Encounters[1];

            case DATA_VOIDREAVEREVENT:
                return Encounters[2];

            case DATA_HIGHASTROMANCERSOLARIANEVENT:
                return Encounters[4];

                //Kael'thas
            case DATA_KAELTHASEVENT:
                return KaelthasEventPhase;
        }

        return 0;
    }
};

InstanceData* GetInstanceData_instance_the_eye(Map* map)
{
    return new instance_the_eye(map);
}

void AddSC_instance_the_eye()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_the_eye";
    newscript->GetInstanceData = GetInstanceData_instance_the_eye;
    m_scripts[nrscripts++] = newscript;
}
