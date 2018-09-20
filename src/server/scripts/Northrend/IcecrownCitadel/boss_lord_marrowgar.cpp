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
#include "icecrown_citadel.h"
#include "InstanceScript.h"
#include "Map.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "PointMovementGenerator.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "SpellScript.h"
#include "TemporarySummon.h"

enum ScriptTexts
{
    SAY_ENTER_ZONE              = 0,
    SAY_AGGRO                   = 1,
    SAY_BONE_STORM              = 2,
    SAY_BONESPIKE               = 3,
    SAY_KILL                    = 4,
    SAY_DEATH                   = 5,
    SAY_BERSERK                 = 6,
    EMOTE_BONE_STORM            = 7,
};

enum Spells
{
    // Lord Marrowgar
    SPELL_BONE_SLICE            = 69055,
    SPELL_BONE_STORM            = 69076,
    SPELL_BONE_SPIKE_GRAVEYARD  = 69057,
    SPELL_COLDFLAME_NORMAL      = 69140,
    SPELL_COLDFLAME_BONE_STORM  = 72705,

    // Bone Spike
    SPELL_IMPALED               = 69065,
    SPELL_RIDE_VEHICLE          = 46598,

    // Coldflame
    SPELL_COLDFLAME_PASSIVE     = 69145,
    SPELL_COLDFLAME_SUMMON      = 69147,
};

uint32 const BoneSpikeSummonId[3] = {69062, 72669, 72670};

enum Events
{
    EVENT_BONE_SPIKE_GRAVEYARD  = 1,
    EVENT_COLDFLAME             = 2,
    EVENT_BONE_STORM_BEGIN      = 3,
    EVENT_BONE_STORM_MOVE       = 4,
    EVENT_BONE_STORM_END        = 5,
    EVENT_ENABLE_BONE_SLICE     = 6,
    EVENT_ENRAGE                = 7,
    EVENT_WARN_BONE_STORM       = 8,

    EVENT_COLDFLAME_TRIGGER     = 9,
    EVENT_FAIL_BONED            = 10,

    EVENT_GROUP_SPECIAL         = 1,
};

enum MovementPoints
{
    POINT_TARGET_BONESTORM_PLAYER   = 36612631,
    POINT_TARGET_COLDFLAME          = 36672631,
};

enum MiscInfo
{
    DATA_COLDFLAME_GUID             = 0,

    // Manual marking for targets hit by Bone Slice as no aura exists for this purpose
    // These units are the tanks in this encounter
    // and should be immune to Bone Spike Graveyard
    DATA_SPIKE_IMMUNE               = 1,
    //DATA_SPIKE_IMMUNE_1,          = 2, // Reserved & used
    //DATA_SPIKE_IMMUNE_2,          = 3, // Reserved & used

    MAX_BONE_SPIKE_IMMUNE           = 3,
};

enum Actions
{
    ACTION_CLEAR_SPIKE_IMMUNITIES = 1,
    ACTION_TALK_ENTER_ZONE        = 2
};

class BoneSpikeTargetSelector : public std::unary_function<Unit*, bool>
{
    public:
        BoneSpikeTargetSelector(UnitAI* ai) : _ai(ai) { }

        bool operator()(Unit* unit) const
        {
            if (unit->GetTypeId() != TYPEID_PLAYER)
                return false;

            if (unit->HasAura(SPELL_IMPALED))
                return false;

            // Check if it is one of the tanks soaking Bone Slice
            for (uint32 i = 0; i < MAX_BONE_SPIKE_IMMUNE; ++i)
                if (unit->GetGUID() == _ai->GetGUID(DATA_SPIKE_IMMUNE + i))
                    return false;

            return true;
        }

    private:
        UnitAI* _ai;
};

class boss_lord_marrowgar : public CreatureScript
{
    public:
        boss_lord_marrowgar() : CreatureScript("boss_lord_marrowgar") { }

        struct boss_lord_marrowgarAI : public BossAI
        {
            boss_lord_marrowgarAI(Creature* creature) : BossAI(creature, DATA_LORD_MARROWGAR)
            {
                _boneStormDuration = RAID_MODE<uint32>(20000, 30000, 20000, 30000);
                _baseSpeed = creature->GetSpeedRate(MOVE_RUN);
                _coldflameLastPos.Relocate(creature);
                _boneSlice = false;
            }

            void Reset() override
            {
                _Reset();
                me->SetSpeedRate(MOVE_RUN, _baseSpeed);
                me->RemoveAurasDueToSpell(SPELL_BONE_STORM);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10s);
                events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, 15s, EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_COLDFLAME, 5s, EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_WARN_BONE_STORM, 45s, 50s);
                events.ScheduleEvent(EVENT_ENRAGE, 10min);
                _boneSlice = false;
                _boneSpikeImmune.clear();
            }

            void JustEngagedWith(Unit* /*who*/) override
            {
                Talk(SAY_AGGRO);

                me->setActive(true);
                DoZoneInCombat();
                instance->SetBossState(DATA_LORD_MARROWGAR, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/) override
            {
                Talk(SAY_DEATH);

                _JustDied();
            }

            void JustReachedHome() override
            {
                _JustReachedHome();
                instance->SetBossState(DATA_LORD_MARROWGAR, FAIL);
                instance->SetData(DATA_BONED_ACHIEVEMENT, uint32(true));    // reset
            }

            void KilledUnit(Unit* victim) override
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
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
                        case EVENT_BONE_SPIKE_GRAVEYARD:
                            if (IsHeroic() || !me->HasAura(SPELL_BONE_STORM))
                                DoCast(me, SPELL_BONE_SPIKE_GRAVEYARD);
                            events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, 15s, 20s, EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_COLDFLAME:
                            _coldflameLastPos.Relocate(me);
                            _coldflameTarget.Clear();
                            if (!me->HasAura(SPELL_BONE_STORM))
                                DoCastAOE(SPELL_COLDFLAME_NORMAL);
                            else
                                DoCast(me, SPELL_COLDFLAME_BONE_STORM);
                            events.ScheduleEvent(EVENT_COLDFLAME, 5s, EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_WARN_BONE_STORM:
                            _boneSlice = false;
                            Talk(EMOTE_BONE_STORM);
                            me->FinishSpell(CURRENT_MELEE_SPELL, false);
                            DoCast(me, SPELL_BONE_STORM);
                            events.DelayEvents(3000, EVENT_GROUP_SPECIAL);
                            events.ScheduleEvent(EVENT_BONE_STORM_BEGIN, 3050);
                            events.ScheduleEvent(EVENT_WARN_BONE_STORM, 90s, 95s);
                            break;
                        case EVENT_BONE_STORM_BEGIN:
                            if (Aura* pStorm = me->GetAura(SPELL_BONE_STORM))
                                pStorm->SetDuration(int32(_boneStormDuration));
                            me->SetSpeedRate(MOVE_RUN, _baseSpeed*3.0f);
                            Talk(SAY_BONE_STORM);
                            events.ScheduleEvent(EVENT_BONE_STORM_END, _boneStormDuration+1);
                            // no break here
                        case EVENT_BONE_STORM_MOVE:
                        {
                            events.ScheduleEvent(EVENT_BONE_STORM_MOVE, _boneStormDuration/3);
                            Unit* unit = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me));
                            if (!unit)
                                unit = SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true);
                            if (unit)
                                me->GetMotionMaster()->MovePoint(POINT_TARGET_BONESTORM_PLAYER, *unit);
                            break;
                        }
                        case EVENT_BONE_STORM_END:
                            if (MovementGenerator* movement = me->GetMotionMaster()->GetMovementGenerator([](MovementGenerator const* a) -> bool
                            {
                                if (a->GetMovementGeneratorType() == POINT_MOTION_TYPE)
                                {
                                    PointMovementGenerator<Creature> const* pointMovement = dynamic_cast<PointMovementGenerator<Creature> const*>(a);
                                    return pointMovement && pointMovement->GetId() == POINT_TARGET_BONESTORM_PLAYER;
                                }
                                return false;
                            }))
                                me->GetMotionMaster()->Remove(movement);
                            me->GetMotionMaster()->MoveChase(me->GetVictim());
                            me->SetSpeedRate(MOVE_RUN, _baseSpeed);
                            events.CancelEvent(EVENT_BONE_STORM_MOVE);
                            events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10s);
                            if (!IsHeroic())
                                events.RescheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, 15000, EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_ENABLE_BONE_SLICE:
                            _boneSlice = true;
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            break;
                    }

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                // We should not melee attack when storming
                if (me->HasAura(SPELL_BONE_STORM))
                    return;

                // 10 seconds since encounter start Bone Slice replaces melee attacks
                if (_boneSlice && !me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                    DoCastVictim(SPELL_BONE_SLICE);

                DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE || id != POINT_TARGET_BONESTORM_PLAYER)
                    return;

                // lock movement
                me->GetMotionMaster()->MoveIdle();
            }

            Position const* GetLastColdflamePosition() const
            {
                return &_coldflameLastPos;
            }

            ObjectGuid GetGUID(int32 type /*= 0 */) const override
            {
                switch (type)
                {
                    case DATA_COLDFLAME_GUID:
                        return _coldflameTarget;
                    case DATA_SPIKE_IMMUNE + 0:
                    case DATA_SPIKE_IMMUNE + 1:
                    case DATA_SPIKE_IMMUNE + 2:
                    {
                        uint32 index = uint32(type - DATA_SPIKE_IMMUNE);
                        if (index < _boneSpikeImmune.size())
                            return _boneSpikeImmune[index];

                        break;
                    }
                }

                return ObjectGuid::Empty;
            }

            void SetGUID(ObjectGuid const& guid, int32 id) override
            {
                switch (id)
                {
                    case DATA_COLDFLAME_GUID:
                        _coldflameTarget = guid;
                        break;
                    case DATA_SPIKE_IMMUNE:
                        _boneSpikeImmune.push_back(guid);
                        break;
                }
            }

            void DoAction(int32 action) override
            {
                switch (action)
                {
                    case ACTION_CLEAR_SPIKE_IMMUNITIES:
                        _boneSpikeImmune.clear();
                        break;
                    case ACTION_TALK_ENTER_ZONE:
                            Talk(SAY_ENTER_ZONE);
                        break;
                    default:
                        break;
                }
            }

        private:
            Position _coldflameLastPos;
            GuidVector _boneSpikeImmune;
            ObjectGuid _coldflameTarget;
            uint32 _boneStormDuration;
            float _baseSpeed;
            bool _boneSlice;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<boss_lord_marrowgarAI>(creature);
        }
};

typedef boss_lord_marrowgar::boss_lord_marrowgarAI MarrowgarAI;

class npc_coldflame : public CreatureScript
{
    public:
        npc_coldflame() : CreatureScript("npc_coldflame") { }

        struct npc_coldflameAI : public ScriptedAI
        {
            npc_coldflameAI(Creature* creature) : ScriptedAI(creature)
            {
            }

            void IsSummonedBy(Unit* owner) override
            {
                if (owner->GetTypeId() != TYPEID_UNIT)
                    return;

                Position pos;
                if (MarrowgarAI* marrowgarAI = CAST_AI(MarrowgarAI, owner->GetAI()))
                    pos.Relocate(marrowgarAI->GetLastColdflamePosition());
                else
                    pos.Relocate(owner);

                if (owner->HasAura(SPELL_BONE_STORM))
                {
                    float ang = pos.GetAbsoluteAngle(me);
                    me->SetOrientation(ang);
                    owner->GetNearPoint2D(nullptr, pos.m_positionX, pos.m_positionY, 5.0f - owner->GetCombatReach(), ang);
                }
                else
                {
                    Player* target = ObjectAccessor::GetPlayer(*owner, owner->GetAI()->GetGUID(DATA_COLDFLAME_GUID));
                    if (!target)
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }

                    float ang = pos.GetAbsoluteAngle(target);
                    me->SetOrientation(ang);
                    owner->GetNearPoint2D(nullptr, pos.m_positionX, pos.m_positionY, 15.0f - owner->GetCombatReach(), ang);
                }

                me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                DoCast(SPELL_COLDFLAME_SUMMON);
                _events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 500ms);
            }

            void UpdateAI(uint32 diff) override
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_COLDFLAME_TRIGGER)
                {
                    Position newPos = me->GetNearPosition(5.0f, 0.0f);
                    me->NearTeleportTo(newPos.GetPositionX(), newPos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    DoCast(SPELL_COLDFLAME_SUMMON);
                    _events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 500ms);
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_coldflameAI>(creature);
        }
};

class npc_bone_spike : public CreatureScript
{
    public:
        npc_bone_spike() : CreatureScript("npc_bone_spike") { }

        struct npc_bone_spikeAI : public ScriptedAI
        {
            npc_bone_spikeAI(Creature* creature) : ScriptedAI(creature), _hasTrappedUnit(false)
            {
                ASSERT(creature->GetVehicleKit());

                SetCombatMovement(false);
            }

            void JustDied(Unit* /*killer*/) override
            {
                if (TempSummon* summ = me->ToTempSummon())
                    if (Unit* trapped = summ->GetSummoner())
                        trapped->RemoveAurasDueToSpell(SPELL_IMPALED);

                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* victim) override
            {
                me->DespawnOrUnsummon();
                victim->RemoveAurasDueToSpell(SPELL_IMPALED);
            }

            void IsSummonedBy(Unit* summoner) override
            {
                DoCast(summoner, SPELL_IMPALED);
                summoner->CastSpell(me, SPELL_RIDE_VEHICLE, true);
                _events.ScheduleEvent(EVENT_FAIL_BONED, 8s);
                _hasTrappedUnit = true;
            }

            void PassengerBoarded(Unit* passenger, int8 /*seat*/, bool apply) override
            {
                if (!apply)
                    return;

                /// @HACK - Change passenger offset to the one taken directly from sniffs
                /// Remove this when proper calculations are implemented.
                /// This fixes healing spiked people
                Movement::MoveSplineInit init(passenger);
                init.DisableTransportPathTransformations();
                init.MoveTo(-0.02206125f, -0.02132235f, 5.514783f, false);
                passenger->GetMotionMaster()->LaunchMoveSpline(std::move(init), EVENT_VEHICLE_BOARD, MOTION_PRIORITY_HIGHEST);
            }

            void UpdateAI(uint32 diff) override
            {
                if (!_hasTrappedUnit)
                    return;

                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_FAIL_BONED)
                    if (InstanceScript* instance = me->GetInstanceScript())
                        instance->SetData(DATA_BONED_ACHIEVEMENT, uint32(false));
            }

        private:
            EventMap _events;
            bool _hasTrappedUnit;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetIcecrownCitadelAI<npc_bone_spikeAI>(creature);
        }
};

class spell_marrowgar_coldflame : public SpellScriptLoader
{
    public:
        spell_marrowgar_coldflame() : SpellScriptLoader("spell_marrowgar_coldflame") { }

        class spell_marrowgar_coldflame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_coldflame_SpellScript);

            void SelectTarget(std::list<WorldObject*>& targets)
            {
                targets.clear();
                // select any unit but not the tank
                Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, -GetCaster()->GetCombatReach(), true, false, -SPELL_IMPALED);
                if (!target)
                    target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, 0.0f, true); // or the tank if its solo
                if (!target)
                    return;

                GetCaster()->GetAI()->SetGUID(target->GetGUID(), DATA_COLDFLAME_GUID);
                targets.push_back(target);
            }

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue()), true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marrowgar_coldflame_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_coldflame_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_marrowgar_coldflame_SpellScript();
        }
};

class spell_marrowgar_coldflame_bonestorm : public SpellScriptLoader
{
    public:
        spell_marrowgar_coldflame_bonestorm() : SpellScriptLoader("spell_marrowgar_coldflame_bonestorm") { }

        class spell_marrowgar_coldflame_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_coldflame_SpellScript);

            void HandleScriptEffect(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                for (uint8 i = 0; i < 4; ++i)
                    GetCaster()->CastSpell(GetHitUnit(), uint32(GetEffectValue() + i), true);
            }

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_coldflame_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_marrowgar_coldflame_SpellScript();
        }
};

class spell_marrowgar_coldflame_damage : public SpellScriptLoader
{
    public:
        spell_marrowgar_coldflame_damage() : SpellScriptLoader("spell_marrowgar_coldflame_damage") { }

        class spell_marrowgar_coldflame_damage_AuraScript : public AuraScript
        {
            PrepareAuraScript(spell_marrowgar_coldflame_damage_AuraScript);

            bool CanBeAppliedOn(Unit* target)
            {
                if (target->HasAura(SPELL_IMPALED))
                    return false;

                if (target->GetExactDist2d(GetOwner()) > GetSpellInfo()->Effects[EFFECT_0].CalcRadius())
                    return false;

                if (Aura* aur = target->GetAura(GetId()))
                    if (aur->GetOwner() != GetOwner())
                        return false;

                return true;
            }

            void Register() override
            {
                DoCheckAreaTarget += AuraCheckAreaTargetFn(spell_marrowgar_coldflame_damage_AuraScript::CanBeAppliedOn);
            }
        };

        AuraScript* GetAuraScript() const override
        {
            return new spell_marrowgar_coldflame_damage_AuraScript();
        }
};

class spell_marrowgar_bone_spike_graveyard : public SpellScriptLoader
{
    public:
        spell_marrowgar_bone_spike_graveyard() : SpellScriptLoader("spell_marrowgar_bone_spike_graveyard") { }

        class spell_marrowgar_bone_spike_graveyard_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_bone_spike_graveyard_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                return ValidateSpellInfo(BoneSpikeSummonId);
            }

            bool Load() override
            {
                return GetCaster()->GetTypeId() == TYPEID_UNIT && GetCaster()->IsAIEnabled();
            }

            SpellCastResult CheckCast()
            {
                return GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 0, BoneSpikeTargetSelector(GetCaster()->GetAI())) ? SPELL_CAST_OK : SPELL_FAILED_NO_VALID_TARGETS;
            }

            void HandleSpikes(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Creature* marrowgar = GetCaster()->ToCreature())
                {
                    CreatureAI* marrowgarAI = marrowgar->AI();
                    uint8 boneSpikeCount = uint8(GetCaster()->GetMap()->GetSpawnMode() & 1 ? 3 : 1);

                    std::list<Unit*> targets;
                    marrowgarAI->SelectTargetList(targets, boneSpikeCount, SELECT_TARGET_RANDOM, 1, BoneSpikeTargetSelector(marrowgarAI));
                    if (targets.empty())
                        return;

                    uint32 i = 0;
                    for (std::list<Unit*>::const_iterator itr = targets.begin(); itr != targets.end(); ++itr, ++i)
                    {
                        Unit* target = *itr;
                        target->CastSpell(target, BoneSpikeSummonId[i], true);
                        if (!target->IsAlive()) // make sure we don't get any stuck spikes on dead targets
                        {
                            if (Aura* aura = target->GetAura(SPELL_IMPALED))
                            {
                                if (Creature* spike = ObjectAccessor::GetCreature(*target, aura->GetCasterGUID()))
                                    spike->DespawnOrUnsummon();
                                aura->Remove();
                            }
                        }
                    }

                    marrowgarAI->Talk(SAY_BONESPIKE);
                }
            }

            void Register() override
            {
                OnCheckCast += SpellCheckCastFn(spell_marrowgar_bone_spike_graveyard_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_bone_spike_graveyard_SpellScript::HandleSpikes, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_marrowgar_bone_spike_graveyard_SpellScript();
        }
};

class spell_marrowgar_bone_storm : public SpellScriptLoader
{
    public:
        spell_marrowgar_bone_storm() : SpellScriptLoader("spell_marrowgar_bone_storm") { }

        class spell_marrowgar_bone_storm_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_bone_storm_SpellScript);

            void RecalculateDamage()
            {
                SetHitDamage(int32(GetHitDamage() / std::max(std::sqrt(GetHitUnit()->GetExactDist2d(GetCaster())), 1.0f)));
            }

            void Register() override
            {
                OnHit += SpellHitFn(spell_marrowgar_bone_storm_SpellScript::RecalculateDamage);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_marrowgar_bone_storm_SpellScript();
        }
};

class spell_marrowgar_bone_slice : public SpellScriptLoader
{
    public:
        spell_marrowgar_bone_slice() : SpellScriptLoader("spell_marrowgar_bone_slice") { }

        class spell_marrowgar_bone_slice_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_marrowgar_bone_slice_SpellScript);

        public:
            spell_marrowgar_bone_slice_SpellScript()
            {
                _targetCount = 0;
            }

        private:
            void ClearSpikeImmunities()
            {
                GetCaster()->GetAI()->DoAction(ACTION_CLEAR_SPIKE_IMMUNITIES);
            }

            void CountTargets(std::list<WorldObject*>& targets)
            {
                _targetCount = std::min<uint32>(targets.size(), GetSpellInfo()->MaxAffectedTargets);
            }

            void SplitDamage()
            {
                // Mark the unit as hit, even if the spell missed or was dodged/parried
                GetCaster()->GetAI()->SetGUID(GetHitUnit()->GetGUID(), DATA_SPIKE_IMMUNE);

                if (!_targetCount)
                    return; // This spell can miss all targets

                SetHitDamage(GetHitDamage() / _targetCount);
            }

            void Register() override
            {
                BeforeCast += SpellCastFn(spell_marrowgar_bone_slice_SpellScript::ClearSpikeImmunities);
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_marrowgar_bone_slice_SpellScript::CountTargets, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnHit += SpellHitFn(spell_marrowgar_bone_slice_SpellScript::SplitDamage);
            }

            uint32 _targetCount;
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_marrowgar_bone_slice_SpellScript();
        }
};

class at_lord_marrowgar_entrance : public OnlyOnceAreaTriggerScript
{
    public:
        at_lord_marrowgar_entrance() : OnlyOnceAreaTriggerScript("at_lord_marrowgar_entrance") { }

        bool _OnTrigger(Player* player, AreaTriggerEntry const* /*areaTrigger*/) override
        {
            if (InstanceScript* instance = player->GetInstanceScript())
                if (Creature* lordMarrowgar = ObjectAccessor::GetCreature(*player, instance->GetGuidData(DATA_LORD_MARROWGAR)))
                    lordMarrowgar->AI()->DoAction(ACTION_TALK_ENTER_ZONE);

            return true;
        }

};

void AddSC_boss_lord_marrowgar()
{
    new boss_lord_marrowgar();
    new npc_coldflame();
    new npc_bone_spike();
    new spell_marrowgar_coldflame();
    new spell_marrowgar_coldflame_bonestorm();
    new spell_marrowgar_coldflame_damage();
    new spell_marrowgar_bone_spike_graveyard();
    new spell_marrowgar_bone_storm();
    new spell_marrowgar_bone_slice();
    new at_lord_marrowgar_entrance();
}
