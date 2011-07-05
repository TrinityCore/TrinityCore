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
SDName: Azshara
SD%Complete: 90
SDComment: Quest support: 2744, 3141, 9364, 10994
SDCategory: Azshara
EndScriptData */

/* ContentData
mobs_spitelashes
npc_loramus_thalipedes
mob_rizzle_sprysprocket
mob_depth_charge
EndContentData */

#include "ScriptPCH.h"
#include "World.h"
#include "WorldPacket.h"

/*######
## mobs_spitelashes
######*/

class mobs_spitelashes : public CreatureScript
{
public:
    mobs_spitelashes() : CreatureScript("mobs_spitelashes") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mobs_spitelashesAI (creature);
    }

    struct mobs_spitelashesAI : public ScriptedAI
    {
        mobs_spitelashesAI(Creature* c) : ScriptedAI(c) {}

        uint32 morphtimer;
        bool spellhit;

        void Reset()
        {
            morphtimer = 0;
            spellhit = false;
        }

        void EnterCombat(Unit* /*who*/) { }

        void SpellHit(Unit* Hitter, const SpellEntry *Spellkind)
        {
            if (!spellhit &&
                Hitter->GetTypeId() == TYPEID_PLAYER &&
                CAST_PLR(Hitter)->GetQuestStatus(9364) == QUEST_STATUS_INCOMPLETE &&
                (Spellkind->Id == 118 || Spellkind->Id == 12824 || Spellkind->Id == 12825 || Spellkind->Id == 12826))
            {
                spellhit=true;
                DoCast(me, 29124);                       //become a sheep
            }
        }

        void UpdateAI(const uint32 diff)
        {
            // we mustn't remove the Creature in the same round in which we cast the summon spell, otherwise there will be no summons
            if (spellhit && morphtimer >= 5000)
            {
                me->DespawnOrUnsummon();
                return;
            }
            // walk 5 seconds before summoning
            if (spellhit && morphtimer<5000)
            {
                morphtimer+=diff;
                if (morphtimer >= 5000)
                {
                    DoCast(me, 28406);                   //summon copies
                    DoCast(me, 6924);                    //visual explosion
                }
            }
            if (!UpdateVictim())
                return;

            //TODO: add abilities for the different creatures
            DoMeleeAttackIfReady();
        }
    };

};

/*######
## npc_loramus_thalipedes
######*/

#define GOSSIP_HELLO_LT1    "Can you help me?"
#define GOSSIP_HELLO_LT2    "Tell me your story"
#define GOSSIP_SELECT_LT1   "Please continue"
#define GOSSIP_SELECT_LT2   "I do not understand"
#define GOSSIP_SELECT_LT3   "Indeed"
#define GOSSIP_SELECT_LT4   "I will do this with or your help, Loramus"
#define GOSSIP_SELECT_LT5   "Yes"

class npc_loramus_thalipedes : public CreatureScript
{
public:
    npc_loramus_thalipedes() : CreatureScript("npc_loramus_thalipedes") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
            case GOSSIP_ACTION_INFO_DEF+1:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(2744);
                break;

            case GOSSIP_ACTION_INFO_DEF+2:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
                player->SEND_GOSSIP_MENU(1813, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+21:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
                player->SEND_GOSSIP_MENU(1814, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+22:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
                player->SEND_GOSSIP_MENU(1815, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+23:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
                player->SEND_GOSSIP_MENU(1816, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+24:
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
                player->SEND_GOSSIP_MENU(1817, creature->GetGUID());
                break;
            case GOSSIP_ACTION_INFO_DEF+25:
                player->CLOSE_GOSSIP_MENU();
                player->AreaExploredOrEventHappens(3141);
                break;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (creature->isQuestGiver())
            player->PrepareQuestMenu(creature->GetGUID());

        if (player->GetQuestStatus(2744) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_LT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

        if (player->GetQuestStatus(3141) == QUEST_STATUS_INCOMPLETE)
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_LT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

        player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());

        return true;
    }
};

/*####
# mob_rizzle_sprysprocket
####*/

enum eRizzleSprysprocketData
{
    MOB_DEPTH_CHARGE                = 23025,
    SPELL_RIZZLE_BLACKJACK          = 39865,
    SPELL_RIZZLE_ESCAPE             = 39871,
    SPELL_RIZZLE_FROST_GRENADE      = 40525,
    SPELL_DEPTH_CHARGE_TRAP         = 38576,
    SPELL_PERIODIC_DEPTH_CHARGE     = 39912,
    SPELL_GIVE_SOUTHFURY_MOONSTONE  = 39886,

    SAY_RIZZLE_START                = -1000351,
    MSG_ESCAPE_NOTICE               = -1000352,
    SAY_RIZZLE_GRENADE              = -1000353,
    SAY_RIZZLE_GRENADE_BACKFIRE     = -1000354, // Not used
    SAY_RIZZLE_FINAL                = -1000355,
    SAY_RIZZLE_FINAL2               = -1000356, // Not used
};

#define GOSSIP_GET_MOONSTONE "Hand over the Southfury moonstone and I'll let you go."

float WPs[58][4] =
{
//pos_x   pos_y     pos_z    orien
{3691.97f, -3962.41f, 35.9118f, 3.67f},
{3675.02f, -3960.49f, 35.9118f, 3.67f},
{3653.19f, -3958.33f, 33.9118f, 3.59f},
{3621.12f, -3958.51f, 29.9118f, 3.48f},
{3604.86f, -3963,    29.9118f, 3.48f},
{3569.94f, -3970.25f, 29.9118f, 3.44f},
{3541.03f, -3975.64f, 29.9118f, 3.41f},
{3510.84f, -3978.71f, 29.9118f, 3.41f},
{3472.7f,  -3997.07f, 29.9118f, 3.35f},
{3439.15f, -4014.55f, 29.9118f, 3.29f},
{3412.8f,  -4025.87f, 29.9118f, 3.25f},
{3384.95f, -4038.04f, 29.9118f, 3.24f},
{3346.77f, -4052.93f, 29.9118f, 3.22f},
{3299.56f, -4071.59f, 29.9118f, 3.20f},
{3261.22f, -4080.38f, 30.9118f, 3.19f},
{3220.68f, -4083.09f, 31.9118f, 3.18f},
{3187.11f, -4070.45f, 33.9118f, 3.16f},
{3162.78f, -4062.75f, 33.9118f, 3.15f},
{3136.09f, -4050.32f, 33.9118f, 3.07f},
{3119.47f, -4044.51f, 36.0363f, 3.07f},
{3098.95f, -4019.8f,  33.9118f, 3.07f},
{3073.07f, -4011.42f, 33.9118f, 3.07f},
{3051.71f, -3993.37f, 33.9118f, 3.02f},
{3027.52f, -3978.6f,  33.9118f, 3.00f},
{3003.78f, -3960.14f, 33.9118f, 2.98f},
{2977.99f, -3941.98f, 31.9118f, 2.96f},
{2964.57f, -3932.07f, 30.9118f, 2.96f},
{2947.9f,  -3921.31f, 29.9118f, 2.96f},
{2924.91f, -3910.8f,  29.9118f, 2.94f},
{2903.04f, -3896.42f, 29.9118f, 2.93f},
{2884.75f, -3874.03f, 29.9118f, 2.90f},
{2868.19f, -3851.48f, 29.9118f, 2.82f},
{2854.62f, -3819.72f, 29.9118f, 2.80f},
{2825.53f, -3790.4f,  29.9118f, 2.744f},
{2804.31f, -3773.05f, 29.9118f, 2.71f},
{2769.78f, -3763.57f, 29.9118f, 2.70f},
{2727.23f, -3745.92f, 30.9118f, 2.69f},
{2680.12f, -3737.49f, 30.9118f, 2.67f},
{2647.62f, -3739.94f, 30.9118f, 2.66f},
{2616.6f,  -3745.75f, 30.9118f, 2.64f},
{2589.38f, -3731.97f, 30.9118f, 2.61f},
{2562.94f, -3722.35f, 31.9118f, 2.56f},
{2521.05f, -3716.6f,  31.9118f, 2.55f},
{2485.26f, -3706.67f, 31.9118f, 2.51f},
{2458.93f, -3696.67f, 31.9118f, 2.51f},
{2432,    -3692.03f, 31.9118f, 2.46f},
{2399.59f, -3681.97f, 31.9118f, 2.45f},
{2357.75f, -3666.6f,  31.9118f, 2.44f},
{2311.99f, -3656.88f, 31.9118f, 2.94f},
{2263.41f, -3649.55f, 31.9118f, 3.02f},
{2209.05f, -3641.76f, 31.9118f, 2.99f},
{2164.83f, -3637.64f, 31.9118f, 3.15f},
{2122.42f, -3639,    31.9118f, 3.21f},
{2075.73f, -3643.59f, 31.9118f, 3.22f},
{2033.59f, -3649.52f, 31.9118f, 3.42f},
{1985.22f, -3662.99f, 31.9118f, 3.42f},
{1927.09f, -3679.56f, 33.9118f, 3.42f},
{1873.57f, -3695.32f, 33.9118f, 3.44f}
};

class mob_rizzle_sprysprocket : public CreatureScript
{
public:
    mob_rizzle_sprysprocket() : CreatureScript("mob_rizzle_sprysprocket") { }

    bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
    {
        player->PlayerTalkClass->ClearMenus();
        if (uiAction == GOSSIP_ACTION_INFO_DEF + 1 && player->GetQuestStatus(10994) == QUEST_STATUS_INCOMPLETE)
        {
            player->CLOSE_GOSSIP_MENU();
            creature->CastSpell(player, SPELL_GIVE_SOUTHFURY_MOONSTONE, true);
            CAST_AI(mob_rizzle_sprysprocket::mob_rizzle_sprysprocketAI, creature->AI())->Must_Die_Timer = 3000;
            CAST_AI(mob_rizzle_sprysprocket::mob_rizzle_sprysprocketAI, creature->AI())->Must_Die = true;
        }
        return true;
    }

    bool OnGossipHello(Player* player, Creature* creature)
    {
        if (player->GetQuestStatus(10994) != QUEST_STATUS_INCOMPLETE)
            return true;
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_GET_MOONSTONE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        player->SEND_GOSSIP_MENU(10811, creature->GetGUID());
        return true;
    }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_rizzle_sprysprocketAI (creature);
    }

    struct mob_rizzle_sprysprocketAI : public ScriptedAI
    {
        mob_rizzle_sprysprocketAI(Creature* c) : ScriptedAI(c) {}

        uint32 spellEscape_Timer;
        uint32 Teleport_Timer;
        uint32 Check_Timer;
        uint32 Grenade_Timer;
        uint32 Must_Die_Timer;
        uint32 CurrWP;

        uint64 PlayerGUID;

        bool Must_Die;
        bool Escape;
        bool ContinueWP;
        bool Reached;

        void Reset()
        {
            spellEscape_Timer = 1300;
            Teleport_Timer = 3500;
            Check_Timer = 10000;
            Grenade_Timer = 30000;
            Must_Die_Timer = 3000;
            CurrWP = 0;

            PlayerGUID = 0;

            Must_Die = false;
            Escape = false;
            ContinueWP = false;
            Reached = false;
        }

        void UpdateAI(const uint32 diff)
        {
            if (Must_Die)
            {
                if (Must_Die_Timer <= diff)
                {
                    me->DespawnOrUnsummon();
                    return;
                } else Must_Die_Timer -= diff;
            }

            if (!Escape)
            {
                if (!PlayerGUID)
                    return;

                if (spellEscape_Timer <= diff)
                {
                    DoCast(me, SPELL_RIZZLE_ESCAPE, false);
                    spellEscape_Timer = 10000;
                } else spellEscape_Timer -= diff;

                if (Teleport_Timer <= diff)
                {
                    //temp solution - unit can't be teleported by core using spelleffect 5, only players
                    Map* pMap = me->GetMap();
                    if (pMap)
                    {
                        pMap->CreatureRelocation(me, 3706.39f, -3969.15f, 35.9118f, 0);
                        me->AI_SendMoveToPacket(3706.39f, -3969.15f, 35.9118f, 0, 0, 0);
                    }
                    //begin swimming and summon depth charges
                    Player* player = Unit::GetPlayer(*me, PlayerGUID);
                    SendText(MSG_ESCAPE_NOTICE, player);
                    DoCast(me, SPELL_PERIODIC_DEPTH_CHARGE);
                    me->SetUnitMovementFlags(MOVEMENTFLAG_HOVER | MOVEMENTFLAG_SWIMMING);
                    me->SetSpeed(MOVE_RUN, 0.85f, true);
                    me->GetMotionMaster()->MovementExpired();
                    me->GetMotionMaster()->MovePoint(CurrWP, WPs[CurrWP][0], WPs[CurrWP][1], WPs[CurrWP][2]);
                    Escape = true;
                } else Teleport_Timer -= diff;

                return;
            }

            if (ContinueWP)
            {
                me->GetMotionMaster()->MovePoint(CurrWP, WPs[CurrWP][0], WPs[CurrWP][1], WPs[CurrWP][2]);
                ContinueWP = false;
            }

            if (Grenade_Timer <= diff)
            {
                Player* player = Unit::GetPlayer(*me, PlayerGUID);
                if (player)
                {
                   DoScriptText(SAY_RIZZLE_GRENADE, me, player);
                   DoCast(player, SPELL_RIZZLE_FROST_GRENADE, true);
                }
                Grenade_Timer = 30000;
            } else Grenade_Timer -= diff;

            if (Check_Timer <= diff)
            {
                Player* player = Unit::GetPlayer(*me, PlayerGUID);
                if (!player)
                {
                    me->DespawnOrUnsummon();
                    return;
                }

                if (me->IsWithinDist(player, 10) && me->GetPositionX() > player->GetPositionX() && !Reached)
                {
                    DoScriptText(SAY_RIZZLE_FINAL, me);
                    me->SetUInt32Value(UNIT_NPC_FLAGS, 1);
                    me->setFaction(35);
                    me->GetMotionMaster()->MoveIdle();
                    me->RemoveAurasDueToSpell(SPELL_PERIODIC_DEPTH_CHARGE);
                    Reached = true;
                }

                Check_Timer = 1000;
            } else Check_Timer -= diff;

        }

        void SendText(int32 iTextEntry, Player* player)
        {
            LocaleConstant loc_idx = player->GetSession()->GetSessionDbLocaleIndex();
            const char* text = sObjectMgr->GetTrinityString(iTextEntry, loc_idx);
            sWorld->SendServerMessage(SERVER_MSG_STRING, text, player);
        }

        void AttackStart(Unit* who)
        {
            if (!who || PlayerGUID)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER && CAST_PLR(who)->GetQuestStatus(10994) == QUEST_STATUS_INCOMPLETE)
            {
                PlayerGUID = who->GetGUID();
                DoScriptText(SAY_RIZZLE_START, me);
                DoCast(who, SPELL_RIZZLE_BLACKJACK, false);
                return;
            }
        }

        void EnterCombat(Unit* /*who*/) {}

        void MovementInform(uint32 type, uint32 id)
        {
            if (type != POINT_MOTION_TYPE)
                return;

            if (id == 57)
            {
                me->DespawnOrUnsummon();
                return;
            }

            ++CurrWP;
            ContinueWP = true;
        }
    };
};

/*####
# mob_depth_charge
####*/
class mob_depth_charge : public CreatureScript
{
public:
    mob_depth_charge() : CreatureScript("mob_depth_charge") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        return new mob_depth_chargeAI (creature);
    }

    struct mob_depth_chargeAI : public ScriptedAI
    {
        mob_depth_chargeAI(Creature* c) : ScriptedAI(c) {}

        bool we_must_die;
        uint32 must_die_timer;

        void Reset()
        {
            me->SetUnitMovementFlags(MOVEMENTFLAG_HOVER | MOVEMENTFLAG_SWIMMING);
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            we_must_die = false;
            must_die_timer = 1000;
        }

        void UpdateAI(const uint32 diff)
        {
            if (we_must_die)
            {
                if (must_die_timer <= diff)
                {
                    me->DespawnOrUnsummon();
                } else must_die_timer -= diff;
            }
            return;
        }

        void MoveInLineOfSight(Unit* who)
        {
            if (!who)
                return;

            if (who->GetTypeId() == TYPEID_PLAYER && me->IsWithinDistInMap(who, 5))
            {
                DoCast(who, SPELL_DEPTH_CHARGE_TRAP);
                we_must_die = true;
                return;
            }
        }

        void AttackStart(Unit* /*who*/)
        {
        }

        void EnterCombat(Unit* /*who*/)
        {
        }
    };

};

void AddSC_azshara()
{
    new mobs_spitelashes();
    new npc_loramus_thalipedes();
    new mob_rizzle_sprysprocket();
    new mob_depth_charge();
}
