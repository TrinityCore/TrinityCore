/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
SDName: Example_Creature
SD%Complete: 100
SDComment: Short custom scripting example
SDCategory: Script Examples
EndScriptData */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"

// **** This script is designed as an example for others to build on ****
// **** Please modify whatever you'd like to as this script is only for developement ****

// **** Script Info* ***
// This script is written in a way that it can be used for both friendly and hostile monsters
// Its primary purpose is to show just how much you can really do with scripts
// I recommend trying it out on both an agressive NPC and on friendly npc

// **** Quick Info* ***
// Functions with Handled Function marked above them are functions that are called automatically by the core
// Functions that are marked Custom Function are functions I've created to simplify code

enum Yells
{
    //List of text id's. The text is stored in database, also in a localized version
    //(if translation not exist for the textId, default english text will be used)
    //Not required to define in this way, but simplify if changes are needed.
    //These texts must be added to the creature texts of the npc for which the script is assigned.
    SAY_AGGRO                                   = 0, // "Let the games begin."
    SAY_RANDOM                                  = 1, // "I see endless suffering. I see torment. I see rage. I see everything.",
                                                     // "Muahahahaha",
                                                     // "These mortal infedels my lord, they have invaded your sanctum and seek to steal your secrets.",
                                                     // "You are already dead.",
                                                     // "Where to go? What to do? So many choices that all end in pain, end in death."
    SAY_BERSERK                                 = 2, // "$N, I sentance you to death!"
    SAY_PHASE                                   = 3, // "The suffering has just begun!"
    SAY_DANCE                                   = 4, // "I always thought I was a good dancer."
    SAY_SALUTE                                  = 5, // "Move out Soldier!"
    SAY_EVADE                                   = 6  // "Help $N! I'm under attack!"
};

enum Spells
{
    // List of spells.
    // Not required to define them in this way, but will make it easier to maintain in case spellId change
    SPELL_BUFF                                  = 25661,
    SPELL_ONE                                   = 12555,
    SPELL_ONE_ALT                               = 24099,
    SPELL_TWO                                   = 10017,
    SPELL_THREE                                 = 26027,
    SPELL_FRENZY                                = 23537,
    SPELL_BERSERK                               = 32965,
};

enum eEnums
{
    // any other constants
    FACTION_WORGEN                              = 24
};

//List of gossip item texts. Items will appear in the gossip window.
#define GOSSIP_ITEM     "I'm looking for a fight"

class example_creature : public CreatureScript
{
    public:

        example_creature()
            : CreatureScript("example_creature")
        {
        }

        struct example_creatureAI : public ScriptedAI
        {
            // *** HANDLED FUNCTION ***
            //This is the constructor, called only once when the Creature is first created
            example_creatureAI(Creature* creature) : ScriptedAI(creature) {}

            // *** CUSTOM VARIABLES ****
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

            // *** HANDLED FUNCTION ***
            //This is called after spawn and whenever the core decides we need to evade
            void Reset()
            {
                m_uiPhase = 1;                                      // Start in phase 1
                m_uiPhaseTimer = 60000;                             // 60 seconds
                m_uiSpell1Timer = 5000;                             //  5 seconds
                m_uiSpell2Timer = urand(10000, 20000);               // between 10 and 20 seconds
                m_uiSpell3Timer = 19000;                            // 19 seconds
                m_uiBeserkTimer = 120000;                           //  2 minutes

                me->RestoreFaction();
            }

            // *** HANDLED FUNCTION ***
            // Enter Combat called once per combat
            void EnterCombat(Unit* who)
            {
                //Say some stuff
                Talk(SAY_AGGRO, who->GetGUID());
            }

            // *** HANDLED FUNCTION ***
            // Attack Start is called when victim change (including at start of combat)
            // By default, attack who and start movement toward the victim.
            //void AttackStart(Unit* who)
            //{
            //    ScriptedAI::AttackStart(who);
            //}

            // *** HANDLED FUNCTION ***
            // Called when going out of combat. Reset is called just after.
            void EnterEvadeMode()
            {
                Talk(SAY_EVADE);
            }

            // *** HANDLED FUNCTION ***
            //Our Receive emote function
            void ReceiveEmote(Player* /*player*/, uint32 uiTextEmote)
            {
                me->HandleEmoteCommand(uiTextEmote);

                switch (uiTextEmote)
                {
                    case TEXT_EMOTE_DANCE:
                        Talk(SAY_DANCE);
                        break;
                    case TEXT_EMOTE_SALUTE:
                        Talk(SAY_SALUTE);
                        break;
                }
             }

            // *** HANDLED FUNCTION ***
            //Update AI is called Every single map update (roughly once every 50ms if a player is within the grid)
            void UpdateAI(const uint32 uiDiff)
            {
                //Out of combat timers
                if (!me->getVictim())
                {
                    //Random Say timer
                    if (m_uiSayTimer <= uiDiff)
                    {
                        //Random switch between 5 outcomes
                        Talk(SAY_RANDOM);

                        m_uiSayTimer = 45000;                      //Say something agian in 45 seconds
                    }
                    else
                        m_uiSayTimer -= uiDiff;

                    //Rebuff timer
                    if (m_uiRebuffTimer <= uiDiff)
                    {
                        DoCast(me, SPELL_BUFF);
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
                        DoCast(me->getVictim(), SPELL_ONE_ALT);
                    else if (me->IsWithinDist(me->getVictim(), 25.0f))
                        DoCast(me->getVictim(), SPELL_ONE);

                    m_uiSpell1Timer = 5000;
                }
                else
                    m_uiSpell1Timer -= uiDiff;

                //Spell 2 timer
                if (m_uiSpell2Timer <= uiDiff)
                {
                    //Cast spell two on our current target.
                    DoCast(me->getVictim(), SPELL_TWO);
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
                        DoCast(me->getVictim(), SPELL_THREE);

                        m_uiSpell3Timer = 19000;
                    }
                    else
                        m_uiSpell3Timer -= uiDiff;

                    if (m_uiBeserkTimer <= uiDiff)
                    {
                        //Say our line then cast uber death spell
                        Talk(SAY_BERSERK, me->getVictim() ? me->getVictim()->GetGUID() : 0);
                        DoCast(me->getVictim(), SPELL_BERSERK);

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
                        Talk(SAY_PHASE);
                        DoCast(me, SPELL_FRENZY);
                    }
                    else
                        m_uiPhaseTimer -= uiDiff;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new example_creatureAI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
            player->SEND_GOSSIP_MENU(907, creature->GetGUID());

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
        {
            player->PlayerTalkClass->ClearMenus();
            if (action == GOSSIP_ACTION_INFO_DEF+1)
            {
                player->CLOSE_GOSSIP_MENU();
                //Set our faction to hostile towards all
                creature->setFaction(FACTION_WORGEN);
                creature->AI()->AttackStart(player);
            }

            return true;
        }
};

//This is the actual function called only once durring InitScripts()
//It must define all handled functions that are to be run in this script
void AddSC_example_creature()
{
    new example_creature();
}
