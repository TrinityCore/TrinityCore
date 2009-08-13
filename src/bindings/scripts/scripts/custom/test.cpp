/* Copyright (C) 2006 - 2008 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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
SDName: Test
SD%Complete: 100
SDComment: Script used for testing escortAI
SDCategory: Script Examples
EndScriptData */

#include "precompiled.h"
#include "../npc/npc_escortAI.h"

struct TRINITY_DLL_DECL npc_testAI : public npc_escortAI
{
    public:

        // CreatureAI functions
        npc_testAI(Creature *c) : npc_escortAI(c) {}

        uint32 DeathCoilTimer;
        uint32 ChatTimer;

        // Pure Virtual Functions
        void WaypointReached(uint32 i)
        {
            switch (i)
            {
                case 1:
                    m_creature->Say("Hmm a nice day for a walk alright", LANG_UNIVERSAL, 0);
                    break;

                case 3:
                {
                    m_creature->Say("Wild Felboar attack!", LANG_UNIVERSAL, 0);
                    Creature* temp = m_creature->SummonCreature(21878, m_creature->GetPositionX()+5, m_creature->GetPositionY()+7, m_creature->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT, 3000);
                    if (temp)
                        temp->AI()->AttackStart(m_creature);
                }
                break;

                case 4:
                {
                    m_creature->Say("Time for me to go! See ya around $N!", LANG_UNIVERSAL, PlayerGUID);
                    m_creature->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);

                    Unit* temp = Unit::GetUnit(*m_creature, PlayerGUID);
                    if (temp)
                    {
                        temp->MonsterSay("Bye Bye!", LANG_UNIVERSAL, 0);
                        temp->HandleEmoteCommand(EMOTE_ONESHOT_WAVE);
                    }
                }
                break;
            }
        }

        void Aggro(Unit*)
        {
            if (IsBeingEscorted)
                m_creature->Say("Help $N! I'm under attack!", LANG_UNIVERSAL, PlayerGUID);
            else m_creature->Say("Die scum!", LANG_UNIVERSAL, 0);
        }

        void Reset()
        {
            DeathCoilTimer = 4000;
            ChatTimer = 4000;
        }

        void JustDied(Unit* killer)
        {
            if (IsBeingEscorted)
            {
                //killer = m_creature when player got to far from creature
                if (killer == m_creature)
                {
                    Unit *pTemp = Unit::GetUnit(*m_creature,PlayerGUID);
                    if (pTemp)
                        DoWhisper("How dare you leave me like that! I hate you! =*(", pTemp);
                }
                else m_creature->Say("...no...how could you let me die $N", LANG_UNIVERSAL, PlayerGUID);
            }
            else m_creature->Say("ugh...", LANG_UNIVERSAL, 0);
        }

        void UpdateAI(const uint32 diff)
        {
            //Must update npc_escortAI
            npc_escortAI::UpdateAI(diff);

            //Combat check
            if (m_creature->isInCombat() && m_creature->getVictim())
            {
                if (DeathCoilTimer < diff)
                {
                    m_creature->Say("Taste death!", LANG_UNIVERSAL, 0);
                    m_creature->CastSpell(m_creature->getVictim(), 33130, false);

                    DeathCoilTimer = 4000;
                }else DeathCoilTimer -= diff;
            }else
            {
                //Out of combat but being escorted
                if (IsBeingEscorted)
                    if (ChatTimer < diff)
                {
                    if (m_creature->HasAura(3593, 0))
                    {
                        m_creature->Say("Fireworks!", LANG_UNIVERSAL, 0);
                        m_creature->CastSpell(m_creature, 11540, false);
                    }else
                    {
                        m_creature->Say("Hmm, I think I could use a buff", LANG_UNIVERSAL, 0);
                        m_creature->CastSpell(m_creature, 3593, false);
                    }

                    ChatTimer = 12000;
                }else ChatTimer -= diff;
            }
        }
};

CreatureAI* GetAI_test(Creature *_Creature)
{
    npc_testAI* testAI = new npc_testAI(_Creature);

    testAI->AddWaypoint(0, 1231, -4419, 23);
    testAI->AddWaypoint(1, 1198, -4440, 23, 0);
    testAI->AddWaypoint(2, 1208, -4392, 23);
    testAI->AddWaypoint(3, 1231, -4419, 23, 5000);
    testAI->AddWaypoint(4, 1208, -4392, 23, 5000);

    return (CreatureAI*)testAI;
}

bool GossipHello_npc_test(Player* pPlayer, Creature *_Creature)
{
    pPlayer->TalkedToCreature(_Creature->GetEntry(),_Creature->GetGUID());
    _Creature->prepareGossipMenu(pPlayer,0);

    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Click to Test Escort(Attack, Defend, Run)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+1);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Click to Test Escort(NoAttack, NoDefend, Walk)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+2);
    pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "Click to Test Escort(NoAttack, Defend, Walk)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF+3);

    _Creature->sendPreparedGossip(pPlayer);
    return true;
}

bool GossipSelect_npc_test(Player* pPlayer, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_ACTION_INFO_DEF+1)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(true, true, pPlayer->GetGUID());

        return true;                                        // prevent Trinity core handling
    }

    if (action == GOSSIP_ACTION_INFO_DEF+2)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(false, false, pPlayer->GetGUID());

        return true;                                        // prevent Trinity core handling
    }

    if (action == GOSSIP_ACTION_INFO_DEF+3)
    {
        pPlayer->CLOSE_GOSSIP_MENU();
        ((npc_escortAI*)(_Creature->AI()))->Start(false, false, pPlayer->GetGUID());

        return true;                                        // prevent Trinity core handling
    }
    return false;
}

void AddSC_test()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="test";
    newscript->GetAI = &GetAI_test;
    newscript->pGossipHello          = &GossipHello_npc_test;
    newscript->pGossipSelect         = &GossipSelect_npc_test;
    newscript->RegisterSelf();
}

