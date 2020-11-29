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
type int = number;
type float = number;
type double = number;
type long = number;
type int8 = number;
type uint8 = number;
type uint16 = number;
type int16 = number;
type uint32 = number;
type int32 = number;
type uint64 = number;
type int64 = number;
type bool = boolean;
type TSArray<T> = T[];

declare type EventHandler = {
    Server : {
    },

    World : {
        OnOpenStateChange(open : bool),
        OnConfigLoad(reload : bool),
        OnMotdChange(newMotd : string),
        OnShutdownInitiate(code : uint32,mask : ShutdownMask),
        OnUpdate(diff : uint32),
    },

    Formula : {
        OnHonorCalculation(honor : TSMutable<float>,level : uint8,multiplier : float),
        OnGrayLevelCalculation(grayLevel : TSMutable<uint8>,playerLevel : uint8),
        OnColorCodeCalculation(color : TSMutable<uint8>,playerLevel : uint8,mobLevel : uint8),
        OnZeroDifferenceCalculation(diff : TSMutable<uint8>,playerLevel : uint8),
        OnBaseGainCalculation(gain : TSMutable<uint32>,playerLevel : uint8,mobLevel : uint8,content : ContentLevels),
        OnGainCalculation(gain : TSMutable<uint32>,player : TSPlayer,unit : TSUnit),
        OnGroupRateCalculation(rate : TSMutable<float>,count : uint32,isRaid : bool),
    },

    Item : {
        OnQuestAccept(player : TSPlayer,item : TSItem,quest : TSQuest),
        // TODO: OnItemUse
        OnExpire(player : TSPlayer,proto : TSItemTemplate),
        OnRemove(player : TSPlayer,item : TSItem),
        OnCastItemCombatSpell(player : TSPlayer,victim : TSUnit,spellInfo : TSSpellInfo,item : TSItem),
    },

    Unit : {
        OnHeal(healer : TSUnit,reciever : TSUnit,gain : TSMutable<uint32>),
        OnDamage(attacker : TSUnit,victim : TSUnit,damage : TSMutable<uint32>),
        ModifyPeriodicDamageAurasTick(target : TSUnit,attacker : TSUnit,damage : TSMutable<uint32>),
        ModifyMeleeDamage(target : TSUnit,attacker : TSUnit,damage : TSMutable<uint32>),
        ModifySpellDamageTaken(target : TSUnit,attacker : TSUnit,damage : TSMutable<int32>),
        ModifyVehiclePassengerExitPos(passenger : TSUnit,vehicle : TSVehicle,pos : TSMutable<Position>),
    },

    AreaTrigger : {
        OnTrigger(player : TSPlayer,id: uint32),
    },

    Vehicle : {
        OnInstall(veh : TSVehicle),
        OnUninstall(veh : TSVehicle),
        OnReset(veh : TSVehicle),
        OnInstallAccessory(veh : TSVehicle,accessory : TSCreature),
        OnAddPassenger(veh : TSVehicle,passenger : TSUnit,seatId : int8),
        OnRemovePassenger(veh : TSVehicle,passenger : TSUnit),
    },

    AchievementCriteria : {
        OnCheck(source : TSPlayer,target : TSUnit),
    },

    Player : {
        OnPVPKill(killer : TSPlayer,killed : TSPlayer),
        OnCreatureKill(killer : TSPlayer,killed : TSCreature),
        OnPlayerKilledByCreature(killer : TSCreature,killed : TSPlayer),
        OnLevelChanged(player : TSPlayer,oldLevel : uint8),
        OnFreeTalentPointsChanged(player : TSPlayer,points : uint32),
        OnTalentsReset(player : TSPlayer,noCost : bool),
        OnMoneyChanged(player : TSPlayer,amount : TSMutable<int32>),
        OnMoneyLimit(player : TSPlayer,amount : int32),
        OnGiveXP(player : TSPlayer,amount : TSMutable<uint32>,victim : TSUnit),
        OnReputationChange(player : TSPlayer,factionId : uint32,standing : TSMutable<int32>,incremental : bool),
        OnDuelRequest(target : TSPlayer,challenger : TSPlayer),
        OnDuelStart(player1 : TSPlayer,player2 : TSPlayer),
        OnDuelEnd(winner : TSPlayer,loser : TSPlayer,type : DuelCompleteType),
        OnSay(player : TSPlayer,type : uint32,lang : uint32,msg : string),
        OnWhisper(player : TSPlayer,type : uint32,lang : uint32,msg : string,receiver : TSPlayer),
        OnPartyChat(player : TSPlayer,type : uint32,lang : uint32,msg : string,group : TSGroup),
        OnGuildChat(player : TSPlayer,type : uint32,lang : uint32,msg : string,guild : TSGuild),
        // TODO: Fix chat to channel
        //OnChat(player : TSPlayer,type : uint32,lang : uint32,msg : string,channel : Channel*),
        OnEmote(player : TSPlayer,emote : Emote),
        OnTextEmote(player : TSPlayer,textEmote : uint32,emoteNum : uint32,guid : uint64),
        OnSpellCast(player : TSPlayer,spell : TSSpell,skipCheck : bool),
        OnLogin(player : TSPlayer,firstLogin : bool),
        OnLogout(player : TSPlayer),
        OnCreate(player : TSPlayer),
        OnDelete(guid : uint64,accountId : uint32),
        OnFailedDelete(guid : uint64,accountId : uint32),
        OnSave(player : TSPlayer),
        OnBindToInstance(player : TSPlayer,difficulty : Difficulty,mapId : uint32,permanent : bool,extendState : uint8),
        OnUpdateZone(player : TSPlayer,newZone : uint32,newArea : uint32),
        OnMapChanged(player : TSPlayer),
        OnQuestObjectiveProgress(player : TSPlayer,quest : TSQuest,objectiveIndex : uint32,progress : uint16),
        OnQuestStatusChange(player : TSPlayer,questId : uint32),
        OnMovieComplete(player : TSPlayer,movieId : uint32),
        OnPlayerRepop(player : TSPlayer),
    },

    Account : {
        OnAccountLogin(accountId : uint32),
        OnFailedAccountLogin(accountId : uint32),
        OnEmailChange(accountId : uint32),
        OnFailedEmailChange(accountId : uint32),
        OnPasswordChange(accountId : uint32),
        OnFailedPasswordChange(accountId : uint32),
    },

    Guild : {
        OnAddMember(guild : TSGuild,player : TSPlayer,plRank : TSMutable<uint8>),
        OnRemoveMember(guild : TSGuild,player : TSPlayer,isDisbanding : bool,isKicked : bool),
        OnMOTDChanged(guild : TSGuild,newMotd : string),
        OnInfoChanged(guild : TSGuild,newInfo : string),
        OnCreate(guild : TSGuild,leader : TSPlayer,name : string),
        OnDisband(guild : TSGuild),
        OnMemberWitdrawMoney(guild : TSGuild,player : TSPlayer,amount : TSMutable<uint32>,isRepair : bool),
        OnMemberDepositMoney(guild : TSGuild,player : TSPlayer,amount : TSMutable<uint32>),
        OnEvent(guild : TSGuild,eventType : uint8,playerGuid1 : uint32,playerGuid2 : uint32,newRank : uint8),
        OnBankEvent(guild : TSGuild,eventType : uint8,tabId : uint8,playerGuid : uint32,itemOrMoney : uint32,itemStackCount : uint16,destTabId : uint8),
    },

    Group : {
        OnAddMember(group : TSGroup,guid : uint64),
        OnInviteMember(group : TSGroup,guid : uint64),
        OnRemoveMember(group : TSGroup,guid : uint64,method : uint32,kicker : uint64,reason : string),
        OnChangeLeader(group : TSGroup,newLeaderGuid : uint64,oldLeaderGuid : uint64),
        OnDisband(group : TSGroup),
    },
}
