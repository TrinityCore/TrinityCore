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
SDName: Thousand Needles
SD%Complete: 100
SDComment: Support for Quest: 4770, 1950
SDCategory: Thousand Needles
EndScriptData */

/* ContentData
npc_swiftmountain
npc_plucky
EndContentData */

#include "precompiled.h"
#include "../../npc/npc_escortAI.h"

/*#####
# npc_swiftmountain
######*/

#define SAY_READY -1000147
#define SAY_AGGRO -1000148
#define SAY_FINISH -1000149

#define QUEST_HOMEWARD_BOUND 4770
#define ENTRY_WYVERN 4107

struct TRINITY_DLL_DECL npc_swiftmountainAI : public npc_escortAI
{
npc_swiftmountainAI(Creature *c) : npc_escortAI(c) {}

    void WaypointReached(uint32 i)
    {
        Player* player = Unit::GetPlayer(PlayerGUID);

        if (!player)
            return;

        switch (i)
        {
        case 46:
            DoScriptText(SAY_AGGRO, m_creature, player);
            break;
         case 47:
            m_creature->SummonCreature(ENTRY_WYVERN, -5016.45, -935.01, -5.46, 5.36,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            m_creature->SummonCreature(ENTRY_WYVERN, -5001.98, -934.96, -5.55, 3.18,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            m_creature->SummonCreature(ENTRY_WYVERN, -4999.06, -949.61, -5.42, 2.04,TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
            break;
         case 70:
            DoScriptText(SAY_FINISH, m_creature, player);
            if (player && player->GetTypeId() == TYPEID_PLAYER)
                ((Player*)player)->GroupEventHappens(QUEST_HOMEWARD_BOUND,m_creature);
            break;

        }
    }

    void Reset()
    {
        m_creature->setFaction(104);
    }

    void EnterCombat(Unit* who){}

    void JustSummoned(Creature* summoned)
    {
        summoned->AI()->AttackStart(m_creature);
    }

    void JustDied(Unit* killer)
    {
        if (PlayerGUID)
        {
            if (Player* player = Unit::GetPlayer(PlayerGUID))
                ((Player*)player)->FailQuest(QUEST_HOMEWARD_BOUND);
        }
    }

    void UpdateAI(const uint32 diff)
    {
        npc_escortAI::UpdateAI(diff);
    }
};

bool QuestAccept_npc_swiftmountain(Player* player, Creature* creature, Quest const* quest)
{
    if (quest->GetQuestId() == QUEST_HOMEWARD_BOUND)
    {
        ((npc_escortAI*)(creature->AI()))->Start(true, true, false, player->GetGUID());
        DoScriptText(SAY_READY, creature, player);
        creature->setFaction(113);
    }

    return true;
}

CreatureAI* GetAI_npc_swiftmountain(Creature *_Creature)
{
    npc_swiftmountainAI* thisAI = new npc_swiftmountainAI(_Creature);

   thisAI->AddWaypoint(0, -5156.69, -1220.49, 48.78, 5000);
   thisAI->AddWaypoint(1, -5157.12, -1220.13, 48.67);
   thisAI->AddWaypoint(2, -5171.7, -1205.36, 47.43);
   thisAI->AddWaypoint(3, -5174.08, -1197.7, 46.90);
   thisAI->AddWaypoint(4, -5178.24, -1183.78, 45.97);
   thisAI->AddWaypoint(5, -5181.52, -1171.03, 45.29);
   thisAI->AddWaypoint(6, -5184.29, -1159.21, 44.62);
   thisAI->AddWaypoint(7, -5184.84, -1152.95, 44.84);
   thisAI->AddWaypoint(8, -5182.04, -1142.83, 44.07);
   thisAI->AddWaypoint(9, -5178.44, -1133.57, 43.91);
   thisAI->AddWaypoint(10, -5176.68, -1129.48, 43.81);
   thisAI->AddWaypoint(11, -5164.85, -1123.33, 43.99);
   thisAI->AddWaypoint(12, -5153.07, -1117.7, 43.66);
   thisAI->AddWaypoint(13, -5143.52, -1113.14, 43.78);
   thisAI->AddWaypoint(14, -5135.86, -1104.42, 47.23);
   thisAI->AddWaypoint(15, -5129.86, -1097.22, 49.52);
   thisAI->AddWaypoint(16, -5127.48, -1087.29, 49.03);
   thisAI->AddWaypoint(17, -5127.57, -1080.4, 46.64);
   thisAI->AddWaypoint(18, -5129.65, -1077.58, 45.29);
   thisAI->AddWaypoint(19, -5135.86, -1069.12, 39.53);
   thisAI->AddWaypoint(20, -5141.97, -1060.58, 32.70);
   thisAI->AddWaypoint(21, -5145.99, -1054.85, 28.98);
   thisAI->AddWaypoint(22, -5147.08, -1050.35, 26.36);
   thisAI->AddWaypoint(23, -5147.5, -1043.37, 21.84);
   thisAI->AddWaypoint(24, -5147.68, -1036.37, 17.05);
   thisAI->AddWaypoint(25, -5147.68, -1029.37, 14.59);
   thisAI->AddWaypoint(26, -5144.62, -1023.9, 11.67);
   thisAI->AddWaypoint(27, -5138.67, -1020.23, 7.81);
   thisAI->AddWaypoint(28, -5135.6, -1018.55, 6.19);
   thisAI->AddWaypoint(29, -5126.25, -1014.76, 1.08);
   thisAI->AddWaypoint(30, -5120.03, -1013.12, -1.11);
   thisAI->AddWaypoint(31, -5112.3, -1027.65, -5.39);
   thisAI->AddWaypoint(32, -5106.99, -1023.09, -5.10);
   thisAI->AddWaypoint(33, -5099.07, -1016.19, -4.92);
   thisAI->AddWaypoint(34, -5091.23, -1009.21, -5.22);
   thisAI->AddWaypoint(35, -5083.62, -1001.97, -5.22);
   thisAI->AddWaypoint(36, -5076.1, -994.652, -4.92);
   thisAI->AddWaypoint(37, -5066.71, -985.507, -4.97);
   thisAI->AddWaypoint(38, -5065.13, -978.689, -5.02);
   thisAI->AddWaypoint(39, -5062.33, -968.57, -5.08);
   thisAI->AddWaypoint(40, -5059.46, -958.469, -5.16);
   thisAI->AddWaypoint(41, -5056.59, -948.375, -5.10);
   thisAI->AddWaypoint(42, -5053.73, -938.274, -5.69);
   thisAI->AddWaypoint(43, -5043.06, -934.822, -5.35);
   thisAI->AddWaypoint(44, -5029.35, -932.007, -5.27);
   thisAI->AddWaypoint(45, -5024.58, -933.781, -5.40);
   thisAI->AddWaypoint(46, -5019.13, -938.172, -5.54);
   thisAI->AddWaypoint(47, -5011, -944.812, -5.47);
   thisAI->AddWaypoint(48, -5002.86, -951.455, -5.44);
   thisAI->AddWaypoint(49, -4994.73, -958.099, -5.41);
   thisAI->AddWaypoint(50, -4990.57, -963.782, -5.33);
   thisAI->AddWaypoint(51, -4987.43, -970.041, -5.17);
   thisAI->AddWaypoint(52, -4981.41, -982.678, -5.10);
   thisAI->AddWaypoint(53, -4977.03, -992.221, -4.97);
   thisAI->AddWaypoint(54, -4972.6, -1001.74, -5.24);
   thisAI->AddWaypoint(55, -4968.15, -1011.25, -5.49);
   thisAI->AddWaypoint(56, -4963.75, -1020.78, -5.07);
   thisAI->AddWaypoint(57, -4959.3, -1030.3, -5.28);
   thisAI->AddWaypoint(58, -4956.28, -1036.61, -5.84);
   thisAI->AddWaypoint(59, -4952.05, -1043.75, -9.04);
   thisAI->AddWaypoint(60, -4943.8, -1055.06, -17.91);
   thisAI->AddWaypoint(61, -4939.47, -1055.61, -20.73);
   thisAI->AddWaypoint(62, -4929.16, -1053.64, -25.65);
   thisAI->AddWaypoint(63, -4922.28, -1052.37, -28.72);
   thisAI->AddWaypoint(64, -4913.26, -1051.3, -31.80);
   thisAI->AddWaypoint(65, -4903.54, -1054.17, -33.48);
   thisAI->AddWaypoint(66, -4905.95, -1056.71, -33.68);
   thisAI->AddWaypoint(67, -4913.18, -1064.32, -39.46);
   thisAI->AddWaypoint(68, -4925.27, -1076.98, -47.39);
   thisAI->AddWaypoint(69, -4932.68, -1084.42, -51.00);
   thisAI->AddWaypoint(70, -4938.3, -1100.41, -50.71, 5000);
   thisAI->AddWaypoint(71, -4937.34, -1102.87, -49.82);

    return (CreatureAI*)thisAI;
}

/*#####
# npc_plucky
######*/

#define GOSSIP_P    "<Learn Secret phrase>"

#define SPELL_TRANSFORM_HUMAN 9192
#define QUEST_GET_THE_SCOOP 1950

struct TRINITY_DLL_DECL npc_pluckyAI : public ScriptedAI
{
    npc_pluckyAI(Creature *c) : ScriptedAI(c) {}

    bool Transformed;
    bool Chicken;

    uint32 Timer;
    uint32 ChickenTimer;

    void Reset()   {

       Transformed = false;
       Chicken     = false;
       m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
       Timer        = 0;
       ChickenTimer = 0;
       }

    void EnterCombat(Unit *who){}

    void TransformHuman(uint32 emoteid)
    {
         if (!Transformed)
         {
             Transformed = true;
             DoCast(m_creature, SPELL_TRANSFORM_HUMAN);
             Timer = 120000;
             if (emoteid == TEXTEMOTE_BECKON)
                 m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
             else
             {
                 ChickenTimer = 1500;
                 Chicken = true;
             }
         }
    }

    void UpdateAI(const uint32 diff)
    {
        if (Transformed)
        {
            if (Timer < diff)
                Reset();
            else Timer-=diff;
        }

       if(Chicken)
       {
           if (ChickenTimer < diff)
           {
               m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
               Chicken = false;
           }else ChickenTimer-=diff;
       }

        if(!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
   }

    void ReceiveEmote( Player *player, uint32 emote )
    {
        if( (emote == TEXTEMOTE_BECKON || emote == TEXTEMOTE_CHICKEN &&
            player->GetQuestStatus(QUEST_GET_THE_SCOOP) == QUEST_STATUS_INCOMPLETE) )
        {
            m_creature->SetInFront(player);
            TransformHuman(emote);
        }
    }
};

bool GossipHello_npc_plucky(Player *player, Creature *_Creature)
{
    if(player->GetQuestStatus(QUEST_GET_THE_SCOOP) == QUEST_STATUS_INCOMPLETE)
        player->ADD_GOSSIP_ITEM(0, GOSSIP_P, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    player->SEND_GOSSIP_MENU(738, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_plucky(Player *player, Creature *_Creature, uint32 sender, uint32 action)
{
    switch( action )
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->CLOSE_GOSSIP_MENU();
            player->CompleteQuest(QUEST_GET_THE_SCOOP);
        break;
    }
    return true;
}

CreatureAI* GetAI_npc_plucky(Creature *_Creature)
{
return new npc_pluckyAI(_Creature);
}

/*#####
#
######*/

void AddSC_thousand_needles()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_swiftmountain";
    newscript->GetAI = &GetAI_npc_swiftmountain;
    newscript->pQuestAccept = &QuestAccept_npc_swiftmountain;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_plucky";
    newscript->GetAI = &GetAI_npc_plucky;
    newscript->pGossipHello =   &GossipHello_npc_plucky;
    newscript->pGossipSelect = &GossipSelect_npc_plucky;
    newscript->RegisterSelf();
}

