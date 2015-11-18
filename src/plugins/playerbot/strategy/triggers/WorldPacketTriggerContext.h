#pragma once

#include "WorldPacketTrigger.h"
#include "WithinAreaTrigger.h"

namespace ai
{
    class WorldPacketTriggerContext : public NamedObjectContext<Trigger>
    {
    public:
        WorldPacketTriggerContext()
        {
            creators["gossip hello"] = &WorldPacketTriggerContext::gossip_hello;
            creators["group invite"] = &WorldPacketTriggerContext::group_invite;
            creators["group set leader"] = &WorldPacketTriggerContext::group_set_leader;
            creators["not enough money"] = &WorldPacketTriggerContext::no_money;
            creators["not enough reputation"] = &WorldPacketTriggerContext::no_reputation;
            creators["cannot equip"] = &WorldPacketTriggerContext::cannot_equip;
            creators["use game object"] = &WorldPacketTriggerContext::use_game_object;
            creators["complete quest"] = &WorldPacketTriggerContext::complete_quest;
            creators["accept quest"] = &WorldPacketTriggerContext::accept_quest;
            creators["quest share"] = &WorldPacketTriggerContext::quest_share;
            creators["loot roll"] = &WorldPacketTriggerContext::loot_roll;
            creators["resurrect request"] = &WorldPacketTriggerContext::resurrect_request;
            creators["area trigger"] = &WorldPacketTriggerContext::area_trigger;
            creators["within area trigger"] = &WorldPacketTriggerContext::within_area_trigger;
            creators["check mount state"] = &WorldPacketTriggerContext::check_mount_state;
            creators["activate taxi"] = &WorldPacketTriggerContext::taxi;
            creators["trade status"] = &WorldPacketTriggerContext::trade_status;
            creators["loot response"] = &WorldPacketTriggerContext::loot_response;
            creators["out of react range"] = &WorldPacketTriggerContext::out_of_react_range;
            creators["quest objective completed"] = &WorldPacketTriggerContext::quest_objective_completed;
            creators["item push result"] = &WorldPacketTriggerContext::item_push_result;
            creators["party command"] = &WorldPacketTriggerContext::party_command;
            creators["taxi done"] = &WorldPacketTriggerContext::taxi_done;
            creators["cast failed"] = &WorldPacketTriggerContext::cast_failed;
            creators["duel requested"] = &WorldPacketTriggerContext::duel_requested;
            creators["ready check"] = &WorldPacketTriggerContext::ready_check;
            creators["ready check finished"] = &WorldPacketTriggerContext::ready_check_finished;
            creators["uninvite"] = &WorldPacketTriggerContext::uninvite;
            creators["lfg join"] = &WorldPacketTriggerContext::lfg_update;
            creators["lfg proposal"] = &WorldPacketTriggerContext::lfg_proposal;
            creators["lfg role check"] = &WorldPacketTriggerContext::lfg_role_check;
            creators["lfg leave"] = &WorldPacketTriggerContext::lfg_leave;
            creators["guild invite"] = &WorldPacketTriggerContext::guild_invite;
            creators["lfg teleport"] = &WorldPacketTriggerContext::lfg_teleport;
        }

    private:
        static Trigger* guild_invite(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "guild invite"); }
        static Trigger* lfg_teleport(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "lfg teleport"); }
        static Trigger* lfg_leave(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "lfg leave"); }
        static Trigger* lfg_proposal(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "lfg proposal"); }
        static Trigger* lfg_role_check(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "lfg role check"); }
        static Trigger* lfg_update(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "lfg join"); }
        static Trigger* uninvite(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "uninvite"); }
        static Trigger* ready_check_finished(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "ready check finished"); }
        static Trigger* ready_check(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "ready check"); }
        static Trigger* duel_requested(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "duel requested"); }
        static Trigger* cast_failed(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "cast failed"); }
        static Trigger* taxi_done(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "taxi done"); }
        static Trigger* party_command(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "party command"); }
        static Trigger* item_push_result(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "item push result"); }
        static Trigger* quest_objective_completed(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "quest objective completed"); }
        static Trigger* out_of_react_range(PlayerbotAI* ai) { return new OutOfReactRangeTrigger(ai); }
        static Trigger* loot_response(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "loot response"); }
        static Trigger* trade_status(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "trade status"); }
        static Trigger* cannot_equip(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "cannot equip"); }
        static Trigger* check_mount_state(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "check mount state"); }
        static Trigger* area_trigger(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "area trigger"); }
        static Trigger* within_area_trigger(PlayerbotAI* ai) { return new WithinAreaTrigger(ai); }
        static Trigger* resurrect_request(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "resurrect request"); }
        static Trigger* gossip_hello(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "gossip hello"); }
        static Trigger* group_invite(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "group invite"); }
        static Trigger* group_set_leader(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "group set leader"); }
        static Trigger* no_money(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "not enough money"); }
        static Trigger* no_reputation(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "not enough reputation"); }
        static Trigger* use_game_object(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "use game object"); }
        static Trigger* complete_quest(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "complete quest"); }
        static Trigger* accept_quest(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "accept quest"); }
        static Trigger* quest_share(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "quest share"); }
        static Trigger* loot_roll(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "loot roll"); }
        static Trigger* taxi(PlayerbotAI* ai) { return new WorldPacketTrigger(ai, "activate taxi"); }
    };
};
