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
SDName: Instance_Scholomance
SD%Complete: 100
SDComment:
SDCategory: Scholomance
EndScriptData */

#include "precompiled.h"
#include "def_scholomance.h"

#define GO_GATE_KIRTONOS    175570
#define GO_GATE_GANDLING    177374
#define GO_GATE_MALICIA     177375
#define GO_GATE_THEOLEN     177377
#define GO_GATE_POLKELT     177376
#define GO_GATE_RAVENIAN    177372
#define GO_GATE_BAROV       177373
#define GO_GATE_ILLUCIA     177371

#define ENCOUNTERS          2

struct TRINITY_DLL_DECL instance_scholomance : public ScriptedInstance
{
    instance_scholomance(Map *map) : ScriptedInstance(map) {Initialize();};

    //Lord Alexei Barov, Doctor Theolen Krastinov, The Ravenian, Lorekeeper Polkelt, Instructor Malicia and the Lady Illucia Barov.
    bool IsBossDied[6];
    uint32 Encounter[ENCOUNTERS];

    uint64 GateKirtonosGUID;
    uint64 GateGandlingGUID;
    uint64 GateMiliciaGUID;
    uint64 GateTheolenGUID;
    uint64 GatePolkeltGUID;
    uint64 GateRavenianGUID;
    uint64 GateBarovGUID;
    uint64 GateIlluciaGUID;

    void Initialize()
    {
        GateKirtonosGUID = 0;
        GateGandlingGUID = 0;
        GateMiliciaGUID = 0;
        GateTheolenGUID = 0;
        GatePolkeltGUID = 0;
        GateRavenianGUID = 0;
        GateBarovGUID = 0;
        GateIlluciaGUID = 0;

        for(uint8 i = 0; i < 6; i++)
            IsBossDied[i] = false;

        for(uint8 i = 0; i < ENCOUNTERS; i++)
            Encounter[i] = NOT_STARTED;
    }

    void OnObjectCreate(GameObject *go)
    {
        switch(go->GetEntry())
        {
            case GO_GATE_KIRTONOS:  GateKirtonosGUID = go->GetGUID(); break;
            case GO_GATE_GANDLING:  GateGandlingGUID = go->GetGUID(); break;
            case GO_GATE_MALICIA:   GateMiliciaGUID = go->GetGUID(); break;
            case GO_GATE_THEOLEN:   GateTheolenGUID = go->GetGUID(); break;
            case GO_GATE_POLKELT:   GatePolkeltGUID = go->GetGUID(); break;
            case GO_GATE_RAVENIAN:  GateRavenianGUID = go->GetGUID(); break;
            case GO_GATE_BAROV:     GateBarovGUID = go->GetGUID(); break;
            case GO_GATE_ILLUCIA:   GateIlluciaGUID = go->GetGUID(); break;
        }
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
            case TYPE_GANDLING:
                Encounter[0] = data;
                break;
            case TYPE_KIRTONOS:
                Encounter[1] = data;
                break;
        }
    }

    uint32 GetData(uint32 type)
    {
        if (type == TYPE_GANDLING)
        {
            if (IsBossDied[0] && IsBossDied[1] && IsBossDied[2] && IsBossDied[3] && IsBossDied[4] && IsBossDied[5])
            {
                Encounter[0] = IN_PROGRESS;
                return IN_PROGRESS;
            }
        }

        return 0;
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

