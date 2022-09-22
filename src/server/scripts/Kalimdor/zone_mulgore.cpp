/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
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
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"

enum EagleSpirit
{
    SPELL_EJECT_ALL_PASSENGERS = 50630,
    SPELL_SPIRIT_FORM          = 69324
};

Position const EagleSpiritflightPath[] =
{
    { -2884.155f, -71.08681f, 242.0678f },
    { -2720.592f, -111.0035f, 242.5955f },
    { -2683.951f, -382.9010f, 231.1792f },
    { -2619.148f, -484.9288f, 231.1792f },
    { -2543.868f, -525.3333f, 231.1792f },
    { -2465.321f, -502.4896f, 190.7347f },
    { -2343.872f, -401.8281f, -8.320873f }
};
uint32 const EagleSpiritflightPathSize = std::extent<decltype(EagleSpiritflightPath)>::value;

struct npc_mulgore_eagle_spirit : public ScriptedAI
{
    npc_mulgore_eagle_spirit(Creature* creature) : ScriptedAI(creature) { }

    void PassengerBoarded(Unit* /*who*/, int8 /*seatId*/, bool apply) override
    {
        if (!apply)
            return;

        DoCastSelf(SPELL_SPIRIT_FORM);
        me->GetMotionMaster()->MoveSmoothPath(EagleSpiritflightPathSize, EagleSpiritflightPath, EagleSpiritflightPathSize, false, true);
    }

    void MovementInform(uint32 type, uint32 pointId) override
    {
        if (type == EFFECT_MOTION_TYPE && pointId == EagleSpiritflightPathSize)
            DoCast(SPELL_EJECT_ALL_PASSENGERS);
    }
};

enum OurTribeImprisoned
{
    // Move Points
    POINT_ID_BRAVE_ESCAPED  = 1,

    // Spells
    SPELL_UNLOCKING         = 71725,

    // Events
    EVENT_TALK_FREED        = 1,
    EVENT_ESCAPE            = 2,

    // Texts
    SAY_BRAVE_FREED         = 0
};

static std::array<Position, 4> CapturedBraveEscapePoints =
{
    Position(-3042.8743f, -678.6991f, 45.932663f),
    Position(-3022.8967f, -674.9234f, 46.631878f),
    Position(-3006.0527f, -683.7966f, 47.65608f),
    Position(-2999.302f,   -695.0346f , 48.756355f)
};

struct npc_mulgore_captured_brave : public ScriptedAI
{
    npc_mulgore_captured_brave(Creature* creature) : ScriptedAI(creature) { }

    void SpellHit(WorldObject* /*caster*/, SpellInfo const* spell) override
    {
        if (spell->Id != SPELL_UNLOCKING)
            return;

        Position pos = me->GetPosition();
        me->MovePosition(pos, 10.f, 0.f);
        me->GetMotionMaster()->MovePoint(0, pos);
        _events.ScheduleEvent(EVENT_TALK_FREED, 3s + 600ms);
    }

    void UpdateAI(uint32 diff) override
    {
        _events.Update(diff);

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_TALK_FREED:
                    Talk(SAY_BRAVE_FREED);
                    _events.ScheduleEvent(EVENT_ESCAPE, 4s);
                    break;
                case EVENT_ESCAPE:
                {
                    Position dest = CapturedBraveEscapePoints.front();
                    for (uint8 i = 1; i < CapturedBraveEscapePoints.size(); ++i)
                        if (me->GetExactDist(CapturedBraveEscapePoints[i]) <= me->GetExactDist(dest))
                            dest = CapturedBraveEscapePoints[i];

                    me->setActive(true); // Ensure that the npc is always updating even when moving out of grid update range
                    me->GetMotionMaster()->MovePoint(POINT_ID_BRAVE_ESCAPED, dest);
                    break;
                }
                default:
                    break;
            }
        }
    }

    void MovementInform(uint32 motionType, uint32 pointId) override
    {
        if (motionType != POINT_MOTION_TYPE || pointId != POINT_ID_BRAVE_ESCAPED)
            return;

        me->DespawnOrUnsummon();
    }

private:
    EventMap _events;
};

enum RiteOfHonor
{
    // Texts
    SAY_AGGRO = 0,

    // Events
    EVENT_QUILLHORN     = 1,
    EVENT_TORCH_TOSS    = 2,

    // Spells
    SPELL_QUILLHORN     = 81691,
    SPELL_TORCH_TOSS    = 81695,
    SPELL_IMMOLATION    = 69316
};

struct npc_mulgore_chief_squealer_thornmantle : public ScriptedAI
{
    npc_mulgore_chief_squealer_thornmantle(Creature* creature) : ScriptedAI(creature) { }

    void JustEngagedWith(Unit* who) override
    {
        Talk(SAY_AGGRO, who);
        _events.ScheduleEvent(EVENT_QUILLHORN, 10s);
    }

    void EnterEvadeMode(EvadeReason why) override
    {
        ScriptedAI::EnterEvadeMode(why);
        _events.Reset();
    }

    void JustDied(Unit* killer) override
    {
        ScriptedAI::JustDied(killer);
        _events.Reset();
        me->m_Events.AddEventAtOffset([&]() { DoCastSelf(SPELL_IMMOLATION); }, 4s);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
            return;

        _events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = _events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_QUILLHORN:
                    DoCastVictim(SPELL_QUILLHORN);
                    _events.ScheduleEvent(EVENT_TORCH_TOSS, 2s + 500ms);
                    _events.Repeat(60s);
                    break;
                case EVENT_TORCH_TOSS:
                    DoCastVictim(SPELL_TORCH_TOSS);
                    break;
                default:
                    break;
            }

            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }

        DoMeleeAttackIfReady();
    }

private:
    EventMap _events;
};

void AddSC_mulgore()
{
    RegisterCreatureAI(npc_mulgore_eagle_spirit);
    RegisterCreatureAI(npc_mulgore_captured_brave);
    RegisterCreatureAI(npc_mulgore_chief_squealer_thornmantle);
}
