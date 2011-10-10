/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

/* ScriptData
SDName: Tanaris
SD%Complete: 80
SDComment: Quest support: 648, 1560, 2954, 4005, 10277, 10279(Special flight path). Noggenfogger vendor
SDCategory: Tanaris
EndScriptData */

/* ContentData
mob_aquementas
npc_custodian_of_time
npc_marin_noggenfogger
npc_steward_of_time
npc_stone_watcher_of_norgannon
npc_OOX17
npc_tooga
EndContentData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"
#include "ScriptedFollowerAI.h"

/*######
## mob_aquementas
######*/

#define AGGRO_YELL_AQUE     -1000350

#define SPELL_AQUA_JET      13586
#define SPELL_FROST_SHOCK   15089

class mob_aquementas : public CreatureScript
{
public:
    mob_aquementas() : CreatureScript("mob_aquementas") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_aquementasAI (creature);
    }

    struct mob_aquementasAI : public ScriptedAI
    {
        mob_aquementasAI(Creature* c) : ScriptedAI(c) {}

        uint32 SendItem_Timer;
        uint32 SwitchFaction_Timer;
        bool isFriendly;

        uint32 FrostShock_Timer;
        uint32 AquaJet_Timer;

        void Reset()
        {
            SendItem_Timer = 0;
            SwitchFaction_Timer = 10000;
            me->setFaction(35);
            isFriendly = true;

            AquaJet_Timer = 5000;
            FrostShock_Timer = 1000;
        }

        void SendItem(Unit* receiver)
        {
            if (CAST_PLR(receiver)->HasItemCount(11169, 1, false) &&
                CAST_PLR(receiver)->HasItemCount(11172, 11, false) &&
                CAST_PLR(receiver)->HasItemCount(11173, 1, false) &&
                !CAST_PLR(receiver)->HasItemCount(11522, 1, true))
            {
                ItemPosCountVec dest;
                uint8 msg = CAST_PLR(receiver)->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, 11522, 1, NULL);
                if (msg == EQUIP_ERR_OK)
                    CAST_PLR(receiver)->StoreNewItem(dest, 11522, 1, true);
            }
        }

        void EnterCombat(Unit* who)
        {
            DoScriptText(AGGRO_YELL_AQUE, me, who);
        }

        void UpdateAI(const uint32 diff)
        {
            if (isFriendly)
            {
                if (SwitchFaction_Timer <= diff)
                {
                    me->setFaction(91);
                    isFriendly = false;
                } else SwitchFaction_Timer -= diff;
            }

            if (!UpdateVictim())
                return;

            if (!isFriendly)
            {
                if (SendItem_Timer <= diff)
                {
                    if (me->getVictim()->GetTypeId() == TYPEID_PLAYER)
                        SendItem(me->getVictim());
                    SendItem_Timer = 5000;
                } else SendItem_Timer -= diff;
            }

            if (FrostShock_Timer <= diff)
            {
                DoCast(me->getVictim(), SPELL_FROST_SHOCK);
                FrostShock_Timer = 15000;
            } else FrostShock_Timer -= diff;

            if (AquaJet_Timer <= diff)
            {
                DoCast(me, SPELL_AQUA_JET);
                AquaJet_Timer = 15000;
            } else AquaJet_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_custodian_of_time
######*/

#define WHISPER_CUSTODIAN_1     -1000217
#define WHISPER_CUSTODIAN_2     -1000218
#define WHISPER_CUSTODIAN_3     -1000219
#define WHISPER_CUSTODIAN_4     -1000220
#define WHISPER_CUSTODIAN_5     -1000221
#define WHISPER_CUSTODIAN_6     -1000222
#define WHISPER_CUSTODIAN_7     -1000223
#define WHISPER_CUSTODIAN_8     -1000224
#define WHISPER_CUSTODIAN_9     -1000225
#define WHISPER_CUSTODIAN_10    -1000226
#define WHISPER_CUSTODIAN_11    -1000227
#define WHISPER_CUSTODIAN_12    -1000228
#define WHISPER_CUSTODIAN_13    -1000229
#define WHISPER_CUSTODIAN_14    -1000230

class npc_custodian_of_time : public CreatureScript
{
public:
    npc_custodian_of_time() : CreatureScript("npc_custodian_of_time") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_custodian_of_timeAI(creature);
    }

    struct npc_custodian_of_timeAI : public npc_escortAI
    {
        npc_custodian_of_timeAI(Creature* c) : npc_escortAI(c) {}

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();
            if (!player)
                return;

            switch (i)
            {
                case 0: DoScriptText(WHISPER_CUSTODIAN_1, me, player); break;
                case 1: DoScriptText(WHISPER_CUSTODIAN_2, me, player); break;
                case 2: DoScriptText(WHISPER_CUSTODIAN_3, me, player); break;
                case 3: DoScriptText(WHISPER_CUSTODIAN_4, me, player); break;
                case 5: DoScriptText(WHISPER_CUSTODIAN_5, me, player); break;
                case 6: DoScriptText(WHISPER_CUSTODIAN_6, me, player); break;
                case 7: DoScriptText(WHISPER_CUSTODIAN_7, me, player); break;
                case 8: DoScriptText(WHISPER_CUSTODIAN_8, me, player); break;
                case 9: DoScriptText(WHISPER_CUSTODIAN_9, me, player); break;
                case 10: DoScriptText(WHISPER_CUSTODIAN_4, me, player); break;
                case 13: DoScriptText(WHISPER_CUSTODIAN_10, me, player); break;
                case 14: DoScriptText(WHISPER_CUSTODIAN_4, me, player); break;
                case 16: DoScriptText(WHISPER_CUSTODIAN_11, me, player); break;
                case 17: DoScriptText(WHISPER_CUSTODIAN_12, me, player); break;
                case 18: DoScriptText(WHISPER_CUSTODIAN_4, me, player); break;
                case 22: DoScriptText(WHISPER_CUSTODIAN_13, me, player); break;
                case 23: DoScriptText(WHISPER_CUSTODIAN_4, me, player); break;
                case 24:
                    DoScriptText(WHISPER_CUSTODIAN_14, me, player);
                    DoCast(player, 34883);
                    // below here is temporary workaround, to be removed when spell works properly
                    player->AreaExploredOrEventHappens(10277);
                    break;
            }
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (HasEscortState(STATE_ESCORT_ESCORTING))
                return;

            if (who->GetTypeId() == TYPEID_PLAYER)
            {
                if (who->HasAura(34877) && CAST_PLR(who)->GetQuestStatus(10277) == QUEST_STATUS_INCOMPLETE)
                {
                    float Radius = 10.0f;
                    if (me->IsWithinDistInMap(who, Radius))
                    {
                        Start(false, false, who->GetGUID());
                    }
                }
            }
        }

        void EnterCombat(Unit* /*who*/) {}
        void Reset() { }

        void UpdateAI(const uint32 diff)
        {
            npc_escortAI::UpdateAI(diff);
        }
    };

};

/*######
## npc_marin_noggenfogger
######*/

class npc_marin_noggenfogger : public CreatureScript
{
public:
    npc_marin_noggenfogger() : CreatureScript("npc_marin_noggenfogger") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_TRADE)
            player->GetSession()->SendListInventory(creature->GetGUID());

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (creature->isVendor() && player->GetQuestRewardStatus(2662))
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }

};

/*######
## npc_steward_of_time
######*/

#define GOSSIP_ITEM_FLIGHT  "Please take me to the master's lair."

class npc_steward_of_time : public CreatureScript
{
public:
    npc_steward_of_time() : CreatureScript("npc_steward_of_time") { }

    bool OnQuestAccept(Player* player, Creature* /*creature*/, Quest const* quest)
    {
        if (quest->GetQuestId() == 10279)                      //Quest: To The Master's Lair
            player->CastSpell(player, 34891, true);               //(Flight through Caverns)

        return false;
    }

    bool OnGossipSelect(Player* player, Creature* /*creature*/, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1)
            player->CastSpell(player, 34891, true);               //(Flight through Caverns)

        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(10279) == QUEST_STATUS_INCOMPLETE || player->GetQuestRewardStatus(10279))
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_FLIGHT, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(9978, creature->GetGUID());
        }
        else
            player->SEND_GOSSIP_MENU(9977, creature->GetGUID());

        return true;
    }

};

/*######
## npc_stone_watcher_of_norgannon
######*/

#define GOSSIP_ITEM_NORGANNON_1     "What function do you serve?"
#define GOSSIP_ITEM_NORGANNON_2     "What are the Plates of Uldum?"
#define GOSSIP_ITEM_NORGANNON_3     "Where are the Plates of Uldum?"
#define GOSSIP_ITEM_NORGANNON_4     "Excuse me? We've been \"reschedueled for visitations\"? What does that mean?!"
#define GOSSIP_ITEM_NORGANNON_5     "So, what's inside Uldum?"
#define GOSSIP_ITEM_NORGANNON_6     "I will return when i have the Plates of Uldum."

class npc_stone_watcher_of_norgannon : public CreatureScript
{
public:
    npc_stone_watcher_of_norgannon() : CreatureScript("npc_stone_watcher_of_norgannon") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
                player->SEND_GOSSIP_MENU(1675, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+1:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
                player->SEND_GOSSIP_MENU(1676, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
                player->SEND_GOSSIP_MENU(1677, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+3:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+4);
                player->SEND_GOSSIP_MENU(1678, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+4:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+5);
                player->SEND_GOSSIP_MENU(1679, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+5:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(2954);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(2954) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_NORGANNON_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF);

        player->SEND_GOSSIP_MENU(1674, creature->GetGUID());

        return true;
    }

};

/*######
## npc_OOX17
######*/

enum e00X17
{
    //texts are signed for 7806
    SAY_OOX_START           = -1000287,
    SAY_OOX_AGGRO1          = -1000288,
    SAY_OOX_AGGRO2          = -1000289,
    SAY_OOX_AMBUSH          = -1000290,
    SAY_OOX17_AMBUSH_REPLY  = -1000291,
    SAY_OOX_END             = -1000292,

    Q_OOX17                 = 648,
    SPAWN_FIRST             = 7803,
    SPAWN_SECOND_1          = 5617,
    SPAWN_SECOND_2          = 7805
};

class npc_OOX17 : public CreatureScript
{
public:
    npc_OOX17() : CreatureScript("npc_OOX17") { }

    bool OnQuestAccept(Player* player, Creature* creature, Quest const* quest)
    {
        if (quest->GetQuestId() == Q_OOX17)
        {
            creature->setFaction(113);
            creature->SetFullHealth();
            creature->SetUInt32Value(UNIT_FIELD_BYTES_1, 0);
            creature->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_OOC_NOT_ATTACKABLE);
            DoScriptText(SAY_OOX_START, creature);

            if (npc_escortAI* pEscortAI = CAST_AI(npc_OOX17::npc_OOX17AI, creature->AI()))
                pEscortAI->Start(true, false, player->GetGUID());
        }
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_OOX17AI(creature);
    }

    struct npc_OOX17AI : public npc_escortAI
    {
        npc_OOX17AI(Creature* c) : npc_escortAI(c) {}

        void WaypointReached(uint32 i)
        {
            Player* player = GetPlayerForEscort();

            if (!player)
                return;

            switch (i) {
                case 23:
                    me->SummonCreature(SPAWN_FIRST, -8350.96f, -4445.79f, 10.10f, 6.20f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_FIRST, -8355.96f, -4447.79f, 10.10f, 6.27f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_FIRST, -8353.96f, -4442.79f, 10.10f, 6.08f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    DoScriptText(SAY_OOX_AMBUSH, me);
                    break;

                case 56:
                    me->SummonCreature(SPAWN_SECOND_1, -7510.07f, -4795.50f, 9.35f, 6.06f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_SECOND_2, -7515.07f, -4797.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    me->SummonCreature(SPAWN_SECOND_2, -7518.07f, -4792.50f, 9.35f, 6.22f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
                    DoScriptText(SAY_OOX_AMBUSH, me);
                    if (Unit* scoff = me->FindNearestCreature(SPAWN_SECOND_2, 30))
                        DoScriptText(SAY_OOX17_AMBUSH_REPLY, scoff);
                    break;

                case 86:
                    if (player)
                    {
                        DoScriptText(SAY_OOX_END, me);
                        player->GroupEventHappens(Q_OOX17, me);
                    }
                    break;
            }
        }

        void Reset(){}

        void EnterCombat(Unit* /*who*/)
        {
            DoScriptText(RAND(SAY_OOX_AGGRO1, SAY_OOX_AGGRO2), me);
        }

        void JustSummoned(Creature* summoned)
        {
            summoned->AI()->AttackStart(me);
        }
    };

};

/*####
# npc_tooga
####*/

enum eTooga
{
    SAY_TOOG_THIRST             = -1000391,
    SAY_TOOG_WORRIED            = -1000392,
    SAY_TOOG_POST_1             = -1000393,
    SAY_TORT_POST_2             = -1000394,
    SAY_TOOG_POST_3             = -1000395,
    SAY_TORT_POST_4             = -1000396,
    SAY_TOOG_POST_5             = -1000397,
    SAY_TORT_POST_6             = -1000398,

    QUEST_TOOGA                 = 1560,
    NPC_TORTA                   = 6015,

    POINT_ID_TO_WATER           = 1,
    FACTION_TOOG_ESCORTEE       = 113
};

const float m_afToWaterLoc[] = {-7032.664551f, -4906.199219f, -1.606446f};

class npc_tooga : public CreatureScript
{
public:
    npc_tooga() : CreatureScript("npc_tooga") { }

    bool OnQuestAccept(Player* player, Creature* creature, const Quest* quest)
    {
        if (quest->GetQuestId() == QUEST_TOOGA)
        {
            if (npc_toogaAI* pToogaAI = CAST_AI(npc_tooga::npc_toogaAI, creature->AI()))
                pToogaAI->StartFollow(player, FACTION_TOOG_ESCORTEE, quest);
        }

        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new npc_toogaAI(creature);
    }

    struct npc_toogaAI : public FollowerAI
    {
        npc_toogaAI(Creature* creature) : FollowerAI(creature) { }

        uint32 m_uiCheckSpeechTimer;
        uint32 m_uiPostEventTimer;
        uint32 m_uiPhasePostEvent;

        uint64 TortaGUID;

        void Reset()
        {
            m_uiCheckSpeechTimer = 2500;
            m_uiPostEventTimer = 1000;
            m_uiPhasePostEvent = 0;

            TortaGUID = 0;
        }

        void MoveInLineOfSight(Unit* who)
        {
            FollowerAI::MoveInLineOfSight(who);

            if (!me->getVictim() && !HasFollowState(STATE_FOLLOW_COMPLETE | STATE_FOLLOW_POSTEVENT) && who->GetEntry() == NPC_TORTA)
            {
                if (me->IsWithinDistInMap(who, INTERACTION_DISTANCE))
                {
                    if (Player* player = GetLeaderForFollower())
                    {
                        if (player->GetQuestStatus(QUEST_TOOGA) == QUEST_STATUS_INCOMPLETE)
                            player->GroupEventHappens(QUEST_TOOGA, me);
                    }

                    TortaGUID = who->GetGUID();
                    SetFollowComplete(true);
                }
            }
        }

        void MovementInform(uint32 uiMotionType, uint32 uiPointId)
        {
            FollowerAI::MovementInform(uiMotionType, uiPointId);

            if (uiMotionType != POINT_MOTION_TYPE)
                return;

            if (uiPointId == POINT_ID_TO_WATER)
                SetFollowComplete();
        }

        void UpdateFollowerAI(const uint32 uiDiff)
        {
            if (!UpdateVictim())
            {
                //we are doing the post-event, or...
                if (HasFollowState(STATE_FOLLOW_POSTEVENT))
                {
                    if (m_uiPostEventTimer <= uiDiff)
                    {
                        m_uiPostEventTimer = 5000;

                        Unit* pTorta = Unit::GetUnit(*me, TortaGUID);
                        if (!pTorta || !pTorta->isAlive())
                        {
                            //something happened, so just complete
                            SetFollowComplete();
                            return;
                        }

                        switch (m_uiPhasePostEvent)
                        {
                            case 1:
                                DoScriptText(SAY_TOOG_POST_1, me);
                                break;
                            case 2:
                                DoScriptText(SAY_TORT_POST_2, pTorta);
                                break;
                            case 3:
                                DoScriptText(SAY_TOOG_POST_3, me);
                                break;
                            case 4:
                                DoScriptText(SAY_TORT_POST_4, pTorta);
                                break;
                            case 5:
                                DoScriptText(SAY_TOOG_POST_5, me);
                                break;
                            case 6:
                                DoScriptText(SAY_TORT_POST_6, pTorta);
                                me->GetMotionMaster()->MovePoint(POINT_ID_TO_WATER, m_afToWaterLoc[0], m_afToWaterLoc[1], m_afToWaterLoc[2]);
                                break;
                        }

                        ++m_uiPhasePostEvent;
                    }
                    else
                        m_uiPostEventTimer -= uiDiff;
                }
                //...we are doing regular speech check
                else if (HasFollowState(STATE_FOLLOW_INPROGRESS))
                {
                    if (m_uiCheckSpeechTimer <= uiDiff)
                    {
                        m_uiCheckSpeechTimer = 5000;

                        if (urand(0, 9) > 8)
                            DoScriptText(RAND(SAY_TOOG_THIRST, SAY_TOOG_WORRIED), me);
                    }
                    else
                        m_uiCheckSpeechTimer -= uiDiff;
                }

                return;
            }

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_tanaris()
{
    new mob_aquementas();
    new npc_custodian_of_time();
    new npc_marin_noggenfogger();
    new npc_steward_of_time();
    new npc_stone_watcher_of_norgannon();
    new npc_OOX17();
    new npc_tooga();
}
