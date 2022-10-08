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

#include "ScriptMgr.h"
#include "ObjectMgr.h"
#include "PhasingHandler.h"
#include "GameObject.h"
#include "ScriptedGossip.h"
#include "Log.h"

 // 92909 LORD_MAXWELL_TYROSUS
enum
{
    QUEST_AN_URGENT_GATHERING = 38710,
    NPC_LORD_MAXWELL_TYROSUS = 92909,
    QUEST_An_Urgent_Gathering = 38710,
    QUEST_The_End_of_the_Saga = 42005,
    QUEST_SHRINE_OF_THE_TRUTHGUARD = 42017,
};

struct npc_npc_lord_maxwell_tyrosus_92909 : public ScriptedAI
{
    npc_npc_lord_maxwell_tyrosus_92909(Creature* creature) : ScriptedAI(creature) { Casting = false; }

    void Reset() override { }

    void MoveInLineOfSight(Unit* who) override
    {
        if (!who || !who->IsInWorld())
            return;
        if (!me->IsWithinDist(who, 25.0f, false))
            return;

        Player* player = who->GetCharmerOrOwnerPlayerOrPlayerItself();

        if (!player)
            return;
        me->GetMotionMaster()->MoveFollow(player, PET_FOLLOW_DIST, me->GetFollowAngle());

        if (!Casting)
        {
            if (player->HasQuest(QUEST_AN_URGENT_GATHERING)) {
                Casting = true;
                me->DespawnOrUnsummon(5000);
            }
        }
    }
    void UpdateAI(uint32 /*diff*/) override { }
    bool Casting;
};

struct npc_travard_108692 : public ScriptedAI
{
    npc_travard_108692(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        TC_LOG_ERROR("server.worldserver", "sGossipSelect %u, %u", menuId, gossipListId);
        if (player->HasQuest(QUEST_An_Urgent_Gathering))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(108692);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }
};

struct npc_orik_trueheart_108693 : public ScriptedAI
{
    npc_orik_trueheart_108693(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        TC_LOG_ERROR("server.worldserver", "sGossipSelect %u, %u", menuId, gossipListId);
        if (player->HasQuest(QUEST_An_Urgent_Gathering))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(108693);
                CloseGossipMenuFor(player);
                Talk(0);
            }
        }
    }
};

struct npc_tahu_sagewind_105727 : public ScriptedAI
{
    npc_tahu_sagewind_105727(Creature* creature) : ScriptedAI(creature) {  }

    void sGossipSelect(Player* player, uint32 menuId, uint32 gossipListId)
    {
        if (player->HasQuest(QUEST_The_End_of_the_Saga))
        {
            if (gossipListId == 0)
            {
                player->KilledMonsterCredit(108669);
                CloseGossipMenuFor(player);
            }
        }
    }
};

//250364/broken-sword
class go_broken_sword_250364 : public GameObjectScript
{
public:
    go_broken_sword_250364() : GameObjectScript("go_broken_sword_250364") { }

    bool OnGossipHello(Player* player, GameObject* go) override
    {
        if (Creature* cow = go->SummonCreature(107314, go->GetRandomNearPosition(10.0f), TEMPSUMMON_TIMED_DESPAWN, 10000))
            cow->AI()->Talk(1);
        go->SummonCreature(107329, go->GetRandomNearPosition(10.0f), TEMPSUMMON_DEAD_DESPAWN, WEEK);
        player->KilledMonsterCredit(113914);
        return false;
    }
};

struct npc_orik_trueheart_105813 : public ScriptedAI
{
    npc_orik_trueheart_105813(Creature* creature) : ScriptedAI(creature) {  }

    void sQuestAccept(Player* player, Quest const* quest) override
    {
        if (quest->GetQuestId() == QUEST_SHRINE_OF_THE_TRUTHGUARD)
        {
            Talk(0);
            if (Creature* bird = me->FindNearestCreature(105886, 50.0f, true))
                bird->AddNpcFlag(UNIT_NPC_FLAG_SPELLCLICK);
        }
    }
};

struct npc_argent_hippogryph_105886 : public ScriptedAI
{
    npc_argent_hippogryph_105886(Creature* creature) : ScriptedAI(creature) { }

    void OnSpellClick(Unit* clicker, bool& /*result*/)
    {
        if (Player* player = clicker->ToPlayer())
        {
            if (player->GetQuestStatus(QUEST_SHRINE_OF_THE_TRUTHGUARD) == QUEST_STATUS_INCOMPLETE)
            {
                player->KilledMonsterCredit(105889);
                player->TeleportTo(1495, Position(4762.8178f, 62.2226f, -0.83612f));
            }
        }
    }
};

void AddSC_class_hall_paladin()
{
    RegisterCreatureAI(npc_npc_lord_maxwell_tyrosus_92909);
    RegisterCreatureAI(npc_travard_108692);
    RegisterCreatureAI(npc_orik_trueheart_108693);
    RegisterCreatureAI(npc_tahu_sagewind_105727);
    new go_broken_sword_250364();
    RegisterCreatureAI(npc_orik_trueheart_105813);
    RegisterCreatureAI(npc_argent_hippogryph_105886);
}
