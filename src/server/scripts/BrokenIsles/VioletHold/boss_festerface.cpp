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
//#include "violet_hold_assault.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_VOMIT = 1,
//    SAY_YUM = 2,
//    // SAY_          = 3  //Taste better going in!
//    SAY_DEATH = 4,
//};
//
//enum Spells
//{
//    SPELL_FESTERFACE_AGGRO = 202000,
//    SPELL_CONGEALING_VOMIT = 201598,
//    SPELL_CONGEALING_VOMIT_VIS = 201624,
//    SPELL_CONGEALING_VOMIT_SUM = 201569,
//    SPELL_YUM = 201715,
//
//    //Summons
//    SPELL_GREEN_SLIME_COSMETICS = 205156,
//    SPELL_FETID_STENCH = 201476,
//    SPELL_RECONGEALING = 201495,
//    SPELL_RECONGEALING_SEARCH = 202265, //Search Festerface
//
//    //Heroic
//    SPELL_ENERGY_TRACKER = 207677,
//    SPELL_SUM_BLACK_BILE = 201729,
//};
//
//enum eEvents
//{
//    EVENT_CONGEALING_VOMIT = 1,
//};
//
//enum Misc
//{
//    DATA_ACHIEVEMENT,
//};
//
//enum Add
//{
//    NPC_BLACK_BILE = 102169,
//};
//
////101995
//class boss_festerface : public CreatureScript
//{
//public:
//    boss_festerface() : CreatureScript("boss_festerface") {}
//
//    struct boss_festerfaceAI : public BossAI
//    {
//        boss_festerfaceAI(Creature* creature) : BossAI(creature, DATA_FESTERFACE)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            me->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//            removeloot = false;
//            bilekill = false;
//        }
//
//        bool removeloot;
//        bool bilekill;
//
//        void Reset() override
//        {
//            _Reset();
//            bilekill = false;
//            me->SetPower(POWER_ENERGY, 0);
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//            //39:33
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//            bilekill = false;
//            DoCast(me, SPELL_FESTERFACE_AGGRO, true);
//
//            if (me->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL)
//                DoCast(me, SPELL_ENERGY_TRACKER, true);
//
//            events.RescheduleEvent(EVENT_CONGEALING_VOMIT, 4000); //39:37, 40:28, 41:19
//        }
//
//        void SummonedCreatureDies(Creature* summoned, Unit* /*who*/) override
//        {
//            if (summoned->GetEntry() == NPC_BLACK_BILE && me->GetMap()->GetDifficultyID() == DIFFICULTY_MYTHIC)
//                bilekill = true;
//        }
//
//        uint32 GetData(uint32 type) const override
//        {
//            switch (type)
//            {
//            case DATA_ACHIEVEMENT:
//                return bilekill ? 1 : 0;
//            }
//
//            return 0;
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//
//            if (removeloot)
//                me->RemoveDynamicFlag(UNIT_DYNFLAG_LOOTABLE);
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (spell->Id == SPELL_RECONGEALING_SEARCH)
//            {
//                DoCast(caster, SPELL_YUM);
//                Talk(SAY_YUM);
//            }
//        }
//
//        void DoAction(int32 const action) override
//        {
//            if (action == ACTION_REMOVE_LOOT)
//                removeloot = true;
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
//                case EVENT_CONGEALING_VOMIT:
//                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                        DoCast(target, SPELL_CONGEALING_VOMIT);
//                    Talk(SAY_VOMIT);
//                    events.RescheduleEvent(EVENT_CONGEALING_VOMIT, 51000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_festerfaceAI(creature);
//    }
//};
//
////102158
//class npc_festerface_congealed_goo : public CreatureScript
//{
//public:
//    npc_festerface_congealed_goo() : CreatureScript("npc_festerface_congealed_goo") {}
//
//    struct npc_festerface_congealed_gooAI : public ScriptedAI
//    {
//        npc_festerface_congealed_gooAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        void Reset() override
//        {
//            DoCast(me, SPELL_GREEN_SLIME_COSMETICS, true);
//            DoCast(me, SPELL_FETID_STENCH, true);
//            Talk(0); //warning
//        }
//
//        void DamageTaken(Unit* /*attacker*/, uint32& damage)
//        {
//            if (damage >= me->GetHealth())
//            {
//                if (!me->HasAura(SPELL_RECONGEALING))
//                {
//                    DoCast(me, SPELL_RECONGEALING, true);
//                }
//                damage = 0;
//            }
//        }
//
//        void SpellHit(Unit* caster, const SpellInfo* spell) override
//        {
//            if (spell->Id == SPELL_YUM)
//                me->DespawnOrUnsummon();
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_festerface_congealed_gooAI(creature);
//    }
//};
//
////201598
//class spell_festerface_congealing_vomit : public SpellScriptLoader
//{
//public:
//    spell_festerface_congealing_vomit() : SpellScriptLoader("spell_festerface_congealing_vomit") {}
//
//    class spell_festerface_congealing_vomit_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_festerface_congealing_vomit_SpellScript);
//
//        uint8 castCount;
//
//        void HandleOnHit(SpellEffIndex /*effIndex*/)
//        {
//            Unit* caster = GetCaster();
//            if (!caster)
//                return;
//
//            castCount = GetSpellInfo()->GetEffect(EFFECT_1)->CalcValue();
//
//            Position pos;
//            float dist = 0.0f;
//            float angle = 0.0f;
//
//            for (uint16 i = 0; i < 44; i++)
//            {
//                angle = frand(-0.3f, 0.3f);
//                caster->GetNearPosition(dist + i, angle);
//                caster->CastSpell(pos, SPELL_CONGEALING_VOMIT_VIS, true);
//            }
//
//            for (uint8 i = 0; i < castCount; i++)
//            {
//                dist += 5.0f;
//                angle = frand(-0.3f, 0.3f);
//                caster->GetNearPosition(frand(dist, 30.0f), angle);
//                caster->CastSpell(pos, SPELL_CONGEALING_VOMIT_SUM, true);
//            }
//        }
//
//        void Register() override
//        {
//            OnEffectLaunchTarget += SpellEffectFn(spell_festerface_congealing_vomit_SpellScript::HandleOnHit, EFFECT_1, SPELL_EFFECT_DUMMY);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_festerface_congealing_vomit_SpellScript();
//    }
//};
//
////201495
//class spell_festerface_recongealing : public SpellScriptLoader
//{
//public:
//    spell_festerface_recongealing() : SpellScriptLoader("spell_festerface_recongealing") { }
//
//    class spell_festerface_recongealing_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_festerface_recongealing_AuraScript);
//
//        void OnApply(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (!GetCaster())
//                return;
//
//            GetCaster()->RemoveAurasDueToSpell(SPELL_FETID_STENCH);
//            GetCaster()->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//            GetCaster()->SetUnitFlags(UNIT_FLAG_NON_ATTACKABLE);
//            GetCaster()->SetUnitFlags(UNIT_FLAG_NOT_SELECTABLE);
//            GetCaster()->SetHealth(GetCaster()->GetMaxHealth());
//        }
//
//        void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//        {
//            if (!GetCaster())
//                return;
//
//            GetCaster()->CastSpell(GetCaster(), SPELL_FETID_STENCH, true);
//            GetCaster()->RemoveUnitFlag(UNIT_FLAG_NON_ATTACKABLE);
//            GetCaster()->RemoveUnitFlag(UNIT_FLAG_NOT_SELECTABLE);
//            GetCaster()->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//        }
//
//        void Register() override
//        {
//            OnEffectApply += AuraEffectApplyFn(spell_festerface_recongealing_AuraScript::OnApply, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//            OnEffectRemove += AuraEffectRemoveFn(spell_festerface_recongealing_AuraScript::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_festerface_recongealing_AuraScript();
//    }
//};
//
////207677
//class spell_festerface_energy_tracker : public SpellScriptLoader
//{
//public:
//    spell_festerface_energy_tracker() : SpellScriptLoader("spell_festerface_energy_tracker") { }
//
//    class spell_festerface_energy_tracker_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_festerface_energy_tracker_AuraScript);
//
//        uint8 PowerCount = 0;
//
//        void OnTick(AuraEffect const* aurEff)
//        {
//            Creature* caster = GetCaster()->ToCreature();
//            if (!caster || !caster->IsInCombat())
//                return;
//
//            PowerCount = caster->GetPower(POWER_ENERGY);
//
//            if (PowerCount < 100)
//                caster->SetPower(POWER_ENERGY, PowerCount + 2);
//            else if (!caster->HasUnitState(UNIT_STATE_CASTING))
//                caster->CastSpell(caster, SPELL_SUM_BLACK_BILE);
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_festerface_energy_tracker_AuraScript::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_festerface_energy_tracker_AuraScript();
//    }
//};
//
//class achievement_i_made_a_food : public AchievementCriteriaScript
//{
//public:
//    achievement_i_made_a_food() : AchievementCriteriaScript("achievement_i_made_a_food") { }
//
//    bool OnCheck(Player* /*player*/, Unit* target) override
//    {
//        if (!target)
//            return false;
//
//        if (Creature* fester = target->ToCreature())
//            if (fester->AI()->GetData(DATA_ACHIEVEMENT))
//                return true;
//
//        return false;
//    }
//};
//
//void AddSC_boss_festerface()
//{
//    new boss_festerface();
//    new npc_festerface_congealed_goo();
//    new spell_festerface_congealing_vomit();
//    new spell_festerface_recongealing();
//    new spell_festerface_energy_tracker();
//    new achievement_i_made_a_food();
//}
