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
//#include "ScriptMgr.h"
//#include "ScriptedCreature.h"
//#include "the_arcway.h"
//
//enum Says
//{
//    SAY_AGGRO = 1,
//    SAY_FEL = 2,
//    SAY_SUM = 3,
//    SAY_WICKED = 4,
//    SAY_WICKED_TEXT = 5,
//    SAY_DEATH = 6,
//};
//
////TO-DO: Весь треш на 703+
//enum Spells
//{
//    SPELL_FEL_FISSURE = 197776,
//    SPELL_FEL_FISSURE_SUM = 197765,
//    SPELL_FEL_FISSURE_AT = 197542, //197579 dmg
//    SPELL_FEL_FISSURE_GO = 197573,
//    SPELL_SHADOW_SLASH = 212028,
//    SPELL_SHADOW_SLASH_AT = 212030,
//    SPELL_WICKED_SLAM = 197810,
//    SPELL_WAKE_OF_SHADOW = 220441, //220443 dmg
//
//    //Felbat
//    SPELL_BOMBARDMENT_AURA = 197786,
//    SPELL_BOMBARDMENT_DMG = 197787,
//    SPELL_THIRST_FOR_BLOOD = 220533,
//};
//
//enum eEvents
//{
//    EVENT_FEL_FISSURE = 1,
//    EVENT_SHADOW_SLASH = 2,
//    EVENT_WICKED_SLAM = 3,
//    EVENT_SUM_FELBAT = 4,
//    EVENT_1,
//    EVENT_2,
//};
//
////98206
//class boss_general_xakal : public CreatureScript
//{
//public:
//    boss_general_xakal() : CreatureScript("boss_general_xakal") {}
//
//    struct boss_general_xakalAI : public BossAI
//    {
//        boss_general_xakalAI(Creature* creature) : BossAI(creature, DATA_XAKAL) {}
//
//        uint8 shadowDist = 0;
//        uint16 shadowTimer = 0;
//        Position shadowPos;
//        float angle;
//
//        void Reset() override
//        {
//            _Reset();
//        }
//
//        void JustEngagedWith(Unit* /*who*/) override
//            //37:50(N) | 58:24(H)
//        {
//            Talk(SAY_AGGRO);
//            _JustEngagedWith();
//
//            events.RescheduleEvent(EVENT_FEL_FISSURE, 6000); //37:56
//            events.RescheduleEvent(EVENT_SHADOW_SLASH, 13000); //38:03
//            events.RescheduleEvent(EVENT_WICKED_SLAM, 40000); //38:30
//            events.RescheduleEvent(EVENT_SUM_FELBAT, 11000); //38:01, 38:23
//        }
//
//        void JustDied(Unit* /*killer*/) override
//        {
//            Talk(SAY_DEATH);
//            _JustDied();
//        }
//
//        void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//        {
//            switch (spell->Id)
//            {
//            case SPELL_FEL_FISSURE:
//                DoCast(target, SPELL_FEL_FISSURE_SUM, true);
//                break;
//            case SPELL_SHADOW_SLASH:
//                Position pos;
//                angle = me->GetRelativeAngle(target);
//                me->GetNearPosition(1.0f, angle);
//                DoCast(target, SPELL_SHADOW_SLASH_AT);
//                break;
//            }
//        }
//
//        void UpdateAI(uint32 diff) override
//        {
//            if (!UpdateVictim())
//                return;
//
//            events.Update(diff);
//
//            if (shadowTimer)
//            {
//                if (shadowTimer <= diff)
//                {
//                    shadowDist += 5;
//                    shadowTimer = 500;
//                    Position pos;
//                    me->CastSpell(pos, SPELL_WAKE_OF_SHADOW, true);
//                    if (shadowDist > 60)
//                        shadowTimer = 0;
//                }
//                else
//                    shadowTimer -= diff;
//            }
//
//            if (me->HasUnitState(UNIT_STATE_CASTING))
//                return;
//
//            if (uint32 eventId = events.ExecuteEvent())
//            {
//                switch (eventId)
//                {
//                case EVENT_FEL_FISSURE:
//                    DoCast(SPELL_FEL_FISSURE);
//                    Talk(SAY_FEL);
//                    events.RescheduleEvent(EVENT_FEL_FISSURE, 14000);
//                    break;
//                case EVENT_SHADOW_SLASH:
//                    shadowDist = 0;
//                    shadowTimer = 500;
//                    DoCast(SPELL_SHADOW_SLASH);
//                    events.RescheduleEvent(EVENT_SHADOW_SLASH, 14000);
//                    break;
//                case EVENT_WICKED_SLAM:
//                    Talk(SAY_WICKED);
//                    Talk(SAY_WICKED_TEXT);
//                    DoCast(SPELL_WICKED_SLAM);
//                    events.RescheduleEvent(EVENT_WICKED_SLAM, 40000);
//                    break;
//                case EVENT_SUM_FELBAT:
//                {
//                    Talk(SAY_SUM);
//                    Position pos;
//                    me->GetRandomNearPosition(30.0f);
//                    me->SummonCreature(NPC_DREAD_FELBAT, pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ() + 20.0f);
//                    events.RescheduleEvent(EVENT_SUM_FELBAT, 22000);
//                    break;
//                }
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new boss_general_xakalAI(creature);
//    }
//};
//
////100342
//class npc_xakal_fissure : public CreatureScript
//{
//public:
//    npc_xakal_fissure() : CreatureScript("npc_xakal_fissure") {}
//
//    struct npc_xakal_fissureAI : public ScriptedAI
//    {
//        npc_xakal_fissureAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//            SetCombatMovement(false);
//            me->SetUnitFlags(UNIT_FLAG_STUNNED);
//        }
//
//        bool active;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            DoCast(me, SPELL_FEL_FISSURE_AT, true);
//        }
//
//        void UpdateAI(uint32 diff) override {}
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_xakal_fissureAI(creature);
//    }
//};
//
////100393
//class npc_xakal_dread_felbat : public CreatureScript
//{
//public:
//    npc_xakal_dread_felbat() : CreatureScript("npc_xakal_dread_felbat") {}
//
//    struct npc_xakal_dread_felbatAI : public ScriptedAI
//    {
//        npc_xakal_dread_felbatAI(Creature* creature) : ScriptedAI(creature)
//        {
//            me->SetReactState(REACT_PASSIVE);
//        }
//
//        EventMap events;
//
//        void Reset() override {}
//
//        void IsSummonedBy(Unit* summoner) override
//        {
//            DoZoneInCombat(me, 120.0f);
//            DoCast(me, SPELL_BOMBARDMENT_AURA, true);
//            events.RescheduleEvent(EVENT_1, 7000);
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
//                    me->SetReactState(REACT_AGGRESSIVE);
//                    events.RescheduleEvent(EVENT_2, 5000);
//                    break;
//                case EVENT_2:
//                    DoCastVictim(SPELL_THIRST_FOR_BLOOD);
//                    events.RescheduleEvent(EVENT_2, 5000);
//                    break;
//                }
//            }
//            DoMeleeAttackIfReady();
//        }
//    };
//
//    CreatureAI* GetAI(Creature* creature) const override
//    {
//        return new npc_xakal_dread_felbatAI(creature);
//    }
//};
//
////197786
//class spell_xakal_bombardment : public SpellScriptLoader
//{
//public:
//    spell_xakal_bombardment() : SpellScriptLoader("spell_xakal_bombardment") { }
//
//    class spell_xakal_bombardment_AuraScript : public AuraScript
//    {
//        PrepareAuraScript(spell_xakal_bombardment_AuraScript);
//
//        void OnPeriodic(AuraEffect const* aurEff)
//        {
//            Creature* caster = GetCaster()->ToCreature();
//            if (!caster)
//                return;
//
//            if (Unit* target = caster->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
//                caster->CastSpell(target, SPELL_BOMBARDMENT_DMG, true);
//        }
//
//        void Register() override
//        {
//            OnEffectPeriodic += AuraEffectPeriodicFn(spell_xakal_bombardment_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
//        }
//    };
//
//    AuraScript* GetAuraScript() const override
//    {
//        return new spell_xakal_bombardment_AuraScript();
//    }
//};
//
//// trash 211950
//uint32 RandomSpells[7] =
//{
//    211995,
//    211959,
//    211999,
//    211956,
//    211958,
//    211994,
//    212008
//};
//
//class spell_throw_staff : public SpellScriptLoader
//{
//public:
//    spell_throw_staff() : SpellScriptLoader("spell_throw_staff") {}
//
//    class spell_throw_staff_SpellScript : public SpellScript
//    {
//        PrepareSpellScript(spell_throw_staff_SpellScript);
//
//        void HandleOnCast()
//        {
//            if (!GetCaster())
//                return;
//
//            if (Unit* target = GetCaster()->SelectNearestPlayer(30.0f))
//                GetCaster()->CastSpell(target, RandomSpells[urand(0, 7)]);
//        }
//
//        void Register() override
//        {
//            OnCast += SpellCastFn(spell_throw_staff_SpellScript::HandleOnCast);
//        }
//    };
//
//    SpellScript* GetSpellScript() const override
//    {
//        return new spell_throw_staff_SpellScript();
//    }
//};
//
//
//void AddSC_boss_general_xakal()
//{
//    new boss_general_xakal();
//    new npc_xakal_fissure();
//    new npc_xakal_dread_felbat();
//    new spell_xakal_bombardment();
//    new spell_throw_staff();
//}
