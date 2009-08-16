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
SDName: Boss_the_black_stalker
SD%Complete: 95
SDComment: Timers may be incorrect
SDCategory: Coilfang Resevoir, Underbog
EndScriptData */

#include "precompiled.h"

#define SPELL_LEVITATE             31704
#define SPELL_SUSPENSION           31719
#define SPELL_LEVITATION_PULSE     31701
#define SPELL_MAGNETIC_PULL        31705
#define SPELL_CHAIN_LIGHTNING      31717
#define SPELL_STATIC_CHARGE        31715
#define SPELL_SUMMON_SPORE_STRIDER 38755

#define ENTRY_SPORE_STRIDER        22299

struct TRINITY_DLL_DECL boss_the_black_stalkerAI : public ScriptedAI
{
    boss_the_black_stalkerAI(Creature *c) : ScriptedAI(c)
    {
        HeroicMode = m_creature->GetMap()->IsHeroic();
    }

    bool HeroicMode;
    uint32 SporeStriders_Timer;
    uint32 Levitate_Timer;
    uint32 ChainLightning_Timer;
    uint32 StaticCharge_Timer;
    uint64 LevitatedTarget;
    uint32 LevitatedTarget_Timer;
    bool InAir;
    uint32 check_Timer;
    std::list<uint64> Striders;

    void Reset()
    {
        Levitate_Timer = 12000;
        ChainLightning_Timer = 6000;
        StaticCharge_Timer = 10000;
        SporeStriders_Timer = 10000+rand()%5000;
        check_Timer = 5000;
        LevitatedTarget = 0;
        LevitatedTarget_Timer = 0;
        Striders.clear();
    }

    void EnterCombat(Unit *who) {}

    void JustSummoned(Creature *summon)
    {
        if (summon && summon->GetEntry() == ENTRY_SPORE_STRIDER)
        {
            Striders.push_back(summon->GetGUID());
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM,1))
                summon->AI()->AttackStart(target);
            else
                if (m_creature->getVictim())
                    summon->AI()->AttackStart(m_creature->getVictim());
        }
    }

    void JustDied(Unit *who)
    {
        for(std::list<uint64>::iterator i = Striders.begin(); i != Striders.end(); ++i)
            if (Creature *strider = Unit::GetCreature(*m_creature, *i))
            {
                strider->SetLootRecipient(NULL);
                strider->DealDamage(strider,strider->GetMaxHealth(),NULL, DIRECT_DAMAGE, SPELL_SCHOOL_MASK_NORMAL, NULL, false);
                strider->RemoveCorpse();
            }
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        // Evade if too far
        if (check_Timer < diff)
        {
            float x,y,z,o;
            m_creature->GetHomePosition(x,y,z,o);
            if (!m_creature->IsWithinDist3d(x,y,z, 60))
            {
                EnterEvadeMode();
                return;
            }
            check_Timer = 1000;
        }else check_Timer -= diff;

        // Spore Striders
        if (HeroicMode && SporeStriders_Timer < diff)
        {
            DoCast(m_creature,SPELL_SUMMON_SPORE_STRIDER);
            SporeStriders_Timer = 10000+rand()%5000;
        }else SporeStriders_Timer -= diff;

        // Levitate
        if (LevitatedTarget)
        {
            if (LevitatedTarget_Timer < diff)
            {
                if (Unit* target = Unit::GetUnit(*m_creature, LevitatedTarget))
                {
                    if (!target->HasAura(SPELL_LEVITATE))
                    {
                        LevitatedTarget = 0;
                        return;
                    }
                    if (InAir)
                    {
                        target->AddAura(SPELL_SUSPENSION, target);
                        LevitatedTarget = 0;
                    }
                    else
                    {
                        target->CastSpell(target, SPELL_MAGNETIC_PULL, true);
                        InAir = true;
                        LevitatedTarget_Timer = 1500;
                    }
                }
                else
                    LevitatedTarget = 0;
            }else LevitatedTarget_Timer -= diff;
        }
        if (Levitate_Timer < diff)
        {
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM,1))
            {
                DoCast(target, SPELL_LEVITATE);
                LevitatedTarget = target->GetGUID();
                LevitatedTarget_Timer = 2000;
                InAir = false;
            }
            Levitate_Timer = 12000+rand()%3000;
        }else Levitate_Timer -= diff;

        // Chain Lightning
        if (ChainLightning_Timer < diff)
        {
            if (Unit *target = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(target, SPELL_CHAIN_LIGHTNING);
            ChainLightning_Timer = 7000;
        }else ChainLightning_Timer -= diff;

        // Static Charge
        if (StaticCharge_Timer < diff)
        {
            if (Unit *target = SelectTarget(SELECT_TARGET_RANDOM,0,30,true))
                DoCast(target, SPELL_STATIC_CHARGE);
            StaticCharge_Timer = 10000;
        }else StaticCharge_Timer -= diff;

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_the_black_stalker(Creature* pCreature)
{
    return new boss_the_black_stalkerAI (pCreature);
}

void AddSC_boss_the_black_stalker()
{
    Script *newscript;

    newscript = new Script;
    newscript->Name="boss_the_black_stalker";
    newscript->GetAI = &GetAI_boss_the_black_stalker;
    newscript->RegisterSelf();
}

