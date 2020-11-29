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

    struct : public EventHandler
    {
    } Server;

    struct : public EventHandler
    {
         EVENT_HANDLE(WorldOnOpenStateChange)
         EVENT_HANDLE(WorldOnConfigLoad)
         EVENT_HANDLE(WorldOnMotdChange)
         EVENT_HANDLE(WorldOnShutdownInitiate)
         EVENT_HANDLE(WorldOnUpdate)
    } World;

    struct : public EventHandler
    {
         EVENT_HANDLE(FormulaOnHonorCalculation)
         EVENT_HANDLE(FormulaOnGrayLevelCalculation)
         EVENT_HANDLE(FormulaOnColorCodeCalculation)
         EVENT_HANDLE(FormulaOnZeroDifferenceCalculation)
         EVENT_HANDLE(FormulaOnBaseGainCalculation)
         EVENT_HANDLE(FormulaOnGainCalculation)
         EVENT_HANDLE(FormulaOnGroupRateCalculation)
    } Formula;

    struct : public EventHandler
    {
         EVENT_HANDLE(ItemOnQuestAccept)
         //EVENT_HANDLE(ItemOnUse)
         EVENT_HANDLE(ItemOnExpire)
         EVENT_HANDLE(ItemOnRemove)
         EVENT_HANDLE(ItemOnCastItemCombatSpell)
    } Item;

    struct : public EventHandler
    {
         EVENT_HANDLE(UnitOnHeal)
         EVENT_HANDLE(UnitOnDamage)
         EVENT_HANDLE(UnitModifyPeriodicDamageAurasTick)
         EVENT_HANDLE(UnitModifyMeleeDamage)
         EVENT_HANDLE(UnitModifySpellDamageTaken)
         //EVENT_HANDLE(UnitModifyVehiclePassengerExitPos)
    } Unit;

    struct : public EventHandler
    {
         //EVENT_HANDLE(AreaTriggerOnTrigger)
    } AreaTrigger;

    struct : public EventHandler
    {
         //EVENT_HANDLE(WeatherOnChange)
    } Weather;

    struct : public EventHandler
    {
         //EVENT_HANDLE(AuctionHouseOnAuctionAdd)
         //EVENT_HANDLE(AuctionHouseOnAuctionRemove)
         //EVENT_HANDLE(AuctionHouseOnAuctionSuccessful)
         //EVENT_HANDLE(AuctionHouseOnAuctionExpire)
    } AuctionHouse;

    struct : public EventHandler
    {
         //EVENT_HANDLE(ConditionOnConditionCheck)
    } Condition;

    struct : public EventHandler
    {
         EVENT_HANDLE(VehicleOnInstall)
         EVENT_HANDLE(VehicleOnUninstall)
         EVENT_HANDLE(VehicleOnReset)
         EVENT_HANDLE(VehicleOnInstallAccessory)
         EVENT_HANDLE(VehicleOnAddPassenger)
         EVENT_HANDLE(VehicleOnRemovePassenger)
    } Vehicle;

    struct : public EventHandler
    {
         //EVENT_HANDLE(AchievementCriteriaOnCheck)
    } AchievementCriteria;

    struct : public EventHandler
    {
         EVENT_HANDLE(PlayerOnPVPKill)
         EVENT_HANDLE(PlayerOnCreatureKill)
         EVENT_HANDLE(PlayerOnPlayerKilledByCreature)
         EVENT_HANDLE(PlayerOnLevelChanged)
         EVENT_HANDLE(PlayerOnFreeTalentPointsChanged)
         EVENT_HANDLE(PlayerOnTalentsReset)
         EVENT_HANDLE(PlayerOnMoneyChanged)
         EVENT_HANDLE(PlayerOnMoneyLimit)
         EVENT_HANDLE(PlayerOnGiveXP)
         EVENT_HANDLE(PlayerOnReputationChange)
         EVENT_HANDLE(PlayerOnDuelRequest)
         EVENT_HANDLE(PlayerOnDuelStart)
         EVENT_HANDLE(PlayerOnDuelEnd)
         EVENT_HANDLE(PlayerOnSay)
         EVENT_HANDLE(PlayerOnWhisper)
         EVENT_HANDLE(PlayerOnChatGroup)
         EVENT_HANDLE(PlayerOnChatGuild)
         //EVENT_HANDLE(PlayerOnChat)
         EVENT_HANDLE(PlayerOnEmote)
         EVENT_HANDLE(PlayerOnTextEmote)
         EVENT_HANDLE(PlayerOnSpellCast)
         EVENT_HANDLE(PlayerOnLogin)
         EVENT_HANDLE(PlayerOnLogout)
         EVENT_HANDLE(PlayerOnCreate)
         EVENT_HANDLE(PlayerOnDelete)
         EVENT_HANDLE(PlayerOnFailedDelete)
         EVENT_HANDLE(PlayerOnSave)
         EVENT_HANDLE(PlayerOnBindToInstance)
         EVENT_HANDLE(PlayerOnUpdateZone)
         EVENT_HANDLE(PlayerOnMapChanged)
         EVENT_HANDLE(PlayerOnQuestObjectiveProgress)
         EVENT_HANDLE(PlayerOnQuestStatusChange)
         EVENT_HANDLE(PlayerOnMovieComplete)
         EVENT_HANDLE(PlayerOnPlayerRepop)
    } Player;

    struct : public EventHandler
    {
         EVENT_HANDLE(AccountOnAccountLogin)
         EVENT_HANDLE(AccountOnFailedAccountLogin)
         EVENT_HANDLE(AccountOnEmailChange)
         EVENT_HANDLE(AccountOnFailedEmailChange)
         EVENT_HANDLE(AccountOnPasswordChange)
         EVENT_HANDLE(AccountOnFailedPasswordChange)
    } Account;

    struct : public EventHandler
    {
         EVENT_HANDLE(GuildOnAddMember)
         EVENT_HANDLE(GuildOnRemoveMember)
         EVENT_HANDLE(GuildOnMOTDChanged)
         EVENT_HANDLE(GuildOnInfoChanged)
         EVENT_HANDLE(GuildOnCreate)
         EVENT_HANDLE(GuildOnDisband)
         EVENT_HANDLE(GuildOnMemberWitdrawMoney)
         EVENT_HANDLE(GuildOnMemberDepositMoney)
         EVENT_HANDLE(GuildOnEvent)
         EVENT_HANDLE(GuildOnBankEvent)
    } Guild;

    struct : public EventHandler
    {
         EVENT_HANDLE(GroupOnAddMember)
         EVENT_HANDLE(GroupOnInviteMember)
         EVENT_HANDLE(GroupOnRemoveMember)
         EVENT_HANDLE(GroupOnChangeLeader)
         EVENT_HANDLE(GroupOnDisband)
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