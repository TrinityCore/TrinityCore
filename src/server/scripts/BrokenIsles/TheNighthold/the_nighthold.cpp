/*
 * Copyright (C) 2022 BfaCore Reforged
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
#include "SpellAuraEffects.h"
#include "SpellScript.h"
#include "SpellInfo.h"
#include "Vehicle.h"
#include "CombatAI.h"
#include "thenighthold.h"
#include "InstanceScript.h"
#include "Unit.h"
#include "ObjectAccessor.h"
#include "MotionMaster.h"
#include "CreatureAIImpl.h"

enum Spells
{
    // Torm the Brute
    SPELL_CRASH_DOOR_VISUAL_FIRST       = 230873,
    SPELL_CRASH_DOOR_VISUAL_SECOND      = 230880,
    SPELL_DEVASTATING_STRIKE            = 230438,
    SPELL_BOULDER_STRIKE                = 231086,
    SPELL_RUMBLING_BLOW                 = 230482,
    // Pulsauron
    SPELL_SHIELD                        = 205647,
    SPELL_BEAM                          = 221153,
    // Fulminant
    SPELL_SCATTER                       = 221172,
    SPELL_SCATTER_DAMAGE                = 221173,
    SPELL_SCATTER_VISUAL                = 221191,
    SPELL_SCATTER_ENERGIZE              = 221175,
    SPELL_FULMINATE                     = 221164,
    // Chaotoid
    SPELL_RELEASE_THE_VOID              = 221158,
    SPELL_COMPRESS_THE_VOID_GRIP        = 221160,
    SPELL_COMPRESS_THE_VOID_JUMP        = 221162,
};

enum Events
{
    // Torm the Brute
    EVENT_TORM_CRASH_DOOR               = 1,
    EVENT_DEVASTATING_STRIKE            = 2,
    EVENT_BOULDER_STRIKE                = 3,
    EVENT_RUMBLING_BLOW                 = 4,
    // Pulsauron
    EVENT_PULSAURON_BEAM                = 5,
    // Fulminant
    EVENT_SCATTER                       = 6,
    EVENT_FULMINATE                     = 7,
    // Chaotoid
    EVENT_RELEASE_THE_VOID              = 8,
    EVENT_COMPRESS_THE_VOID_GRIP        = 9
};

// 115914 - Torm the Brute
class npc_torm_the_brute : public CreatureScript
{
public:
    npc_torm_the_brute() : CreatureScript("npc_torm_the_brute") { }

    struct npc_torm_the_bruteAI : public ScriptedAI
    {
        npc_torm_the_bruteAI(Creature* creature) : ScriptedAI(creature)
        {
            _instance = creature->GetInstanceScript();
        }

        void Reset() override
        {
            events.SetPhase(1);
            events.ScheduleEvent(EVENT_TORM_CRASH_DOOR, urand(10000, 25000), 0, 1);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.SetPhase(2);
            events.ScheduleEvent(EVENT_DEVASTATING_STRIKE, 6000);
            events.ScheduleEvent(EVENT_BOULDER_STRIKE, 13000);
            events.ScheduleEvent(EVENT_RUMBLING_BLOW, 17000);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            events.Reset();
            events.SetPhase(1);
            ScriptedAI::EnterEvadeMode(why);
            events.ScheduleEvent(EVENT_TORM_CRASH_DOOR, urand(10000, 25000), 0, 1);
        }

        void JustDied(Unit* /*killer*/) override
        {
            _instance->SetData(DATA_TORM_THE_BRUTE, DONE);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim() && me->IsInCombat())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_TORM_CRASH_DOOR:
                    DoCastSelf(RAND(SPELL_CRASH_DOOR_VISUAL_FIRST, SPELL_CRASH_DOOR_VISUAL_SECOND));
                    events.ScheduleEvent(EVENT_TORM_CRASH_DOOR, urand(5000, 15000), 0, 1);
                    break;
                case EVENT_DEVASTATING_STRIKE:
                    DoCastVictim(SPELL_DEVASTATING_STRIKE);
                    events.ScheduleEvent(EVENT_DEVASTATING_STRIKE, 22000);
                    break;
                case EVENT_BOULDER_STRIKE:
                    if (auto target = SelectTarget(SELECT_TARGET_RANDOM, 0, NonTankTargetSelector(me)))
                        DoCast(target, SPELL_BOULDER_STRIKE);
                    events.ScheduleEvent(EVENT_BOULDER_STRIKE, 11000);
                    break;
                case EVENT_RUMBLING_BLOW:
                    DoCastSelf(SPELL_RUMBLING_BLOW);
                    events.ScheduleEvent(EVENT_RUMBLING_BLOW, 18000);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }

    private:
        InstanceScript* _instance;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_torm_the_bruteAI>(creature);
    }
};

// 111081 - Fulminant
class npc_fulminant : public CreatureScript
{
public:
    npc_fulminant() : CreatureScript("npc_fulminant") { }

    struct npc_fulminantAI : public ScriptedAI
    {
        npc_fulminantAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, 100);
            me->SetPower(POWER_ENERGY, 100);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_SCATTER, 10000);
            events.ScheduleEvent(EVENT_FULMINATE, 25000);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            events.Reset();
            ScriptedAI::EnterEvadeMode(why);
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;

            events.Update(diff);

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            if (me->GetPower(POWER_ENERGY) == 100 && events.GetPhaseMask() == 1)
                DoCastSelf(SPELL_FULMINATE);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                case EVENT_SCATTER:
                    DoCastVictim(SPELL_SCATTER);
                    events.ScheduleEvent(EVENT_SCATTER, 6000);
                    break;
                case EVENT_FULMINATE:
                    DoCastSelf(SPELL_FULMINATE);
                    events.SetPhase(1);
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_fulminantAI>(creature);
    }
};

// 111071 - Pulsauron
class npc_pulsauron : public CreatureScript
{
public:
    npc_pulsauron() : CreatureScript("npc_pulsauron") { }

    struct npc_pulsauronAI : public ScriptedAI
    {
        npc_pulsauronAI(Creature* creature) : ScriptedAI(creature) { }

        void Reset() override
        {
            me->SetReactState(REACT_PASSIVE);
            DoCastSelf(SPELL_SHIELD);
        }

        void EnterCombat(Unit* /*who*/) override
        {
            me->GetMotionMaster()->MoveRotate(180000, urand(0, 1) ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
            events.ScheduleEvent(EVENT_PULSAURON_BEAM, 5000);
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            me->GetMotionMaster()->MoveTargetedHome();
            events.Reset();
            ScriptedAI::EnterEvadeMode(why);
        }

        /*void MovementInform(uint32 type, uint32 id) override
        {
            if (type == ROTATE_MOTION_TYPE && me->IsInCombat())
                me->GetMotionMaster()->MoveRotate(180000, urand(0, 1) ? ROTATE_DIRECTION_LEFT : ROTATE_DIRECTION_RIGHT);
        }*/

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
                case EVENT_PULSAURON_BEAM:
                    DoCastSelf(SPELL_BEAM);
                    events.ScheduleEvent(EVENT_PULSAURON_BEAM, urand(15000, 30000));
                    break;
                default:
                    break;
                }
            }
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_pulsauronAI>(creature);
    }
};

// 111075 - Chaotoid
class npc_chaotoid : public CreatureScript
{
public:
    npc_chaotoid() : CreatureScript("npc_chaotoid") { }

    struct npc_chaotoidAI : public ScriptedAI
    {
        npc_chaotoidAI(Creature* creature) : ScriptedAI(creature) { }

        void EnterCombat(Unit* /*who*/) override
        {
            events.ScheduleEvent(EVENT_RELEASE_THE_VOID, urand(10000, 20000));
            events.ScheduleEvent(EVENT_COMPRESS_THE_VOID_GRIP, urand(15000, 25000));
        }

        void EnterEvadeMode(EvadeReason why) override
        {
            events.Reset();
            ScriptedAI::EnterEvadeMode(why);
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
                case EVENT_RELEASE_THE_VOID:
                    DoCastSelf(SPELL_RELEASE_THE_VOID);
                    events.ScheduleEvent(EVENT_RELEASE_THE_VOID, urand(15000, 25000));
                    break;
                case EVENT_COMPRESS_THE_VOID_GRIP:
                    DoCastSelf(SPELL_COMPRESS_THE_VOID_GRIP);
                    events.ScheduleEvent(EVENT_COMPRESS_THE_VOID_GRIP, urand(20000, 35000));
                    break;
                default:
                    break;
                }
            }
            DoMeleeAttackIfReady();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetTheNightholdAI<npc_chaotoidAI>(creature);
    }
};

// 221189 - Scatter
// 7.1.5
class spell_fulminant_scatter_area : public SpellScriptLoader
{
public:
    spell_fulminant_scatter_area() : SpellScriptLoader("spell_fulminant_scatter_area") { }

    class spell_fulminant_scatter_area_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_fulminant_scatter_area_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo
            ({
                SPELL_SCATTER_DAMAGE,
                SPELL_SCATTER_VISUAL,
                SPELL_SCATTER_ENERGIZE
            });
        }

        void HandleAreaSelect(std::list<WorldObject*>& targets)
        {
            targetsCount = targets.size();
        }

        void HandleHitTarget(SpellEffIndex /*effIndex*/)
        {
            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            uint32 damage = GetEffectValue() / targetsCount;
            caster->CastCustomSpell(SPELL_SCATTER_DAMAGE, SPELLVALUE_BASE_POINT0, damage, target, TRIGGERED_FULL_MASK);
            caster->CastSpell(target, SPELL_SCATTER_VISUAL, true);
            caster->CastSpell(caster, SPELL_SCATTER_ENERGIZE, true);
        }

        uint8 targetsCount;

        void Register() override
        {
            OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_fulminant_scatter_area_SpellScript::HandleAreaSelect, EFFECT_1, TARGET_UNIT_DEST_AREA_ENEMY);
            OnEffectHitTarget += SpellEffectFn(spell_fulminant_scatter_area_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_DUMMY);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_fulminant_scatter_area_SpellScript();
    }
};

// 221160 - Compress the Void
// 7.1.5
class spell_chaotoid_compress_the_void : public SpellScriptLoader
{
public:
    spell_chaotoid_compress_the_void() : SpellScriptLoader("spell_chaotoid_compress_the_void") { }

    class spell_chaotoid_compress_the_void_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_chaotoid_compress_the_void_SpellScript);

        bool Validate(SpellInfo const* /*spellInfo*/) override
        {
            return ValidateSpellInfo({ SPELL_COMPRESS_THE_VOID_JUMP });
        }

        void HandleHitTarget(SpellEffIndex effIndex)
        {
            if (effIndex == 1)
            {
                PreventHitDefaultEffect(effIndex);
                return;
            }

            Unit* caster = GetCaster();
            Unit* target = GetHitUnit();
            if (!caster || !target)
                return;

            target->CastSpell(caster, SPELL_COMPRESS_THE_VOID_JUMP, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_chaotoid_compress_the_void_SpellScript::HandleHitTarget, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
            OnEffectHitTarget += SpellEffectFn(spell_chaotoid_compress_the_void_SpellScript::HandleHitTarget, EFFECT_1, SPELL_EFFECT_FORCE_CAST_2);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_chaotoid_compress_the_void_SpellScript();
    }
};

void AddSC_the_nighthold()
{
    new npc_torm_the_brute();
    new npc_fulminant();
    new npc_pulsauron();
    new npc_chaotoid();
    new spell_fulminant_scatter_area();
    new spell_chaotoid_compress_the_void();
}
