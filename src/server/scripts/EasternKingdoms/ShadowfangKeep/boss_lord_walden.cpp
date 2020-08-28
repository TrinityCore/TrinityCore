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

#include "shadowfang_keep.h"
#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellAuras.h"
#include "SpellAuraEffects.h"
#include "Player.h"
#include "InstanceScript.h"
#include "MotionMaster.h"

enum Texts
{
    SAY_AGGRO   = 0,
    SAY_SLAY    = 1,
    SAY_DEATH   = 2,
    SAY_INTRO   = 3
};

enum Spells
{
    // Lord Walden
    SPELL_ICE_SHARDS                = 93527,
    SPELL_CONJURE_FROST_MIXTURE     = 93505,
    SPELL_CONJURE_POISONOUS_MIXTURE = 93697,
    SPELL_CONJURE_MYSTERY_TOXIN     = 93695,
    SPELL_FULLY_COAGULATED          = 93660,

    // Mystery Toxine
    SPELL_TOXIC_COAGULENT           = 93572,
    SPELL_TOXIC_CATALYST            = 93573,
    SPELL_TOXIC_CATALYST_AOE        = 93689,
    SPELL_SHRINK                    = 59632
};

enum Events
{
    EVENT_ICE_SHARDS = 1,
    EVENT_CONJURE_FROST_MIXTURE,
    EVENT_CONJURE_POISONOUS_MIXTURE,
    EVENT_CONJURE_MYSTERY_TOXIN,
    EVENT_CLEAR_EMOTE_STATE
};

enum Phases
{
    PHASE_INTRO     = 1,
    PHASE_COMBAT    = 2
};

enum MovePoints
{
    POINT_TALK_INTRO_1 = 4,
    POINT_TALK_INTRO_2 = 8,
    POINT_TALK_INTRO_3 = 12
};

struct boss_lord_walden : public BossAI
{
    boss_lord_walden(Creature* creature) : BossAI(creature, DATA_LORD_WALDEN) { }

    void Reset() override
    {
        BossAI::Reset();
        events.SetPhase(PHASE_INTRO);
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);

        events.SetPhase(PHASE_COMBAT);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_CONJURE_FROST_MIXTURE, 8s);
        events.ScheduleEvent(EVENT_CONJURE_POISONOUS_MIXTURE, 31s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_CONJURE_MYSTERY_TOXIN, 10s);
        else
            events.ScheduleEvent(EVENT_ICE_SHARDS, 22s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
    }

    void KilledUnit(Unit* target) override
    {
        if (target->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_MYSTERY_TOXIN:
                summon->CastSpell(summon, me->GetHealthPct() > 35.f ? SPELL_TOXIC_COAGULENT : SPELL_TOXIC_CATALYST);
                summon->m_Events.AddEventAtOffset([summon]()
                {
                    summon->RemoveAurasDueToSpell(SPELL_SHRINK);
                }, 1s + 200ms);

                if (me->GetHealthPct() <= 35.f)
                {
                    summon->m_Events.AddEventAtOffset([summon]()
                    {
                        summon->CastSpell(summon, SPELL_TOXIC_CATALYST_AOE);
                    }, 2s + 400ms);
                }
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type != WAYPOINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_TALK_INTRO_1:
                Talk(SAY_INTRO);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                events.ScheduleEvent(EVENT_CLEAR_EMOTE_STATE, 54s, 0, PHASE_INTRO);
                break;
            case POINT_TALK_INTRO_2:
                Talk(SAY_INTRO);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                events.ScheduleEvent(EVENT_CLEAR_EMOTE_STATE, 47s, PHASE_INTRO);
                break;
            case POINT_TALK_INTRO_3:
                Talk(SAY_INTRO);
                me->SetUInt32Value(UNIT_NPC_EMOTESTATE, EMOTE_STATE_USE_STANDING);
                events.ScheduleEvent(EVENT_CLEAR_EMOTE_STATE, 46s, PHASE_INTRO);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim() && !events.IsInPhase(PHASE_INTRO))
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CONJURE_FROST_MIXTURE:
                    DoCastAOE(SPELL_CONJURE_FROST_MIXTURE);
                    events.Repeat(11s);
                    break;
                case EVENT_ICE_SHARDS:
                    me->StopMoving();
                    DoCastSelf(SPELL_ICE_SHARDS);
                    if (!IsHeroic())
                        events.Repeat(45s);
                    break;
                case EVENT_CONJURE_POISONOUS_MIXTURE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                        DoCast(target, SPELL_CONJURE_POISONOUS_MIXTURE);
                    events.Repeat(31s);
                    break;
                case EVENT_CONJURE_MYSTERY_TOXIN:
                    events.RescheduleEvent(EVENT_CONJURE_FROST_MIXTURE, 18s);
                    events.ScheduleEvent(EVENT_ICE_SHARDS, 12s);
                    me->StopMoving();
                    DoCast(SPELL_CONJURE_MYSTERY_TOXIN);
                    events.Repeat(45s);
                    break;
                case EVENT_CLEAR_EMOTE_STATE:
                    me->SetUInt32Value(UNIT_NPC_EMOTESTATE, 0);
                    break;
                default:
                    break;
            }
        }
        DoMeleeAttackIfReady();
    }
};

class spell_walden_toxic_coagulent : public AuraScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_FULLY_COAGULATED });
    }

    void AfterApply(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        if (GetStackAmount() == GetSpellInfo()->StackAmount)
        {
            GetTarget()->CastSpell(GetTarget(), SPELL_FULLY_COAGULATED, true);
            Remove();
        }
    }

    void Register() override
    {
        AfterEffectApply.Register(&spell_walden_toxic_coagulent::AfterApply, EFFECT_1, SPELL_AURA_PERIODIC_DAMAGE, AURA_EFFECT_HANDLE_REAL_OR_REAPPLY_MASK);
    }
};

class spell_walden_conjure_poisonous_mixture : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_walden_conjure_poisonous_mixture::FilterTargets, EFFECT_ALL, TARGET_UNIT_DEST_AREA_ENEMY);
    }
};

class spell_walden_ice_shards : public AuraScript
{
    void HandleEffectPeriodic(AuraEffect const* aurEff)
    {
        PreventDefaultAction();
        Creature* caster = GetTarget()->ToCreature();
        if (!caster)
            return;

        if (caster->IsAIEnabled)
            if (Unit* target = caster->AI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 50.0f, true))
                caster->CastSpell(target, GetSpellInfo()->Effects[aurEff->GetEffIndex()].TriggerSpell, true);
    }

    void Register() override
    {
        OnEffectPeriodic.Register(&spell_walden_ice_shards::HandleEffectPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_TRIGGER_SPELL);
    }
};

class spell_walden_conjure_mystery_toxin : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 4.58f, 0.0f });
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_walden_conjure_mystery_toxin::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_walden_toxic_catalyst : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if([](WorldObject* obj)->bool
        {
            Unit* target = obj->ToUnit();
            return target && !target->isMoving();
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_walden_toxic_catalyst::FilterTargets, EFFECT_ALL, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_lord_walden()
{
    RegisterShadowfangKeepCreatureAI(boss_lord_walden);
    RegisterSpellScript(spell_walden_toxic_coagulent);
    RegisterSpellScript(spell_walden_conjure_poisonous_mixture);
    RegisterSpellScript(spell_walden_ice_shards);
    RegisterSpellScript(spell_walden_conjure_mystery_toxin);
    RegisterSpellScript(spell_walden_toxic_catalyst);
}
