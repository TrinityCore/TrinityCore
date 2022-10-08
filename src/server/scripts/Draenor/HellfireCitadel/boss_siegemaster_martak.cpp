/*
* Copyright (C) 2021 BfaCore Reforged
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
#include "hellfire_citadel.h"
#include "GameObject.h"
enum Spells
{
    SPELL_HOWLING_AXE = 184370,
    SPELL_INSPIRING_PRESENCE = 185090,
    SPELL_SHOCKWAVE = 184394,
};

enum Events
{
    // Intro
    EVENT_INTRO = 1,
    EVENT_HP_50,
    EVENT_HP_45,
    EVENT_SUMMON_1,
    EVENT_SUMMON_2,
    EVENT_SUMMON_3,
};

// 93023
struct boss_siegemaster_martak : public BossAI
{
    boss_siegemaster_martak(Creature* creature) : BossAI(creature, DATA_SIEGEMASTER_MARTAK) {  }

    Position pos1 = { 3944.46f, -563.65f, 30.9604f, 4.97272f };
    Position pos2 = { 3949.256f, -680.2031f, 30.94324f, 5.101f };

    void JustDied(Unit* /*killer*/) override
    {
        Talk(4);
        _JustDied();
        GameObject* box = me->SummonGameObject(243309, Position(3965.42f, -732.45f, 33.398f), QuaternionData(0.0f, 0.0f, 0.0f, 0.0f), WEEK);
        if(box)
            box->SetLootState(LootState::GO_READY);

        me->SummonCreature(NPC_IRON_REAVER, pos1);
    }

    void DoAction(int32 action) override
    {
        if (action == 1)
        {
            me->SetHomePosition(pos2);
            me->GetMotionMaster()->MovePoint(1, pos2, true);
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthWillBeBelowPctDamaged(50, damage))
        {
            events.ScheduleEvent(EVENT_HP_50, 3s);
        }
        if (me->HealthWillBeBelowPctDamaged(45, damage))
        {
            events.ScheduleEvent(EVENT_HP_45, 3s);
        }
    }

    void ScheduleTasks() override
    {
        Talk(1);
        me->SummonCreature(93931, Position(3933.29f, -561.4f, 31.0f, 4.845f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
        me->SummonCreature(92911, Position(3960.85f, -562.89f, 31.0f, 4.62f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
        me->SummonCreature(90114, Position(3955.5f, -560.0f, 31.0f, 4.6f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
        me->SummonCreature(93881, Position(3940.4f, -559.6f, 31.0f, 4.95f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
        events.ScheduleEvent(SPELL_HOWLING_AXE, 4s);
        events.ScheduleEvent(SPELL_INSPIRING_PRESENCE, 5s);
        events.ScheduleEvent(SPELL_SHOCKWAVE, 10s);
        events.ScheduleEvent(EVENT_SUMMON_1, 17s, 19s);
        events.ScheduleEvent(EVENT_SUMMON_2, 16s, 18s);
        events.ScheduleEvent(EVENT_SUMMON_3, 18s, 19s);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
        case SPELL_HOWLING_AXE:
        {
            DoCast(SPELL_HOWLING_AXE);
            DoCast(184379);
            events.Repeat(4s);
            break;
        }
        case SPELL_INSPIRING_PRESENCE:
        {
            DoCast(SPELL_INSPIRING_PRESENCE);
            events.Repeat(10s);
            break;
        }
        case SPELL_SHOCKWAVE:
        {
            DoCast(SPELL_SHOCKWAVE);
            DoCast(184393);
            events.Repeat(15s);
            break;
        }
        case EVENT_HP_50:
        {
            Talk(11);
            me->SummonCreature(90410, Position(3976.3f, -637.6f, 31.0f, 4.6f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(28s, 33s);
            break;

        case EVENT_HP_45:
        {
            Talk(6);
            me->SummonCreature(90432, Position(3907.3f, -643.6f, 31.0f, 4.6f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(28s, 33s);
            break;
        }
        case EVENT_SUMMON_1:
        {
            me->SummonCreature(93931, Position(3933.29f, -561.4f, 31.0f, 4.845f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(30s);
            break;
        }
        case EVENT_SUMMON_2:
        {
            me->SummonCreature(92911, Position(3960.85f, -562.89f, 31.0f, 4.6f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(35s);
            break;
        }
        case EVENT_SUMMON_3:
        {
            Talk(5);
            me->SummonCreature(90114, Position(3955.5f, -560.09f, 31.0f, 4.6f), TEMPSUMMON_MANUAL_DESPAWN, WEEK);
            events.Repeat(36s);
            break;
        }
        default:
            break;
        }
        }
    }



};

void AddSC_boss_siegemaster_martak()
{
    RegisterCreatureAI(boss_siegemaster_martak);
}
