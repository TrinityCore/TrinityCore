/*
 * Copyright (C) 2008-2012 TrinityCore <http://www.trinitycore.org/>
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

#include "ScriptPCH.h"
#include "ruby_sanctum.h"

enum Texts
{
    SAY_AGGRO                           = 0, // You will sssuffer for this intrusion! (17528)
    SAY_CONFLAGRATION                   = 1, // Burn in the master's flame! (17532)
    EMOTE_ENRAGED                       = 2, // %s becomes enraged!
    SAY_KILL                            = 3, // Halion will be pleased. (17530) - As it should be.... (17529)
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
    EVENT_ENRAGE                    = 1,
    EVENT_FLIGHT                    = 2,
    EVENT_FLAME_BREATH              = 3,
    EVENT_CONFLAGRATION             = 4,

    // Event group
    EVENT_GROUP_LAND_PHASE          = 1,
};

enum MovementPoints
{
    POINT_FLIGHT            = 1,
    POINT_LAND              = 2,
};

enum Misc
{
    SOUND_ID_DEATH          = 17531,
};

Position const SavianaRagefireFlyPos  = {3155.51f, 683.844f, 95.20f, 4.69f};
Position const SavianaRagefireLandPos = {3151.07f, 636.443f, 79.54f, 4.69f};

class boss_saviana_ragefire : public CreatureScript
{
    public:
        boss_saviana_ragefire() : CreatureScript("boss_saviana_ragefire") { }

        struct boss_saviana_ragefireAI : public BossAI
        {
            boss_saviana_ragefireAI(Creature* creature) : BossAI(creature, DATA_SAVIANA_RAGEFIRE)
            {
            }

            void Reset()
            {
                _Reset();
                me->SetReactState(REACT_AGGRESSIVE);
            }

            void EnterCombat(Unit* /*who*/)
            {
                _EnterCombat();
                Talk(SAY_AGGRO);
                events.Reset();
                events.ScheduleEvent(EVENT_ENRAGE, 20000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLAME_BREATH, 14000, EVENT_GROUP_LAND_PHASE);
                events.ScheduleEvent(EVENT_FLIGHT, 60000);
            }

            void JustDied(Unit* /*killer*/)
            {
                _JustDied();
                me->PlayDirectSound(SOUND_ID_DEATH);
            }

            void MovementInform(uint32 type, uint32 point)
            {
                if (type != POINT_MOTION_TYPE)
                    return;

                switch (point)
                {
                    case POINT_FLIGHT:
                        events.ScheduleEvent(EVENT_CONFLAGRATION, 1000);
                        Talk(SAY_CONFLAGRATION);
                        break;
                    case POINT_LAND:
                        me->SetFlying(false);
                        me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                        me->SetReactState(REACT_AGGRESSIVE);
                        if (me->GetMotionMaster()->GetCurrentMovementGeneratorType() == POINT_MOTION_TYPE)
                            me->GetMotionMaster()->MovementExpired();
                        DoStartMovement(me->getVictim());
                        break;
                    default:
                        break;
                }
            }

            void JustReachedHome()
            {
                _JustReachedHome();
                me->SetFlying(false);
                me->RemoveUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
            }

            void KilledUnit(Unit* victim)
            {
                if (victim->GetTypeId() == TYPEID_PLAYER)
                    Talk(SAY_KILL);
            }

            void UpdateAI(uint32 const diff)
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
                            me->SetFlying(true);
                            me->AddUnitMovementFlag(MOVEMENTFLAG_LEVITATING);
                            me->SetReactState(REACT_PASSIVE);
                            me->GetMotionMaster()->MovePoint(POINT_FLIGHT, SavianaRagefireFlyPos);
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
                        default:
                            break;
                    }
                }

                DoMeleeAttackIfReady();
            }
        };

        CreatureAI* GetAI(Creature* creature) const
        {
            return GetRubySanctumAI<boss_saviana_ragefireAI>(creature);
        }
};

class ConflagrationTargetSelector
{
    public:
        ConflagrationTargetSelector() { }

        bool operator()(Unit* unit)
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

            void FilterTargets(std::list<Unit*>& unitList)
            {
                unitList.remove_if (ConflagrationTargetSelector());
                uint8 maxSize = uint8(GetCaster()->GetMap()->GetSpawnMode() & 1 ? 6 : 3);
                if (unitList.size() > maxSize)
                    Trinity::RandomResizeList(unitList, maxSize);
            }

            void HandleDummy(SpellEffIndex effIndex)
            {
                PreventHitDefaultEffect(effIndex);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_FLAME_BEACON, true);
                GetCaster()->CastSpell(GetHitUnit(), SPELL_CONFLAGRATION_2, false);
            }

            void Register()
            {
                OnUnitTargetSelect += SpellUnitTargetFn(spell_saviana_conflagration_init_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_init_SpellScript::HandleDummy, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const
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
                GetHitUnit()->GetMotionMaster()->MovePoint(POINT_LAND, SavianaRagefireLandPos);
            }

            void Register()
            {
                OnEffectHitTarget += SpellEffectFn(spell_saviana_conflagration_throwback_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            }
        };

        SpellScript* GetSpellScript() const
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
