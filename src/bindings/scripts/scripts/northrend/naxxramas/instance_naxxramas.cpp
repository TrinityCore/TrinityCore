/* Copyright (C) 2008 - 2009 Trinity <http://www.trinitycore.org/>
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

#include "precompiled.h"
#include "def_naxxramas.h"

const DoorData doorData[] =
{
    {181126,    BOSS_ANUBREKHAN,DOOR_TYPE_ROOM,     BOUNDARY_S},
    {181195,    BOSS_ANUBREKHAN,DOOR_TYPE_PASSAGE,  0},
    {194022,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE,  0},
    {181209,    BOSS_MAEXXNA,   DOOR_TYPE_ROOM,     BOUNDARY_SW},
    {181200,    BOSS_NOTH,      DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181201,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181202,    BOSS_NOTH,      DOOR_TYPE_PASSAGE,  0},
    {181202,    BOSS_HEIGAN,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181203,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  BOUNDARY_E},
    {181241,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE,  0},
    {181241,    BOSS_LOATHEB,   DOOR_TYPE_ROOM,     BOUNDARY_W},
    {181123,    BOSS_PATCHWERK, DOOR_TYPE_PASSAGE,  0},
    {181123,    BOSS_GROBBULUS, DOOR_TYPE_ROOM,     0},
    {181120,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  BOUNDARY_NW},
    {181121,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE,  0},
    {181121,    BOSS_THADDIUS,  DOOR_TYPE_ROOM,     0},
    {181124,    BOSS_RAZUVIOUS, DOOR_TYPE_PASSAGE,  0},
    {181124,    BOSS_GOTHIK,    DOOR_TYPE_ROOM,     BOUNDARY_N},
    {181125,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  BOUNDARY_S},
    {181119,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE,  0},
    {181119,    BOSS_HORSEMEN,  DOOR_TYPE_ROOM,     BOUNDARY_NE},
    {181225,    BOSS_SAPPHIRON, DOOR_TYPE_PASSAGE,  BOUNDARY_W},
    {0,         0,              DOOR_TYPE_ROOM,     0}, // EOF
};

const MinionData minionData[] =
{
    //{16573,     BOSS_ANUBREKHAN},     there is no spawn point in db, so we do not add them here
    {16506,     BOSS_FAERLINA},
    {16803,     BOSS_RAZUVIOUS},
    {16063,     BOSS_HORSEMEN},
    {16064,     BOSS_HORSEMEN},
    {16065,     BOSS_HORSEMEN},
    {30549,     BOSS_HORSEMEN},
    {0,         0,}
};

enum eEnums
{
    GO_HORSEMEN_CHEST_HERO  = 193426,
    GO_HORSEMEN_CHEST       = 181366,                   //four horsemen event, DoRespawnGameObject() when event == DONE
    GO_GOTHIK_GATE          = 181170,

    SPELL_ERUPTION          = 29371
};

const float HeiganPos[2] = {2796, -3707};
const float HeiganEruptionSlope[3] =
{
    (-3685 - HeiganPos[1]) /(2724 - HeiganPos[0]),
    (-3647 - HeiganPos[1]) /(2749 - HeiganPos[0]),
    (-3637 - HeiganPos[1]) /(2771 - HeiganPos[0]),
};

// 0  H      x
//  1        ^
//   2       |
//    3  y<--o
inline uint32 GetEruptionSection(float x, float y)
{
    y -= HeiganPos[1];
    if (y < 1.0f)
        return 0;

    x -= HeiganPos[0];
    if (x > -1.0f)
        return 3;

    float slope = y/x;
    for (uint32 i = 0; i < 3; ++i)
        if (slope > HeiganEruptionSlope[i])
            return i;
    return 3;
}

struct TRINITY_DLL_DECL instance_naxxramas : public InstanceData
{
    instance_naxxramas(Map* pMap) : InstanceData(pMap)
        , Sapphiron(NULL), pGothikGate(NULL), HorsemenChest(NULL), HorsemenNum(0)
    {
        SetBossNumber(MAX_BOSS_NUMBER);
        LoadDoorData(doorData);
        LoadMinionData(minionData);
    }

    std::set<GameObject*> HeiganEruption[4];
    GameObject* pGothikGate, *HorsemenChest;
    Creature* Sapphiron;
    uint32 HorsemenNum;

    void OnCreatureCreate(Creature* pCreature, bool add)
    {
        switch(pCreature->GetEntry())
        {
            case 15989: Sapphiron = add ? pCreature : NULL; return;
        }

        AddMinion(pCreature, add);
    }

    void OnGameObjectCreate(GameObject* pGo, bool add)
    {
        if (pGo->GetGOInfo()->displayId == 6785 || pGo->GetGOInfo()->displayId == 1287)
        {
            uint32 section = GetEruptionSection(pGo->GetPositionX(), pGo->GetPositionY());
            if (add)
                HeiganEruption[section].insert(pGo);
            else
                HeiganEruption[section].erase(pGo);
            return;
        }

        switch(pGo->GetEntry())
        {
            case GO_BIRTH: if (!add && Sapphiron) Sapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH); return;
            case GO_GOTHIK_GATE: pGothikGate = add ? pGo : NULL; break;
            case GO_HORSEMEN_CHEST: HorsemenChest = add ? pGo : NULL; break;
            case GO_HORSEMEN_CHEST_HERO: HorsemenChest = add ? pGo : NULL; break;
        }

        AddDoor(pGo, add);
    }

    void SetData(uint32 id, uint32 value)
    {
        switch(id)
        {
            case DATA_HEIGAN_ERUPT:
                HeiganErupt(value);
                break;
            case DATA_GOTHIK_GATE:
                if (pGothikGate)
                    pGothikGate->SetGoState(GOState(value));
                break;
        }
    }

    bool SetBossState(uint32 id, EncounterState state)
    {
        if (!InstanceData::SetBossState(id, state))
            return false;

        if (id == BOSS_HORSEMEN && state == DONE && HorsemenChest)
            HorsemenChest->SetRespawnTime(HorsemenChest->GetRespawnDelay());

        return true;
    }

    void HeiganErupt(uint32 section)
    {
        for (uint32 i = 0; i < 4; ++i)
        {
            if (i == section)
                continue;

            for (std::set<GameObject*>::iterator itr = HeiganEruption[i].begin(); itr != HeiganEruption[i].end(); ++itr)
            {
                (*itr)->SendCustomAnim();
                (*itr)->CastSpell(NULL, SPELL_ERUPTION);
            }
        }
    }
};

bool AreaTrigger_at_naxxramas_frostwyrm_wing(Player* pPlayer, AreaTriggerEntry *at)
{
    if (pPlayer->isGameMaster())
        return false;

    InstanceData *data = pPlayer->GetInstanceData();
    if (data)
        for (uint32 i = BOSS_ANUBREKHAN; i < BOSS_SAPPHIRON; ++i)
            if (data->GetBossState(i) != DONE)
                return true;

    return false;
}

InstanceData* GetInstanceData_instance_naxxramas(Map* pMap)
{
    return new instance_naxxramas(pMap);
}

void AddSC_instance_naxxramas()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "instance_naxxramas";
    newscript->GetInstanceData = &GetInstanceData_instance_naxxramas;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "at_naxxramas_frostwyrm_wing";
    newscript->pAreaTrigger = &AreaTrigger_at_naxxramas_frostwyrm_wing;
    newscript->RegisterSelf();
}
