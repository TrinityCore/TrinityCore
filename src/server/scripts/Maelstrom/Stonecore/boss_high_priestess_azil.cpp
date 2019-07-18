/*
 * Copyright (C) 2008-2019 TrinityCore <https://www.trinitycore.org/>
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
#include "DynamicObject.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "MoveSplineInit.h"
#include "ObjectAccessor.h"
#include "Player.h"
#include "ScriptedCreature.h"
#include "Spell.h"
#include "SpellScript.h"
#include "stonecore.h"
#include "Vehicle.h"
#include <G3D/Vector3.h>

enum Spells
{
    SPELL_ENERGY_SHIELD             = 82858,

    SPELL_CURSE_OF_BLOOD            = 79345,
    SPELL_FORCE_GRIP                = 79351,
    SPELL_SUMMON_GRAVITY_WELL       = 79340,
    SPELL_EARTH_FURY_ENERGY_SHIELD  = 79050,

    // Gravity Well
    SPELL_GRAVITY_WELL_VISUAL       = 79245,
    SPELL_GRAVITY_WELL_AURA_DAMAGE  = 79244,
    SPELL_GRAVITY_WELL_AURA_PULL    = 79333,

    SPELL_GRAVITY_WELL_DAMAGE       = 79249,
    SPELL_GRAVITY_WELL_PULL         = 79332,

    // Fury of Earth phase
    SPELL_EARTH_FURY_CASTING_VISUAL = 79002,
    SPELL_SEISMIC_SHARD_SUMMON_1    = 86860,
    SPELL_SEISMIC_SHARD_SUMMON_2    = 86858,
    SPELL_SEISMIC_SHARD_SUMMON_3    = 86856,
    SPELL_SEISMIC_SHARD_VISUAL      = 79009,
    SPELL_SEISMIC_SHARD_PREPARE     = 86862,
    SPELL_SEISMIC_SHARD_TARGETING   = 80511,
    SPELL_SEISMIC_SHARD_LAUNCH      = 79015,
    SPELL_SEISMIC_SHARD_MISSLE      = 79014,
    SPELL_EJECT_ALL_PASSENGERS      = 68576,

    // Add wave spells
    SPELL_SUMMON_WAVE_SOUTH         = 79200,
    SPELL_SUMMON_WAVE_WEST          = 79196,
    SPELL_SUMMON_ADD_SOUTH          = 79193,
    SPELL_SUMMON_ADD_WEST           = 79199,
};

enum NPCs
{
    NPC_DEVOUT_FOLLOWER       = 42428,
    NPC_SEISMIC_SHARD         = 42355,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_PHASE_TWO = 1,
    SAY_DEATH = 2,
};

enum Events
{
    EVENT_NONE,

    EVENT_INTRO_MOVE,

    EVENT_CURSE_OF_BLOOD,
    EVENT_FORCE_GRIP,
    EVENT_SUMMON_GRAVITY_WELL,
    EVENT_ENERGY_SHIELD,
    EVENT_EARTH_FURY,

    EVENT_SUMMON_WAVE_SOUTH,
    EVENT_SUMMON_WAVE_WEST,

    EVENT_GRAVITY_WELL_AURA_DAMAGE,
    EVENT_GRAVITY_WELL_AURA_PULL,

    // Phase 2: Fury of Earth
    EVENT_EARTH_FURY_FLY_UP,
    EVENT_EARTH_FURY_FLY_ABOVE_PLATFORM,
    EVENT_EARTH_FURY_PREPARE_SHARD,
    EVENT_EARTH_FURY_LAUNCH_SHARD,
    EVENT_EARTH_FURY_FLY_DOWN,
    EVENT_START_ATTACK,

    EVENT_LAUNCH,
    EVENT_SEISMIC_SHARD_MOUNT
};

enum Points
{
    POINT_NONE,

    POINT_INTRO_MOVE,
    POINT_FLY_UP,
    POINT_ABOVE_PLATFORM,
    POINT_PLATFORM,
    POINT_GROUND,
};

Position const GroundPos = { 1331.82f, 980.314f, 207.542f };
Position const AbovePlatformPos = { 1336.21f, 960.813f, 215.0f };

// TO-DO:
// - Find more sniffs and script Force Grip spell (79351)

class boss_high_priestess_azil : public CreatureScript
{
    public:
        boss_high_priestess_azil() : CreatureScript("boss_high_priestess_azil") { }

        struct boss_high_priestess_azilAI : public BossAI
        {
            boss_high_priestess_azilAI(Creature* creature) : BossAI(creature, DATA_HIGH_PRIESTESS_AZIL) { }
            void Reset() override
            {
                _Reset();

                me->SetCanFly(false);
                me->SetDisableGravity(false);
                me->SetReactState(REACT_PASSIVE);

                events.ScheduleEvent(EVENT_INTRO_MOVE, 2000);
                events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 6000);
                events.ScheduleEvent(EVENT_FORCE_GRIP, urand(8000,10000));
                events.ScheduleEvent(EVENT_SUMMON_GRAVITY_WELL, 16000);
                events.ScheduleEvent(EVENT_ENERGY_SHIELD, urand(35000,36000));
                events.ScheduleEvent(EVENT_SUMMON_WAVE_SOUTH, 0);
                events.ScheduleEvent(EVENT_SUMMON_WAVE_WEST, 40000);
            }

            void EnterCombat(Unit* /*victim*/) override
            {
                _EnterCombat();

                DoCast(me, SPELL_ENERGY_SHIELD);
                Talk(SAY_AGGRO);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();

                Talk(SAY_DEATH);
            }

            void MovementInform(uint32 type, uint32 id) override
            {
                if (type != POINT_MOTION_TYPE && id != POINT_INTRO_MOVE)
                    return;

                switch (id)
                {
                    case POINT_INTRO_MOVE:
                        me->RemoveAurasDueToSpell(SPELL_ENERGY_SHIELD);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoStartMovement(me->GetVictim());
                        break;
                    case POINT_FLY_UP:
                        me->SetCanFly(true);
                        me->SetDisableGravity(true);
                        events.ScheduleEvent(EVENT_EARTH_FURY_FLY_ABOVE_PLATFORM, 1000);
                        break;
                    case POINT_ABOVE_PLATFORM:
                        me->SetFacingTo(5.218534f);
                        DoCast(me, SPELL_EARTH_FURY_CASTING_VISUAL);
                        DoCast(me, SPELL_SEISMIC_SHARD_SUMMON_1);
                        DoCast(me, SPELL_SEISMIC_SHARD_SUMMON_2);
                        DoCast(me, SPELL_SEISMIC_SHARD_SUMMON_3);
                        events.ScheduleEvent(EVENT_EARTH_FURY_PREPARE_SHARD, 6700);
                        break;
                    case POINT_GROUND:
                        DoCast(me, SPELL_EJECT_ALL_PASSENGERS);
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoStartMovement(me->GetVictim());
                        // Find more sniffs to correct these timers, this was copied from Reset() void.
                        events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, 6000);
                        events.ScheduleEvent(EVENT_FORCE_GRIP, urand(8000, 10000));
                        events.ScheduleEvent(EVENT_SUMMON_GRAVITY_WELL, 16000);
                        break;
                    default:
                        break;
                }
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
                        case EVENT_INTRO_MOVE:
                            me->GetMotionMaster()->MoveJump(GroundPos, me->GetSpeed(MOVE_FLIGHT), 1.918408f, POINT_INTRO_MOVE);
                            break;
                        case EVENT_CURSE_OF_BLOOD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_CURSE_OF_BLOOD);
                            events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, urand(13000, 15000));
                            break;
                        case EVENT_FORCE_GRIP:
                            DoCastVictim(SPELL_FORCE_GRIP);
                            events.ScheduleEvent(EVENT_CURSE_OF_BLOOD, urand(13000, 15000));
                            break;
                        case EVENT_SUMMON_GRAVITY_WELL:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                                DoCast(target, SPELL_SUMMON_GRAVITY_WELL);
                            events.ScheduleEvent(EVENT_SUMMON_GRAVITY_WELL, urand(13000, 15000));
                            break;
                        case EVENT_ENERGY_SHIELD:
                            events.Reset();
                            DoCast(me, SPELL_EARTH_FURY_ENERGY_SHIELD);
                            events.ScheduleEvent(EVENT_EARTH_FURY, 0);
                            break;
                        case EVENT_EARTH_FURY:
                            countSeismicShard = 3;
                            me->SetReactState(REACT_PASSIVE);
                            me->SetFacingTo(5.862942f);
                            events.ScheduleEvent(EVENT_EARTH_FURY_FLY_UP, 1600);
                            break;
                        case EVENT_EARTH_FURY_FLY_UP:
                            Talk(SAY_PHASE_TWO);
                            me->GetMotionMaster()->MovePoint(POINT_FLY_UP, me->GetPositionX(), me->GetPositionY(), me->GetPositionZ() + 5);
                            break;
                        case EVENT_EARTH_FURY_FLY_ABOVE_PLATFORM:
                            me->GetMotionMaster()->MovePoint(POINT_ABOVE_PLATFORM, AbovePlatformPos);
                            break;
                        case EVENT_EARTH_FURY_PREPARE_SHARD:
                            DoCast(me, SPELL_SEISMIC_SHARD_PREPARE);
                            events.ScheduleEvent(EVENT_EARTH_FURY_LAUNCH_SHARD, 1800);
                            break;
                        case EVENT_EARTH_FURY_LAUNCH_SHARD:
                            if (Unit* target = SelectTarget(SELECT_TARGET_RANDOM, 0, 100.0f, true))
                            {
                                me->SetFacingToObject(target);
                                DoCast(target, SPELL_SEISMIC_SHARD_TARGETING);
                                DoCast(me, SPELL_SEISMIC_SHARD_LAUNCH);
                                countSeismicShard -= 1;
                            }
                            events.ScheduleEvent(countSeismicShard > 0 ? EVENT_EARTH_FURY_PREPARE_SHARD : EVENT_EARTH_FURY_FLY_DOWN, 4800);
                            break;
                        case EVENT_EARTH_FURY_FLY_DOWN:
                        {
                            me->RemoveAurasDueToSpell(SPELL_EARTH_FURY_CASTING_VISUAL);
                            me->RemoveAurasDueToSpell(SPELL_EARTH_FURY_ENERGY_SHIELD);
                            Position pos = me->GetPosition();
                            me->UpdateGroundPositionZ(pos.GetPositionX(), pos.GetPositionY(), pos.m_positionZ);
                            me->GetMotionMaster()->MovePoint(POINT_GROUND, pos);
                            break;
                        }
                        case EVENT_SUMMON_WAVE_SOUTH:
                            if (Creature* worldtrigger = me->FindNearestCreature(NPC_WORLDTRIGGER, 150.0f))
                                worldtrigger->CastSpell(worldtrigger, SPELL_SUMMON_WAVE_SOUTH);
                            events.ScheduleEvent(EVENT_SUMMON_WAVE_SOUTH, 12000);
                            break;
                        case EVENT_SUMMON_WAVE_WEST:
                            if (Creature* worldtrigger = me->FindNearestCreature(NPC_WORLDTRIGGER, 150.0f))
                                worldtrigger->CastSpell(worldtrigger, SPELL_SUMMON_WAVE_WEST);
                            events.ScheduleEvent(EVENT_SUMMON_WAVE_WEST, 20000);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }

        private:
            uint8 countSeismicShard = 3;
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetStonecoreAI<boss_high_priestess_azilAI>(creature);
        }
};

// 42428 - Devout Follower
class npc_devout_follower : public CreatureScript
{
public:
    npc_devout_follower() : CreatureScript("npc_devout_follower") { }

    struct npc_devout_followerAI : public ScriptedAI
    {
        npc_devout_followerAI(Creature* creature) : ScriptedAI(creature) { }

        void IsSummonedBy(Unit* summoner) override
        {
            if (summoner->GetEntry() != NPC_WORLDTRIGGER)
                return;

            if (Unit* target = me->SelectNearestPlayer(200.0f))
            {
                me->AddThreat(target, 0.0f);
                me->SetInCombatWith(target);
                target->SetInCombatWith(me);
                DoStartMovement(target);
                me->Attack(target, true);
            }
            else
                me->GetMotionMaster()->MovePoint(POINT_NONE, summoner->GetPosition());
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStonecoreAI<npc_devout_followerAI>(creature);
    }
};

// 42499 - Gravity Well
class npc_gravity_well : public CreatureScript
{
public:
    npc_gravity_well() : CreatureScript("npc_gravity_well") { }

    struct npc_gravity_wellAI : public ScriptedAI
    {
        npc_gravity_wellAI(Creature* creature) : ScriptedAI(creature)
        {
            DoCast(me, SPELL_GRAVITY_WELL_VISUAL);
            events.ScheduleEvent(EVENT_GRAVITY_WELL_AURA_DAMAGE, 3200);
            events.ScheduleEvent(EVENT_GRAVITY_WELL_AURA_PULL, 4500);
            if (!IsHeroic())
                me->DespawnOrUnsummon(23200);
        }

        void KilledUnit(Unit* victim) override
        {
            if (victim->GetEntry() != NPC_DEVOUT_FOLLOWER)
                return;

            me->SetObjectScale(me->GetObjectScale() - 0.25f);
            if (me->GetObjectScale() <= 0.0f)
                me->DespawnOrUnsummon(1000);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_GRAVITY_WELL_AURA_DAMAGE:
                        me->RemoveAurasDueToSpell(SPELL_GRAVITY_WELL_VISUAL);
                        DoCast(me, SPELL_GRAVITY_WELL_AURA_DAMAGE);
                        break;
                    case EVENT_GRAVITY_WELL_AURA_PULL:
                        DoCast(me, SPELL_GRAVITY_WELL_AURA_PULL);
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
        return GetStonecoreAI<npc_gravity_wellAI>(creature);
    }
};

// 42355 - Seismic Shard
class npc_seismic_shard : public CreatureScript
{
public:
    npc_seismic_shard() : CreatureScript("npc_seismic_shard") { }

    struct npc_seismic_shardAI : public ScriptedAI
    {
        npc_seismic_shardAI(Creature* creature) : ScriptedAI(creature)
        {
            instance = creature->GetInstanceScript();
            me->SetDisableGravity(true);
            DoCast(me, SPELL_SEISMIC_SHARD_VISUAL);

            Movement::MoveSplineInit init(me);
            FillPath(me->GetPosition(), init.Path());
            init.SetFly();
            init.Launch();

            events.ScheduleEvent(EVENT_SEISMIC_SHARD_MOUNT, 2400);
        }

        void UpdateAI(uint32 diff) override
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SEISMIC_SHARD_MOUNT:
                        if (Creature* highPriestAzil = ObjectAccessor::GetCreature(*me, instance->GetGuidData(DATA_HIGH_PRIESTESS_AZIL)))
                            if (Vehicle* vehicle = highPriestAzil->GetVehicleKit())
                                me->EnterVehicle(highPriestAzil, vehicle->GetNextEmptySeat(0, false)->first);
                        break;
                    default:
                        break;
                }
            }

        }

    private:
        void FillPath(Position const& pos, Movement::PointsArray& path)
        {
            G3D::Vector3 point;

            point.x = pos.GetPositionX();
            point.y = pos.GetPositionY();
            point.z = pos.GetPositionZ();

            point.x -= 1.0f;
            path.push_back(point);

            point.x += 1.0f;
            path.push_back(point);

            point.z += 25.0f;
            path.push_back(point);

            path.push_back(point);
        }

        InstanceScript* instance;
        EventMap events;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetStonecoreAI<npc_seismic_shardAI>(creature);
    }
};

// 79200 - Summon Follower
class spell_summon_wave_south : public SpellScriptLoader
{
public:
    spell_summon_wave_south() : SpellScriptLoader("spell_summon_wave_south") { }

    class spell_summon_wave_south_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_wave_south_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SUMMON_ADD_SOUTH });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            for (int i = 0; i < 3; i++)
                caster->CastSpell(caster, SPELL_SUMMON_ADD_SOUTH, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_summon_wave_south_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_wave_south_SpellScript();
    }
};

// 79196 - Summon Follower
class spell_summon_wave_west : public SpellScriptLoader
{
public:
    spell_summon_wave_west() : SpellScriptLoader("spell_summon_wave_west") { }

    class spell_summon_wave_west_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_summon_wave_west_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_SUMMON_ADD_WEST });
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            for (int i = 0; i < 10; i++)
                caster->CastSpell(caster, SPELL_SUMMON_ADD_WEST, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_summon_wave_west_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_summon_wave_west_SpellScript();
    }
};

// 79251 - Gravity Well (casts damage spell on units within 10 yards)
class PlayerPetOrDevoutFollowerCheck
{
public:
    bool operator()(WorldObject* object) const
    {
        // Valid targets are players, pets and Devout Followers
        if (object->GetTypeId() == TYPEID_UNIT)
            return !object->ToUnit()->IsPet() && object->GetEntry() != NPC_DEVOUT_FOLLOWER;
        return object->GetTypeId() != TYPEID_PLAYER;
    }
};

class spell_gravity_well_damage_nearby : public SpellScriptLoader
{
public:
    spell_gravity_well_damage_nearby() : SpellScriptLoader("spell_gravity_well_damage_nearby") { }

    class spell_gravity_well_damage_nearby_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gravity_well_damage_nearby_SpellScript);

        void SetRadiusMod()
        {
            GetSpell()->SetSpellValue(SPELLVALUE_RADIUS_MOD, int32(GetCaster()->GetObjectScale() * 10000 * 2 / 3));
        }

        void FilterTargets(std::list<WorldObject*>& unitList)
        {
            unitList.remove_if(PlayerPetOrDevoutFollowerCheck());
        }

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetCaster()->CastSpell(GetHitUnit(), SPELL_GRAVITY_WELL_DAMAGE, true);
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_gravity_well_damage_nearby_SpellScript::SetRadiusMod);
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_gravity_well_damage_nearby_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_gravity_well_damage_nearby_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gravity_well_damage_nearby_SpellScript();
    }
};

// 79249 - Gravity Well (damage)
class spell_gravity_well_damage : public SpellScriptLoader
{
public:
    spell_gravity_well_damage() : SpellScriptLoader("spell_gravity_well_damage") { }

    class spell_gravity_well_damage_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gravity_well_damage_SpellScript);

        void CalculateDamage(SpellEffIndex /*effIndex*/)
        {
            Unit* target = GetHitUnit();
            if (!target)
                return;

            float distance = GetCaster()->GetDistance2d(target);

            if (target->GetEntry() == NPC_DEVOUT_FOLLOWER)
                SetHitDamage(int32(200000 - (1000 * distance))); //need more research on this formula, damage values from sniffs: 189264, 190318, 190478, 196134, 197672, 199735
            else
                SetHitDamage(int32(4000 - (200 * distance)));
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_gravity_well_damage_SpellScript::CalculateDamage, EFFECT_0, SPELL_EFFECT_SCHOOL_DAMAGE);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gravity_well_damage_SpellScript();
    }
};

// 79332 - Gravity Well (pull units within 10 yards)
class spell_gravity_well_pull : public SpellScriptLoader
{
public:
    spell_gravity_well_pull() : SpellScriptLoader("spell_gravity_well_pull") { }

    class spell_gravity_well_pull_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_gravity_well_pull_SpellScript);

        void SetRadiusMod()
        {
            GetSpell()->SetSpellValue(SPELLVALUE_RADIUS_MOD, int32(GetCaster()->GetObjectScale() * 10000 * 2 / 3));
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_gravity_well_pull_SpellScript::SetRadiusMod);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_gravity_well_pull_SpellScript();
    }
};

// 86863 - Seismic Shard (makes shard reenter Azil)
class spell_seismic_shard_change_seat : public SpellScriptLoader
{
public:
    spell_seismic_shard_change_seat() : SpellScriptLoader("spell_seismic_shard_change_seat") { }

    class spell_seismic_shard_change_seat_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_seismic_shard_change_seat_SpellScript);

        void ExitVehicle()
        {
            GetCaster()->ExitVehicle();
        }

        void Register() override
        {
            BeforeCast += SpellCastFn(spell_seismic_shard_change_seat_SpellScript::ExitVehicle);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_seismic_shard_change_seat_SpellScript();
    }
};

// 79015 - Seismic Shard (launches shard)
class spell_seismic_shard : public SpellScriptLoader
{
public:
    spell_seismic_shard() : SpellScriptLoader("spell_seismic_shard") { }

    class spell_seismic_shard_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_seismic_shard_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            Creature* target = GetHitUnit()->ToCreature();
            if (!target)
                return;

            target->ExitVehicle();
            DynamicObject* dynamicObject = GetCaster()->GetDynObject(SPELL_SEISMIC_SHARD_TARGETING);
            target->CastSpell(dynamicObject->GetPositionX(), dynamicObject->GetPositionY(), dynamicObject->GetPositionZ(), SPELL_SEISMIC_SHARD_MISSLE, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_seismic_shard_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_seismic_shard_SpellScript();
    }
};

void AddSC_boss_high_priestess_azil()
{
    new boss_high_priestess_azil();
    new npc_devout_follower();
    new npc_gravity_well();
    new npc_seismic_shard();
    new spell_summon_wave_south();
    new spell_summon_wave_west();
    new spell_gravity_well_damage_nearby();
    new spell_gravity_well_damage();
    new spell_gravity_well_pull();
    new spell_seismic_shard_change_seat();
    new spell_seismic_shard();
}
