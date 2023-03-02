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
//#include "emerald_nightmare.h"
//#include "SpellAuraDefines.h"
//#include "SpellAuraEffects.h"
//
//enum Says
//{
//    SAY_AGGRO = 0,
//    SAY_ROT = 1,
//    SAY_BREATH_EMOTE = 2,
//    SAY_BREATH = 3,
//    SAY_PHASE = 4,
//    SAY_DEATH = 5,
//};
//
//enum Spells
//{
//    SPELL_ENERGIZE = 220952,
//    SPELL_ALLOW_ROT_CAST = 204755,
//    SPELL_HEART_SWARM = 203552,
//    SPELL_ROT_FILTER = 203095,
//    SPELL_ROT_DOT = 203096,
//    SPELL_VOLATILE_ROT = 204463,
//    SPELL_INFESTED_GROUND_MISSILE = 204377,
//    SPELL_INFESTED_GROUND_AT = 203044,
//    SPELL_INFESTED_GROUND_VIS = 204476,
//    SPELL_INFESTED_BREATH_FILTER = 202968,
//    SPELL_INFESTED_BREATH_CHANNEL = 202977,
//    SPELL_INFESTED_BREATH_DMG = 202978,
//    SPELL_TRANSFORM_BUGS = 204894,
//
//    //Heroic
//    SPELL_TARGETING_AURA = 220189,
//    SPELL_INFESTED = 204504,
//
//    //Mythic
//    SPELL_INFESTED_MIND_FILTER = 225943,
//    SPELL_INFESTED_MIND = 205043,
//    SPELL_SPREAD_INFESTATION = 205070,
//
//    //!Trash
//        //Gelatinized Decay - 111004
//        SPELL_TRANSFORM_INSECT_AURA = 220978,
//        SPELL_TRANSFORM_INSECT = 220976,
//        SPELL_WAVE_OF_DECAY = 221059,
//        SPELL_UNSTABLE_DECAY = 221030,
//        SPELL_PUTRID_SWARM = 221033, //Aura summons Vermin
//
//        //Corrupted Vermin - 111005
//        SPELL_HEART_SWARM_SCALE = 203647,
//        SPELL_PUTRID_SWARM_DMG = 221036,
//
//        //Corrupted Vermin - 102998
//        SPELL_SCALE = 196285,
//        SPELL_BURST_OF_CORRUPTION = 203646,
//};
//
//enum eEvents
//{
//    EVENT_CHECK_POWER = 1,
//    EVENT_ALLOW_ROT_CAST = 2,
//    EVENT_ROT = 3,
//    EVENT_VOLATILE_ROT = 4,
//    EVENT_INFESTED_BREATH = 5,
//    EVENT_HEART_SWARM_END = 6,
//    EVENT_INFESTED_MIND = 7, //Mythic
//};
//
//enum ePhases
//{
//    PHASE_BATTLE = 1,
//    PHASE_SWARM = 2
//};
//
//enum eOther
//{
//    DATA_SWARM_COUNTER = 1,
//
//    EVENT_1,
//    EVENT_2,
//    EVENT_3,
//    EVENT_4,
//    EVENT_5,
//};
//
//Position const decayPos[3] =
//{
//    {1910.29f, 1332.19f, 369.50f},
//    {1866.0f,  1332.56f, 369.50f},
//    {1851.89f, 1295.29f, 369.50f}
//};
//
////102672
//struct boss_nythendra : public BossAI
//{
//    boss_nythendra(Creature* creature) : BossAI(creature, DATA_NYTHENDRA) {}
//
//    bool intro = true;
//    uint8 swarmCount = 0;
//    uint8 rotCastCount = 0;
//    uint8 decayDiedCount = 0;
//
//    void Intro()
//    {
//        intro = false;
//        decayDiedCount = 0;
//        me->SetReactState(REACT_PASSIVE);
//        me->SetUnitFlags(UNIT_FLAG_IMMUNE_TO_PC);
//        me->SetUnitFlags(UNIT_FLAG_NOT_ATTACKABLE_1);
//        me->SetStandState(UNIT_STAND_STATE_SLEEP);
//
//        for (uint8 i = 0; i < 3; ++i)
//            me->SummonCreature(NPC_GELATINIZED_DECAY, decayPos[i]);
//    }
//
//    void Reset() override
//    {
//        _Reset();
//        me->SetPower(POWER_ENERGY, 100);
//
//        if (intro)
//            Intro();
//        else
//            me->SetReactState(REACT_AGGRESSIVE);
//
//        uint8 playerCount = me->GetMap()->GetPlayersCountExceptGMs();
//        if (playerCount < 15)
//            swarmCount = 1;
//        else if (playerCount >= 15 && playerCount < 25)
//            swarmCount = 2;
//        else
//            swarmCount = 3;
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        Talk(SAY_AGGRO);
//        _JustEngagedWith();
//
//        events.RescheduleEvent(EVENT_CHECK_POWER, 5000);
//        events.RescheduleEvent(EVENT_ALLOW_ROT_CAST, 1000);
//        DefaultEvents(true);
//
//        instance->DoOnPlayers([](Player* player)
//        {
//            if (!player->HasAura(SPELL_TARGETING_AURA))
//                player->CastSpell(player, SPELL_TARGETING_AURA, true);
//        });
//    }
//
//    void DefaultEvents(bool JustEngagedWith)
//    {
//        events.RescheduleEvent(EVENT_ROT, JustEngagedWith ? 6000 : 14000);
//        events.RescheduleEvent(EVENT_VOLATILE_ROT, JustEngagedWith ? 24000 : 35000);
//        events.RescheduleEvent(EVENT_INFESTED_BREATH, (JustEngagedWith ? urand(35, 40) : 47) * IN_MILLISECONDS);
//    }
//
//    void EnterEvadeMode(EvadeReason w)
//    {
//        BossAI::EnterEvadeMode();
//        RemoveAuras();
//        RemoveBugs();
//    }
//
//    void JustDied(Unit* /*killer*/) override
//    {
//        _JustDied();
//        RemoveAuras();
//        RemoveBugs();
//        Talk(SAY_DEATH);
//    }
//
//    void SummonedCreatureDies(Creature* summon, Unit* /*killer*/) override
//    {
//        if (summon->GetEntry() == NPC_GELATINIZED_DECAY)
//        {
//            if (++decayDiedCount >= 3)
//            {
//                me->SetReactState(REACT_DEFENSIVE);
//                me->RemoveUnitFlag(UNIT_FLAG_IMMUNE_TO_PC);
//                me->RemoveUnitFlag(UNIT_FLAG_NOT_ATTACKABLE_1);
//                me->SetStandState(UNIT_STAND_STATE_STAND);
//            }
//        }
//    }
//
//    void SpellHitTarget(Unit* target, const SpellInfo* spell) override
//    {
//        switch (spell->Id)
//        {
//        case SPELL_INFESTED_BREATH_FILTER:
//        {
//            Position pos;
//            me->GetNearPosition(10.0f, me->GetRelativeAngle(target));
//            if (auto stalker = me->SummonCreature(NPC_BREATH_STALKER, pos, TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN, 10000))
//            {
//                for (uint8 i = 0; i < 5; ++i)
//                    me->CastSpell(me, SPELL_INFESTED_BREATH_DMG, true);
//                me->SetFacingToObject(stalker);
//                me->CastSpell(stalker, SPELL_INFESTED_BREATH_CHANNEL);
//            }
//            break;
//        }
//        case SPELL_TRANSFORM_BUGS:
//            target->SetVisible(true);
//            break;
//        case SPELL_INFESTED_MIND_FILTER:
//            if (target->GetAuraCount(SPELL_INFESTED) >= 10)
//                me->CastSpell(target, SPELL_INFESTED_MIND, true);
//            break;
//        }
//    }
//
//    void RemoveAuras()
//    {
//        if (IsHeroicPlusRaid())
//        {
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED_MIND);
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED);
//        }
//    }
//
//    void RemoveBugs()
//    {
//        std::list<Creature*> bugslist;
//        me->GetCreatureListWithEntryInGrid(bugslist, NPC_CORRUPTED_VERMIN, 150.0f);
//        for (auto bugs : bugslist)
//        {
//            bugs->RemoveAurasDueToSpell(SPELL_TRANSFORM_BUGS);
//            bugs->SetVisible(false);
//        }
//
//        if (IsHeroicPlusRaid())
//            instance->DoRemoveAurasDueToSpellOnPlayers(SPELL_INFESTED);
//    }
//
//    uint32 GetData(uint32 type) const override
//    {
//        switch (type)
//        {
//        case DATA_SWARM_COUNTER:
//            return swarmCount;
//        }
//        return 0;
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
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
//            case EVENT_CHECK_POWER:
//                if (me->GetPower(POWER_ENERGY) == 0)
//                {
//                    ++swarmCount;
//                    me->AttackStop();
//                    events.Reset();
//                    Talk(SAY_PHASE);
//                    DoCast(me, SPELL_TRANSFORM_BUGS, true);
//                    DoCast(SPELL_HEART_SWARM);
//                    events.RescheduleEvent(EVENT_HEART_SWARM_END, 20000);
//                }
//                events.RescheduleEvent(EVENT_CHECK_POWER, 10000);
//                break;
//            case EVENT_ALLOW_ROT_CAST:
//                DoCast(me, SPELL_ALLOW_ROT_CAST, true);
//                events.RescheduleEvent(EVENT_ALLOW_ROT_CAST, 120000);
//                break;
//            case EVENT_ROT:
//                if (me->GetPower(POWER_ENERGY) > 0)
//                {
//                    DoCast(SPELL_ROT_FILTER);
//                    Talk(SAY_ROT);
//                }
//                events.RescheduleEvent(EVENT_ROT, 16000);
//                break;
//            case EVENT_VOLATILE_ROT:
//                if (me->GetPower(POWER_ENERGY) > 0)
//                {
//                    DoCastVictim(SPELL_VOLATILE_ROT);
//                }
//                events.RescheduleEvent(EVENT_VOLATILE_ROT, 25000);
//                break;
//            case EVENT_INFESTED_BREATH:
//                me->AttackStop();
//                me->SetReactState(REACT_AGGRESSIVE);
//                DoCast(SPELL_INFESTED_BREATH_FILTER);
//                Talk(SAY_BREATH_EMOTE);
//                Talk(SAY_BREATH);
//                events.RescheduleEvent(EVENT_INFESTED_BREATH, 36000);
//                if (IsMythicRaid())
//                    events.RescheduleEvent(EVENT_INFESTED_MIND, 1000);
//                break;
//            case EVENT_HEART_SWARM_END:
//                DefaultEvents(false);
//                RemoveBugs();
//                me->SetReactState(REACT_AGGRESSIVE);
//                break;
//            case EVENT_INFESTED_MIND:
//                DoCast(SPELL_INFESTED_MIND_FILTER);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////111004
//struct npc_nythendra_gelatinized_decay : public ScriptedAI
//{
//    npc_nythendra_gelatinized_decay(Creature* creature) : ScriptedAI(creature) {}
//
//    EventMap events;
//
//    void Reset() override
//    {
//        events.Reset();
//        me->GetMotionMaster()->MoveRandom(15.0f);
//    }
//
//    void JustEngagedWith(Unit* /*who*/) override
//    {
//        events.RescheduleEvent(EVENT_1, 2000);
//        events.RescheduleEvent(EVENT_2, 4000);
//        events.RescheduleEvent(EVENT_3, 22000);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        if (!UpdateVictim())
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
//            case EVENT_1:
//                DoCast(SPELL_WAVE_OF_DECAY);
//                events.RescheduleEvent(EVENT_1, 3000);
//                break;
//            case EVENT_2:
//                DoCast(SPELL_UNSTABLE_DECAY);
//                events.RescheduleEvent(EVENT_2, 10000);
//                break;
//            case EVENT_3:
//                DoCast(SPELL_PUTRID_SWARM);
//                events.RescheduleEvent(EVENT_3, 30000);
//                break;
//            }
//        }
//        DoMeleeAttackIfReady();
//    }
//};
//
////102998, 111005
//struct npc_nythendra_corrupted_vermin : public ScriptedAI
//{
//    npc_nythendra_corrupted_vermin(Creature* creature) : ScriptedAI(creature)
//    {
//        me->SetSpeed(MOVE_WALK, 0.5f);
//        me->SetSpeed(MOVE_RUN, 0.5f);
//        me->SetReactState(REACT_PASSIVE);
//        if (me->GetEntry() == NPC_CORRUPTED_VERMIN)
//            me->SetVisible(false);
//    }
//
//    EventMap events;
//    uint8 castCount = 0;
//
//    void Reset() override
//    {
//        events.Reset();
//        events.RescheduleEvent(EVENT_1, 1000);
//        me->GetMotionMaster()->MoveRandom(5.0f);
//        DoCast(me, SPELL_SCALE, true);
//    }
//
//    void IsSummonedBy(Unit* summoner) override
//    {
//        me->SetMovementAnimKitId(11428);
//    }
//
//    void UpdateAI(uint32 diff) override
//    {
//        events.Update(diff);
//
//        if (uint32 eventId = events.ExecuteEvent())
//        {
//            switch (eventId)
//            {
//            case EVENT_1:
//                if (me->HasAura(SPELL_TRANSFORM_BUGS) || me->HasAura(SPELL_TRANSFORM_INSECT) || me->GetEntry() == NPC_CORRUPTED_VERMIN_2)
//                    if (Unit* pTarget = me->SelectNearestPlayer(3.0f))
//                        if (me->GetDistance(pTarget) < 2.0f)
//                        {
//                            castCount = 0;
//                            me->StopMoving();
//                            me->GetMotionMaster()->Clear();
//                            me->AddUnitState(UNIT_STATE_ROOT);
//                            me->RemoveAurasDueToSpell(SPELL_SCALE);
//                            DoCast(me, SPELL_HEART_SWARM_SCALE, true);
//                            events.RescheduleEvent(EVENT_2, 2000);
//                            break;
//                        }
//                events.RescheduleEvent(EVENT_1, 2000);
//                break;
//            case EVENT_2:
//                if (me->GetEntry() == NPC_CORRUPTED_VERMIN_2)
//                    DoCast(SPELL_PUTRID_SWARM_DMG);
//                else
//                {
//                    DoCast(SPELL_BURST_OF_CORRUPTION);
//                    if (++castCount == 3)
//                    {
//                        castCount = 0;
//                        DoCast(me, SPELL_SCALE, true);
//                        me->RemoveAurasDueToSpell(SPELL_HEART_SWARM_SCALE);
//                        me->ClearUnitState(UNIT_STATE_ROOT);
//                        events.RescheduleEvent(EVENT_1, 18000);
//                        break;
//                    }
//                }
//                events.RescheduleEvent(EVENT_2, 2000);
//                break;
//            }
//        }
//    }
//};
//
////203095
//class spell_nythendra_rot : public SpellScript
//{
//    PrepareSpellScript(spell_nythendra_rot);
//
//    uint8 swarmCount = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        if (Unit* caster = GetCaster())
//        {
//            if (caster->GetVictim())
//                targets.remove(caster->GetVictim());
//
//            if (caster->IsAIEnabled)
//                swarmCount = caster->GetAI()->GetData(DATA_SWARM_COUNTER);
//        }
//        Trinity::Containers::RandomResize(targets, swarmCount);
//    }
//
//    void HandleOnHit()
//    {
//        if (GetCaster() && GetHitUnit())
//            GetCaster()->CastSpell(GetHitUnit(), SPELL_ROT_DOT, true);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_nythendra_rot::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
//        OnHit += SpellHitFn(spell_nythendra_rot::HandleOnHit);
//    }
//};
//
////204463, 203096
//class spell_nythendra_volatile_rot : public AuraScript
//{
//    PrepareAuraScript(spell_nythendra_volatile_rot);
//
//    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
//    {
//        AuraRemoveMode mode = GetTargetApplication()->GetRemoveMode();
//
//        if (!GetCaster() || !GetTarget() || mode != AURA_REMOVE_BY_EXPIRE)
//            return;
//
//        if (aurEff->GetId() == SPELL_VOLATILE_ROT)
//        {
//            for (uint8 i = 0; i < 4; ++i)
//                GetTarget()->CastSpell(GetTarget(), SPELL_INFESTED_GROUND_VIS, true);
//        }
//        else if (aurEff->GetId() == SPELL_ROT_DOT)
//            GetCaster()->CastSpell(GetTarget(), SPELL_INFESTED_GROUND_AT, true);
//    }
//
//    void Register() override
//    {
//        OnEffectRemove += AuraEffectRemoveFn(spell_nythendra_volatile_rot::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL, AURA_EFFECT_HANDLE_REAL);
//        OnEffectRemove += AuraEffectRemoveFn(spell_nythendra_volatile_rot::OnRemove, EFFECT_2, SPELL_AURA_MOD_SCALE, AURA_EFFECT_HANDLE_REAL);
//    }
//};
//
////204470
//class spell_nythendra_volatile_rot_dmg : public SpellScript
//{
//    PrepareSpellScript(spell_nythendra_volatile_rot_dmg);
//
//    void DealDamage()
//    {
//        if (!GetCaster() || !GetHitUnit())
//            return;
//
//        float distance = GetCaster()->GetExactDist2d(GetHitUnit());
//        float radius = GetSpellInfo()->GetEffect(EFFECT_0)->CalcRadius(GetCaster());
//        uint32 perc;
//        if (distance < 15.0f)
//            perc = 100 - (distance / 10) * 30;
//        else
//            perc = 15 - (distance / radius) * 30;
//
//        uint32 damage = CalculatePct(GetHitDamage(), perc);
//        SetHitDamage(damage);
//    }
//
//    void Register() override
//    {
//        OnHit += SpellHitFn(spell_nythendra_volatile_rot_dmg::DealDamage);
//    }
//};
//
////203536, 203537
//class spell_nythendra_infested_ground_rot : public SpellScript
//{
//    PrepareSpellScript(spell_nythendra_infested_ground_rot);
//
//    void HandleDummy(SpellEffIndex effIndex)
//    {
//        if (!GetCaster())
//            return;
//
//        WorldLocation* loc = GetHitDest();
//        if (auto instance = GetCaster()->GetInstanceScript())
//            if (auto nythendra = instance->instance->GetCreature(instance->GetGuidData(NPC_NYTHENDRA)))
//                if (nythendra->IsInCombat())
//                    nythendra->CastSpell(loc->GetPosition(), SPELL_INFESTED_GROUND_MISSILE, true);
//    }
//
//    void HandleScript(SpellEffIndex effIndex)
//    {
//        if (!GetCaster() || !GetCaster()->IsInCombat())
//            return;
//
//        WorldLocation* loc = GetHitDest();
//        GetCaster()->CastSpell(loc->GetPosition(), SPELL_INFESTED_GROUND_AT, true);
//    }
//
//    void Register() override
//    {
//        OnEffectHit += SpellEffectFn(spell_nythendra_infested_ground_rot::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
//        OnEffectHit += SpellEffectFn(spell_nythendra_infested_ground_rot::HandleScript, EFFECT_0, SPELL_EFFECT_TRIGGER_MISSILE);
//    }
//};
//
////203045,202978,203097,204470,203646,205070
//class spell_nythendra_infested : public SpellScript
//{
//    PrepareSpellScript(spell_nythendra_infested);
//
//    void HandleOnHit()
//    {
//        if (!GetCaster() || !GetHitUnit() || GetHitUnit()->HasAura(SPELL_INFESTED_MIND))
//            return;
//
//        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
//            if (Creature* nythendra = instance->instance->GetCreature(instance->GetGuidData(NPC_NYTHENDRA)))
//                if (nythendra->GetMap()->GetDifficultyID() != DIFFICULTY_NORMAL_RAID && nythendra->GetMap()->GetDifficultyID() != DIFFICULTY_LFR)
//                    nythendra->CastSpell(GetHitUnit(), SPELL_INFESTED, true);
//    }
//
//    void Register() override
//    {
//        OnHit += SpellHitFn(spell_nythendra_infested::HandleOnHit);
//    }
//};
//
////205043
//class spell_nythendra_infested_mind : public AuraScript
//{
//    PrepareAuraScript(spell_nythendra_infested_mind);
//
//        void OnAbsorb(AuraEffect* aurEff, DamageInfo& dmgInfo, uint32& absorbAmount)
//    {
//        absorbAmount = 1;
//
//        if (GetTarget() && GetTarget()->HealthBelowPct(51))
//            this->Remove();
//    }
//
//    void OnPeriodic(AuraEffect const* aurEff)
//    {
//        if (GetTarget())
//        {
//            GetTarget()->GetMotionMaster()->Clear();
//            GetTarget()->CastSpell(GetTarget(), SPELL_SPREAD_INFESTATION);
//        }
//    }
//
//    void Register() override
//    {
//        OnEffectAbsorb += AuraEffectAbsorbFn(spell_nythendra_infested_mind::OnAbsorb, EFFECT_0);
//        OnEffectPeriodic += AuraEffectPeriodicFn(spell_nythendra_infested_mind::OnPeriodic, EFFECT_8, SPELL_AURA_PERIODIC_DUMMY);
//    }
//};
//
////222760
//class spell_en_befoulment : public SpellScript
//{
//    PrepareSpellScript(spell_en_befoulment);
//
//    uint8 targetCount = 0;
//
//    void FilterTargets(std::list<WorldObject*>& targets)
//    {
//        targetCount = targets.size();
//    }
//
//    void HandleDamage(SpellEffIndex /*effectIndex*/)
//    {
//        if (targetCount)
//            SetHitDamage(GetHitDamage() / targetCount);
//    }
//
//    void Register() override
//    {
//        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_en_befoulment::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
//        OnEffectHitTarget += SpellEffectFn(spell_en_befoulment::HandleDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
//    }
//};
//
//void AddSC_nythendra()
//{
//    RegisterCreatureAI(boss_nythendra);
//    RegisterCreatureAI(npc_nythendra_gelatinized_decay);
//    RegisterCreatureAI(npc_nythendra_corrupted_vermin); 
//    RegisterAuraScript(spell_nythendra_volatile_rot);
//    RegisterSpellScript(spell_nythendra_volatile_rot_dmg);
//    RegisterSpellScript(spell_nythendra_infested_ground_rot);
//    RegisterSpellScript(spell_nythendra_rot);
//    RegisterSpellScript(spell_nythendra_infested);
//    RegisterAuraScript(spell_nythendra_infested_mind);
//    RegisterSpellScript(spell_en_befoulment);
//}
