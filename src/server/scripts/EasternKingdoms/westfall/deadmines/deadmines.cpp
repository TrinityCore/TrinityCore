/* Copyright (C) 2006 - 2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Deadmines
SD%Complete: 90
SDComment: Contains GO for event at end door
SDCategory: Deadmines
EndScriptData */

#include "scriptPCH.h"
#include "deadmines.h"

bool GOHello_go_door_lever_dm(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if (!pInstance)
        return false;

    GameObject* pGoDoor = pInstance->instance->GetGameObject(pInstance->GetData64(DATA_DEFIAS_DOOR));

    return !(pGoDoor && pGoDoor->GetGoState() == 1);
}

bool GOHello_go_defias_cannon(Player* pPlayer, GameObject* pGo)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if (!pInstance)
        return false;

    if (pInstance->GetData(TYPE_DEFIAS_ENDDOOR) == DONE || pInstance->GetData(TYPE_DEFIAS_ENDDOOR) == IN_PROGRESS)
        return false;

    pInstance->SetData(TYPE_DEFIAS_ENDDOOR, IN_PROGRESS);
    return false;
}

bool GOHello_go_defias_gunpowder(Player* player, GameObject* pGo)
{
    ScriptedInstance* pInstance = (ScriptedInstance*)pGo->GetInstanceData();

    if (!pInstance)
        return false;

    if (pInstance->GetData(GUN_POWDER_EVENT) == 0)
    {
        Creature* pirate3;
        if (pirate3 = pGo->SummonCreature(634, -131.290833f, -591.243103f, 18.077190f, 4.792192f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 310000))//DEFIAS_OVERSEER
        {
            pirate3->GetMotionMaster()->MovePoint(0, -128.925980f, -616.494629f, 13.532340f, MOVE_PATHFINDING, 0, 6.269623f);
            pirate3->SetRespawnDelay(350000);
        }
        pInstance->SetData(GUN_POWDER_EVENT, 1);
    }
    return true;
}

struct go_defias_gunpowderAI: public GameObjectAI
{
    go_defias_gunpowderAI(GameObject* go) : GameObjectAI(go) {}

    void SummonedMovementInform(Creature* summoned, uint32 motion_type, uint32 point_id) override
    {
        if (motion_type == POINT_MOTION_TYPE)
        {
            if (point_id == 0)
                summoned->GetMotionMaster()->MovePoint(1, -115.263672f, -617.396118f, 13.579387f, MOVE_PATHFINDING, 0, 6.182347f);
            else if (point_id == 1)
                summoned->SetHomePosition(-115.263672f, -617.396118f, 13.579387f, 6.182347f);
        }
    }
};

GameObjectAI* GetAIgo_defias_gunpowder(GameObject *go)
{
    return new go_defias_gunpowderAI(go);
}

void AddSC_deadmines()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "go_door_lever_dm";
    newscript->pGOHello = &GOHello_go_door_lever_dm;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_defias_cannon";
    newscript->pGOHello = &GOHello_go_defias_cannon;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "go_defias_gunpowder";
    newscript->pGOHello = &GOHello_go_defias_gunpowder;
    newscript->GOGetAI = &GetAIgo_defias_gunpowder;
    newscript->RegisterSelf();
}
