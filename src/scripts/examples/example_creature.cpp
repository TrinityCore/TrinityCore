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
SDName: Example_Creature
SD%Complete: 100
SDComment: Short custom scripting example
SDCategory: Script Examples
EndScriptData */

#include "ScriptedPch.h"
#include "SpellId.h"

// **** This script is designed as an example for others to build on ****
// **** Please modify whatever you'd like to as this script is only for developement ****

// **** Script Info ****
// This script is written in a way that it can be used for both friendly and hostile monsters
// Its primary purpose is to show just how much you can really do with scripts
// I recommend trying it out on both an agressive NPC and on friendly npc

// **** Quick Info ****
// Functions with Handled Function marked above them are functions that are called automatically by the core
// Functions that are marked Custom Function are functions I've created to simplify code

enum Yells
{
    //List of text id's. The text is stored in database, also in a localized version
    //(if translation not exist for the textId, default english text will be used)
    //Not required to define in this way, but simplify if changes are needed.
    SAY_AGGRO                                   = -1999900,
    SAY_RANDOM_0                                = -1999901,
    SAY_RANDOM_1                                = -1999902,
    SAY_RANDOM_2                                = -1999903,
    SAY_RANDOM_3                                = -1999904,
    SAY_RANDOM_4                                = -1999905,
    SAY_BERSERK                                 = -1999906,
    SAY_PHASE                                   = -1999907,
    SAY_DANCE                                   = -1999908,
    SAY_SALUTE                                  = -1999909,
    SAY_EVADE                                   = -1999910,
};

enum Spells
{
    // List of spells. 
    // Not required to define them in this way, but will make it easier to maintain in case spellId change
    SPELL_BUFF                                  = SPELL_INCREASED_STAMINA_25661,
    SPELL_ONE                                   = SPELL_PUMMEL_12555,
    SPELL_ONE_ALT                               = SPELL_POISON_BOLT_VOLLEY_24099,
    SPELL_TWO                                   = SPELL_FROST_HOLD_10017,
    SPELL_THREE                                 = SPELL_KNOCKBACK_26027,
    SPELL_FRENZY                                = SPELL_FRENZY_23537,
    SPELL_BERSERK                               = SPELL_BERSERK_32965,
};

enum eEnums
{
    // any other constants
    FACTION_WORGEN                              = 24
};

//List of gossip item texts. Items will appear in the gossip window.
#define GOSSIP_ITEM     "I'm looking for a fight"

struct example_creatureAI : public ScriptedAI
{
    //*** HANDLED FUNCTION ***
    //This is the constructor, called only once when the Creature is first created
    example_creatureAI(Creature *c) : ScriptedAI(c) {}

    //*** CUSTOM VARIABLES ****
    //These variables are for use only by this individual script.
    //Nothing else will ever call them but us.

    uint32 m_uiSayTimer;                                    // Timer for random chat
    uint32 m_uiRebuffTimer;                                 // Timer for rebuffing
    uint32 m_uiSpell1Timer;                                 // Timer for spell 1 when in combat
    uint32 m_uiSpell2Timer;                                 // Timer for spell 1 when in combat
    uint32 m_uiSpell3Timer;                                 // Timer for spell 1 when in combat
    uint32 m_uiBeserkTimer;                                 // Timer until we go into Beserk (enraged) mode
    uint32 m_uiPhase;                                       // The current battle phase we are in
    uint32 m_uiPhaseTimer;                                  // Timer until phase transition

    //*** HANDLED FUNCTION ***
    //This is called after spawn and whenever the core decides we need to evade
    void Reset()
    {
        m_uiPhase = 1;                                      // Start in phase 1
        m_uiPhaseTimer = 60000;                             // 60 seconds
        m_uiSpell1Timer = 5000;                             //  5 seconds
        m_uiSpell2Timer = urand(10000,20000);               // between 10 and 20 seconds
        m_uiSpell3Timer = 19000;                            // 19 seconds
        m_uiBeserkTimer = 120000;                           //  2 minutes

        m_creature->RestoreFaction();
    }

    //*** HANDLED FUNCTION ***
    // Enter Combat called once per combat
    void EnterCombat(Unit* pWho)
    {
        //Say some stuff
        DoScriptText(SAY_AGGRO, m_creature, pWho);
    }

    //*** HANDLED FUNCTION ***
    // Attack Start is called when victim change (including at start of combat)
    // By default, attack pWho and start movement toward the victim.
    //void AttackStart(Unit* pWho)
    //{
    //    ScriptedAI::AttackStart(pWho);
    //}

    //*** HANDLED FUNCTION ***
    // Called when going out of combat. Reset is called just after.
    void EnterEvadeMode()
    {
        DoScriptText(SAY_EVADE, m_creature);
    }

    //*** HANDLED FUNCTION ***
    //Our Receive emote function
    void ReceiveEmote(Player* pPlayer, uint32 uiTextEmote)
    {
        m_creature->HandleEmoteCommand(uiTextEmote);

        switch(uiTextEmote)
        {
            case TEXTEMOTE_DANCE:
                DoScriptText(SAY_DANCE, m_creature);
                break;
            case TEXTEMOTE_SALUTE:
                DoScriptText(SAY_SALUTE, m_creature);
                break;
        }
     }

    //*** HANDLED FUNCTION ***
    //Update AI is called Every single map update (roughly once every 50ms if a player is within the grid)
    void UpdateAI(const uint32 uiDiff)
    {
        //Out of combat timers
        if (!m_creature->getVictim())
        {
            //Random Say timer
            if (m_uiSayTimer <= uiDiff)
            {
                //Random switch between 5 outcomes
                DoScriptText(RAND(SAY_RANDOM_0,SAY_RANDOM_1,SAY_RANDOM_2,SAY_RANDOM_3,SAY_RANDOM_4), m_creature);

                m_uiSayTimer = 45000;                      //Say something agian in 45 seconds
            }
            else
                m_uiSayTimer -= uiDiff;

            //Rebuff timer
            if (m_uiRebuffTimer <= uiDiff)
            {
                DoCast(m_creature, SPELL_BUFF);
                m_uiRebuffTimer = 900000;                  //Rebuff agian in 15 minutes
            }
            else
                m_uiRebuffTimer -= uiDiff;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Spell 1 timer
        if (m_uiSpell1Timer <= uiDiff)
        {
            //Cast spell one on our current target.
            if (rand()%50 > 10)
                DoCast(m_creature->getVictim(), SPELL_ONE_ALT);
            else if (m_creature->IsWithinDist(m_creature->getVictim(), 25.0f))
                DoCast(m_creature->getVictim(), SPELL_ONE);

            m_uiSpell1Timer = 5000;
        }
        else
            m_uiSpell1Timer -= uiDiff;

        //Spell 2 timer
        if (m_uiSpell2Timer <= uiDiff)
        {
            //Cast spell two on our current target.
            DoCast(m_creature->getVictim(), SPELL_TWO);
            m_uiSpell2Timer = 37000;
        }
        else
            m_uiSpell2Timer -= uiDiff;

        //Beserk timer
        if (m_uiPhase > 1)
        {
            //Spell 3 timer
            if (m_uiSpell3Timer <= uiDiff)
            {
                //Cast spell one on our current target.
                DoCast(m_creature->getVictim(), SPELL_THREE);

                m_uiSpell3Timer = 19000;
            }
            else
                m_uiSpell3Timer -= uiDiff;

            if (m_uiBeserkTimer <= uiDiff)
            {
                //Say our line then cast uber death spell
                DoScriptText(SAY_BERSERK, m_creature, m_creature->getVictim());
                DoCast(m_creature->getVictim(), SPELL_BERSERK);

                //Cast our beserk spell agian in 12 seconds if we didn't kill everyone
                m_uiBeserkTimer = 12000;
            }
            else
                m_uiBeserkTimer -= uiDiff;
        }
        else if (m_uiPhase == 1)                            //Phase timer
        {
            if (m_uiPhaseTimer <= uiDiff)
            {
                //Go to next phase
                ++m_uiPhase;
                DoScriptText(SAY_PHASE, m_creature);
                DoCast(m_creature, SPELL_FRENZY);
            }
            else
                m_uiPhaseTimer -= uiDiff;
        }

        DoMeleeAttackIfReady();
    }
};

//This is the GetAI method used by all scripts that involve AI
//It is called every time a new Creature using this script is created
CreatureAI* GetAI_example_creature(Creature* pCreature)
{
    return new example_creatureAI (pCreature);
}

//This function is called when the player clicks an option on the gossip menu
bool GossipSelect_example_creature(Player* pPlayer, Creature* pCreature, uint32 uiSender, uint32 uiAction)
{
    if (uiAction == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        //Set our faction to hostile towards all
        pCreature->setFaction(FACTION_WORGEN);
        pCreature->AI()->AttackStart(pPlayer);
    }

    return true;
}

//This function is called when the player opens the gossip menu
bool GossipHello_example_creature(Player* pPlayer, Creature* pCreature)
{
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
    pPlayer->SEND_GOSSIP_MENU(907, pCreature->GetGUID());

    return true;
}

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_example_creature()
{
    Script* newscript;

    newscript = new Script;
    newscript->Name = "example_creature";
    newscript->GetAI = &GetAI_example_creature;
    newscript->pGossipHello = &GossipHello_example_creature;
    newscript->pGossipSelect = &GossipSelect_example_creature;
    newscript->RegisterSelf();
}
