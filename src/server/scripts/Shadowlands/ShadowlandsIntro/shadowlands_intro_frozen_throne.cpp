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

    bool GossipHello(Player* player) override
    {
        AddGossipItemFor(player, GOSSIP_ICON_CHAT, "Tell me what happened.", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 0);
        SendGossipMenuFor(player, 41731, me->GetGUID());
        player->PrepareQuestMenu(me->GetGUID());

        return true;
    }

    bool GossipSelect(Player* player, uint32 /*menuId*/, uint32 /*gossipListId*/) override
    {
        if (player->GetQuestStatus(QUEST_CHILLING_SUMMONS_A) == QUEST_STATUS_INCOMPLETE || player->GetQuestStatus(QUEST_CHILLING_SUMMONS_H) == QUEST_STATUS_INCOMPLETE)
        {
            player->KilledMonsterCredit(173229);
            player->KilledMonsterCredit(171789);
            player->KilledMonsterCredit(170749);
            player->ForceCompleteQuest(QUEST_CHILLING_SUMMONS_A);
            player->ForceCompleteQuest(QUEST_CHILLING_SUMMONS_H);
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

   // void QuestAccept(Player * player, Quest const* quest)
   // {
     //   if (quest->/*quest*/ == QUEST_THROUGH_SHATTERED_SKY)
       // {
         //   player->KilledMonsterCredit(me->GetEntry());
          //  player->ForceCompleteQuest(QUEST_THROUGH_SHATTERED_SKY);
           // player->TeleportTo(2364, 4146.165f, 7870.028f, 4970.662f, 5.572f);
       // }
   // }
};

void AddSC_ShadowlandsIntro()
{
    RegisterCreatureAI(npc_chilling_summons_commander);
    RegisterCreatureAI(npc_deathbringer_rise_teleport_controller);
    RegisterCreatureAI(npc_highlord_bolvar_fordragon_169076);
}

//player->npc_highlord_bolvar_fordragon_169076::ForceCompleteQuest(QUEST_THROUGH_SHATTERED_SKY)
//{
 //   return player ->();
//}
