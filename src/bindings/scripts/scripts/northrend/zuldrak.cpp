/*
 * Copyright (C) 2009 Trinity <http://www.trinitycore.org/>
 *
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

#include "precompiled.h"

/*####
## npc_drakuru_shackles
####*/

enum eDrakuruShackles
{
    SPELL_LEFT_CHAIN           = 59951,
    SPELL_RIGHT_CHAIN          = 59952,
    SPELL_UNLOCK_SHACKLE       = 55083,
    SPELL_FREE_RAGECLAW        = 55223,

    NPC_RAGECLAW               = 29686
};

struct TRINITY_DLL_DECL npc_drakuru_shacklesAI : public ScriptedAI
{
    npc_drakuru_shacklesAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    Unit* Rageclaw;

    void Reset()
    {
        m_creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        float x, y, z;
        Rageclaw = NULL;
        m_creature->GetClosePoint(x, y, z, m_creature->GetObjectSize()/3,0.1);
        if (Unit* summon = m_creature->SummonCreature(NPC_RAGECLAW,x,y,z,0,TEMPSUMMON_DEAD_DESPAWN,1000))
            DoActionOnRageclaw(true,summon);
    }

    void DoActionOnRageclaw(bool bLocking, Unit* pWho)
    {
        if (!pWho)
            return;

        if (bLocking)
        {
            if (pWho)
            {
                Rageclaw = pWho;

                m_creature->SetInFront(Rageclaw);
                Rageclaw->SetInFront(m_creature);

                DoCast(Rageclaw, SPELL_LEFT_CHAIN, true);
                DoCast(Rageclaw, SPELL_RIGHT_CHAIN, true);
            }
        }
        else
        {
            DoCast(Rageclaw, SPELL_FREE_RAGECLAW, true);
            CAST_PLR(pWho)->CastSpell(Rageclaw, SPELL_UNLOCK_SHACKLE, true);
            m_creature->setDeathState(DEAD);
        }
    }

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_UNLOCK_SHACKLE)
        {
            if (Rageclaw)
                DoActionOnRageclaw(false, pCaster);
            else
                m_creature->setDeathState(JUST_DIED);
        }
    }
};

CreatureAI* GetAI_npc_drakuru_shackles(Creature* pCreature)
{
    return new npc_drakuru_shacklesAI (pCreature);
}

/*####
## npc_captured_rageclaw
####*/

enum eRageclaw
{
    SPELL_UNSHACKLED           = 55085,
    SPELL_KNEEL                = 39656
};

const char * SAY_RAGECLAW_1 =      "I poop on you, trollses!";
const char * SAY_RAGECLAW_2 =      "ARRRROOOOGGGGAAAA!";
const char * SAY_RAGECLAW_3 =      "No more mister nice wolvar!";

#define SAY_RAGECLAW RAND(SAY_RAGECLAW_1,SAY_RAGECLAW_2,SAY_RAGECLAW_3)

struct TRINITY_DLL_DECL npc_captured_rageclawAI : public ScriptedAI
{
    npc_captured_rageclawAI(Creature* pCreature) : ScriptedAI(pCreature) {}

    uint32 DespawnTimer;
    bool Despawn;

    void Reset()
    {
        Despawn = false;
        DespawnTimer = 0;
        m_creature->setFaction(35);
        DoCast(m_creature, SPELL_KNEEL, true); // Little Hack for kneel - Thanks Illy :P
    }

    void MoveInLineOfSight(Unit *who){}

    void SpellHit(Unit* pCaster, const SpellEntry* pSpell)
    {
        if (pSpell->Id == SPELL_FREE_RAGECLAW)
        {
            m_creature->RemoveAurasDueToSpell(SPELL_LEFT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_RIGHT_CHAIN);

            m_creature->RemoveAurasDueToSpell(SPELL_KNEEL);

            m_creature->setFaction(m_creature->GetCreatureInfo()->faction_H);

            DoCast(m_creature, SPELL_UNSHACKLED, true);
            m_creature->MonsterSay(SAY_RAGECLAW, LANG_UNIVERSAL, NULL);
            m_creature->GetMotionMaster()->MoveRandom(10);

            DespawnTimer = 10000;
            Despawn = true;
        }
    }

    void UpdateAI(const uint32 uiDiff)
    {
        if (m_creature->getVictim())
        {
            DoMeleeAttackIfReady();
            return;
        }

        if (!Despawn)
            return;

        if (DespawnTimer <= uiDiff)
            m_creature->setDeathState(JUST_DIED);
        else DespawnTimer -= uiDiff;
   }
};

CreatureAI* GetAI_npc_captured_rageclaw(Creature* pCreature)
{
    return new npc_captured_rageclawAI (pCreature);
}

/*####
## npc_gymer
####*/

#define    GOSSIP_ITEM_G "I'm ready, Gymer. Let's go!"

enum eGymer
{
    QUEST_STORM_KING_VENGEANCE    = 12919,
    SPELL_GYMER                   = 55568
};

bool GossipHello_npc_gymer(Player* pPlayer, Creature* pCreature)
{
    if (pCreature->isQuestGiver())
        pPlayer->PrepareQuestMenu(pCreature->GetGUID());

    pPlayer->SEND_GOSSIP_MENU(pCreature->GetNpcTextId(), pCreature->GetGUID());

    if (pPlayer->GetQuestStatus(QUEST_STORM_KING_VENGEANCE) == QUEST_STATUS_INCOMPLETE)
    {
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_G, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
        pPlayer->SEND_GOSSIP_MENU(13640, pCreature->GetGUID());
    }

    return true;
}

bool GossipSelect_npc_gymer(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->CastSpell(pPlayer, SPELL_GYMER, true);
    }

    return true;
}

void AddSC_zuldrak()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name = "npc_drakuru_shackles";
    newscript->GetAI = &GetAI_npc_drakuru_shackles;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_captured_rageclaw";
    newscript->GetAI = &GetAI_npc_captured_rageclaw;
    newscript->RegisterSelf();

    newscript = new Script;
    newscript->Name = "npc_gymer";
    newscript->pGossipHello = &GossipHello_npc_gymer;
    newscript->pGossipSelect = &GossipSelect_npc_gymer;
    newscript->RegisterSelf();
}
