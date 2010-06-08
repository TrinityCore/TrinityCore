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
SDName: Icecrown
SD%Complete: 100
SDComment: Quest support: 12807
SDCategory: Icecrown
EndScriptData */

/* ContentData
npc_arete
EndContentData */

#include "ScriptPCH.h"

/*######
## npc_arete
######*/

#define GOSSIP_ARETE_ITEM1 "Lord-Commander, I would hear your tale."
#define GOSSIP_ARETE_ITEM2 "<You nod slightly but do not complete the motion as the Lord-Commander narrows his eyes before he continues.>"
#define GOSSIP_ARETE_ITEM3 "I thought that they now called themselves the Scarlet Onslaught?"
#define GOSSIP_ARETE_ITEM4 "Where did the grand admiral go?"
#define GOSSIP_ARETE_ITEM5 "That's fine. When do I start?"
#define GOSSIP_ARETE_ITEM6 "Let's finish this!"
#define GOSSIP_ARETE_ITEM7 "That's quite a tale, Lord-Commander."

enum eArete
{
    GOSSIP_TEXTID_ARETE1        = 13525,
    GOSSIP_TEXTID_ARETE2        = 13526,
    GOSSIP_TEXTID_ARETE3        = 13527,
    GOSSIP_TEXTID_ARETE4        = 13528,
    GOSSIP_TEXTID_ARETE5        = 13529,
    GOSSIP_TEXTID_ARETE6        = 13530,
    GOSSIP_TEXTID_ARETE7        = 13531,

    QUEST_THE_STORY_THUS_FAR    = 12807
};

bool GossipHello_npc_arete(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_THE_STORY_THUS_FAR) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE1, pCreature->GetGUID());
        return true;
    }

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_arete(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE2, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE3, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM4, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 4);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE4, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+4:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM5, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE5, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+5:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM6, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 6);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE6, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+6:
            pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ARETE_ITEM7, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 7);
            pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_ARETE7, pCreature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+7:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->AreaExploredOrEventHappens(QUEST_THE_STORY_THUS_FAR);
            break;
    }

    return true;
}

/*######
## npc_dame_evniki_kapsalis
######*/

enum eDameEnvikiKapsalis
{
    TITLE_CRUSADER    = 123
};

bool GossipHello_npc_dame_evniki_kapsalis(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->HasTitle(TITLE_CRUSADER))
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_VENDOR, GOSSIP_TEXT_BROWSE_GOODS, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TRADE);

    pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_dame_evniki_kapsalis(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_TRADE)
        pPlayer->SEND_VENDORLIST(pCreature->GetGUID());
    return true;
}

/*######
## npc_squire_david
######*/

enum eSquireDavid
{
    QUEST_THE_ASPIRANT_S_CHALLENGE_H                    = 13680,
    QUEST_THE_ASPIRANT_S_CHALLENGE_A                    = 13679,

    NPC_ARGENT_VALIANT                                  = 33448,

    GOSSIP_TEXTID_SQUIRE                                = 14407
};

#define GOSSIP_SQUIRE_ITEM_1 "I am ready to fight!"
#define GOSSIP_SQUIRE_ITEM_2 "How do the Argent Crusader raiders fight?"

bool GossipHello_npc_squire_david(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_H) == QUEST_STATUS_INCOMPLETE ||
        pPlayer->GetQuestStatus(QUEST_THE_ASPIRANT_S_CHALLENGE_A) == QUEST_STATUS_INCOMPLETE)//We need more info about it.
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_SQUIRE_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    }

    pPlayer->SEND_GOSSIP_MENU(GOSSIP_TEXTID_SQUIRE, pCreature->GetGUID());
    return true;
}

bool GossipSelect_npc_squire_david(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pCreature->SummonCreature(NPC_ARGENT_VALIANT,8575.451,952.472,547.554,0.38);
    }
    //else
        //pPlayer->SEND_GOSSIP_MENU(???, pCreature->GetGUID()); Missing text
    return true;
}

/*######
## npc_argent_valiant
######*/

enum eArgentValiant
{
    SPELL_CHARGE                = 63010,
    SPELL_SHIELD_BREAKER        = 65147,

    NPC_ARGENT_VALIANT_CREDIT   = 24108
};

struct npc_argent_valiantAI : public ScriptedAI
{
    npc_argent_valiantAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        pCreature->GetMotionMaster()->MovePoint(0,8599.258,963.951,547.553);
        pCreature->setFaction(35); //wrong faction in db?
    }

    uint32 uiChargeTimer;
    uint32 uiShieldBreakerTimer;

    void Reset()
    {
        uiChargeTimer = 7000;
        uiShieldBreakerTimer = 10000;
    }

    void MovementInform(uint32 uiType, uint32 /*uiId*/)
    {
        if (uiType != POINT_MOTION_TYPE)
            return;

        me->setFaction(14);
    }

    void DamageTaken(Unit* pDoneBy, uint32& uiDamage)
    {
        if (uiDamage > me->GetHealth() && pDoneBy->GetTypeId() == TYPEID_PLAYER)
        {
            uiDamage = 0;
            CAST_PLR(pDoneBy)->KilledMonsterCredit(NPC_ARGENT_VALIANT_CREDIT,0);
            me->setFaction(35);
            me->ForcedDespawn(5000);
            me->SetHomePosition(me->GetPositionX(),me->GetPositionY(),me->GetPositionZ(),me->GetOrientation());
            EnterEvadeMode();
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (!UpdateVictim())
            return;

        if (uiChargeTimer <= uiDiff)
        {
            DoCastVictim(SPELL_CHARGE);
            uiChargeTimer = 7000;
        } else uiChargeTimer -= uiDiff;

        if (uiShieldBreakerTimer <= uiDiff)
        {
            DoCastVictim(SPELL_SHIELD_BREAKER);
            uiShieldBreakerTimer = 10000;
        } else uiShieldBreakerTimer -= uiDiff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_npc_argent_valiant(Creature* pCreature)
{
    return new npc_argent_valiantAI (pCreature);
}

/*######
## npc_argent_tournament_post
######*/

enum eArgentTournamentPost
{
    SPELL_ROPE_BEAM                 = 63413,
    NPC_GORMOK_THE_IMPALER          = 35469,
    NPC_ICEHOWL                     = 35470
};

struct npc_argent_tournament_postAI : public ScriptedAI
{
    npc_argent_tournament_postAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    void UpdateAI(const uint32 /*uiDiff*/)
    {
        if (me->IsNonMeleeSpellCasted(false))
            return;

        if (Creature* pTarget = me->FindNearestCreature(NPC_GORMOK_THE_IMPALER, 6.0f))
            DoCast(pTarget, SPELL_ROPE_BEAM);

        if (Creature* pTarget2 = me->FindNearestCreature(NPC_ICEHOWL, 6.0f))
            DoCast(pTarget2, SPELL_ROPE_BEAM);

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_argent_tournament_post(Creature* pCreature)
{
    return new npc_argent_tournament_postAI (pCreature);
}

/*######
## npc_alorah_and_grimmin
######*/

enum ealorah_and_grimmin
{
    SPELL_CHAIN                     = 68341,
    NPC_FJOLA_LIGHTBANE             = 36065,
    NPC_EYDIS_DARKBANE              = 36066,
    NPC_PRIESTESS_ALORAH            = 36101,
    NPC_PRIEST_GRIMMIN              = 36102
};

struct npc_alorah_and_grimminAI : public ScriptedAI
{
    npc_alorah_and_grimminAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    bool uiCast;

    void Reset()
    {
        uiCast = false;
    }

    void UpdateAI(const uint32 /*uiDiff*/)
    {
        if (uiCast)
            return;
        uiCast = true;
        Creature* pTarget = NULL;

        switch(me->GetEntry())
        {
            case NPC_PRIESTESS_ALORAH:
                pTarget = me->FindNearestCreature(NPC_EYDIS_DARKBANE, 10.0f);
                break;
            case NPC_PRIEST_GRIMMIN:
                pTarget = me->FindNearestCreature(NPC_FJOLA_LIGHTBANE, 10.0f);
                break;
        }
        if (pTarget)
            DoCast(pTarget, SPELL_CHAIN);

        if (!UpdateVictim())
            return;
    }
};

CreatureAI* GetAI_npc_alorah_and_grimmin(Creature* pCreature)
{
    return new npc_alorah_and_grimminAI (pCreature);
}

/*######
## npc_guardian_pavilion
######*/

enum eGuardianPavilion
{
    SPELL_TRESPASSER_H                            = 63987,
    AREA_SUNREAVER_PAVILION                       = 4676,

    AREA_SILVER_COVENANT_PAVILION                 = 4677,
    SPELL_TRESPASSER_A                            = 63986,
};

struct npc_guardian_pavilionAI : public Scripted_NoMovementAI
{
    npc_guardian_pavilionAI(Creature* pCreature) : Scripted_NoMovementAI(pCreature) {}

    void MoveInLineOfSight(Unit* pWho)
    {
        if (me->GetAreaId() != AREA_SUNREAVER_PAVILION && me->GetAreaId() != AREA_SILVER_COVENANT_PAVILION)
            return;

        if (!pWho || pWho->GetTypeId() != TYPEID_PLAYER || !me->IsHostileTo(pWho) || !me->isInBackInMap(pWho, 5.0f))
            return;

        if (pWho->HasAura(SPELL_TRESPASSER_H) || pWho->HasAura(SPELL_TRESPASSER_A))
            return;

        if (pWho->ToPlayer()->GetTeamId() == TEAM_ALLIANCE)
            pWho->CastSpell(pWho, SPELL_TRESPASSER_H, true);
        else
            pWho->CastSpell(pWho, SPELL_TRESPASSER_A, true);

    }
};

CreatureAI* GetAI_npc_guardian_pavilion(Creature* pCreature)
{
    return new npc_guardian_pavilionAI (pCreature);
}

void AddSC_icecrown()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_arete";
    newscript->pGossipHello = &GossipHello_npc_arete;
    newscript->pGossipSelect = &GossipSelect_npc_arete;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_dame_evniki_kapsalis";
    newscript->pGossipHello = &GossipHello_npc_dame_evniki_kapsalis;
    newscript->pGossipSelect = &GossipSelect_npc_dame_evniki_kapsalis;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_squire_david";
    newscript->pGossipHello = &GossipHello_npc_squire_david;
    newscript->pGossipSelect = &GossipSelect_npc_squire_david;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_argent_valiant";
    newscript->GetAI = &GetAI_npc_argent_valiant;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_argent_tournament_post";
    newscript->GetAI = &GetAI_npc_argent_tournament_post;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_alorah_and_grimmin";
    newscript->GetAI = &GetAI_npc_alorah_and_grimmin;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_guardian_pavilion";
    newscript->GetAI = &GetAI_npc_guardian_pavilion;
    newscript->RegisterSelf();
}
