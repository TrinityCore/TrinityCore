/*
 * Copyright 2023 AzgathCore
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

#include "GameTables.h"
#include "halls_of_valor.h"
#include "ScenarioMgr.h"
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "SpellAuraDefines.h"
#include "SpellAuraEffects.h"
#include <Challenge.h>

enum Says
{
    SAY_AGGRO = 0,
    SAY_EXPEL_LIGHT = 1,
    SAY_DEATH = 2,
};

enum Spells
{
    SPELL_ASCENDANCE = 191475,
    SPELL_ASCENDANCE_JUMP = 191478,
    SPELL_EMPOWERMENT_TRACKER = 192130,
    SPELL_EXPEL_LIGHT = 192044, //192095 - 29:16?
    SPELL_EXPEL_LIGHT_DMG = 192067,
    SPELL_EXPEL_LIGHT_CONFUSE = 192070, //not used?
    SPELL_EXPEL_LIGHT_DUMMY = 192095,
    SPELL_SHIELD_OF_LIGHT = 192018,
    SPELL_MYSTIC_MOD_DMG_THUNDER = 192132,
    SPELL_MYSTIC_MOD_DMG_HOLY = 192133,

    //Special Ability
    SPELL_EYE_OF_THE_STORM = 192304, //????? ?????????? ????????
    SPELL_EYE_OF_THE_STORM_DMG = 200901,
    SPELL_EYE_OF_THE_STORM_AT = 203955,
    SPELL_ARCING_BOLT_FILTER = 191978,
    SPELL_SANCTIFY_TICK = 192158,
    SPELL_SANCTIFY_AT = 192163,

    //Defender
    SPELL_OLMYR_VISUAL = 191899,
    SPELL_SOLSTEN_VISUAL = 192147,
    SPELL_OLMYR_LIGHT = 192288,

    SPELL_CONVERSATION = 198226,
};

enum eEvents
{
    EVENT_EXPEL_LIGHT = 1,
    EVENT_SHIELD_OF_LIGHT = 2,
    EVENT_SPECIAL_ABILITY = 3,
    EVENT_ARCING_BOLT = 4,

    EVENT_2,
    EVENT_1,
};

//95833
class boss_hyrja : public CreatureScript
{
public:
    boss_hyrja() : CreatureScript("boss_hyrja") {}

    struct boss_hyrjaAI : public BossAI
    {
        boss_hyrjaAI(Creature* creature) : BossAI(creature, DATA_HYRJA), summons(me)
        {
            me->SetReactState(REACT_PASSIVE);
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
        }

        SummonList summons;
        ObjectGuid defGUID[2];
        bool eventComplete = false;
        bool _introDone = false;
        uint8 defenderComplete = 0;
        uint8 lightStack = 0;

        void Reset() override
        {
            summons.DespawnAll();
            _Reset();
            SummonDefenders();
            lightStack = 0;
            me->RemoveAurasDueToSpell(SPELL_EMPOWERMENT_TRACKER);
            if (eventComplete)
            {
                DoCast(me, SPELL_ASCENDANCE, true);
                me->SetReactState(REACT_AGGRESSIVE);
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(SAY_AGGRO);
            _JustEngagedWith();
            DoCast(me, SPELL_EMPOWERMENT_TRACKER, true);

            if (auto olmyr = me->GetCreature(*me, defGUID[0]))
                olmyr->CastSpell(olmyr, 192152, true);

            if (auto solsten = me->GetCreature(*me, defGUID[1]))
                solsten->CastSpell(solsten, 192150, true);

            events.RescheduleEvent(EVENT_EXPEL_LIGHT, 3000);
            events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 10000);
            events.RescheduleEvent(EVENT_SPECIAL_ABILITY, 20000);
            events.RescheduleEvent(EVENT_ARCING_BOLT, 12000);
        }

        void JustDied(Unit* /*killer*/) override
        {
            Talk(SAY_DEATH);
            _JustDied();
            summons.DespawnAll();
        }

        void SummonDefenders()
        {
            me->SummonCreature(NPC_OLMYR_THE_ENLIGHTENED, 3141.80f, 362.52f, 655.27f, 4.66f);
            me->SummonCreature(NPC_SOLSTEN, 3187.97f, 316.82f, 655.27f, 3.16f);
        }

        void JustSummoned(Creature* sum) override
        {
            summons.Summon(sum);

            if (sum->GetEntry() == NPC_OLMYR_THE_ENLIGHTENED)
            {
                defGUID[0].Clear();
                defGUID[0] = sum->GetGUID();
            }

            if (sum->GetEntry() == NPC_SOLSTEN)
            {
                defGUID[1].Clear();
                defGUID[1] = sum->GetGUID();
            }
        }

        void MoveInLineOfSight(Unit* who) override
        {
            if (who->GetTypeId() != TYPEID_PLAYER)
                return;

            if (!_introDone && me->IsWithinDistInMap(who, 45.0f))
            {
                _introDone = true;
                DoCast(SPELL_CONVERSATION);
            }
        }

        void DoAction(int32 const action) override
        {
            if (eventComplete)
                return;

            defenderComplete++;

            if (defenderComplete == 2)
                DoCast(SPELL_ASCENDANCE);
        }

        void SpellHit(Unit* caster, const SpellInfo* spell) override
        {
            if (spell->Id == SPELL_ASCENDANCE && !eventComplete)
                DoCast(me, SPELL_ASCENDANCE_JUMP, true);
        }

        void MovementInform(uint32 type, uint32 id) override
        {
            if (type != EFFECT_MOTION_TYPE)
                return;

            if (id == SPELL_ASCENDANCE_JUMP)
            {
                eventComplete = true;
                me->SetHomePosition(me->GetPositionX(), me->GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                me->SetReactState(REACT_AGGRESSIVE);
                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
                me->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
            }
        }

        uint32 GetData(uint32 type) const override
        {
            switch (type)
            {
            case DATA_HYRJA_EVENT_COMPLETE:
                return eventComplete;
            case DATA_HYRJA_LIGHT_STACK:
                return lightStack;
            }
            return 0;
        }

        void SetData(uint32 type, uint32 value) override
        {
            switch (type)
            {
            case DATA_HYRJA_LIGHT_STACK:
                lightStack = value;
                break;
            default:
                break;
            }
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() || !CheckInRoom())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_EXPEL_LIGHT:
                    lightStack = 3;
                    DoCast(SPELL_EXPEL_LIGHT);
                    Talk(SAY_EXPEL_LIGHT);
                    events.RescheduleEvent(EVENT_EXPEL_LIGHT, 30000);
                    break;
                case EVENT_SHIELD_OF_LIGHT:
                    me->CastSpell(me->GetVictim(), SPELL_SHIELD_OF_LIGHT);
                    events.RescheduleEvent(EVENT_SHIELD_OF_LIGHT, 20000);
                    break;
                case EVENT_SPECIAL_ABILITY:
                {
                    auto olmyr = me->GetCreature(*me, defGUID[0]);
                    auto solsten = me->GetCreature(*me, defGUID[1]);
                    if (!olmyr || !solsten)
                        return;

                    me->AttackStop();

                    if (me->GetDistance(solsten) < me->GetDistance(olmyr))
                    {
                        me->CastSpell(me, SPELL_EYE_OF_THE_STORM, true);
                        me->CastSpell(me, SPELL_EYE_OF_THE_STORM_AT, true);
                        me->SetReactState(REACT_AGGRESSIVE);
                    }
                    else
                    {
                        DoCast(SPELL_SANCTIFY_TICK);
                        me->SetReactState(REACT_AGGRESSIVE);
                    }
                    events.RescheduleEvent(EVENT_SPECIAL_ABILITY, 30000);
                    break;
                }
                case EVENT_ARCING_BOLT:
                    DoCast(SPELL_ARCING_BOLT_FILTER);
                    events.RescheduleEvent(EVENT_ARCING_BOLT, 12000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new boss_hyrjaAI(creature);
    }
};

//97202, 97219
class npc_hyrja_defenders : public CreatureScript
{
public:
    npc_hyrja_defenders() : CreatureScript("npc_hyrja_defenders") {}

    struct npc_hyrja_defendersAI : public ScriptedAI
    {
        npc_hyrja_defendersAI(Creature* creature) : ScriptedAI(creature)
        {
            ascendance = false;
        }

        EventMap events;
        bool ascendance;

        void Reset() override
        {
            events.Reset();

            if (Unit* summoner = me->GetOwner())
                if (summoner->GetAI()->GetData(DATA_HYRJA_EVENT_COMPLETE) == 1)
                    SpiritForm();
        }

        void DamageTaken(Unit* /*attacker*/, uint32& damage)
        {
            if (damage >= me->GetHealth())
            {
                if (!ascendance)
                {
                    ascendance = true;
                    if (Unit* summoner = me->GetOwner())
                        summoner->ToCreature()->AI()->DoAction(true);

                    EnterEvadeMode();
                    SpiritForm();
                }
                damage = 0;
            }
        }

        void JustEngagedWith(Unit* /*who*/) override
        {
            Talk(0);
            events.RescheduleEvent(EVENT_2, 30000);
            events.RescheduleEvent(EVENT_1, 5000);
        }

        void SpiritForm()
        {
            Talk(1);
            me->AttackStop();
            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);

            if (me->GetEntry() == NPC_OLMYR_THE_ENLIGHTENED)
                DoCast(me, SPELL_OLMYR_VISUAL, true);
            else
                DoCast(me, SPELL_SOLSTEN_VISUAL, true);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetDistance(me->GetHomePosition()) >= 30.0f)
            {
                EnterEvadeMode();
                return;
            }

            if (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_1:
                    if (me->GetEntry() == NPC_OLMYR_THE_ENLIGHTENED)
                        DoCast(SPELL_OLMYR_LIGHT);
                    else
                    {
                        DoCast(me, SPELL_MYSTIC_MOD_DMG_THUNDER, true);
                      //  DoCastVictim(SPELL_SOLSTEN_ARCING);
                    }
                    events.RescheduleEvent(EVENT_1, 7000);
                    break;
                case EVENT_2:
                    if (me->GetEntry() == NPC_OLMYR_THE_ENLIGHTENED)
                        DoCast(me, SPELL_SANCTIFY_TICK);
                    else
                    {
                        DoCast(me, SPELL_EYE_OF_THE_STORM, true);
                        DoCast(me, SPELL_EYE_OF_THE_STORM_AT, true);
                        DoCast(SPELL_EYE_OF_THE_STORM_DMG);
                    }
                    events.RescheduleEvent(EVENT_2, 30000);
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_hyrja_defendersAI(creature);
    }
};

//192130
class spell_hyrja_empowerment_tracker : public SpellScriptLoader
{
public:
    spell_hyrja_empowerment_tracker() : SpellScriptLoader("spell_hyrja_empowerment_tracker") {}

    class spell_hyrja_empowerment_tracker_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hyrja_empowerment_tracker_AuraScript);

            uint8 stack = 0;

        void OnPereodic(AuraEffect const* aurEff)
        {
            if (!GetTarget())
                return;

            //Thunder
            if (GetTarget()->HasAura(192008))
            {
                if (!GetTarget()->HasAura(191924))
                {
                    if (Aura* aura = GetTarget()->GetAura(SPELL_MYSTIC_MOD_DMG_HOLY))
                    {
                        stack = aura->GetStackAmount();

                        if (stack > 2 && GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                            aura->SetStackAmount(stack - 2);
                        else
                            aura->Remove();
                    }
                }
                GetTarget()->CastSpell(GetTarget(), SPELL_MYSTIC_MOD_DMG_THUNDER, true);
            }

            //Holy
            if (GetTarget()->HasAura(191924))
            {
                if (!GetTarget()->HasAura(192008))
                {
                    if (Aura* aura = GetTarget()->GetAura(SPELL_MYSTIC_MOD_DMG_THUNDER))
                    {
                        stack = aura->GetStackAmount();

                        if (stack > 2 && GetTarget()->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                            aura->SetStackAmount(stack - 2);
                        else
                            aura->Remove();
                    }
                }
                GetTarget()->CastSpell(GetTarget(), SPELL_MYSTIC_MOD_DMG_HOLY, true);
            }
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hyrja_empowerment_tracker_AuraScript::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hyrja_empowerment_tracker_AuraScript();
    }
};

//192048
class spell_hyrja_expel_light : public SpellScriptLoader
{
public:
    spell_hyrja_expel_light() : SpellScriptLoader("spell_hyrja_expel_light") {}

    class spell_hyrja_expel_light_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hyrja_expel_light_AuraScript);

        void OnApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
        {
            if (!GetTarget())
                return;

            if (InstanceScript* instance = GetTarget()->GetInstanceScript())
            {
                Creature* hyrja = instance->instance->GetCreature(instance->GetGuidData(DATA_HYRJA));
                if (!hyrja)
                    return;

                if (hyrja->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                {
                    if (hyrja->GetAI())
                    {
                        uint8 stack = hyrja->GetAI()->GetData(DATA_HYRJA_LIGHT_STACK);
                        if (stack > 1)
                            SetStackAmount(stack);

                        GetTarget()->CastSpell(GetTarget(), SPELL_EXPEL_LIGHT_DUMMY, true);
                    }
                }
            }
        }

        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
        {
            Unit* target = GetTarget();
            if (!target)
                return;

            if (InstanceScript* instance = target->GetInstanceScript())
            {
                Creature* hyrja = instance->instance->GetCreature(instance->GetGuidData(DATA_HYRJA));
                if (!hyrja)
                    return;

                if (hyrja->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
                {
                    if (hyrja->GetAI())
                    {
                        uint8 stack = hyrja->GetAI()->GetData(DATA_HYRJA_LIGHT_STACK);
                        if (stack > 1)
                        {
                            hyrja->GetAI()->SetData(DATA_HYRJA_LIGHT_STACK, stack - 1);
                            if (Unit* randTarget = hyrja->AI()->SelectTarget(SELECT_TARGET_RANDOM, 1, 100.0f, true, -SPELL_EXPEL_LIGHT_DUMMY))
                                target->CastSpell(randTarget, GetId(), true, 0, 0, hyrja->GetGUID());
                            else if (Unit* randTarget = hyrja->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 80.0f, true))
                                target->CastSpell(randTarget, GetId(), true, 0, 0, hyrja->GetGUID());
                        }
                    }
                }
                hyrja->CastSpell(target, SPELL_EXPEL_LIGHT_DMG, true);
            }
        }

        void Register() override
        {
            OnEffectApply += AuraEffectApplyFn(spell_hyrja_expel_light_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
            OnEffectRemove += AuraEffectRemoveFn(spell_hyrja_expel_light_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hyrja_expel_light_AuraScript();
    }
};

//192158
class spell_hyrja_sanctify : public SpellScriptLoader
{
public:
    spell_hyrja_sanctify() : SpellScriptLoader("spell_hyrja_sanctify") {}

    class spell_hyrja_sanctify_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hyrja_sanctify_AuraScript);

            void OnPereodic(AuraEffect const* aurEff)
        {
            Unit* caster = GetCaster();
            if (!caster)
                return;

            for (uint8 i = 0; i < 6; i++)
                caster->CastSpell(caster, SPELL_SANCTIFY_AT, true);
        }

        void Register() override
        {
            OnEffectPeriodic += AuraEffectPeriodicFn(spell_hyrja_sanctify_AuraScript::OnPereodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hyrja_sanctify_AuraScript();
    }
};

//203963
class spell_hyrja_eye_storm_absorb : public SpellScriptLoader
{
public:
    spell_hyrja_eye_storm_absorb() : SpellScriptLoader("spell_hyrja_eye_storm_absorb") {}

    class spell_hyrja_eye_storm_absorb_AuraScript : public AuraScript
    {
        PrepareAuraScript(spell_hyrja_eye_storm_absorb_AuraScript);

        uint32 absorbSave;

        bool Load() override
        {
            absorbSave = 0;
            return true;
        }

        void CalculateAmount(AuraEffect const* auraEffect, int32& amount, bool&)
        {
            amount = -1;

          //  absorbSave = GetSpellInfo()->GetEffect(EFFECT_0, GetCaster()->GetMap()->GetDifficultyID())->CalcValue(GetCaster());

            // Calculation from Mythic+
            if (auto instance = GetCaster()->GetInstanceScript())
            {
                if (auto hyrja = instance->instance->GetCreature(instance->GetGuidData(DATA_HYRJA)))
                    if (auto effect = hyrja->GetAuraEffect(ChallengersMight, EFFECT_1))
                        AddPct(absorbSave, effect->GetAmount());
            }
        }

        void Absorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
        {
            absorbAmount = absorbSave;
        }

        void Register() override
        {
            DoEffectCalcAmount += AuraEffectCalcAmountFn(spell_hyrja_eye_storm_absorb_AuraScript::CalculateAmount, EFFECT_0, SPELL_AURA_SCHOOL_ABSORB);
            OnEffectAbsorb += AuraEffectAbsorbFn(spell_hyrja_eye_storm_absorb_AuraScript::Absorb, EFFECT_0);
        }
    };

    AuraScript* GetAuraScript() const override
    {
        return new spell_hyrja_eye_storm_absorb_AuraScript();
    }
};

//4885
class at_sanctify : public AreaTriggerScript
{
public:
    at_sanctify() : AreaTriggerScript("at_sanctify") {}

    bool OnTrigger(Player* player, const AreaTriggerEntry* /*at*/, bool /*enter*/) override
    {
        player->CastSpell(player, 192206, true);
        return true;
    }
};

void AddSC_boss_hyrja()
{
    new boss_hyrja();
    new npc_hyrja_defenders();
    new spell_hyrja_empowerment_tracker();
    new spell_hyrja_expel_light();
    new spell_hyrja_sanctify();
    new spell_hyrja_eye_storm_absorb();
    new at_sanctify();
}
