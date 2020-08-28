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

#include "stonecore.h"
#include "ScriptMgr.h"
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "PassiveAI.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"

enum Spells
{
    SPELL_FACE_RANDOM_PLAYER        = 82530,

    // Slabhide
    SPELL_LAVA_FISSURE              = 80803,
    SPELL_SAND_BLAST                = 80807,
    SPELL_STALACTITE_SUMMON         = 80656,
    SPELL_COOLDOWN_5S               = 95323,
    SPELL_CRYSTAL_STORM_PERIODIC    = 92305,
    SPELL_CRYSTAL_STORM             = 92265,

    // Lava Fissure
    SPELL_LAVA_FISSURE_CRACK        = 80798,
    SPELL_LAVA_FISSURE_ERUPTION     = 80800,

    // Stalactite Trigger
    SPELL_STALACTITE_SUMMON_TRIGGER = 81028,
    SPELL_STALACTITE_SHADE          = 80654,
    SPELL_STALACTITE_MISSILE        = 80643,
    SPELL_STALACTITE_MISSILE_HC     = 92653,
    SPELL_STALACTITE_CREATE         = 80647
};

enum Actions
{
    ACTION_STALACTITE_MISSLE = 0
};

enum Events
{
    // Slabhide
    EVENT_LAND_INTRO = 1,
    EVENT_HANDLE_ROCK_WALLS,
    EVENT_LAVA_FISSURE,
    EVENT_SAND_BLAST,
    EVENT_AIR_PHASE,
    EVENT_LAND,
    EVENT_ATTACK,

    // Lava Fissure
    EVENT_LAVA_FISSURE_ERUPTION,

    // Stalactite Trigger - Boss
    EVENT_STALACTITE_MISSLE
};

enum Phases
{
    PHASE_INTRO     = 0,
    PHASE_COMBAT    = 1
};

enum MovementPoints
{
    POINT_SLABHIDE_INTRO = 1,
    POINT_SLABHIDE_INTRO_LAND,

    POINT_SLABHIDE_MIDDLE,
    POINT_SLABHIDE_IN_AIR,
    POINT_SLABHIDE_LAND
};

Position const SlabhideIntroPos = { 1292.27f, 1226.16f, 265.573f };
Position const SlabhideIntroLandPos = { 1292.352f, 1226.478f, 247.6368f, 3.630285f };

Position const SlabhideMiddlePos = { 1280.73f, 1212.31f, 247.3837f };
Position const SlabhideInAirPos = { 1280.73f, 1212.31f, 257.3837f };
Position const SlabhideLandPos = { 1282.7f, 1229.77f, 247.155f, 3.82227f };

struct boss_slabhide : public BossAI
{
    boss_slabhide(Creature* creature) : BossAI(creature, DATA_SLABHIDE), _isFlying(false) { }

    void InitializeAI() override
    {
        if (instance->GetData(DATA_EVENT_PROGRESS) == EVENT_INDEX_SLABHIDE_INTRO)
        {
            me->SetDisableGravity(false);
            me->SetHover(false);
        }
        else
        {
            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
            me->SetDisableGravity(true);
            me->SetHover(true);
            me->SetReactState(REACT_PASSIVE);
            events.SetPhase(PHASE_INTRO);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (_isFlying && damage >= me->GetHealth())
            damage = me->GetHealth() - 1; // Let creature health fall to 1 hp but prevent it from dying during air phase.
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        events.SetPhase(PHASE_COMBAT);
        events.ScheduleEvent(EVENT_HANDLE_ROCK_WALLS, 4s);
        events.ScheduleEvent(EVENT_LAVA_FISSURE, 6s, 8s);
        events.ScheduleEvent(EVENT_SAND_BLAST, 8s, 10s);
        events.ScheduleEvent(EVENT_AIR_PHASE, 10s);
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        _EnterEvadeMode();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        instance->SetBossState(DATA_SLABHIDE, FAIL);
        DespawnAll();
        summons.DespawnAll();
        me->DespawnOrUnsummon();
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        DespawnAll();
    }

    void DoAction(int32 action) override
    {
        switch (action)
        {
            case ACTION_SLABHIDE_INTRO:
                me->setActive(true);
                me->GetMotionMaster()->MovePoint(POINT_SLABHIDE_INTRO, SlabhideIntroPos, false);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
            return;

        switch (id)
        {
            case POINT_SLABHIDE_INTRO:
                me->SetFacingTo(SlabhideIntroLandPos.GetOrientation());
                events.ScheduleEvent(EVENT_LAND_INTRO, 200ms, 0, PHASE_INTRO);
                break;
            case POINT_SLABHIDE_INTRO_LAND:
                me->setActive(false);
                me->SetDisableGravity(false);
                me->SetHover(false);
                me->SetHomePosition(SlabhideIntroLandPos);
                me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                me->SetReactState(REACT_AGGRESSIVE);
                break;
            case POINT_SLABHIDE_MIDDLE:
                _isFlying = true;
                me->GetMotionMaster()->MoveTakeoff(POINT_SLABHIDE_IN_AIR, SlabhideInAirPos);
                break;
            case POINT_SLABHIDE_IN_AIR:
                me->SetDisableGravity(true);
                me->SetHover(true);
                DoCastSelf(SPELL_STALACTITE_SUMMON);
                events.ScheduleEvent(EVENT_LAND, 8s);
                break;
            case POINT_SLABHIDE_LAND:
                _isFlying = false;
                me->SetDisableGravity(false);
                me->SetHover(false);
                DoCastSelf(SPELL_COOLDOWN_5S);
                events.ScheduleEvent(EVENT_ATTACK, 1s + 200ms);
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
                case EVENT_LAND_INTRO:
                    me->GetMotionMaster()->MoveLand(POINT_SLABHIDE_INTRO_LAND, SlabhideIntroLandPos);
                    break;
                case EVENT_HANDLE_ROCK_WALLS:
                    instance->SetData(DATA_SLABHIDE_ROCK_WALL, false);
                    break;
                case EVENT_LAVA_FISSURE:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                        DoCast(target, SPELL_LAVA_FISSURE);
                    events.Repeat(6s, 8s);
                    break;
                case EVENT_SAND_BLAST:
                    DoCast(me, SPELL_SAND_BLAST);
                    events.Repeat(8s, 11s);
                    break;
                case EVENT_AIR_PHASE:
                    events.Reset();
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    me->GetMotionMaster()->MovePoint(POINT_SLABHIDE_MIDDLE, SlabhideMiddlePos);
                    events.Repeat(60s);
                    break;
                case EVENT_LAND:
                    me->GetMotionMaster()->MoveLand(POINT_SLABHIDE_LAND, SlabhideMiddlePos);
                    break;
                case EVENT_ATTACK:
                    events.ScheduleEvent(EVENT_LAVA_FISSURE, 6s, 8s);
                    events.ScheduleEvent(EVENT_SAND_BLAST, 8s, 10s);
                    me->SetReactState(REACT_AGGRESSIVE);
                    if (IsHeroic())
                        DoCast(me, SPELL_CRYSTAL_STORM_PERIODIC);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

private:
    void DespawnAll()
    {
        // Despawn stalactite triggers npcs
        std::vector<Creature*> listStalactiteTrigger;
        me->GetCreatureListWithEntryInGrid(listStalactiteTrigger, NPC_STALACTITE_TRIGGER, 200.0f);
        for (Creature* creature : listStalactiteTrigger)
            creature->DespawnOrUnsummon();

        // Despawn stalactite objects
        std::vector<GameObject*> listStalactite;
        me->GetGameObjectListWithEntryInGrid(listStalactite, GO_STALACTITE, 200.0f);
        for (GameObject* go : listStalactite)
            go->Delete();
    }

    bool _isFlying;
};

struct npc_slabhide_lava_fissure : public NullCreatureAI
{
    npc_slabhide_lava_fissure(Creature* creature) : NullCreatureAI(creature) { }

    void JustAppeared() override
    {
        DoCast(me, SPELL_LAVA_FISSURE_CRACK);
        bool isHeroic = me->GetMap()->IsHeroic();
        _events.ScheduleEvent(EVENT_LAVA_FISSURE_ERUPTION, isHeroic ? 3s : 5s);
        me->DespawnOrUnsummon(isHeroic ? 33s : 15s);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_LAVA_FISSURE_ERUPTION:
                    me->RemoveAurasDueToSpell(SPELL_LAVA_FISSURE_CRACK);
                    DoCast(me, SPELL_LAVA_FISSURE_ERUPTION);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

struct npc_slabhide_stalactite_trigger : public NullCreatureAI
{
    npc_slabhide_stalactite_trigger(Creature* creature) : NullCreatureAI(creature) { }

    void IsSummonedBy(Unit* /*summoner*/) override
    {
        DoCast(me, SPELL_STALACTITE_SHADE, true);
        _events.ScheduleEvent(EVENT_STALACTITE_MISSLE, 1s + 300ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STALACTITE_MISSLE:
                    DoCastSelf(SPELL_STALACTITE_MISSILE);
                    me->DespawnOrUnsummon(11s);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
};

class spell_slabhide_stalactite : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_STALACTITE_SUMMON_TRIGGER });
    }

    void SummonStalactiteTrigger()
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_STALACTITE_SUMMON_TRIGGER, true);
    }

    void Register() override
    {
        OnHit.Register(&spell_slabhide_stalactite::SummonStalactiteTrigger);
    }
};

class spell_slabhide_stalactite_summon : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 55.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect.Register(&spell_slabhide_stalactite_summon::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class spell_slabhide_stalactite_dest_relocation : public SpellScript
{
    void SetDest(SpellDestination& dest)
    {
        if (Unit* caster = GetCaster())
        {
            float x = dest._position.GetPositionX();
            float y = dest._position.GetPositionY();
            float z = dest._position.GetPositionZ();
            float ground = caster->GetMap()->GetStaticHeight(caster->GetPhaseShift(), x, y, z - 40.0f);

            dest.RelocateOffset({ 0.0f, 0.0f, ground - z, 0.0f });
        }
    }

    void Register()
    {
        OnDestinationTargetSelect.Register(&spell_slabhide_stalactite_dest_relocation::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_slabhide_crystal_storm_periodic : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_CRYSTAL_STORM });
    }

    void HandleDummy(SpellEffIndex /*eff*/)
    {
        if (Unit* caster = GetCaster())
            caster->CastSpell(caster, SPELL_CRYSTAL_STORM);
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_slabhide_crystal_storm_periodic::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_slabhide()
{
    RegisterStonecoreCreatureAI(boss_slabhide);
    RegisterStonecoreCreatureAI(npc_slabhide_lava_fissure);
    RegisterStonecoreCreatureAI(npc_slabhide_stalactite_trigger);
    RegisterSpellScript(spell_slabhide_stalactite);
    RegisterSpellScript(spell_slabhide_stalactite_summon);
    RegisterSpellScript(spell_slabhide_stalactite_dest_relocation);
    RegisterSpellScript(spell_slabhide_crystal_storm_periodic);
}
