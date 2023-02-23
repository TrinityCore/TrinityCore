/*
 * Copyright 2023 AzgathCore
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

#include "ScriptMgr.h"
#include "ScriptedGossip.h"

enum ShadowLandsIntro
{
	QUEST_CHILLING_SUMMONS_A = 60545,
	QUEST_CHILLING_SUMMONS_H = 61874,
	QUEST_THROUGH_SHATTERED_SKY = 59751,    
};

//171789,171791
struct npc_chilling_summons_commander : public ScriptedAI
{
    npc_chilling_summons_commander(Creature* c) : ScriptedAI(c) { }

    bool GossipHello(Player* player)
    {
        SendGossipMenuFor(player, 41731, me->GetGUID());
        player->PrepareQuestMenu(me->GetGUID());

        return true;
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/)
    {
        if (player->GetQuestStatus(QUEST_CHILLING_SUMMONS_A) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_CHILLING_SUMMONS_H) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(173229);
            player->KilledMonsterCredit(171789);
            player->KilledMonsterCredit(170749);
            //player->ForceCompleteQuest(QUEST_CHILLING_SUMMONS_A);//tmp
            //player->ForceCompleteQuest(QUEST_CHILLING_SUMMONS_H);//tmp
            player->TeleportTo(2147, -633.468f, 2210.952f, 550.705f, 0.09f);
        }

        return true;
    }
};

//115634
struct npc_deathbringer_rise_teleport_controller : public ScriptedAI
{
    npc_deathbringer_rise_teleport_controller(Creature* c) : ScriptedAI(c) { }

    void MoveInLineOfSight(Unit* target) override
    {
        if (!target->IsPlayer())
            return;

        if (target->GetDistance2d(me) <= 6.0f)
            if (Player* player = target->ToPlayer())
                player->TeleportTo(2147, 559.735f, -2125.220f, 840.856f, 3.176f, false);
    }
};

//169076
struct npc_highlord_bolvar_fordragon_169076 : public ScriptedAI
{
    npc_highlord_bolvar_fordragon_169076(Creature* c) : ScriptedAI(c) { }

    void QuestAccept(Player * /*player*/, Quest const* /*quest*/)
    {
    }
};

void AddSC_ShadowlandsIntro()
{
    RegisterCreatureAI(npc_chilling_summons_commander);
    RegisterCreatureAI(npc_deathbringer_rise_teleport_controller);
    RegisterCreatureAI(npc_highlord_bolvar_fordragon_169076);
}
