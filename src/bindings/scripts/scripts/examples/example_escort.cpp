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
SDName: Example_Escort
SD%Complete: 100
SDComment: Script used for testing escortAI
SDCategory: Script Examples
EndScriptData */
#include "precompiled.h"
#include "escort_ai.h"
enum eEnums
{
    NPC_FELBOAR                 = 21878,
    SPELL_DEATH_COIL            = 33130,
    SPELL_ELIXIR_OF_FORTITUDE   = 3593,
    SPELL_BLUE_FIREWORK         = 11540,
    SAY_AGGRO1                  = -1999910,
    SAY_AGGRO2                  = -1999911,
    SAY_WP_1                    = -1999912,
    SAY_WP_2                    = -1999913,
    SAY_WP_3                    = -1999914,
    SAY_WP_4                    = -1999915,
    SAY_DEATH_1                 = -1999916,
    SAY_DEATH_2                 = -1999917,
    SAY_DEATH_3                 = -1999918,
    SAY_SPELL                   = -1999919,
    SAY_RAND_1                  = -1999920,
    SAY_RAND_2                  = -1999921
};
#define GOSSIP_ITEM_1   "Click to Test Escort(Attack, Run)"
#define GOSSIP_ITEM_2   "Click to Test Escort(NoAttack, Walk)"
#define GOSSIP_ITEM_3   "Click to Test Escort(NoAttack, Run)"
struct TRINITY_DLL_DECL example_escortAI : public npc_escortAI
{
    // CreatureAI functions
    example_escortAI(Creature* pCreature) : npc_escortAI(pCreature) { }
    uint32 m_uiDeathCoilTimer;
    uint32 m_uiChatTimer;
    void JustSummoned(Creature* pSummoned)
    {
        pSummoned->AI()->AttackStart(m_creature);
    }
    // Pure Virtual Functions (Have to be implemented)
    void WaypointReached(uint32 uiWP)
    {
        switch (uiWP)
        {
            case 1:
                DoScriptText(SAY_WP_1, m_creature);
                break;
            case 3:
                DoScriptText(SAY_WP_2, m_creature);
                m_creature->SummonCreature(NPC_FELBOAR, m_creature->GetPositionX()+5.0f, m_creature->GetPositionY()+7.0f, m_creature->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                break;
            case 4:
                if (Player* pPlayer = GetPlayerForEscort())
                {
                    //pTmpPlayer is the target of the text
                    DoScriptText(SAY_WP_3, m_creature, pPlayer);
                    //pTmpPlayer is the source of the text
                    DoScriptText(SAY_WP_4, pPlayer);
                }
                break;
        }
    }
    void EnterCombat(Unit* pWho)
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (Player* pPlayer = GetPlayerForEscort())
                DoScriptText(SAY_AGGRO1, m_creature, pPlayer);
        }
        else
            DoScriptText(SAY_AGGRO2, m_creature);
    }
    void Reset()
    {
        m_uiDeathCoilTimer = 4000;
        m_uiChatTimer = 4000;
    }
    void JustDied(Unit* pKiller)
    {
        if (HasEscortState(STATE_ESCORT_ESCORTING))
        {
            if (Player* pPlayer = GetPlayerForEscort())
            {
                // not a likely case, code here for the sake of example
                if (pKiller == m_creature)
                {
                    DoScriptText(SAY_DEATH_1, m_creature, pPlayer);
                }
                else
                    DoScriptText(SAY_DEATH_2, m_creature, pPlayer);
            }
        }
        else
            DoScriptText(SAY_DEATH_3, m_creature);
    }
    void UpdateAI(const uint32 uiDiff)
    {
        //Must update npc_escortAI
        npc_escortAI::UpdateAI(uiDiff);
        //Combat check
        if (m_creature->getVictim())
        {
            if (m_uiDeathCoilTimer < uiDiff)
            {
                DoScriptText(SAY_SPELL, m_creature);
                m_creature->CastSpell(m_creature->getVictim(), SPELL_DEATH_COIL, false);
                m_uiDeathCoilTimer = 4000;
            }
            else
                m_uiDeathCoilTimer -= uiDiff;
        }
        else
        {
            //Out of combat but being escorted
            if (HasEscortState(STATE_ESCORT_ESCORTING))
            {
                if (m_uiChatTimer < uiDiff)
                {
                    if (m_creature->HasAura(SPELL_ELIXIR_OF_FORTITUDE, 0))
                    {
                        DoScriptText(SAY_RAND_1, m_creature);
                        m_creature->CastSpell(m_creature, SPELL_BLUE_FIREWORK, false);
                    }
                    else
                    {
                        DoScriptText(SAY_RAND_2, m_creature);
                        m_creature->CastSpell(m_creature, SPELL_ELIXIR_OF_FORTITUDE, false);
                    }
                    m_uiChatTimer = 12000;
                }
                else
                    m_uiChatTimer -= uiDiff;
            }
        }
    }
};
CreatureAI* GetAI_example_escort(Creature* pCreature)
{
    return new example_escortAI(pCreature);
}
bool GossipHello_example_escort(Player* pPlayer, Creature* pCreature)
{
    pPlayer->TalkedToCreature(pCreature->GetEntry(), pCreature->GetGUID());
    pCreature->prepareGossipMenu(pPlayer, 0);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);
    pCreature->sendPreparedGossip(pPlayer);
    return true;
}
bool GossipSelect_example_escort(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    npc_escortAI* pEscortAI = CAST_AI(example_escortAI, pCreature->AI());
    switch(uiAction)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pEscortAI)
                pEscortAI->Start(true, true, pPlayer->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pEscortAI)
                pEscortAI->Start(false, false, pPlayer->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            pPlayer->CLOSE_GOSSIP_MENU();
            if (pEscortAI)
                pEscortAI->Start(false, true, pPlayer->GetGUID());
            break;
        default:
            return false;                                   // nothing defined      -> trinity core handling
    }
    return true;                                            // no default handling  -> prevent trinity core handling
}
void AddSC_example_escort()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "example_escort";
    newscript->GetAI = &GetAI_example_escort;
    newscript->pGossipHello = &GossipHello_example_escort;
    newscript->pGossipSelect = &GossipSelect_example_escort;
    newscript->RegisterSelf();
}
