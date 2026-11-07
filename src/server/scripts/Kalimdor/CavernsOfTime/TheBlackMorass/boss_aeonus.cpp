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

/*
 * Combat timers requires to be revisited
 */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptedCreature.h"
#include "SpellInfo.h"
#include "the_black_morass.h"

enum AeonusTexts
{
    SAY_ENTER                   = 0,
    SAY_BANISH                  = 1,
    SAY_AGGRO                   = 2,
    SAY_SLAY                    = 3,
    SAY_DEATH                   = 4,
    EMOTE_ENRAGE                = 5
};

enum AeonusSpells
{
    // Initial
    SPELL_THRASH                = 8876,
    SPELL_DOUBLE_ATTACK         = 19818,

    // Combat
    SPELL_CLEAVE                = 40504,
    SPELL_TIME_STOP             = 31422,
    SPELL_SAND_BREATH           = 31473,
    SPELL_ENRAGE                = 37605,
    SPELL_BANISH_HELPER         = 31550,

    // Misc
    SPELL_CORRUPT_MEDIVH        = 37853,
    SPELL_CLOSE_TIME_RIFT       = 31322
};

enum AeonusEvents
{
    EVENT_CLEAVE                = 1,
    EVENT_TIME_STOP,
    EVENT_SAND_BREATH,
    EVENT_ENRAGE,
    EVENT_BANISH_HELPER
};

enum AeonusMisc
{
    POINT_MEDIVH                = 0
};

// 17881 - Aeonus
struct boss_aeonus : public BossAI
{
    boss_aeonus(Creature* creature) : BossAI(creature, DATA_AEONUS) { }

    void JustAppeared() override
    {
        Talk(SAY_ENTER);

        DoCastSelf(IsHeroic() ? SPELL_DOUBLE_ATTACK : SPELL_THRASH);

        me->SetReactState(REACT_DEFENSIVE);

        if (Creature* medivh = instance->GetCreature(DATA_MEDIVH))
        {
            float x, y, z;
            medivh->GetContactPoint(me, x, y, z, 20.0f);
            me->GetMotionMaster()->MovePoint(POINT_MEDIVH, x, y, z);
        }
    }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);

        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CLEAVE, 10s, 25s);
        events.ScheduleEvent(EVENT_TIME_STOP, 10s, 20s);
        events.ScheduleEvent(EVENT_SAND_BREATH, 10s, 25s);
        events.ScheduleEvent(EVENT_ENRAGE, 20s, 25s);
        events.ScheduleEvent(EVENT_BANISH_HELPER, 1s);
    }

    void OnSpellCast(SpellInfo const* spellInfo) override
    {
        switch (spellInfo->Id)
        {
            case SPELL_BANISH_HELPER:
                Talk(SAY_BANISH);
                break;
            case SPELL_ENRAGE:
                Talk(EMOTE_ENRAGE);
                break;
            default:
                break;
        }
    }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type == POINT_MOTION_TYPE && id == POINT_MEDIVH)
            DoCastSelf(SPELL_CORRUPT_MEDIVH);
    }

    void JustReachedHome() override
    {
        BossAI::JustReachedHome();

        if (Creature* medivh = instance->GetCreature(DATA_MEDIVH))
        {
            float x, y, z;
            medivh->GetContactPoint(me, x, y, z, 20.0f);
            me->GetMotionMaster()->MovePoint(POINT_MEDIVH, x, y, z);
        }
    }

    void KilledUnit(Unit* /*who*/) override
    {
        Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);

        DoCastSelf(SPELL_CLOSE_TIME_RIFT, true);
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
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.Repeat(15s, 20s);
                    break;
                case EVENT_TIME_STOP:
                    DoCastSelf(SPELL_TIME_STOP);
                    events.Repeat(10s, 30s);
                    break;
                case EVENT_SAND_BREATH:
                    DoCastVictim(SPELL_SAND_BREATH);
                    events.Repeat(10s, 30s);
                    break;
                case EVENT_ENRAGE:
                    DoCastSelf(SPELL_ENRAGE);
                    events.Repeat(30s, 35s);
                    break;
                case EVENT_BANISH_HELPER:
                    if (me->FindNearestCreature(NPC_TIME_KEEPER, 30.0f, true))
                        DoCastSelf(SPELL_BANISH_HELPER);
                    events.Repeat(1s);
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

void AddSC_boss_aeonus()
{
    RegisterBlackMorassCreatureAI(boss_aeonus);
}
