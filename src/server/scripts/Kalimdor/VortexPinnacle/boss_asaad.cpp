/*
 * Copyright (C) 2008-2016 TrinityCore <http://www.trinitycore.org/>
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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "vortex_pinnacle.h"

enum Spells
{
    SPELL_SUMMON_SKYFALL_STAR = 96260, // summons 52019
    SPELL_CHAIN_LIGHTNING = 87622,
    SPELL_SOTS_TARGETING = 86632,
    SPELL_STATIC_CLING = 87618,

    SPELL_UNSTABLE_GROUNDING_FIELD = 86911, // 20 sec channel, visual
    SPELL_SUPREMACY_OF_THE_STORM_TELEPORT = 87328,
    SPELL_SUPREMACY_OF_THE_STORM = 86930,

    // Skyfall Star
    SPELL_ARCANE_BARRAGE_AURA = 87845,

    // Storm Target
    SPELL_SOTS_SUMMON = 86658,

    // Unstable Grounding Field
    SPELL_SOTS_TRIGGER = 86926,
    SPELL_STORM_RUNE_BEAM_AA = 86981,
    SPELL_STORM_RUNE_BEAM_A = 86921,
    SPELL_STORM_RUNE_BEAM_B = 86923,
    SPELL_STORM_RUNE_BEAM_C = 86925,
    SPELL_STORM_SUMMON_GROUNDING_FIELD = 87518,

    // Grounding Field
    SPELL_GROUNDING_FIELD_VISUAL_BEAMS = 87517,
};

enum NPCs
{
    NPC_SKYFALL_STAR = 52019,
    NPC_STORM_TARGET = 46387,
    NPC_UNSTABLE_GROUNDING_FIELD = 46492,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_SOTS_EMOTE = 1,
    SAY_SOTS = 2,
    SAY_DEATH = 3,
};

enum Actions
{
    ACTION_NONE,
    ACTION_SOTS_TARGET,
    ACTION_SUPREMACY_OF_THE_STORM,
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
    EVENT_GROUNDING_FIELD_VISUAL_BEAMS,
};

enum Points
{
    POINT_STORM_A,
    POINT_STORM_B,
    POINT_STORM_C,
};

uint32 const StormTargetPositions = 39;
Position const StormTargetPositionData[StormTargetPositions] =
{
    { -633.771f, 490.976f, 646.7143f, 3.141593f }, // 56889
    { -625.688f, 501.934f, 646.7143f, 3.141593f }, // 56890
    { -620.226f, 490.892f, 646.7143f, 3.141593f }, // 56891

    { -649.906f, 494.905f, 646.7143f, 3.141593f }, // 56892
    { -643.214f, 503.953f, 646.7143f, 3.141593f }, // 56893
    { -640.542f, 487.474f, 646.7143f, 3.141593f }, // 56894

    { -637.839f, 516.186f, 646.7143f, 1.099557f }, // 56895
    { -634.068f, 507.51f,  646.7143f, 1.099557f }, // 56896
    { -650.894f, 509.323f, 646.7143f, 1.099557f }, // 56897

    { -637.01f,  530.09f,  646.7143f, 1.099557f }, // 56898
    { -632.167f, 521.153f, 646.7143f, 1.099557f }, // 56899
    { -646.939f, 519.566f, 646.7143f, 1.099557f }, // 56900

    { -628.512f, 516.988f, 646.7143f, 1.099557f }, // 56901
    { -622.184f, 507.908f, 646.7143f, 1.099557f }, // 56902
    { -633.148f, 499.762f, 646.7143f, 1.099557f }, // 56903

    { -615.528f, 515.944f, 646.7143f, 1.099557f }, // 56904
    { -609.41f,  504.675f, 646.7143f, 1.099557f }, // 56905
    { -618.748f, 501.946f, 646.7143f, 1.099557f }, // 56906

    { -600.986f, 522.576f, 646.7143f, 1.099557f }, // 56907
    { -594.96f,  507.582f, 646.7143f, 1.099557f }, // 56908
    { -605.094f, 509.141f, 646.7143f, 1.099557f }, // 56909

    { -617.269f, 521.168f, 646.7143f, 0.0f }, // 56910
    { -606.75f,  530.002f, 646.7143f, 0.0f }, // 56911
    { -608.832f, 515.175f, 646.7143f, 0.0f }, // 56912

    { -627.957f, 529.927f, 646.7143f, 0.0f }, // 56913
    { -616.997f, 530.564f, 646.7143f, 0.0f }, // 56914
    { -621.91f,  517.644f, 646.7143f, 0.0f }, // 56915

    { -604.839f, 485.186f, 646.7143f, 3.141593f }, // 56916
    { -616.885f, 496.186f, 646.7143f, 3.141593f }, // 56917
    { -606.833f, 500.078f, 646.7143f, 3.141593f }, // 56918

    { -600.387f, 482.604f, 646.7143f, 3.141593f }, // 56919
    { -602.899f, 497.245f, 646.7143f, 3.141593f }, // 56920
    { -592.599f, 500.392f, 646.7143f, 3.141593f }, // 56921

    { -622.946f, 483.113f, 646.7143f, 3.141593f }, // 56922
    { -613.104f, 488.776f, 646.7143f, 3.141593f }, // 56923
    { -606.915f, 477.097f, 646.7143f, 3.141593f }, // 56924

    { -640.717f, 480.623f, 646.7143f, 3.141593f }, // 56925
    { -627.049f, 486.917f, 646.7143f, 3.141593f }, // 56926
    { -623.059f, 476.104f, 646.7143f, 3.141593f }, // 56927
};

class boss_asaad : public CreatureScript
{
    public:
        boss_asaad() : CreatureScript("boss_asaad") { }

        struct boss_asaadAI : public BossAI
        {
            boss_asaadAI(Creature* creature) : BossAI(creature, DATA_ASAAD) { }

            void Reset() override
            {
                _Reset();

                me->SetReactState(REACT_AGGRESSIVE);

                events.ScheduleEvent(EVENT_SUMMON_SKYFALL_STAR, 11000);
                events.ScheduleEvent(EVENT_CHAIN_LIGHTNING, 14500);
                events.ScheduleEvent(EVENT_SOTS, 18000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_STATIC_CLING, 10800);
            }

            void EnterCombat(Unit* /*target*/) override
            {
                _EnterCombat();

                Talk(SAY_AGGRO);

                // Spawn Storm Targets
                for (uint32 i = 0; i < StormTargetPositions; i++)
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
                }

                BossAI::JustSummoned(creature);
            }

            void SpellHitTarget(Unit* target, const SpellInfo* spellInfo) override
            {
                if (spellInfo->Id != SPELL_SOTS_TARGETING || target->GetEntry() != NPC_STORM_TARGET)
                    return;

                stormTargetA = target->ToCreature();

                for (uint32 i = 0; i < StormTargetPositions; i++)
                {
                    if (stormTargetGUIDs[i] != target->GetGUID())
                        continue;

                    stormTargetB = ObjectAccessor::GetCreature(*me, stormTargetGUIDs[i % 3 == 0 ? i + 1 : (i % 3 == 1 ? i - 1 : i - 2)]);
                    stormTargetC = ObjectAccessor::GetCreature(*me, stormTargetGUIDs[i % 3 == 0 ? i + 2 : (i % 3 == 1 ? i + 1 : i - 1)]);

                    ASSERT(stormTargetB);
                    ASSERT(stormTargetC);
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

                _JustDied();
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
                            DoCast(me, SPELL_SUMMON_SKYFALL_STAR);
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

            Creature* GetSelectedStormTarget(uint32 point)
            {
                if (point == POINT_STORM_A)
                    return stormTargetA;
                if (point == POINT_STORM_B)
                    return stormTargetB;
                if (point == POINT_STORM_C)
                    return stormTargetC;
                return NULL;
            }

            Position GetTriangleCenterPosition()
            {
                Position pos;
                pos.m_positionX = (stormTargetA->GetPositionX() + stormTargetB->GetPositionX() + stormTargetC->GetPositionX()) / 3;
                pos.m_positionY = (stormTargetA->GetPositionY() + stormTargetB->GetPositionY() + stormTargetC->GetPositionY()) / 3;
                pos.m_positionZ = stormTargetA->GetPositionZ() + 8.0f;
                return pos;
            }

            void ResetStormTargets()
            {
                stormTargetA->CastStop();
                stormTargetB->CastStop();
                stormTargetC->CastStop();
            }

        private:
            GuidVector stormTargetGUIDs;
            Creature* stormTargetA;
            Creature* stormTargetB;
            Creature* stormTargetC;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_asaadAI>(creature);
        }
};

typedef boss_asaad::boss_asaadAI AsaadAI;

// 46387 - Storm Target
class npc_storm_target : public CreatureScript
{
public:
    npc_storm_target() : CreatureScript("npc_storm_target") { }

    struct npc_storm_targetAI : public ScriptedAI
    {
        npc_storm_targetAI(Creature* creature) : ScriptedAI(creature) { }

        void DoAction(int32 action) override
        {
            if (action != ACTION_SOTS_TARGET)
                return;

            events.ScheduleEvent(EVENT_SOTS_SUMMON, 400);
        }

        void JustSummoned(Creature* creature) override
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                if (Creature* asaad = instance->GetCreature(DATA_ASAAD))
                    ENSURE_AI(AsaadAI, asaad->AI())->JustSummoned(creature);
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
                    case EVENT_SOTS_SUMMON:
                        DoCast(me, SPELL_SOTS_SUMMON);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_storm_targetAI>(creature);
    }
};

// 46492 - Unstable Grounding Field
class npc_unstable_grounding_field : public CreatureScript
{
public:
    npc_unstable_grounding_field() : CreatureScript("npc_unstable_grounding_field") { }

    struct npc_unstable_grounding_fieldAI : public ScriptedAI
    {
        npc_unstable_grounding_fieldAI(Creature* creature) : ScriptedAI(creature)
        {
            if (InstanceScript* instance = me->GetInstanceScript())
                if (Creature* asaad = instance->GetCreature(DATA_ASAAD))
                    asaadAI = CAST_AI(AsaadAI, asaad->AI());

            me->SetWalk(true);
            events.ScheduleEvent(EVENT_STORM_ASSAD_CHANNEL, 400);
        }

        void MovementInform(uint32 movementType, uint32 pointId) override
        {
            if (movementType != POINT_MOTION_TYPE)
                return;

            switch (pointId)
            {
                case POINT_STORM_B:
                    if (Creature* stormTargetB = asaadAI->GetSelectedStormTarget(POINT_STORM_B))
                        stormTargetB->CastSpell((Unit*)NULL, SPELL_STORM_RUNE_BEAM_A);
                    events.ScheduleEvent(EVENT_STORM_MOVE_C, 1200);
                    break;
                case POINT_STORM_C:
                    if (Creature* stormTargetB = asaadAI->GetSelectedStormTarget(POINT_STORM_C))
                        stormTargetB->CastSpell((Unit*)NULL, SPELL_STORM_RUNE_BEAM_B);
                    events.ScheduleEvent(EVENT_STORM_MOVE_A, 1200);
                    break;
                case POINT_STORM_A:
                {
                    if (Creature* stormTargetB = asaadAI->GetSelectedStormTarget(POINT_STORM_A))
                        stormTargetB->CastSpell((Unit*)NULL, SPELL_STORM_RUNE_BEAM_C);

                    DoCast(me, SPELL_STORM_SUMMON_GROUNDING_FIELD);
                    Position pos = asaadAI->GetTriangleCenterPosition();
                    me->CastSpell(pos.GetPositionX(), pos.GetPositionY(), pos.GetPositionZ(), SPELL_STORM_SUMMON_GROUNDING_FIELD, true);
                    events.ScheduleEvent(EVENT_STORM_ASAAD_TELEPORT, 500);
                    break;
                }
                default:
                    break;
            }
        };

        void UpdateAI(uint32 diff) override
        {
            if (events.Empty())
                return;

            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_STORM_ASSAD_CHANNEL:
                        DoCast(me, SPELL_SOTS_TRIGGER);
                        events.ScheduleEvent(EVENT_STORM_RUNE_BEAM_AA, 400);
                        break;
                    case EVENT_STORM_RUNE_BEAM_AA:
                        DoCast(me, SPELL_STORM_RUNE_BEAM_AA);
                        events.ScheduleEvent(EVENT_STORM_MOVE_B, 800);
                        break;
                    case EVENT_STORM_MOVE_B:
                        if (Creature* stormTargetB = asaadAI->GetSelectedStormTarget(POINT_STORM_B))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_B, stormTargetB->GetPosition());
                        break;
                    case EVENT_STORM_MOVE_C:
                        DoCast(me, SPELL_STORM_RUNE_BEAM_B);
                        if (Creature* stormTargetC = asaadAI->GetSelectedStormTarget(POINT_STORM_C))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_C, stormTargetC->GetPosition());
                        break;
                    case EVENT_STORM_MOVE_A:
                        me->CastStop();
                        DoCast(me, SPELL_STORM_RUNE_BEAM_C);
                        if (Creature* stormTargetA = asaadAI->GetSelectedStormTarget(POINT_STORM_A))
                            me->GetMotionMaster()->MovePoint(POINT_STORM_A, stormTargetA->GetPosition());
                        break;
                    case EVENT_STORM_ASAAD_TELEPORT:
                        asaadAI->DoAction(ACTION_SUPREMACY_OF_THE_STORM);
                        me->DespawnOrUnsummon(700);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        AsaadAI* asaadAI;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_unstable_grounding_fieldAI>(creature);
    }
};

// 47000 - Grounding Field
class npc_asaad_grounding_field : public CreatureScript
{
public:
    npc_asaad_grounding_field() : CreatureScript("npc_asaad_grounding_field") { }

    struct npc_asaad_grounding_fieldAI : public ScriptedAI
    {
        npc_asaad_grounding_fieldAI(Creature* creature) : ScriptedAI(creature)
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

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_asaad_grounding_fieldAI>(creature);
    }
};

// 86632 - SOTS Targeting
class spell_sots_targeting : public SpellScriptLoader
{
public:
    spell_sots_targeting() : SpellScriptLoader("spell_sots_targeting") { }

    class spell_sots_targeting_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sots_targeting_SpellScript);

        void SelectRandom(std::list<WorldObject*>& targets)
        {
            Trinity::Containers::RandomResizeList(targets, 1);
        }

        void HandleDummy(SpellEffIndex /*effIndex*/)
        {
            if (Creature* creature = GetHitCreature())
                creature->GetAI()->DoAction(ACTION_SOTS_TARGET);
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_sots_targeting_SpellScript::SelectRandom, EFFECT_0, TARGET_UNIT_DEST_AREA_ENTRY);
            OnEffectHitTarget += SpellEffectFn(spell_sots_targeting_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sots_targeting_SpellScript();
    }
};

// 86926  - SOTS Trigger (makes Asaad channel Unstable Grounding Field)
class spell_sots_trigger : public SpellScriptLoader
{
public:
    spell_sots_trigger() : SpellScriptLoader("spell_sots_trigger") { }

    class spell_sots_trigger_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_sots_trigger_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            if (!sSpellMgr->GetSpellInfo(SPELL_UNSTABLE_GROUNDING_FIELD))
                return false;
            return true;
        }

        void HandleScriptEffect(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_UNSTABLE_GROUNDING_FIELD, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_sots_trigger_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_sots_trigger_SpellScript();
    }
};

// 86981 - Storm Rune Beam AA
// 86921 - Storm Rune Beam A
// 86923 - Storm Rune Beam B
// 86925 - Storm Rune Beam C
class spell_storm_rune_beam : public SpellScriptLoader
{
public:
    spell_storm_rune_beam() : SpellScriptLoader("spell_storm_rune_beam") { }

    class spell_storm_rune_beam_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_storm_rune_beam_SpellScript);

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
                    target = ENSURE_AI(AsaadAI, asaad->AI())->GetSelectedStormTarget(POINT_STORM_A);
                    break;
                case SPELL_STORM_RUNE_BEAM_B:
                    target = ENSURE_AI(AsaadAI, asaad->AI())->GetSelectedStormTarget(POINT_STORM_B);
                    break;
                case SPELL_STORM_RUNE_BEAM_C:
                    target = ENSURE_AI(AsaadAI, asaad->AI())->GetSelectedStormTarget(POINT_STORM_C);
                    break;
                default:
                    break;
            }
        }

        void Register() override
        {
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_storm_rune_beam_SpellScript::SetTarget, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_storm_rune_beam_SpellScript();
    }
};

// 87517 - Grounding Field Visual Beams
class spell_grounding_field_visual_beams : public SpellScriptLoader
{
public:
    spell_grounding_field_visual_beams() : SpellScriptLoader("spell_grounding_field_visual_beams") { }

    class spell_grounding_field_visual_beams_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_grounding_field_visual_beams_SpellScript);

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
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_grounding_field_visual_beams_SpellScript::SetTargetA, EFFECT_0, TARGET_UNIT_NEARBY_ENTRY);
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_grounding_field_visual_beams_SpellScript::SetTargetB, EFFECT_1, TARGET_UNIT_NEARBY_ENTRY);
            OnObjectTargetSelect += SpellObjectTargetSelectFn(spell_grounding_field_visual_beams_SpellScript::SetTargetC, EFFECT_2, TARGET_UNIT_NEARBY_ENTRY);
        }

    private:
        Creature* GetStormTarget(uint32 point)
        {
            if (InstanceScript* instance = GetCaster()->GetInstanceScript())
                if (Creature* asaad = instance->GetCreature(DATA_ASAAD))
                    return ENSURE_AI(AsaadAI, asaad->AI())->GetSelectedStormTarget(point);
            return NULL;
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_grounding_field_visual_beams_SpellScript();
    }
};

// 87553/93994 - Supremacy of the Storm (massive aoe damage)
class spell_supremacy_of_the_storm : public SpellScriptLoader
{
public:
    spell_supremacy_of_the_storm() : SpellScriptLoader("spell_supremacy_of_the_storm") { }

    class spell_supremacy_of_the_storm_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_supremacy_of_the_storm_SpellScript);

        void FilterTargets(std::list<WorldObject*>& targets)
        {
            InstanceScript* instance = GetCaster()->GetInstanceScript();
            if (!instance)
                return;

            Creature* asaad = instance->GetCreature(DATA_ASAAD);
            if (!asaad)
                return;

            AsaadAI* asaadAI = CAST_AI(AsaadAI, asaad->AI());

            if (Creature* stormTargetA = asaadAI->GetSelectedStormTarget(POINT_STORM_A))
                if (Creature* stormTargetB = asaadAI->GetSelectedStormTarget(POINT_STORM_B))
                    if (Creature* stormTargetC = asaadAI->GetSelectedStormTarget(POINT_STORM_C))
                        targets.remove_if(TargetInTriangleCheck(false, stormTargetA->GetPosition(), stormTargetB->GetPosition(), stormTargetC->GetPosition()));
        }

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_supremacy_of_the_storm_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_supremacy_of_the_storm_SpellScript();
    }
};

void AddSC_boss_asaad()
{
    new boss_asaad();
    new npc_storm_target();
    new npc_unstable_grounding_field();
    new npc_asaad_grounding_field();
    new spell_sots_targeting();
    new spell_sots_trigger();
    new spell_storm_rune_beam();
    new spell_grounding_field_visual_beams();
    new spell_supremacy_of_the_storm();
}
