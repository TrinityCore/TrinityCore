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


#include "ScriptMgr.h"
#include "Player.h"
#include "SpellMgr.h"
#include "ScriptedGossip.h"
#include "ScriptedCreature.h"
#include "ScriptedEscortAI.h"
#include "Log.h"
#include "Conversation.h"
#include "CreatureTextMgr.h"
#include "PhasingHandler.h"
#include "AreaTriggerAI.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellScript.h"
//#include "WorldQuestMgr.h"
#include "GameEventMgr.h"
#include "Unit.h"

enum eSays
{
    SAY_AGGRO = 0,
    SAY_KILL = 1
};

enum eSpells
{
    SPELL_BEGUILING_CHARM = 247549,
    SPELL_BEGUILING_CHARM_AURA = 247551,
    SPELL_HEART_BREAKER = 247517,
    SPELL_FEL_LASH = 247604,
    SPELL_SADIST = 247590,
    SPELL_SADIST_PROC = 247544,

    SPELL_FEL_BREATH = 247731,
    SPELL_STOMP = 247733,
    SPELL_DRAIN = 247739,
    SPELL_DRAIN_HP = 247742,

    SPELL_SEARING_GAZE = 247320,
    SPELL_GUSHING_WOUND = 247318,
    SPELL_LASH = 247325,
    SPELL_EYE_SORE = 247332,
    SPELL_PHANTASM = 247393,
    SPELL_PHANTASM_TRIGGER = 247370,

    SPELL_REAP = 247492,
    SPELL_SOW = 247577,
    SPELL_SOW_DMG = 247495,
    SPELL_DEATH_FIELD = 247632,
    SPELL_DEATH_FIELD_VISUAL = 247635,
    SPELL_SEEDS_OF_CHAOS = 247586,

    SPELL_SILENCE = 247698,
    SPELL_SOUL_CLEAVE = 247410,
    SPELL_CAVITATION = 247415,
    SPELL_SEED_OF_DESTRUCTION = 247437,
    SPELL_WAKE_OF_DESTRUCTION = 247440,

    SPELL_FEL_BLAST = 254147,
    SPELL_INFECTED_CLAWS = 247362,
    SPELL_INFECTED_CLAWS_PROC = 247361,
    SPELL_NAUSEA = 247441,
    SPELL_SLIMBERING_GASP = 247379,
    SPELL_GROTESQUE_GREEN = 247447,
    SPELL_GROTESQUE_RED = 247497,
    SPELL_GROTESQUE_SPAWN = 247443,
    SPELL_POOL_OF_FIRE = 254802,

    SPELL_FEL_FIREBOLT = 247423,
    SPELL_SCORCHING_PRESENCE = 247401
};

enum eEvents
{
    EVENT_HEART_BREAKER = 1,
    EVENT_FEL_LASH = 2,
    EVENT_BEGUILING_CHARM = 3,

    EVENT_FEL_BREATH = 4,
    EVENT_STOMP = 5,
    EVENT_DRAIN = 6,

    EVENT_SEARING_GAZE = 7,
    EVENT_GUSHING_WOUND = 8,
    EVENT_LASH = 9,
    EVENT_EYE_SORE = 10,
    EVENT_PHANTASM = 11,

    EVENT_REAP = 12,
    EVENT_SOW = 13,
    EVENT_DEATH_FIELD = 14,
    EVENT_SEEDS_OF_CHAOS = 15,

    EVENT_SILENCE = 16,
    EVENT_SOUL_CLEAVE = 17,
    EVENT_CAVITATION = 18,
    EVENT_SEED_OF_DESTRUCTION = 19,

    EVENT_FEL_BLAST = 20,
    EVENT_GROTESQUE_SPAWN = 21
};

enum Phase
{
    PHASE_1 = 1,
    PHASE_2
};

struct boss_mistress_alluradel : public ScriptedAI
{
    boss_mistress_alluradel(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;
    uint32 checktimer;
    ObjectGuid tankGUID;

    void Reset() override
    {
        events.Reset();
        me->RemoveAllAuras();
        me->SetPower(POWER_ENERGY, 0);
        DoCast(SPELL_SADIST);
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        events.RescheduleEvent(EVENT_HEART_BREAKER, 4000);
        events.RescheduleEvent(EVENT_FEL_LASH, 15000);
        events.RescheduleEvent(EVENT_BEGUILING_CHARM, 29000);
        events.RescheduleEvent(EVENT_PHANTASM, 33000);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*who*/) override
    {
        Talk(2);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_HEART_BREAKER:
                DoCast(SPELL_HEART_BREAKER);
                events.RescheduleEvent(EVENT_HEART_BREAKER, 22000);
                break;
            case EVENT_FEL_LASH:
                DoCast(SPELL_FEL_LASH);
                events.RescheduleEvent(EVENT_FEL_LASH, 32000);
                break;
            case EVENT_BEGUILING_CHARM:
                ZoneTalk(1, 0);
                DoCast(SPELL_BEGUILING_CHARM);
                events.RescheduleEvent(EVENT_BEGUILING_CHARM, 40000);
                break;
            default:
                break;
            }
        }

        if (me->HasAura(SPELL_SADIST))
        {
            checktimer = 0;
            if (checktimer <= diff)
            {
                if (Unit* victim = me->GetVictim())
                {
                    if (victim->GetGUID() != tankGUID)
                    {
                        tankGUID = victim->GetGUID();
                        me->RemoveAura(SPELL_SADIST_PROC);
                        checktimer = 500;
                    }
                }
            }
            else checktimer -= diff;
        }
        DoMeleeAttackIfReady();
    }
};

struct boss_pit_lor_vilemus : public ScriptedAI
{
    boss_pit_lor_vilemus(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->RemoveAllAuras();
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        events.RescheduleEvent(EVENT_FEL_BREATH, 20000);
        events.RescheduleEvent(EVENT_STOMP, 13000);
        events.RescheduleEvent(EVENT_DRAIN, 22000);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*who*/) override
    {
        me->RemoveAllAreaTriggers();
        Talk(SAY_KILL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FEL_BREATH:
                DoCast(SPELL_FEL_BREATH);
                events.RescheduleEvent(EVENT_FEL_BREATH, 19000);
                break;
            case EVENT_STOMP:
                DoCast(SPELL_STOMP);
                events.RescheduleEvent(EVENT_STOMP, 19000);
                break;
            case EVENT_DRAIN:
                DoCast(SPELL_DRAIN);
                events.RescheduleEvent(EVENT_DRAIN, 15400);
                break;
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct boss_occularus : public ScriptedAI
{
    boss_occularus(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->RemoveAllAuras();
        me->RemoveAllAreaTriggers();
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        events.RescheduleEvent(EVENT_SEARING_GAZE, 7000);
        events.RescheduleEvent(EVENT_GUSHING_WOUND, 10000);
        events.RescheduleEvent(EVENT_LASH, 45500);
        events.RescheduleEvent(EVENT_EYE_SORE, 24000);
        events.RescheduleEvent(EVENT_PHANTASM, 27000);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*who*/) override
    {
        me->RemoveAllAreaTriggers();
        Talk(SAY_KILL);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_PHANTASM)
        {
            Position pos;
            float dist = 0.0f;

            for (uint8 i = 0; i < 4; ++i)
            {
                dist += 2.0f;
                target->GetNearPosition(dist, 0.0f);
                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_PHANTASM_TRIGGER, true);
            }
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SEARING_GAZE:
                if (auto target = me->GetVictim())
                    DoCast(target, SPELL_SEARING_GAZE, false);
                events.RescheduleEvent(EVENT_SEARING_GAZE, 10000);
                break;
            case EVENT_GUSHING_WOUND:
                if (auto target = me->GetVictim())
                    DoCast(target, SPELL_GUSHING_WOUND, false);
                events.RescheduleEvent(EVENT_GUSHING_WOUND, 11000);
            case EVENT_LASH:
                if (auto target = me->GetVictim())
                    DoCast(target, SPELL_LASH, false);
                events.RescheduleEvent(EVENT_LASH, 18000);
                break;
            case EVENT_EYE_SORE:
                DoCast(SPELL_EYE_SORE);
                break;
            case EVENT_PHANTASM:
                DoCast(SPELL_PHANTASM);
                events.RescheduleEvent(EVENT_PHANTASM, 39000);
                break;
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct boss_inquisitor_meto : public ScriptedAI
{
    boss_inquisitor_meto(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->RemoveAllAuras();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        events.RescheduleEvent(EVENT_REAP, 8000);
        events.RescheduleEvent(EVENT_SOW, 5000);
        events.RescheduleEvent(EVENT_DEATH_FIELD, 12000);
        events.RescheduleEvent(EVENT_SEEDS_OF_CHAOS, 26000);
    }

    void JustDied(Unit* /*who*/) override
    {
        me->RemoveAllAreaTriggers();
        Talk(SAY_KILL);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_REAP:
                DoCast(SPELL_REAP);
                events.RescheduleEvent(EVENT_REAP, 20000);
                break;
            case EVENT_SOW:
                DoCast(SPELL_SOW);
                DoCast(SPELL_SOW_DMG);
                events.RescheduleEvent(EVENT_SOW, 15000);
                break;
            case EVENT_DEATH_FIELD:
            {
                Position pos;
                float angle = me->GetAngle(me);
                for (uint8 i = 0; i < 9; i++)
                {
                    angle += 0.1f;
                    me->GetNearPosition(35.0f, angle);
                    me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_DEATH_FIELD_VISUAL, true);
                }
                DoCast(SPELL_DEATH_FIELD);
                events.RescheduleEvent(EVENT_DEATH_FIELD, 15000);
                break;
            }
            case EVENT_SEEDS_OF_CHAOS:
            {
                for (uint8 i = 0; i < 3; ++i)
                {
                    Position pos;
                    float angle = 6.28f / 3 * i;
                    me->GetNearPosition(10.0f, angle);
                    me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_SEEDS_OF_CHAOS, true);
                }
                events.RescheduleEvent(EVENT_SEEDS_OF_CHAOS, 30000);
                break;
            }
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

struct boss_sotanathor : public ScriptedAI
{
    boss_sotanathor(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
        me->RemoveAllAuras();
        me->RemoveAllAreaTriggers();
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        events.RescheduleEvent(EVENT_SOUL_CLEAVE, 17000);
        events.RescheduleEvent(EVENT_SILENCE, 23000);
        events.RescheduleEvent(EVENT_CAVITATION, 21000);
        events.RescheduleEvent(EVENT_SEED_OF_DESTRUCTION, 16000);
    }

    void JustDied(Unit* /*who*/) override
    {
        Talk(4);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_CAVITATION:
            if (target->IsPlayer() && target->IsInCombat())
            {
                Position pos;
                float angle = 0.0f;
                for (uint8 i = 0; i < 4; i++)
                {
                    target->GetNearPosition(5.0f, angle);
                    target->CastSpell(pos, SPELL_WAKE_OF_DESTRUCTION, true, 0, 0, me->GetGUID());
                    angle += 1.57f;
                }
            }
            break;
        case SPELL_SEED_OF_DESTRUCTION:
            Talk(1, target);
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() || me->HasUnitState(UNIT_STATE_CASTING))
            return;

        events.Update(diff);
        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_SOUL_CLEAVE:
                DoCast(SPELL_SOUL_CLEAVE);
                events.RescheduleEvent(SPELL_SOUL_CLEAVE, 28000);
                break;
            case EVENT_SILENCE:
                DoCast(SPELL_SILENCE);
                events.RescheduleEvent(EVENT_SILENCE, 28000);
                break;
            case EVENT_CAVITATION:
                ZoneTalk(2, 0);
                DoCast(SPELL_CAVITATION);
                events.RescheduleEvent(EVENT_CAVITATION, 27000);
                break;
            case EVENT_SEED_OF_DESTRUCTION:
                DoCast(SPELL_SEED_OF_DESTRUCTION);
                events.RescheduleEvent(EVENT_SEED_OF_DESTRUCTION, 36000);
                break;
            default:
                break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

uint32 RANDOM_GROTESQUE_SPAWN[2] =
{
    SPELL_GROTESQUE_GREEN,
    SPELL_GROTESQUE_RED
};

struct boss_matron_folnuna : public ScriptedAI
{
    boss_matron_folnuna(Creature* creature) : ScriptedAI(creature)
    {
        SetCombatMovement(false);
    }

    EventMap events;
    uint32 checktimer;
    ObjectGuid tankGUID;
    uint8 eventPhase;
    bool slimbering;

    void Reset() override
    {
        events.Reset();
        DespawnAllSummons();
        me->RemoveAllAuras();
        me->SetMaxPower(POWER_ENERGY, 100);
        me->SetPower(POWER_ENERGY, 0);
        me->SetReactState(REACT_AGGRESSIVE);
        DoCast(SPELL_INFECTED_CLAWS);
        DoCast(SPELL_POOL_OF_FIRE);

        eventPhase = 0;
        slimbering = false;
    }

    void EnterCombat(Unit* /*unit*/) override
    {
        Talk(SAY_AGGRO);
        DoCast(SPELL_NAUSEA);
        StartEvents(PHASE_1);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode();
    }

    void JustDied(Unit* /*who*/) override
    {
        DespawnAllSummons();
        Talk(SAY_KILL);
    }

    void DespawnAllSummons()
    {
        std::list<Creature*> list;
        list.clear();
        me->GetCreatureListWithEntryInGrid(list, 124552, 300.0f);
        me->GetCreatureListWithEntryInGrid(list, 124551, 300.0f);
        if (!list.empty())
            for (auto cre : list)
                cre->DespawnOrUnsummon();
    }

    void SetPower(Powers power, int32 value) 
    {
        if (power != POWER_ENERGY || !me->IsInCombat())
            return;

        if (value == 100)
        {
            if (!me->HasUnitState(UNIT_STATE_CASTING))
            {
                if (!slimbering)
                {
                    slimbering = true;
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    StartEvents(PHASE_2);

                    if (auto trigger = me->SummonCreature(124537, 4408.702f, 6490.092f, 40.38989f, 1.38464f, TEMPSUMMON_TIMED_DESPAWN, 15000))
                        DoCast(trigger, SPELL_SLIMBERING_GASP, false);

                    //me->AddDelayedCombat(500, [=]() -> void { me->SetPower(POWER_ENERGY, 0); });
                }
            }
        }
    }

    void DoAction(int32 const action) override
    {
        if (action == 1)
            StartEvents(PHASE_1);
    }

    void StartEvents(uint8 phase)
    {
        events.Reset();
        eventPhase = phase;

        switch (phase)
        {
        case PHASE_1:
            slimbering = false;
            me->SetReactState(REACT_AGGRESSIVE);
            events.RescheduleEvent(EVENT_FEL_BLAST, 2000);
            events.RescheduleEvent(EVENT_GROTESQUE_SPAWN, 8000);
            break;
        case PHASE_2:
            events.CancelEvent(EVENT_FEL_BLAST);
            events.CancelEvent(EVENT_GROTESQUE_SPAWN);
            break;
        }
    }

    void SpellHitTarget(Unit* /*target*/, SpellInfo const* spell) override
    {
        switch (spell->Id)
        {
        case SPELL_GROTESQUE_SPAWN:
            auto threatlist = me->getThreatManager().getThreatList();
            if (!threatlist.empty())
            {
                auto& itr = Trinity::Containers::SelectRandomContainerElement(threatlist);

                if (Unit* target = itr->getTarget())
                    for (uint8 i = 0; i < 4; ++i)
                        target->CastSpell(me, RANDOM_GROTESQUE_SPAWN[urand(0, 1)], false, 0, 0, me->GetGUID());
            }
            break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        if (me->HasUnitState(UNIT_STATE_CASTING) && eventPhase != PHASE_2)
            return;

        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case EVENT_FEL_BLAST:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    DoCast(target, SPELL_FEL_BLAST, false);

                events.RescheduleEvent(EVENT_FEL_BLAST, 10000);
                break;
            case EVENT_GROTESQUE_SPAWN:
                DoCast(SPELL_GROTESQUE_SPAWN);
                events.RescheduleEvent(EVENT_GROTESQUE_SPAWN, 35000);
                break;
            default:
                break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

//247549
class spell_beguiling_charm : public SpellScript
{
    PrepareSpellScript(spell_beguiling_charm);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        targets.remove_if([caster](WorldObject* object) -> bool
            {
                Unit* unit = object->ToUnit();
                if (!unit)
                    return true;

                if (unit->isInFront(caster, float(M_PI) / 2))
                    return false;

                return true;
            });
    }

    void HandleDummy(SpellEffIndex /*effIndex */)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;
        Unit* target = GetHitUnit();
        if (!target)
            return;

        caster->CastSpell(target, SPELL_BEGUILING_CHARM_AURA, false);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_beguiling_charm::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_beguiling_charm::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

//247590
class spell_sadist : public AuraScript
{
    PrepareAuraScript(spell_sadist);

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();

        if (!caster)
            return;

        caster->CastSpell(caster, SPELL_SADIST_PROC, false);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_sadist::OnProc, EFFECT_0, SPELL_AURA_DUMMY);
    }
};

//247739
class spell_drain : public AuraScript
{
    PrepareAuraScript(spell_drain);

    void OnTick(AuraEffect const* /*auraEffect*/)
    {
        Unit* target = GetTarget();
        Unit* caster = GetCaster();
        if (!target)
            return;
        if (!caster)
            return;

        caster->CastSpell(target, SPELL_DRAIN_HP, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_drain::OnTick, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
    }
};


//247332
class spell_eye_sore : public SpellScript
{
    PrepareSpellScript(spell_eye_sore);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        uint32 count = 5;

        if (targets.size() > count)
            targets.resize(count);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_eye_sore::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

//247410
class spell_soul_cleave : public SpellScript
{
    PrepareSpellScript(spell_soul_cleave);

    uint8 targetsCount = 0;

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targetsCount = targets.size();
    }

    void HandleDamage(SpellEffIndex /*effectIndex*/)
    {
        if (targetsCount)
            SetHitDamage(GetHitDamage() / targetsCount);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_soul_cleave::FilterTargets, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
        OnEffectHitTarget += SpellEffectFn(spell_soul_cleave::HandleDamage, EFFECT_1, SPELL_EFFECT_SCHOOL_DAMAGE);
    }
};

//247437
class spell_argus_seed_of_destruction : public AuraScript
{
    PrepareAuraScript(spell_argus_seed_of_destruction);

    void OnRemove(AuraEffect const* aurEff, AuraEffectHandleModes /*mode*/)
    {
        if (!GetCaster() || !GetTarget() || !GetCaster()->IsInCombat() || GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Position pos;
        float angle = 0.5f;
        for (uint8 i = 0; i < 4; ++i)
        {
            GetTarget()->GetNearPosition(5.0f, angle);
            GetTarget()->CastSpell(pos, SPELL_WAKE_OF_DESTRUCTION, true);
            GetTarget()->GetNearPosition(5.0f, -angle);
            GetTarget()->CastSpell(pos, SPELL_WAKE_OF_DESTRUCTION, true);
            angle += 1.0f;
        }
    }

    void Register() override
    {
        OnEffectRemove += AuraEffectRemoveFn(spell_argus_seed_of_destruction::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

//247362
class spell_infected_claws : public AuraScript
{
    PrepareAuraScript(spell_infected_claws);

    void OnProc(AuraEffect const* aurEff, ProcEventInfo& eventInfo)
    {
        Unit* caster = GetCaster();
        if (!caster)
            return;

        if (Unit* target = caster->GetVictim())
            caster->CastSpell(target, SPELL_INFECTED_CLAWS_PROC, false);
    }

    void Register() override
    {
        OnEffectProc += AuraEffectProcFn(spell_infected_claws::OnProc, EFFECT_0, SPELL_AURA_PROC_TRIGGER_SPELL);
    }
};



struct npc_fiery_trickster : ScriptedAI
{
    npc_fiery_trickster(Creature* creature) : ScriptedAI(creature) {}

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        std::list<Player*> playerList;
        GetPlayerListInGrid(playerList, me, 300.0f);
        //Trinity::Containers::RandomResizeList(playerList, 1);
        for (std::list<Player*>::iterator itr = playerList.begin(); itr != playerList.end(); ++itr)
            if (!playerList.empty())
                me->AI()->AttackStart((*itr));

        events.RescheduleEvent(1, 2000);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, 200.0f, true))
                    DoCast(target, SPELL_FEL_FIREBOLT, false);
                events.RescheduleEvent(1, 2500);
                break;
            }
        }
    }
};

struct npc_felblaze_maniacr : ScriptedAI
{
    npc_felblaze_maniacr(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    EventMap events;

    void Reset() override
    {
        events.Reset();
    }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(SPELL_SCORCHING_PRESENCE);
        me->GetMotionMaster()->MoveRandom(5.0f);
        events.RescheduleEvent(1, 2500);
    }

    void UpdateAI(uint32 diff) override
    {
        events.Update(diff);

        if (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
            case 1:
                me->GetMotionMaster()->MoveRandom(5.0f);
                events.RescheduleEvent(1, 2500);
                break;
            }
        }
    }
};

//124537
struct npc_slumbering_gasp : ScriptedAI
{
    npc_slumbering_gasp(Creature* creature) : ScriptedAI(creature)
    {
        me->SetReactState(REACT_PASSIVE);
    }

    void Reset() override
    {
        me->GetMotionMaster()->MovePath(124537, false);
    }
};

//247441
class spell_folnuna_nausea : public AuraScript
{
    PrepareAuraScript(spell_folnuna_nausea);

    uint8 power{};
    std::vector<uint32> energy = { 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 1, 1 };
    uint32 i = 0;

    void Tick(AuraEffect const* aurEff)
    {
        if (auto folnuna = GetCaster()->ToCreature())
        {
            power = folnuna->GetPower(POWER_ENERGY);
            folnuna->SetPower(POWER_ENERGY, power + energy[i]);
        }
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_folnuna_nausea::Tick, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

 //247069
class spell_enter_rift : public SpellScript
{
    PrepareSpellScript(spell_enter_rift);

    SpellCastResult CheckCast()
    {
        if (Player* player = GetCaster()->ToPlayer())
        {
            if (player->FindNearestCreature(125849, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(126547, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                        return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(126593, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                       return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(126499, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                        return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(126120, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                        return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(125863, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48107))
                        return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127531, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127536, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127533, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127535, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127532, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else if (player->FindNearestCreature(127528, 10.0f) && !player->IsGameMaster())
            {
                if (player->GetQuestRewardStatus(48513))
                    return SPELL_CAST_OK;
            }
            else
                return SPELL_CAST_OK;
        }

        SetCustomCastResultMessage(SPELL_CUSTOM_ERROR_CANT_CAST_THAT_RIGHT_NOW);
        return SPELL_FAILED_CUSTOM_ERROR;
    }

    void HandleScript(SpellEffIndex /*effIndex*/)
    {
        Player* player = GetCaster()->ToPlayer();
        if (!player)
            return;

        // Invasion Points World Bosses
        if (player->FindNearestCreature(127531, 10.0f))
            player->TeleportTo(1779, -9893.78f, -4994.144f, 128.9254f, 0.94049f);
        else if (player->GetZoneId() == 9296)
            player->TeleportTo(1669, -2472.86f, 9164.73f, -158.6602f, 4.78481f);
        else if (player->FindNearestCreature(127536, 10.0f))
            player->TeleportTo(1779, 5276.58f, -9767.488f, 9.806942f, 1.15248f);
        else if (player->GetZoneId() == 9300)
            player->TeleportTo(1669, -2686.8990f, 8990.405f, -137.7017f, 0.73607f);
        else if (player->FindNearestCreature(127533, 10.0f))
            player->TeleportTo(1779, -10027.7265f, 2789.3244f, 18.655104f, 5.460755f);
        else if (player->GetZoneId() == 9298)
            player->TeleportTo(1669, -2921.87f, 9390.2724f, -161.97367f, 2.11761f);
        else if (player->FindNearestCreature(127535, 10.0f))
            player->TeleportTo(1779, 5702.83f, -1427.244f, 25.7616f, 4.14519f);
        else if (player->GetZoneId() == 9297)
            player->TeleportTo(1669, -3228.58f, 9115.177f, -164.4702f, 2.28962f);
        else if (player->FindNearestCreature(127532, 10.0f))
            player->TeleportTo(1779, -1398.3713f, 8368.603f, 90.93035f, 2.95033f);
        else if (player->GetZoneId() == 9299)
            player->TeleportTo(1669, 5529.8891f, 10086.2578f, -90.1988f, 0.95757f);
        else if (player->FindNearestCreature(127528, 10.0f))
            player->TeleportTo(1779, 4478.4077f, 6588.98f, 41.9538f, 3.08555f);
        else if (player->GetZoneId() == 9295)
            player->TeleportTo(1669, 2025.9199f, 1506.299f, 408.5905f, 5.33963f);

        // Insavion Points
        else if (player->FindNearestCreature(126547, 10.0f))
            player->TeleportTo(1779, -3791.71f, -8176.95f, 10.38279f, 0.967909f);
        else if (player->GetZoneId() == 9180)
        {
            if (sGameEventMgr->IsActiveEvent(112))
                player->TeleportTo(1669, 6200.979f, 9566.7851f, -80.97315f, 3.506402f);
            else if (sGameEventMgr->IsActiveEvent(119))
                player->TeleportTo(1669, -2229.58f, 9368.0429f, -62.1973f, 4.82296f);
        }
        else if (player->FindNearestCreature(125849, 10.0f))
            player->TeleportTo(1779, -4027.05f, -4973.6f, 129.74f, 1.55695f);
        else if (player->GetZoneId() == 9100)
        {
            if (sGameEventMgr->IsActiveEvent(113))
                player->TeleportTo(1669, -3359.614f, 9068.9697f, -169.6225f, 5.15407f);
            else if (sGameEventMgr->IsActiveEvent(118))
                player->TeleportTo(1669, 6343.798f, 10271.27f, 36.76093f, 4.09881f);
        }
        else if (player->FindNearestCreature(126120, 10.0f))
            player->TeleportTo(1779, 746.3156f, 727.73101f, 41.13044f, 3.67524f);
        else if (player->GetZoneId() == 9126)
        {
            if (sGameEventMgr->IsActiveEvent(110))
                player->TeleportTo(1669, 647.5516f, 1222.51f, 441.88827f, 0.25902f);
            else if (sGameEventMgr->IsActiveEvent(116))
                player->TeleportTo(1669, -2761.37f, 9217.5722f, -170.2415f, 4.81119f);
        }
        else if (player->FindNearestCreature(126499, 10.0f))
            player->TeleportTo(1779, -4156.705f, 652.0654f, 16.91975f, 5.70575f);
        else if (player->GetZoneId() == 9127)
        {
            if (sGameEventMgr->IsActiveEvent(111))
                player->TeleportTo(1669, -3257.6542f, 8791.98f, -151.2981f, 5.64684f);
            else if (sGameEventMgr->IsActiveEvent(115))
                player->TeleportTo(1669, 749.7797f, 2010.853f, 389.763f, 6.19852f);
        }
        else if (player->FindNearestCreature(126593, 10.0f))
            player->TeleportTo(1779, -1762.29f, -1423.4097f, 27.41837f, 4.59284f);
        else if (player->GetZoneId() == 9102)
        {
            if (sGameEventMgr->IsActiveEvent(110))
                player->TeleportTo(1669, -2457.0305f, 9379.4101f, -128.84635f, 4.981937f);
            else if (sGameEventMgr->IsActiveEvent(114))
                player->TeleportTo(1669, 5774.88f, 9258.8242f, -30.23626f, 2.43533f);
        }
        else if (player->FindNearestCreature(125863, 10.0f))
            player->TeleportTo(1779, -1405.4796f, 900.4859f, 89.52139f, 3.31297f);
        else if (player->GetZoneId() == 9128)
        {
            if (sGameEventMgr->IsActiveEvent(117))
                player->TeleportTo(1669, 1827.7225f, 1064.06f, 499.74401f, 1.76106f);
            else if (sGameEventMgr->IsActiveEvent(111))
                player->TeleportTo(1669, -2560.2529f, 8992.1601f, -139.5325f, 3.64879f);
        }

    }

    void Register() override
    {
        OnCheckCast += SpellCheckCastFn(spell_enter_rift::CheckCast);
        OnEffectHitTarget += SpellEffectFn(spell_enter_rift::HandleScript, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};


struct at_seeds_of_chaos : AreaTriggerAI
{
    at_seeds_of_chaos(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) {}

    bool OnPlayerEnter = false;
    uint32 scaleTimer = 1000;

    void OnUnitEnter(Unit* player) override
    {
        if (!player->IsPlayer())
            return;

        OnPlayerEnter = true;
    }

    void OnUnitExit(Unit* player) override
    {
        if (!player->IsPlayer())
            return;

        OnPlayerEnter = false;
    }
};

void AddSC_zone_argus()
{
    RegisterCreatureAI(boss_mistress_alluradel);
    RegisterCreatureAI(boss_pit_lor_vilemus);
    RegisterCreatureAI(boss_occularus);
    RegisterCreatureAI(boss_inquisitor_meto);
    RegisterCreatureAI(boss_sotanathor);
    RegisterCreatureAI(boss_matron_folnuna);
    RegisterCreatureAI(npc_fiery_trickster);
    RegisterCreatureAI(npc_felblaze_maniacr);
    RegisterCreatureAI(npc_slumbering_gasp);
    RegisterSpellScript(spell_beguiling_charm);
    RegisterSpellScript(spell_eye_sore);
    RegisterSpellScript(spell_soul_cleave);
    RegisterSpellScript(spell_enter_rift);
    RegisterAuraScript(spell_sadist);
    RegisterAuraScript(spell_drain);
    RegisterAuraScript(spell_argus_seed_of_destruction);
    RegisterAuraScript(spell_infected_claws);
    RegisterAuraScript(spell_folnuna_nausea);
    RegisterAreaTriggerAI(at_seeds_of_chaos);
}
