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
    {181126,    BOSS_ANUBREKHAN,DOOR_TYPE_ROOM},
    {181195,    BOSS_ANUBREKHAN,DOOR_TYPE_PASSAGE},
    {194022,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE},
    {181209,    BOSS_FAERLINA,  DOOR_TYPE_PASSAGE},
    {181209,    BOSS_MAEXXNA,   DOOR_TYPE_ROOM},
    {181200,    BOSS_NOTH,      DOOR_TYPE_ROOM},
    {181201,    BOSS_NOTH,      DOOR_TYPE_PASSAGE},
    {181202,    BOSS_NOTH,      DOOR_TYPE_PASSAGE},
    {181202,    BOSS_HEIGAN,    DOOR_TYPE_ROOM},
    {181203,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE},
    {181241,    BOSS_HEIGAN,    DOOR_TYPE_PASSAGE},
    {181241,    BOSS_LOATHEB,   DOOR_TYPE_ROOM},
    {181123,    BOSS_PATCHWERK, DOOR_TYPE_PASSAGE},
    {181123,    BOSS_GROBBULUS, DOOR_TYPE_ROOM},
    {181120,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE},
    {181121,    BOSS_GLUTH,     DOOR_TYPE_PASSAGE},
    {181121,    BOSS_THADDIUS,  DOOR_TYPE_ROOM},
    {181124,    BOSS_RAZUVIOUS, DOOR_TYPE_PASSAGE},
    {181124,    BOSS_GOTHIK,    DOOR_TYPE_ROOM},
    {181125,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE},
    {181119,    BOSS_GOTHIK,    DOOR_TYPE_PASSAGE},
    {181119,    BOSS_HORSEMEN,  DOOR_TYPE_ROOM},
    {0,         0,              DOOR_TYPE_ROOM}, // EOF
};

#define GO_GOTHIK_GATE      181170

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

struct TRINITY_DLL_DECL instance_naxxramas : public InstanceData
{
    instance_naxxramas(Map *map) : InstanceData(map)
        , Sapphiron(NULL)
    {
        SetBossNumber(MAX_BOSS_NUMBER);
        LoadDoorData(doorData);
    }

    std::set<GameObject*> HeiganEruption[4];
    Creature *Sapphiron;
    std::set<Creature*> Worshipper;

    void OnCreatureCreate(Creature *creature, bool add)
    {
        switch(creature->GetEntry())
        {
            case 15989: Sapphiron = add ? creature : NULL; break;
            case 16506: if(add) Worshipper.insert(creature); else Worshipper.erase(creature); break;
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
            case GO_BIRTH: if(!add && Sapphiron) Sapphiron->AI()->DoAction(DATA_SAPPHIRON_BIRTH); return;
        }

        AddDoor(go, add);
    }

    void SetBossState(uint32 id, EncounterState state)
    {
        InstanceData::SetBossState(id, state);
        switch(id)
        {
            case BOSS_FAERLINA:
                if(state == NOT_STARTED)
                    for(std::set<Creature*>::iterator itr = Worshipper.begin(); itr != Worshipper.end(); ++itr)
                        if(!(*itr)->isAlive())
                            (*itr)->Respawn();
            break;
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
    newscript->GetInstanceData = &GetInstanceData_instance_naxxramas;
    newscript->RegisterSelf();
}
