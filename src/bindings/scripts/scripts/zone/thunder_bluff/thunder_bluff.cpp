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
SDName: Thunder_Bluff
SD%Complete: 100
SDComment: Quest support: 925
SDCategory: Thunder Bluff
EndScriptData */

#include "precompiled.h"

/*#####
# npc_cairne_bloodhoof
######*/

#define SPELL_BERSERKER_CHARGE  16636
#define SPELL_CLEAVE            16044
#define SPELL_MORTAL_STRIKE     16856
#define SPELL_THUNDERCLAP       23931
#define SPELL_UPPERCUT          22916

#define GOSSIP_HCB "I know this is rather silly but a young ward who is a bit shy would like your hoofprint."
//TODO: verify abilities/timers
struct TRINITY_DLL_DECL npc_cairne_bloodhoofAI : public ScriptedAI
{
    npc_cairne_bloodhoofAI(Creature* c) : ScriptedAI(c) {}

    uint32 BerserkerCharge_Timer;
    uint32 Cleave_Timer;
    uint32 MortalStrike_Timer;
    uint32 Thunderclap_Timer;
    uint32 Uppercut_Timer;

    void Reset()
    {
        BerserkerCharge_Timer = 30000;
        Cleave_Timer = 5000;
        MortalStrike_Timer = 10000;
        Thunderclap_Timer = 15000;
        Uppercut_Timer = 10000;
    }

    void EnterCombat(Unit *who) {}

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        if (BerserkerCharge_Timer < diff)
        {
            Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0);
            if (target)
                DoCast(target,SPELL_BERSERKER_CHARGE);
            BerserkerCharge_Timer = 25000;
        }else BerserkerCharge_Timer -= diff;

        if (Uppercut_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_UPPERCUT);
            Uppercut_Timer = 20000;
        }else Uppercut_Timer -= diff;

        if (Thunderclap_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_THUNDERCLAP);
            Thunderclap_Timer = 15000;
        }else Thunderclap_Timer -= diff;

        if (MortalStrike_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_MORTAL_STRIKE);
            MortalStrike_Timer = 15000;
        }else MortalStrike_Timer -= diff;

        if (Cleave_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CLEAVE);
            Cleave_Timer = 7000;
        }else Cleave_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_npc_cairne_bloodhoof(Creature *_Creature)
{
    return new npc_cairne_bloodhoofAI (_Creature);
}

bool GossipHello_npc_cairne_bloodhoof(Player* pPlayer, Creature *_Creature)
{
    if (_Creature->isQuestGiver())
        pPlayer->PrepareQuestMenu(_Creature->GetGUID());

    if (pPlayer->GetQuestStatus(925) == QUEST_STATUS_INCOMPLETE)
        pPlayer->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, GOSSIP_HCB, GOSSIP_SENDER_MAIN, GOSSIP_SENDER_INFO);

    pPlayer->SEND_GOSSIP_MENU(7013, _Creature->GetGUID());

    return true;
}

bool GossipSelect_npc_cairne_bloodhoof(Player* pPlayer, Creature *_Creature, uint32 sender, uint32 action)
{
    if (action == GOSSIP_SENDER_INFO)
    {
        pPlayer->CastSpell(pPlayer, 23123, false);
        pPlayer->SEND_GOSSIP_MENU(7014, _Creature->GetGUID());
    }
    return true;
}

void AddSC_thunder_bluff()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="npc_cairne_bloodhoof";
    newscript->GetAI = &GetAI_npc_cairne_bloodhoof;
    newscript->pGossipHello = &GossipHello_npc_cairne_bloodhoof;
    newscript->pGossipSelect = &GossipSelect_npc_cairne_bloodhoof;
    newscript->RegisterSelf();
}

