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
SDName: Battleground
SD%Complete: 100
SDComment: Spirit guides in battlegrounds will revive all players every 30 sec
SDCategory: Battlegrounds
EndScriptData */

#include "scriptPCH.h"
#include <Creature.cpp>
#include <Server/Packets/PartyPackets.h>

// **** Script Info ****
// Spiritguides in battlegrounds resurrecting many players at once
// every 30 seconds - through a channeled spell, which gets autocasted
// the whole time
// if spiritguide despawns all players around him will get teleported
// to the next spiritguide
// here i'm not sure, if a dummyspell exist for it

// **** Quick Info ****
// battleground spiritguides - this script handles gossipHello
// and JustDied also it let autocast the channel-spell

enum
{
    SPELL_SPIRIT_HEAL_CHANNEL       = 22011,                // Spirit Heal Channel

    SPELL_SPIRIT_HEAL               = 22012,                // Spirit Heal

    SPELL_WAITING_TO_RESURRECT      = 2584                  // players who cancel this aura don't want a resurrection
};

struct npc_spirit_guideAI : ScriptedAI
{
    explicit npc_spirit_guideAI(Creature* pCreature) : ScriptedAI(pCreature)
    {
        uiTimerRez = 0;

        npc_spirit_guideAI::Reset();
    }

    void Reset() override
    {
    }

    uint32 uiTimerRez;

    uint32 GetData(uint32 /*type*/) 
    {
        return uiTimerRez;
    }

    void UpdateAI(uint32 const uiDiff) override
    {
        if (uiTimerRez < uiDiff)
        {
            //creature->InterruptNonMeleeSpells(true);
           // creature->CastSpell(creature, SPELL_SPIRIT_HEAL, true);
           // creature->CastSpell(creature, SPELL_SPIRIT_HEAL_CHANNEL, false);
            uiTimerRez = 30000;
        }
        else
            uiTimerRez -= uiDiff;
    }

    void CorpseRemoved(uint32 &) override
    {
        // TODO: would be better to cast a dummy spell
       // Map* pMap = ->GetMap();

        //if (!pMap || !pMap->IsBattleGround())
            return;

       // Map::PlayerList const &PlayerList = pMap->GetPlayers();

        //for (const auto& itr : PlayerList)
        {
           // Player* pPlayer = itr.getSource();
         //   if (!Player || !Player->IsWithinDistInMap(creature, 20.0f) || !pPlayer->HasAura(SPELL_WAITING_TO_RESURRECT) || pPlayer->IsAlive())
           //     continue;

            // repop player again - now this node won't be counted and another node is searched
           // Player->RepopAtGraveyard();
        }
    }

    void AttackedBy(Unit* /*pWho*/) 
    {
    }

    void AttackStart(Unit* /*pWho*/) override
    {
    }

    void DamageTaken(Unit* /*pFrom*/, uint32 &damage) 
    {
        damage = 0;
    }
};

bool GossipHello_npc_spirit_guide(Player* pPlayer, Creature* pCreature)
{
    pPlayer->CastSpell(pPlayer, SPELL_WAITING_TO_RESURRECT, true);
    return true;
}

CreatureAI* GetAI_npc_spirit_guide(Creature* pCreature)
{
    return new npc_spirit_guideAI(pCreature);
}

enum
{
    SPELL_SPAWN_EFFECT     = 23235,
    SPELL_BUFF_ALLIANCE_15 = 23033,
    SPELL_BUFF_HORDE_15    = 23033,
    SPELL_BUFF_ALLIANCE_10 = 23574,
    SPELL_BUFF_HORDE_10    = 23033,
};
/*
[SQL]
-- script_name
UPDATE creature_template SET script_name="npc_etendard" WHERE entry IN
(
-- Alliance Alterac
14752,
-- Alliance
14465,
-- Horde Alterac
14751,
-- Horde
14466
);
-- Ajout des sorts
-- Alliance Alterac
UPDATE creature_template SET spell1=23574 WHERE entry = 14752;
-- Alliance
UPDATE creature_template SET spell1=23033 WHERE entry = 14465;
-- Horde Alterac
-- Horde
UPDATE creature_template SET spell1=23576 WHERE entry = 14751;
UPDATE creature_template SET spell1=23036 WHERE entry = 14466;
*/
struct npc_etendardAI : CreatureAI
{
    explicit npc_etendardAI(Creature* pCreature) : CreatureAI(pCreature)
    {
        m_bSpawned = false;
   //     m_bAutoRepeatSpell = pCreature->GetCreatureInfo()->spells[0];
    }

    bool m_bSpawned;
    uint32 m_bAutoRepeatSpell;

    void UpdateAI(uint32 const uiDiff) 
    {
        if (!m_bSpawned)
        {
           // creature->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_IMMUNE_TO_NPC);
           // creature->SetDefaultMovementType(IDLE_MOTION_TYPE);
            //creature->CastSpell(creature, SPELL_SPAWN_EFFECT, true);
            //creature->CastSpell(creature, m_bAutoRepeatSpell, true);
            m_bSpawned = true;
        }
    }
};


CreatureAI* GetAI_npc_etendard(Creature* pCreature)
{
   
}

void AddSC_battleground()
{
    void AddSC_npc_etendardAI();
    void AddSC_GetAI_npc_spirit_guide();
    void AddSC_GossipHello_npc_spirit_guide();
    void AddSC_npc_etendard();
    void AddSC_GetAI_npc_etendard();
    void AddSC_npc_spirit_guide();
}
