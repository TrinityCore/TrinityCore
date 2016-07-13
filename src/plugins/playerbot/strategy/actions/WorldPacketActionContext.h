#pragma once

#include "AcceptInvitationAction.h"
#include "PassLeadershipToMasterAction.h"
#include "TellMasterAction.h"
#include "TalkToQuestGiverAction.h"
#include "AcceptQuestAction.h"
#include "LootRollAction.h"
#include "ReviveFromCorpseAction.h"
#include "AcceptResurrectAction.h"
#include "UseMeetingStoneAction.h"
#include "AreaTriggerAction.h"
#include "CheckMountStateAction.h"
#include "RememberTaxiAction.h"
#include "TradeStatusAction.h"
#include "InventoryChangeFailureAction.h"
#include "LootAction.h"
#include "QuestAction.h"
#include "LeaveGroupAction.h"
#include "TellCastFailedAction.h"
#include "AcceptDuelAction.h"
#include "ReadyCheckAction.h"
#include "LfgActions.h"
#include "SecurityCheckAction.h"
#include "GuildAcceptAction.h"

namespace ai
{
    class WorldPacketActionContext : public NamedObjectContext<Action>
    {
    public:
        WorldPacketActionContext()
        {
            creators["accept invitation"] = &WorldPacketActionContext::accept_invitation;
            creators["leader"] = &WorldPacketActionContext::pass_leadership_to_master;
            creators["tell not enough money"] = &WorldPacketActionContext::tell_not_enough_money;
            creators["tell not enough reputation"] = &WorldPacketActionContext::tell_not_enough_reputation;
            creators["tell cannot equip"] = &WorldPacketActionContext::tell_cannot_equip;
            creators["talk to quest giver"] = &WorldPacketActionContext::turn_in_quest;
            creators["accept quest"] = &WorldPacketActionContext::accept_quest;
            creators["accept all quests"] = &WorldPacketActionContext::accept_all_quests;
            creators["accept quest share"] = &WorldPacketActionContext::accept_quest_share;
            creators["loot roll"] = &WorldPacketActionContext::loot_roll;
            creators["revive from corpse"] = &WorldPacketActionContext::revive_from_corpse;
            creators["accept resurrect"] = &WorldPacketActionContext::accept_resurrect;
            creators["use meeting stone"] = &WorldPacketActionContext::use_meeting_stone;
            creators["area trigger"] = &WorldPacketActionContext::area_trigger;
            creators["reach area trigger"] = &WorldPacketActionContext::reach_area_trigger;
            creators["check mount state"] = &WorldPacketActionContext::check_mount_state;
            creators["remember taxi"] = &WorldPacketActionContext::remember_taxi;
            creators["accept trade"] = &WorldPacketActionContext::accept_trade;
            creators["store loot"] = &WorldPacketActionContext::store_loot;
            creators["tell out of react range"] = &WorldPacketActionContext::tell_out_of_react_range;
            creators["quest objective completed"] = &WorldPacketActionContext::quest_objective_completed;
            creators["party command"] = &WorldPacketActionContext::party_command;
            creators["tell cast failed"] = &WorldPacketActionContext::tell_cast_failed;
            creators["accept duel"] = &WorldPacketActionContext::accept_duel;
            creators["ready check"] = &WorldPacketActionContext::ready_check;
            creators["ready check finished"] = &WorldPacketActionContext::ready_check_finished;
            creators["uninvite"] = &WorldPacketActionContext::uninvite;
            creators["lfg join"] = &WorldPacketActionContext::lfg_join;
            creators["lfg accept"] = &WorldPacketActionContext::lfg_accept;
            creators["lfg role check"] = &WorldPacketActionContext::lfg_role_check;
            creators["lfg leave"] = &WorldPacketActionContext::lfg_leave;
            creators["lfg teleport"] = &WorldPacketActionContext::lfg_teleport;
            creators["security check"] = &WorldPacketActionContext::security_check;
            creators["guild accept"] = &WorldPacketActionContext::guild_accept;
        }

    private:
        static Action* guild_accept(PlayerbotAI* ai) { return new GuildAcceptAction(ai); }
        static Action* security_check(PlayerbotAI* ai) { return new SecurityCheckAction(ai); }
        static Action* lfg_teleport(PlayerbotAI* ai) { return new LfgTeleportAction(ai); }
        static Action* lfg_leave(PlayerbotAI* ai) { return new LfgLeaveAction(ai); }
        static Action* lfg_accept(PlayerbotAI* ai) { return new LfgAcceptAction(ai); }
        static Action* lfg_role_check(PlayerbotAI* ai) { return new LfgRoleCheckAction(ai); }
        static Action* lfg_join(PlayerbotAI* ai) { return new LfgJoinAction(ai); }
        static Action* uninvite(PlayerbotAI* ai) { return new UninviteAction(ai); }
        static Action* ready_check_finished(PlayerbotAI* ai) { return new FinishReadyCheckAction(ai); }
        static Action* ready_check(PlayerbotAI* ai) { return new ReadyCheckAction(ai); }
        static Action* accept_duel(PlayerbotAI* ai) { return new AcceptDuelAction(ai); }
        static Action* tell_cast_failed(PlayerbotAI* ai) { return new TellCastFailedAction(ai); }
        static Action* party_command(PlayerbotAI* ai) { return new PartyCommandAction(ai); }
        static Action* quest_objective_completed(PlayerbotAI* ai) { return new QuestObjectiveCompletedAction(ai); }
        static Action* store_loot(PlayerbotAI* ai) { return new StoreLootAction(ai); }
        static Action* tell_out_of_react_range(PlayerbotAI* ai) { return new OutOfReactRangeAction(ai); }
        static Action* accept_trade(PlayerbotAI* ai) { return new TradeStatusAction(ai); }
        static Action* remember_taxi(PlayerbotAI* ai) { return new RememberTaxiAction(ai); }
        static Action* check_mount_state(PlayerbotAI* ai) { return new CheckMountStateAction(ai); }
        static Action* area_trigger(PlayerbotAI* ai) { return new AreaTriggerAction(ai); }
        static Action* reach_area_trigger(PlayerbotAI* ai) { return new ReachAreaTriggerAction(ai); }
        static Action* use_meeting_stone(PlayerbotAI* ai) { return new UseMeetingStoneAction(ai); }
        static Action* accept_resurrect(PlayerbotAI* ai) { return new AcceptResurrectAction(ai); }
        static Action* revive_from_corpse(PlayerbotAI* ai) { return new ReviveFromCorpseAction(ai); }
        static Action* accept_invitation(PlayerbotAI* ai) { return new AcceptInvitationAction(ai); }
        static Action* pass_leadership_to_master(PlayerbotAI* ai) { return new PassLeadershipToMasterAction(ai); }
        static Action* tell_not_enough_money(PlayerbotAI* ai) { return new TellMasterAction(ai, "Not enough money"); }
        static Action* tell_not_enough_reputation(PlayerbotAI* ai) { return new TellMasterAction(ai, "Not enough reputation"); }
        static Action* tell_cannot_equip(PlayerbotAI* ai) { return new InventoryChangeFailureAction(ai); }
        static Action* turn_in_quest(PlayerbotAI* ai) { return new TalkToQuestGiverAction(ai); }
        static Action* accept_quest(PlayerbotAI* ai) { return new AcceptQuestAction(ai); }
        static Action* accept_all_quests(PlayerbotAI* ai) { return new AcceptAllQuestsAction(ai); }
        static Action* accept_quest_share(PlayerbotAI* ai) { return new AcceptQuestShareAction(ai); }
        static Action* loot_roll(PlayerbotAI* ai) { return (QueryItemUsageAction*)new LootRollAction(ai); }
    };


};
