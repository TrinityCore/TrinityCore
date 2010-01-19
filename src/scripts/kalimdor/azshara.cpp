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

#include "ScriptedPch.h"
#include "World.h"
#include "WorldPacket.h"

/*######
## mobs_spitelashes
######*/

struct TRINITY_DLL_DECL mobs_spitelashesAI : public ScriptedAI
{
    mobs_spitelashesAI(Creature *c) : ScriptedAI(c) {}

    uint32 morphtimer;
    bool spellhit;

    void Reset()
    {
        morphtimer = 0;
        spellhit = false;
    }

    void EnterCombat(Unit *who) { }

    void SpellHit(Unit *Hitter, const SpellEntry *Spellkind)
    {
        if (!spellhit &&
            Hitter->GetTypeId() == TYPEID_PLAYER &&
            CAST_PLR(Hitter)->GetQuestStatus(9364) == QUEST_STATUS_INCOMPLETE &&
            (Spellkind->Id==118 || Spellkind->Id== 12824 || Spellkind->Id== 12825 || Spellkind->Id== 12826))
        {
            spellhit=true;
            DoCast(m_creature, 29124);                       //become a sheep
        }
    }

    void UpdateAI(const uint32 diff)
    {
        // we mustn't remove the Creature in the same round in which we cast the summon spell, otherwise there will be no summons
        if (spellhit && morphtimer>=5000)
        {
            m_creature->ForcedDespawn();
            return;
        }
        // walk 5 seconds before summoning
        if (spellhit && morphtimer<5000)
        {
            morphtimer+=diff;
            if (morphtimer>=5000)
            {
                DoCast(m_creature, 28406);                   //summon copies
                DoCast(m_creature, 6924);                    //visual explosion
            }
        }
        if (!UpdateVictim())
            return;

        //TODO: add abilities for the different creatures
        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_mobs_spitelashes(Creature* pCreature)
{
    return new mobs_spitelashesAI (pCreature);
}

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

bool GossipHello_npc_loramus_thalipedes(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(2744) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_LT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);

    if (pPlayer->GetQuestStatus(3141) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HELLO_LT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_loramus_thalipedes(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch (uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(2744);
            break;

        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 21);
            pPlayer->SEND_GOSSIP_MENU(1813, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+21:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            pPlayer->SEND_GOSSIP_MENU(1814, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+22:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 23);
            pPlayer->SEND_GOSSIP_MENU(1815, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+23:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 24);
            pPlayer->SEND_GOSSIP_MENU(1816, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+24:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SELECT_LT5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 25);
            pPlayer->SEND_GOSSIP_MENU(1817, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+25:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(3141);
            break;
    }
    return true;
}

/*####
# mob_rizzle_sprysprocket
####*/

#define MOB_DEPTH_CHARGE 23025
#define SPELL_RIZZLE_BLACKJACK 39865
#define SPELL_RIZZLE_ESCAPE 39871
#define SPELL_RIZZLE_FROST_GRENADE 40525
#define SPELL_DEPTH_CHARGE_TRAP 38576
#define SPELL_PERIODIC_DEPTH_CHARGE 39912
#define SPELL_GIVE_SOUTHFURY_MOONSTONE 39886

#define SAY_RIZZLE_START -1000245
#define SAY_RIZZLE_GRENADE -1000246
#define SAY_RIZZLE_FINAL -1000247

#define GOSSIP_GET_MOONSTONE "Hand over the Southfury moonstone and I'll let you go."

//next message must be send to player when Rizzle jump into river, not implemented
#define MSG_ESCAPE_NOTICE "Rizzle Sprysprocket takes the Southfury moonstone and escapes into the river. Follow her!"

float WPs[58][4] =
{
//pos_x   pos_y     pos_z    orien
{3691.97, -3962.41, 35.9118, 3.67},
{3675.02, -3960.49, 35.9118, 3.67},
{3653.19, -3958.33, 33.9118, 3.59},
{3621.12, -3958.51, 29.9118, 3.48},
{3604.86, -3963,    29.9118, 3.48},
{3569.94, -3970.25, 29.9118, 3.44},
{3541.03, -3975.64, 29.9118, 3.41},
{3510.84, -3978.71, 29.9118, 3.41},
{3472.7,  -3997.07, 29.9118, 3.35},
{3439.15, -4014.55, 29.9118, 3.29},
{3412.8,  -4025.87, 29.9118, 3.25},
{3384.95, -4038.04, 29.9118, 3.24},
{3346.77, -4052.93, 29.9118, 3.22},
{3299.56, -4071.59, 29.9118, 3.20},
{3261.22, -4080.38, 30.9118, 3.19},
{3220.68, -4083.09, 31.9118, 3.18},
{3187.11, -4070.45, 33.9118, 3.16},
{3162.78, -4062.75, 33.9118, 3.15},
{3136.09, -4050.32, 33.9118, 3.07},
{3119.47, -4044.51, 36.0363, 3.07},
{3098.95, -4019.8,  33.9118, 3.07},
{3073.07, -4011.42, 33.9118, 3.07},
{3051.71, -3993.37, 33.9118, 3.02},
{3027.52, -3978.6,  33.9118, 3.00},
{3003.78, -3960.14, 33.9118, 2.98},
{2977.99, -3941.98, 31.9118, 2.96},
{2964.57, -3932.07, 30.9118, 2.96},
{2947.9,  -3921.31, 29.9118, 2.96},
{2924.91, -3910.8,  29.9118, 2.94},
{2903.04, -3896.42, 29.9118, 2.93},
{2884.75, -3874.03, 29.9118, 2.90},
{2868.19, -3851.48, 29.9118, 2.82},
{2854.62, -3819.72, 29.9118, 2.80},
{2825.53, -3790.4,  29.9118, 2.744},
{2804.31, -3773.05, 29.9118, 2.71},
{2769.78, -3763.57, 29.9118, 2.70},
{2727.23, -3745.92, 30.9118, 2.69},
{2680.12, -3737.49, 30.9118, 2.67},
{2647.62, -3739.94, 30.9118, 2.66},
{2616.6,  -3745.75, 30.9118, 2.64},
{2589.38, -3731.97, 30.9118, 2.61},
{2562.94, -3722.35, 31.9118, 2.56},
{2521.05, -3716.6,  31.9118, 2.55},
{2485.26, -3706.67, 31.9118, 2.51},
{2458.93, -3696.67, 31.9118, 2.51},
{2432,    -3692.03, 31.9118, 2.46},
{2399.59, -3681.97, 31.9118, 2.45},
{2357.75, -3666.6,  31.9118, 2.44},
{2311.99, -3656.88, 31.9118, 2.94},
{2263.41, -3649.55, 31.9118, 3.02},
{2209.05, -3641.76, 31.9118, 2.99},
{2164.83, -3637.64, 31.9118, 3.15},
{2122.42, -3639,    31.9118, 3.21},
{2075.73, -3643.59, 31.9118, 3.22},
{2033.59, -3649.52, 31.9118, 3.42},
{1985.22, -3662.99, 31.9118, 3.42},
{1927.09, -3679.56, 33.9118, 3.42},
{1873.57, -3695.32, 33.9118, 3.44}
};

struct TRINITY_DLL_DECL mob_rizzle_sprysprocketAI : public ScriptedAI
{
    mob_rizzle_sprysprocketAI(Creature *c) : ScriptedAI(c) {}

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
            if (Must_Die_Timer <= diff)
            {
                m_creature->ForcedDespawn();
                return;
            } else Must_Die_Timer -= diff;

        if (!Escape)
        {
            if (!PlayerGUID)
                return;

            if (spellEscape_Timer <= diff)
            {
                DoCast(m_creature, SPELL_RIZZLE_ESCAPE, false);
                spellEscape_Timer = 10000;
            } else spellEscape_Timer -= diff;

            if (Teleport_Timer <= diff)
            {
                //temp solution - unit can't be teleported by core using spelleffect 5, only players
                Map* pMap = m_creature->GetMap();
                if (pMap)
                {
                    pMap->CreatureRelocation(m_creature, 3706.39, -3969.15, 35.9118, 0);
                    m_creature->AI_SendMoveToPacket(3706.39, -3969.15, 35.9118, 0, 0, 0);
                }
                //begin swimming and summon depth charges
                Player* pPlayer = Unit::GetPlayer(PlayerGUID);
                SendText(MSG_ESCAPE_NOTICE, pPlayer);
                DoCast(m_creature, SPELL_PERIODIC_DEPTH_CHARGE);
                m_creature->SetUnitMovementFlags(MOVEMENTFLAG_HOVER | MOVEMENTFLAG_SWIMMING);
                m_creature->SetSpeed(MOVE_RUN, 0.85f, true);
                m_creature->GetMotionMaster()->MovementExpired();
                m_creature->GetMotionMaster()->MovePoint(CurrWP, WPs[CurrWP][0], WPs[CurrWP][1], WPs[CurrWP][2]);
                Escape = true;
            } else Teleport_Timer -= diff;

            return;
        }

        if (ContinueWP)
        {
            m_creature->GetMotionMaster()->MovePoint(CurrWP, WPs[CurrWP][0], WPs[CurrWP][1], WPs[CurrWP][2]);
            ContinueWP = false;
        }

        if (Grenade_Timer <= diff)
        {
            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            if (pPlayer)
            {
               DoScriptText(SAY_RIZZLE_GRENADE, m_creature, pPlayer);
               DoCast(pPlayer, SPELL_RIZZLE_FROST_GRENADE, true);
            }
            Grenade_Timer = 30000;
        } else Grenade_Timer -= diff;

        if (Check_Timer <= diff)
        {
            Player* pPlayer = Unit::GetPlayer(PlayerGUID);
            if (!pPlayer)
            {
                m_creature->ForcedDespawn();
                return;
            }

            if (m_creature->IsWithinDist(pPlayer, 10) && m_creature->GetPositionX() > pPlayer->GetPositionX() && !Reached)
            {
                DoScriptText(SAY_RIZZLE_FINAL, m_creature);
                m_creature->SetUInt32Value(UNIT_NPC_FLAGS, 1);
                m_creature->setFaction(35);
                m_creature->GetMotionMaster()->MoveIdle();
                m_creature->RemoveAurasDueToSpell(SPELL_PERIODIC_DEPTH_CHARGE);
                Reached = true;
            }

            Check_Timer = 1000;
        } else Check_Timer -= diff;

    }

    void SendText(const char *text, Player* pPlayer)
    {
        WorldPacket data(SMSG_SERVER_MESSAGE, 0);              // guess size
        data << text;
        if (pPlayer)
            pPlayer->GetSession()->SendPacket(&data);
    }

    void AttackStart(Unit *who)
    {
        if (!who || PlayerGUID)
            return;

        if (who->GetTypeId() == TYPEID_PLAYER && CAST_PLR(who)->GetQuestStatus(10994) == QUEST_STATUS_INCOMPLETE)
        {
            PlayerGUID = who->GetGUID();
            DoScriptText(SAY_RIZZLE_START, m_creature);
            DoCast(who, SPELL_RIZZLE_BLACKJACK, false);
            return;
        }
    }

    void EnterCombat(Unit* who) {}

    void MovementInform(uint32 type, uint32 id)
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == 57)
        {
            m_creature->ForcedDespawn();
            return;
        }

        ++CurrWP;
        ContinueWP = true;
    }

};

bool GossipHello_mob_rizzle_sprysprocket(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(10994) != QUEST_STATUS_INCOMPLETE)
        return true;
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_GET_MOONSTONE, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(10811, pCreature->GetGUID());
    return true;
}

bool GossipSelect_mob_rizzle_sprysprocket(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF + 1 && pPlayer->GetQuestStatus(10994) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->CastSpell(pPlayer, SPELL_GIVE_SOUTHFURY_MOONSTONE, true);
        CAST_AI(mob_rizzle_sprysprocketAI, pCreature->AI())->Must_Die_Timer = 3000;
        CAST_AI(mob_rizzle_sprysprocketAI, pCreature->AI())->Must_Die = true;
    }
    return true;
}

CreatureAI* GetAI_mob_rizzle_sprysprocket(Creature* pCreature)
{
    return new mob_rizzle_sprysprocketAI (pCreature);
}

/*####
# mob_depth_charge
####*/

struct TRINITY_DLL_DECL mob_depth_chargeAI : public ScriptedAI
{
    mob_depth_chargeAI(Creature *c) : ScriptedAI(c) {}

    bool we_must_die;
    uint32 must_die_timer;

    void Reset()
    {
        m_creature->SetUnitMovementFlags(MOVEMENTFLAG_HOVER | MOVEMENTFLAG_SWIMMING);
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        we_must_die = false;
        must_die_timer = 1000;
    }

    void UpdateAI(const uint32 diff)
    {
        if (we_must_die)
            if (must_die_timer <= diff)
            {
                m_creature->ForcedDespawn();
            } else must_die_timer -= diff;
        return;
    }

    void MoveInLineOfSight(Unit *who)
    {
        if (!who)
            return;

        if (who->GetTypeId() == TYPEID_PLAYER && m_creature->IsWithinDistInMap(who, 5))
        {
            DoCast(who, SPELL_DEPTH_CHARGE_TRAP);
            we_must_die = true;
            return;
        }
    }

    void AttackStart(Unit *who)
    {
        return;
    }

    void EnterCombat(Unit* who)
    {
        return;
    }
};

CreatureAI* GetAI_mob_depth_charge(Creature* pCreature)
{
    return new mob_depth_chargeAI (pCreature);
}

void AddSC_azshara()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mobs_spitelashes";
    newscript->GetAI = &GetAI_mobs_spitelashes;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_loramus_thalipedes";
    newscript->pGossipHello =  &GossipHello_npc_loramus_thalipedes;
    newscript->pGossipSelect = &GossipSelect_npc_loramus_thalipedes;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_rizzle_sprysprocket";
    newscript->GetAI = &GetAI_mob_rizzle_sprysprocket;
    newscript->pGossipHello =  &GossipHello_mob_rizzle_sprysprocket;
    newscript->pGossipSelect = &GossipSelect_mob_rizzle_sprysprocket;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "mob_depth_charge";
    newscript->GetAI = &GetAI_mob_depth_charge;
    newscript->RegisterSelf();
}

