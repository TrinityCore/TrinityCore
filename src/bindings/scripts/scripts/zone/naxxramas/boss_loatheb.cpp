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
SDName: Boss_Loatheb
SD%Complete: 100
SDComment:
SDCategory: Naxxramas
EndScriptData */

#include "precompiled.h"

#define SPELL_CORRUPTED_MIND        29198
#define SPELL_POISON_AURA           29865
#define SPELL_INEVITABLE_DOOM       29204
#define SPELL_REMOVE_CURSE          30281

#define ADD_1X 2957.040
#define ADD_1Y -3997.590
#define ADD_1Z 274.280

#define ADD_2X 2909.130
#define ADD_2Y -4042.970
#define ADD_2Z 274.280

#define ADD_3X 2861.102
#define ADD_3Y -3997.901
#define ADD_3Z 274.280

struct TRINITY_DLL_DECL boss_loathebAI : public ScriptedAI
{
    boss_loathebAI(Creature *c) : ScriptedAI(c) {}

    uint32 CorruptedMind_Timer;
    uint32 PoisonAura_Timer;
    uint32 InevitableDoom_Timer;
    uint32 InevitableDoom5mins_Timer;
    uint32 RemoveCurse_Timer;
    uint32 Summon_Timer;

    void Reset()
    {
        CorruptedMind_Timer = 4000;
        PoisonAura_Timer = 2500;
        InevitableDoom_Timer = 120000;
        InevitableDoom5mins_Timer = 300000;
        RemoveCurse_Timer = 30000;
        Summon_Timer = 8000;
    }

    void EnterCombat(Unit *who)
    {
    }

    void JustDied(Unit* Killer)
    {
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        //CorruptedMind_Timer
        if (CorruptedMind_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_CORRUPTED_MIND);
            CorruptedMind_Timer = 62000;
        }else CorruptedMind_Timer -= diff;

        //PoisonAura_Timer
        if (PoisonAura_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_POISON_AURA);
            PoisonAura_Timer = 60000;
        }else PoisonAura_Timer -= diff;

        //InevitableDoom_Timer
        if (InevitableDoom_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_INEVITABLE_DOOM);
            InevitableDoom_Timer = 120000;
        }else InevitableDoom_Timer -= diff;

        //InevitableDoom5mins_Timer
        if (InevitableDoom5mins_Timer < diff)
        {
            DoCast(m_creature->getVictim(),SPELL_INEVITABLE_DOOM);
            InevitableDoom5mins_Timer = 15000;
        }else InevitableDoom5mins_Timer -= diff;

        //RemoveCurse_Timer
        if (RemoveCurse_Timer < diff)
        {
            DoCast(m_creature,SPELL_REMOVE_CURSE);
            RemoveCurse_Timer = 30000;
        }else RemoveCurse_Timer -= diff;

        //Summon_Timer
        if (Summon_Timer < diff)
        {
            Unit* target = NULL;
            Unit* SummonedSpores = NULL;

            SummonedSpores = m_creature->SummonCreature(16286,ADD_1X,ADD_1Y,ADD_1Z,0,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,80000);
            SummonedSpores = m_creature->SummonCreature(16286,ADD_2X,ADD_2Y,ADD_2Z,0,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,80000);
            SummonedSpores = m_creature->SummonCreature(16286,ADD_3X,ADD_3Y,ADD_3Z,0,TEMPSUMMON_TIMED_OR_DEAD_DESPAWN,80000);
            if (SummonedSpores)
            {
                target = SelectUnit(SELECT_TARGET_RANDOM,0);
                if (target)
                    SummonedSpores->AddThreat(target,1.0f);
            }

            Summon_Timer = 28000;
        } else Summon_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};
CreatureAI* GetAI_boss_loatheb(Creature *_Creature)
{
    return new boss_loathebAI (_Creature);
}

void AddSC_boss_loatheb()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name="boss_loatheb";
    newscript->GetAI = &GetAI_boss_loatheb;
    newscript->RegisterSelf();
}

