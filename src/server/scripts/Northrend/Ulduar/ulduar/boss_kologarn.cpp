/*
 * Copyright (C) 2008-2010 TrinityCore <http://www.trinitycore.org/>
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
#include "ulduar.h"
#include "Vehicle.h"

#define SPELL_ARM_DEAD_DAMAGE   RAID_MODE(63629,63979)
#define SPELL_TWO_ARM_SMASH     RAID_MODE(63356,64003)
#define SPELL_ONE_ARM_SMASH     RAID_MODE(63573,64006)
#define SPELL_STONE_SHOUT       RAID_MODE(63716,64005)
#define SPELL_PETRIFY_BREATH    RAID_MODE(62030,63980)

#define SPELL_STONE_GRIP        RAID_MODE(62166,63981)
#define SPELL_ARM_SWEEP         RAID_MODE(63766,63983)

enum Events
{
    EVENT_NONE = 0,
    EVENT_SMASH,
    EVENT_GRIP,
    EVENT_SWEEP,
};

enum Yells
{
    SAY_AGGRO                                   = -1603230,
    SAY_SLAY_1                                  = -1603231,
    SAY_SLAY_2                                  = -1603232,
    SAY_LEFT_ARM_GONE                           = -1603233,
    SAY_RIGHT_ARM_GONE                          = -1603234,
    SAY_SHOCKWAVE                               = -1603235,
    SAY_GRAB_PLAYER                             = -1603236,
    SAY_DEATH                                   = -1603237,
    SAY_BERSERK                                 = -1603238,
};

enum
{
    ACHIEV_DISARMED_START_EVENT                   = 21687,
};

struct boss_kologarnAI : public BossAI
{
    boss_kologarnAI(Creature *pCreature) : BossAI(pCreature, TYPE_KOLOGARN), vehicle(pCreature->GetVehicleKit()),
        left(false), right(false)
    {
        assert(vehicle);
        me->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_NOT_SELECTABLE);
        me->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED); // i think this is a hack, but there is no other way to disable his rotation
    }

    Vehicle *vehicle;
    bool left, right;

    void AttackStart(Unit *who)
    {
        me->Attack(who, true);
    }

    void JustDied(Unit * /*victim*/)
    {
        DoScriptText(SAY_DEATH, me);
        _JustDied();
    }

    void KilledUnit(Unit* /*who*/)
    {
        DoScriptText(RAND(SAY_SLAY_2,SAY_SLAY_2), me);
    }

    void PassengerBoarded(Unit *who, int8 /*seatId*/, bool apply)
    {
        if (who->GetTypeId() == TYPEID_UNIT)
        {
            if (who->GetEntry() == 32933)
                left = apply;
            else if (who->GetEntry() == 32934)
                right = apply;

            if (!apply && instance)
                instance->DoStartTimedAchievement(ACHIEVEMENT_TIMED_TYPE_EVENT, ACHIEV_DISARMED_START_EVENT);

            who->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_STUNNED);
            CAST_CRE(who)->SetReactState(REACT_PASSIVE);
        }
    }

    void EnterCombat(Unit * /*who*/)
    {
        DoScriptText(SAY_AGGRO, me);
        _EnterCombat();
        events.ScheduleEvent(EVENT_SMASH, 5000);
        events.ScheduleEvent(EVENT_SWEEP, 10000);
        events.ScheduleEvent(EVENT_GRIP, 15000);
    }

    void UpdateAI(const uint32 diff)
    {
        if (!UpdateVictim())
            return;

        events.Update(diff);

        if (me->hasUnitState(UNIT_STAT_CASTING))
            return;

        // TODO: because we are using hack, he is stunned and cannot cast, so we use triggered for every spell
        switch(events.GetEvent())
        {
            case EVENT_NONE:
                break;
            case EVENT_SMASH:
                if (left && right)
                    DoCastVictim(SPELL_TWO_ARM_SMASH, true);
                else if (left || right)
                    DoCastVictim(SPELL_ONE_ARM_SMASH, true);
                events.RepeatEvent(15000);
                break;
            case EVENT_SWEEP:
                if (left)
                    DoCastAOE(SPELL_ARM_SWEEP, true);
                events.RepeatEvent(15000);
                break;
            case EVENT_GRIP:
                if (right)
                    DoCastAOE(SPELL_STONE_GRIP, true);
                events.RepeatEvent(15000);
                break;
            default:
                events.PopEvent();
                break;
        }

        DoMeleeAttackIfReady();
    }
};

CreatureAI* GetAI_boss_kologarn(Creature* pCreature)
{
    return new boss_kologarnAI (pCreature);
}

void AddSC_boss_kologarn()
{
    Script *newscript;
    newscript = new Script;
    newscript->Name = "boss_kologarn";
    newscript->GetAI = &GetAI_boss_kologarn;
    newscript->RegisterSelf();
}
