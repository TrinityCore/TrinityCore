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
#include "Map.h"
#include "MotionMaster.h"
#include "ruby_sanctum.h"
#include "ScriptedCreature.h"
#include "SpellMgr.h"
#include "SpellScript.h"

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
            boss_saviana_ragefireAI(Creature* creature) : BossAI(creature, DATA_SAVIANA_RAGEFIRE) { }

            void Reset() override
            {
                _Reset();
                me->SetReactState(REACT_AGGRESSIVE);
                me->SetCanFly(false);
                me->SetDisableGravity(false);
            }

            void EnterCombat(Unit* /*who*/) override
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.Reset();
                events.ScheduleEvent(EVENT_ENRAGE, Seconds(20), EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLAME_BREATH, Seconds(14), EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLIGHT, Seconds(60), EVENT_GROUP_LAND_PHASE);
            }

            void JustDied(Unit* /*killer*/) override
            {
                _JustDied();
                DoPlaySoundToSet(me, SOUND_ID_DEATH);
            }

            void MovementInform(uint32 type, uint32 point) override
            {
                if (type != POINT_MOTION_TYPE && type != EFFECT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_FLIGHT:
                        events.ScheduleEvent(EVENT_CONFLAGRATION, Seconds(1));
                        Talk(SAY_CONFLAGRATION);
                        break;
                    case POINT_LAND:
                        events.ScheduleEvent(EVENT_LAND_GROUND, Milliseconds(1));
                        break;
                    case POINT_LAND_GROUND:
                        me->SetCanFly(false);
                        me->SetDisableGravity(false);
                        me->RemoveByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                        me->SetReactState(REACT_AGGRESSIVE);
                        events.ScheduleEvent(EVENT_ENRAGE, Seconds(1), EVENT_GROUP_LAND_PHASE);
                        events.ScheduleEvent(EVENT_FLAME_BREATH, Seconds(2), Seconds(4), EVENT_GROUP_LAND_PHASE);
                        events.ScheduleEvent(EVENT_FLIGHT, Seconds(50), EVENT_GROUP_LAND_PHASE);
                        break;
                    case POINT_TAKEOFF:
                        events.ScheduleEvent(EVENT_AIR_MOVEMENT, Milliseconds(1));
                        break;
                    default:
                        break;
                }
            }

            void EnterEvadeMode(EvadeReason /*why*/) override
            {
                _DespawnAtEvade();
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
                        case EVENT_FLIGHT:
                        {
                            me->SetCanFly(true);
                            me->SetDisableGravity(true);
                            me->SetByteFlag(UNIT_FIELD_BYTES_1, UNIT_BYTES_1_OFFSET_ANIM_TIER, UNIT_BYTE1_FLAG_ALWAYS_STAND | UNIT_BYTE1_FLAG_HOVER);
                            me->SetReactState(REACT_PASSIVE);
                            me->AttackStop();
                            Position pos;
                            pos.Relocate(me);
                            pos.m_positionZ += 10.0f;
                            me->GetMotionMaster()->MoveTakeoff(POINT_TAKEOFF, pos);
                            events.CancelEventGroup(EVENT_GROUP_LAND_PHASE);
                            break;
                        }
                        case EVENT_CONFLAGRATION:
                            DoCastSelf(SPELL_CONFLAGRATION, true);
                            break;
                        case EVENT_ENRAGE:
                            DoCastSelf(SPELL_ENRAGE);
                            Talk(EMOTE_ENRAGED);
                            events.Repeat(Seconds(24));
                            break;
                        case EVENT_FLAME_BREATH:
                            DoCastVictim(SPELL_FLAME_BREATH);
                            events.Repeat(Seconds(20), Seconds(30));
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

                    if (me->HasUnitState(UNIT_STATE_CASTING))
                        return;
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
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

// 74452 - Conflagration
class spell_saviana_conflagration_init : public SpellScriptLoader
{
    public:
        spell_saviana_conflagration_init() : SpellScriptLoader("spell_saviana_conflagration_init") { }

        class spell_saviana_conflagration_init_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_saviana_conflagration_init_SpellScript);

            bool Validate(SpellInfo const* /*spell*/) override
            {
                if (!sSpellMgr->GetSpellInfo(SPELL_FLAME_BEACON)
                    || !sSpellMgr->GetSpellInfo(SPELL_CONFLAGRATION_2))
                    return false;
                return true;
            }

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                targets.remove_if(ConflagrationTargetSelector());
                uint8 maxSize = uint8(GetCaster()->GetMap()->Is25ManRaid() ? 6 : 3);
                if (targets.size() > maxSize)
                    Trinity::Containers::RandomResize(targets, maxSize);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_FLAME_BEACON, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CONFLAGRATION_2, false);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_saviana_conflagration_init_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_init_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_saviana_conflagration_init_SpellScript();
        }
};

// 74455 - Conflagration
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

            void Register() override
            {
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_throwback_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const override
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
