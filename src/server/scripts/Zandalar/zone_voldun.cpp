/*
 * Copyright (C) 2022 BfaCore Reforged
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

 //Missing scripts

#include "Creature.h"
#include "GameObject.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "QuestPackets.h"
#include "ScenePackets.h"
#include "SceneMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "TemporarySummon.h"
#include "WorldSession.h"
#include "PhasingHandler.h"
#include "Conversation.h"
#include "GameObjectAI.h"

enum MardumQuests
{
    QUEST_SEARCHING_THE_RUINS = 47716
};

struct npc_voldun_julwaba : public ScriptedAI
{
    npc_voldun_julwaba(Creature* creature) : ScriptedAI(creature) { }

    void MoveInLineOfSight(Unit* unit) override
    {
        if (Player* player = unit->ToPlayer())
            if (player->GetDistance(me) < 5.0f)
                if (!player->GetQuestObjectiveData(QUEST_SEARCHING_THE_RUINS, 0))
                    player->KilledMonsterCredit(me->GetEntry());
    }
};

void AddSC_zone_voldun()
{
    RegisterCreatureAI(npc_voldun_julwaba);
}
