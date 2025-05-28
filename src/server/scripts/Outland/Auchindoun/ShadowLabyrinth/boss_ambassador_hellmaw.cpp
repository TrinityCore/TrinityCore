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

#include "InstanceScript.h"
#include "MotionMaster.h"
#include "ScriptMgr.h"
#include "shadow_labyrinth.h"

enum HellmawTexts
{
    SAY_AGGRO               = 1,
    SAY_HELP                = 2,
    SAY_SLAY                = 3,
    SAY_DEATH               = 4
};

enum HellmawSpells
{
    SPELL_BANISH            = 30231,
    SPELL_CORROSIVE_ACID    = 33551,
    SPELL_FEAR              = 33547,
    SPELL_ENRAGE            = 34970
};

enum HellmawEvents
{
    EVENT_CORROSIVE_ACID    = 1,
    EVENT_FEAR,
    EVENT_BERSERK,

    EVENT_INTRO_1,
    EVENT_INTRO_2
};

enum HellmawMisc
{
    PATH_INTRO              = 669990,
    SOUND_INTRO             = 9349
};

// 18731 - Ambassador Hellmaw
struct boss_ambassador_hellmaw : public BossAI
{
    boss_ambassador_hellmaw(Creature* creature) : BossAI(creature, DATA_AMBASSADOR_HELLMAW) { }

    void JustEngagedWith(Unit* who) override
    {
        BossAI::JustEngagedWith(who);
        Talk(SAY_AGGRO);

        events.ScheduleEvent(EVENT_CORROSIVE_ACID, 5s, 10s);
        events.ScheduleEvent(EVENT_FEAR, 25s, 30s);
        if (IsHeroic())
            events.ScheduleEvent(EVENT_BERSERK, 3min);
    }

    void MoveInLineOfSight(Unit* who) override
    {
        if (me->HasAura(SPELL_BANISH))
            return;

        ScriptedAI::MoveInLineOfSight(who);
    }

    void DoAction(int32 actionId) override
    {
        if (actionId == ACTION_AMBASSADOR_HELLMAW_INTRO)
            events.ScheduleEvent(EVENT_INTRO_1, 0s);
        else if (actionId == ACTION_AMBASSADOR_HELLMAW_BANISH)
        {
            if (instance->GetData(DATA_FEL_OVERSEER))
            {
                /// !HACK: He is immune to banish
                me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, false);
                DoCastSelf(SPELL_BANISH);
            }
        }
    }

    void KilledUnit(Unit* who) override
    {
        if (who->GetTypeId() == TYPEID_PLAYER)
            Talk(SAY_SLAY);
    }

    void JustDied(Unit* /*killer*/) override
    {
        _JustDied();
        Talk(SAY_DEATH);
    }

    void UpdateAI(uint32 diff) override
    {
        if (!UpdateVictim())
        {
            events.Update(diff);

            while (uint32 eventId = events.ExecuteEvent())
            {
                switch (eventId)
                {
                    case EVENT_INTRO_1:
                        me->RemoveAurasDueToSpell(SPELL_BANISH);
                        me->HandleEmoteCommand(EMOTE_ONESHOT_ROAR);
                        DoPlaySoundToSet(me, SOUND_INTRO);
                        me->ApplySpellImmune(-1, IMMUNITY_MECHANIC, MECHANIC_BANISH, true);
                        events.ScheduleEvent(EVENT_INTRO_2, 1500ms);
                        break;
                    case EVENT_INTRO_2:
                        me->GetMotionMaster()->MovePath(PATH_INTRO, true);
                        break;
                    default:
                        break;
                }
            }

            return;
        }

        if (me->HasAura(SPELL_BANISH))
        {
            EnterEvadeMode(EVADE_REASON_OTHER);
            return;
        }

        events.Update(diff);

        if (me->HasUnitState(UNIT_STATE_CASTING))
            return;

        while (uint32 eventId = events.ExecuteEvent())
        {
            switch (eventId)
            {
                case EVENT_CORROSIVE_ACID:
                    DoCastVictim(SPELL_CORROSIVE_ACID);
                    events.Repeat(15s, 25s);
                    break;
                case EVENT_FEAR:
                    DoCastAOE(SPELL_FEAR);
                    events.Repeat(20s, 35s);
                    break;
                case EVENT_BERSERK:
                    DoCastSelf(SPELL_ENRAGE);
                    break;
                default:
                    break;
            }
        }

        DoMeleeAttackIfReady();
    }
};

void AddSC_boss_ambassador_hellmaw()
{
    RegisterShadowLabyrinthCreatureAI(boss_ambassador_hellmaw);
}
