/*
 * Copyright (C) 2008-2011 TrinityCore <http://www.trinitycore.org/>
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

#include "ObjectMgr.h"
#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "SpellAuras.h"
#include "MapManager.h"
#include "icecrown_citadel.h"

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

uint32 const boneSpikeSummonId[3] = {69062, 72669, 72670};

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

#define DATA_COLDFLAME_GUID 0

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
                _introDone = false;
                _boneSlice = false;
            }

            void Reset()
            {
                _Reset();
                me->SetSpeed(MOVE_RUN, _baseSpeed, true);
                me->RemoveAurasDueToSpell(SPELL_BONE_STORM);
                me->RemoveAurasDueToSpell(SPELL_BERSERK);
                events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(10000, 15000), EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_COLDFLAME, 5000, EVENT_GROUP_SPECIAL);
                events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(45000, 50000));
                events.ScheduleEvent(EVENT_ENRAGE, 600000);
            }

            void EnterCombat(Unit* /*who*/)
            {
                Talk(SAY_AGGRO);

                me->setActive(true);
                DoZoneInCombat();
                instance->SetBossState(DATA_LORD_MARROWGAR, IN_PROGRESS);
            }

            void JustDied(Unit* /*killer*/)
            {
                Talk(SAY_DEATH);

                _JustDied();
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                instance->SetBossState(DATA_LORD_MARROWGAR, FAIL);
                instance->SetData(DATA_BONED_ACHIEVEMENT, uint32(true));    // reset
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void MoveInLineOfSight(Unit* who)
            {
                if (!_introDone && me->IsWithinDistInMap(who, 70.0f))
                {
                    Talk(SAY_ENTER_ZONE);
                    _introDone = true;
                }
            }

            void UpdateAI(uint32 const diff)
            {
                if (!UpdateVictim() || !CheckInRoom())
                    return;

                events.Update(diff);

                if (me->HasUnitState(UNIT_STAT_CASTING))
                    return;

                while (uint32 eventId = events.ExecuteEvent())
                {
                    switch (eventId)
                    {
                        case EVENT_BONE_SPIKE_GRAVEYARD:
                            if (IsHeroic() || !me->HasAura(SPELL_BONE_STORM))
                                DoCast(me, SPELL_BONE_SPIKE_GRAVEYARD);
                            events.ScheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(15000, 20000), EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_COLDFLAME:
                            _coldflameLastPos.Relocate(me);
                            _coldflameTarget = 0LL;
                            if (!me->HasAura(SPELL_BONE_STORM))
                                DoCastAOE(SPELL_COLDFLAME_NORMAL);
                            else
                                DoCast(me, SPELL_COLDFLAME_BONE_STORM);
                            events.ScheduleEvent(EVENT_COLDFLAME, 5000, EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_WARN_BONE_STORM:
                            _boneSlice = false;
                            Talk(EMOTE_BONE_STORM);
                            me->FinishSpell(CURRENT_MELEE_SPELL, false);
                            DoCast(me, SPELL_BONE_STORM);
                            events.DelayEvents(3000, EVENT_GROUP_SPECIAL);
                            events.ScheduleEvent(EVENT_BONE_STORM_BEGIN, 3050);
                            events.ScheduleEvent(EVENT_WARN_BONE_STORM, urand(90000, 95000));
                            break;
                        case EVENT_BONE_STORM_BEGIN:
                            if (Aura* pStorm = me->GetAura(SPELL_BONE_STORM))
                                pStorm->SetDuration(int32(_boneStormDuration));
                            me->SetSpeed(MOVE_RUN, _baseSpeed*3.0f, true);
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
                                me->GetMotionMaster()->MovePoint(POINT_TARGET_BONESTORM_PLAYER, unit->GetPositionX(), unit->GetPositionY(), unit->GetPositionZ());
                            break;
                        }
                        case EVENT_BONE_STORM_END:
                            if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                                me->GetMotionMaster()->MovementExpired();
                            DoStartMovement(me->getVictim());
                            me->SetSpeed(MOVE_RUN, _baseSpeed, true);
                            events.CancelEvent(EVENT_BONE_STORM_MOVE);
                            events.ScheduleEvent(EVENT_ENABLE_BONE_SLICE, 10000);
                            if (!IsHeroic())
                                events.RescheduleEvent(EVENT_BONE_SPIKE_GRAVEYARD, urand(15000, 20000), EVENT_GROUP_SPECIAL);
                            break;
                        case EVENT_ENABLE_BONE_SLICE:
                            _boneSlice = true;
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_BERSERK, true);
                            Talk(SAY_BERSERK);
                            break;
                    }
                }

                // We should not melee attack when storming
                if (me->HasAura(SPELL_BONE_STORM))
                    return;

                // 10 seconds since encounter start Bone Slice replaces melee attacks
                if (_boneSlice && !me->GetCurrentSpell(CURRENT_MELEE_SPELL))
                    DoCastVictim(SPELL_BONE_SLICE);

                DoMeleeAttackIfReady();
            }

            void MovementInform(uint32 type, uint32 id)
            {
                if (type != POINT_MOTION_TYPE || id != POINT_TARGET_BONESTORM_PLAYER)
                    return;

                // lock movement
                DoStartNoMovement(me->getVictim());
            }

            Position const* GetLastColdflamePosition() const
            {
                return &_coldflameLastPos;
            }

            uint64 GetGUID(int32 type/* = 0 */)
            {
                if (type == DATA_COLDFLAME_GUID)
                    return _coldflameTarget;
                return 0LL;
            }

            void SetGUID(uint64 guid, int32 type/* = 0 */)
            {
                if (type != DATA_COLDFLAME_GUID)
                    return;

                _coldflameTarget = guid;
            }

        private:
            Position _coldflameLastPos;
            uint64 _coldflameTarget;
            uint32 _boneStormDuration;
            float _baseSpeed;
            bool _introDone;
            bool _boneSlice;
        };

        CreatureAI* GetAI(Creature* creature) const
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

            void IsSummonedBy(Unit* owner)
            {
                if (owner->GetTypeId() != TYPEID_UNIT)
                    return;

                Creature* creOwner = owner->ToCreature();
                Position pos;
                // random target case
                if (owner->HasAura(SPELL_BONE_STORM))
                {
                    if (MarrowgarAI* marrowgarAI = CAST_AI(MarrowgarAI, creOwner->AI()))
                    {
                        Position const* ownerPos = marrowgarAI->GetLastColdflamePosition();
                        float ang = me->GetAngle(ownerPos) - static_cast<float>(M_PI);
                        MapManager::NormalizeOrientation(ang);
                        me->SetOrientation(ang);
                        owner->GetNearPosition(pos, 2.5f, 0.0f);
                    }
                }
                else
                {
                    Player* target = ObjectAccessor::GetPlayer(*owner, owner->GetAI()->GetGUID(DATA_COLDFLAME_GUID));
                    if (!target)
                    {
                        me->DespawnOrUnsummon();
                        return;
                    }

                    me->SetOrientation(owner->GetAngle(target));
                    owner->GetNearPosition(pos, owner->GetObjectSize() / 2.0f, 0.0f);
                }

                me->NearTeleportTo(pos.GetPositionX(), pos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                _events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 450);
            }

            void UpdateAI(uint32 const diff)
            {
                _events.Update(diff);

                if (_events.ExecuteEvent() == EVENT_COLDFLAME_TRIGGER)
                {
                    Position newPos;
                    me->GetNearPosition(newPos, 5.5f, 0.0f);
                    me->NearTeleportTo(newPos.GetPositionX(), newPos.GetPositionY(), me->GetPositionZ(), me->GetOrientation());
                    DoCast(SPELL_COLDFLAME_SUMMON);
                    _events.ScheduleEvent(EVENT_COLDFLAME_TRIGGER, 450);
                }
            }

        private:
            EventMap _events;
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetIcecrownCitadelAI<npc_coldflameAI>(creature);
        }
};

class npc_bone_spike : public CreatureScript
{
    public:
        npc_bone_spike() : CreatureScript("npc_bone_spike") { }

        struct npc_bone_spikeAI : public Scripted_NoMovementAI
        {
            npc_bone_spikeAI(Creature* creature) : Scripted_NoMovementAI(creature), _hasTrappedUnit(false)
            {
                ASSERT(creature->GetVehicleKit());
            }

            void JustDied(Unit* /*killer*/)
            {
                if (TempSummon* summ = me->ToTempSummon())
                    if (Unit* trapped = summ->GetSummoner())
                        trapped->RemoveAurasDueToSpell(SPELL_IMPALED);

                me->DespawnOrUnsummon();
            }

            void KilledUnit(Unit* victim)
            {
                me->DespawnOrUnsummon();
                victim->RemoveAurasDueToSpell(SPELL_IMPALED);
            }

            void IsSummonedBy(Unit* summoner)
            {
                DoCast(summoner, SPELL_IMPALED);
                summoner->CastSpell(me, SPELL_RIDE_VEHICLE, true);
                _events.ScheduleEvent(EVENT_FAIL_BONED, 8000);
                _hasTrappedUnit = true;
            }

            void UpdateAI(uint32 const diff)
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

        CreatureAI* GetAI(Creature* creature) const
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

            void SelectTarget(std::list<Unit*>& targets)
            {
                targets.clear();
                // select any unit but not the tank (by owners threatlist)
                Unit* target = GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_RANDOM, 1, -GetCaster()->GetObjectSize(), true, -SPELL_IMPALED);
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

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_marrowgar_coldflame_SpellScript::SelectTarget, EFFECT_0, TARGET_UNIT_DEST_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_coldflame_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
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

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_coldflame_SpellScript::HandleScriptEffect, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
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

            void OnPeriodic(AuraEffect const* /*aurEff*/)
            {
                if (DynamicObject* owner = GetDynobjOwner())
                    if (GetTarget()->GetExactDist2d(owner) >= owner->GetRadius() || GetTarget()->HasAura(SPELL_IMPALED))
                        PreventDefaultAction();
            }

            void Register()
            {
                OnEffectPeriodic += AuraEffectPeriodicFn(spell_marrowgar_coldflame_damage_AuraScript::OnPeriodic, EFFECT_0, SPELL_AURA_PERIODIC_DAMAGE);
            }
        };

        AuraScript* GetAuraScript() const
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

            SpellCastResult CheckCast()
            {
                return GetCaster()->GetAI()->SelectTarget(SELECT_TARGET_TOPAGGRO, 1, 0.0f, true, -SPELL_IMPALED) ? SPELL_CAST_OK : SPELL_FAILED_NO_VALID_TARGETS;
            }

            void HandleSpikes(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                if (Creature* marrowgar = GetCaster()->ToCreature())
                {
                    bool didHit = false;
                    CreatureAI* marrowgarAI = marrowgar->AI();
                    uint8 boneSpikeCount = uint8(GetCaster()->GetMap()->GetSpawnMode() & 1 ? 3 : 1);
                    for (uint8 i = 0; i < boneSpikeCount; ++i)
                    {
                        // select any unit but not the tank
                        Unit* target = marrowgarAI->SelectTarget(SELECT_TARGET_RANDOM, 1, 150.0f, true, -SPELL_IMPALED);
                        if (!target)
                            break;

                        didHit = true;
                        target->CastCustomSpell(boneSpikeSummonId[i], SPELLVALUE_BASE_POINT0, 0, target, true);
                    }

                    if (didHit)
                        marrowgarAI->Talk(SAY_BONESPIKE);
                }
            }

            void Register()
            {
                OnCheckCast += SpellCheckCastFn(spell_marrowgar_bone_spike_graveyard_SpellScript::CheckCast);
                OnEffectHitTarget += SpellEffectFn(spell_marrowgar_bone_spike_graveyard_SpellScript::HandleSpikes, EFFECT_1, SPELL_EFFECT_APPLY_AURA);
            }
        };

        SpellScript* GetSpellScript() const
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
                SetHitDamage(int32(GetHitDamage() / std::max(sqrtf(GetHitUnit()->GetExactDist2d(GetCaster())), 1.0f)));
            }

            void Register()
            {
                OnHit += SpellHitFn(spell_marrowgar_bone_storm_SpellScript::RecalculateDamage);
            }
        };

        SpellScript* GetSpellScript() const
        {
            return new spell_marrowgar_bone_storm_SpellScript();
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
}
