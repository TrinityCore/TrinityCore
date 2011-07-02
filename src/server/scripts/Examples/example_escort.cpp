/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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
SDName: Example_Escort
SD%Complete: 100
SDComment: Script used for testing escortAI
SDCategory: Script Examples
EndScriptData */

#include "ScriptPCH.h"
#include "ScriptedEscortAI.h"

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

class example_escort : public CreatureScript
{
    public:

        example_escort()
            : CreatureScript("example_escort")
        {
        }

        struct example_escortAI : public npc_escortAI
        {
            // CreatureAI functions
            example_escortAI(Creature* creature) : npc_escortAI(creature) { }

            uint32 m_uiDeathCoilTimer;
            uint32 m_uiChatTimer;

            void JustSummoned(Creature* pSummoned)
            {
                pSummoned->AI()->AttackStart(me);
            }

            // Pure Virtual Functions (Have to be implemented)
            void WaypointReached(uint32 uiWP)
            {
                switch (uiWP)
                {
                    case 1:
                        DoScriptText(SAY_WP_1, me);
                        break;
                    case 3:
                        DoScriptText(SAY_WP_2, me);
                        me->SummonCreature(NPC_FELBOAR, me->GetPositionX()+5.0f, me->GetPositionY()+7.0f, me->GetPositionZ(), 0.0f, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                        break;
                    case 4:
                        if (Player* player = GetPlayerForEscort())
                        {
                            //pTmpPlayer is the target of the text
                            DoScriptText(SAY_WP_3, me, player);
                            //pTmpPlayer is the source of the text
                            DoScriptText(SAY_WP_4, player);
                        }
                        break;
                }
            }

            void EnterCombat(Unit* /*who*/)
            {
                if (HasEscortState(STATE_ESCORT_ESCORTING))
                {
                    if (Player* player = GetPlayerForEscort())
                        DoScriptText(SAY_AGGRO1, me, player);
                }
                else
                    DoScriptText(SAY_AGGRO2, me);
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
                    if (Player* player = GetPlayerForEscort())
                    {
                        // not a likely case, code here for the sake of example
                        if (pKiller == me)
                        {
                            DoScriptText(SAY_DEATH_1, me, player);
                        }
                        else
                            DoScriptText(SAY_DEATH_2, me, player);
                    }
                }
                else
                    DoScriptText(SAY_DEATH_3, me);
            }

            void UpdateAI(const uint32 uiDiff)
            {
                //Must update npc_escortAI
                npc_escortAI::UpdateAI(uiDiff);

                //Combat check
                if (me->getVictim())
                {
                    if (m_uiDeathCoilTimer <= uiDiff)
                    {
                        DoScriptText(SAY_SPELL, me);
                        DoCast(me->getVictim(), SPELL_DEATH_COIL, false);
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
                        if (m_uiChatTimer <= uiDiff)
                        {
                            if (me->HasAura(SPELL_ELIXIR_OF_FORTITUDE, 0))
                            {
                                DoScriptText(SAY_RAND_1, me);
                                DoCast(me, SPELL_BLUE_FIREWORK, false);
                            }
                            else
                            {
                                DoScriptText(SAY_RAND_2, me);
                                DoCast(me, SPELL_ELIXIR_OF_FORTITUDE, false);
                            }

                            m_uiChatTimer = 12000;
                        }
                        else
                            m_uiChatTimer -= uiDiff;
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return new example_escortAI(creature);
        }

        bool OnGossipHello(Player* player, Creature* creature)
        {
            player->TalkedToCreature(creature->GetEntry(), creature->GetGUID());
            player->PrepareGossipMenu(creature, 0);

            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_1, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_2, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
            player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_ITEM_3, GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);

            player->SendPreparedGossip(creature);

            return true;
        }

        bool OnGossipSelect(Player* player, Creature* creature, uint32 /*uiSender*/, uint32 uiAction)
        {
            player->PlayerTalkClass->ClearMenus();
            npc_escortAI* pEscortAI = CAST_AI(example_escort::example_escortAI, creature->AI());

            switch(uiAction)
            {
                case GOSSIP_ACTION_INFO_DEF+1:
                    player->CLOSE_GOSSIP_MENU();

                    if (pEscortAI)
                        pEscortAI->Start(true, true, player->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+2:
                    player->CLOSE_GOSSIP_MENU();

                    if (pEscortAI)
                        pEscortAI->Start(false, false, player->GetGUID());
                    break;
                case GOSSIP_ACTION_INFO_DEF+3:
                    player->CLOSE_GOSSIP_MENU();

                    if (pEscortAI)
                        pEscortAI->Start(false, true, player->GetGUID());
                    break;
                default:
                    return false;                                   // nothing defined      -> trinity core handling
            }

            return true;                                            // no default handling  -> prevent trinity core handling
        }
};

void AddSC_example_escort()
{
    new example_escort();
}
