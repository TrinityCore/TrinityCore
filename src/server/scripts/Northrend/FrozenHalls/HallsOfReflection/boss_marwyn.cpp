/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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

#include "ScriptMgr.h"
#include "boss_horAI.h"
#include "halls_of_reflection.h"
#include "InstanceScript.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"

enum Texts
{
    SAY_AGGRO                                     = 0,
    SAY_SLAY                                      = 1,
    SAY_DEATH                                     = 2,
    SAY_CORRUPTED_FLESH                           = 3
};

enum Spells
{
    SPELL_OBLITERATE                              = 72360,
    SPELL_WELL_OF_CORRUPTION                      = 72362,
    SPELL_CORRUPTED_FLESH                         = 72363,
    SPELL_SHARED_SUFFERING                        = 72368,
    SPELL_SHARED_SUFFERING_DISPEL                 = 72373
};

enum Events
{
    EVENT_NONE,
    EVENT_OBLITERATE,
    EVENT_WELL_OF_CORRUPTION,
    EVENT_CORRUPTED_FLESH,
    EVENT_SHARED_SUFFERING
};

class boss_marwyn : public CreatureScript
{
    public:
        boss_marwyn() : CreatureScript("boss_marwyn") { }

        struct boss_marwynAI : public boss_horAI
        {
            boss_marwynAI(Creature* creature) : boss_horAI(creature, DATA_MARWYN) { }

            void Reset() override
            {
                boss_horAI::Reset();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);
                DoZoneInCombat();
                instance->SetBossState(DATA_MARWYN, IN_PROGRESS);

                events.ScheduleEvent(EVENT_OBLITERATE, 8s, 13s);
                events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 12s);
                events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 20s);
                events.ScheduleEvent(EVENT_SHARED_SUFFERING, 14s, 15s);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);
                events.Reset();
                instance->SetBossState(DATA_MARWYN, DONE);
            }

            void KilledUnit(Unit* who) override
            {
                if (who->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_SLAY);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!UpdateVictim())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                switch (events.ExecuteEvent())
                {
                    case EVENT_OBLITERATE:
                        DoCastVictim(SPELL_OBLITERATE);
                        events.ScheduleEvent(EVENT_OBLITERATE, 8s, 13s);
                        break;
                    case EVENT_WELL_OF_CORRUPTION:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            DoCast(target, SPELL_WELL_OF_CORRUPTION);
                        events.ScheduleEvent(EVENT_WELL_OF_CORRUPTION, 13s);
                        break;
                    case EVENT_CORRUPTED_FLESH:
                        Talk(SAY_CORRUPTED_FLESH);
                        DoCastAOE(SPELL_CORRUPTED_FLESH);
                        events.ScheduleEvent(EVENT_CORRUPTED_FLESH, 20s);
                        break;
                    case EVENT_SHARED_SUFFERING:
                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true))
                            DoCast(target, SPELL_SHARED_SUFFERING);
                        events.ScheduleEvent(EVENT_SHARED_SUFFERING, 14s, 15s);
                        break;
                    default:
                        break;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetHallsOfReflectionAI<boss_marwynAI>(creature);
        }
};

// 72368, 72369 - Shared Suffering
class spell_marwyn_shared_suffering : public SpellScriptLoader
{
    public:
        spell_marwyn_shared_suffering() : SpellScriptLoader("spell_marwyn_shared_suffering") { }

        class spell_marwyn_shared_suffering_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_marwyn_shared_suffering_AuraScript);

            void HandleEffectRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_ENEMY_SPELL)
                    return;

                if (Unit* caster = GetCaster())
                {
                    int32 remainingDamage = aurEff->GetAmount() * aurEff->GetRemainingTicks();
                    if (remainingDamage > 0)
                    {
                        CastSpellExtraArgs args(TRIGGERED_FULL_MASK);
                        args.AddSpellMod(SPELLVALUE_BASE_POINT1, remainingDamage);
                        caster->CastSpell(GetTarget(), SPELL_SHARED_SUFFERING_DISPEL, args);
                    }
                }
            }

            void Register() override
            {
                AfterEffectRemove += AuraEffectRemoveFn(spell_marwyn_shared_suffering_AuraScript::HandleEffectRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_marwyn_shared_suffering_AuraScript();
        }
};

void AddSC_boss_marwyn()
{
    new boss_marwyn();
    new spell_marwyn_shared_suffering();
}
