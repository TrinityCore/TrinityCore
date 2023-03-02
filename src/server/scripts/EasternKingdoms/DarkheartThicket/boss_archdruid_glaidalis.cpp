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
//#include "darkheart_thicket.h"
//
//enum Says
//{
//    SAY_EVENT_BOSS = 0,
//    SAY_AGGRO = 1,
//    SAY_NIGHTFALL = 2,
//    SAY_RAMPAGE = 3,
//    SAY_GREIEVOUS = 4,
//    SAY_20 = 5,
//    SAY_DEATH = 6,
//    //event
//    SAY_EVENT = 0,
//};
//
//enum Spells
//{
//    SPELL_PRE_GRIEVOUS_LEAP = 197709,
//    SPELL_GRIEVOUS_LEAP = 196346,
//    SPELL_GRIEVOUS_LEAP_MORPH = 196348,
//    SPELL_GRIEVOUS_LEAP_RETURN = 198095,
//    SPELL_GRIEVOUS_LEAP_DOT = 196376,
//    SPELL_GRIEVOUS_LEAP_AOE_1 = 196354,
//    SPELL_GRIEVOUS_LEAP_AOE_2 = 198269,
//    SPELL_PRIMAL_RAMPAGE_MORPH = 198360,
//    SPELL_PRIMAL_RAMPAGE_KNOCK = 198376,
//    SPELL_PRIMAL_RAMPAGE_CHARGE = 198379,
//    SPELL_NIGHTFALL = 198400,
//    SPELL_NIGHTFALL_DOT = 198408,
//    SPELL_SUM_ABOMINATION = 198432, //Mythic
//
//    //Pre-event
//    SPELL_VISUAL = 197642,
//    //End
//    SPELL_TALK = 202882,
//
//    //Abomination
//    SPELL_FIXATE = 198477,
//    SPELL_NIGHTMARE_DEATH = 210262,
//};
//
//enum eEvents
//{
//    EVENT_PRE_GRIEVOUS_LEAP = 1, 
//    EVENT_GRIEVOUS_LEAP = 2,
//    EVENT_PRIMAL_RAMPAGE = 3,
//    EVENT_NIGHTFALL = 4,
//};
//
////96512
//struct boss_arch_druid_glaidalis : public BossAI
//{
//    explicit boss_arch_druid_glaidalis(Creature* creature) : BossAI(creature, DATA_GLAIDALIS)
//    {
//        introEvent = false;
//        _introDone = false;
//        _say_20 = false;
//        instance->HandleGameObject(instance->GetGuidData(GO_GLAIDALIS_INVIS_DOOR), true);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//    }
//
//    bool introEvent;
//    bool _introDone;
//    bool _say_20;
//    uint32 primalDelayTimer;
//
//    void Reset() override
//    {
//        _Reset();
//        _say_20 = false;
//        primalDelayTimer = 0;
//
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTFALL_DOT);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//        events.RescheduleEvent(EVENT_GRIEVOUS_LEAP, 6000);
//        events.RescheduleEvent(EVENT_PRIMAL_RAMPAGE, 14000);
//        events.RescheduleEvent(EVENT_NIGHTFALL, 20000);
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        Talk(SAY_DEATH);
//        _JustDied();
//        instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_NIGHTFALL_DOT);
//        DoCast(me, SPELL_TALK, true);
//    }
//
//    void MovementInform(uint32 type, uint32 id) override
//    {
//        if (type == EFFECT_MOTION_TYPE)
//            if (id == SPELL_GRIEVOUS_LEAP_MORPH && me->HasAura(SPELL_GRIEVOUS_LEAP_MORPH))
//            {
//                DoCastVictim(SPELL_GRIEVOUS_LEAP_RETURN);
//            }
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_GRIEVOUS_LEAP_AOE_1:
//        case SPELL_GRIEVOUS_LEAP_AOE_2:
//            if (me->GetGUID() != target->GetGUID())
//                DoCast(target, SPELL_GRIEVOUS_LEAP_DOT, true);
//            break;
//        }
//    }
//
//    void MoveInLineOfSight(Unit* who) override
//    {
//        if (!who || !who->IsPlayer() || who->ToPlayer()->IsGameMaster())
//            return;
//
//        if (!_introDone && me->IsWithinDistInMap(who, 48.0f))
//        {
//            _introDone = true;
//            instance->HandleGameObject(instance->GetGuidData(GO_GLAIDALIS_INVIS_DOOR), false);
//            std::list<Creature*> list;
//            me->GetCreatureListWithEntryInGrid(list, NPC_DRUIDIC_PRESERVER, 150.0f);
//            if (!list.empty())
//            {
//                Talk(SAY_EVENT_BOSS);
//                for (auto const& itr : list)
//                {
//                    if (Creature* target = itr->FindNearestCreature(100404, 50.0f, true))  //trigger
//                        itr->CastSpell(target, SPELL_VISUAL);
//                }
//
//                std::list<Creature*>::const_iterator itr = list.begin();
//                std::advance(itr, urand(0, list.size() - 1));
//                (*itr)->AI()->Talk(SAY_EVENT);
//            }
//            events.RescheduleEvent(EVENT_PRE_GRIEVOUS_LEAP, 3000);
//        }
//    }
//
//    void DamageTaken(Unit* /*attacker*/, uint32& damage)
//    {
//        if (me->HealthBelowPct(21) && !_say_20)
//        {
//            _say_20 = true;
//            Talk(SAY_20);
//        }
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim() && introEvent)
//            return;
//
//        events.Update(diff);
//
//        if (me->HasUnitState(UNIT_STATE_CASTING))
//            return;
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_PRE_GRIEVOUS_LEAP:
//                if (Creature* target = me->FindNearestCreature(NPC_DRUIDIC_PRESERVER, 200.0f, true))
//                {
//                    me->CastSpell(target, SPELL_PRE_GRIEVOUS_LEAP);
//                    me->Kill(target, target);
//                    events.RescheduleEvent(EVENT_PRE_GRIEVOUS_LEAP, 700);
//                }
//                else
//                {
//                    BossAI::EnterEvadeMode(); //?? ????????? ?????
//                    if (Creature* trigger = me->FindNearestCreature(102851, 200.0f, true))   //trigger aura
//                        trigger->RemoveAurasDueToSpell(203257);
//                    instance->HandleGameObject(instance->GetGuidData(GO_GLAIDALIS_INVIS_DOOR), true);
//                    introEvent = true;
//                    me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                    me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                }
//                break;
//            case EVENT_GRIEVOUS_LEAP:
//                if (urand(0, 1) == 1)
//                    Talk(SAY_GREIEVOUS);
//                DoCast(SPELL_GRIEVOUS_LEAP);
//                events.RescheduleEvent(EVENT_GRIEVOUS_LEAP, 16000);
//                break;
//            case EVENT_PRIMAL_RAMPAGE:
//                if (urand(0, 1) == 1)
//                    Talk(SAY_RAMPAGE);
//                primalDelayTimer = 10000;
//                DoCast(me, SPELL_PRIMAL_RAMPAGE_MORPH, true);
//                if (Unit* pTaget = me->GetVictim())
//                {
//                    DoCast(pTaget, SPELL_PRIMAL_RAMPAGE_KNOCK, true);
//                    DoCast(pTaget, SPELL_PRIMAL_RAMPAGE_CHARGE);
//                }
//                events.RescheduleEvent(EVENT_PRIMAL_RAMPAGE, 16000);
//                break;
//            case EVENT_NIGHTFALL:
//                Talk(SAY_NIGHTFALL);
//                DoCast(SPELL_NIGHTFALL);
//                events.RescheduleEvent(EVENT_NIGHTFALL, 16000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////102962
//struct npc_glaidalis_nightmare_abomination : public ScriptedAI
//{
//    explicit npc_glaidalis_nightmare_abomination(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetReactState(REACT_PASSIVE);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_FEAR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_POLYMORPH, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_HORROR, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_SAPPED, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_CHARM, true);
//        me->ApplySpellImmune(0, IMMUNITY_MECHANIC, MECHANIC_DISORIENTED, true);
//        me->ApplySpellImmune(0, IMMUNITY_STATE, SPELL_AURA_MOD_CONFUSE, true);
//    }
//
//    ObjectGuid targetGUID;
//    uint32 fixateTimer = 0;
//
//    void Reset() {}
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        fixateTimer = 2000;
//    }
//
//    void JustDied(Unit* /*killer*/)
//    {
//        me->CastSpell(me, SPELL_NIGHTMARE_DEATH, true);
//    }
//
//    void UpdateAI(uint32 diff)
//    {
//        if (!UpdateVictim())
//            return;
//
//        if (me->HasUnitState(UNIT_STATE_STUNNED))
//            return;
//
//        if (fixateTimer)
//        {
//            if (fixateTimer <= diff)
//            {
//                fixateTimer = 2000;
//
//                if (targetGUID.IsEmpty())
//                {
//                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 60.0f, true))
//                    {
//                        targetGUID = target->GetGUID();
//                        me->CastSpell(target, SPELL_FIXATE, true);
//                        me->ClearUnitState(UNIT_STATE_CASTING);
//                        AttackStart(target);
//                    }
//                }
//            }
//            else
//                fixateTimer -= diff;
//        }
//
//        DoMeleeAttackIfReady();
//    }
//};
//
////196346
//class spell_glaidalis_grievous_leap : public SpellScript
//{
//    PrepareSpellScript(spell_glaidalis_grievous_leap);
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        Unit* caster = GetCaster();
//        if (targets.empty() || !caster)
//            return;
//
//        targets.clear();
//
//      //  if (Unit* target = caster->GetAI()->SelectTarget(SELECT_TARGET_FARTHEST, 0, 55.0f, true))
//           // targets.push_back(target);
//    }
//
//    void HandleOnHit()
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        GetCaster()->CastSpell(GetHitUnit(), SPELL_GRIEVOUS_LEAP_MORPH, true);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_glaidalis_grievous_leap::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
//        OnHit += SpellHitFn(spell_glaidalis_grievous_leap::HandleOnHit);
//    }
//};
//
////196376
//class spell_glaidalis_grievous_tear : public AuraScript
//{
//    PrepareAuraScript(spell_glaidalis_grievous_tear);
//
//        uint32 checkTimer = 500;
//
//    void OnUpdate(AuraEffect const* auraEffect)
//    {
//  
//            if (GetUnitOwner() && GetUnitOwner()->HealthAbovePct(90))
//                this->Remove();
//    }
//
//    void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
//    {
//        absorbAmount = 0;
//    }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_glaidalis_grievous_tear::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);;
//        OnEffectAbsorb += AuraEffectAbsorbFn(spell_glaidalis_grievous_tear::OnAbsorb, EFFECT_1);
//    }
//};
//
////200684 trash
//class spell_nightmare_toxin : public AuraScript
//{
//    PrepareAuraScript(spell_nightmare_toxin);
//
//    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
//    {
//        if (!GetTarget())
//            return;
//
//        if (auto spider = GetTarget()->FindNearestCreature(101679, 40.0f, true))
//            spider->CastSpell(GetTarget(), 200686, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_nightmare_toxin::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////225484 trash
//class spell_nightclaw_grievous_rip : public AuraScript
//{
//    PrepareAuraScript(spell_nightclaw_grievous_rip);
//
//        uint32 checkTimer = 500;
//
//        void OnUpdate(AuraEffect const* auraEffect)
//        {
//
//            if (GetUnitOwner() && GetUnitOwner()->HealthAbovePct(90))
//                this->Remove();
//        }
//
//        void Absorb(AuraEffect* auraEffect, DamageInfo& dmgInfo, uint32& absorbAmount)
//        {
//            absorbAmount = 0;
//        }
//
//    void Register() override
//    {
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_nightclaw_grievous_rip::OnUpdate, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);;
//        OnEffectAbsorb += AuraEffectAbsorbFn(spell_nightclaw_grievous_rip::Absorb, EFFECT_2);
//    }
//};
//
//void AddSC_boss_archdruid_glaidalis()
//{
//    RegisterCreatureAI(boss_arch_druid_glaidalis);
//    RegisterCreatureAI(npc_glaidalis_nightmare_abomination);
//    RegisterSpellScript(spell_glaidalis_grievous_leap);
//    RegisterAuraScript(spell_glaidalis_grievous_tear);
//    RegisterAuraScript(spell_nightmare_toxin);
//    RegisterAuraScript(spell_nightclaw_grievous_rip);
//}
