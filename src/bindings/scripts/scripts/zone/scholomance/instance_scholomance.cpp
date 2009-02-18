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
SDName: Instance_Scholomance
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "def_scholomance.h"

struct TRINITY_DLL_DECL instance_scholomance : public ScriptedInstance
{
    instance_scholomance(Map *map) : ScriptedInstance(map) {Initialize();};

    //Lord Alexei Barov, Doctor Theolen Krastinov, The Ravenian, Lorekeeper Polkelt, Instructor Malicia and the Lady Illucia Barov.
    bool IsBossDied[6];

    void Initialize()
    {
        IsBossDied[0] = false;
        IsBossDied[1] = false;
        IsBossDied[2] = false;
        IsBossDied[3] = false;
        IsBossDied[4] = false;
        IsBossDied[5] = false;
    }

    bool IsEncounterInProgress() const
    {
        //not active in scholomance
        return false;
    }

    uint32 GetData(uint32 type)
    {
        if(type == DATA_CANSPAWNGANDLING)
            if(IsBossDied[0] && IsBossDied[1] && IsBossDied[2] && IsBossDied[3] && IsBossDied[4] && IsBossDied[5])
                return 1;

        return 0;
    }

    void SetData(uint32 type, uint32 data)
    {
        switch(type)
        {
            case DATA_LORDALEXEIBAROV_DEATH:
                IsBossDied[0] = true;
                break;

            case DATA_DOCTORTHEOLENKRASTINOV_DEATH:
                IsBossDied[1] = true;
                break;

            case DATA_THERAVENIAN_DEATH:
                IsBossDied[2] = true;
                break;

            case DATA_LOREKEEPERPOLKELT_DEATH:
                IsBossDied[3] = true;
                break;

            case DATA_INSTRUCTORMALICIA_DEATH:
                IsBossDied[4] = true;
                break;

            case DATA_LADYILLUCIABAROV_DEATH:
                IsBossDied[5] = true;
                break;
        }
    }
};

InstanceData* GetInstanceData_instance_scholomance(Map* map)
{
    return new instance_scholomance(map);
}

void AddSC_instance_scholomance()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_scholomance";
    newscript->GetInstanceData = &GetInstanceData_instance_scholomance;
    newscript->RegisterSelf();
}

