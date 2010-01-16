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
SDName: Dustwallow_Marsh
SD%Complete: 95
SDComment: Quest support: 11180, 558, 11126, 11142, 11180. Vendor Nat Pagle
SDCategory: Dustwallow Marsh
EndScriptData */

/* ContentData
mobs_risen_husk_spirit
npc_restless_apparition
npc_deserter_agitator
npc_lady_jaina_proudmoore
npc_nat_pagle
npc_private_hendel
npc_cassa_crimsonwing - handled by npc_taxi
EndContentData */

#include "precompiled.h"

/*######
## mobs_risen_husk_spirit
######*/

enum eHuskSpirit
{
    QUEST_WHATS_HAUNTING_WITCH_HILL     = 11180,

    SPELL_SUMMON_RESTLESS_APPARITION    = 42511,
    SPELL_CONSUME_FLESH                 = 37933,               //Risen Husk
    SPELL_INTANGIBLE_PRESENCE           = 43127,               //Risen Spirit

    NPC_RISEN_HUSK                      = 23555,
    NPC_RISEN_SPIRIT                    = 23554,
    NPC_RESTLESS_APPARITION             = 23861
};

struct TRINITY_DLL_DECL mobs_risen_husk_spiritAI : public ScriptedAI
{
    mobs_risen_husk_spiritAI(Creature *c) : ScriptedAI(c) {}

    uint32 m_uiConsumeFlesh_Timer;
    uint32 m_uiIntangiblePresence_Timer;

    void Reset()
    {
        m_uiConsumeFlesh_Timer = 10000;
        m_uiIntangiblePresence_Timer = 5000;
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (m_uiConsumeFlesh_Timer <= uiDiff)
        {
            if (m_creature->GetEntry() == NPC_RISEN_HUSK)
                DoCast(m_creature->getVictim(), SPELL_CONSUME_FLESH);

            m_uiConsumeFlesh_Timer = 15000;
        }
        else
            m_uiConsumeFlesh_Timer -= uiDiff;

        if (m_uiIntangiblePresence_Timer <= uiDiff)
        {
            if (m_creature->GetEntry() == NPC_RISEN_SPIRIT)
                DoCast(m_creature->getVictim(), SPELL_INTANGIBLE_PRESENCE);

            m_uiIntangiblePresence_Timer = 20000;
        }
        else
            m_uiIntangiblePresence_Timer -= uiDiff;

        DoMeleeAttackIfReady();
    }

    void JustDied(Unit* pKiller)
    {
        if (pKiller->GetTypeId() == TYPEID_PLAYER)
            if (CAST_PLR(pKiller)->GetQuestStatus(QUEST_WHATS_HAUNTING_WITCH_HILL) == QUEST_STATUS_INCOMPLETE)
            {
                DoCast(pKiller, SPELL_SUMMON_RESTLESS_APPARITION, true);
                CAST_PLR(pKiller)->KilledMonsterCredit(NPC_RESTLESS_APPARITION,0);
            }
    }
};

CreatureAI* GetAI_mobs_risen_husk_spirit(Creature* pCreature)
{
    return new mobs_risen_husk_spiritAI (pCreature);
}

/*######
## npc_restless_apparition
######*/

enum eRestlessApparition
{
    SAY_RESTLESS_1      = -1000469,
    SAY_RESTLESS_2      = -1000470,
    SAY_RESTLESS_3      = -1000471
};

struct TRINITY_DLL_DECL npc_restless_apparitionAI : public ScriptedAI
{
    npc_restless_apparitionAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void Reset()
    {
        DoScriptText(RAND(SAY_RESTLESS_1,SAY_RESTLESS_2,SAY_RESTLESS_3), m_creature);
    }
};

CreatureAI* GetAI_npc_restless_apparition(Creature* pCreature)
{
    return new npc_restless_apparitionAI (pCreature);
}

/*######
## npc_deserter_agitator
######*/

enum eAgitator
{
    QUEST_TRAITORS_AMONG_US = 11126,
    FACTION_THER_DESERTER   = 1883
};

struct TRINITY_DLL_DECL npc_deserter_agitatorAI : public ScriptedAI
{
    npc_deserter_agitatorAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset()
    {
        me->RestoreFaction();
    }
};

CreatureAI* GetAI_npc_deserter_agitator(Creature* pCreature)
{
    return new npc_deserter_agitatorAI (pCreature);
}

bool GossipHello_npc_deserter_agitator(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_TRAITORS_AMONG_US) == QUEST_STATUS_INCOMPLETE)
    {
        pCreature->setFaction(FACTION_THER_DESERTER);
        pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

/*######
## npc_lady_jaina_proudmoore
######*/

enum eLadyJaina
{
    QUEST_JAINAS_AUTOGRAPH = 558,
    SPELL_JAINAS_AUTOGRAPH = 23122
};

#define GOSSIP_ITEM_JAINA "I know this is rather silly but i have a young ward who is a bit shy and would like your autograph."

bool GossipHello_npc_lady_jaina_proudmoore(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_JAINAS_AUTOGRAPH) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_JAINA, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_lady_jaina_proudmoore(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_SENDER_INFO)
    {
        pPlayer->SEND_GOSSIP_MENU(7012, pCreature->GetGUID());
        pPlayer->CastSpell(pPlayer, SPELL_JAINAS_AUTOGRAPH, false);
    }
    return true;
}

/*######
## npc_nat_pagle
######*/

enum eNatPagle
{
    QUEST_NATS_MEASURING_TAPE = 8227
};

bool GossipHello_npc_nat_pagle(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pCreature->isVendor() && pPlayer->GetQuestRewardStatus(QUEST_NATS_MEASURING_TAPE))
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);
        pPlayer->SEND_GOSSIP_MENU(7640, pCreature->GetGUID());
    }
    else
        pPlayer->SEND_GOSSIP_MENU(7638, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_nat_pagle(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());

    return true;
}

/*######
## npc_private_hendel
######*/

enum eHendel
{
    // looks like all this text ids are wrong.
    SAY_PROGRESS_1_TER          = -1000411, // signed for 3568
    SAY_PROGRESS_2_HEN          = -1000412, // signed for 3568
    SAY_PROGRESS_3_TER          = -1000413,
    SAY_PROGRESS_4_TER          = -1000414,
    EMOTE_SURRENDER             = -1000415,

    QUEST_MISSING_DIPLO_PT16    = 1324,
    FACTION_HOSTILE             = 168,                      //guessed, may be different

    NPC_SENTRY                  = 5184,                     //helps hendel
    NPC_JAINA                   = 4968,                     //appears once hendel gives up
    NPC_TERVOSH                 = 4967
};

//TODO: develop this further, end event not created
struct TRINITY_DLL_DECL npc_private_hendelAI : public ScriptedAI
{
    npc_private_hendelAI(Creature* pCreature) : ScriptedAI(pCreature) { }

    void Reset()
    {
        me->RestoreFaction();
    }

    void AttackedBy(Unit* pAttacker)
    {
        if (m_creature->getVictim())
            return;

        if (m_creature->IsFriendlyTo(pAttacker))
            return;

        AttackStart(pAttacker);
    }

    void DamageTaken(Unit* pDoneBy, uint32 &uiDamage)
    {
        if (uiDamage > m_creature->GetHealth() || ((m_creature->GetHealth() - uiDamage)*100 / m_creature->GetMaxHealth() < 20))
        {
            uiDamage = 0;

            if (Player* pPlayer = pDoneBy->GetCharmerOrOwnerPlayerOrPlayerItself())
                pPlayer->GroupEventHappens(QUEST_MISSING_DIPLO_PT16, m_creature);

            DoScriptText(EMOTE_SURRENDER, m_creature);
            EnterEvadeMode();
        }
    }
};

bool QuestAccept_npc_private_hendel(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_MISSING_DIPLO_PT16)
        pCreature->setFaction(FACTION_HOSTILE);

    return true;
}

CreatureAI* GetAI_npc_private_hendel(Creature* pCreature)
{
    return new npc_private_hendelAI(pCreature);
}

/*######
## npc_zelfrax
######*/

const Position MovePosition = {-2967.030,-3872.1799,35.620};

enum eZelfrax
{
    SAY_ZELFRAX     = -1000472,
    SAY_ZELFRAX_2   = -1000473
};

struct TRINITY_DLL_DECL npc_zelfraxAI : public ScriptedAI
{
    npc_zelfraxAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        MoveToDock();
    }

    void AttackStart(Unit* pWho)
    {
        if (!pWho)
            return;

        if (m_creature->Attack(pWho, true))
        {
            m_creature->SetInCombatWith(pWho);
            pWho->SetInCombatWith(m_creature);

            if (IsCombatMovement())
                m_creature->GetMotionMaster()->MoveChase(pWho);
        }
    }

    void MovementInform(uint32 uiType, uint32 uiId)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        m_creature->SetHomePosition(m_creature->GetPositionX(),m_creature->GetPositionY(),m_creature->GetPositionZ(),m_creature->GetOrientation());
        m_creature->RemoveFlag(UNIT_FIELD_FLAGS,UNIT_FLAG_OOC_NOT_ATTACKABLE);
        SetCombatMovement(true);

        if (m_creature->isInCombat())
            if (Unit* pUnit = m_creature->getVictim())
                m_creature->GetMotionMaster()->MoveChase(pUnit);
    }

    void MoveToDock()
    {
        SetCombatMovement(false);
        m_creature->GetMotionMaster()->MovePoint(0,MovePosition);
        DoScriptText(SAY_ZELFRAX,m_creature);
        DoScriptText(SAY_ZELFRAX_2,m_creature);
    }

    void UpdateAI(uint32 const uiDiff)
    {
        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_zelfrax(Creature* pCreature)
{
    return new npc_zelfraxAI(pCreature);
}

void AddSC_dustwallow_marsh()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "mobs_risen_husk_spirit";
    newscript->GetAI = &GetAI_mobs_risen_husk_spirit;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_restless_apparition";
    newscript->GetAI = &GetAI_npc_restless_apparition;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_deserter_agitator";
    newscript->GetAI = &GetAI_npc_deserter_agitator;
    newscript->pGossipHello = &GossipHello_npc_deserter_agitator;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lady_jaina_proudmoore";
    newscript->pGossipHello = &GossipHello_npc_lady_jaina_proudmoore;
    newscript->pGossipSelect = &GossipSelect_npc_lady_jaina_proudmoore;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_nat_pagle";
    newscript->pGossipHello = &GossipHello_npc_nat_pagle;
    newscript->pGossipSelect = &GossipSelect_npc_nat_pagle;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_private_hendel";
    newscript->GetAI = &GetAI_npc_private_hendel;
    newscript->pQuestAccept = &QuestAccept_npc_private_hendel;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_zelfrax";
    newscript->GetAI = &GetAI_npc_zelfrax;
    newscript->RegisterSelf();
}

