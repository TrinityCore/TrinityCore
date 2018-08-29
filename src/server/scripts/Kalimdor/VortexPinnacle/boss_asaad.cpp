/*
 * Copyright (C) 2008-2018 TrinityCore <https://www.trinitycore.org/>
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
#include "MotionMaster.h"
#include "ObjectAccessor.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellInfo.h"
#include "SpellScript.h"
#include "TemporarySummon.h"
#include "vortex_pinnacle.h"

enum Spells
{
    // Asaad
    SPELL_SUMMON_SKYFALL_STAR               = 96260, // summons 52019
    SPELL_CHAIN_LIGHTNING                   = 87622,
    SPELL_SOTS_TARGETING                    = 86632,
    SPELL_STATIC_CLING                      = 87618,

    SPELL_UNSTABLE_GROUNDING_FIELD          = 86911, // 20 sec channel, visual
    SPELL_SUPREMACY_OF_THE_STORM_TELEPORT   = 87328,
    SPELL_SUPREMACY_OF_THE_STORM            = 86930,

    // Skyfall Star
    SPELL_ARCANE_BARRAGE_AURA               = 87845,

    // Storm Target
    SPELL_SOTS_SUMMON                       = 86658,

    // Unstable Grounding Field
    SPELL_SOTS_TRIGGER                      = 86926,
    SPELL_STORM_RUNE_BEAM_AA                = 86981,
    SPELL_STORM_RUNE_BEAM_A                 = 86921,
    SPELL_STORM_RUNE_BEAM_B                 = 86923,
    SPELL_STORM_RUNE_BEAM_C                 = 86925,
    SPELL_STORM_SUMMON_GROUNDING_FIELD      = 87518,

    // Grounding Field
    SPELL_GROUNDING_FIELD_VISUAL_BEAMS      = 87517
};

enum NPCs
{
    NPC_SKYFALL_STAR                = 52019,
    NPC_STORM_TARGET                = 46387,
    NPC_UNSTABLE_GROUNDING_FIELD    = 46492
};

enum Texts
{
    SAY_AGGRO       = 0,
    SAY_SOTS_EMOTE  = 1,
    SAY_SOTS        = 2,
    SAY_DEATH       = 3
};

enum Actions
{
    ACTION_NONE,
    ACTION_SOTS_TARGET,
    ACTION_SUPREMACY_OF_THE_STORM
};

enum Events
{
    EVENT_NONE,
    EVENT_SUMMON_SKYFALL_STAR,
    EVENT_CHAIN_LIGHTNING,
    EVENT_STATIC_CLING,
    EVENT_SOTS,
    EVENT_SOTS_START,
    EVENT_SOTS_END,
    EVENT_ATTACK,

    // Storm Target
    EVENT_SOTS_SUMMON,

    // Unstable Grounding Field npc
    EVENT_STORM_ASSAD_CHANNEL,
    EVENT_STORM_RUNE_BEAM_AA,
    EVENT_STORM_MOVE_B,
    EVENT_STORM_MOVE_C,
    EVENT_STORM_MOVE_A,
    EVENT_STORM_ASAAD_TELEPORT,

    // Grounding Field npc
    EVENT_GROUNDING_FIELD_VISUAL_BEAMS
};

enum Points
{
    POINT_STORM_A = 1,
    POINT_STORM_B,
    POINT_STORM_C
};

float const TRIANGLE_Z = 646.7143f;

uint32 const StormTargetPositions = 39;
Position const StormTargetPositionData[StormTargetPositions] =
{
    { -633.771f, 490.976f, TRIANGLE_Z, 3.141593f }, // 56889
    { -625.688f, 501.934f, TRIANGLE_Z, 3.141593f }, // 56890
    { -620.226f, 490.892f, TRIANGLE_Z, 3.141593f }, // 56891

    { -649.906f, 494.905f, TRIANGLE_Z, 3.141593f }, // 56892
    { -643.214f, 503.953f, TRIANGLE_Z, 3.141593f }, // 56893
    { -640.542f, 487.474f, TRIANGLE_Z, 3.141593f }, // 56894

    { -637.839f, 516.186f, TRIANGLE_Z, 1.099557f }, // 56895
    { -634.068f, 507.51f,  TRIANGLE_Z, 1.099557f }, // 56896
    { -650.894f, 509.323f, TRIANGLE_Z, 1.099557f }, // 56897

    { -637.01f,  530.09f,  TRIANGLE_Z, 1.099557f }, // 56898
    { -632.167f, 521.153f, TRIANGLE_Z, 1.099557f }, // 56899
    { -646.939f, 519.566f, TRIANGLE_Z, 1.099557f }, // 56900

    { -628.512f, 516.988f, TRIANGLE_Z, 1.099557f }, // 56901
    { -622.184f, 507.908f, TRIANGLE_Z, 1.099557f }, // 56902
    { -633.148f, 499.762f, TRIANGLE_Z, 1.099557f }, // 56903

    { -615.528f, 515.944f, TRIANGLE_Z, 1.099557f }, // 56904
    { -609.41f,  504.675f, TRIANGLE_Z, 1.099557f }, // 56905
    { -618.748f, 501.946f, TRIANGLE_Z, 1.099557f }, // 56906

    { -600.986f, 522.576f, TRIANGLE_Z, 1.099557f }, // 56907
    { -594.96f,  507.582f, TRIANGLE_Z, 1.099557f }, // 56908
    { -605.094f, 509.141f, TRIANGLE_Z, 1.099557f }, // 56909

    { -617.269f, 521.168f, TRIANGLE_Z, 0.0f }, // 56910
    { -606.75f,  530.002f, TRIANGLE_Z, 0.0f }, // 56911
    { -608.832f, 515.175f, TRIANGLE_Z, 0.0f }, // 56912

    { -627.957f, 529.927f, TRIANGLE_Z, 0.0f }, // 56913
    { -616.997f, 530.564f, TRIANGLE_Z, 0.0f }, // 56914
    { -621.91f,  517.644f, TRIANGLE_Z, 0.0f }, // 56915

    { -604.839f, 485.186f, TRIANGLE_Z, 3.141593f }, // 56916
    { -616.885f, 496.186f, TRIANGLE_Z, 3.141593f }, // 56917
    { -606.833f, 500.078f, TRIANGLE_Z, 3.141593f }, // 56918

    { -600.387f, 482.604f, TRIANGLE_Z, 3.141593f }, // 56919
    { -602.899f, 497.245f, TRIANGLE_Z, 3.141593f }, // 56920
    { -592.599f, 500.392f, TRIANGLE_Z, 3.141593f }, // 56921

    { -622.946f, 483.113f, TRIANGLE_Z, 3.141593f }, // 56922
    { -613.104f, 488.776f, TRIANGLE_Z, 3.141593f }, // 56923
    { -606.915f, 477.097f, TRIANGLE_Z, 3.141593f }, // 56924

    { -640.717f, 480.623f, TRIANGLE_Z, 3.141593f }, // 56925
    { -627.049f, 486.917f, TRIANGLE_Z, 3.141593f }, // 56926
    { -623.059f, 476.104f, TRIANGLE_Z, 3.141593f }, // 56927
};

struct boss_asaad : public BossAI
{
    boss_asaad(Creature* creature) : BossAI(creature, DATA_ASAAD)
    {
        stormTargetGUIDs.reserve(StormTargetPositions);
    }

    void Reset() override
    {
        _Reset();
        stormTargetGUIDs.clear();

        me->SetReactState(REACT_AGGRESSIVE);
    }

    void JustEngagedWith(Unit* /*target*/) override
    {
        _JustEngagedWith();
        Talk(SAY_AGGRO);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
        events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 11000);
        events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 14500);
        events.ScheduleEvent(EVENT_SOTS, 18000);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_STATIC_CLING, 10800);

        // Spawn Storm Targets
        for (uint32 i = 0; i < StormTargetPositions; ++i)
            if (Creature* stormTarget = me->SummonCreature(NPC_STORM_TARGET, StormTargetPositionData[i]))
                stormTargetGUIDs.push_back(stormTarget->GetGUID());
    }

    void JustSummoned(Creature* creature) override
    {
        if (creature->GetEntry() == NPC_SKYFALL_STAR)
        {
            creature->SetReactState(REACT_PASSIVE);
            creature->SetInCombatWithZone();
            creature->CastSpell(creature, SPELL_ARCANE_BARRAGE_AURA);
            Position const pos = me->GetHomePosition();
            creature->GetMotionMaster()->MoveCirclePath(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), 40.0f, false, 8);
        }

        BossAI::JustSummoned(creature);
    }

    void SpellHitTarget(Unit* target, SpellInfo const* spellInfo) override
    {
        if (spellInfo->Id != SPELL_SOTS_TARGETING || target->GetEntry() != NPC_STORM_TARGET)
            return;

        selectedStormTargets[0] = target->GetGUID();
        auto itr = std::find(stormTargetGUIDs.begin(), stormTargetGUIDs.end(), target->GetGUID());
        ASSERT(itr != stormTargetGUIDs.end());

        uint8 index = uint8(std::distance(stormTargetGUIDs.begin(), itr));
        switch (index % 3)
        {
            case 0:
                selectedStormTargets[1] = stormTargetGUIDs.at(index + 1);
                selectedStormTargets[2] = stormTargetGUIDs.at(index + 2);
                break;
            case 1:
                selectedStormTargets[1] = stormTargetGUIDs.at(index - 1);
                selectedStormTargets[2] = stormTargetGUIDs.at(index + 1);
                break;
            case 2:
                selectedStormTargets[1] = stormTargetGUIDs.at(index - 2);
                selectedStormTargets[2] = stormTargetGUIDs.at(index - 1);
                break;
        }
    }

    void DoAction(int32 action) override
    {
        if (action != ACTION_SUPREMACY_OF_THE_STORM)
            return;

        me->CastStop();
        me->SetDisableGravity(true);
        DoCast(me, SPELL_SUPREMACY_OF_THE_STORM_TELEPORT);
        DoCast(me, SPELL_SUPREMACY_OF_THE_STORM);
        events.ScheduleEvent(EVENT_SOTS_END, 6000);
    }

    void JustDied(Unit* /*killer*/) override
    {
        Talk(SAY_DEATH);
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _JustDied();
    }

    void EnterEvadeMode(EvadeReason /*why*/) override
    {
        summons.DespawnAll();
        instance->SendEncounterUnit(ENCOUNTER_FRAME_DISENGAGE, me);
        _EnterEvadeMode();
        _DespawnAtEvade();
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
                case EVENT_STATIC_CLING:
                    DoCast(me, SPELL_STATIC_CLING);
                    events.ScheduleEvent(EVENT_STATIC_CLING, 16000);
                    break;
                case EVENT_SUMMON_SKYFALL_STAR:
                    DoCast(me, SPELL_SUMMON_SKYFALL_STAR, true);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 14500);
                    break;
                case EVENT_CHAIN_LIGHTNING:
                    DoCast(me, SPELL_CHAIN_LIGHTNING);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 14500);
                    break;
                case EVENT_SOTS:
                    Talk(SAY_SOTS_EMOTE);
                    events.Reset();
                    events.ScheduleEvent(EVENT_SOTS_START, 200);
                    events.ScheduleEvent(EVENT_SOTS, 45800);
                    break;
                case EVENT_SOTS_START:
                    me->SetReactState(REACT_PASSIVE);
                    me->AttackStop();
                    Talk(SAY_SOTS);
                    DoCast(me, SPELL_SOTS_TARGETING);
                    break;
                case EVENT_SOTS_END:
                    ResetStormTargets();
                    me->SetDisableGravity(false);
                    events.ScheduleEvent(EVENT_ATTACK, 2000);
                    break;
                case EVENT_ATTACK:
                    me->SetReactState(REACT_AGGRESSIVE);
                    events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 100);
                    events.ScheduleEvent(EVENT_STATIC_CLING, 2000);
                    events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 3500);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }

    ObjectGuid GetGUID(int32 type) const override
    {
        switch (type)
        {
            case POINT_STORM_A:
            case POINT_STORM_B:
            case POINT_STORM_C:
                return selectedStormTargets[type - POINT_STORM_A];
            default:
                break;
        }

        return ObjectGuid::Empty;
    }

    Position GetTriangleCenterPosition() const
    {
        Position pos;
        pos.m_positionZ = TRIANGLE_Z + 8.f;

        for (uint8 i = 0; i < 3; ++i)
        {
            if (Creature* stormTarget = ObjectAccessor::GetCreature(*me, selectedStormTargets[i]))
            {
                pos.m_positionX += stormTarget->m_positionX;
                pos.m_positionY += stormTarget->m_positionY;
            }
        }

        pos.m_positionX /= 3.f;
        pos.m_positionY /= 3.f;
        return pos;
    }

    void ResetStormTargets()
    {
        for (uint8 i = 0; i < 3; ++i)
        {
            if (Creature* stormTarget = ObjectAccessor::GetCreature(*me, selectedStormTargets[i]))
                stormTarget->CastStop();

            selectedStormTargets[i].Clear();
        }
    }

private:

    GuidVector stormTargetGUIDs;
    std::array<ObjectGuid, 3> selectedStormTargets;
};

typedef boss_asaad AsaadAI;

// 46387 - Storm Target
struct npc_asaad_storm_target : public ScriptedAI
{
    npc_asaad_storm_target(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript()) { }

    void DoAction(int32 action) override
    {
        if (action == ACTION_SOTS_TARGET)
            _events.ScheduleEvent(EVENT_SOTS_SUMMON, 400);
    }

    void JustSummoned(Creature* creature) override
    {
        if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
            asaad->AI()->JustSummoned(creature);
    }

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_SOTS_SUMMON:
                    DoCast(me, SPELL_SOTS_SUMMON);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

// 46492 - Unstable Grounding Field
struct npc_asaad_unstable_grounding_field : public ScriptedAI
{
    npc_asaad_unstable_grounding_field(Creature* creature) : ScriptedAI(creature), _instance(creature->GetInstanceScript())
    {
        me->SetWalk(true);
        _events.ScheduleEvent(EVENT_STORM_ASSAD_CHANNEL, 400);
    }

    void MovementInform(uint32 movementType, uint32 pointId) override
    {
        if (movementType != POINT_MOTION_TYPE)
            return;

        Creature* asaad = _instance->GetCreature(DATA_ASAAD);
        if (!asaad)
            return;

        switch (pointId)
        {
            case POINT_STORM_B:
                if (Creature* stormTargetB = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_B)))
                    stormTargetB->CastSpell((Unit*)nullptr, SPELL_STORM_RUNE_BEAM_A);
                _events.ScheduleEvent(EVENT_STORM_MOVE_C, 1200);
                break;
            case POINT_STORM_C:
                if (Creature* stormTargetC = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_C)))
                    stormTargetC->CastSpell((Unit*)nullptr, SPELL_STORM_RUNE_BEAM_B);
                _events.ScheduleEvent(EVENT_STORM_MOVE_A, 1200);
                break;
            case POINT_STORM_A:
            {
                if (Creature* stormTargetA = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_A)))
                    stormTargetA->CastSpell((Unit*)nullptr, SPELL_STORM_RUNE_BEAM_C);

                DoCast(me, SPELL_STORM_SUMMON_GROUNDING_FIELD);

                Position pos = ENSURE_AI(AsaadAI, asaad->AI())->GetTriangleCenterPosition();
                me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_STORM_SUMMON_GROUNDING_FIELD, true);
                _events.ScheduleEvent(EVENT_STORM_ASAAD_TELEPORT, 500);
                break;
            }
            default:
                break;
        }
    };

    void UpdateAI(uint32 diff) override
    {
        if (_events.Empty())
            return;

        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_STORM_ASSAD_CHANNEL:
                    DoCast(me, SPELL_SOTS_TRIGGER);
                    _events.ScheduleEvent(EVENT_STORM_RUNE_BEAM_AA, 400);
                    break;
                case EVENT_STORM_RUNE_BEAM_AA:
                    DoCast(me, SPELL_STORM_RUNE_BEAM_AA);
                    _events.ScheduleEvent(EVENT_STORM_MOVE_B, 800);
                    break;
                case EVENT_STORM_MOVE_B:
                    if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
                        if (Creature* stormTargetB = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_B)))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_B, stormTargetB->GetPosition());
                    break;
                case EVENT_STORM_MOVE_C:
                    DoCast(me, SPELL_STORM_RUNE_BEAM_B);
                    if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
                        if (Creature* stormTargetC = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_C)))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_C, stormTargetC->GetPosition());
                    break;
                case EVENT_STORM_MOVE_A:
                    me->CastStop();
                    DoCast(me, SPELL_STORM_RUNE_BEAM_C);
                    if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
                        if (Creature* stormTargetA = ObjectAccessor::GetCreature(*me, asaad->AI()->GetGUID(POINT_STORM_A)))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_A, stormTargetA->GetPosition());
                    break;
                case EVENT_STORM_ASAAD_TELEPORT:
                    if (Creature* asaad = _instance->GetCreature(DATA_ASAAD))
                        asaad->AI()->DoAction(ACTION_SUPREMACY_OF_THE_STORM);
                    me->DespawnOrUnsummon(700);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap _events;
    InstanceScript* _instance;
};

// 47000 - Grounding Field
struct npc_asaad_grounding_field : public ScriptedAI
{
    npc_asaad_grounding_field(Creature* creature) : ScriptedAI(creature)
    {
        me->SetDisableGravity(true);
        events.ScheduleEvent(EVENT_GROUNDING_FIELD_VISUAL_BEAMS, 500);
    }

    void UpdateAI(uint32 diff) override
    {
        if (events.Empty())
            return;

        events.Update(diff);

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_GROUNDING_FIELD_VISUAL_BEAMS:
                    DoCast(me, SPELL_GROUNDING_FIELD_VISUAL_BEAMS);
                    me->DespawnOrUnsummon(6000);
                    break;
                default:
                    break;
            }
        }
    }

private:
    EventMap events;
};

// 86632 - SOTS Targeting
class spell_asaad_sots_targeting : public SpellScript
{
    PrepareSpellScript(spell_asaad_sots_targeting);

    void SelectRandom(std::list<WorldObject*>& targets)
    {
        Trinity::Containers::RandomResize(targets, 1);
    }

    void HandleDummy(SpellEffIndex /*effIndex*/)
    {
        if (Creature* creature = GetHitCreature())
            creature->GetAI()->DoAction(ACTION_SOTS_TARGET);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_asaad_sots_targeting::SelectRandom, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
        OnEffectHitTarget += SpellEffectFn(spell_asaad_sots_targeting::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
    }
};

// 86926  - SOTS Trigger (makes Asaad channel Unstable Grounding Field)
class spell_asaad_sots_trigger : public SpellScript
{
    PrepareSpellScript(spell_asaad_sots_trigger);

    bool Validate(SpellInfo const* /*spellInfo*/) override
    {
        return ValidateSpellInfo({ SPELL_UNSTABLE_GROUNDING_FIELD });
    }

    void HandleScriptEffect(SpellEffIndex /*effIndex*/)
    {
        GetHitUnit()->CastSpell(GetHitUnit(), SPELL_UNSTABLE_GROUNDING_FIELD, true);
    }

    void Register() override
    {
        OnEffectHitTarget += SpellEffectFn(spell_asaad_sots_trigger::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
    }
};

// 86981 - Storm Rune Beam AA
// 86921 - Storm Rune Beam A
// 86923 - Storm Rune Beam B
// 86925 - Storm Rune Beam C
class spell_asaad_storm_rune_beam : public SpellScript
{
    PrepareSpellScript(spell_asaad_storm_rune_beam);

    void SetTarget(WorldObject*& target)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* asaad = instance->GetCreature(DATA_ASAAD);
        if (!asaad)
            return;

        switch (GetSpellInfo()->Id)
        {
            case SPELL_STORM_RUNE_BEAM_AA:
            case SPELL_STORM_RUNE_BEAM_A:
                target = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_A));
                break;
            case SPELL_STORM_RUNE_BEAM_B:
                target = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_B));
                break;
            case SPELL_STORM_RUNE_BEAM_C:
                target = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_C));
                break;
            default:
                break;
        }
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_asaad_storm_rune_beam::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
    }
};

// 87517 - Grounding Field Visual Beams
class spell_asaad_grounding_field_visual_beams : public SpellScript
{
    PrepareSpellScript(spell_asaad_grounding_field_visual_beams);

    void SetTargetA(WorldObject*& target)
    {
        target = GetStormTarget(POINT_STORM_A);
    }

    void SetTargetB(WorldObject*& target)
    {
        target = GetStormTarget(POINT_STORM_B);
    }

    void SetTargetC(WorldObject*& target)
    {
        target = GetStormTarget(POINT_STORM_C);
    }

    void Register() override
    {
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_asaad_grounding_field_visual_beams::SetTargetA, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_asaad_grounding_field_visual_beams::SetTargetB, EFFECT_1, TARGET_UNIT_NEARBY_ENTRY);
        OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_asaad_grounding_field_visual_beams::SetTargetC, EFFECT_2, TARGET_UNIT_NEARBY_ENTRY);
    }
private:
    Creature * GetStormTarget(uint32 point)
    {
        if (InstanceScript* instance = GetCaster()->GetInstanceScript())
            if (Creature* asaad = instance->GetCreature(DATA_ASAAD))
                ObjectAccessor::GetCreature(*GetCaster(), asaad->AI()->GetGUID(point));

        return nullptr;
    }
};

// 87553/93994 - Supremacy of the Storm (massive aoe damage)
class spell_asaad_supremacy_of_the_storm : public SpellScript
{
    PrepareSpellScript(spell_asaad_supremacy_of_the_storm);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* asaad = instance->GetCreature(DATA_ASAAD);
        if (!asaad)
            return;

        Creature* stormTargetA = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_A));
        Creature* stormTargetB = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_B));
        Creature* stormTargetC = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_C));

        if (!stormTargetA || !stormTargetB || !stormTargetC)
            return;

        TriangleBoundary triangle(*stormTargetA, *stormTargetB, *stormTargetC);
        targets.remove_if([&](WorldObject* target)
        {
            return triangle.IsWithinBoundary(target);
        });
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_asaad_supremacy_of_the_storm::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class AboveGroundCheck
{
    public:
        AboveGroundCheck() { }

        bool operator()(WorldObject* object)
        {
            if (Unit* target = object->ToUnit())
                return (target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING)
                    || target->HasUnitMovementFlag(MOVEMENTFLAG_FALLING_FAR)
                    || target->HasUnitMovementFlag(MOVEMENTFLAG_PITCH_UP));

            return false;
        }
};

class spell_asaad_supremacy_of_the_storm_visual : public SpellScript
{
    PrepareSpellScript(spell_asaad_supremacy_of_the_storm_visual);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        InstanceScript* instance = GetCaster()->GetInstanceScript();
        if (!instance)
            return;

        Creature* asaad = instance->GetCreature(DATA_ASAAD);
        if (!asaad)
            return;

        Creature* stormTargetA = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_A));
        Creature* stormTargetB = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_B));
        Creature* stormTargetC = ObjectAccessor::GetCreature(*asaad, asaad->AI()->GetGUID(POINT_STORM_C));

        if (!stormTargetA || !stormTargetB || !stormTargetC)
            return;

        TriangleBoundary triangle(*stormTargetA, *stormTargetB, *stormTargetC);
        targets.remove_if([&](WorldObject* target)
        {
            return triangle.IsWithinBoundary(target);
        });

        // Hitting 5 dummy npc's per hit
        if (!targets.empty() && targets.size() > 5)
            Trinity::Containers::RandomResize(targets, 5);
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_asaad_supremacy_of_the_storm_visual::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENTRY);
    }
};

class spell_asaad_static_cling : public SpellScript
{
    PrepareSpellScript(spell_asaad_static_cling);

    void FilterTargets(std::list<WorldObject*>& targets)
    {
        targets.remove_if(AboveGroundCheck());
    }

    void Register() override
    {
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_asaad_static_cling::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_asaad_static_cling::FilterTargets, EFFECT_1, TARGET_UNIT_SRC_AREA_ENEMY);
    }
};

class spell_asaad_summon_skyfall_star : public SpellScript
{
    PrepareSpellScript(spell_asaad_summon_skyfall_star);

    void SetDest(SpellDestination& dest)
    {
        Creature* caster = GetCaster()->ToCreature();
        if (!caster)
            return;

        Position const homePos = caster->GetHomePosition();
        float radius = GetSpellInfo()->Effects[EFFECT_0].CalcRadius();
        float o = frand(0.0f, float(M_PI * 2));
        float x = homePos.GetPositionX() + cos(o) * radius;
        float y = homePos.GetPositionY() + sin(o) * radius;
        float z = caster->GetMap()->GetStaticHeight(caster->GetPhaseShift(), x, y, caster->GetPositionZ() + 2.0f);

        dest.Relocate({ x, y, z });
    }

    void Register()
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_asaad_summon_skyfall_star::SetDest, EFFECT_0, TARGET_DEST_DEST_RADIUS);
    }
};

void AddSC_boss_asaad()
{
    RegisterVortexPinnacleCreatureAI(boss_asaad);
    RegisterVortexPinnacleCreatureAI(npc_asaad_storm_target);
    RegisterVortexPinnacleCreatureAI(npc_asaad_unstable_grounding_field);
    RegisterVortexPinnacleCreatureAI(npc_asaad_grounding_field);
    RegisterSpellScript(spell_asaad_sots_targeting);
    RegisterSpellScript(spell_asaad_sots_trigger);
    RegisterSpellScript(spell_asaad_storm_rune_beam);
    RegisterSpellScript(spell_asaad_grounding_field_visual_beams);
    RegisterSpellScript(spell_asaad_supremacy_of_the_storm);
    RegisterSpellScript(spell_asaad_supremacy_of_the_storm_visual);
    RegisterSpellScript(spell_asaad_static_cling);
    RegisterSpellScript(spell_asaad_summon_skyfall_star);
}
