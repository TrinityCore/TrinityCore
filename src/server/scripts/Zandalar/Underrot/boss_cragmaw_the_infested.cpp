/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "CreatureAI.h"
#include "CreatureAIImpl.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellAuras.h"
#include "SharedDefines.h"
#include "TemporarySummon.h"
#include "underrot.h"

enum CragmawSpells
{
    // Cragmaw
    SPELL_CRAWG_EATING                  = 279156,
    SPELL_POWER_DISPLAY_TANTRUM         = 271771,
    SPELL_POWER_ENERGIZE_TANTRUM        = 271775,
    SPELL_CHARGE_SELECTOR               = 260292,
    SPELL_INDIGESTION                   = 260793,
    SPELL_TANTRUM_INITIAL               = 260333,

    // Larva
    SPELL_DESTROY_LARVA                 = 260418,
    SPELL_METAMORPHOSIS_2               = 260766,
    SPELL_SUMMON_BLOOD_TICK             = 260353,
    SPELL_SUMMON_BLOOD_TICK_VISUAL      = 260496,

    // Blood Tick
    SPELL_BLOOD_BURST_DAMAGE            = 278637,
    SPELL_SERRATED_FANGS                = 260455,

    // Fetid Maggot
    SPELL_FEIGN_DEATH                   = 159474
};

enum CragmawEvents
{
    // Cragmaw
    EVENT_CHARGE_SELECTOR       = 1,
    EVENT_INDIGESTION,
    EVENT_NORMAL_REQUEUE,
    EVENT_CHECK_ENERGY_TANTRUM,

    // Blood Tick
    EVENT_SERRATED_FANGS        = 1
};

enum CragmawPoints
{
    POINT_TANTRUM_START_RND_MOVEMENT    = 0
};

enum CragmawNPC
{
    NPC_FETID_MAGGOT    = 130909
};

Position const FetidMaggotSpawn = { 857.864f, 984.981f, 39.231f, 4.68147f };

// 131817 - Cragmaw the Infested
struct boss_cragmaw_the_infested : public BossAI
{
    boss_cragmaw_the_infested(Creature* creature) : BossAI(creature, DATA_CRAGMAW_THE_INFESTED) { }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void JustAppeared() override
    {
        me->SetPowerType(POWER_ENERGY);
        DoCast(SPELL_POWER_DISPLAY_TANTRUM);

        if (instance->GetData(DATA_CRAGMAW_CRAWG_EATING))
            return;

        DoCastSelf(SPELL_CRAWG_EATING);
        me->SetEmoteState(EMOTE_STATE_EAT);
        if (TempSummon* summon = me->SummonCreature(NPC_FETID_MAGGOT, FetidMaggotSpawn))
        {
            _fetidMaggotGuid = summon->GetGUID();
            summon->CastSpell(nullptr, SPELL_FEIGN_DEATH, true);
        }
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        summons.DespawnAll();
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void ScheduleSpells()
    {
        events.Reset();

        if (GetDifficulty() == DIFFICULTY_NORMAL)
            events.ScheduleEvent(EVENT_NORMAL_REQUEUE, 45s);

        if (urand(0, 1) == 0)
        {
            events.ScheduleEvent(EVENT_CHARGE_SELECTOR, 9s);
            events.ScheduleEvent(EVENT_INDIGESTION, 20s);
            events.ScheduleEvent(EVENT_CHARGE_SELECTOR, 33s);
        }
        else
        {
            events.ScheduleEvent(EVENT_INDIGESTION, 9s);
            events.ScheduleEvent(EVENT_CHARGE_SELECTOR, 21s);
            events.ScheduleEvent(EVENT_CHARGE_SELECTOR, 41s);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);
        instance->SetData(DATA_CRAGMAW_CRAWG_EATING, 1);
        ScheduleSpells();
        events.ScheduleEvent(EVENT_CHECK_ENERGY_TANTRUM, 500ms);

        if (Creature* fetidMaggot = ObjectAccessor::GetCreature(*me, _fetidMaggotGuid))
            fetidMaggot->DespawnOrUnsummon();

        if (IsHeroicOrHigher())
            DoCast(SPELL_POWER_ENERGIZE_TANTRUM);
    }

    void MovementInform(uint32 /*type*/, uint32 id) override
    {
        if (id == POINT_TANTRUM_START_RND_MOVEMENT)
            me->GetMotionMaster()->MoveRandom(20.0f);
    }

    void OnChannelFinished(SpellInfo const* spell) override
    {
        if (spell->Id == SPELL_TANTRUM_INITIAL)
            me->SetReactState(REACT_AGGRESSIVE);
    };

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        switch (events.ExecuteEvent())
        {
            case EVENT_CHARGE_SELECTOR:
                DoCast(SPELL_CHARGE_SELECTOR);
                break;
            case EVENT_INDIGESTION:
                DoCast(SPELL_INDIGESTION);
                break;
            case EVENT_NORMAL_REQUEUE:
                ScheduleSpells();
                break;
            case EVENT_CHECK_ENERGY_TANTRUM:
                if (me->GetPower(POWER_ENERGY) >= 100)
                {
                    ScheduleSpells();
                    DoCast(SPELL_TANTRUM_INITIAL);
                    me->SetReactState(REACT_PASSIVE);
                    me->GetMotionMaster()->MovePoint(POINT_TANTRUM_START_RND_MOVEMENT, me->GetHomePosition());
                }
                events.Repeat(500ms);
                break;
            default:
                break;
        }
    }
private:
    ObjectGuid _fetidMaggotGuid;
};

// 132051 - Blood Tick
struct npc_cragmaw_blood_tick : public ScriptedAI
{
    npc_cragmaw_blood_tick(Creature* creature) : ScriptedAI(creature) { }

    void JustAppeared() override
    {
        Creature* cragmaw = me->GetInstanceScript()->GetCreature(DATA_CRAGMAW_THE_INFESTED);
        if (!cragmaw || !cragmaw->IsAIEnabled())
            return;

        cragmaw->AI()->JustSummoned(me);
        DoZoneInCombat();
    }

    void JustEngagedWith(Unit* /*who*/) override
    {
        _events.ScheduleEvent(EVENT_SERRATED_FANGS, 1s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING) || me->HasUnitState(UNIT_STATE_STUNNED))
            return;

        switch (_events.ExecuteEvent())
        {
            case EVENT_SERRATED_FANGS:
                DoCastVictim(SPELL_SERRATED_FANGS);
                _events.ScheduleEvent(EVENT_SERRATED_FANGS, 6s);
                break;
            default:
                break;
        }
    }
private:
    EventMap _events;
};

// 271775 - Tantrum Energy Bar (periodic)
class spell_cragmaw_power_energize_tantrum : public AuraScript
{
    void HandlePeriodic(AuraEffect const* /*aurEff*/)
    {
        Unit* target = GetTarget();
        target->SetPower(POWER_ENERGY, target->GetPower(POWER_ENERGY) + 2);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_cragmaw_power_energize_tantrum::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
    }
};

// 260411 - Summon Larva
class spell_cragmaw_summon_larva : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (Creature* creature = GetTarget()->ToCreature())
            creature->DespawnOrUnsummon(300ms);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_cragmaw_summon_larva::OnRemove, EFFECT_0, SPELL_AURA_AREA_TRIGGER, AURA_EFFECT_HANDLE_REAL);
    }
};

// 260418 - Destroy Larva
struct at_cragmaw_destroy_larva : AreaTriggerAI
{
    at_cragmaw_destroy_larva(AreaTrigger* areatrigger) : AreaTriggerAI(areatrigger) { }

    void OnUnitEnter(Unit* unit) override
    {
        if (!unit->IsPlayer())
            return;

        at->GetCaster()->CastSpell(nullptr, SPELL_DESTROY_LARVA, true);
    }
};

// 260416 - Metamorphosis
class spell_cragmaw_larva_metamorphosis : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo(
        {
            SPELL_SUMMON_BLOOD_TICK,
            SPELL_SUMMON_BLOOD_TICK_VISUAL,
            SPELL_METAMORPHOSIS_2
        });
    }

    void HandlePeriodic(AuraEffect const* aurEff)
    {
        if (aurEff->GetTickNumber() == aurEff->GetTotalTicks() - 2)
            GetTarget()->CastSpell(nullptr, SPELL_METAMORPHOSIS_2, true);
    }

    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetTargetApplication()->GetRemoveMode() != AURA_REMOVE_BY_EXPIRE)
            return;

        Unit* target = GetTarget();
        target->CastSpell(nullptr, SPELL_SUMMON_BLOOD_TICK_VISUAL, true);
        target->CastSpell(target->GetPosition(), SPELL_SUMMON_BLOOD_TICK, true);
    }

    void Register() override
    {
        OnEffectPeriodic += AuraEffectPeriodicFn(spell_cragmaw_larva_metamorphosis::HandlePeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY);
        AfterEffectRemove += AuraEffectRemoveFn(spell_cragmaw_larva_metamorphosis::OnRemove, EFFECT_0, SPELL_AURA_PERIODIC_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

// 278641 - Blood Burst
class spell_cragmaw_blood_burst : public AuraScript
{
    void OnRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        Unit* target = GetTarget();
        target->CastSpell(target, SPELL_BLOOD_BURST_DAMAGE, true);
    }

    void Register() override
    {
        AfterEffectRemove += AuraEffectRemoveFn(spell_cragmaw_blood_burst::OnRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};

void AddSC_boss_cragmaw_the_infested()
{
    // Creature
    RegisterUnderrotCreatureAI(boss_cragmaw_the_infested);
    RegisterUnderrotCreatureAI(npc_cragmaw_blood_tick);

    // Spells
    RegisterSpellScript(spell_cragmaw_power_energize_tantrum);
    RegisterSpellScript(spell_cragmaw_larva_metamorphosis);
    RegisterSpellScript(spell_cragmaw_blood_burst);
    RegisterSpellScript(spell_cragmaw_summon_larva);

    // AreaTrigger
    RegisterAreaTriggerAI(at_cragmaw_destroy_larva);
}
