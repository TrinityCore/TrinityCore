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
SDName: Instance_Naxxramas
SD%Complete: 0
SDComment: Place holder
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"
#include "def_naxxramas.h"

#define SPELL_ERUPTION      29371

const float HeiganPos[2] = {2796, -3707};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

// 0  H  O-->x
//  1    |
//   2   V
//    3  y
inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if(y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if(x > -1.0f)
        return 3;

    float slope = y/x;
    for(uint32 i = 0; i < 3; ++i)
        if(slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

struct TRINITY_DLL_DECL instance_naxxramas : public ScriptedInstance
{
    instance_naxxramas(Map *map) : ScriptedInstance(map)
        , Sapphiron(NULL)
    {
        SetBossNumber(15);
    }

    std::set<GameObject*> HeiganEruption[4];
    Creature *Sapphiron;

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 15989: Sapphiron = add ? creature : NULL; break;
        }
    }

    void OnObjectCreate(GameObject* go, bool add)
    {
        if(go->GetGOInfo()->displayId == 6785 || go->GetGOInfo()->displayId == 1287)
        {
            uint32 section = GetEruptionSection(go->GetPositionX(), go->GetPositionY());
            if(add)
                HeiganEruption[section].insert(go);
            else
                HeiganEruption[section].erase(go);
            return;
        }

        switch(go->GetEntry())
        {
            case 181200: SetBossRoomDoor(BOSS_NOTH, go, add); break;
            case 181201: SetBossPassageDoor(BOSS_NOTH, go, add); break;
            case 181202: SetBossRoomDoor(BOSS_HEIGAN, go, add); break;
            case 181203: SetBossPassageDoor(BOSS_HEIGAN, go, add); break;
            case 181241: SetBossRoomDoor(BOSS_LOATHEB, go, add); break;
            case GO_BIRTH: if(!add && Sapphiron) Sapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH); break;
        }
    }

    void SetData(uint32 id, uint32 value)
    {
        switch(id)
        {
            case DATA_HEIGAN_ERUPT:
                HeiganErupt(value);
                break;
        }
    }

    void HeiganErupt(uint32 section)
    {
        for(uint32 i = 0; i < 4; ++i)
        {
            if(i == section)
                continue;

            for(std::set<GameObject*>::iterator itr = HeiganEruption[i].begin(); itr != HeiganEruption[i].end(); ++itr)
            {
                (*itr)->SendCustomAnim();
                (*itr)->CastSpell(NULL, SPELL_ERUPTION);
            }
        }
    }
};

InstanceData* GetInstanceData_instance_naxxramas(Map* map)
{
    return new instance_naxxramas(map);
}

void AddSC_instance_naxxramas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_naxxramas";
    newscript->GetInstanceData = GetInstanceData_instance_naxxramas;
    newscript->RegisterSelf();
}
