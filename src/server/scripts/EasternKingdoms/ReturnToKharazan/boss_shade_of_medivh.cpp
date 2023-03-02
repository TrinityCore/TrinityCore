///*
// * Copyright 2023 AzgathCore
// *
// * This program is free software; you can redistribute it and/or modify it
// * under the terms of the GNU General Public License as published by the
// * Free Software Foundation; either version 2 of the License, or (at your
// * option) any later version.
// *
// * This program is distributed in the hope that it will be useful, but WITHOUT
// * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
// * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
// * more details.
// *
// * You should have received a copy of the GNU General Public License along
// * with this program. If not, see <http://www.gnu.org/licenses/>.
// */
//
//#include "new_karazhan.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_SPECIAL_ARCANE = 1,
//    SAY_SPECIAL_FROST = 2,
//    SAY_SPECIAL_FIRE = 3,
//    SAY_DEATH = 4,
//};
//
//enum Spells
//{
//    SPELL_ARCANE_CHANNEL_VIS = 189573,
//    SPELL_MANA_REGEN = 228582,
//    SPELL_VO_CONTROLLER = 232314, //unk
//    SPELL_FROSTBITE = 227592,
//    SPELL_INFERNO_BOLT = 227615,
//    SPELL_INFERNO_BOLT_VIS = 228249,
//    SPELL_PIERCING_MISSILES = 227628,
//    SPELL_PIERCING_MISSILES_DMG = 227641,
//    SPELL_PIERCING_MISSILES_VIS = 227644,
//
//    //Special Arcane Ability
//    SPELL_GUARDIAN_IMAGE = 228334,
//    SPELL_GUARDIAN_IMAGE_SUM = 228338,
//    SPELL_DISSOLVE = 228572, //Invisible
//    SPELL_REFORM_VISUAL_STATE_1 = 228568,
//    SPELL_REFORM_VISUAL_STATE_2 = 228569,
//
//    //Special Fire Ability
//    SPELL_FLAME_WREATH_FILTER = 228269,
//    SPELL_FLAME_WREATH_AT = 228257,
//
//    //Special Frost Ability
//    SPELL_CEASELESS_WINTER_AT = 227779,
//
//    //Summons
//    SPELL_ARCANE_DISSOLVE = 228343,
//    SPELL_SHIMMER = 228521,
//    SPELL_ARCANE_BOLT = 228991,
//    SPELL_REFORM_VISUAL = 228558,
//
//    //Other
//    SPELL_DIMENSION_FALL = 231851, //unk
//    SPELL_DIMENSION_FALL_MID_FALL = 232630, //unk
//    SPELL_SAFE_FALL = 231462,
//};
//
//enum eEvents
//{
//    EVENT_ALTERNATING_ABILITY = 1,
//    EVENT_SPECIAL_FROST = 2,
//    EVENT_SPECIAL_FIRE = 3,
//    EVENT_SPECIAL_ARCANE = 4,
//    
//    EVENT_1,
//    EVENT_2,
//};
//
//enum Actions
//{
//    ACTION_1 = 1,
//};
//
////114350
//class boss_shade_of_medivh : public CreatureScript
//{
//public:
//    boss_shade_of_medivh() : CreatureScript("boss_shade_of_medivh") {}
//
//    struct boss_shade_of_medivhAI : public BossAI
//    {
//        boss_shade_of_medivhAI(Creature* creature) : BossAI(creature, DATA_SHADE_OF_MEDIVH)
//        {
//            SetCombatMovement(false);
//            DoCast(SPELL_ARCANE_CHANNEL_VIS);
//        }
//
//        bool specialAbility;
//        uint8 summonsDiedCount;
//        uint8 interruptRand;
//        std::list<ObjectGuid> listGuid;
//
//        void Reset() override
//        {
//            _Reset();
//            me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_1);
//            me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_2);
//            me->RemoveAurasDueToSpell(SPELL_DISSOLVE);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//            me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//            me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//            me->SetPower(POWER_MANA, 0);
//            me->SetReactState(REACT_AGGRESSIVE);
//            specialAbility = false;
//            interruptRand = 0;
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//            me->InterruptNonMeleeSpells(false);
//            DoCast(me, SPELL_MANA_REGEN, true);
//
//            events.RescheduleEvent(EVENT_ALTERNATING_ABILITY, 500);
//        }
//
//        void JustReachedHome() override
//        {
//            DoCast(SPELL_ARCANE_CHANNEL_VIS);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_GUARDIAN_IMAGE)
//            {
//                summonsDiedCount = 0;
//                DoCast(me, SPELL_DISSOLVE, true);
//                me->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//                me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_NPC);
//                me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//
//                for (uint8 i = 0; i < 3; i++)
//                    me->CastSpell(medivhSEventPos[i], SPELL_GUARDIAN_IMAGE_SUM, true);
//            }
//
//            if (spell->Id == SPELL_REFORM_VISUAL)
//            {
//                if (!summonsDiedCount)
//                    DoCast(me, SPELL_REFORM_VISUAL_STATE_1, true);
//                else if (summonsDiedCount == 1)
//                    DoCast(me, SPELL_REFORM_VISUAL_STATE_2, true);
//                else
//                {
//                    me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_1);
//                    me->RemoveAurasDueToSpell(SPELL_REFORM_VISUAL_STATE_2);
//                    me->RemoveAurasDueToSpell(SPELL_DISSOLVE);
//                    me->SetPower(POWER_MANA, 0);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_NPC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    DoCast(me, SPELL_MANA_REGEN, true);
//                    specialAbility = false;
//                    events.RescheduleEvent(EVENT_ALTERNATING_ABILITY, 500);
//                }
//                summonsDiedCount++;
//            }
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_FLAME_WREATH_FILTER)
//            {
//                listGuid.push_back(target->GetGUID());
//            }
//        }
//
//        void OnSpellFinished(SpellInfo const* spell) override
//        {
//            if (spell->Id == SPELL_CEASELESS_WINTER_AT || spell->Id == SPELL_FLAME_WREATH_FILTER)
//            {
//                me->SetPower(POWER_MANA, 0);
//                specialAbility = false;
//            }
//        }
//
//
//        bool GetObjectData(ObjectGuid const& guid)
//        {
//            bool find = false;
//
//            for (auto targetGuid : listGuid)
//                if (targetGuid == guid)
//                    find = true;
//
//            if (!find)
//                listGuid.push_back(guid);
//
//            return find;
//        }
//
//        void SetData(uint32 type, uint32 value) override
//        {
//            if (type == 1 && value == 1)
//            {
//                ZoneTalk(5, nullptr);
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_1 && !specialAbility)
//            {
//                specialAbility = true;
//
//                switch (urand(0, 2))
//                {
//                case 0: //Special Frost
//                    events.RescheduleEvent(EVENT_SPECIAL_FROST, 500);
//                    break;
//                case 1: //Special Fire
//                    events.RescheduleEvent(EVENT_SPECIAL_FIRE, 500);
//                    break;
//                case 2: //Special Arcane
//                    events.RescheduleEvent(EVENT_SPECIAL_ARCANE, 500);
//                    break;
//                }
//            }
//        }
//
//        void OnInterruptCast(Unit* /*caster*/, uint32 /*spellId*/, uint32 curSpellID, uint32 /*schoolMask*/)
//        {
//            switch (curSpellID)
//            {
//            case SPELL_FROSTBITE:
//                interruptRand = RAND(2, 3);
//                break;
//            case SPELL_INFERNO_BOLT:
//                interruptRand = RAND(1, 3);
//                break;
//            case SPELL_PIERCING_MISSILES:
//                interruptRand = RAND(1, 2);
//                break;
//            }
//        }
//
//        void CastDefAbility()
//        {
//            Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 1, 60.0f, true);
//            if (!target)
//                target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true);
//            if (!target)
//                return;
//
//            switch (!interruptRand ? urand(1, 3) : interruptRand)
//            {
//            case 1: //Frost
//                DoCast(target, SPELL_FROSTBITE);
//                break;
//            case 2: //Fire
//                DoCast(target, SPELL_INFERNO_BOLT_VIS, true);
//                DoCast(target, SPELL_INFERNO_BOLT);
//                break;
//            case 3: //Arcane
//                me->CastSpell(me->GetVictim(), SPELL_PIERCING_MISSILES);
//                break;
//            }
//            interruptRand = 0;
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_ALTERNATING_ABILITY:
//                    CastDefAbility();
//                    events.RescheduleEvent(EVENT_ALTERNATING_ABILITY, 4000);
//                    break;
//                case EVENT_SPECIAL_FROST:
//                    Talk(SAY_SPECIAL_FROST);
//                    DoCast(SPELL_CEASELESS_WINTER_AT);
//                    break;
//                case EVENT_SPECIAL_FIRE:
//                    Talk(SAY_SPECIAL_FIRE);
//                    listGuid.clear();
//                    DoCast(SPELL_FLAME_WREATH_FILTER);
//                    break;
//                case EVENT_SPECIAL_ARCANE:
//                    Talk(SAY_SPECIAL_ARCANE);
//                    events.CancelEvent(EVENT_ALTERNATING_ABILITY);
//                    me->AttackStop();
//                    me->RemoveAurasDueToSpell(SPELL_MANA_REGEN);
//                    DoCast(SPELL_GUARDIAN_IMAGE);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_shade_of_medivhAI(creature);
//    }
//};
//
////114675
//class npc_medivh_guardian_image : public CreatureScript
//{
//public:
//    npc_medivh_guardian_image() : CreatureScript("npc_medivh_guardian_image") {}
//
//    struct npc_medivh_guardian_imageAI : public Scripted_NoMovementAI
//    {
//        npc_medivh_guardian_imageAI(Creature* creature) : Scripted_NoMovementAI(creature) {}
//
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            DoCast(me, SPELL_ARCANE_DISSOLVE, true);
//
//            events.RescheduleEvent(EVENT_1, 2000);
//            events.RescheduleEvent(EVENT_2, 2000);
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            DoCast(me, SPELL_REFORM_VISUAL, true);
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_1:
//                    DoCast(me, SPELL_SHIMMER, true);
//                    break;
//                case EVENT_2:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                    {
//                      //  DoResetThreat();
////me->AddThreat(target, 100000.0f);
//                        DoCast(target, SPELL_ARCANE_BOLT);
//                    }
//                    events.RescheduleEvent(EVENT_2, 2000);
//                    break;
//                }
//            }
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_medivh_guardian_imageAI(creature);
//    }
//};
//
//
////228582
//class spell_medivh_mana_regen : public SpellScriptLoader
//{
//public:
//    spell_medivh_mana_regen() : SpellScriptLoader("spell_medivh_mana_regen") { }
//
//    class spell_medivh_mana_regen_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_medivh_mana_regen_AuraScript);
//
//        uint8 counter = 0;
//        uint8 manaPct = 0;
//
//        void OnTick(AuraEffect const* aurEff)
//        {
//            Creature* caster = GetCaster()->ToCreature();
//            if (!caster || !caster->IsInCombat())
//                return;
//
//            if (uint32(caster->GetPowerPct(POWER_MANA)) < 100)
//            {
//                if (!counter)
//                    manaPct += 4;
//                else
//                    manaPct += 3;
//
//                counter >= 2 ? counter = 0 : counter++;
//                caster->SetPower(POWER_MANA, caster->CountPctFromMaxPower(POWER_MANA, manaPct));
//            }
//            else
//            {
//                manaPct = 0;
//                caster->AI()->DoAction(ACTION_1);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_medivh_mana_regen_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_medivh_mana_regen_AuraScript();
//    }
//};
//
////228232
//class spell_medivh_ceaseless_winter : public SpellScriptLoader
//{
//public:
//    spell_medivh_ceaseless_winter() : SpellScriptLoader("spell_medivh_ceaseless_winter") { }
//
//    class spell_medivh_ceaseless_winter_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_medivh_ceaseless_winter_AuraScript);
//
//        void OnTick(AuraEffect const* aurEff)
//        {
//            if (GetTarget() && GetTarget()->isMoving())
//            {
//                if (Aura* aura = GetTarget()->GetAura(227806))
//                    aura->ModStackAmount(-1);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_medivh_ceaseless_winter_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_medivh_ceaseless_winter_AuraScript();
//    }
//};
//
//void AddSC_boss_shade_of_medivh()
//{
//    new boss_shade_of_medivh();
//    new npc_medivh_guardian_image();
//    new spell_medivh_mana_regen();
//    new spell_medivh_ceaseless_winter();
//}
