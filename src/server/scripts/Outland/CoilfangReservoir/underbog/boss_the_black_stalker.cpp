/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
SDName: Boss_the_black_stalker
SD%Complete: 95
SDComment: Timers may be incorrect
SDCategory: Coilfang Resevoir, Underbog
EndScriptData */

#include "ScriptPCH.h"

#define SPELL_LEVITATE             31704
#define SPELL_SUSPENSION           31719
#define SPELL_LEVITATION_PULSE     31701
#define SPELL_MAGNETIC_PULL        31705
#define SPELL_CHAIN_LIGHTNING      31717
#define SPELL_STATIC_CHARGE        31715
#define SPELL_SUMMON_SPORE_STRIDER 38755

#define ENTRY_SPORE_STRIDER        22299

struct boss_the_black_stalkerAI : public ScriptedAI
{
    boss_the_black_stalkerAI(Creature *c) : ScriptedAI(c)
    {
    }

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

    void EnterCombat(Unit * /*who*/) {}

    void JustSummoned(Creature *summon)
    {
        if (summon && summon->GetEntry() == ENTRY_SPORE_STRIDER)
        {
            Striders.push_back(summon->GetGUID());
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
                summon->AI()->AttackStart(pTarget);
            else
                if (me->getVictim())
                    summon->AI()->AttackStart(me->getVictim());
        }
    }

    void JustDied(Unit * /*who*/)
    {
        for (std::list<uint64>::const_iterator i = Striders.begin(); i != Striders.end(); ++i)
            if (Creature *strider = Unit::GetCreature(*me, *i))
                strider->DisappearAndDie();
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        // Evade if too far
        if (check_Timer <= diff)
        {
            float x,y,z,o;
            me->GetHomePosition(x,y,z,o);
            if (!me->IsWithinDist3d(x,y,z, 60))
            {
                EnterEvadeMode();
                return;
            }
            check_Timer = 1000;
        } else check_Timer -= diff;

        // Spore Striders
        if (IsHeroic() && SporeStriders_Timer <= diff)
        {
            DoCast(me, SPELL_SUMMON_SPORE_STRIDER);
            SporeStriders_Timer = 10000+rand()%5000;
        } else SporeStriders_Timer -= diff;

        // Levitate
        if (LevitatedTarget)
        {
            if (LevitatedTarget_Timer <= diff)
            {
                if (Unit *pTarget = Unit::GetUnit(*me, LevitatedTarget))
                {
                    if (!pTarget->HasAura(SPELL_LEVITATE))
                    {
                        LevitatedTarget = 0;
                        return;
                    }
                    if (InAir)
                    {
                        pTarget->AddAura(SPELL_SUSPENSION, pTarget);
                        LevitatedTarget = 0;
                    }
                    else
                    {
                        pTarget->CastSpell(pTarget, SPELL_MAGNETIC_PULL, true);
                        InAir = true;
                        LevitatedTarget_Timer = 1500;
                    }
                }
                else
                    LevitatedTarget = 0;
            } else LevitatedTarget_Timer -= diff;
        }
        if (Levitate_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,1))
            {
                DoCast(pTarget, SPELL_LEVITATE);
                LevitatedTarget = pTarget->GetGUID();
                LevitatedTarget_Timer = 2000;
                InAir = false;
            }
            Levitate_Timer = 12000+rand()%3000;
        } else Levitate_Timer -= diff;

        // Chain Lightning
        if (ChainLightning_Timer <= diff)
        {
            if (Unit *pTarget = SelectUnit(SELECT_TARGET_RANDOM,0))
                DoCast(pTarget, SPELL_CHAIN_LIGHTNING);
            ChainLightning_Timer = 7000;
        } else ChainLightning_Timer -= diff;

        // Static Charge
        if (StaticCharge_Timer <= diff)
        {
            if (Unit *pTarget = SelectTarget(SELECT_TARGET_RANDOM,0,30,true))
                DoCast(pTarget, SPELL_STATIC_CHARGE);
            StaticCharge_Timer = 10000;
        } else StaticCharge_Timer -= diff;

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
    newscript->Name = "boss_the_black_stalker";
    newscript->GetAI = &GetAI_boss_the_black_stalker;
    newscript->RegisterSelf();
}

