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
#include "GameObject.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "stonecore.h"

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
    ACTION_STALACTITE_MISSLE
};

enum Events
{
    EVENT_NONE,

    // Intro events
    EVENT_LAND_INTRO,
    EVENT_ROAR_EMOTE,

    // Slabhide combat
    EVENT_HANDLE_ROCK_WALLS,
    EVENT_LAVA_FISSURE,
    EVENT_SAND_BLAST,
    EVENT_AIR_PHASE,
    EVENT_STALACTITE,
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
    POINT_NONE,

    POINT_SLABHIDE_INTRO,
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

class boss_slabhide : public CreatureScript
{
    public:
        boss_slabhide() : CreatureScript("boss_slabhide") { }

        struct boss_slabhideAI : public BossAI
        {
            boss_slabhideAI(Creature* creature) : BossAI(creature, DATA_SLABHIDE)
            {
                Initialize();
            }

            void Initialize()
            {
                _isFlying = false;
            }

            void Reset() override
            {
                _Reset();
                Initialize();

                if (instance->GetData(DATA_EVENT_PROGRESS) == EVENT_INDEX_SLABHIDE_INTRO)
                {
                    me->SetCanFly(false);
                    me->SetDisableGravity(false);
                    me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                }
                else
                {
                    me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                    me->setActive(true);
                    me->SetCanFly(true);
                    me->SetDisableGravity(true);
                    me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                    me->SetReactState(REACT_PASSIVE);
                    events.SetPhase(PHASE_INTRO);
                }
            }

            void DamageTaken(Unit* /*attacker*/, uint32& damage) override
            {
                if (_isFlying && damage >= me->GetHealth())
                    damage = me->GetHealth() - 1; // Let creature health fall to 1 hp but prevent it from dying during air phase.
            }

            void JustEngagedWith(Unit* /*victim*/) override
            {
                _JustEngagedWith();
                instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);

                events.SetPhase(PHASE_COMBAT);
                events.ScheduleEvent(EVENT_HANDLE_ROCK_WALLS, Seconds(4));
                events.ScheduleEvent(EVENT_LAVA_FISSURE, Seconds(6), Seconds(8));
                events.ScheduleEvent(EVENT_SAND_BLAST, Seconds(8), Seconds(10));
                events.ScheduleEvent(EVENT_AIR_PHASE, Seconds(10));
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
                        events.ScheduleEvent(EVENT_LAND_INTRO, Milliseconds(200));
                        break;
                    case POINT_SLABHIDE_INTRO_LAND:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetHover(false);
                        me->SetHomePosition(SlabhideIntroLandPos);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
                        me->SetReactState(REACT_AGGRESSIVE);
                        break;
                    case POINT_SLABHIDE_MIDDLE:
                        _isFlying = true;
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetHover(true);
                        me->GetMotionMaster()->MoveTakeoff(POINT_SLABHIDE_IN_AIR, SlabhideInAirPos);
                        break;
                    case POINT_SLABHIDE_IN_AIR:
                        events.ScheduleEvent(EVENT_STALACTITE, Milliseconds(400));
                        break;
                    case POINT_SLABHIDE_LAND:
                        _isFlying = false;
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetHover(false);
                        DoCast(me, SPELL_COOLDOWN_5S);
                        events.ScheduleEvent(EVENT_ATTACK, Seconds(1) + Milliseconds(200));
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
                            events.Repeat(Seconds(6), Seconds(8));
                            break;
                        case EVENT_SAND_BLAST:
                            DoCast(me, SPELL_SAND_BLAST);
                            events.Repeat(Seconds(8), Seconds(11));
                            break;
                        case EVENT_AIR_PHASE:
                            events.Reset();
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            me->GetMotionMaster()->MovePoint(POINT_SLABHIDE_MIDDLE, SlabhideMiddlePos);
                            events.Repeat(Seconds(60));
                            break;
                        case EVENT_STALACTITE:
                            DoCast(me, SPELL_STALACTITE_SUMMON);
                            events.ScheduleEvent(EVENT_LAND, Seconds(8));
                            break;
                        case EVENT_LAND:
                            me->GetMotionMaster()->MoveLand(POINT_SLABHIDE_LAND, SlabhideMiddlePos);
                            break;
                        case EVENT_ATTACK:
                            events.ScheduleEvent(EVENT_LAVA_FISSURE, Seconds(6), Seconds(8));
                            events.ScheduleEvent(EVENT_SAND_BLAST, Seconds(8), Seconds(10));
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

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<boss_slabhideAI>(creature);
        }
};

class npc_slabhide_lava_fissure : public CreatureScript
{
    public:
        npc_slabhide_lava_fissure() : CreatureScript("npc_slabhide_lava_fissure") { }

        struct npc_slabhide_lava_fissureAI : public ScriptedAI
        {
            npc_slabhide_lava_fissureAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(me, SPELL_LAVA_FISSURE_CRACK, true);
                _events.ScheduleEvent(EVENT_LAVA_FISSURE_ERUPTION, IsHeroic() ? Seconds(3) : Seconds(5));
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
                            DoCast(me, SPELL_LAVA_FISSURE_ERUPTION, true);
                            me->DespawnOrUnsummon(IsHeroic() ? Seconds(30) : Seconds(10));
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<npc_slabhide_lava_fissureAI>(creature);
        }
};

class npc_slabhide_stalactite_trigger : public CreatureScript
{
    public:
        npc_slabhide_stalactite_trigger() : CreatureScript("npc_slabhide_stalactite_trigger") { }

        struct npc_slabhide_stalactite_triggerAI : public ScriptedAI
        {
            npc_slabhide_stalactite_triggerAI(Creature* creature) : ScriptedAI(creature) { }

            void IsSummonedBy(Unit* /*summoner*/) override
            {
                DoCast(me, SPELL_STALACTITE_SHADE, true);
                _events.ScheduleEvent(EVENT_STALACTITE_MISSLE, Seconds(1) + Milliseconds(300));
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                while (uint32 eventId = _events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_STALACTITE_MISSLE:
                            DoCast(me, SPELL_STALACTITE_MISSILE);
                            me->DespawnOrUnsummon(Seconds(11));
                            break;
                        default:
                            break;
                    }
                }
            }

        private:
            EventMap _events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStonecoreAI<npc_slabhide_stalactite_triggerAI>(creature);
    }
};

class spell_slabhide_stalactite : public SpellScript
{
    PrepareSpellScript(spell_slabhide_stalactite);

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
        OnHit += SpellHitFn(spell_slabhide_stalactite::SummonStalactiteTrigger);
    }
};

class spell_slabhide_stalactite_summon : public SpellScript
{
    PrepareSpellScript(spell_slabhide_stalactite_summon);

    void SetDest(SpellDestination& dest)
    {
        dest.RelocateOffset({ 0.0f, 0.0f, 55.0f, 0.0f });
    }

    void Register() override
    {
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_slabhide_stalactite_summon::SetDest, EFFECT_0, TARGET_DEST_CASTER_RANDOM);
    }
};

class spell_slabhide_stalactite_dest_relocation : public SpellScript
{
    PrepareSpellScript(spell_slabhide_stalactite_dest_relocation);

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
        OnDestinationTargetSelect += SpellDestinationTargetSelectFn(spell_slabhide_stalactite_dest_relocation::SetDest, EFFECT_0, TARGET_DEST_CASTER);
    }
};

class spell_slabhide_crystal_storm_periodic : public SpellScript
{
    PrepareSpellScript(spell_slabhide_crystal_storm_periodic);

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
        OnEffectHitTarget += SpellEffectFn(spell_slabhide_crystal_storm_periodic::HandleDummy, EFFECT_0, SPELL_EFFECT_APPLY_AURA);
    }
};

void AddSC_boss_slabhide()
{
    new boss_slabhide();
    new npc_slabhide_lava_fissure();
    new npc_slabhide_stalactite_trigger();
    RegisterSpellScript(spell_slabhide_stalactite);
    RegisterSpellScript(spell_slabhide_stalactite_summon);
    RegisterSpellScript(spell_slabhide_stalactite_dest_relocation);
    RegisterSpellScript(spell_slabhide_crystal_storm_periodic);
}
