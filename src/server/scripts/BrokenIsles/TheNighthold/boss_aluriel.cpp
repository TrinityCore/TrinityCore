/*
 * Copyright (C) 2022 BfaCore Reforged
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

#include "AreaTrigger.h"
#include "AreaTriggerAI.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Player.h"
#include "ObjectAccessor.h"
#include "MoveSpline.h"
#include "MoveSplineFlag.h"
#include "MoveSplineInit.h"
#include "SpellHistory.h"
#include "SpellMgr.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "SpellAuraEffects.h"
#include "thenighthold.h"
#include "CreatureAIImpl.h"
#include "Log.h"
#include "Object.h"
#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"

enum Texts
{
    SAY_AGGRO         = 0,
    SAY_ANNIHILATE    = 1,
    SAY_FROST         = 2,
    SAY_REPLICATE     = 3,
    SAY_4             = 4,
    SAY_DETONATE      = 5,
    SAY_ANIMATE       = 6,
    SAY_ANNIHILATE2   = 7,
    SAY_ANNIHILATE3   = 8,
    SAY_DEATH         = 9,
};
enum Spells
{
    SPELL_ANNIHILATE              = 212492,
    SPELL_ANNIHILATE_DEB          = 215458,
    SPELL_MARK_OF_FROST           = 212587,
    SPELL_MARK_OF_FROST_AOE       = 212648,
    SPELL_FROSTBITTEN             = 212647,
    SPELL_REPLICATE_MARK_OF_FROST = 212530,
    SPELL_DETONATE                = 212735,
    SPELL_AREA_DETONATE           = 212734,
    SPELL_POOL_OF_FROST           = 212736,
    SPELL_ANIMATE                 = 213853,
    SPELL_ANIMATE_SUMMON          = 213854,
    SPELL_FIERY_ENCHANTMENT       = 213867,
    SPELL_FROST_ENCHANTMENT       = 216389,
};

enum Events
{
    EVENT_ANNIHILATE    = 1,
    EVENT_STATE_FROST   = 2,
    EVENT_MARK_OF_FROST = 3,
    EVENT_REPLICATE_MARK_OF_FROST = 4,
    EVENT_FROST_SAY     = 5,
    EVENT_DETONATE      = 6,
    EVENT_ANIMATE       = 7,
    EVENT_STATE_FIRE    = 8,

};

class boss_aluriel : public CreatureScript {
public:
    boss_aluriel() : CreatureScript("boss_aluriel") { }

    struct boss_alurielAI : public BossAI {
        boss_alurielAI(Creature* creature) : BossAI(creature, BOSS_ALURIEL)
        {
        }

        uint8 curID;
        EventMap events;
        int8 annihilate = 0;

        void StartMovePath()
        {
            Movement::MoveSplineInit init(me);
            init.SetCyclic();
            init.SetSmooth();
            init.SetVelocity(4.0f);
            init.MovebyPath(WaypointAlurielAnomaly, 0);
            init.Launch();
        }

        void EnterCombat(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            DoZoneInCombat();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            _EnterCombat();

            events.ScheduleEvent(EVENT_ANNIHILATE, 8000);
            events.ScheduleEvent(EVENT_STATE_FROST, 25000);
        }

        void Reset() override
        {
            events.Reset();
            StartMovePath();
            _Reset();
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            annihilate = 0;
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            me->RemoveAllAreaTriggers();

            _DespawnAtEvade();
            summons.DespawnAll();
        }

        void KilledUnit(Unit* /*who*/) override
        {
            //if (who->ToPlayer())
            //   Talk(SAY_KILL);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_ANNIHILATE:
                {
                    uint8 say = SAY_ANNIHILATE;
                    if (annihilate == 1)
                        say = SAY_ANNIHILATE2;
                    else if (annihilate > 1)
                        say = SAY_ANNIHILATE3;

                    Talk(say);

                    DoCastVictim(SPELL_ANNIHILATE);
                    annihilate++;
                    events.ScheduleEvent(EVENT_ANNIHILATE, 45000);
                    break;
                }
                case EVENT_STATE_FROST:
                    Talk(SAY_FROST);
                    events.ScheduleEvent(EVENT_MARK_OF_FROST, 5000);
                    break;
                case EVENT_MARK_OF_FROST:
                {
                    std::list<Unit*> targetList;
                    float radius = 50.0f;
                    std::list<Unit*> validList;
                    me->GetAttackableUnitListInRange(targetList, radius);

                    if (!targetList.empty())
                        for (auto itr : targetList)
                            if (me->IsValidAttackTarget(itr))
                                validList.push_back(itr);

                    Trinity::Containers::RandomResize(validList, 2);
                    if (!validList.empty())
                        for (auto itr : validList)
                            itr->CastSpell(itr, SPELL_MARK_OF_FROST, true);

                    events.ScheduleEvent(EVENT_REPLICATE_MARK_OF_FROST, 15000);
                    break;
                }
                case EVENT_REPLICATE_MARK_OF_FROST:
                {
                    Talk(SAY_REPLICATE);
                    DoCast(SPELL_REPLICATE_MARK_OF_FROST);
                    events.ScheduleEvent(EVENT_FROST_SAY, 9000);
                    break;
                }
                case EVENT_FROST_SAY:
                {
                    Talk(SAY_4);
                    events.ScheduleEvent(EVENT_DETONATE, 15000);
                    break;
                }
                case EVENT_DETONATE:
                {
                    DoCast(SPELL_DETONATE);
                    Talk(SAY_DETONATE);
                    events.ScheduleEvent(EVENT_ANIMATE, 7000);
                    break;
                }
                case EVENT_ANIMATE:
                {
                    Talk(SAY_ANIMATE);
                    DoCast(SPELL_ANIMATE);
                    me->RemoveAllAreaTriggers();
                    events.ScheduleEvent(EVENT_STATE_FIRE, 10000);
                    break;
                }
                case EVENT_STATE_FIRE:
                {
                    // 16:38:39
                    me->RemoveAura(SPELL_FROST_ENCHANTMENT);
                    DoCast(SPELL_FIERY_ENCHANTMENT);
                    break;
                }
                default:
                    break;
                }
            }

            DoMeleeAttackIfReady();
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<boss_alurielAI>(creature);
    }
};

// Mark of Frost - 212587
// 7.3.5
class spell_gen_mark_of_frost : public SpellScriptLoader
{
public:
    spell_gen_mark_of_frost() : SpellScriptLoader("spell_gen_mark_of_frost") { }

    class spell_gen_mark_of_frost_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_mark_of_frost_AuraScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_MARK_OF_FROST))
                return false;
            return true;
        }

        void Tick(AuraEffect const* /*aurEff*/)
        {
            if (Unit* caster = GetCaster())
            {
                std::list<Unit*> targetList;
                float radius = 2.0f;
                Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(caster, caster, radius);
                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(caster, targetList, u_check);
                Cell::VisitAllObjects(caster, searcher, radius);

                if (!targetList.empty())
                    for (auto itr : targetList)
                        if (caster->IsFriendlyTo(itr))
                            if (itr->HasAura(SPELL_MARK_OF_FROST) && itr != caster)
                            {
                                std::list<Unit*> PlayerList;
                                radius = 50.0f;
                                std::list<Unit*> validList;
                                Trinity::AnyFriendlyUnitInObjectRangeCheck u_check(caster, caster, radius);
                                Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(caster, PlayerList, u_check);
                                Cell::VisitAllObjects(caster, searcher, radius);

                                if (!PlayerList.empty())
                                    for (auto itr2 : PlayerList)
                                        if (caster->IsFriendlyTo(itr2))
                                            validList.push_back(itr2);

                                Trinity::Containers::RandomResize(validList, 2);
                                if (!validList.empty())
                                {
                                    itr->RemoveAura(GetId());
                                    caster->RemoveAura(GetId());

                                    for (auto newtarget : validList)
                                    {
                                        if (Aura* newaura = caster->AddAura(GetId(), newtarget))
                                            newaura->SetDuration(GetDuration());

                                        if (newtarget == caster || newtarget == itr)
                                            newtarget->RemoveAura(SPELL_FROSTBITTEN);
                                    }


                                    caster->CastSpell(caster, SPELL_MARK_OF_FROST_AOE, true);
                                }
                            }
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_gen_mark_of_frost_AuraScript::Tick, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gen_mark_of_frost_AuraScript();
    }
};

// 212531 Mark of Forst
// 7.3.5
class spell_gen_target_mark_of_forst : public SpellScriptLoader
{
public:
    spell_gen_target_mark_of_forst() : SpellScriptLoader("spell_gen_target_mark_of_forst") { }

    class spell_gen_target_mark_of_forst_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_gen_target_mark_of_forst_AuraScript);


        void HandleRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (Unit* caster = GetTarget())
                caster->CastSpell(caster, SPELL_MARK_OF_FROST, true);
        }

        void Register() override
        {
            AfterEffectRemove += AuraEffectApplyFn(spell_gen_target_mark_of_forst_AuraScript::HandleRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_gen_target_mark_of_forst_AuraScript();
    }
};

// Detonate 212735
// 7.3.5
class spell_gen_aluriel_detonate : public SpellScriptLoader
{
public:
    spell_gen_aluriel_detonate() : SpellScriptLoader("spell_gen_aluriel_detonate") { }

    class spell_gen_aluriel_detonate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_aluriel_detonate_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targetsList)
        {
            targetsList.remove_if([](WorldObject* obj)
            {
                if (Unit* target = obj->ToUnit())
                    return !target->HasAura(SPELL_MARK_OF_FROST);

                return true;
            });
        }

        void Detonate(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            caster->CastSpell(target, SPELL_AREA_DETONATE, true);
            target->CastSpell(target, SPELL_MARK_OF_FROST_AOE, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_aluriel_detonate_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_gen_aluriel_detonate_SpellScript::Detonate, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gen_aluriel_detonate_SpellScript();
    }
};

// Mark of frost detonate 212734
// Last Update 7.1.5
class areatrigger_mark_of_frost_detonate : public AreaTriggerEntityScript
{
public:
    areatrigger_mark_of_frost_detonate() : AreaTriggerEntityScript("areatrigger_mark_of_frost_detonate") { }

    struct areatrigger_mark_of_frost_detonateAI : AreaTriggerAI
    {
        areatrigger_mark_of_frost_detonateAI(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

        void OnUnitEnter(Unit* unit) override
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(SPELL_POOL_OF_FROST);
            Unit* caster = at->GetCaster();
            if (!caster || !unit || !spellInfo)
                return;

            if (!caster->IsValidAttackTarget(unit))
                return;

            if (!unit->HasAura(spellInfo->Id, caster->GetGUID()))
                caster->AddAura(spellInfo->Id, unit);
        }

        void OnUnitExit(Unit* unit) override
        {
            Unit* caster = at->GetCaster();
            if (!caster || !unit)
                return;

            if (unit->HasAura(SPELL_POOL_OF_FROST, caster->GetGUID()))
                unit->RemoveAura(SPELL_POOL_OF_FROST, caster->GetGUID());
        }
    };

    AreaTriggerAI* GetAI(AreaTrigger* areatrigger) const override
    {
        return new areatrigger_mark_of_frost_detonateAI(areatrigger);
    }
};

// 213853
// 7.3.5
class spell_gen_aluriel_animate : public SpellScriptLoader
{
public:
    spell_gen_aluriel_animate() : SpellScriptLoader("spell_gen_aluriel_animate") { }

    class spell_gen_aluriel_animate_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gen_aluriel_animate_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targetsList)
        {
            targetsList.remove_if([](WorldObject* obj)
            {
                if (Creature* target = obj->ToCreature())
                    return target->GetEntry() != 107694;

                return true;
            });
        }

        void Animate(SpellEffIndex /*effIndex*/)
        {
            if (Unit * target = GetHitUnit())
                GetCaster()->CastSpell(target, SPELL_ANIMATE_SUMMON, true);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gen_aluriel_animate_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_gen_aluriel_animate_SpellScript::Animate, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gen_aluriel_animate_SpellScript();
    }
};

void AddSC_boss_aluriel()
{
    new boss_aluriel();
    new spell_gen_mark_of_frost();
    new spell_gen_target_mark_of_forst();
    new spell_gen_aluriel_detonate();
    new areatrigger_mark_of_frost_detonate();
    new spell_gen_aluriel_animate();
}
