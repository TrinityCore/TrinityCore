/*
 * Copyright (C) 2014-2015 Warlegend-Project <http://www.warlegend-project.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ScriptedCreature.h"
#include "PassiveAI.h"
#include "throne_of_thunder.h"

enum eSpells
{
    /* Tortos */
    SPELL_CALL_OF_TORTOS        = 136294,
    SPELL_FURIOUS_STONE_BREATH  = 133939,
    SPELL_GROWING_FURY          = 136010,
    SPELL_KICK_SHELL            = 134030,
    SPELL_QUAKE_STOMP           = 134920,
    SPELL_SNAPPING_BITE         = 135251,
    SPELL_ZERO_POWER            = 72242,
    SPELL_BERSERK               = 26662,

    /* Rockfall */
    SPELL_ROCKFALL              = 134475,

    /* Vampiric Cave Bat */
    SPELL_DRAIN_THE_WEAK        = 135103,
};

enum eEvents
{
    /* Tortos */
    EVENT_CALL_OF_TORTOS        = 1,
    EVENT_FURIOUS_STONE_BREATH  = 2,
    EVENT_QUAKE_STOMP           = 3,
    EVENT_SNAPPING_BITE         = 4,
    EVENT_SUMMON_BATS           = 5,
    EVENT_BERSERK               = 6,
    EVENT_GROWING_FURY_RANGE    = 7,
};

enum ePhases
{
    PHASE_NULL,
    PHASE_COMBAT,
    PHASE_FURIOUS_STONE_BREATH,
};

enum Npcs
{
    NPC_VAMPIRIC_CAVE_BAT       = 69352,
};

// Tortos #67977#
class boss_tortos : public CreatureScript
{
public:
    boss_tortos() : CreatureScript("boss_tortos") { }

    CreatureAI* GetAI(Creature* creature) const
    {
        if (!creature->GetVehicleKit())
            return NULL;

        return GetThroneOfThunderAI<boss_tortos_AI>(creature);
    }

    struct boss_tortos_AI : public BossAI
    {
        boss_tortos_AI(Creature* creature) : 
            BossAI(creature, DATA_TORTOS) { }

        void Reset() override
        {
            _Reset();

            events.Reset();
            events.SetPhase(PHASE_NULL);

            me->SetFloatValue(UNIT_FIELD_BOUNDING_RADIUS, 30);
            me->SetFloatValue(UNIT_FIELD_COMBAT_REACH, 30);

            me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_DISABLE_MOVE);
            me->SetFlag(UNIT_FIELD_FLAGS2, UNIT_FLAG2_DISABLE_TURN);

            me->setPowerType(POWER_ENERGY);
            me->SetMaxPower(POWER_ENERGY, me->GetCreatePowers(POWER_ENERGY));
            me->SetPower(POWER_ENERGY, 0);
            DoCast(me, SPELL_ZERO_POWER);

            me->RemoveAurasDueToSpell(SPELL_BERSERK);
        }

        void JustDied(Unit* /*killer*/) override { }

        void KilledUnit(Unit* /*unit*/) override { }

        void EnterCombat(Unit* /*unit*/) override
        {
            _EnterCombat();

            instance->SendEncounterUnit(ENCOUNTER_FRAME_ENGAGE, me);
            
            events.SetPhase(PHASE_COMBAT);

            DoZoneInCombat();

            events.ScheduleEvent(EVENT_SNAPPING_BITE, 9*IN_MILLISECONDS, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_CALL_OF_TORTOS, 21*IN_MILLISECONDS, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_QUAKE_STOMP, 24*IN_MILLISECONDS, 0, PHASE_COMBAT);
            events.ScheduleEvent(EVENT_BERSERK, 13*MINUTE*IN_MILLISECONDS);
            events.ScheduleEvent(EVENT_GROWING_FURY_RANGE, 6*IN_MILLISECONDS, 0, PHASE_COMBAT); // Let the tank come in melee range from the Tortos
        }

        void UpdateAI(uint32 diff) override
        {
            if (!UpdateVictim())
                return;
            
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;

            events.Update(diff);
            
            if (events.IsInPhase(PHASE_COMBAT) && me->GetPower(POWER_ENERGY) == me->GetMaxPower(POWER_ENERGY))
            {
                events.ScheduleEvent(EVENT_FURIOUS_STONE_BREATH, IN_MILLISECONDS, 0, PHASE_FURIOUS_STONE_BREATH);
                events.SetPhase(PHASE_FURIOUS_STONE_BREATH);
            }

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_SNAPPING_BITE:
                        DoCastVictim(SPELL_SNAPPING_BITE);
                        events.ScheduleEvent(EVENT_SNAPPING_BITE, 8*IN_MILLISECONDS, 0, PHASE_COMBAT);
                        break;

                    case EVENT_CALL_OF_TORTOS:
                        DoCast(SPELL_CALL_OF_TORTOS);
                        events.ScheduleEvent(EVENT_CALL_OF_TORTOS, MINUTE*IN_MILLISECONDS, 0, PHASE_COMBAT);
                        break;

                    case EVENT_QUAKE_STOMP:
                        DoCast(SPELL_QUAKE_STOMP);
                        events.ScheduleEvent(EVENT_QUAKE_STOMP, 47*IN_MILLISECONDS, 0, PHASE_COMBAT);
                        break;

                    case EVENT_SUMMON_BATS:
                        events.ScheduleEvent(EVENT_SUMMON_BATS, 45*IN_MILLISECONDS, 0, PHASE_COMBAT);
                        break;

                    case EVENT_BERSERK:
                        DoCast(SPELL_BERSERK);
                        events.CancelEvent(EVENT_BERSERK);
                        break;

                    case EVENT_GROWING_FURY_RANGE:
                    {
                        std::list<Player*> playerList;
                        GetPlayerListInGrid(playerList, me, me->GetMeleeReach());

                        if (playerList.empty())
                        {
                            DoCast(SPELL_GROWING_FURY);
                            events.ScheduleEvent(EVENT_GROWING_FURY_RANGE, IN_MILLISECONDS, 0, PHASE_COMBAT);
                        }
                        else
                            events.ScheduleEvent(EVENT_GROWING_FURY_RANGE, 5*IN_MILLISECONDS, 0, PHASE_COMBAT);

                        break;
                    }

                    case EVENT_FURIOUS_STONE_BREATH:
                        DoCast(SPELL_FURIOUS_STONE_BREATH);
                        events.SetPhase(PHASE_COMBAT);

                        events.CancelEvent(EVENT_FURIOUS_STONE_BREATH);
                        break;

                    default:
                        break;
                }
            }

            DoMeleeAttackIfReady();
        }
    };
};

// NPC : Rockfall #68219#
class npc_rockfall : public CreatureScript
{
public:

    npc_rockfall() : CreatureScript("npc_rockfall") { }

    struct npc_rockfallAI : public PassiveAI
    {
        npc_rockfallAI(Creature* creature) : PassiveAI(creature) { }

        void Reset() override
        {
            //me->SetToTrigger(true, true);
            
            DoCast(SPELL_ROCKFALL);

            DoZoneInCombat();
        }
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return new npc_rockfallAI(creature);
    }
};

// Spell : Rockfall - 140431
class spell_rockfall : public SpellScriptLoader
{
    public:
        spell_rockfall() : SpellScriptLoader("spell_rockfall") { }

        class spell_rockfall_SpellScript : public SpellScript
        {
            PrepareSpellScript(spell_rockfall_SpellScript);

            void FilterTargets(std::list<WorldObject*>& targets)
            {
                Trinity::Containers::RandomResizeList(targets, 1);
            }

            void HandleHit(SpellEffIndex /*effIndex*/)
            {
                int32 spellTrigger = GetEffectValue();

                if (Unit* target = GetHitUnit())
                    target->CastSpell(target, spellTrigger, true);
            }

            void Register() override
            {
                OnObjectAreaTargetSelect += SpellObjectAreaTargetSelectFn(spell_rockfall_SpellScript::FilterTargets, EFFECT_0, TARGET_UNIT_SRC_AREA_ENEMY);
                OnEffectHitTarget += SpellEffectFn(spell_rockfall_SpellScript::HandleHit, EFFECT_0, SPELL_EFFECT_DUMMY);
            }
        };

        SpellScript* GetSpellScript() const override
        {
            return new spell_rockfall_SpellScript();
        }
};

void AddSC_tortos()
{
    new boss_tortos();
    new npc_rockfall();
    new spell_rockfall();
}
