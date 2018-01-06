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
#include "ScriptedCreature.h"
#include "SpellScript.h"
#include "Player.h"
#include "vortex_pinnacle.h"

enum Spells
{
    SPELL_STORMS_EDGE_AURA = 86295,
    SPELL_LIGHTNING_BOLT = 86331,
    SPELL_SUMMON_TEMPEST = 86340,
    SPELL_STORMS_EDGE_VISUAL = 86329,
    SPELL_STORMS_EDGE_CYCLONE_SHIELD_AURA = 86310, // periodically triggers 86311

    // Ertan's Vortex
    SPELL_CYCLONE_SHIELD = 86267,
    SPELL_CYCLONE_SHIELD_TRIGGER = 86292,

    SPELL_STORMS_EDGE_SCRIPT = 86299, // targets closest cyclone and makes it cast SPELL_STORMS_EDGE_DAMAGE on caster
//  SPELL_STORMS_EDGE_DAMAGE = 86309,
};

enum NPCs
{
    NPC_ERTANS_VORTEX = 46007,
};

enum Texts
{
    SAY_AGGRO = 0,
    SAY_STORMS_EDGE = 1,
};

enum Actions
{
    ACTION_STORMS_EDGE,
};

enum Events
{
    EVENT_NONE,
    EVENT_SUMMON_TEMPEST,
    EVENT_STORMS_EDGE_SPAWN,
    EVENT_STORMS_EDGE,
    EVENT_STORMS_EDGE_AURA,
    EVENT_STORMS_EDGE_END,

    // Ertan's Vortex
    EVENT_MOVE_POINT,
};

enum Points
{
    POINT_ERTANS_VORTEX_S       = 0,
    POINT_ERTANS_VORTEX_SW      = 1,
    POINT_ERTANS_VORTEX_W       = 2,
    POINT_ERTANS_VORTEX_NW      = 3,
    POINT_ERTANS_VORTEX_N       = 4,
    POINT_ERTANS_VORTEX_NE      = 5,
    POINT_ERTANS_VORTEX_E       = 6,
    POINT_ERTANS_VORTEX_SE      = 7,
    POINT_ERTANS_VORTEX_MAX     = 8,
    POINT_NONE,
};

const Position ErtansVortexPoints[POINT_ERTANS_VORTEX_MAX] =
{
    { -744.889f,  3.98611f, 635.6728f }, // South
    { -737.552f,  21.592f,  635.6728f }, // South-West
    { -719.802f,  28.8351f, 635.6728f }, // West
    { -702.144f,  21.9878f, 635.6728f }, // North-West
    { -694.911f,  4.16493f, 635.6728f }, // North
    { -702.212f, -13.6806f, 635.6728f }, // North-East
    { -719.934f, -20.9497f, 635.6728f }, // East
    { -737.649f, -13.5347f, 635.6728f }, // South-East
};

const Position ErtansVortexMiddlePoints[POINT_ERTANS_VORTEX_MAX] =
{
    { -724.3819f,  2.915083f,   635.6728f }, // South
    { -724.0161f,  6.648534f,   635.6728f }, // South-West
    { -721.1381f,  9.082433f,   635.6728f }, // West
    { -716.7177f,  8.423817f,   635.6728f }, // North-West
    { -714.6548f,  5.146466f,   635.6728f }, // North
    { -715.2417f,  1.857746f,   635.6728f }, // North-East
    { -718.2345f, -0.4830246f,  635.6728f }, // East
    { -721.9816f, -0.05864143f, 635.6728f }, // South-East
};

class boss_grand_vizier_ertan : public CreatureScript
{
    public:
        boss_grand_vizier_ertan() : CreatureScript("boss_grand_vizier_ertan") { }

        struct boss_grand_vizier_ertanAI : public BossAI
        {
            boss_grand_vizier_ertanAI(Creature* creature) : BossAI(creature, DATA_GRAND_VIZIER_ERTAN)
            {
                me->SetDisableGravity(true);
                SetCombatMovement(false);
            }

            void Reset() override
            {
                _Reset();

                // Should have, but gets stuck in evade mode...
                //me->AddUnitState(UNIT_STATE_ROOT);

                events.ScheduleEvent(EVENT_STORMS_EDGE_SPAWN, 400);
                events.ScheduleEvent(EVENT_STORMS_EDGE, 23000);
                if (IsHeroic())
                    events.ScheduleEvent(EVENT_SUMMON_TEMPEST, 17000);
            }

            void JustEngagedWith(Unit* /*target*/) override
            {
                _JustEngagedWith();

                SummonErtansVortexes();
                DoCast(me, SPELL_STORMS_EDGE_AURA);
                Talk(SAY_AGGRO);
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
                        case EVENT_SUMMON_TEMPEST:
                            DoCast(me, SPELL_SUMMON_TEMPEST);
                            events.ScheduleEvent(EVENT_SUMMON_TEMPEST, 17000);
                            break;
                        case EVENT_STORMS_EDGE:
                        {
                            DoCast(me, SPELL_STORMS_EDGE_VISUAL);
                            EntryCheckPredicate pred(NPC_ERTANS_VORTEX);
                            summons.DoAction(ACTION_STORMS_EDGE, pred);
                            Talk(SAY_STORMS_EDGE);
                            events.ScheduleEvent(EVENT_STORMS_EDGE_AURA, 3000);
                            events.ScheduleEvent(EVENT_STORMS_EDGE, 32000);
                            break;
                        }
                        case EVENT_STORMS_EDGE_AURA:
                            me->RemoveAurasDueToSpell(SPELL_STORMS_EDGE_AURA);
                            DoCast(me, SPELL_STORMS_EDGE_CYCLONE_SHIELD_AURA);
                            events.ScheduleEvent(EVENT_STORMS_EDGE_END, 6000);
                            break;
                        case EVENT_STORMS_EDGE_END:
                            me->RemoveAurasDueToSpell(SPELL_STORMS_EDGE_CYCLONE_SHIELD_AURA);
                            DoCast(me, SPELL_STORMS_EDGE_AURA);
                            break;
                        default:
                            break;
                    }
                }

                DoSpellAttackIfReady(SPELL_LIGHTNING_BOLT);
            }

        private:
            void SummonErtansVortexes() // Summons Ertan's Vortex at each point and makes them move to the next point
            {
                for (int8 i = 0; i < POINT_ERTANS_VORTEX_MAX; i++)
                {
                    if (Creature* ertansVortex = me->SummonCreature(NPC_ERTANS_VORTEX, ErtansVortexPoints[i]))
                    {
                        if (i == POINT_ERTANS_VORTEX_SE)
                            ertansVortex->GetMotionMaster()->MovePoint(POINT_ERTANS_VORTEX_S, ErtansVortexPoints[POINT_ERTANS_VORTEX_S]);
                        else
                            ertansVortex->GetMotionMaster()->MovePoint(i + 1, ErtansVortexPoints[i + 1]);
                    }
                }
            }
        };

        CreatureAI* GetAI(Creature* creature) const override
        {
            return GetInstanceAI<boss_grand_vizier_ertanAI>(creature);
        }
};

// 46007 - Ertan's Vortex
class npc_ertans_vortex : public CreatureScript
{
public:
    npc_ertans_vortex() : CreatureScript("npc_ertans_vortex") { }

    struct npc_ertans_vortexAI : public ScriptedAI
    {
        npc_ertans_vortexAI(Creature* creature) : ScriptedAI(creature)
        {
            currentPointId = 0;
            DoCast(me, SPELL_CYCLONE_SHIELD);
        }

        void DoAction(int32 action) override
        {
            if (action != ACTION_STORMS_EDGE)
                return;

            me->GetMotionMaster()->MovePoint(POINT_NONE, ErtansVortexMiddlePoints[currentPointId]);
            events.ScheduleEvent(EVENT_MOVE_POINT, 9000);
        }

        void MovementInform(uint32 movementType, uint32 pointId) override
        {
            if (movementType != POINT_MOTION_TYPE || pointId == POINT_NONE)
                return;

            if (pointId < POINT_ERTANS_VORTEX_SE)
                currentPointId = pointId + 1;
            else
                currentPointId = POINT_ERTANS_VORTEX_S;

            events.ScheduleEvent(EVENT_MOVE_POINT, 1);
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
                    case EVENT_MOVE_POINT:
                        me->GetMotionMaster()->MovePoint(currentPointId, ErtansVortexPoints[currentPointId]);
                        break;
                    default:
                        break;
                }
            }
        }

    private:
        EventMap events;
        uint32 currentPointId;
    };

    CreatureAI* GetAI(Creature* creature) const override
    {
        return GetInstanceAI<npc_ertans_vortexAI>(creature);
    }
};

// 86284 - Storm's Edge (targets players outside cyclone ring/further than 25 yards and makes them cast 86299)
// 86311 - Storm's Edge (targets all players and makes them cast 86299)
class spell_storms_edge : public SpellScriptLoader
{
public:
    spell_storms_edge() : SpellScriptLoader("spell_storms_edge") { }

    class spell_storms_edge_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_storms_edge_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetHitUnit(), SPELL_STORMS_EDGE_SCRIPT, true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_storms_edge_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_storms_edge_SpellScript();
    }
};

// 86299 - Storm's Edge (targets closest Ertan's Vortex and makes it cast 86309 on caster)
class spell_storms_edge_script : public SpellScriptLoader
{
public:
    spell_storms_edge_script() : SpellScriptLoader("spell_storms_edge_script") { }

    class spell_storms_edge_script_SpellScript : public SpellScript
    {
        PrepareSpellScript(spell_storms_edge_script_SpellScript);

        void HandleScript(SpellEffIndex /*effIndex*/)
        {
            GetHitUnit()->CastSpell(GetCaster(), uint32(GetEffectValue()), true);
        }

        void Register() override
        {
            OnEffectHitTarget += SpellEffectFn(spell_storms_edge_script_SpellScript::HandleScript, EFFECT_0, SPELL_EFFECT_SCRIPT_EFFECT);
        }
    };

    SpellScript* GetSpellScript() const override
    {
        return new spell_storms_edge_script_SpellScript();
    }
};

void AddSC_boss_grand_vizier_ertan()
{
    new boss_grand_vizier_ertan();
    new npc_ertans_vortex();
    new spell_storms_edge();
    new spell_storms_edge_script();
}
