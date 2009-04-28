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
SDName: Boss_Baron_Geddon
SD%Complete: 100
SDComment:
SDCategory: Molten Core
EndScriptData */

#include "precompiled.h"

#define EMOTE_SERVICE               -1409000

#define SPELL_INFERNO               19695
#define SPELL_IGNITEMANA            19659
#define SPELL_LIVINGBOMB            20475
#define SPELL_ARMAGEDDOM            20479

struct TRINITY_DLL_DECL boss_baron_geddonAI : public ScriptedAI
{
    boss_baron_geddonAI(Creature *c) : ScriptedAI(c) {}

    uint32 Inferno_Timer;
    uint32 IgniteMana_Timer;
    uint32 LivingBomb_Timer;

    void Reset()
    {
        Inferno_Timer = 45000;                              //These times are probably wrong
        IgniteMana_Timer = 30000;
        LivingBomb_Timer = 35000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //If we are <2% hp cast Armageddom
        if (m_creature->GetHealth()*100 / m_creature->GetMaxHealth() <= 2)
        {
            m_creature->InterruptNonMeleeSpells(true);
            DoCast(m_creature,SPELL_ARMAGEDDOM);
            DoScriptText(EMOTE_SERVICE, m_creature);
            return;
        }

        //Inferno_Timer
        if (Inferno_Timer < diff)
        {
            DoCast(m_creature,SPELL_INFERNO);
            Inferno_Timer = 45000;
        }else Inferno_Timer -= diff;

        //IgniteMana_Timer
        if (IgniteMana_Timer < diff)
        {
            if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target,SPELL_IGNITEMANA);

            IgniteMana_Timer = 30000;
        }else IgniteMana_Timer -= diff;

        //LivingBomb_Timer
        if (LivingBomb_Timer < diff)
        {
           if (Unit* target = SelectUnit(SELECT_TARGET_RANDOM,0))
               DoCast(target,SPELL_LIVINGBOMB);

            LivingBomb_Timer = 35000;
        }else LivingBomb_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_baron_geddon(Creature *_Creature)
{
    return new boss_baron_geddonAI (_Creature);
}

void AddSC_boss_baron_geddon()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_baron_geddon";
    newscript->GetAI = &GetAI_boss_baron_geddon;
    newscript->RegisterSelf();
}

