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
SDName: Boss_Gloomrel
SD%Complete: 80
SDComment: Learning Smelt Dark Iron if tribute quest rewarded. Missing event and re-spawn GO Spectral Chalice
SDCategory: Blackrock Depths
EndScriptData */

#include "precompiled.h"

#define SPELL_HAMSTRING             9080
#define SPELL_CLEAVE                15579
#define SPELL_MORTALSTRIKE          15708

struct TRINITY_DLL_DECL boss_gloomrelAI : public ScriptedAI
{
    boss_gloomrelAI(Creature *c) : ScriptedAI(c) {Reset();}

    uint32 HamString_Timer;
    uint32 Cleave_Timer;
    uint32 MortalStrike_Timer;

    void Reset()
    {
        HamString_Timer = 19000;
        Cleave_Timer = 6000;
        MortalStrike_Timer = 10000;

        m_creature->setFaction(734);
    }

    void Aggro(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        //Return since we have no target
        if (!m_creature->SelectHostilTarget() || !m_creature->getVictim() )
            return;

        //HamString_Timer
        if (HamString_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_HAMSTRING);
            HamString_Timer = 14000;
        }else HamString_Timer -= diff;

        //Cleave_Timer
        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 8000;
        }else Cleave_Timer -= diff;

        //MortalStrike_Timer
        if (MortalStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MORTALSTRIKE);
            MortalStrike_Timer = 12000;
        }else MortalStrike_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_gloomrel(Creature *_Creature)
{
    return new boss_gloomrelAI (_Creature);
}

bool GossipHello_boss_gloomrel(Player *player, Creature *_Creature)
{
    if (player->GetQuestRewardStatus(4083) == 1 && player->GetSkillValue(SKILL_MINING) >= 230 && !player->HasSpell(14891) )
        player->ADD_GOSSIP_ITEM(0, "Teach me the art of smelting dark iron", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);

    if (player->GetQuestRewardStatus(4083) == 0 && player->GetSkillValue(SKILL_MINING) >= 230)
        player->ADD_GOSSIP_ITEM(0, "I want to pay tribute", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);

    player->ADD_GOSSIP_ITEM(0, "Challenge", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
    player->SEND_GOSSIP_MENU(2602, _Creature->GetGUID());

    return true;
}

bool GossipSelect_boss_gloomrel(Player *player, Creature *_Creature, uint32 sender, uint32 action )
{
    switch (action)
    {
        case GOSSIP_ACTION_INFO_DEF+1:
            player->ADD_GOSSIP_ITEM( 0, "Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 11);
            player->SEND_GOSSIP_MENU(2606, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+11:
            player->CLOSE_GOSSIP_MENU();
            _Creature->CastSpell(player, 14894, false);
            break;
        case GOSSIP_ACTION_INFO_DEF+2:
            player->ADD_GOSSIP_ITEM( 0, "[PH] Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 22);
            player->SEND_GOSSIP_MENU(2604, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+22:
            player->CLOSE_GOSSIP_MENU();
            //re-spawn object here
            break;
        case GOSSIP_ACTION_INFO_DEF+3:
            player->ADD_GOSSIP_ITEM( 0, "[PH] Continue...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33);
            player->SEND_GOSSIP_MENU(2605, _Creature->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF+33:
            player->CLOSE_GOSSIP_MENU();
            //start event here, below code just temporary
            _Creature->setFaction(754);
            break;
    }
    return true;
}

void AddSC_boss_gloomrel()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_gloomrel";
    newscript->GetAI = GetAI_boss_gloomrel;
    newscript->pGossipHello = &GossipHello_boss_gloomrel;
    newscript->pGossipSelect = &GossipSelect_boss_gloomrel;
    m_scripts[nrscripts++] = newscript;
}
