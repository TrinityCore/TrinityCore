/*
* Copyright (C) 2008-2017 TrinityCore <http://www.trinitycore.org/>
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
#include "PhasingHandler.h"

enum Spells
{
    SPELL_JETSAM_TARGET = 220295,
    SPELL_JETSAM_DAMAGE = 220354,

    SPELL_BREAKSAM_CAST = 223317,
    SPELL_BREAKSAM_DAMAGE = 219497,

    SPELL_YAKSAM_CAST = 223373,
    SPELL_YAKSAM_DAMAGE = 223374,

    SPELL_YAKSAM_SUMM_1 = 223404,
    SPELL_YAKSAM_SUMM_2 = 223403,
    SPELL_YAKSAM_SUMM_3 = 223391,

    SPELL_OOZING_BILE_AURA = 223355,
    SPELL_OOZING_BILE_MISSILE = 223361,

    SPELL_GETSAM_TARGET = 220340,
    SPELL_GETSAM_DAMAGE = 220367,

    SPELL_FLOTSAM_SLEEP = 204253
};

enum Events
{
    EVENT_JETSAM    = 1,
    EVENT_BREAKSAM  = 2,
    EVENT_YAKSAM    = 3,
    EVENT_GETSAM    = 4,
    EVENT_YAKSAM_SUMMON = 5
};

enum NPCs
{
    NPC_FLOTSAM = 99929,
    NPC_JETSAM = 103203,
    NPC_REGURGITATED_MARSHTROOPER = 112128
};

enum Phases
{
    PHASE_ASLEEP = 0,
    PHASE_COMBAT = 1
};

class boss_flotsam : public CreatureScript
{
public:
    boss_flotsam() : CreatureScript("boss_flotsam") { }

    struct boss_flotsamAI : public WorldBossAI
    {
        int32 getsamCount;
        int32 manaTimer;

        boss_flotsamAI(Creature* creature) : WorldBossAI(creature)
        {
            getsamCount = 0;
            manaTimer = 0;
        }

        void Reset() override
        {
            _Reset();
            getsamCount = 0;
            me->SetFullHealth();
            me->GetMotionMaster()->MoveTargetedHome();
            me->SetPowerType(POWER_MANA);
            me->SetMaxPower(POWER_MANA, 100);
            me->SetPower(POWER_MANA, 0);
            me->RemoveFlag(UNIT_FIELD_FLAGS_2, UNIT_FLAG2_REGENERATE_POWER);
            events.SetPhase(PHASE_ASLEEP);
            events.Reset();
        }

        void EnterCombat(Unit* who) override
        {
            if (!who)
                return;
            me->setActive(true);
            DoZoneInCombat();
            me->SetFullHealth();
            events.Reset();
            events.SetPhase(PHASE_COMBAT);
            events.ScheduleEvent(EVENT_JETSAM, 10000);
            //me->AI()->Talk(88247); //On aggro text
            me->SetPower(POWER_MANA, 0);
            getsamCount = 0;
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            Reset();
            DoStopAttack();
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (events.Empty())
            {
                events.ScheduleEvent(EVENT_JETSAM, 1000);
            }

            if (me->IsInCombat())
            {
                manaTimer += diff;
                if (manaTimer >= 1000)
                {
                    if (me->GetPower(POWER_MANA) < 100)
                        me->ModifyPower(POWER_MANA, +2);
                    else
                        events.ScheduleEvent(EVENT_GETSAM, 200);

                    manaTimer = 0;
                }
            }

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_JETSAM:
                {
                    if (me->IsInCombat())
                    {
                        Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                        if (!target)
                            break;

                        DoCast(target, SPELL_JETSAM_TARGET, false);
                        getsamCount++;
                        events.ScheduleEvent(EVENT_BREAKSAM, 5000);
                    }
                    break;
                }
                case EVENT_BREAKSAM:
                {
                    me->CastSpell(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_BREAKSAM_CAST, false);

                    if (getsamCount >= 4)
                    {
                        events.ScheduleEvent(EVENT_YAKSAM, 5000);
                        getsamCount = 0;
                    } else
                        events.ScheduleEvent(EVENT_JETSAM, 10000);

                    break;
                }
                case EVENT_YAKSAM:
                {
                    me->CastSpell(SelectTarget(SELECT_TARGET_TOPAGGRO), SPELL_YAKSAM_CAST, false);
                    events.ScheduleEvent(EVENT_JETSAM, 5000);
                    events.ScheduleEvent(EVENT_YAKSAM_SUMMON, 200);
                    break;
                }
                case EVENT_GETSAM:
                {
                    me->CastSpell(me, SPELL_GETSAM_TARGET, false);
                    break;
                }
                case EVENT_YAKSAM_SUMMON:
                {
                    me->CastSpell(me, SPELL_YAKSAM_SUMM_1, false);
                    me->CastSpell(me, SPELL_YAKSAM_SUMM_2, false);
                    me->CastSpell(me, SPELL_YAKSAM_SUMM_3, false);
                    break;
                }
                }
            }

            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_flotsamAI(creature);
    }
};

class spell_flotsam_jetsam_target : public SpellScriptLoader
{
public:
    spell_flotsam_jetsam_target() : SpellScriptLoader("spell_flotsam_jetsam_target") { }

    class spell_flotsam_jetsam_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flotsam_jetsam_target_SpellScript);

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            PreventHitAura();

            Unit* hit = GetHitUnit();
            Unit* caster = GetCaster();

            if (!hit || !caster)
                return;

            if (Creature* tempSumm = caster->SummonCreature(NPC_JETSAM, hit->GetPositionX(), hit->GetPositionY(), hit->GetPositionZ(), 0, TEMPSUMMON_TIMED_DESPAWN, 120000))
            {
                tempSumm->SetGuidValue(UNIT_FIELD_SUMMONEDBY, caster->GetGUID());
                PhasingHandler::InheritPhaseShift(tempSumm, caster);
                tempSumm->SetName(caster->GetName());
                caster->AddAura(SPELL_JETSAM_TARGET, tempSumm);
                tempSumm->CastSpell(tempSumm, SPELL_JETSAM_DAMAGE, true);
            }

            caster->CastSpell(hit, SPELL_JETSAM_DAMAGE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_flotsam_jetsam_target_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_flotsam_jetsam_target_SpellScript();
    }
};

//220340
class spell_flotsam_getsam_target : public SpellScriptLoader
{
public:
    spell_flotsam_getsam_target() : SpellScriptLoader("spell_flotsam_getsam_target") { }

    class spell_flotsam_getsam_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flotsam_getsam_target_SpellScript);

        void FilterTargets(std::list<WorldObject*>& p_Targets)
        {
            if (Unit* caster = GetCaster())
            {
                p_Targets.remove_if([caster](WorldObject* object) -> bool
                {
                    if (object == nullptr || object->ToUnit() == nullptr)
                        return true;

                    Unit* unit = object->ToUnit();

                    if (unit == caster)
                        return true;

                    if (!unit->HasAura(SPELL_JETSAM_TARGET))
                        return true;

                    if (unit->GetOwner() != caster)
                        return true;

                    return false;
                });
            }
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_flotsam_getsam_target_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_flotsam_getsam_target_SpellScript();
    }
};

//220367
class spell_flotsam_getsam_damage : public SpellScriptLoader
{
public:
    spell_flotsam_getsam_damage() : SpellScriptLoader("spell_flotsam_getsam_damage") { }

    class spell_flotsam_getsam_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flotsam_getsam_damage_SpellScript);

        void HandleHit(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->KillSelf();
        }

        void Register() override
        {
            OnEffectHit += SpellEffectFn(spell_flotsam_getsam_damage_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_flotsam_getsam_damage_SpellScript();
    }
};

//223374
class spell_flotsam_yaksam_target : public SpellScriptLoader
{
public:
    spell_flotsam_yaksam_target() : SpellScriptLoader("spell_flotsam_yaksam_target") { }

    class spell_flotsam_yaksam_target_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flotsam_yaksam_target_SpellScript);

        void HandleHit()
        {
            Unit* caster = GetCaster();

            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_YAKSAM_SUMM_1, false);
            caster->CastSpell(caster, SPELL_YAKSAM_SUMM_2, false);
            caster->CastSpell(caster, SPELL_YAKSAM_SUMM_3, false);
        }

        void Register() override
        {
            OnCast += SpellCastFn(spell_flotsam_yaksam_target_SpellScript::HandleHit);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_flotsam_yaksam_target_SpellScript();
    }
};

//112128
class npc_flotsam_regurgitated_marshstomper : public CreatureScript
{
public:
    npc_flotsam_regurgitated_marshstomper() : CreatureScript("npc_flotsam_regurgitated_marshstomper") {}

    struct npc_flotsam_regurgitated_marshstomperAI : public ScriptedAI
    {
        npc_flotsam_regurgitated_marshstomperAI(Creature* creature) : ScriptedAI(creature) {}

        enum SpellData
        {
            SPELL_TO_CAST = 223355
        };

        void Reset() override
        {
            std::list<Unit*> targets;
            me->GetAttackableUnitListInRange(targets, 30.0f);
            targets.resize(1);
            Unit* target = targets.front();
            if (target)
            {
                me->CombatStart(target);
                me->GetMotionMaster()->MoveFollow(target, 0.0f, 0);
            }
            ApplyBuff();
        }

        void ApplyBuff()
        {
            if (!me)
                return;

            me->CastSpell(me, SPELL_TO_CAST, true); //Applies AreaTrigger aura
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_flotsam_regurgitated_marshstomperAI(creature);
    }
};

//223357
class spell_flotsam_oozing_bile_aura : public SpellScriptLoader
{
public:
    spell_flotsam_oozing_bile_aura() : SpellScriptLoader("spell_flotsam_oozing_bile_aura") { }

    class spell_flotsam_oozing_bile_aura_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_flotsam_oozing_bile_aura_SpellScript);

        void HandleLaunch(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            caster->CastSpell(caster, SPELL_OOZING_BILE_MISSILE, true);
        }

        void Register() override
        {
            OnEffectLaunch += SpellEffectFn(spell_flotsam_oozing_bile_aura_SpellScript::HandleLaunch, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_flotsam_oozing_bile_aura_SpellScript();
    }
};
void AddSC_boss_flotsam()
{
    new boss_flotsam();

    new npc_flotsam_regurgitated_marshstomper();

    new spell_flotsam_getsam_damage();
    new spell_flotsam_getsam_target();
    new spell_flotsam_jetsam_target();
    new spell_flotsam_oozing_bile_aura();
    //new spell_flotsam_yaksam_target();
}
