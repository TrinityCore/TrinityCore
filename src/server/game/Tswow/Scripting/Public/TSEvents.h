/*
 * This file is part of tswow (https://github.com/tswow/).
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * 
 * This program is free software: you can redistribute it and/or 
 * modify it under the terms of the GNU General Public License as 
 * published by the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, 
 * but WITHOUT ANY WARRANTY; without even the implied warranty of 
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 
 * See the GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License 
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#pragma once

#include "TSEvent.h"
#include "TSPlayer.h"
#include "TSMutable.h"
#include "TSMutableString.h"
#include <cstdint>

// WorldScript
EVENT_TYPE(WorldOnOpenStateChange,bool)
EVENT_TYPE(WorldOnConfigLoad,bool)
EVENT_TYPE(WorldOnMotdChange,TSString)
EVENT_TYPE(WorldOnShutdownInitiate,uint32,uint32)
EVENT_TYPE(WorldOnUpdate,uint32)

// FormulaScript
EVENT_TYPE(FormulaOnHonorCalculation,TSMutable<float>,uint8,float)
EVENT_TYPE(FormulaOnGrayLevelCalculation,TSMutable<uint8>,uint8)
EVENT_TYPE(FormulaOnColorCodeCalculation,TSMutable<uint32>,uint8,uint8)
EVENT_TYPE(FormulaOnZeroDifferenceCalculation,TSMutable<uint8>,uint8)
EVENT_TYPE(FormulaOnBaseGainCalculation,TSMutable<uint32>,uint8,uint8,uint32)
EVENT_TYPE(FormulaOnGainCalculation,TSMutable<uint32>,TSPlayer,TSUnit)
EVENT_TYPE(FormulaOnGroupRateCalculation,TSMutable<float>,uint32,bool)

// ItemScript
EVENT_TYPE(ItemOnQuestAccept,TSPlayer,TSItem,TSQuest, TSMutable<bool>)
//EVENT_TYPE(ItemOnUse,TSPlayer,TSItem,TSMutable<const>, TSMutable<bool>)
EVENT_TYPE(ItemOnExpire,TSPlayer,TSItemTemplate, TSMutable<bool>)
EVENT_TYPE(ItemOnRemove,TSPlayer,TSItem, TSMutable<bool>)
EVENT_TYPE(ItemOnCastItemCombatSpell,TSPlayer,TSUnit,TSSpellInfo,TSItem,TSMutable<bool>)

// UnitScript
EVENT_TYPE(UnitOnHeal,TSUnit,TSUnit,TSMutable<uint32>)
EVENT_TYPE(UnitOnDamage,TSUnit,TSUnit,TSMutable<uint32>)
EVENT_TYPE(UnitModifyPeriodicDamageAurasTick,TSUnit,TSUnit,TSMutable<uint32>)
EVENT_TYPE(UnitModifyMeleeDamage,TSUnit,TSUnit,TSMutable<uint32>)
EVENT_TYPE(UnitModifySpellDamageTaken,TSUnit,TSUnit,TSMutable<int32>)
//EVENT_TYPE(UnitModifyVehiclePassengerExitPos,TSUnit,TSVehicle,TSMutable<Position>)

// AreaTriggerScript
//EVENT_TYPE(AreaTriggerOnTrigger,TSPlayer,const*, TSMutable<bool>)

// WeatherScript
//EVENT_TYPE(WeatherOnChange,Weather*,WeatherState,float)

// AuctionHouseScript
//EVENT_TYPE(AuctionHouseOnAuctionAdd,AuctionHouseObject*,AuctionEntry*)
//EVENT_TYPE(AuctionHouseOnAuctionRemove,AuctionHouseObject*,AuctionEntry*)
//EVENT_TYPE(AuctionHouseOnAuctionSuccessful,AuctionHouseObject*,AuctionEntry*)
//EVENT_TYPE(AuctionHouseOnAuctionExpire,AuctionHouseObject*,AuctionEntry*)

// ConditionScript
//EVENT_TYPE(ConditionOnConditionCheck,const*,TSMutable<ConditionSourceInfo>, TSMutable<bool>)

// VehicleScript
EVENT_TYPE(VehicleOnInstall,TSVehicle)
EVENT_TYPE(VehicleOnUninstall,TSVehicle)
EVENT_TYPE(VehicleOnReset,TSVehicle)
EVENT_TYPE(VehicleOnInstallAccessory,TSVehicle,TSCreature)
EVENT_TYPE(VehicleOnAddPassenger,TSVehicle,TSUnit,int8)
EVENT_TYPE(VehicleOnRemovePassenger,TSVehicle,TSUnit)

// AchievementCriteriaScript
//EVENT_TYPE(AchievementCriteriaOnCheck,TSPlayer,TSUnit, TSMutable<bool>)

// PlayerScript
EVENT_TYPE(PlayerOnPVPKill,TSPlayer,TSPlayer)
EVENT_TYPE(PlayerOnCreatureKill,TSPlayer,TSCreature)
EVENT_TYPE(PlayerOnPlayerKilledByCreature,TSCreature,TSPlayer)
EVENT_TYPE(PlayerOnLevelChanged,TSPlayer,uint8)
EVENT_TYPE(PlayerOnFreeTalentPointsChanged,TSPlayer,uint32)
EVENT_TYPE(PlayerOnTalentsReset,TSPlayer,bool)
EVENT_TYPE(PlayerOnMoneyChanged,TSPlayer,TSMutable<int32>)
EVENT_TYPE(PlayerOnMoneyLimit,TSPlayer,int32)
EVENT_TYPE(PlayerOnGiveXP,TSPlayer,TSMutable<uint32>,TSUnit)
EVENT_TYPE(PlayerOnReputationChange,TSPlayer,uint32,TSMutable<int32>,bool)
EVENT_TYPE(PlayerOnDuelRequest,TSPlayer,TSPlayer)
EVENT_TYPE(PlayerOnDuelStart,TSPlayer,TSPlayer)
EVENT_TYPE(PlayerOnDuelEnd,TSPlayer,TSPlayer,uint32)
EVENT_TYPE(PlayerOnSay,TSPlayer,uint32,uint32,TSMutableString)
EVENT_TYPE(PlayerOnWhisper,TSPlayer,uint32,uint32,TSMutableString,TSPlayer)
EVENT_TYPE(PlayerOnChatGroup,TSPlayer,uint32,uint32,TSMutableString,TSGroup)
EVENT_TYPE(PlayerOnChatGuild,TSPlayer,uint32,uint32,TSMutableString,TSGuild)
//EVENT_TYPE(PlayerOnChat,TSPlayer,uint32,uint32,TSString,Channel*)
EVENT_TYPE(PlayerOnEmote,TSPlayer,uint32)
EVENT_TYPE(PlayerOnTextEmote,TSPlayer,uint32,uint32,uint64)
EVENT_TYPE(PlayerOnSpellCast,TSPlayer,TSSpell,bool)
EVENT_TYPE(PlayerOnLogin,TSPlayer,bool)
EVENT_TYPE(PlayerOnLogout,TSPlayer)
EVENT_TYPE(PlayerOnCreate,TSPlayer)
EVENT_TYPE(PlayerOnDelete,uint64,uint32)
EVENT_TYPE(PlayerOnFailedDelete,uint64,uint32)
EVENT_TYPE(PlayerOnSave,TSPlayer)
EVENT_TYPE(PlayerOnBindToInstance,TSPlayer,uint32,uint32,bool,uint8)
EVENT_TYPE(PlayerOnUpdateZone,TSPlayer,uint32,uint32)
EVENT_TYPE(PlayerOnMapChanged,TSPlayer)
EVENT_TYPE(PlayerOnQuestObjectiveProgress,TSPlayer,TSQuest,uint32,uint16)
EVENT_TYPE(PlayerOnQuestStatusChange,TSPlayer,uint32)
EVENT_TYPE(PlayerOnMovieComplete,TSPlayer,uint32)
EVENT_TYPE(PlayerOnPlayerRepop,TSPlayer)

// AccountScript
EVENT_TYPE(AccountOnAccountLogin,uint32)
EVENT_TYPE(AccountOnFailedAccountLogin,uint32)
EVENT_TYPE(AccountOnEmailChange,uint32)
EVENT_TYPE(AccountOnFailedEmailChange,uint32)
EVENT_TYPE(AccountOnPasswordChange,uint32)
EVENT_TYPE(AccountOnFailedPasswordChange,uint32)

// GuildScript
EVENT_TYPE(GuildOnAddMember,TSGuild,TSPlayer,TSMutable<uint8>)
EVENT_TYPE(GuildOnRemoveMember,TSGuild,TSPlayer,bool,bool)
EVENT_TYPE(GuildOnMOTDChanged,TSGuild,TSString)
EVENT_TYPE(GuildOnInfoChanged,TSGuild,TSString)
EVENT_TYPE(GuildOnCreate,TSGuild,TSPlayer,TSString)
EVENT_TYPE(GuildOnDisband,TSGuild)
EVENT_TYPE(GuildOnMemberWitdrawMoney,TSGuild,TSPlayer,TSMutable<uint32>,bool)
EVENT_TYPE(GuildOnMemberDepositMoney,TSGuild,TSPlayer,TSMutable<uint32>)
EVENT_TYPE(GuildOnEvent,TSGuild,uint8,uint32,uint32,uint8)
EVENT_TYPE(GuildOnBankEvent,TSGuild,uint8,uint8,uint32,uint32,uint16,uint8)

// GroupScript
EVENT_TYPE(GroupOnAddMember,TSGroup,uint64)
EVENT_TYPE(GroupOnInviteMember,TSGroup,uint64)
EVENT_TYPE(GroupOnRemoveMember,TSGroup,uint64,uint32,uint64,TSString)
EVENT_TYPE(GroupOnChangeLeader,TSGroup,uint64,uint64)
EVENT_TYPE(GroupOnDisband,TSGroup)


struct TSEvents
{
    // WorldScript
    EVENT(WorldOnOpenStateChange)
    EVENT(WorldOnConfigLoad)
    EVENT(WorldOnMotdChange)
    EVENT(WorldOnShutdownInitiate)
    EVENT(WorldOnUpdate)

    // FormulaScript
    EVENT(FormulaOnHonorCalculation)
    EVENT(FormulaOnGrayLevelCalculation)
    EVENT(FormulaOnColorCodeCalculation)
    EVENT(FormulaOnZeroDifferenceCalculation)
    EVENT(FormulaOnBaseGainCalculation)
    EVENT(FormulaOnGainCalculation)
    EVENT(FormulaOnGroupRateCalculation)

    // ItemScript
    EVENT(ItemOnQuestAccept)
    //EVENT(ItemOnUse)
    EVENT(ItemOnExpire)
    EVENT(ItemOnRemove)
    EVENT(ItemOnCastItemCombatSpell)


    // UnitScript
    EVENT(UnitOnHeal)
    EVENT(UnitOnDamage)
    EVENT(UnitModifyPeriodicDamageAurasTick)
    EVENT(UnitModifyMeleeDamage)
    EVENT(UnitModifySpellDamageTaken)
    //EVENT(UnitModifyVehiclePassengerExitPos)

    // AreaTriggerScript
    //EVENT(AreaTriggerOnTrigger)

    // WeatherScript
    //EVENT(WeatherOnChange)

    // AuctionHouseScript
    //EVENT(AuctionHouseOnAuctionAdd)
    //EVENT(AuctionHouseOnAuctionRemove)
    //EVENT(AuctionHouseOnAuctionSuccessful)
    //EVENT(AuctionHouseOnAuctionExpire)

    // ConditionScript
    //EVENT(ConditionOnConditionCheck)

    // VehicleScript
    EVENT(VehicleOnInstall)
    EVENT(VehicleOnUninstall)
    EVENT(VehicleOnReset)
    EVENT(VehicleOnInstallAccessory)
    EVENT(VehicleOnAddPassenger)
    EVENT(VehicleOnRemovePassenger)


    // AchievementCriteriaScript
    //EVENT(AchievementCriteriaOnCheck)


    // PlayerScript
    EVENT(PlayerOnPVPKill)
    EVENT(PlayerOnCreatureKill)
    EVENT(PlayerOnPlayerKilledByCreature)
    EVENT(PlayerOnLevelChanged)
    EVENT(PlayerOnFreeTalentPointsChanged)
    EVENT(PlayerOnTalentsReset)
    EVENT(PlayerOnMoneyChanged)
    EVENT(PlayerOnMoneyLimit)
    EVENT(PlayerOnGiveXP)
    EVENT(PlayerOnReputationChange)
    EVENT(PlayerOnDuelRequest)
    EVENT(PlayerOnDuelStart)
    EVENT(PlayerOnDuelEnd)
    EVENT(PlayerOnSay)
    EVENT(PlayerOnWhisper)
    EVENT(PlayerOnChatGroup)
    EVENT(PlayerOnChatGuild)
    //EVENT(PlayerOnChat) // <-- On Chat Channel
    EVENT(PlayerOnEmote)
    EVENT(PlayerOnTextEmote)
    EVENT(PlayerOnSpellCast)
    EVENT(PlayerOnLogin)
    EVENT(PlayerOnLogout)
    EVENT(PlayerOnCreate)
    EVENT(PlayerOnDelete)
    EVENT(PlayerOnFailedDelete)
    EVENT(PlayerOnSave)
    EVENT(PlayerOnBindToInstance)
    EVENT(PlayerOnUpdateZone)
    EVENT(PlayerOnMapChanged)
    EVENT(PlayerOnQuestObjectiveProgress)
    EVENT(PlayerOnQuestStatusChange)
    EVENT(PlayerOnMovieComplete)
    EVENT(PlayerOnPlayerRepop)

    // AccountScript
    EVENT(AccountOnAccountLogin)
    EVENT(AccountOnFailedAccountLogin)
    EVENT(AccountOnEmailChange)
    EVENT(AccountOnFailedEmailChange)
    EVENT(AccountOnPasswordChange)
    EVENT(AccountOnFailedPasswordChange)

    // GuildScript
    EVENT(GuildOnAddMember)
    EVENT(GuildOnRemoveMember)
    EVENT(GuildOnMOTDChanged)
    EVENT(GuildOnInfoChanged)
    EVENT(GuildOnCreate)
    EVENT(GuildOnDisband)
    EVENT(GuildOnMemberWitdrawMoney)
    EVENT(GuildOnMemberDepositMoney)
    EVENT(GuildOnEvent)
    EVENT(GuildOnBankEvent)

    // GroupScript
    EVENT(GroupOnAddMember)
    EVENT(GroupOnInviteMember)
    EVENT(GroupOnRemoveMember)
    EVENT(GroupOnChangeLeader)
    EVENT(GroupOnDisband)
};

class TSEventHandlers
{
public:

    struct ServerEvents: public EventHandler
    {
         ServerEvents* operator->() { return this;}
    } Server;

    struct WorldEvents: public EventHandler
    {
         WorldEvents* operator->() { return this;}
         EVENT_HANDLE(World,OnOpenStateChange)
         EVENT_HANDLE(World,OnConfigLoad)
         EVENT_HANDLE(World,OnMotdChange)
         EVENT_HANDLE(World,OnShutdownInitiate)
         EVENT_HANDLE(World,OnUpdate)
    } World;

    struct FormulaEvents: public EventHandler
    {
         FormulaEvents* operator->() { return this;}
         EVENT_HANDLE(Formula,OnHonorCalculation)
         EVENT_HANDLE(Formula,OnGrayLevelCalculation)
         EVENT_HANDLE(Formula,OnColorCodeCalculation)
         EVENT_HANDLE(Formula,OnZeroDifferenceCalculation)
         EVENT_HANDLE(Formula,OnBaseGainCalculation)
         EVENT_HANDLE(Formula,OnGainCalculation)
         EVENT_HANDLE(Formula,OnGroupRateCalculation)
    } Formula;

    struct ItemEvents: public EventHandler
    {
         ItemEvents* operator->() { return this;}
         EVENT_HANDLE(Item,OnQuestAccept)
         //EVENT_HANDLE(Item,OnUse)
         EVENT_HANDLE(Item,OnExpire)
         EVENT_HANDLE(Item,OnRemove)
         EVENT_HANDLE(Item,OnCastItemCombatSpell)
    } Item;

    struct UnitEvents: public EventHandler
    {
         UnitEvents* operator->() { return this;}
         EVENT_HANDLE(Unit,OnHeal)
         EVENT_HANDLE(Unit,OnDamage)
         EVENT_HANDLE(Unit,ModifyPeriodicDamageAurasTick)
         EVENT_HANDLE(Unit,ModifyMeleeDamage)
         EVENT_HANDLE(Unit,ModifySpellDamageTaken)
         //EVENT_HANDLE(Unit,ModifyVehiclePassengerExitPos)
    } Unit;

    struct AreaTriggerEvents: public EventHandler
    {
         AreaTriggerEvents* operator->() { return this;}
         //EVENT_HANDLE(Area,TriggerOnTrigger)
    } AreaTrigger;

    struct WeatherEvents: public EventHandler
    {
         WeatherEvents* operator->() { return this;}
         //EVENT_HANDLE(Weather,OnChange)
    } Weather;

    struct AuctionEvents: public EventHandler
    {
         AuctionEvents* operator->() { return this;}
         //EVENT_HANDLE(AuctionHouse,OnAuctionAdd)
         //EVENT_HANDLE(AuctionHouse,OnAuctionRemove)
         //EVENT_HANDLE(AuctionHouse,OnAuctionSuccessful)
         //EVENT_HANDLE(AuctionHouse,OnAuctionExpire)
    } AuctionHouse;

    struct ConditionEvents: public EventHandler
    {
         ConditionEvents* operator->() { return this;}
         //EVENT_HANDLE(Condition,OnConditionCheck)
    } Condition;

    struct VehicleEvents: public EventHandler
    {
         VehicleEvents* operator->() { return this;}
         EVENT_HANDLE(Vehicle,OnInstall)
         EVENT_HANDLE(Vehicle,OnUninstall)
         EVENT_HANDLE(Vehicle,OnReset)
         EVENT_HANDLE(Vehicle,OnInstallAccessory)
         EVENT_HANDLE(Vehicle,OnAddPassenger)
         EVENT_HANDLE(Vehicle,OnRemovePassenger)
    } Vehicle;

    struct AchievementEvents: public EventHandler
    {
         AchievementEvents* operator->() { return this;}
         //EVENT_HANDLE(AchievementCriteria,OnCheck)
    } AchievementCriteria;

    struct PlayerEvents : public EventHandler
    {
         PlayerEvents* operator->() { return this;}
         EVENT_HANDLE(Player,OnPVPKill)
         EVENT_HANDLE(Player,OnCreatureKill)
         EVENT_HANDLE(Player,OnPlayerKilledByCreature)
         EVENT_HANDLE(Player,OnLevelChanged)
         EVENT_HANDLE(Player,OnFreeTalentPointsChanged)
         EVENT_HANDLE(Player,OnTalentsReset)
         EVENT_HANDLE(Player,OnMoneyChanged)
         EVENT_HANDLE(Player,OnMoneyLimit)
         EVENT_HANDLE(Player,OnGiveXP)
         EVENT_HANDLE(Player,OnReputationChange)
         EVENT_HANDLE(Player,OnDuelRequest)
         EVENT_HANDLE(Player,OnDuelStart)
         EVENT_HANDLE(Player,OnDuelEnd)
         EVENT_HANDLE(Player,OnSay)
         EVENT_HANDLE(Player,OnWhisper)
         EVENT_HANDLE(Player,OnChatGroup)
         EVENT_HANDLE(Player,OnChatGuild)
         //EVENT_HANDLE(Player,OnChat)
         EVENT_HANDLE(Player,OnEmote)
         EVENT_HANDLE(Player,OnTextEmote)
         EVENT_HANDLE(Player,OnSpellCast)
         EVENT_HANDLE(Player,OnLogin)
         EVENT_HANDLE(Player,OnLogout)
         EVENT_HANDLE(Player,OnCreate)
         EVENT_HANDLE(Player,OnDelete)
         EVENT_HANDLE(Player,OnFailedDelete)
         EVENT_HANDLE(Player,OnSave)
         EVENT_HANDLE(Player,OnBindToInstance)
         EVENT_HANDLE(Player,OnUpdateZone)
         EVENT_HANDLE(Player,OnMapChanged)
         EVENT_HANDLE(Player,OnQuestObjectiveProgress)
         EVENT_HANDLE(Player,OnQuestStatusChange)
         EVENT_HANDLE(Player,OnMovieComplete)
         EVENT_HANDLE(Player,OnPlayerRepop)
    } Player;

    struct AccountEvents : public EventHandler
    {
         AccountEvents* operator->() { return this;}
         EVENT_HANDLE(Account,OnAccountLogin)
         EVENT_HANDLE(Account,OnFailedAccountLogin)
         EVENT_HANDLE(Account,OnEmailChange)
         EVENT_HANDLE(Account,OnFailedEmailChange)
         EVENT_HANDLE(Account,OnPasswordChange)
         EVENT_HANDLE(Account,OnFailedPasswordChange)
    } Account;

    struct GuildEvents : public EventHandler
    {
         GuildEvents* operator->() { return this;}
         EVENT_HANDLE(Guild,OnAddMember)
         EVENT_HANDLE(Guild,OnRemoveMember)
         EVENT_HANDLE(Guild,OnMOTDChanged)
         EVENT_HANDLE(Guild,OnInfoChanged)
         EVENT_HANDLE(Guild,OnCreate)
         EVENT_HANDLE(Guild,OnDisband)
         EVENT_HANDLE(Guild,OnMemberWitdrawMoney)
         EVENT_HANDLE(Guild,OnMemberDepositMoney)
         EVENT_HANDLE(Guild,OnEvent)
         EVENT_HANDLE(Guild,OnBankEvent)
    } Guild;

    struct GroupEvents : public EventHandler
    {
         GroupEvents* operator->(){return this;}
         EVENT_HANDLE(Group,OnAddMember)
         EVENT_HANDLE(Group,OnInviteMember)
         EVENT_HANDLE(Group,OnRemoveMember)
         EVENT_HANDLE(Group,OnChangeLeader)
         EVENT_HANDLE(Group,OnDisband)
    } Group;

    void Unload()
    {
         Server.Unload();
         World.Unload();
         Formula.Unload();
         Item.Unload();
         Unit.Unload();
         AreaTrigger.Unload();
         Weather.Unload();
         AuctionHouse.Unload();
         Condition.Unload();
         Vehicle.Unload();
         AchievementCriteria.Unload();
         Player.Unload();
         Account.Unload();
         Guild.Unload();
         Group.Unload();
    }
};