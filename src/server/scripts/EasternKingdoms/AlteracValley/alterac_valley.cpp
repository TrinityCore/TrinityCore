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
#include "BattlegroundAV.h"
#include "GameObject.h"
#include "GameObjectAI.h"
#include "Player.h"
#include "ScriptedCreature.h"

#include <chrono>

enum Spells
{
    SPELL_CHARGE                                  = 22911,
    SPELL_CLEAVE                                  = 40504,
    SPELL_DEMORALIZING_SHOUT                      = 23511,
    SPELL_ENRAGE                                  = 8599,
    SPELL_WHIRLWIND                               = 13736
};

enum Creatures
{
    NPC_NORTH_MARSHAL                             = 14762,
    NPC_SOUTH_MARSHAL                             = 14763,
    NPC_ICEWING_MARSHAL                           = 14764,
    NPC_STONEHEARTH_MARSHAL                       = 14765,
    NPC_EAST_FROSTWOLF_WARMASTER                  = 14772,
    NPC_ICEBLOOD_WARMASTER                        = 14773,
    NPC_TOWER_POINT_WARMASTER                     = 14776,
    NPC_WEST_FROSTWOLF_WARMASTER                  = 14777
};

enum Events
{
    EVENT_CHARGE_TARGET        = 1,
    EVENT_CLEAVE               = 2,
    EVENT_DEMORALIZING_SHOUT   = 3,
    EVENT_WHIRLWIND            = 4,
    EVENT_ENRAGE               = 5,
    EVENT_CHECK_RESET          = 6
};

struct npc_av_marshal_or_warmaster : public ScriptedAI
{
    npc_av_marshal_or_warmaster(Creature* creature) : ScriptedAI(creature) { }

    void Reset() override
    {
        events.Reset();
        events.ScheduleEvent(EVENT_CHARGE_TARGET, 2s, 12s);
        events.ScheduleEvent(EVENT_CLEAVE, 1s, 11s);
        events.ScheduleEvent(EVENT_DEMORALIZING_SHOUT, 2s);
        events.ScheduleEvent(EVENT_WHIRLWIND, 5s, 20s);
        events.ScheduleEvent(EVENT_ENRAGE, 5s, 20s);
        events.ScheduleEvent(EVENT_CHECK_RESET, 5s);
    }

    void JustAppeared() override
    {
        Reset();
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
                case EVENT_CHARGE_TARGET:
                    DoCastVictim(SPELL_CHARGE);
                    events.ScheduleEvent(EVENT_CHARGE, 10s, 25s);
                    break;
                case EVENT_CLEAVE:
                    DoCastVictim(SPELL_CLEAVE);
                    events.ScheduleEvent(EVENT_CLEAVE, 10s, 16s);
                    break;
                case EVENT_DEMORALIZING_SHOUT:
                    DoCast(me, SPELL_DEMORALIZING_SHOUT);
                    events.ScheduleEvent(EVENT_DEMORALIZING_SHOUT, 10s, 15s);
                    break;
                case EVENT_WHIRLWIND:
                    DoCast(me, SPELL_WHIRLWIND);
                    events.ScheduleEvent(EVENT_WHIRLWIND, 10s, 25s);
                    break;
                case EVENT_ENRAGE:
                    DoCast(me, SPELL_ENRAGE);
                    events.ScheduleEvent(EVENT_ENRAGE, 10s, 30s);
                    break;
                case EVENT_CHECK_RESET:
                {
                    Position const& _homePosition = me->GetHomePosition();
                    if (me->GetDistance2d(_homePosition.GetPositionX(), _homePosition.GetPositionY()) > 50.0f)
                    {
                        EnterEvadeMode();
                        return;
                    }
                    events.ScheduleEvent(EVENT_CHECK_RESET, 5s);
                    break;
                }
            }
            if (me->HasUnitState(UNIT_STATE_CASTING))
                return;
        }
    }

private:
    EventMap events;
};

struct go_av_capturable_object : public GameObjectAI
{
    go_av_capturable_object(GameObject* go) : GameObjectAI(go) { }

    void Reset() override
    {
        me->setActive(true);
    }

    bool OnGossipHello(Player* player) override
    {
        if (me->GetGoState() != GO_STATE_READY)
            return true;

        if (ZoneScript* zonescript = me->GetZoneScript())
        {
            zonescript->DoAction(ACTION_AV_INTERACT_CAPTURABLE_OBJECT, player, me);
            return false;
        }

        return true;
    }
};

struct go_av_contested_object : public go_av_capturable_object
{
    go_av_contested_object(GameObject* go) : go_av_capturable_object(go) { }

    void Reset() override
    {
        go_av_capturable_object::Reset();
        _scheduler.Schedule(4min, [&](TaskContext)
        {
            if (ZoneScript* zonescript = me->GetZoneScript())
                zonescript->DoAction(ACTION_AV_CAPTURE_CAPTURABLE_OBJECT, me, me);
        });
    }

    void UpdateAI(uint32 diff) override
    {
        _scheduler.Update(diff);
    }

private:
    TaskScheduler _scheduler;
};

class at_av_exploit : public AreaTriggerScript
{
public:
    at_av_exploit() : AreaTriggerScript("at_av_exploit") { }

    bool OnTrigger(Player* player, AreaTriggerEntry const* /*trigger*/) override
    {
        if (Battleground* battleground = player->GetBattleground())
            if (battleground->GetStatus() == STATUS_WAIT_JOIN)
                battleground->TeleportPlayerToExploitLocation(player);

        return true;
    }
};

void AddSC_alterac_valley()
{
    RegisterCreatureAI(npc_av_marshal_or_warmaster);
    RegisterGameObjectAI(go_av_capturable_object);
    RegisterGameObjectAI(go_av_contested_object);
    new at_av_exploit();
}
