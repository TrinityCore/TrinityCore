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
#include "ScriptedCreature.h"
#include "ScriptMgr.h"
#include "the_stockade.h"

enum Says
{
    SAY_PULL       = 0, // Forest just setback!
    SAY_ENRAGE     = 1, // AreaTriggerMessage: Hogger Enrages!
    SAY_DEATH      = 2, // Yiipe!

    SAY_WARDEN_1   = 0, // Yell - This ends here, Hogger!
    SAY_WARDEN_2   = 1, // Say - He's...he's dead?
    SAY_WARDEN_3   = 2  // Say - It's simply too good to be true. You couldn't have killed him so easily!
};

enum Spells
{
    SPELL_VICIOUS_SLICE     = 86604,
    SPELL_MADDENING_CALL    = 86620,
    SPELL_ENRAGE            = 86736
};

enum Events
{
    EVENT_VICIOUS_SLICE = 1,
    EVENT_MADDENING_CALL,

    EVENT_SAY_WARDEN_1,
    EVENT_SAY_WARDEN_2,
    EVENT_SAY_WARDEN_3
};

enum Points
{
    POINT_FINISH = 1
};

Position const wardenThelwaterMovePoint = { 152.019f, 106.198f, -35.1896f, 1.082104f };
Position const wardenThelwaterSpawnPosition = { 138.369f, 78.2932f, -33.85627f, 1.082104f };

// Hogger - 46254
struct boss_hogger : public BossAI
{
    boss_hogger(Creature* creature) : BossAI(creature, DATA_HOGGER), _hasEnraged(false) { }

    void Reset() override
    {
        _hasEnraged = false;
    }

    void EnterCombat(Unit* who) override
    {
        BossAI::EnterCombat(who);

        Talk(SAY_PULL);

        events.ScheduleEvent(EVENT_VICIOUS_SLICE, 3s, 4s);
        events.ScheduleEvent(EVENT_MADDENING_CALL, 1s, 2s);
    }

    void JustDied(Unit* killer) override
    {
        BossAI::JustDied(killer);

        Talk(SAY_DEATH);

        me->SummonCreature(NPC_WARDEN_THELWATER, wardenThelwaterSpawnPosition);
    }

    void JustSummoned(Creature* summon) override
    {
        BossAI::JustSummoned(summon);

        if (summon->GetEntry() == NPC_WARDEN_THELWATER)
            summon->GetMotionMaster()->MovePoint(POINT_FINISH, wardenThelwaterMovePoint);
    }

    void ExecuteEvent(uint32 eventId) override
    {
        switch (eventId)
        {
            case EVENT_VICIOUS_SLICE:
                DoCastVictim(SPELL_VICIOUS_SLICE);
                events.Repeat(10s, 14s);
                break;
            case EVENT_MADDENING_CALL:
                DoCast(SPELL_MADDENING_CALL);
                events.Repeat(15s, 20s);
                break;
            default:
                break;
        }
    }

    void DamageTaken(Unit* /*attacker*/, uint32& damage) override
    {
        if (me->HealthBelowPctDamaged(30, damage) && !_hasEnraged)
        {
            _hasEnraged = true;

            Talk(SAY_ENRAGE);
            DoCastSelf(SPELL_ENRAGE);
        }
    }

private:
    bool _hasEnraged;
};

// Warden Thelwater - 46409
struct npc_warden_thelwater : public ScriptedAI
{
    npc_warden_thelwater(Creature* creature) : ScriptedAI(creature) { }

    void MovementInform(uint32 type, uint32 id) override
    {
        if (type != POINT_MOTION_TYPE)
            return;

        if (id == POINT_FINISH)
        {
            scheduler.Schedule(1s, [this](TaskContext /*context*/)
            {
                Talk(SAY_WARDEN_1);
            });

            scheduler.Schedule(5s, [this](TaskContext /*context*/)
            {
                Talk(SAY_WARDEN_2);
            });

            scheduler.Schedule(8s, [this](TaskContext /*context*/)
            {
                Talk(SAY_WARDEN_3);
            });
        }
    }

    void UpdateAI(const uint32 diff) override
    {
        scheduler.Update(diff);
    }

private:
    TaskScheduler scheduler;
};

void AddSC_boss_hogger()
{
    RegisterStormwindStockadesAI(boss_hogger);
    RegisterStormwindStockadesAI(npc_warden_thelwater);
}
