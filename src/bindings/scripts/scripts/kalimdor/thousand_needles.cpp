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
SDComment: Support for Quest: 1950, 4770, 4904, 4966
SDCategory: Thousand Needles
EndScriptData */

/* ContentData
npc_kanati
npc_lakota_windsong
npc_swiftmountain
npc_plucky
EndContentData */

#include "precompiled.h"
#include "../npc/npc_escortAI.h"

/*#####
# npc_kanati
######*/

enum
{
    SAY_KAN_START              = -1000410,

    QUEST_PROTECT_KANATI        = 4966,
    NPC_GALAK_ASS               = 10720
};

const float m_afGalakLoc[]= {-4867.387695, -1357.353760, -48.226 };

struct TRINITY_DLL_DECL npc_kanatiAI : public npc_escortAI
{
    npc_kanatiAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset() { }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 0:
                DoScriptText(SAY_KAN_START, m_creature);
                DoSpawnGalak();
                break;
            case 1:
                if (Player* pPlayer = Unit::GetPlayer(PlayerGUID))
                    pPlayer->GroupEventHappens(QUEST_PROTECT_KANATI, m_creature);
                break;
        }
    }

    void DoSpawnGalak()
    {
        for(int i = 0; i < 3; ++i)
            m_creature->SummonCreature(NPC_GALAK_ASS,
            m_afGalakLoc[0], m_afGalakLoc[1], m_afGalakLoc[2], 0.0f,
            TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 25000);
    }

    void JustSummoned(Creature* pSummoned)
    {
        pSummoned->AI()->AttackStart(m_creature);
    }
};

CreatureAI* GetAI_npc_kanati(Creature* pCreature)
{
    npc_kanatiAI* pTempAI = new npc_kanatiAI(pCreature);

    pTempAI->FillPointMovementListForCreature();

    return (CreatureAI*)pTempAI;
}

bool QuestAccept_npc_kanati(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_PROTECT_KANATI)
    {
        if (npc_kanatiAI* pEscortAI = CAST_AI(npc_kanatiAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest, true);
    }
    return true;
}

/*######
# npc_lakota_windsong
######*/

enum
{
    SAY_LAKO_START              = -1000365,
    SAY_LAKO_LOOK_OUT           = -1000366,
    SAY_LAKO_HERE_COME          = -1000367,
    SAY_LAKO_MORE               = -1000368,
    SAY_LAKO_END                = -1000369,

    QUEST_FREE_AT_LAST          = 4904,
    NPC_GRIM_BANDIT             = 10758,
    FACTION_ESCORTEE_LAKO       = 232,                      //guessed

    ID_AMBUSH_1                 = 0,
    ID_AMBUSH_2                 = 2,
    ID_AMBUSH_3                 = 4
};

float m_afBanditLoc[6][6]=
{
    {-4905.479492, -2062.732666, 84.352},
    {-4915.201172, -2073.528320, 84.733},
    {-4878.883301, -1986.947876, 91.966},
    {-4877.503906, -1966.113403, 91.859},
    {-4767.985352, -1873.169189, 90.192},
    {-4788.861328, -1888.007813, 89.888}
};

struct TRINITY_DLL_DECL npc_lakota_windsongAI : public npc_escortAI
{
    npc_lakota_windsongAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset() { }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 8:
                DoScriptText(SAY_LAKO_LOOK_OUT, m_creature);
                DoSpawnBandits(ID_AMBUSH_1);
                break;
            case 14:
                DoScriptText(SAY_LAKO_HERE_COME, m_creature);
                DoSpawnBandits(ID_AMBUSH_2);
                break;
            case 21:
                DoScriptText(SAY_LAKO_MORE, m_creature);
                DoSpawnBandits(ID_AMBUSH_3);
                break;
            case 45:
                if (Player* pPlayer = (Player*)Unit::GetUnit(*m_creature, PlayerGUID))
                    pPlayer->GroupEventHappens(QUEST_FREE_AT_LAST, m_creature);
                break;
        }
    }

    void DoSpawnBandits(int uiAmbushId)
    {
        for(int i = 0; i < 2; ++i)
            m_creature->SummonCreature(NPC_GRIM_BANDIT,
            m_afBanditLoc[i+uiAmbushId][0], m_afBanditLoc[i+uiAmbushId][1], m_afBanditLoc[i+uiAmbushId][2], 0.0f,
            TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
    }
};

CreatureAI* GetAI_npc_lakota_windsong(Creature* pCreature)
{
    npc_lakota_windsongAI* pTempAI = new npc_lakota_windsongAI(pCreature);

    pTempAI->FillPointMovementListForCreature();

    return (CreatureAI*)pTempAI;
}

bool QuestAccept_npc_lakota_windsong(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_FREE_AT_LAST)
    {
        DoScriptText(SAY_LAKO_START, pCreature, pPlayer);
        pCreature->setFaction(FACTION_ESCORTEE_LAKO);

        if (npc_lakota_windsongAI* pEscortAI = CAST_AI(npc_lakota_windsongAI, pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

/*######
# npc_paoka_swiftmountain
######*/

enum
{
    SAY_START           = -1000147,
    SAY_WYVERN          = -1000148,
    SAY_COMPLETE        = -1000149,

    QUEST_HOMEWARD      = 4770,
    NPC_WYVERN          = 4107,
    FACTION_ESCORTEE    = 232                               //guessed
};

float m_afWyvernLoc[3][3]=
{
    {-4990.606, -906.057, -5.343},
    {-4970.241, -927.378, -4.951},
    {-4985.364, -952.528, -5.199}
};

struct TRINITY_DLL_DECL npc_paoka_swiftmountainAI : public npc_escortAI
{
    npc_paoka_swiftmountainAI(Creature* pCreature) : npc_escortAI(pCreature) { }

    void Reset() { }

    void WaypointReached(uint32 uiPointId)
    {
        switch(uiPointId)
        {
            case 15:
                DoScriptText(SAY_WYVERN, m_creature);
                DoSpawnWyvern();
                break;
            case 26:
                DoScriptText(SAY_COMPLETE, m_creature);
                break;
            case 27:
                if (Player* pPlayer = (Player*)Unit::GetUnit(*m_creature, PlayerGUID))
                    pPlayer->GroupEventHappens(QUEST_HOMEWARD, m_creature);
                break;
        }
    }

    void DoSpawnWyvern()
    {
        for(int i = 0; i < 3; ++i)
            m_creature->SummonCreature(NPC_WYVERN,
            m_afWyvernLoc[i][0], m_afWyvernLoc[i][1], m_afWyvernLoc[i][2], 0.0f,
            TEMPSUMMON_TIMED_OR_DEAD_DESPAWN, 60000);
    }
};

CreatureAI* GetAI_npc_paoka_swiftmountain(Creature* pCreature)
{
    npc_paoka_swiftmountainAI* pTempAI = new npc_paoka_swiftmountainAI(pCreature);

    pTempAI->FillPointMovementListForCreature();

    return (CreatureAI*)pTempAI;
}

bool QuestAccept_npc_paoka_swiftmountain(Player* pPlayer, Creature* pCreature, const Quest* pQuest)
{
    if (pQuest->GetQuestId() == QUEST_HOMEWARD)
    {
        DoScriptText(SAY_START, pCreature, pPlayer);
        pCreature->setFaction(FACTION_ESCORTEE);

        if (npc_paoka_swiftmountainAI* pEscortAI = CAST_AI(npc_paoka_swiftmountainAI,pCreature->AI()))
            pEscortAI->Start(false, false, pPlayer->GetGUID(), pQuest);
    }
    return true;
}

/*#####
# npc_plucky
######*/

#define GOSSIP_P    "Please tell me the Phrase.."

enum
{
    FACTION_FRIENDLY        = 35,
    QUEST_SCOOP             = 1950,
    SPELL_PLUCKY_HUMAN      = 9192,
    SPELL_PLUCKY_CHICKEN    = 9220
};

struct TRINITY_DLL_DECL npc_pluckyAI : public ScriptedAI
{
    npc_pluckyAI(Creature *c) : ScriptedAI(c) { m_uiNormFaction = c->getFaction(); }

    uint32 m_uiNormFaction;
    uint32 m_uiResetTimer;

    void Reset()
    {
        m_uiResetTimer = 120000;

        if (m_creature->getFaction() != m_uiNormFaction)
            m_creature->setFaction(m_uiNormFaction);

        if (m_creature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
            m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

        m_creature->CastSpell(m_creature, SPELL_PLUCKY_CHICKEN, false);
    }

    void ReceiveEmote(Player* pPlayer, uint32 uiTextEmote)
    {
        if (pPlayer->GetQuestStatus(QUEST_SCOOP) == QUEST_STATUS_INCOMPLETE)
        {
            if (uiTextEmote == TEXTEMOTE_BECKON)
            {
                m_creature->setFaction(FACTION_FRIENDLY);
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                m_creature->CastSpell(m_creature, SPELL_PLUCKY_HUMAN, false);
            }
        }

        if (uiTextEmote == TEXTEMOTE_CHICKEN)
        {
            if (m_creature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
                return;
            else
            {
                m_creature->setFaction(FACTION_FRIENDLY);
                m_creature->SetFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);
                m_creature->CastSpell(m_creature, SPELL_PLUCKY_HUMAN, false);
                m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
            }
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_creature->HasFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP))
        {
            if (m_uiResetTimer < uiDiff)
            {
                if (!m_creature->getVictim())
                    EnterEvadeMode();
                else
                    m_creature->RemoveFlag(UNIT_NPC_FLAGS, UNIT_NPC_FLAG_GOSSIP);

                return;
            }
            else
                m_uiResetTimer -= uiDiff;
        }

        if (!UpdateVictim())
            return;

        DoMeleeAttackIfReady();
    }
};

bool GossipHello_npc_plucky(Player* pPlayer, Creature* pCreature)
{
    if (pPlayer->GetQuestStatus(QUEST_SCOOP) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_P, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->SEND_GOSSIP_MENU(738, pCreature->GetGUID());

    return true;
}

bool GossipSelect_npc_plucky(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            pPlayer->CompleteQuest(QUEST_SCOOP);
        break;
    }
    return true;
}

CreatureAI* GetAI_npc_plucky(Creature* pCreature)
{
    return new npc_pluckyAI(pCreature);
}

/*#####
#
######*/

void AddSC_thousand_needles()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_kanati";
    newscript->GetAI = &GetAI_npc_kanati;
    newscript->pQuestAccept = &QuestAccept_npc_kanati;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_lakota_windsong";
    newscript->GetAI = &GetAI_npc_lakota_windsong;
    newscript->pQuestAccept = &QuestAccept_npc_lakota_windsong;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_paoka_swiftmountain";
    newscript->GetAI = &GetAI_npc_paoka_swiftmountain;
    newscript->pQuestAccept = &QuestAccept_npc_paoka_swiftmountain;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_plucky";
    newscript->GetAI = &GetAI_npc_plucky;
    newscript->pGossipHello =   &GossipHello_npc_plucky;
    newscript->pGossipSelect = &GossipSelect_npc_plucky;
    newscript->RegisterSelf();
}

