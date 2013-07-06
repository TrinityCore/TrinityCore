/*
 * Copyright (C) 2008-2013 TrinityCore <http://www.trinitycore.org/>
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
#include "ruby_sanctum.h"

enum Texts
{
    SAY_AGGRO                   = 0, // You will sssuffer for this intrusion! (17528)
    SAY_CONFLAGRATION           = 1, // Burn in the master's flame! (17532)
    EMOTE_ENRAGED               = 2, // %s becomes enraged!
    SAY_KILL                    = 3, // Halion will be pleased. (17530) - As it should be.... (17529)
};

enum Spells
{
    SPELL_CONFLAGRATION         = 74452,
    SPELL_FLAME_BEACON          = 74453,
    SPELL_CONFLAGRATION_2       = 74454, // Unknown dummy effect
    SPELL_ENRAGE                = 78722,
    SPELL_FLAME_BREATH          = 74403,
};

enum Events
{
    EVENT_ENRAGE                = 1,
    EVENT_FLIGHT                = 2,
    EVENT_FLAME_BREATH          = 3,
    EVENT_CONFLAGRATION         = 4,
    EVENT_LAND_GROUND           = 5,
    EVENT_AIR_MOVEMENT          = 6,

    // Event group
    EVENT_GROUP_LAND_PHASE      = 1,
};

enum MovementPoints
{
    POINT_FLIGHT                = 1,
    POINT_LAND                  = 2,
    POINT_TAKEOFF               = 3,
    POINT_LAND_GROUND           = 4
};

enum Misc
{
    SOUND_ID_DEATH              = 17531,
};

Position const SavianaRagefireFlyOutPos  = {3155.51f, 683.844f, 95.0f,   4.69f};
Position const SavianaRagefireFlyInPos   = {3151.07f, 636.443f, 79.540f, 4.69f};
Position const SavianaRagefireLandPos    = {3151.07f, 636.443f, 78.649f, 4.69f};

class boss_saviana_ragefire : public CreatureScript
{
    public:
        boss_saviana_ragefire() : CreatureScript("boss_saviana_ragefire") { }

        struct boss_saviana_ragefireAI : public BossAI
        {
            boss_saviana_ragefireAI(Creature* creature) : BossAI(creature, DATA_SAVIANA_RAGEFIRE)
            {
            }

            void Reset() OVERRIDE
            {
                _Reset();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterCombat(Unit* /*who*/) OVERRIDE
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.Reset();
                events.ScheduleEvent(EVENT_ENRAGE, 20000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLAME_BREATH, 14000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLIGHT, 60000);
            }

            void JustDied(Unit* /*killer*/) OVERRIDE
            {
                _JustDied();
                me->PlayDirectSound(SOUND_ID_DEATH);
            }

            void MovementInform(uint32 type, uint32 point) OVERRIDE
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_FLIGHT:
                        events.ScheduleEvent(EVENT_CONFLAGRATION, 1000);
                        Talk(SAY_CONFLAGRATION);
                        break;
                    case POINT_LAND:
                        events.ScheduleEvent(EVENT_LAND_GROUND, 1);
                        break;
                    case POINT_LAND_GROUND:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetReactState(REACT_AGGRESSIVE);
                        DoStartMovement(me->GetVictim());
                        break;
                    case POINT_TAKEOFF:
                        events.ScheduleEvent(EVENT_AIR_MOVEMENT, 1);
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome() OVERRIDE
            {
                _JustReachedHome();
                me->SetCanFly(false);
                me->SetDisableGravity(false);
            }

            void KilledUnit(Unit* victim) OVERRIDE
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(uint32 diff) OVERRIDE
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
                        case EVENT_FLIGHT:
                        {
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, 3, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            Position pos;
                            pos.Relocate(me);
                            pos.m_positionZ += 10.0f;
                            me->GetMotionMaster()->MoveTakeoff(POINT_TAKEOFF, pos);
                            events.ScheduleEvent(EVENT_FLIGHT, 50000);
                            events.DelayEvents(12500, EVENT_GROUP_LAND_PHASE);
                            break;
                        }
                        case EVENT_CONFLAGRATION:
                            DoCast(me, SPELL_CONFLAGRATION, true);
                            break;
                        case EVENT_ENRAGE:
                            DoCast(me, SPELL_ENRAGE);
                            Talk(EMOTE_ENRAGED);
                            events.ScheduleEvent(EVENT_ENRAGE, urand(15000, 20000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_FLAME_BREATH:
                            DoCastVictim(SPELL_FLAME_BREATH);
                            events.ScheduleEvent(EVENT_FLAME_BREATH, urand(20000, 30000), EVENT_GROUP_LAND_PHASE);
                            break;
                        case EVENT_AIR_MOVEMENT:
                            me->GetMotionMaster()->MovePoint(POINT_FLIGHT, SavianaRagefireFlyOutPos);
                            break;
                        case EVENT_LAND_GROUND:
                            me->GetMotionMaster()->MoveLand(POINT_LAND_GROUND, SavianaRagefireLandPos);
                            break;
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const OVERRIDE
        {
            return GetRubySanctumAI<boss_saviana_ragefireAI>(creature);
        }
};

class ConflagrationTargetSelector
{
    public:
        ConflagrationTargetSelector() { }

        bool operator()(WorldObject* unit) const
        {
            return unit->GetTypeId() != TYPEID_PLAYER;
        }
};

class spell_saviana_conflagration_init : public SpellScriptLoader
{
    public:
        spell_saviana_conflagration_init() : SpellScriptLoader("spell_saviana_conflagration_init") { }

        class spell_saviana_conflagration_init_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_saviana_conflagration_init_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ConflagrationTargetSelector());
                uint8 maxSize = uint8(GetCaster()->GetMap()->GetSpawnMode() & 1 ? 6 : 3);
                if (targets.size() > maxSize)
                    Trinity::Containers::RandomResizeList(targets, maxSize);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_FLAME_BEACON, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CONFLAGRATION_2, false);
            }

            void Register() OVERRIDE
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_saviana_conflagration_init_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_init_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_saviana_conflagration_init_SpellScript();
        }
};

class spell_saviana_conflagration_throwback : public SpellScriptLoader
{
    public:
        spell_saviana_conflagration_throwback() : SpellScriptLoader("spell_saviana_conflagration_throwback") { }

        class spell_saviana_conflagration_throwback_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_saviana_conflagration_throwback_SpellScript);

            void HandleScript(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
                GetHitUnit()->GetMotionMaster()->MovePoint(POINT_LAND, SavianaRagefireFlyInPos);
            }

            void Register() OVERRIDE
            {
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_throwback_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const OVERRIDE
        {
            return new spell_saviana_conflagration_throwback_SpellScript();
        }
};

void AddSC_boss_saviana_ragefire()
{
    new boss_saviana_ragefire();
    new spell_saviana_conflagration_init();
    new spell_saviana_conflagration_throwback();
}
