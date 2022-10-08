/*
 * Copyright (C) 2017-2019 AshamaneProject <https://github.com/AshamaneProject>
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
#include "ScriptedCreature.h"
#include "AreaTriggerTemplate.h"
#include "AreaTriggerAI.h"
#include "Spell.h"
#include "AreaTrigger.h"
#include "karazhan_legion.h"

enum Spells
{
    // Shade of Medivh
    SPELL_PIERCING_MISSILES                 = 227628,
    SPELL_INFERNO_BOLT                      = 227615,
    SPELL_FROSTBITE                         = 227592,
    SPELL_CEASELESS_WINTER                  = 227779,
    SPELL_CEASELESS_WINTER_DMG              = 227806,
    SPELL_FLAME_WREATH                      = 228269,
    SPELL_FLAME_WREATH_AREA                 = 228257,
    SPELL_FLAME_WREATH_DMG                  = 228262,
    SPELL_GUARDIAN_IMAGE                    = 228334,
    SPELL_GUARDIAN_IMAGE_TRIGGER            = 228338,
    SPELL_MANA_REGEN                        = 32102,

    // Guardian Image
    SPELL_ARCANE_BOLT                       = 228991,
    SPELL_SHIMMER                           = 228521
};

enum Events
{
    EVENT_PIERCING_MISSILES                 = 1,
    EVENT_INFERNO_BOLT                      = 2,
    EVENT_FROSTBITE                         = 3,
    EVENT_CEASELESS_WINTER                  = 4,
    EVENT_FLAME_WREATH                      = 5,
    EVENT_GUARDIAN_IMAGE                    = 6,
    EVENT_REGEN_ENERGY                      = 7,
    EVENT_RESTORE_STATE                     = 8,
    EVENT_INVISIBLE                         = 9,

    EVENT_ARCANE_BOLT                       = 8
};

enum Says
{
    SAY_INTRO                               = 0,
    SAY_AGGRO                               = 1,
    SAY_MISSILES                            = 2,
    SAY_INFERNO_BOLT                        = 3,
    SAY_FROSTBITE                           = 4,
    SAY_WINTER                              = 5,
    SAY_FLAME_WREATH                        = 6,
    SAY_GUARDIAN                            = 7,
    SAY_KILL                                = 8,
    SAY_WIPE                                = 9,
    SAY_DEATH                               = 10,
};

Position GuardianImagesPos [] =
{
    { -4599.056f, -2494.145f, 2876.509f, 4.702493f },
    { -4578.388f, -2517.197f, 2876.509f, 3.020952f },
    { -4619.883f, -2517.877f, 2876.509f, 0.008949f },
};

constexpr int32 ACTION_FULL_MANA            = 1;
constexpr uint32 NPC_GUARDIAN_IMAGE         = 114675;

class boss_new_shade_of_medivh : public CreatureScript
{
    public:
        explicit boss_new_shade_of_medivh() : CreatureScript("boss_new_shade_of_medivh") { }

        struct boss_new_shade_of_medivh_AI : public BossAI
        {
            explicit boss_new_shade_of_medivh_AI(Creature* creature) : BossAI(creature, DATA_SHADE_OF_MEDIVH) { }

            void ScheduleTasks()
            {
                uint8 order = urand(0, 2);

                if (order == 0)
                    events.RescheduleEvent(EVENT_INFERNO_BOLT, 8s);
                else if (order == 1)
                    events.RescheduleEvent(EVENT_FROSTBITE, 8s);
                else if (order == 2)
                    events.RescheduleEvent(EVENT_PIERCING_MISSILES, 8s);
            }

            void DoAction(int32 action) override
            {
                if (action == ACTION_FULL_MANA)
                {
                    uint8 order = urand(0, 2);
                    events.Reset();

                    if (order == 0)
                        events.RescheduleEvent(EVENT_FLAME_WREATH, 500ms);
                    else if (order == 1)
                        events.RescheduleEvent(EVENT_CEASELESS_WINTER, 500ms);
                    else if (order == 2)
                        events.RescheduleEvent(EVENT_GUARDIAN_IMAGE, 500ms);
                }
            }

            void EnterCombat(Unit* /**/) override
            {
                Talk(SAY_AGGRO);
                me->SetPower(POWER_MANA, 0);
                me->SetMaxPower(POWER_MANA, 100);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                _EnterCombat();
                events.ScheduleEvent(EVENT_REGEN_ENERGY, 1s);
                ScheduleTasks();
            }

            void JustDied(Unit* /**/) override
            {
                Talk(SAY_DEATH);
                me->SetVisible(true);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                _JustDied();
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim && victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void SummonedCreatureDies(Creature* summon, Unit* /**/) override
            {
                if (!summon)
                    return;

                if (summon->GetEntry() == NPC_GUARDIAN_IMAGE)
                {
                    _imagesDead++;

                    if (_imagesDead >= 3)
                    {
                        _imagesDead = 0;
                        events.ScheduleEvent(EVENT_RESTORE_STATE, 100ms);
                    }
                }
            }

            void EnterEvadeMode(EvadeReason why) override
            {
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetVisible(true);
                instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                me->RemoveAllAreaTriggers();
                BossAI::EnterEvadeMode(why);
            }

            void JustReachedHome() override
            {
                Talk(SAY_WIPE);
                _JustReachedHome();
            }

            void SpellHit(Unit* /**/, SpellInfo const* spell) override
            {
                if (!spell)
                    return;

                if (spell->HasEffect(SPELL_EFFECT_INTERRUPT_CAST))
                {
                    Spell* currentSpell = me->GetCurrentSpell(CURRENT_CHANNELED_SPELL);

                    if (currentSpell)
                    {
                        if (currentSpell->GetSpellInfo()->Id == SPELL_PIERCING_MISSILES)
                            me->CastStop();

                        ScheduleTasks();
                    }
                    else
                    {
                        currentSpell = me->GetCurrentSpell(CURRENT_GENERIC_SPELL);

                        if (currentSpell)
                        {
                            if (currentSpell->GetSpellInfo()->Id == SPELL_PIERCING_MISSILES)
                                me->CastStop();

                            ScheduleTasks();
                        }
                    }
                }
            }

            void ExecuteEvent(uint32 eventId) override
            {
                switch (eventId)
                {
                    case EVENT_PIERCING_MISSILES:
                    {
                        if (roll_chance_f(45))
                            Talk(SAY_MISSILES);
                        DoCastVictim(SPELL_PIERCING_MISSILES);
                        ScheduleTasks();
                        break;
                    }

                    case EVENT_INFERNO_BOLT:
                    {
                        if (roll_chance_f(45))
                            Talk(SAY_INFERNO_BOLT);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_INFERNO_BOLT);
                        ScheduleTasks();
                        break;
                    }

                    case EVENT_FROSTBITE:
                    {
                        if (roll_chance_i(33))
                            Talk(SAY_FROSTBITE);

                        if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                            DoCast(target, SPELL_FROSTBITE);
                        ScheduleTasks();
                        break;
                    }

                    case EVENT_CEASELESS_WINTER:
                    {
                        Talk(SAY_WINTER);
                        DoCast(me, SPELL_CEASELESS_WINTER);
                        break;
                    }

                    case EVENT_FLAME_WREATH:
                    {
                        Talk(SAY_FLAME_WREATH);
                        DoCast(me, SPELL_FLAME_WREATH);
                        break;
                    }

                    case EVENT_GUARDIAN_IMAGE:
                    {
                        Talk(SAY_GUARDIAN);
                        _imagesDead = 0;
                        me->SetReactState(REACT_PASSIVE);
                        events.Reset();
                        DoCast(me, SPELL_GUARDIAN_IMAGE);
                        events.ScheduleEvent(EVENT_INVISIBLE, 100ms);
                        break;
                    }

                    case EVENT_INVISIBLE:
                    {
                        me->SetVisible(false);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
                        break;
                    }

                    case EVENT_RESTORE_STATE:
                    {
                        me->SetVisible(true);
                        me->SetReactState(REACT_AGGRESSIVE);
                        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
                        ScheduleTasks();
                        events.ScheduleEvent(EVENT_REGEN_ENERGY, 1s);
                    }

                    case EVENT_REGEN_ENERGY:
                    {
                        int32 power = me->GetMaxPower(POWER_MANA) * 0.03f;
                        me->ModifyPower(POWER_MANA, power);

                        if (me->GetPower(POWER_MANA) == me->GetMaxPower(POWER_MANA))
                        {
                            me->SetReactState(REACT_PASSIVE);
                            me->SetPower(POWER_MANA, 0);
                            DoAction(ACTION_FULL_MANA);
                        }
                        events.ScheduleEvent(EVENT_REGEN_ENERGY, 1s);
                        break;
                    }
                }
            }

            private:
                uint8 _imagesDead;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new boss_new_shade_of_medivh_AI(creature);
        }
};

class npc_kara_guardian_image : public CreatureScript
{
    public:
        npc_kara_guardian_image() : CreatureScript("npc_kara_guardian_image") { }

        struct npc_kara_guardian_image_AI : public ScriptedAI
        {
            explicit npc_kara_guardian_image_AI(Creature* creature) : ScriptedAI(creature)
            {
                me->CastSpell(me, SPELL_SHIMMER, true);
                me->AddUnitState(UNIT_STATE_ROOT);
            }

            void Reset()
            {
                _events.Reset();
            }

            void IsSummonedBy(Unit* /**/) override
            {
                _events.ScheduleEvent(EVENT_ARCANE_BOLT, 2s);
                InstanceScript* instance = me->GetInstanceScript();

                if (instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            }

            void JustDied(Unit* /**/) override
            {
                InstanceScript* instance = me->GetInstanceScript();

                if (instance)
                    instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (me->HasUnitState(UNIT_STATE_CASTING))
                    return;

                if (_events.ExecuteEvent() == EVENT_ARCANE_BOLT)
                {
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 0, true))
                        DoCast(target, SPELL_ARCANE_BOLT);

                    _events.ScheduleEvent(EVENT_ARCANE_BOLT, 2s);
                }
            }

            private:
                EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return new npc_kara_guardian_image_AI(creature);
        }
};

class spell_shade_medivh_flame_wreath : public SpellScriptLoader
{
    public:
        spell_shade_medivh_flame_wreath() : SpellScriptLoader("spell_shade_medivh_flame_wreath") { }

        class spell_flame_wreath_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_flame_wreath_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    GetCaster()->CastSpell(GetHitUnit(), SPELL_FLAME_WREATH_AREA, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_flame_wreath_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_flame_wreath_SpellScript();
        }
};

class spell_shade_medivh_guardian_image : public SpellScriptLoader
{
    public:
        spell_shade_medivh_guardian_image() : SpellScriptLoader("spell_shade_medivh_guardian_image") { }

        class spell_guardian_image_SpellScript : public SpellScript
        {
            public:
                PrepareSpellScript(spell_guardian_image_SpellScript);

                void HandleDummy(SpellEffIndex /**/)
                {
                    if (!GetHitUnit())
                        return;

                    for (uint8 i = 0; i < 3; ++i)
                        GetCaster()->CastSpell(GuardianImagesPos[i].GetPositionX(),
                        GuardianImagesPos[i].GetPositionY(), GuardianImagesPos[i].GetPositionZ(),
                        SPELL_GUARDIAN_IMAGE_TRIGGER, true);
                }

                void Register() override
                {
                    OnEffectHitTarget += SpellEffectFn(spell_guardian_image_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
                }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_guardian_image_SpellScript();
        }
};

class spell_shade_medivh_ceaseless_winter : public SpellScriptLoader
{
    public:
        spell_shade_medivh_ceaseless_winter() : SpellScriptLoader("spell_shade_medivh_ceaseless_winter") { }

        class spell_ceaserless_winter_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_ceaserless_winter_AuraScript);

            void OnApply(AuraEffect const* /**/, AuraEffectHandleModes /**/)
            {
                if (!GetUnitOwner())
                    return;

                _OwnerPos = GetUnitOwner()->GetPosition();
            }

            void OnPeriodic(AuraEffect const* /**/)
            {
                if (!GetUnitOwner())
                    return;

                _OwnerPos.SetOrientation(GetUnitOwner()->GetOrientation());

                if (_OwnerPos != GetUnitOwner()->GetPosition())
                {
                    _OwnerPos = GetUnitOwner()->GetPosition();
                    ModStackAmount(-1);
                }
                else
                    ModStackAmount(1);
            }

            void Register() override
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_ceaserless_winter_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
                OnEffectApply += AuraEffectApplyFn(spell_ceaserless_winter_AuraScript::OnApply, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
            }

            Position _OwnerPos;
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_ceaserless_winter_AuraScript();
        }
};

class at_kara_ceaseless_winter : public AreaTriggerEntityScript
{
    public:
        at_kara_ceaseless_winter() : AreaTriggerEntityScript("at_kara_ceaseless_winter") { }

        struct at_kara_ceaseless_winter_AI : public AreaTriggerAI
        {
            explicit at_kara_ceaseless_winter_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _timerCheck = 0;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->CastSpell(target, SPELL_CEASELESS_WINTER_DMG, true);
            }

            void OnUnitExit(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                    target->RemoveAurasDueToSpell(SPELL_CEASELESS_WINTER_DMG);
            }

            void OnUpdate(uint32 diff) override
            {
                _timerCheck += diff;

                if (_timerCheck >= IN_MILLISECONDS + 500)
                {
                    _timerCheck = 0;

                    for (auto & it : at->GetInsideUnits())
                    {
                        Player* ptr = ObjectAccessor::GetPlayer(*at, it);

                        if (!ptr)
                            continue;

                        if (!ptr->HasAura(SPELL_CEASELESS_WINTER_DMG))
                            ptr->CastSpell(ptr, SPELL_CEASELESS_WINTER_DMG, true);
                    }
                }
            }

            private:
                uint32 _timerCheck;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_ceaseless_winter_AI(at);
        }
};

class at_kara_flame_wreath : public AreaTriggerEntityScript
{
    public:
        at_kara_flame_wreath() : AreaTriggerEntityScript("at_kara_flame_wreath") { }

        struct at_kara_flame_wreath_AI : public AreaTriggerAI
        {
            explicit at_kara_flame_wreath_AI(AreaTrigger* at) : AreaTriggerAI(at)
            {
                _targetGuid = ObjectGuid::Empty;
            }

            void OnUnitEnter(Unit* target) override
            {
                if (target && target->GetTypeId() == TYPEID_PLAYER)
                {
                    if (_targetGuid == ObjectGuid::Empty)
                        _targetGuid = target->GetGUID();
                    else if (target->GetGUID() != _targetGuid)
                    {
                        Unit* targetOne = ObjectAccessor::GetUnit(*at, _targetGuid);

                        if (targetOne)
                        {
                            targetOne->CastSpell(targetOne, SPELL_FLAME_WREATH_DMG, true);
                            at->Remove();
                        }
                    }
                }
            }

            void OnUnitExit(Unit* target) override
            {
                if (!target)
                    return;

                if (_targetGuid == ObjectGuid::Empty)
                    return;

                if (_targetGuid == target->GetGUID())
                {
                    Unit* targetOne = ObjectAccessor::GetUnit(*at, _targetGuid);

                    if (targetOne)
                    {
                        at->GetCaster()->CastSpell(targetOne, SPELL_FLAME_WREATH_DMG, true);
                        at->Remove();
                    }
                }
            }

            private:
                ObjectGuid _targetGuid;
        };

        AreaTriggerAI* GetAI(AreaTrigger* at) const override
        {
            return new at_kara_flame_wreath_AI(at);
        }
};

void AddSC_boss_shade_of_medivh_karazhan_legion()
{
    new boss_new_shade_of_medivh();
    new npc_kara_guardian_image();
    new spell_shade_medivh_flame_wreath();
    new spell_shade_medivh_guardian_image();
    new spell_shade_medivh_ceaseless_winter();
    new at_kara_flame_wreath();
    new at_kara_ceaseless_winter();
}
