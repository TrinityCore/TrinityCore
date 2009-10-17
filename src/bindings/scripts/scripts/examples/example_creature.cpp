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

#include "precompiled.h"

// **** This script is designed as an example for others to build on ****
// **** Please modify whatever you'd like to as this script is only for developement ****

// **** Script Info ****
// This script is written in a way that it can be used for both friendly and hostile monsters
// Its primary purpose is to show just how much you can really do with scripts
// I recommend trying it out on both an agressive NPC and on friendly npc

// **** Quick Info ****
// Functions with Handled Function marked above them are functions that are called automatically by the core
// Functions that are marked Custom Function are functions I've created to simplify code

enum
{
    //List of text id's. The text is stored in database, also in a localized version
    //(if translation not exist for the textId, default english text will be used)
    //Not required to define in this way, but simplify if changes are needed.
    SAY_AGGRO       = -1999900,
    SAY_RANDOM_0    = -1999901,
    SAY_RANDOM_1    = -1999902,
    SAY_RANDOM_2    = -1999903,
    SAY_RANDOM_3    = -1999904,
    SAY_RANDOM_4    = -1999905,
    SAY_BESERK      = -1999906,
    SAY_PHASE       = -1999907,
    SAY_DANCE       = -1999908,
    SAY_SALUTE      = -1999909,

    //List of spells. Not required to define them in this way, but will make it easier to maintain in case spellId change
    SPELL_BUFF      = 25661,
    SPELL_ONE       = 12555,
    SPELL_ONE_ALT   = 24099,
    SPELL_TWO       = 10017,
    SPELL_THREE     = 26027,
    SPELL_ENRAGE    = 23537,
    SPELL_BESERK    = 32309,

    FACTION_WORGEN  = 24
};

//List of gossip item texts. Items will appear in the gossip window.
#define GOSSIP_ITEM     "I'm looking for a fight"

struct TRINITY_DLL_DECL example_creatureAI : public ScriptedAI
{
    //*** HANDLED FUNCTION ***
    //This is the constructor, called only once when the Creature is first created
    example_creatureAI(Creature *c) : ScriptedAI(c) {Reset();}

    //*** CUSTOM VARIABLES ****
    //These variables are for use only by this individual script.
    //Nothing else will ever call them but us.

    uint32 m_uiSay_Timer;                                   //Timer for random chat
    uint32 m_uiRebuff_Timer;                                //Timer for rebuffing
    uint32 m_uiSpell_1_Timer;                               //Timer for spell 1 when in combat
    uint32 m_uiSpell_2_Timer;                               //Timer for spell 1 when in combat
    uint32 m_uiSpell_3_Timer;                               //Timer for spell 1 when in combat
    uint32 m_uiBeserk_Timer;                                //Timer until we go into Beserk (enraged) mode
    uint32 m_uiPhase;                                       //The current battle phase we are in
    uint32 m_uiPhase_Timer;                                 //Timer until phase transition

    //*** HANDLED FUNCTION ***
    //This is called whenever the core decides we need to evade
    void Reset()
    {
        m_uiPhase = 1;                                      //Start in phase 1
        m_uiPhase_Timer = 60000;                            //60 seconds
        m_uiSpell_1_Timer = 5000;                           //5 seconds
        m_uiSpell_2_Timer = 37000;                          //37 seconds
        m_uiSpell_3_Timer = 19000;                          //19 seconds
        m_uiBeserk_Timer = 120000;                          //2 minutes
    }

    //*** HANDLED FUNCTION ***
    //Attack Start is called whenever someone hits us.
    void EnterCombat(Unit* pWho)
    {
        //Say some stuff
        DoScriptText(SAY_AGGRO, m_creature, pWho);
    }

    //Our Recive emote function
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
    //Update AI is called Every single map update (roughly once every 100ms if a player is within the grid)
    void UpdateAI(const uint32 uiDiff)
    {
        //Out of combat timers
        if (!m_creature->getVictim())
        {
            //Random Say timer
            if (m_uiSay_Timer < uiDiff)
            {
                //Random switch between 5 outcomes
                DoScriptText(RAND(SAY_RANDOM_0,SAY_RANDOM_1,SAY_RANDOM_2,SAY_RANDOM_3,SAY_RANDOM_4), m_creature);

                m_uiSay_Timer = 45000;                      //Say something agian in 45 seconds
            }
            else
                m_uiSay_Timer -= uiDiff;

            //Rebuff timer
            if (m_uiRebuff_Timer < uiDiff)
            {
                DoCast(m_creature, SPELL_BUFF);
                m_uiRebuff_Timer = 900000;                  //Rebuff agian in 15 minutes
            }
            else
                m_uiRebuff_Timer -= uiDiff;
        }

        //Return since we have no target
        if (!UpdateVictim())
            return;

        //Spell 1 timer
        if (m_uiSpell_1_Timer < uiDiff)
        {
            //Cast spell one on our current target.
            if (rand()%50 > 10)
                DoCast(m_creature->getVictim(), SPELL_ONE_ALT);
            else if (m_creature->IsWithinDist(m_creature->getVictim(), 25.0f))
                DoCast(m_creature->getVictim(), SPELL_ONE);

            m_uiSpell_1_Timer = 5000;
        }
        else
            m_uiSpell_1_Timer -= uiDiff;

        //Spell 2 timer
        if (m_uiSpell_2_Timer < uiDiff)
        {
            //Cast spell one on our current target.
            DoCast(m_creature->getVictim(), SPELL_TWO);
            m_uiSpell_2_Timer = 37000;
        }
        else
            m_uiSpell_2_Timer -= uiDiff;

        //Beserk timer
        if (m_uiPhase > 1)
        {
            //Spell 3 timer
            if (m_uiSpell_3_Timer < uiDiff)
            {
                //Cast spell one on our current target.
                DoCast(m_creature->getVictim(), SPELL_THREE);

                m_uiSpell_3_Timer = 19000;
            }
            else
                m_uiSpell_3_Timer -= uiDiff;

            if (m_uiBeserk_Timer < uiDiff)
            {
                //Say our line then cast uber death spell
                DoScriptText(SAY_BESERK, m_creature, m_creature->getVictim());
                DoCast(m_creature->getVictim(), SPELL_BESERK);

                //Cast our beserk spell agian in 12 seconds if we didn't kill everyone
                m_uiBeserk_Timer = 12000;
            }
            else
                m_uiBeserk_Timer -= uiDiff;
        }
        else if (m_uiPhase == 1)                            //Phase timer
        {
            if (m_uiPhase_Timer < uiDiff)
            {
                //Go to next phase
                ++m_uiPhase;
                DoScriptText(SAY_PHASE, m_creature);
                DoCast(m_creature, SPELL_ENRAGE);
            }
            else
                m_uiPhase_Timer -= uiDiff;
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
        //Set our faction to hostile twoards all
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
