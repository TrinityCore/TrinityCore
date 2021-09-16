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

#include "ScriptMgr.h"
#include "AreaBoundary.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "PassiveAI.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "vortex_pinnacle.h"

enum Spells
{
    // Asaad
    SPELL_STATIC_CLING                      = 87618,
    SPELL_SOTS_TARGETING                    = 86632,
    SPELL_SUMMON_SKYFALL_STAR               = 96260,
    SPELL_CHAIN_LIGHTNING                   = 87622,
    SPELL_UNSTABLE_GROUNDING_FIELD          = 86911,
    SPELL_SUPREMACY_OF_THE_STORM_TELEPORT   = 87328,
    SPELL_SUPREMACY_OF_THE_STORM            = 86930,

    // Skyfall Star
    SPELL_ARCANE_BARRAGE                    = 87845,

    // Storm Target
    SPELL_SOTS_SUMMON                       = 86658,

    // Unstable Grounding Field
    SPELL_SOTS_TRIGGER                      = 86926,
    SPELL_STORM_RUNE_BEAM_AA                = 86981,
    SPELL_STORM_RUNE_BEAM_A                 = 86921,
    SPELL_STORM_RUNE_BEAM_B                 = 86923,
    SPELL_STORM_RUNE_BEAM_C                 = 86925,
    SPELL_SUPREMACY_OF_THE_STORM_SUMMON     = 87518,

    // Grounding Field
    SPELL_GROUNDING_FIELD                   = 87514,
    SPELL_GROUNDING_FIELD_VISUAL_BEAMS      = 87517
};

enum Texts
{
    SAY_AGGRO                               = 0,
    SAY_ANNOUNCE_UNSTABLE_GROUNDING_FIELD   = 1,
    SAY_SUPREMACY_OF_THE_STORM              = 2,
    SAY_DEATH                               = 3
};

enum Events
{
    EVENT_SUPREMACY_OF_THE_STORM = 1,
    EVENT_FALL_DOWN,
    EVENT_SUMMON_SKYFALL_STAR,
    EVENT_CHAIN_LIGHTNING,
    EVENT_STATIC_CLING,

    // Unstable Grounding Field npc
    EVENT_MOVE_TO_NEXT_CORNER,
    EVENT_LINK_STORM_TARGETS,
    EVENT_FINISH_TRIANGLE
};

enum MovePoints
{
    POINT_TRIANGLE_1    = 0,
    POINT_TRIANGLE_2    = 1,
    POINT_TRIANGLE_3    = 2
};

enum Data
{
    DATA_RANDOM_STORM_TARGET    = 0,
    DATA_PREVIOUS_STORM_TARGET  = 0,
    DATA_STORM_TARGET_1         = 0,
    DATA_STORM_TARGET_2         = 1,
    DATA_STORM_TARGET_3         = 2
};

float const TRIANGLE_Z      = 646.7143f;
float const TRIANGLE_TOP_Z  = 654.7143f;

static uint8 const MaxStormTargetTrios = 13;
static uint8 const MaxStormTargetTrianglePoints = 3;

static std::array<Position, 39> StormTargetSummonPositions = 
{
    Position(-633.771f, 490.976f, TRIANGLE_Z, 3.141593f),
    Position(-625.688f, 501.934f, TRIANGLE_Z, 3.141593f),
    Position(-620.226f, 490.892f, TRIANGLE_Z, 3.141593f),

    Position(-649.906f, 494.905f, TRIANGLE_Z, 3.141593f),
    Position(-643.214f, 503.953f, TRIANGLE_Z, 3.141593f),
    Position(-640.542f, 487.474f, TRIANGLE_Z, 3.141593f),

    Position(-637.839f, 516.186f, TRIANGLE_Z, 1.099557f),
    Position(-634.068f, 507.51f,  TRIANGLE_Z, 1.099557f),
    Position(-650.894f, 509.323f, TRIANGLE_Z, 1.099557f),

    Position(-637.01f,  530.09f,  TRIANGLE_Z, 1.099557f),
    Position(-632.167f, 521.153f, TRIANGLE_Z, 1.099557f),
    Position(-646.939f, 519.566f, TRIANGLE_Z, 1.099557f),

    Position(-628.512f, 516.988f, TRIANGLE_Z, 1.099557f),
    Position(-622.184f, 507.908f, TRIANGLE_Z, 1.099557f),
    Position(-633.148f, 499.762f, TRIANGLE_Z, 1.099557f),

    Position(-615.528f, 515.944f, TRIANGLE_Z, 1.099557f),
    Position(-609.41f,  504.675f, TRIANGLE_Z, 1.099557f),
    Position(-618.748f, 501.946f, TRIANGLE_Z, 1.099557f),

    Position(-600.986f, 522.576f, TRIANGLE_Z, 1.099557f),
    Position(-594.96f,  507.582f, TRIANGLE_Z, 1.099557f),
    Position(-605.094f, 509.141f, TRIANGLE_Z, 1.099557f),

    Position(-617.269f, 521.168f, TRIANGLE_Z, 0.0f),
    Position(-606.75f,  530.002f, TRIANGLE_Z, 0.0f),
    Position(-608.832f, 515.175f, TRIANGLE_Z, 0.0f),

    Position(-627.957f, 529.927f, TRIANGLE_Z, 0.0f),
    Position(-616.997f, 530.564f, TRIANGLE_Z, 0.0f),
    Position(-621.91f,  517.644f, TRIANGLE_Z, 0.0f),

    Position(-604.839f, 485.186f, TRIANGLE_Z, 3.141593f),
    Position(-616.885f, 496.186f, TRIANGLE_Z, 3.141593f),
    Position(-606.833f, 500.078f, TRIANGLE_Z, 3.141593f),

    Position(-600.387f, 482.604f, TRIANGLE_Z, 3.141593f),
    Position(-602.899f, 497.245f, TRIANGLE_Z, 3.141593f),
    Position(-592.599f, 500.392f, TRIANGLE_Z, 3.141593f),

    Position(-622.946f, 483.113f, TRIANGLE_Z, 3.141593f),
    Position(-613.104f, 488.776f, TRIANGLE_Z, 3.141593f),
    Position(-606.915f, 477.097f, TRIANGLE_Z, 3.141593f),

    Position(-640.717f, 480.623f, TRIANGLE_Z, 3.141593f),
    Position(-627.049f, 486.917f, TRIANGLE_Z, 3.141593f),
    Position(-623.059f, 476.104f, TRIANGLE_Z, 3.141593f)
};

struct boss_asaad : public BossAI
{
    boss_asaad(Creature* creature) : BossAI(creature, DATA_ASAAD),  _selectedStormTargetTrio(0), _stormTargetTrioIndex(0)
    {
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me, 1);

        for (uint8 i = 0; i < StormTargetSummonPositions.size(); ++i)
        {
            uint8 stormTargetTrioIndex = i / MaxStormTargetTrianglePoints;
            if (Creature* creature = DoSummon(NPC_STORM_TARGET, StormTargetSummonPositions[i]))
            {
                uint8 stormTargetTriangleIndex = i % MaxStormTargetTrianglePoints;
                _stormTargetData[stormTargetTrioIndex][stormTargetTriangleIndex] = creature->GetGUID();
            }
        }

        events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 10s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_STATIC_CLING, 10s);
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 14s);
        events.ScheduleEvent(EVENT_SUPREMACY_OF_THE_STORM, 18s);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        FallDown();
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
    }

    void JustSummoned(Creature* summon) override
    {
        summons.Summon(summon);

        switch (summon->GetEntry())
        {
            case NPC_UNSTABLE_GROUNDING_FIELD:
                me->AttackStop();
                me->SetReactState(REACT_PASSIVE);
                Talk(SAY_ANNOUNCE_UNSTABLE_GROUNDING_FIELD, summon);
                Talk(SAY_SUPREMACY_OF_THE_STORM, summon);
                DoCast(summon, SPELL_UNSTABLE_GROUNDING_FIELD);
                break;
            case NPC_GROUNDING_FIELD_ASAAD:
                me->InterruptNonMeleeSpells(true);
                DoCastAOE(SPELL_SUPREMACY_OF_THE_STORM_TELEPORT);
                DoCastSelf(SPELL_SUPREMACY_OF_THE_STORM);
                me->SetDisableGravity(true);
                me->SetHover(true);

                events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 12s);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_STATIC_CLING, 12s);
                events.ScheduleEvent(EVENT_FALL_DOWN, 7s);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 25s);
                events.ScheduleEvent(EVENT_SUPREMACY_OF_THE_STORM, 33s);
                break;
            case NPC_SKYFALL_STAR:
                summon->CastSpell(nullptr, SPELL_ARCANE_BARRAGE);
                break;
            default:
                break;
        }
    }

    void SetGUID(ObjectGuid const& guid, int32 type) override
    {
        switch (type)
        {
            case DATA_RANDOM_STORM_TARGET:
                for (uint8 i = 0; i < _stormTargetData.size(); ++i)
                {
                    for (uint8 j = 0; j < _stormTargetData[i].size(); ++j)
                    {
                        if (_stormTargetData[i][j] == guid)
                        {
                            _selectedStormTargetTrio = i;
                            _stormTargetTrioIndex = j;
                            break;
                        }
                    }
                }
                break;
            default:
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_STORM_TARGET_1:
            case DATA_STORM_TARGET_2:
            case DATA_STORM_TARGET_3:
                return _stormTargetData[_selectedStormTargetTrio][(_stormTargetTrioIndex + type) % MaxStormTargetTrianglePoints];
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SUPREMACY_OF_THE_STORM:
                    events.Reset();
                    DoCastAOE(SPELL_SOTS_TARGETING, CastSpellExtraArgs().AddSpellMod(SPELLVALUE_MAX_TARGETS, 1));
                    break;
                case EVENT_FALL_DOWN:
                    FallDown();
                    summons.DespawnEntry(NPC_GROUNDING_FIELD_ASAAD);
                    break;
                case EVENT_SUMMON_SKYFALL_STAR:
                    DoCastSelf(SPELL_SUMMON_SKYFALL_STAR);
                    events.Repeat(12s);
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 30.f, true))
                        DoCast(target, SPELL_CHAIN_LIGHTNING);
                    break;
                case EVENT_STATIC_CLING:
                    DoCastAOE(SPELL_STATIC_CLING);
                    events.Repeat(17s);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
private:
    std::array<std::array<ObjectGuid, MaxStormTargetTrianglePoints>, MaxStormTargetTrios> _stormTargetData;
    uint8 _selectedStormTargetTrio;
    uint8 _stormTargetTrioIndex;

    void FallDown()
    {
        if (!me->IsGravityDisabled())
            return;

        me->SetDisableGravity(false);
        me->SetHover(false);
        me->SetReactState(REACT_AGGRESSIVE);
    }
};

static std::array<uint32, MaxStormTargetTrianglePoints> StormRuneBeamSpellsGroundingField =
{
    SPELL_STORM_RUNE_BEAM_AA,
    SPELL_STORM_RUNE_BEAM_B,
    SPELL_STORM_RUNE_BEAM_C
};

static std::array<uint32, MaxStormTargetTrianglePoints> StormRuneBeamSpellsStormTarget =
{
    SPELL_STORM_RUNE_BEAM_A,
    SPELL_STORM_RUNE_BEAM_B,
    SPELL_STORM_RUNE_BEAM_C
};

struct npc_asaad_unstable_grounding_field : public NullCreatureAI
{
    npc_asaad_unstable_grounding_field(Creature* creature) : NullCreatureAI(creature), _instance(nullptr), _stormTargetIndex(0) { }

    void InitializeAI() override
    {
        _instance = me->GetInstanceScript();
    }

    void JustAppeared() override
    {
        DoCastAOE(SPELL_SOTS_TRIGGER);

        if (!_instance)
            return;

        if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
        {
            if (asaad->IsAIEnabled())
            {
                for (uint8 i = 0; i < MaxStormTargetTrianglePoints; ++i)
                    _stormTargetGUIDs[i] = asaad->AI()->GetGUID(DATA_STORM_TARGET_1 + i);

                _events.ScheduleEvent(EVENT_MOVE_TO_NEXT_CORNER, 400ms);
            }
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE)
            return;

        switch (pointId)
        {
            case POINT_TRIANGLE_1:
            case POINT_TRIANGLE_2:
                _events.ScheduleEvent(EVENT_LINK_STORM_TARGETS, 800ms);
                _events.ScheduleEvent(EVENT_MOVE_TO_NEXT_CORNER, 2s);
                break;
            case POINT_TRIANGLE_3:
                _events.ScheduleEvent(EVENT_LINK_STORM_TARGETS, 800ms);
                _events.ScheduleEvent(EVENT_FINISH_TRIANGLE, 400ms);
                break;
            default:
                break;
        }
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case DATA_PREVIOUS_STORM_TARGET:
                return _stormTargetGUIDs[_stormTargetIndex - 1];
            default:
                return ObjectGuid::Empty;
        }

        return ObjectGuid::Empty;
    }

    void JustSummoned(Creature* summon) override
    {
        switch (summon->GetEntry())
        {
            case NPC_GROUNDING_FIELD_ASAAD:
                if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
                    if (asaad->IsAIEnabled())
                        asaad->AI()->JustSummoned(summon);

                summon->CastSpell(summon, SPELL_GROUNDING_FIELD);
                summon->CastSpell(summon, SPELL_GROUNDING_FIELD_VISUAL_BEAMS);
                break;
            default:
                break;
        }
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_MOVE_TO_NEXT_CORNER:
                    me->InterruptNonMeleeSpells(true);
                    DoCast(StormRuneBeamSpellsGroundingField[_stormTargetIndex]);
                    if (Creature* stormTarget = ObjectAccessor::GetCreature(*me, _stormTargetGUIDs[(_stormTargetIndex + 1) % MaxStormTargetTrianglePoints]))
                    {
                        _stormTargetPositions[_stormTargetIndex] = stormTarget->GetPosition();
                        me->ClearUnitState(UNIT_STATE_CASTING); // The rune beams don't have any attribute to allow movement while channeling.
                        me->GetMotionMaster()->MovePoint(POINT_TRIANGLE_1 + _stormTargetIndex, _stormTargetPositions[_stormTargetIndex], true, 5.f);
                    }
                    ++_stormTargetIndex;
                    break;
                case EVENT_LINK_STORM_TARGETS:
                    if (Creature* stormTarget = ObjectAccessor::GetCreature(*me, _stormTargetGUIDs[_stormTargetIndex % MaxStormTargetTrianglePoints]))
                        stormTarget->CastSpell(stormTarget, StormRuneBeamSpellsStormTarget[_stormTargetIndex - 1]);
                    break;
                case EVENT_FINISH_TRIANGLE:
                {
                    float centerX = (_stormTargetPositions[0].GetPositionX() + _stormTargetPositions[1].GetPositionX() + _stormTargetPositions[2].GetPositionX()) / 3.f;
                    float centerY = (_stormTargetPositions[0].GetPositionY() + _stormTargetPositions[1].GetPositionY() + _stormTargetPositions[2].GetPositionY()) / 3.f;
                    me->CastSpell({ centerX, centerY, TRIANGLE_TOP_Z }, SPELL_SUPREMACY_OF_THE_STORM_SUMMON);
                    me->DespawnOrUnsummon(1s);
                    break;
                }
                default:
                    break;
            }
        }
    }

private:
    InstanceScript* _instance;
    EventMap _events;
    std::array<ObjectGuid, MaxStormTargetTrianglePoints> _stormTargetGUIDs;
    std::array<Position, MaxStormTargetTrianglePoints> _stormTargetPositions;
    uint8 _stormTargetIndex = 0;
};

// 86632 - SOTS Targeting
class spell_asaad_sots_targeting : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_SOTS_SUMMON });
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        // Ensure that the Unstable Grounding Field is summoned further away from us
        targets.remove_if([&](WorldObject const* target)
        {
            return GetCaster()->GetExactDist2d(target) <= 20.f;
        });
    }

    void HandleDummyEffect(SpellEffIndex /*effIndex*/)
    {
        Creature* caster = GetCaster() ? GetCaster()->ToCreature() : nullptr;
        if (!caster || !caster->IsAIEnabled())
            return;

        caster->AI()->SetGUID(GetHitUnit()->GetGUID(), DATA_RANDOM_STORM_TARGET);
        GetHitUnit()->CastSpell(nullptr, SPELL_SOTS_SUMMON);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_asaad_sots_targeting::FilterTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget.Register(&spell_asaad_sots_targeting::HandleDummyEffect, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 86926 - SOTS Trigger
class spell_asaad_sots_trigger : public SpellScript
{
    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_GROUNDING_FIELD });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        Unit* caster = GetCaster();
        if (!caster || !caster->IsCreature())
            return;

        if (Creature* creature = GetHitCreature())
            if (creature->IsAIEnabled())
                creature->AI()->JustSummoned(caster->ToCreature());
    }

    void Register() override
    {
        OnEffectHitTarget.Register(&spell_asaad_sots_trigger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 86923 - Storm Rune Beam A
// 86925 - Storm Rune Beam B
// 87517 - Storm Rune Beam C
class spell_asaad_storm_rune_beam : public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsCreature() && GetCaster()->GetEntry() != NPC_UNSTABLE_GROUNDING_FIELD;
    }

    void SetTarget(WorldObject*& target)
    {
        if (Creature* groundingField = GetCaster()->FindNearestCreature(NPC_UNSTABLE_GROUNDING_FIELD, 5.f))
            if (groundingField->IsAIEnabled())
                target = ObjectAccessor::GetCreature(*GetCaster(), groundingField->AI()->GetGUID(DATA_PREVIOUS_STORM_TARGET));
    }

    void Register() override
    {
        OnObjectTargetSelect.Register(&spell_asaad_storm_rune_beam::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// 87517 - Grounding Field Visual Beams
class spell_asaad_grounding_field_visual_beams : public SpellScript
{
    bool Load() override
    {
        _instance = GetCaster()->GetInstanceScript();
        return _instance != nullptr;
    }

    void SetTarget1(WorldObject*& target)
    {
        if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
            if (asaad->IsAIEnabled())
                target = ObjectAccessor::GetCreature(*GetCaster(), asaad->AI()->GetGUID(DATA_STORM_TARGET_1));
    }

    void SetTarget2(WorldObject*& target)
    {
        if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
            if (asaad->IsAIEnabled())
                target = ObjectAccessor::GetCreature(*GetCaster(), asaad->AI()->GetGUID(DATA_STORM_TARGET_2));
    }

    void SetTarget3(WorldObject*& target)
    {
        if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
            if (asaad->IsAIEnabled())
                target = ObjectAccessor::GetCreature(*GetCaster(), asaad->AI()->GetGUID(DATA_STORM_TARGET_3));
    }

    void Register() override
    {
        OnObjectTargetSelect.Register(&spell_asaad_grounding_field_visual_beams::SetTarget1, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnObjectTargetSelect.Register(&spell_asaad_grounding_field_visual_beams::SetTarget2, EFFECT_1, TARGET_UNIT_NEARBY_ENTRY);
        OnObjectTargetSelect.Register(&spell_asaad_grounding_field_visual_beams::SetTarget3, EFFECT_2, TARGET_UNIT_NEARBY_ENTRY);
    }
private:
    InstanceScript* _instance;
};

class spell_asaad_grounding_field_visual_beams_AuraScript : public AuraScript
{
    void AfterRemove(AuraEffect const* /*aurEff*/, AuraEffectHandleModes /*mode*/)
    {
        GetTarget()->InterruptNonMeleeSpells(true);
    }

    void Register() override
    {
        AfterEffectRemove.Register(&spell_asaad_grounding_field_visual_beams_AuraScript::AfterRemove, EFFECT_0, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_asaad_grounding_field_visual_beams_AuraScript::AfterRemove, EFFECT_1, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
        AfterEffectRemove.Register(&spell_asaad_grounding_field_visual_beams_AuraScript::AfterRemove, EFFECT_2, SPELL_AURA_DUMMY, AURA_EFFECT_HANDLE_REAL);
    }
};


// 87474 - Grounding Field
class spell_asaad_grounding_field : public SpellScript
{
    bool Load() override
    {
        _instance = GetCaster()->GetInstanceScript();
        return _instance != nullptr;
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* asaad = _instance->GetCreature(DATA_ASAAD);
        if (!asaad || !asaad->IsAIEnabled())
            return;

        std::array<Position, MaxStormTargetTrianglePoints> trianglePoints;
        for (uint8 i = 0; i < trianglePoints.size(); ++i)
            if (Creature* stormTarget = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(DATA_STORM_TARGET_1 + i)))
                trianglePoints[i] = stormTarget->GetPosition();

        TriangleBoundary boundary = { trianglePoints[0], trianglePoints[1], trianglePoints[2] };
        targets.remove_if([boundary](WorldObject const* target)
        {
            return !boundary.IsWithinBoundary(target);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_asaad_grounding_field::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
private:
    InstanceScript* _instance;
};

// 87618 - Static Cling
class spell_asaad_static_cling : public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        targets.remove_if([](WorldObject const* target)
        {
            Player const* player = target->ToPlayer();
            return (!player || player->HasUnitMovementFlag(MOVEMENTFLAG_FALLING | MOVEMENTFLAG_FALLING_FAR));
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_asaad_static_cling::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect.Register(&spell_asaad_static_cling::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

// 86715 - Supremacy of the Storm
class spell_asaad_supremacy_of_the_storm_visual: public SpellScript
{
    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Trinity::Containers::RandomResize(targets, 5);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_asaad_supremacy_of_the_storm_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

// 87553/93994 - Supremacy of the Storm
class spell_asaad_supremacy_of_the_storm_damage: public SpellScript
{
    bool Load() override
    {
        return GetCaster()->IsCreature();
    }

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        if (targets.empty())
            return;

        Creature* caster = GetCaster()->ToCreature();
        if (!caster->IsAIEnabled())
            return;

        // Despite the grounding field npc having an aura, the aura kicks in later than the damage kicks, so it cannot be used as reliable check source.
        std::array<Position, MaxStormTargetTrianglePoints> trianglePoints;
        for (uint8 i = 0; i < trianglePoints.size(); ++i)
            if (Creature* stormTarget = ObjectAccessor::GetCreature(*caster, caster->AI()->GetGUID(DATA_STORM_TARGET_1 + i)))
                trianglePoints[i] = stormTarget->GetPosition();

        TriangleBoundary boundary = { trianglePoints[0], trianglePoints[1], trianglePoints[2] };
        targets.remove_if([boundary](WorldObject const* target)
        {
            return boundary.IsWithinBoundary(target);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect.Register(&spell_asaad_supremacy_of_the_storm_damage::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

void AddSC_boss_asaad()
{
    RegisterVortexPinnacleCreatureAI(boss_asaad);
    RegisterVortexPinnacleCreatureAI(npc_asaad_unstable_grounding_field);
    RegisterSpellScript(spell_asaad_sots_targeting);
    RegisterSpellScript(spell_asaad_sots_trigger);
    RegisterSpellScript(spell_asaad_storm_rune_beam);
    RegisterSpellAndAuraScriptPair(spell_asaad_grounding_field_visual_beams, spell_asaad_grounding_field_visual_beams_AuraScript);
    RegisterSpellScript(spell_asaad_grounding_field);
    RegisterSpellScript(spell_asaad_static_cling);
    RegisterSpellScript(spell_asaad_supremacy_of_the_storm_visual);
    RegisterSpellScript(spell_asaad_supremacy_of_the_storm_damage);
}
