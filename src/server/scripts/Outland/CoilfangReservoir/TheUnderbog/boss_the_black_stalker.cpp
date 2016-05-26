/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "ScriptedCreature.h"

enum Spells
{
    SPELL_LEVITATE              = 31704,
    SPELL_SUSPENSION            = 31719,
    SPELL_LEVITATION_PULSE      = 31701,
    SPELL_MAGNETIC_PULL         = 31705,
    SPELL_CHAIN_LIGHTNING       = 31717,
    SPELL_STATIC_CHARGE         = 31715,
    SPELL_SUMMON_SPORE_STRIDER  = 38755
};

enum CreatureIdS
{
    ENTRY_SPORE_STRIDER         = 22299
};

class boss_the_black_stalker : public CreatureScript
{
public:
    boss_the_black_stalker() : CreatureScript("boss_the_black_stalker") { }

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_the_black_stalkerAI(creature);
    }

    struct boss_the_black_stalkerAI : public ScriptedAI
    {
        boss_the_black_stalkerAI(Creature* creature) : ScriptedAI(creature), Striders(creature)
        {
            Initialize();
            InAir = false;
        }

        void Initialize()
        {
            Levitate_Timer = 12000;
            ChainLightning_Timer = 6000;
            StaticCharge_Timer = 10000;
            SporeStriders_Timer = 10000 + rand32() % 5000;
            check_Timer = 5000;
            LevitatedTarget.Clear();
            LevitatedTarget_Timer = 0;
        }

        uint32 SporeStriders_Timer;
        uint32 Levitate_Timer;
        uint32 ChainLightning_Timer;
        uint32 StaticCharge_Timer;
        ObjectGuid LevitatedTarget;
        uint32 LevitatedTarget_Timer;
        bool InAir;
        uint32 check_Timer;
        SummonList Striders;

        void Reset() override
        {
            Initialize();
            Striders.DespawnAll();
        }

        void EnterCombat(Unit* /*who*/) override { }

        void JustSummoned(Creature* summon) override
        {
            if (summon && summon->GetEntry() == ENTRY_SPORE_STRIDER)
            {
                Striders.Summon(summon);
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                    summon->AI()->AttackStart(target);
                else
                    if (me->GetVictim())
                        summon->AI()->AttackStart(me->GetVictim());
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            Striders.DespawnAll();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            // Evade if too far
            if (check_Timer <= diff)
            {
                float x, y, z, o;
                me->GetHomePosition(x, y, z, o);
                if (!me->IsWithinDist3d(x, y, z, 60))
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
                SporeStriders_Timer = 10000 + rand32() % 5000;
            } else SporeStriders_Timer -= diff;

            // Levitate
            if (LevitatedTarget)
            {
                if (LevitatedTarget_Timer <= diff)
                {
                    if (Unit* target = ObjectAccessor::GetUnit(*me, LevitatedTarget))
                    {
                        if (!target->HasAura(SPELL_LEVITATE))
                        {
                            LevitatedTarget.Clear();
                            return;
                        }
                        if (InAir)
                        {
                            target->AddAura(SPELL_SUSPENSION, target);
                            LevitatedTarget.Clear();
                        }
                        else
                        {
                            target->CastSpell(target, SPELL_MAGNETIC_PULL, true);
                            InAir = true;
                            LevitatedTarget_Timer = 1500;
                        }
                    }
                    else
                        LevitatedTarget.Clear();
                } else LevitatedTarget_Timer -= diff;
            }
            if (Levitate_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1))
                {
                    DoCast(target, SPELL_LEVITATE);
                    LevitatedTarget = target->GetGUID();
                    LevitatedTarget_Timer = 2000;
                    InAir = false;
                }
                Levitate_Timer = 12000 + rand32() % 3000;
            } else Levitate_Timer -= diff;

            // Chain Lightning
            if (ChainLightning_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                    DoCast(target, SPELL_CHAIN_LIGHTNING);
                ChainLightning_Timer = 7000;
            } else ChainLightning_Timer -= diff;

            // Static Charge
            if (StaticCharge_Timer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30, true))
                    DoCast(target, SPELL_STATIC_CHARGE);
                StaticCharge_Timer = 10000;
            } else StaticCharge_Timer -= diff;

            DoMeleeAttackIfReady();
        }
    };

};

void AddSC_boss_the_black_stalker()
{
    new boss_the_black_stalker();
}
