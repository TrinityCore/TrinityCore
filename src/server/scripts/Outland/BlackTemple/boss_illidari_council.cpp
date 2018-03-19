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

#include "CellImpl.h"
#include "GridNotifiersImpl.h"
#include "InstanceScript.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "black_temple.h"

enum Says
{
    SAY_COUNCIL_AGRO        = 0,
    SAY_COUNCIL_ENRAGE      = 1,
    SAY_COUNCIL_SPECIAL     = 2,
    SAY_COUNCIL_SLAY        = 3,
    SAY_COUNCIL_COMNT       = 4,
    SAY_COUNCIL_DEATH       = 5
};

enum Spells
{
    // Illidari Council (Trigger)
    SPELL_EMPYREAL_BALANCE              = 41499,
    SPELL_EMPYREAL_EQUIVALENCY          = 41333,

    // Generic
    SPELL_SHARED_RULE                   = 41342,
    SPELL_BERSERK                       = 45078,
    SPELL_BALANCE_OF_POWER              = 41341,
    SPELL_QUIET_SUICIDE                 = 3617, // Serverside spell

    // High Nethermancer Zerevor's
    SPELL_FLAMESTRIKE                   = 41481,
    SPELL_BLIZZARD                      = 41482,
    SPELL_ARCANE_BOLT                   = 41483,
    SPELL_ARCANE_EXPLOSION              = 41524,
    SPELL_DAMPEN_MAGIC                  = 41478,

    // Lady Malande's
    SPELL_EMPOWERED_SMITE               = 41471,
    SPELL_CIRCLE_OF_HEALING             = 41455,
    SPELL_REFLECTIVE_SHIELD             = 41475,
    SPELL_REFLECTIVE_SHIELD_DAMAGE      = 33619,
    SPELL_DIVINE_WRATH                  = 41472,

    // Gathios the Shatterer's
    SPELL_BLESS_PROTECTION              = 41450,
    SPELL_BLESS_SPELL_WARDING           = 41451,
    SPELL_CONSECRATION                  = 41541,
    SPELL_HAMMER_OF_JUSTICE             = 41468,
    SPELL_SEAL_OF_COMMAND               = 41469,
    SPELL_SEAL_OF_BLOOD                 = 41459,
    SPELL_CHROMATIC_AURA                = 41453,
    SPELL_DEVOTION_AURA                 = 41452,
    SPELL_JUDGEMENT_PRIMER              = 41473,
    SPELL_JUDGEMENT                     = 41467,
    SPELL_JUDGEMENT_OF_COMMAND          = 41470,
    SPELL_JUDGEMENT_OF_BLOOD            = 41461,

    // Veras Darkshadow's
    SPELL_DEADLY_STRIKE                 = 41480,
    SPELL_DEADLY_POISON                 = 41485,
    SPELL_ENVENOM                       = 41487,
    SPELL_VANISH                        = 41476,

    // Veras Vanish Effect
    SPELL_BIRTH                         = 40031,
    SPELL_ENVENOM_DUMMY                 = 41510
};

enum IllidariEvents
{
    EVENT_EMPYREAL_EQUIVALENCY = 1,
    EVENT_VANISH,
    EVENT_DEADLY_STRIKE,
    EVENT_FLAMESTRIKE,
    EVENT_BLIZZARD,
    EVENT_ARCANE_EXPLOSION,
    EVENT_ARCANE_EXPLOSION_CHECK,
    EVENT_DAMPEN_MAGIC,
    EVENT_BLESS,
    EVENT_CONSECRATION,
    EVENT_AURA,
    EVENT_JUDGEMENT,
    EVENT_HAMMER_OF_JUSTICE,
    EVENT_CIRCLE_OF_HEALING,
    EVENT_REFLECTIVE_SHIELD,
    EVENT_DIVINE_WRATH,
    EVENT_BERSERK
};

enum IllidariMisc
{
    SUMMON_COUNCIL_GROUP = 1,
    ACTION_REFRESH_DAMPEN
};

uint32 const CouncilData[4] =
{
    DATA_GATHIOS_THE_SHATTERER,
    DATA_HIGH_NETHERMANCER_ZEREVOR,
    DATA_LADY_MALANDE,
    DATA_VERAS_DARKSHADOW
};

static uint32 GetRandomBossExcept(uint32 exception)
{
    std::vector<uint32> bossData;
    for (uint32 data : CouncilData)
        if (data != exception)
            bossData.emplace_back(data);

    return bossData[urand(0, 3)];
}

class boss_illidari_council : public CreatureScript
{
public:
    boss_illidari_council() : CreatureScript("boss_illidari_council") { }

    struct boss_illidari_councilAI : public BossAI
    {
        boss_illidari_councilAI(Creature* creature) : BossAI(creature, DATA_ILLIDARI_COUNCIL), _inCombat(false) { }

        void Reset() override
        {
            _Reset();
            _inCombat = false;
            me->SummonCreatureGroup(SUMMON_COUNCIL_GROUP);
            DoCastSelf(SPELL_EMPYREAL_BALANCE, true);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            if (!_inCombat)
            {
                _inCombat = true;
                _EnterCombat();
                for (uint32 bossData : CouncilData)
                {
                    if (Creature* council = instance->GetCreature(bossData))
                    {
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, council);
                        DoZoneInCombat(council);
                    }
                }
                events.ScheduleEvent(EVENT_EMPYREAL_EQUIVALENCY, Seconds(2));
                events.ScheduleEvent(EVENT_BERSERK, Minutes(15));
                if (Creature* council = instance->GetCreature(CouncilData[urand(0, 3)]))
                    council->AI()->Talk(SAY_COUNCIL_AGRO);
            }
        }

        void EnterEvadeMode(EvadeReason /*why*/) override
        {
            if (!me->IsInEvadeMode())
            {
                _inCombat = false;
                for (uint32 bossData : CouncilData)
                    if (Creature* council = instance->GetCreature(bossData))
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);

                summons.DespawnAll();
                _DespawnAtEvade();
            }
        }

        void JustDied(Unit* /*killer*/) override
        {
            _inCombat = false;
            events.Reset();
            instance->SetBossState(DATA_ILLIDARI_COUNCIL, DONE);

            for (uint32 bossData : CouncilData)
            {
                if (Creature* council = instance->GetCreature(bossData))
                {
                    // Allow loot
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, council);
                    council->LowerPlayerDamageReq(council->GetMaxHealth());
                    council->CastSpell(council, SPELL_QUIET_SUICIDE, true);
                }
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_EMPYREAL_EQUIVALENCY:
                        DoCastSelf(SPELL_EMPYREAL_EQUIVALENCY, true);
                        events.Repeat(Seconds(2));
                        break;
                    case EVENT_BERSERK:
                        for (uint32 bossData : CouncilData)
                        {
                            if (Creature* council = instance->GetCreature(bossData))
                            {
                                council->CastSpell(council, SPELL_BERSERK, true);
                                council->AI()->Talk(SAY_COUNCIL_ENRAGE);
                            }
                        }
                        break;
                    default:
                        break;
                }

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }
        }

        private:
            bool _inCombat;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_illidari_councilAI>(creature);
    }
};

struct IllidariCouncilBossAI : public BossAI
{
    IllidariCouncilBossAI(Creature* creature, uint32 bossId) : BossAI(creature, bossId), _bossId(bossId)
    {
        SetBoundary(instance->GetBossBoundary(DATA_ILLIDARI_COUNCIL));
    }

    void Reset() override
    {
        me->SetCombatPulseDelay(0);
        events.Reset();
    }

    void EnterCombat(Unit* /*who*/) override
    {
        me->SetCombatPulseDelay(5);
        me->setActive(true);
        if (Creature* illidari = instance->GetCreature(DATA_ILLIDARI_COUNCIL))
            DoZoneInCombat(illidari);
        ScheduleEvents();
    }

    virtual void ScheduleEvents() = 0;

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_COUNCIL_DEATH);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        if (Creature* illidari = instance->GetCreature(DATA_ILLIDARI_COUNCIL))
            illidari->AI()->EnterEvadeMode(why);
    }

    void DamageTaken(Unit* who, uint32 &damage) override
    {
        if (damage >= me->GetHealth() && who->GetGUID() != me->GetGUID())
            damage = me->GetHealth() - 1;
    }

    void KilledUnit(Unit* victim) override
    {
        if (victim->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_COUNCIL_SLAY);

        if (roll_chance_i(30))
            if (Creature* boss = instance->GetCreature(GetRandomBossExcept(_bossId)))
                boss->AI()->Talk(SAY_COUNCIL_COMNT);
    }

private:
    uint32 _bossId;
};

class HammerTargetSelector : public std::unary_function<Unit*, bool>
{
public:
    HammerTargetSelector(Unit const* unit) : _me(unit) { }

    bool operator()(Unit* unit) const
    {
        return _me->IsInRange(unit, 10.0f, 40.0f);
    }

private:
    Unit const* _me;
};

class boss_gathios_the_shatterer : public CreatureScript
{
public:
    boss_gathios_the_shatterer() : CreatureScript("boss_gathios_the_shatterer") { }

    struct boss_gathios_the_shattererAI : public IllidariCouncilBossAI
    {
        boss_gathios_the_shattererAI(Creature* creature) : IllidariCouncilBossAI(creature, DATA_GATHIOS_THE_SHATTERER) { }

        void ScheduleEvents() override
        {
            DoCastSelf(SPELL_SEAL_OF_BLOOD);
            events.ScheduleEvent(EVENT_BLESS, Seconds(20));
            events.ScheduleEvent(EVENT_CONSECRATION, Seconds(10));
            events.ScheduleEvent(EVENT_HAMMER_OF_JUSTICE, Seconds(10));
            events.ScheduleEvent(EVENT_JUDGEMENT, Seconds(15));
            events.ScheduleEvent(EVENT_AURA, Seconds(6));
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_BLESS:
                {
                    std::list<Unit*> TargetList;
                    Trinity::AnyFriendlyUnitInObjectRangeCheck checker(me, me, 100.0f);
                    Trinity::UnitListSearcher<Trinity::AnyFriendlyUnitInObjectRangeCheck> searcher(me, TargetList, checker);
                    Cell::VisitAllObjects(me, searcher, 100.0f);

                    if (!TargetList.empty())
                    {
                        Unit* target = Trinity::Containers::SelectRandomContainerElement(TargetList);
                        DoCast(target, RAND(SPELL_BLESS_PROTECTION, SPELL_BLESS_SPELL_WARDING));
                    }
                    events.Repeat(Seconds(30), Seconds(45));
                    break;
                }
                case EVENT_AURA:
                    DoCastSelf(RAND(SPELL_CHROMATIC_AURA, SPELL_DEVOTION_AURA));
                    events.Repeat(Seconds(30));
                    break;
                case EVENT_HAMMER_OF_JUSTICE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, HammerTargetSelector(me)))
                        DoCast(target, SPELL_HAMMER_OF_JUSTICE);
                    events.Repeat(Seconds(20));
                    break;
                case EVENT_JUDGEMENT:
                    DoCastVictim(SPELL_JUDGEMENT);
                    events.Repeat(Seconds(15));
                    break;
                case EVENT_CONSECRATION:
                    DoCastSelf(SPELL_CONSECRATION);
                    events.Repeat(Seconds(30), Seconds(35));
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_gathios_the_shattererAI>(creature);
    }
};

class boss_high_nethermancer_zerevor : public CreatureScript
{
public:
    boss_high_nethermancer_zerevor() : CreatureScript("boss_high_nethermancer_zerevor") { }

    struct boss_high_nethermancer_zerevorAI : public IllidariCouncilBossAI
    {
        boss_high_nethermancer_zerevorAI(Creature* creature) : IllidariCouncilBossAI(creature, DATA_HIGH_NETHERMANCER_ZEREVOR), _canUseArcaneExplosion(true) { }

        void Reset() override
        {
            IllidariCouncilBossAI::Reset();
            _canUseArcaneExplosion = true;
            DoCastSelf(SPELL_DAMPEN_MAGIC);
        }

        void ScheduleEvents() override
        {
            events.ScheduleEvent(EVENT_FLAMESTRIKE, Seconds(8));
            events.ScheduleEvent(EVENT_BLIZZARD, Seconds(25));
            events.ScheduleEvent(EVENT_ARCANE_EXPLOSION, Seconds(5));
            DoCastSelf(SPELL_DAMPEN_MAGIC);
        }

        void DoAction(int32 actionId) override
        {
            if (actionId == ACTION_REFRESH_DAMPEN)
                events.ScheduleEvent(EVENT_DAMPEN_MAGIC, Seconds(50));
        }
        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_FLAMESTRIKE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_FLAMESTRIKE);
                    Talk(SAY_COUNCIL_SPECIAL);
                    events.Repeat(Seconds(40));
                    break;
                case EVENT_BLIZZARD:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0))
                        DoCast(target, SPELL_BLIZZARD);
                    events.Repeat(Seconds(15), Seconds(40));
                    break;
                case EVENT_ARCANE_EXPLOSION_CHECK:
                    _canUseArcaneExplosion = true;
                    break;
                case EVENT_ARCANE_EXPLOSION:
                    if (_canUseArcaneExplosion && SelectTarget(SELECT_TARGET_RANDOM, 0, 10.0f))
                    {
                        DoCastSelf(SPELL_ARCANE_EXPLOSION);
                        _canUseArcaneExplosion = false;
                        events.ScheduleEvent(EVENT_ARCANE_EXPLOSION_CHECK, Seconds(5));
                    }
                    events.Repeat(Seconds(1));
                    break;
                case EVENT_DAMPEN_MAGIC:
                    DoCastSelf(SPELL_DAMPEN_MAGIC);
                    break;
                default:
                    break;
            }
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
                ExecuteEvent(eventId);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoSpellAttackIfReady(SPELL_ARCANE_BOLT);
        }

    private:
        bool _canUseArcaneExplosion;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_high_nethermancer_zerevorAI>(creature);
    }

};

class boss_lady_malande : public CreatureScript
{
public:
    boss_lady_malande() : CreatureScript("boss_lady_malande") { }

    struct boss_lady_malandeAI : public IllidariCouncilBossAI
    {
        boss_lady_malandeAI(Creature* creature) : IllidariCouncilBossAI(creature, DATA_LADY_MALANDE) { }

        void ScheduleEvents() override
        {
            events.ScheduleEvent(EVENT_CIRCLE_OF_HEALING, Seconds(20));
            events.ScheduleEvent(EVENT_REFLECTIVE_SHIELD, Seconds(25));
            events.ScheduleEvent(EVENT_DIVINE_WRATH, Seconds(32));
        }

        void HealReceived(Unit* /*who*/, uint32& addhealth) override
        {
            // Need be negative to heal trigger
            int32 bp = addhealth * (-1);
            me->CastCustomSpell(SPELL_SHARED_RULE, SPELLVALUE_BASE_POINT0, bp, (Unit*) nullptr, true);
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_CIRCLE_OF_HEALING:
                    DoCastSelf(SPELL_CIRCLE_OF_HEALING);
                    events.Repeat(Seconds(20), Seconds(35));
                    break;
                case EVENT_REFLECTIVE_SHIELD:
                    DoCastSelf(SPELL_REFLECTIVE_SHIELD);
                    Talk(SAY_COUNCIL_SPECIAL);
                    events.Repeat(Seconds(40));
                    break;
                case EVENT_DIVINE_WRATH:
                    DoCastVictim(SPELL_DIVINE_WRATH);
                    events.Repeat(Seconds(20));
                    break;
                default:
                    break;
            }
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
                ExecuteEvent(eventId);
                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;
            }

            DoSpellAttackIfReady(SPELL_EMPOWERED_SMITE);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_lady_malandeAI>(creature);
    }

};

class boss_veras_darkshadow : public CreatureScript
{
public:
    boss_veras_darkshadow() : CreatureScript("boss_veras_darkshadow") { }

    struct boss_veras_darkshadowAI : public IllidariCouncilBossAI
    {
        boss_veras_darkshadowAI(Creature* creature) : IllidariCouncilBossAI(creature, DATA_VERAS_DARKSHADOW)
        {
            me->SetMaxHealth(1327900);
            me->SetFullHealth();
        }

        void ScheduleEvents() override
        {
            events.ScheduleEvent(EVENT_DEADLY_STRIKE, Seconds(18));
            events.ScheduleEvent(EVENT_VANISH, Seconds(18));
        }

        void ExecuteEvent(uint32 eventId) override
        {
            switch (eventId)
            {
                case EVENT_DEADLY_STRIKE:
                    DoCastSelf(SPELL_DEADLY_STRIKE);
                    events.Repeat(Seconds(60));
                    break;
                case EVENT_VANISH:
                    DoCastSelf(SPELL_VANISH);
                    Talk(SAY_COUNCIL_SPECIAL);
                    events.Repeat(Seconds(60));
                    break;
                default:
                    break;
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<boss_veras_darkshadowAI>(creature);
    }
};

class npc_veras_vanish_effect : public CreatureScript
{
public:
    npc_veras_vanish_effect() : CreatureScript("npc_veras_vanish_effect") { }

    struct npc_veras_vanish_effectAI : public PassiveAI
    {
        npc_veras_vanish_effectAI(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            DoCastSelf(SPELL_BIRTH, true);
            DoCastSelf(SPELL_ENVENOM_DUMMY, true);
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetBlackTempleAI<npc_veras_vanish_effectAI>(creature);
    }
};

// 41499 - Empyreal Balance
class spell_illidari_council_empyreal_balance : public SpellScriptLoader
{
    public:
        spell_illidari_council_empyreal_balance() : SpellScriptLoader("spell_illidari_council_empyreal_balance") { }

        class spell_illidari_council_empyreal_balance_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_illidari_council_empyreal_balance_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_BALANCE_OF_POWER });
            }

            void HandleDummy(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                target->CastSpell(target, SPELL_BALANCE_OF_POWER, true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_illidari_council_empyreal_balance_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_illidari_council_empyreal_balance_SpellScript();
        }
};

// 41333 - Empyreal Equivalency
class spell_illidari_council_empyreal_equivalency : public SpellScriptLoader
{
    public:
        spell_illidari_council_empyreal_equivalency() : SpellScriptLoader("spell_illidari_council_empyreal_equivalency") { }

        class spell_illidari_council_empyreal_equivalency_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_illidari_council_empyreal_equivalency_SpellScript);

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* target = GetHitUnit();
                int32 casterHpPct = (int32) GetCaster()->GetHealthPct();
                uint32 newHp = target->CountPctFromMaxHealth(casterHpPct);
                if (newHp <= 0)
                    newHp = target->GetMaxHealth() - 1;
                target->SetHealth(newHp);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_illidari_council_empyreal_equivalency_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_illidari_council_empyreal_equivalency_SpellScript();
        }
};

// 41341 - Balance of Power
class spell_illidari_council_balance_of_power : public SpellScriptLoader
{
    public:
        spell_illidari_council_balance_of_power() : SpellScriptLoader("spell_illidari_council_balance_of_power") { }

        class spell_illidari_council_balance_of_power_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_council_balance_of_power_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SHARED_RULE });
            }

            void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& /*absorbAmount*/)
            {
                PreventDefaultAction();
                int32 bp = dmgInfo.GetDamage();
                GetTarget()->CastCustomSpell(SPELL_SHARED_RULE, SPELLVALUE_BASE_POINT0, bp, (Unit*) nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectAbsorb += AuraEffectAbsorbFn(spell_illidari_council_balance_of_power_AuraScript::Absorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_council_balance_of_power_AuraScript();
        }
};

// 41480 - Deadly Strike
class spell_illidari_council_deadly_strike : public SpellScriptLoader
{
    public:
        spell_illidari_council_deadly_strike() : SpellScriptLoader("spell_illidari_council_deadly_strike") { }

        class spell_illidari_council_deadly_strike_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_council_deadly_strike_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_DEADLY_POISON });
            }

            void OnTrigger(AuraEffect const* aurEff)
            {
                PreventDefaultAction();

                if (Unit* victim = GetTarget()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0))
                    GetTarget()->CastSpell(victim, SPELL_DEADLY_POISON, true, nullptr, aurEff);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_illidari_council_deadly_strike_AuraScript::OnTrigger, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_council_deadly_strike_AuraScript();
        }
};

// 41485 - Deadly Poison
class spell_illidari_council_deadly_poison : public SpellScriptLoader
{
    public:
        spell_illidari_council_deadly_poison() : SpellScriptLoader("spell_illidari_council_deadly_poison") { }

        class spell_illidari_council_deadly_poison_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_council_deadly_poison_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_ENVENOM });
            }

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Unit* caster = GetCaster())
                    caster->CastSpell(GetTarget(), SPELL_ENVENOM, true);
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_illidari_council_deadly_poison_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_council_deadly_poison_AuraScript();
        }
};

// 41475 - Reflective Shield
class spell_illidari_council_reflective_shield : public SpellScriptLoader
{
    public:
        spell_illidari_council_reflective_shield() : SpellScriptLoader("spell_illidari_council_reflective_shield") { }

        class spell_illidari_council_reflective_shield_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_council_reflective_shield_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_REFLECTIVE_SHIELD_DAMAGE });
            }

            void OnAbsorb(AuraEffect* aurEff, DamageInfo & dmgInfo, uint32 & absorbAmount)
            {
                Unit* target = GetTarget();
                if (dmgInfo.GetAttacker() == target)
                    return;

                int32 bp = absorbAmount / 2;
                target->CastCustomSpell(dmgInfo.GetAttacker(), SPELL_REFLECTIVE_SHIELD_DAMAGE, &bp, nullptr, nullptr, true, nullptr, aurEff);
            }

            void Register() override
            {
                 AfterEffectAbsorb += AuraEffectAbsorbFn(spell_illidari_council_reflective_shield_AuraScript::OnAbsorb, EFFECT_0);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_council_reflective_shield_AuraScript();
        }
};

// 41467 - Judgement
class spell_illidari_council_judgement : public SpellScriptLoader
{
    public:
        spell_illidari_council_judgement() : SpellScriptLoader("spell_illidari_council_judgement") { }

        class spell_illidari_council_judgement_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_illidari_council_judgement_SpellScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo(
                {
                    SPELL_JUDGEMENT_OF_BLOOD,
                    SPELL_JUDGEMENT_OF_COMMAND,
                    SPELL_JUDGEMENT_PRIMER
                });
            }

            void HandleScript(SpellEffIndex /*effIndex*/)
            {
                Unit* caster = GetCaster();
                Unit* target = GetHitUnit();
                uint32 judgementId = caster->HasAura(SPELL_SEAL_OF_BLOOD) ? SPELL_JUDGEMENT_OF_BLOOD : SPELL_JUDGEMENT_OF_COMMAND;
                caster->CastSpell(target, SPELL_JUDGEMENT_PRIMER, true);
                caster->CastSpell(target, judgementId, true);
            }

            void OnFinishCast()
            {
                if (Creature* caster = GetCaster()->ToCreature())
                    caster->AI()->Talk(SAY_COUNCIL_SPECIAL);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_illidari_council_judgement_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
                AfterCast += SpellCastFn(spell_illidari_council_judgement_SpellScript::OnFinishCast);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_illidari_council_judgement_SpellScript();
        }
};

/* 41469 - Seal of Command
   41459 - Seal of Blood */
class spell_illidari_council_seal : public SpellScriptLoader
{
    public:
        spell_illidari_council_seal() : SpellScriptLoader("spell_illidari_council_seal") { }

        class spell_illidari_council_seal_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_council_seal_AuraScript);

            bool Validate(SpellInfo const* /*spellInfo*/) override
            {
                return ValidateSpellInfo({ SPELL_SEAL_OF_COMMAND, SPELL_SEAL_OF_BLOOD });
            }

            void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
            {
                Unit* target = GetTarget();
                if (target->IsInWorld() && target->IsAlive())
                {
                    uint32 spellId = aurEff->GetId() == SPELL_SEAL_OF_COMMAND ? SPELL_SEAL_OF_BLOOD : SPELL_SEAL_OF_COMMAND;
                    target->CastSpell(target, spellId, true);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_illidari_council_seal_AuraScript::OnRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_council_seal_AuraScript();
        }
};

// 41478 - Dampen Magic
class spell_illidari_dampen_magic : public SpellScriptLoader
{
    public:
        spell_illidari_dampen_magic() : SpellScriptLoader("spell_illidari_dampen_magic") { }

        class spell_illidari_dampen_magic_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_illidari_dampen_magic_AuraScript);

            void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
            {
                if (Creature* target = GetTarget()->ToCreature())
                {
                    AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
                    if (mode == AURA_REMOVE_BY_ENEMY_SPELL || mode == AURA_REMOVE_BY_EXPIRE)
                        target->AI()->DoAction(ACTION_REFRESH_DAMPEN);
                }
            }

            void Register() override
            {
                OnEffectRemove += AuraEffectRemoveFn(spell_illidari_dampen_magic_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_MOD_DAMAGE_PERCENT_TAKEN, AURA_EFFECT_HANDLE_REAL);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_illidari_dampen_magic_AuraScript();
        }
};

void AddSC_boss_illidari_council()
{
    new boss_illidari_council();
    new boss_gathios_the_shatterer();
    new boss_lady_malande();
    new boss_veras_darkshadow();
    new boss_high_nethermancer_zerevor();
    new npc_veras_vanish_effect();
    new spell_illidari_council_empyreal_balance();
    new spell_illidari_council_empyreal_equivalency();
    new spell_illidari_council_balance_of_power();
    new spell_illidari_council_deadly_strike();
    new spell_illidari_council_deadly_poison();
    new spell_illidari_council_reflective_shield();
    new spell_illidari_council_judgement();
    new spell_illidari_council_seal();
    new spell_illidari_dampen_magic();
}
