/*
 * Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
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

/* Script Data Start
SDName: Boss krystallus
SDAuthor: LordVanMartin
SD%Complete:
SDComment:
SDCategory:
Script Data End */

#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "halls_of_stone.h"

enum Spells
{
    SPELL_BOULDER_TOSS                             = 50843,
    H_SPELL_BOULDER_TOSS                           = 59742,
    SPELL_GROUND_SPIKE                             = 59750,
    SPELL_GROUND_SLAM                              = 50827,
    SPELL_SHATTER                                  = 50810,
    H_SPELL_SHATTER                                = 61546,
    SPELL_SHATTER_EFFECT                           = 50811,
    H_SPELL_SHATTER_EFFECT                         = 61547,
    SPELL_STONED                                   = 50812,
    SPELL_STOMP                                    = 48131,
    H_SPELL_STOMP                                  = 59744
};

enum Yells
{
    SAY_AGGRO                                   = 0,
    SAY_KILL                                    = 1,
    SAY_DEATH                                   = 2,
    SAY_SHATTER                                 = 3
};

class boss_krystallus : public CreatureScript
{
public:
    boss_krystallus() : CreatureScript("boss_krystallus") { }

    struct boss_krystallusAI : public ScriptedAI
    {
        boss_krystallusAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
        }

        uint32 uiBoulderTossTimer;
        uint32 uiGroundSpikeTimer;
        uint32 uiGroundSlamTimer;
        uint32 uiShatterTimer;
        uint32 uiStompTimer;

        bool bIsSlam;

        InstanceScript* instance;

        void Reset() override
        {
            bIsSlam = false;

            uiBoulderTossTimer = urand(3000, 9000);
            uiGroundSpikeTimer = urand(9000, 14000);
            uiGroundSlamTimer = urand(15000, 18000);
            uiStompTimer = urand(20000, 29000);
            uiShatterTimer = 0;

            instance->SetBossState(DATA_KRYSTALLUS, NOT_STARTED);
        }
        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);

            instance->SetBossState(DATA_KRYSTALLUS, IN_PROGRESS);
        }

        void UpdateAI(uint32 diff) override
        {
            //Return since we have no target
            if (!UpdateVictim())
                return;

            if (uiBoulderTossTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_BOULDER_TOSS);
                uiBoulderTossTimer = urand(9000, 15000);
            } else uiBoulderTossTimer -= diff;

            if (uiGroundSpikeTimer <= diff)
            {
                if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100, true))
                    DoCast(target, SPELL_GROUND_SPIKE);
                uiGroundSpikeTimer = urand(12000, 17000);
            } else uiGroundSpikeTimer -= diff;

            if (uiStompTimer <= diff)
            {
                DoCast(me, SPELL_STOMP);
                uiStompTimer = urand(20000, 29000);
            } else uiStompTimer -= diff;

            if (uiGroundSlamTimer <= diff)
            {
                DoCast(me, SPELL_GROUND_SLAM);
                bIsSlam = true;
                uiShatterTimer = 10000;
                uiGroundSlamTimer = urand(15000, 18000);
            } else uiGroundSlamTimer -= diff;

            if (bIsSlam)
            {
                if (uiShatterTimer <= diff)
                {
                    DoCast(me, DUNGEON_MODE(SPELL_SHATTER, H_SPELL_SHATTER));
                } else uiShatterTimer -= diff;
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);

            instance->SetBossState(DATA_KRYSTALLUS, DONE);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetTypeId() != TYPEID_PLAYER)
                return;

            Talk(SAY_KILL);
        }

        void SpellHitTarget(Unit* /*target*/, const SpellInfo* pSpell) override
        {
            //this part should be in the core
            if (pSpell->Id == SPELL_SHATTER || pSpell->Id == H_SPELL_SHATTER)
            {
                /// @todo we need eventmap to kill this stuff
                //clear this, if we are still performing
                if (bIsSlam)
                {
                    bIsSlam = false;

                    //and correct movement, if not already
                    if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() != CHASE_MOTION_TYPE)
                    {
                        if (me->GetVictim())
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                    }
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetHallsOfStoneAI<boss_krystallusAI>(creature);
    }
};

class spell_krystallus_shatter : public SpellScriptLoader
{
    public:
        spell_krystallus_shatter() : SpellScriptLoader("spell_krystallus_shatter") { }

        class spell_krystallus_shatter_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_krystallus_shatter_SpellScript)

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                if (Unit* target = GetHitUnit())
                {
                    target->RemoveAurasDueToSpell(SPELL_STONED);
                    target->CastSpell((Unit*)NULL, SPELL_SHATTER_EFFECT, true);
                }
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_krystallus_shatter_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_krystallus_shatter_SpellScript();
        }
};

class spell_krystallus_shatter_effect : public SpellScriptLoader
{
    public:
        spell_krystallus_shatter_effect() : SpellScriptLoader("spell_krystallus_shatter_effect") { }

        class spell_krystallus_shatter_effect_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_krystallus_shatter_effect_SpellScript)

            void CalculateDamage()
            {
                if (!GetHitUnit())
                    return;

                float radius = GetSpellInfo()->Effects[EFFECT_0].CalcRadius(GetCaster());
                if (!radius)
                    return;

                float distance = GetCaster()->GetDistance2d(GetHitUnit());
                if (distance > 1.0f)
                    SetHitDamage(int32(GetHitDamage() * ((radius - distance) / radius)));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_krystallus_shatter_effect_SpellScript::CalculateDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_krystallus_shatter_effect_SpellScript();
        }
};

void AddSC_boss_krystallus()
{
    new boss_krystallus();
    new spell_krystallus_shatter();
    new spell_krystallus_shatter_effect();
}
