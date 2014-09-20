#pragma once

#include "ListQuestsActions.h"
#include "StatsAction.h"
#include "LeaveGroupAction.h"
#include "TellReputationAction.h"
#include "LogLevelAction.h"
#include "TellLosAction.h"
#include "DropQuestAction.h"
#include "QueryQuestAction.h"
#include "QueryItemUsageAction.h"
#include "LootStrategyAction.h"
#include "AddLootAction.h"
#include "ReleaseSpiritAction.h"
#include "TeleportAction.h"
#include "TaxiAction.h"
#include "RepairAllAction.h"
#include "UseItemAction.h"
#include "TellItemCountAction.h"
#include "RewardAction.h"
#include "BuyAction.h"
#include "SellAction.h"
#include "UnequipAction.h"
#include "EquipAction.h"
#include "TradeAction.h"
#include "ChangeTalentsAction.h"
#include "ListSpellsAction.h"
#include "ChangeStrategyAction.h"
#include "TrainerAction.h"
#include "ChangeChatAction.h"
#include "SetHomeAction.h"
#include "ResetAiAction.h"
#include "DestroyItemAction.h"
#include "BuffAction.h"
#include "AttackAction.h"
#include "HelpAction.h"
#include "GuildBankAction.h"
#include "ChatShortcutActions.h"
#include "GossipHelloAction.h"
#include "CastCustomSpellAction.h"
#include "InviteToGroupAction.h"
#include "TellCastFailedAction.h"
#include "RtiAction.h"
#include "ReviveFromCorpseAction.h"
#include "BankAction.h"
#include "PositionAction.h"
#include "TellTargetAction.h"
#include "UseMeetingStoneAction.h"
#include "WhoAction.h"
#include "SaveManaAction.h"
#include "../values/Formations.h"

namespace ai
{
    class ChatActionContext : public NamedObjectContext<Action>
    {
    public:
        ChatActionContext()
        {
            creators["stats"] = &ChatActionContext::stats;
            creators["quests"] = &ChatActionContext::quests;
            creators["leave"] = &ChatActionContext::leave;
            creators["reputation"] = &ChatActionContext::reputation;
            creators["log"] = &ChatActionContext::log;
            creators["los"] = &ChatActionContext::los;
            creators["drop"] = &ChatActionContext::drop;
            creators["query quest"] = &ChatActionContext::query_quest;
            creators["query item usage"] = &ChatActionContext::query_item_usage;
            creators["ll"] = &ChatActionContext::ll;
            creators["add all loot"] = &ChatActionContext::add_all_loot;
            creators["release"] = &ChatActionContext::release;
            creators["teleport"] = &ChatActionContext::teleport;
            creators["taxi"] = &ChatActionContext::taxi;
            creators["repair"] = &ChatActionContext::repair;
            creators["use"] = &ChatActionContext::use;
            creators["item count"] = &ChatActionContext::item_count;
            creators["equip"] = &ChatActionContext::equip;
            creators["unequip"] = &ChatActionContext::unequip;
            creators["sell"] = &ChatActionContext::sell;
            creators["buy"] = &ChatActionContext::buy;
            creators["reward"] = &ChatActionContext::reward;
            creators["trade"] = &ChatActionContext::trade;
            creators["talents"] = &ChatActionContext::talents;
            creators["spells"] = &ChatActionContext::spells;
            creators["co"] = &ChatActionContext::co;
            creators["nc"] = &ChatActionContext::nc;
            creators["dead"] = &ChatActionContext::dead;
            creators["trainer"] = &ChatActionContext::trainer;
            creators["attack my target"] = &ChatActionContext::attack_my_target;
            creators["chat"] = &ChatActionContext::chat;
            creators["home"] = &ChatActionContext::home;
            creators["destroy"] = &ChatActionContext::destroy;
            creators["reset ai"] = &ChatActionContext::reset_ai;
            creators["buff"] = &ChatActionContext::buff;
            creators["help"] = &ChatActionContext::help;
            creators["gb"] = &ChatActionContext::gb;
            creators["bank"] = &ChatActionContext::bank;
            creators["follow chat shortcut"] = &ChatActionContext::follow_chat_shortcut;
            creators["stay chat shortcut"] = &ChatActionContext::stay_chat_shortcut;
            creators["flee chat shortcut"] = &ChatActionContext::flee_chat_shortcut;
            creators["runaway chat shortcut"] = &ChatActionContext::runaway_chat_shortcut;
            creators["grind chat shortcut"] = &ChatActionContext::grind_chat_shortcut;
            creators["tank attack chat shortcut"] = &ChatActionContext::tank_attack_chat_shortcut;
            creators["gossip hello"] = &ChatActionContext::gossip_hello;
            creators["cast custom spell"] = &ChatActionContext::cast_custom_spell;
            creators["invite"] = &ChatActionContext::invite;
            creators["spell"] = &ChatActionContext::spell;
            creators["rti"] = &ChatActionContext::rti;
            creators["spirit healer"] = &ChatActionContext::spirit_healer;
            creators["position"] = &ChatActionContext::position;
            creators["tell target"] = &ChatActionContext::tell_target;
            creators["summon"] = &ChatActionContext::summon;
            creators["who"] = &ChatActionContext::who;
            creators["save mana"] = &ChatActionContext::save_mana;
            creators["max dps chat shortcut"] = &ChatActionContext::max_dps_chat_shortcut;
            creators["tell attackers"] = &ChatActionContext::tell_attackers;
            creators["formation"] = &ChatActionContext::formation;
        }

    private:
        static Action* formation(PlayerbotAI* ai) { return new SetFormationAction(ai); }
        static Action* tell_attackers(PlayerbotAI* ai) { return new TellAttackersAction(ai); }
        static Action* max_dps_chat_shortcut(PlayerbotAI* ai) { return new MaxDpsChatShortcutAction(ai); }
        static Action* save_mana(PlayerbotAI* ai) { return new SaveManaAction(ai); }
        static Action* who(PlayerbotAI* ai) { return new WhoAction(ai); }
        static Action* summon(PlayerbotAI* ai) { return new SummonAction(ai); }
        static Action* tell_target(PlayerbotAI* ai) { return new TellTargetAction(ai); }
        static Action* position(PlayerbotAI* ai) { return new PositionAction(ai); }
        static Action* spirit_healer(PlayerbotAI* ai) { return new SpiritHealerAction(ai); }
        static Action* rti(PlayerbotAI* ai) { return new RtiAction(ai); }
        static Action* invite(PlayerbotAI* ai) { return new InviteToGroupAction(ai); }
        static Action* spell(PlayerbotAI* ai) { return new TellSpellAction(ai); }
        static Action* cast_custom_spell(PlayerbotAI* ai) { return new CastCustomSpellAction(ai); }
        static Action* tank_attack_chat_shortcut(PlayerbotAI* ai) { return new TankAttackChatShortcutAction(ai); }
        static Action* grind_chat_shortcut(PlayerbotAI* ai) { return new GrindChatShortcutAction(ai); }
        static Action* flee_chat_shortcut(PlayerbotAI* ai) { return new FleeChatShortcutAction(ai); }
        static Action* runaway_chat_shortcut(PlayerbotAI* ai) { return new GoawayChatShortcutAction(ai); }
        static Action* stay_chat_shortcut(PlayerbotAI* ai) { return new StayChatShortcutAction(ai); }
        static Action* follow_chat_shortcut(PlayerbotAI* ai) { return new FollowChatShortcutAction(ai); }
        static Action* gb(PlayerbotAI* ai) { return new GuildBankAction(ai); }
        static Action* bank(PlayerbotAI* ai) { return new BankAction(ai); }
        static Action* help(PlayerbotAI* ai) { return new HelpAction(ai); }
        static Action* buff(PlayerbotAI* ai) { return new BuffAction(ai); }
        static Action* destroy(PlayerbotAI* ai) { return new DestroyItemAction(ai); }
        static Action* home(PlayerbotAI* ai) { return new SetHomeAction(ai); }
        static Action* chat(PlayerbotAI* ai) { return new ChangeChatAction(ai); }
        static Action* attack_my_target(PlayerbotAI* ai) { return new AttackMyTargetAction(ai); }
        static Action* trainer(PlayerbotAI* ai) { return new TrainerAction(ai); }
        static Action* co(PlayerbotAI* ai) { return new ChangeCombatStrategyAction(ai); }
        static Action* nc(PlayerbotAI* ai) { return new ChangeNonCombatStrategyAction(ai); }
        static Action* dead(PlayerbotAI* ai) { return new ChangeDeadStrategyAction(ai); }
        static Action* spells(PlayerbotAI* ai) { return new ListSpellsAction(ai); }
        static Action* talents(PlayerbotAI* ai) { return new ChangeTalentsAction(ai); }

        static Action* equip(PlayerbotAI* ai) { return new EquipAction(ai); }
        static Action* unequip(PlayerbotAI* ai) { return new UnequipAction(ai); }
        static Action* sell(PlayerbotAI* ai) { return new SellAction(ai); }
        static Action* buy(PlayerbotAI* ai) { return new BuyAction(ai); }
        static Action* reward(PlayerbotAI* ai) { return new RewardAction(ai); }
        static Action* trade(PlayerbotAI* ai) { return new TradeAction(ai); }

        static Action* item_count(PlayerbotAI* ai) { return new TellItemCountAction(ai); }
        static Action* use(PlayerbotAI* ai) { return new UseItemAction(ai); }
        static Action* repair(PlayerbotAI* ai) { return new RepairAllAction(ai); }
        static Action* taxi(PlayerbotAI* ai) { return new TaxiAction(ai); }
        static Action* teleport(PlayerbotAI* ai) { return new TeleportAction(ai); }
        static Action* release(PlayerbotAI* ai) { return new ReleaseSpiritAction(ai); }
        static Action* query_item_usage(PlayerbotAI* ai) { return new QueryItemUsageAction(ai); }
        static Action* query_quest(PlayerbotAI* ai) { return new QueryQuestAction(ai); }
        static Action* drop(PlayerbotAI* ai) { return new DropQuestAction(ai); }
        static Action* stats(PlayerbotAI* ai) { return new StatsAction(ai); }
        static Action* quests(PlayerbotAI* ai) { return new ListQuestsAction(ai); }
        static Action* leave(PlayerbotAI* ai) { return new LeaveGroupAction(ai); }
        static Action* reputation(PlayerbotAI* ai) { return new TellReputationAction(ai); }
        static Action* log(PlayerbotAI* ai) { return new LogLevelAction(ai); }
        static Action* los(PlayerbotAI* ai) { return new TellLosAction(ai); }
        static Action* ll(PlayerbotAI* ai) { return new LootStrategyAction(ai); }
        static Action* add_all_loot(PlayerbotAI* ai) { return new AddAllLootAction(ai); }
        static Action* reset_ai(PlayerbotAI* ai) { return new ResetAiAction(ai); }
        static Action* gossip_hello(PlayerbotAI* ai) { return new GossipHelloAction(ai); }
    };


};
