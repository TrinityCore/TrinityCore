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

declare class TSMutable<T> {
    get() : T;
    set(value: T) : void;
}

declare class TSPosition {
    x: float;
    y: float;
    z: float;
    o: float;
    map: uint32;
}

interface Array<T> {
    get(index: number): T;
    set(index: number, value: T);
}

declare class TSMutableString extends TSMutable<string>{}

declare class TSPlayer extends TSUnit {
    IsNull() : bool
    CanTitanGrip() : bool
    HasTalent(spellId : uint32,spec : uint8) : bool
    HasAchieved(achievementId : uint32) : bool
    HasQuest(quest : uint32) : bool
    HasSkill(skill : uint32) : bool
    HasSpell(id : uint32) : bool
    HasAtLoginFlag(flag : uint32) : bool
    HasQuestForGO(entry : int32) : bool
    HasTitle(id : uint32) : bool
    HasItem(itemId : uint32,count : uint32,check_bank : bool) : bool
    HasQuestForItem(entry : uint32) : bool
    CanUseItem(item : TSItem,entry : uint32) : bool
    HasSpellCooldown(spellId : uint32) : bool
    CanShareQuest(entry : uint32) : bool
    CanSpeak() : bool
    CanUninviteFromGroup() : bool
    CanFly() : bool
    IsInWater() : bool
    IsMoving() : bool
    IsFlying() : bool
    IsInGroup() : bool
    IsInGuild() : bool
    IsGM() : bool
    IsInArenaTeam(type : uint32) : bool
    IsImmuneToDamage() : bool
    CanCompleteQuest(entry : uint32) : bool
    IsHorde() : bool
    IsAlliance() : bool
    IsDND() : bool
    IsAFK() : bool
    IsFalling() : bool
    IsGroupVisibleFor(target : TSPlayer) : bool
    IsInSameRaidWith(target : TSPlayer) : bool
    IsInSameGroupWith(target : TSPlayer) : bool
    IsHonorOrXPTarget(victim : TSUnit) : bool
    IsVisibleForPlayer(target : TSPlayer) : bool
    IsGMVisible() : bool
    IsTaxiCheater() : bool
    IsGMChat() : bool
    IsAcceptingWhispers() : bool
    IsRested() : bool
    InBattlegroundQueue() : bool
    InArena() : bool
    InBattleground() : bool
    CanBlock() : bool
    CanParry() : bool
    GetSpecsCount(entry : uint32,mapid : uint32,zone : uint32) : uint8
    GetActiveSpec() : uint32
    GetPhaseMaskForSpawn() : uint32
    GetArenaPoints() : uint32
    GetHonorPoints() : uint32
    GetShieldBlockValue() : uint32
    GetSpellCooldownDelay(spellId : uint32) : uint32
    GetLatency() : uint32
    GetChampioningFaction() : uint32
    GetOriginalSubGroup() : uint8
    GetOriginalGroup() : TSGroup
    GetNextRandomRaidMember(radius : float) : TSPlayer
    GetSubGroup() : uint8
    GetGroupInvite() : TSGroup
    GetXPRestBonus(xp : uint32) : uint32
    GetBattlegroundTypeId() : uint32
    GetBattlegroundId() : uint32
    GetReputationRank(faction : uint32) : uint32
    GetDrunkValue() : uint16
    GetSkillTempBonusValue(skill : uint32) : int16
    GetSkillPermBonusValue(skill : uint32) : int16
    GetPureSkillValue(skill : uint32) : uint16
    GetBaseSkillValue(skill : uint32) : uint16
    GetSkillValue(skill : uint32) : uint16
    GetPureMaxSkillValue(skill : uint32) : uint16
    GetMaxSkillValue(skill : uint32) : uint16
    GetManaBonusFromIntellect() : float
    GetHealthBonusFromStamina() : float
    GetDifficulty(isRaid : bool) : int32
    GetGuildRank() : uint32
    GetFreeTalentPoints() : uint32
    GetGuildName() : string
    GetReputation(faction : uint32) : int32
    GetComboTarget() : TSUnit
    GetComboPoints() : uint8
    GetInGameTime() : uint32
    GetQuestStatus(entry : uint32) : uint32
    GetQuestRewardStatus(questId : uint32) : bool
    GetReqKillOrCastCurrentCount(questId : uint32,entry : int32) : uint16
    GetQuestLevel(quest : TSQuest) : uint32
    GetEquippedItemBySlot(slot : uint8) : TSItem
    GetRestBonus() : float
    GetChatTag() : uint8
    GetItemByPos(bag : uint8,slot : uint8) : TSItem
    GetItemByGUID(guid : uint64) : TSItem
    GetItemByEntry(entry : uint32) : TSItem
    GetGossipTextId(obj : TSWorldObject) : uint32
    GetSelection() : TSUnit
    GetGMRank() : uint32
    GetMoney() : uint32
    GetGuildId() : uint32
    GetTeam() : uint32
    GetItemCount(entry : uint32,checkinBank : bool) : uint32
    GetLifetimeKills() : uint32
    GetPlayerIP() : string
    GetLevelPlayedTime() : uint32
    GetTotalPlayedTime() : uint32
    GetGuild() : TSGuild
    GetGroup() : TSGroup
    GetAccountId() : uint32
    GetAccountName() : string
    GetCorpse() : TSCorpse
    GetDbLocaleIndex() : int
    GetDbcLocale() : uint32
    SetPlayerLock(apply : bool) : void
    SetAtLoginFlag(flag : uint32) : void
    SetSheath(sheathed : uint32) : void
    SetDrunkValue(newDrunkValue : uint8) : void
    SetFactionForRace(race : uint8) : void
    SetSkill(id : uint16,step : uint16,currVal : uint16,maxVal : uint16) : void
    SetGuildRank(rank : uint8) : void
    SetFreeTalentPoints(points : uint32) : void
    SetReputation(faction : uint32,value : int32) : void
    SetQuestStatus(entry : uint32,status : uint32) : void
    SetRestBonus(bonus : float) : void
    SetAcceptWhispers(on : bool) : void
    SetPvPDeath(on : bool) : void
    SetGMVisible(on : bool) : void
    SetTaxiCheat(on : bool) : void
    SetGMChat(on : bool) : void
    SetGameMaster(on : bool) : void
    SetGender(_gender : uint32) : void
    SetArenaPoints(arenaP : uint32) : void
    SetHonorPoints(honorP : uint32) : void
    SetLifetimeKills(val : uint32) : void
    SetCoinage(amt : uint32) : void
    SetBindPoint(x : float,y : float,z : float,mapId : uint32,areaId : uint32) : void
    SetKnownTitle(id : uint32) : void
    ResetPetTalents(pType : int32) : void
    ResetAchievements() : void
    SendShowMailBox(guid : uint64) : void
    ModifyArenaPoints(amount : int32) : void
    ModifyHonorPoints(amount : int32) : void
    SaveToDB() : void
    SummonPlayer(summoner : TSUnit) : void
    Mute(muteseconds : uint32) : void
    RewardQuest(entry : uint32) : void
    SendAuctionMenu(unit : TSUnit) : void
    SendTaxiMenu(creature : TSCreature) : void
    SendSpiritResurrect() : void
    SendTabardVendorActivate(obj : TSWorldObject) : void
    SendShowBank(obj : TSWorldObject) : void
    SendListInventory(obj : TSWorldObject) : void
    SendTrainerList(obj : TSCreature) : void
    SendGuildInvite(plr : TSPlayer) : void
    LogoutPlayer(save : bool) : void
    RemoveFromBattlegroundRaid() : void
    UnbindInstance(map : uint32,difficulty : uint32) : void
    UnbindAllInstances() : void
    LeaveBattleground(teleToEntryPoint : bool) : void
    DurabilityRepair(position : uint16,cost : bool,discountMod : float,guildBank : bool) : uint32
    DurabilityRepairAll(cost : bool,discountMod : float,guildBank : bool) : uint32
    DurabilityPointLossForEquipSlot(slot : int32) : void
    DurabilityPointsLossAll(points : int32,inventory : bool) : void
    DurabilityPointsLoss(item : TSItem,points : int32) : void
    DurabilityLoss(item : TSItem,percent : double) : void
    DurabilityLossAll(percent : double,inventory : bool) : void
    KillPlayer() : void
    RemoveFromGroup() : void
    ResetTalentsCost() : uint32
    ResetTalents(no_cost : bool) : void
    RemoveSpell(entry : uint32,disabled : bool,learn_low_rank : bool) : void
    ClearComboPoints() : void
    AddComboPoints(target : TSUnit,count : int8) : void
    TalkedToCreature(entry : uint32,creature : TSCreature) : void
    KilledMonsterCredit(entry : uint32) : void
    GroupEventHappens(questId : uint32,obj : TSWorldObject) : void
    AreaExploredOrEventHappens(questId : uint32) : void
    FailQuest(entry : uint32) : void
    IncompleteQuest(entry : uint32) : void
    CompleteQuest(entry : uint32) : void
    //AddQuest(entry : uint32) : void
    RemoveQuest(entry : uint32) : void
    Whisper(text : string,lang : uint32,receiver : TSPlayer,guid : uint64) : void
    TextEmote(text : string) : void
    Yell(text : string,lang : uint32) : void
    Say(text : string,lang : uint32) : void
    GiveXP(xp : uint32,victim : TSUnit) : void
    ToggleDND() : void
    ToggleAFK() : void
    EquipItem(item : TSItem,slot : uint32,entry : uint32) : TSItem
    CanEquipItem(item : TSItem,slot : uint32,entry : uint32) : bool
    UnsetKnownTitle(id : uint32) : void
    AdvanceSkillsToMax() : void
    AdvanceAllSkills(step : uint32) : void
    AdvanceSkill(_skillId : uint32,_step : uint32) : void
    Teleport(mapId : uint32,x : float,y : float,z : float,o : float) : bool
    AddLifetimeKills(val : uint32) : void
    AddItem(itemId : uint32,itemCount : uint32) : TSItem
    RemoveItem(item : TSItem,itemCount : uint32,itemId : uint32) : void
    RemoveLifetimeKills(val : uint32) : void
    ResetSpellCooldown(spellId : uint32,update : bool) : void
    //ResetTypeCooldowns(category : uint32,update : bool) : void
    ResetAllCooldowns() : void
    SendBroadcastMessage(message : string) : void
    SendAreaTriggerMessage(msg : string) : void
    SendNotification(msg : string) : void
    SendPacketPlayer(data : TSWorldPacket,selfOnly : bool) : void
    SendAddonMessage(prefix : string,message : string,channel : uint8,receiver : TSPlayer) : void
    KickPlayer() : void
    ModifyMoney(amt : int32) : void
    LearnSpell(id : uint32) : void
    LearnTalent(id : uint32,rank : uint32) : void
    ResurrectPlayer(percent : float,sickness : bool) : void
    GossipMenuAddItem(_icon : uint32,msg : string,_sender : uint32,_intid : uint32,_code : bool,_promptMsg : string,_money : uint32) : void
    GossipComplete() : void
    GossipSendMenu(npc_text : uint32,sender : TSObject,menu_id : uint32) : void
    GossipClearMenu() : void
    StartTaxi(pathId : uint32) : void
    GossipSendPOI(x : float,y : float,icon : uint32,flags : uint32,data : uint32,iconText : string) : void
    GossipAddQuests(source : TSWorldObject) : void
    SendQuestTemplate(questId : uint32,activateAccept : bool) : void
    SpawnBones() : void
    RemovedInsignia(looter : TSPlayer) : void
    GroupInvite(invited : TSPlayer) : bool
    GroupCreate(invited : TSPlayer) : TSGroup
    SendCinematicStart(CinematicSequenceId : uint32) : void
    SendMovieStart(MovieId : uint32) : void    
}

declare class TSCorpse extends TSWorldObject {
    IsNull() : bool
    GetOwnerGUID() : uint64
    GetGhostTime() : uint32
    GetType() : uint32
    ResetGhostTime() : void
    SaveToDB() : void    
}

declare class TSCreature extends TSUnit {
    IsNull() : bool
    IsReputationGainDisabled() : bool
    CanCompleteQuest(quest_id : uint32) : bool
    IsTargetableForAttack(mustBeDead : bool) : bool
    CanAssistTo(u : TSUnit,enemy : TSUnit,checkfaction : bool) : bool
    HasSearchedAssistance() : bool
    IsTappedBy(player : TSPlayer) : bool
    HasLootRecipient() : bool
    CanAggro() : bool
    CanSwim() : bool
    CanWalk() : bool
    IsInEvadeMode() : bool
    IsElite() : bool
    IsGuard() : bool
    IsCivilian() : bool
    IsRacialLeader() : bool
    IsWorldBoss() : bool
    HasCategoryCooldown(spell : uint32) : bool
    HasSpell(id : uint32) : bool
    HasQuest(questId : uint32) : bool
    HasSpellCooldown(spellId : uint32) : bool
    CanFly() : bool
    IsTrigger() : bool
    IsDamageEnoughForLootingAndReward() : bool
    CanStartAttack(target : TSUnit,force : bool) : bool
    HasLootMode(lootMode : uint16) : bool
    GetRespawnDelay() : uint32
    GetWanderRadius() : float
    GetWaypointPath() : uint32
    GetCurrentWaypointId() : uint32
    GetDefaultMovementType() : uint32
    GetAggroRange(target : TSUnit) : float
    GetLootRecipientGroup() : TSGroup
    GetLootRecipient() : TSPlayer
    GetScriptName() : string
    GetAIName() : string
    GetScriptId() : uint32
    GetCreatureSpellCooldownDelay(spell : uint32) : uint32
    GetCorpseDelay() : uint32
    GetHomePosition() : float
    SetHomePosition(x : float,y : float,z : float,o : float) : void
    //GetAITarget(targetType : uint32,playerOnly : bool,position : uint32,dist : float,aura : int32) : TSUnit
    //GetAITargets() : TSArray<TSUnit>
    GetAITargetsCount() : int
    GetNPCFlags() : uint32
    GetShieldBlockValue() : uint32
    GetLootMode() : uint16
    GetDBTableGUIDLow() : uint32
    SetNPCFlags(flags : uint32) : void
    SetDisableGravity(disable : bool) : void
    SetLootMode(lootMode : uint16) : void
    SetDeathState(state : int32) : void
    SetWalk(enable : bool) : void
    SetEquipmentSlots(main_hand : uint32,off_hand : uint32,ranged : uint32) : void
    SetAggroEnabled(allow : bool) : void
    SetDisableReputationGain(disable : bool) : void
    SetInCombatWithZone() : void
    SetWanderRadius(dist : float) : void
    SetRespawnDelay(delay : uint32) : void
    SetDefaultMovementType(type : int32) : void
    SetNoSearchAssistance(val : bool) : void
    SetNoCallAssistance(val : bool) : void
    SetHover(enable : bool) : void
    DespawnOrUnsummon(msTimeToDespawn : uint32) : void
    Respawn() : void
    RemoveCorpse() : void
    MoveWaypoint() : void
    CallAssistance() : void
    CallForHelp(radius : float) : void
    FleeToGetAssistance() : void
    AttackStart(target : TSUnit) : void
    SaveToDB() : void
    SelectVictim() : TSUnit
    UpdateEntry(entry : uint32,dataGuidLow : uint32) : void
    ResetLootMode() : void
    RemoveLootMode(lootMode : uint16) : void
    AddLootMode(lootMode : uint16) : void
    GetCreatureFamily() : uint32    
}

declare class TSAura {
    IsNull() : bool
    GetCaster() : TSWorldObject
    GetCasterGUID() : uint64
    GetCasterLevel() : uint32
    GetDuration() : int32
    GetAuraId() : uint32
    GetMaxDuration() : int32
    GetStackAmount() : uint32
    GetOwner() : TSWorldObject
    SetDuration(duration : int32) : void
    SetMaxDuration(duration : int32) : void
    SetStackAmount(amount : uint8) : void
    Remove() : void    
}

declare class TSGuild {
    IsNull() : bool
    GetMembers() : TSArray<TSPlayer>
    GetMemberCount() : uint32
    GetLeader() : TSPlayer
    GetLeaderGUID() : uint64
    GetId() : uint32
    GetName() : string
    GetMOTD() : string
    GetInfo() : string
    SetLeader(player : TSPlayer) : void
    SetBankTabText(tabId : uint8,text : string) : void
    SendPacket(data : TSWorldPacket) : void
    SendPacketToRanked(data : TSWorldPacket,ranked : uint8) : void
    Disband() : void
    AddMember(player : TSPlayer,rankId : uint8) : void
    DeleteMember(player : TSPlayer,isDisbanding : bool) : void
    SetMemberRank(player : TSPlayer,newRank : uint8) : void    
}

declare class TSGroup {
    IsNull() : bool
    IsLeader(guid : uint64) : bool
    IsFull() : bool
    IsRaidGroup() : bool
    IsBGGroup() : bool
    IsMember(guid : uint64) : bool
    IsAssistant(guid : uint64) : bool
    SameSubGroup(player1 : TSPlayer,player2 : TSPlayer) : bool
    HasFreeSlotSubGroup(subGroup : uint8) : bool
    AddMember(player : TSPlayer) : bool
    GetMembers() : TSArray<TSPlayer>
    GetLeaderGUID() : uint64
    GetGUID() : uint64
    GetMemberGUID(name : string) : uint64
    GetMembersCount() : uint32
    GetMemberGroup(guid : uint64) : uint8
    SetLeader(guid : uint64) : void
    SendPacket(data : TSWorldPacket,ignorePlayersInBg : bool,ignore : uint64) : void
    RemoveMember(guid : uint64,method : uint32) : bool
    Disband() : void
    ConvertToRaid() : void
    SetMembersGroup(guid : uint64,subGroup : uint8) : void
    SetTargetIcon(icon : uint8,target : uint64,setter : uint64) : void    
}

declare class TSWorldPacket {
    IsNull() : bool
    GetOpcode() : uint16
    GetSize() : uint32
    SetOpcode(opcode : uint32) : void
    ReadByte() : int8
    ReadUByte() : uint8
    ReadShort() : int16
    ReadUShort() : uint16
    ReadLong() : int32
    ReadULong() : uint32
    ReadFloat() : float
    ReadDouble() : double
    ReadGUID() : uint64
    ReadString() : string
    WriteGUID(guid : uint64) : void
    WriteString(_val : string) : void
    WriteByte(byte : int8) : void
    WriteUByte(byte : uint8) : void
    WriteShort(_short : int16) : void
    WriteUShort(_ushort : uint16) : void
    WriteLong(_long : int32) : void
    WriteULong(_ulong : uint32) : void
    WriteFloat(_val : float) : void
    WriteDouble(_val : double) : void    
}

declare class TSQuest {
    IsNull() : bool
    HasFlag(flag : uint32) : bool
    IsDaily() : bool
    IsRepeatable() : bool
    GetId() : uint32
    GetLevel() : uint32
    GetMinLevel() : uint32
    GetNextQuestId() : int32
    GetPrevQuestId() : int32
    GetNextQuestInChain() : int32
    GetFlags() : uint32
    GetType() : uint32    
}

declare class TSMap {
    IsNull() : bool
    IsArena() : bool
    IsBattleground() : bool
    IsDungeon() : bool
    IsEmpty() : bool
    IsHeroic() : bool
    IsRaid() : bool
    GetName() : string
    GetHeight(x : float,y : float,phasemask : uint32) : float
    GetDifficulty() : int32
    GetInstanceId() : uint32
    GetPlayerCount() : uint32
    GetMapId() : uint32
    GetPlayers(team : uint32) : TSArray<TSPlayer>
    GetAreaId(x : float,y : float,z : float,phasemask : float) : uint32
    GetWorldObject(guid : uint64) : TSWorldObject
    SetWeather(zoneId : uint32,weatherType : uint32,grade : float) : void
}

declare class TSItem extends TSObject {
    IsNull() : bool
    IsSoulBound() : bool
    IsBoundAccountWide() : bool
    IsBoundByEnchant() : bool
    IsNotBoundToPlayer(player : TSPlayer) : bool
    IsLocked() : bool
    IsBag() : bool
    IsCurrencyToken() : bool
    IsNotEmptyBag() : bool
    IsBroken() : bool
    CanBeTraded(mail : bool) : bool
    IsInTrade() : bool
    IsInBag() : bool
    IsEquipped() : bool
    HasQuest(quest : uint32) : bool
    IsPotion() : bool
    IsWeaponVellum() : bool
    IsArmorVellum() : bool
    IsConjuredConsumable() : bool
    //GetItemLink(locale : uint8) : string
    GetOwnerGUID() : uint64
    GetOwner() : TSPlayer
    GetCount() : uint32
    GetMaxStackCount() : uint32
    GetSlot() : uint8
    GetBagSlot() : uint8
    GetEnchantmentId(enchant_slot : uint32) : uint32
    GetSpellId(index : uint32) : uint32
    GetSpellTrigger(index : uint32) : uint32
    GetClass() : uint32
    GetSubClass() : uint32
    GetName() : string
    GetDisplayId() : uint32
    GetQuality() : uint32
    GetBuyCount() : uint32
    GetBuyPrice() : uint32
    GetSellPrice() : uint32
    GetInventoryType() : uint32
    GetAllowableClass() : uint32
    GetAllowableRace() : uint32
    GetItemLevel() : uint32
    GetRequiredLevel() : uint32
    GetStatsCount() : uint32
    GetRandomProperty() : uint32
    GetRandomSuffix() : int32
    GetItemSet() : uint32
    GetBagSize() : uint32
    SetOwner(player : TSPlayer) : void
    SetBinding(soulbound : bool) : void
    SetCount(count : uint32) : void
    SetEnchantment(enchant : uint32,slot : uint32) : bool
    ClearEnchantment(slot : uint32) : bool
    SaveToDB() : void    
}

declare class TSBattleground {
    IsNull() : bool
    GetName() : string
    GetAlivePlayersCountByTeam(team : uint32) : uint32
    GetMap() : TSMap
    GetBonusHonorFromKillCount(kills : uint32) : uint32
    GetEndTime() : uint32
    GetFreeSlotsForTeam(team : uint32) : uint32
    GetInstanceId() : uint32
    GetMapId() : uint32
    GetTypeId() : uint32
    GetMaxLevel() : uint32
    GetMinLevel() : uint32
    GetMaxPlayers() : uint32
    GetMinPlayers() : uint32
    GetMaxPlayersPerTeam() : uint32
    GetMinPlayersPerTeam() : uint32
    GetWinner() : uint32
    GetStatus() : uint32    
}

declare class TSGameObject extends TSWorldObject {
    IsNull() : bool
    HasQuest(questId : uint32) : bool
    IsSpawned() : bool
    IsTransport() : bool
    IsActive() : bool
    GetDisplayId() : uint32
    GetGoState() : uint32
    GetLootState() : uint32
    GetLootRecipient() : TSPlayer
    GetLootRecipientGroup() : TSGroup
    GetDBTableGUIDLow() : uint32
    SetGoState(state : uint32) : void
    SetLootState(state : uint32) : void
    SaveToDB() : void
    RemoveFromWorld(deldb : bool) : void
    UseDoorOrButton(delay : uint32) : void
    Despawn() : void
    Respawn() : void
    SetRespawnTime(respawn : int32) : void    
}

declare class TSSpell {
    IsNull() : bool
    IsAutoRepeat() : bool
    GetCaster() : TSUnit
    GetCastTime() : int32
    GetEntry() : uint32
    GetPowerCost() : uint32
    GetDuration() : int32
    GetTargetDest() : TSPosition
    GetTarget() : TSObject
    SetAutoRepeat(repeat : bool) : void
    Cast(skipCheck : bool) : void
    Cancel() : void
    Finish() : void    
}

declare class TSVehicle {
    IsNull() : bool
    IsOnBoard(passenger : TSUnit) : bool
    GetOwner() : TSUnit
    GetEntry() : uint32
    GetPassenger(seatId : int8) : TSUnit
    AddPassenger(passenger : TSUnit,seatId : int8) : void
    RemovePassenger(passenger : TSUnit) : void    
}

declare class TSWorldObject extends TSObject {
    IsNull() : bool
    GetCreaturesInRange(range : float,entry : uint32,hostile : uint32,dead : uint32) : TSArray<TSCreature>
    GetPlayersInRange(range : float,hostile : uint32,dead : uint32) : TSArray<TSPlayer>
    GetNearObjects(range : float,type : uint16,entry : uint32,hostile : uint32,dead : uint32) : TSArray<TSWorldObject>
    GetGameObjectsInRange(range : float,entry : uint32,hostile : uint32) : TSArray<TSGameObject>
    GetName() : string
    GetMap() : TSMap
    GetPhaseMask() : uint32
    SetPhaseMask(phaseMask : uint32,update : bool) : void
    GetInstanceId() : uint32
    GetAreaId() : uint32
    GetZoneId() : uint32
    GetMapId() : uint32
    GetX() : float
    GetY() : float
    GetZ() : float
    GetO() : float
    GetLocation() : float
    GetNearestPlayer(range : float,hostile : uint32,dead : uint32) : TSPlayer
    GetNearestGameObject(range : float,entry : uint32,hostile : uint32) : TSGameObject
    GetNearestCreature(range : float,entry : uint32,hostile : uint32,dead : uint32) : TSCreature
    GetNearObject(range : float,type : uint16,entry : uint32,hostile : uint32,dead : uint32) : TSWorldObject
    GetDistance(target : TSWorldObject,X : float,Y : float,Z : float) : float
    GetDistance2d(target : TSWorldObject,X : float,Y : float) : float
    GetRelativePoint(dist : float,rad : float) : float
    SendPacket(data : TSWorldPacket) : void
    SummonGameObject(entry : uint32,x : float,y : float,z : float,o : float,respawnDelay : uint32) : TSGameObject
    SpawnCreature(entry : uint32,x : float,y : float,z : float,o : float,spawnType : uint32,despawnTimer : uint32) : TSCreature
    IsWithinLoS(target : TSWorldObject,x : float,y : float,z : float) : bool
    IsInMap(target : TSWorldObject) : bool
    IsWithinDist3d(x : float,y : float,z : float,dist : float) : bool
    IsWithinDist2d(x : float,y : float,dist : float) : bool
    IsWithinDist(target : TSWorldObject,distance : float,is3D : bool) : bool
    IsWithinDistInMap(target : TSWorldObject,distance : float,is3D : bool) : bool
    IsInRange(target : TSWorldObject,minrange : float,maxrange : float,is3D : bool) : bool
    IsInRange2d(x : float,y : float,minrange : float,maxrange : float) : bool
    IsInRange3d(x : float,y : float,z : float,minrange : float,maxrange : float) : bool
    IsInFront(target : TSWorldObject,arc : float) : bool
    IsInBack(target : TSWorldObject,arc : float) : bool
    PlayMusic(musicid : uint32,player : TSPlayer) : void
    PlayDirectSound(soundId : uint32,player : TSPlayer) : void
    PlayDistanceSound(soundId : uint32,player : TSPlayer) : void    
}

declare class TSObject {
    IsNull() : bool
    IsUnit() : bool
    IsCreature() : bool
    IsGameObject() : bool
    IsPlayer() : bool
    IsCorpse() : bool
    HasFlag(index : uint16,flag : uint32) : bool
    IsInWorld() : bool
    GetInt32Value(index : uint16) : int32
    GetUInt32Value(index : uint16) : uint32
    GetFloatValue(index : uint16) : float
    GetByteValue(index : uint16,offset : uint8) : uint8
    GetUInt16Value(index : uint16,offset : uint8) : uint16
    GetScale() : float
    GetEntry() : uint32
    GetGUID() : uint64
    GetGUIDLow() : uint32
    GetTypeId() : uint8
    GetUInt64Value(index : uint16) : uint64
    SetFlag(index : uint16,flag : uint32) : void
    SetInt32Value(index : uint16,value : int32) : void
    SetUInt32Value(index : uint16,value : uint32) : void
    UpdateUInt32Value(index : uint16,value : uint32) : void
    SetFloatValue(index : uint16,value : float) : void
    SetByteValue(index : uint16,offset : uint8,value : uint8) : void
    SetUInt16Value(index : uint16,offset : uint8,value : uint16) : void
    SetInt16Value(index : uint16,offset : uint8,value : int16) : void
    SetScale(size : float) : void
    SetUInt64Value(index : uint16,value : uint64) : void
    RemoveFlag(index : uint16,flag : uint32) : void
    ToCorpse() : TSCorpse
    ToGameObject() : TSGameObject
    ToUnit() : TSUnit
    ToCreature() : TSCreature
    ToPlayer() : TSPlayer    
}

declare class TSUnit extends TSWorldObject {
    IsNull() : bool
    Attack(who : TSUnit,meleeAttack : bool) : bool
    AttackStop() : bool
    IsStandState() : bool
    IsMounted() : bool
    IsRooted() : bool
    IsFullHealth() : bool
    IsInAccessiblePlaceFor(creature : TSCreature) : bool
    IsAuctioneer() : bool
    IsGuildMaster() : bool
    IsInnkeeper() : bool
    IsTrainer() : bool
    IsGossip() : bool
    IsTaxi() : bool
    IsSpiritHealer() : bool
    IsSpiritGuide() : bool
    IsTabardDesigner() : bool
    IsServiceProvider() : bool
    IsSpiritService() : bool
    IsAlive() : bool
    IsDead() : bool
    IsDying() : bool
    IsBanker() : bool
    IsVendor() : bool
    IsBattleMaster() : bool
    IsCharmed() : bool
    IsArmorer() : bool
    IsAttackingPlayer() : bool
    IsPvPFlagged() : bool
    IsOnVehicle() : bool
    IsInCombat() : bool
    IsUnderWater() : bool
    IsInWater() : bool
    IsStopped() : bool
    IsQuestGiver() : bool
    HealthBelowPct(pct : int32) : bool
    HealthAbovePct(pct : int32) : bool
    HasAura(spell : uint32) : bool
    IsCasting() : bool
    HasUnitState(state : uint32) : bool
    GetOwner() : TSUnit
    GetOwnerGUID() : uint64
    GetMountId() : uint32
    GetCreatorGUID() : uint64
    GetCharmerGUID() : uint64
    GetCharmGUID() : uint64
    GetPetGUID() : uint64
    GetControllerGUID() : uint64
    GetControllerGUIDS() : uint64
    GetStat(stat : uint32) : float
    GetBaseSpellPower(spellschool : uint32) : uint32
    GetVictim() : TSUnit
    GetCurrentSpell(type : uint32) : TSSpell
    GetStandState() : uint8
    GetDisplayId() : uint32
    GetNativeDisplayId() : uint32
    GetLevel() : uint8
    GetHealth() : uint32
    PowerSelectorHelper(unit : TSUnit,powerType : int) : uint32
    GetPower(type : int) : uint32
    GetMaxPower(type : int) : uint32
    GetPowerPct(type : int) : float
    GetPowerType() : uint32
    GetMaxHealth() : uint32
    GetHealthPct() : float
    GetGender() : uint8
    GetRace() : uint32
    GetClass() : uint32
    GetRaceMask() : uint32
    GetClassMask() : uint32
    GetCreatureType() : uint32
    GetClassAsString(locale : uint8) : string
    GetRaceAsString(locale : uint8) : string
    GetFaction() : uint32
    GetAura(spellID : uint32) : TSAura
    GetFriendlyUnitsInRange(range : float) : TSArray<TSUnit>
    GetUnfriendlyUnitsInRange(range : float) : TSArray<TSUnit>
    GetVehicleKit() : TSVehicle
    GetVehicle() : TSVehicle
    GetCritterGUID() : uint64
    GetSpeed(type : uint32) : float
    GetMovementType() : uint32
    SetOwnerGUID(guid : uint64) : void
    SetPvP(apply : bool) : void
    SetSheath(sheathed : uint32) : void
    SetName(name : string) : void
    SetSpeed(type : uint32,rate : float,forced : bool) : void
    SetFaction(factionId : uint32) : void
    SetLevel(newlevel : uint8) : void
    SetHealth(amt : uint32) : void
    SetMaxHealth(amt : uint32) : void
    SetPower(amt : uint32,type : int) : void
    ModifyPower(amt : int32,type : int) : void
    SetMaxPower(type : int,amt : uint32) : void
    SetPowerType(type : uint32) : void
    SetDisplayId(model : uint32) : void
    SetNativeDisplayId(model : uint32) : void
    SetFacing(o : float) : void
    SetFacingToObject(obj : TSWorldObject) : void
    SetCreatorGUID(guid : uint64) : void
    SetPetGUID(guid : uint64) : void
    SetWaterWalk(enable : bool) : void
    SetStandState(state : uint8) : void
    SetFFA(apply : bool) : void
    SetSanctuary(apply : bool) : void
    SetCritterGUID(guid : uint64) : void
    SetRooted(apply : bool) : void
    SetConfused(apply : bool) : void
    SetFeared(apply : bool) : void
    ClearThreatList(apply : bool,x : bool) : void
    Mount(displayId : uint32) : void
    Dismount() : void
    Emote(emoteId : uint32) : void
    EmoteState(emoteId : uint32) : void
    CountPctFromCurHealth(health : int32) : int32
    CountPctFromMaxHealth(health : int32) : int32
    SendChatMessageToPlayer(type : uint8,lang : uint32,msg : string,target : TSPlayer) : void
    PrepareMove() : void
    MoveStop() : void
    MoveExpire(reset : bool) : void
    MoveClear(reset : bool) : void
    MoveIdle() : void
    MoveRandom(radius : float) : void
    MoveHome() : void
    MoveFollow(target : TSUnit,dist : float,angle : float) : void
    MoveChase(target : TSUnit,dist : float,angle : float) : void
    MoveConfused() : void
    MoveFleeing(target : TSUnit,time : uint32) : void
    MoveTo(id : uint32,x : float,y : float,z : float,genPath : bool) : void
    MoveJump(x : float,y : float,z : float,zSpeed : float,maxHeight : float,id : uint32) : void
    SendUnitWhisper(msg : string,lang : uint32,receiver : TSPlayer,bossWhisper : bool) : void
    SendUnitEmote(msg : string,receiver : TSUnit,bossEmote : bool) : void
    SendUnitSay(msg : string,language : uint32) : void
    SendUnitYell(msg : string,language : uint32) : void
    DeMorph() : void
    CastSpell(target : TSUnit,spell : uint32,triggered : bool) : void
    CastCustomSpell(target : TSUnit,spell : uint32,triggered : bool,bp0 : int32,bp1 : int32,bp2 : int32,castItem : TSItem,originalCaster : uint64) : void
    CastSpellAoF(_x : float,_y : float,_z : float,spell : uint32,triggered : bool) : void
    ClearInCombat() : void
    StopSpellCast(spellId : uint32) : void
    InterruptSpell(spellType : int,delayed : bool) : void
    AddAura(spell : uint32,target : TSUnit) : TSAura
    RemoveAura(spellId : uint32) : void
    RemoveAllAuras() : void
    AddUnitState(state : uint32) : void
    ClearUnitState(state : uint32) : void
    NearTeleport(x : float,y : float,z : float,o : float) : void
    DealDamage(target : TSUnit,damage : uint32,durabilityloss : bool,school : uint32,spell : uint32) : void
    DealHeal(target : TSUnit,spell : uint32,amount : uint32,critical : bool) : void
    Kill(target : TSUnit,durLoss : bool) : void
    AddThreat(victim : TSUnit,threat : float,spell : uint32,schoolMask : uint32) : void    
}

declare class TSItemTemplate {
    IsNull() : bool
    Id() : uint32;
}

declare class TSSpellInfo {
    IsNull() : bool
    Id() : uint32;
}

declare class TSSpellCastTargets {
    IsNull() : bool
    GetUnit() : TSUnit;
}

declare namespace _hidden {
    export class World {
        OnOpenStateChange(callback: (open : bool)=>void);
        OnConfigLoad(callback: (reload : bool)=>void);
        OnMotdChange(callback: (newMotd : string)=>void);
        OnShutdownInitiate(callback: (code : uint32,mask : uint32)=>void);
        OnUpdate(callback: (diff : uint32)=>void);
    }

    export class Formula {
        OnHonorCalculation(callback: (honor : TSMutable<float>,level : uint8,multiplier : float)=>void);
        OnGrayLevelCalculation(callback: (grayLevel : TSMutable<uint8>,playerLevel : uint8)=>void);
        OnColorCodeCalculation(callback: (color : TSMutable<uint8>,playerLevel : uint8,mobLevel : uint8)=>void);
        OnZeroDifferenceCalculation(callback: (diff : TSMutable<uint8>,playerLevel : uint8)=>void);
        OnBaseGainCalculation(callback: (gain : TSMutable<uint32>,playerLevel : uint8,mobLevel : uint8,content : uint32)=>void);
        OnGainCalculation(callback: (gain : TSMutable<uint32>,player : TSPlayer,unit : TSUnit)=>void);
        OnGroupRateCalculation(callback: (rate : TSMutable<float>,count : uint32,isRaid : bool)=>void);
    }

    export class Item {
        OnQuestAccept(callback: (player : TSPlayer,item : TSItem,quest : TSQuest)=>void);
        // TODO: OnItemUse
        OnExpire(callback: (player : TSPlayer,proto : TSItemTemplate)=>void);
        OnRemove(callback: (player : TSPlayer,item : TSItem)=>void);
        OnCastItemCombatSpell(callback: (player : TSPlayer,victim : TSUnit,spellInfo : TSSpellInfo,item : TSItem)=>void);
    }

    export class Unit {
        OnHeal(callback: (healer : TSUnit,reciever : TSUnit,gain : TSMutable<uint32>)=>void);
        OnDamage(callback: (attacker : TSUnit,victim : TSUnit,damage : TSMutable<uint32>)=>void);
        ModifyPeriodicDamageAurasTick(callback: (target : TSUnit,attacker : TSUnit,damage : TSMutable<uint32>)=>void);
        ModifyMeleeDamage(callback: (target : TSUnit,attacker : TSUnit,damage : TSMutable<uint32>)=>void);
        ModifySpellDamageTaken(callback: (target : TSUnit,attacker : TSUnit,damage : TSMutable<int32>)=>void);
        //ModifyVehiclePassengerExitPos(callback: (passenger : TSUnit,vehicle : TSVehicle,pos : TSMutable<Position>)=>void);
    }

    export class AreaTrigger {
        OnTrigger(callback: (player : TSPlayer,id: uint32)=>void);
    }

    export class Vehicle {
        OnInstall(callback: (veh : TSVehicle)=>void);
        OnUninstall(callback: (veh : TSVehicle)=>void);
        OnReset(callback: (veh : TSVehicle)=>void);
        OnInstallAccessory(callback: (veh : TSVehicle,accessory : TSCreature)=>void);
        OnAddPassenger(callback: (veh : TSVehicle,passenger : TSUnit,seatId : int8)=>void);
        OnRemovePassenger(callback: (veh : TSVehicle,passenger : TSUnit)=>void);
    }

    export class AchievementCriteria {
        OnCheck(callback: (source : TSPlayer,target : TSUnit)=>void);
    }

    export class Player {
        OnPVPKill(callback: (killer : TSPlayer,killed : TSPlayer)=>void);
        OnCreatureKill(callback: (killer : TSPlayer,killed : TSCreature)=>void);
        OnPlayerKilledByCreature(callback: (killer : TSCreature,killed : TSPlayer)=>void);
        OnLevelChanged(callback: (player : TSPlayer,oldLevel : uint8)=>void);
        OnFreeTalentPointsChanged(callback: (player : TSPlayer,points : uint32)=>void);
        OnTalentsReset(callback: (player : TSPlayer,noCost : bool)=>void);
        OnMoneyChanged(callback: (player : TSPlayer,amount : TSMutable<int32>)=>void);
        OnMoneyLimit(callback: (player : TSPlayer,amount : int32)=>void);
        OnGiveXP(callback: (player : TSPlayer,amount : TSMutable<uint32>,victim : TSUnit)=>void);
        OnReputationChange(callback: (player : TSPlayer,factionId : uint32,standing : TSMutable<int32>,incremental : bool)=>void);
        OnDuelRequest(callback: (target : TSPlayer,challenger : TSPlayer)=>void);
        OnDuelStart(callback: (player1 : TSPlayer,player2 : TSPlayer)=>void);
        OnDuelEnd(callback: (winner : TSPlayer,loser : TSPlayer,type : uint32)=>void);
        OnSay(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : string)=>void);
        OnWhisper(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : string,receiver : TSPlayer)=>void);
        //OnPartyChat(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : string,group : TSGroup)=>void);
        //OnGuildChat(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : string,guild : TSGuild)=>void);
        // TODO: Fix chat to channel
        //OnChat(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : string,channel : Channel*)=>void),
        OnEmote(callback: (player : TSPlayer,emote : uint32)=>void);
        OnTextEmote(callback: (player : TSPlayer,textEmote : uint32,emoteNum : uint32,guid : uint64)=>void);
        OnSpellCast(callback: (player : TSPlayer,spell : TSSpell,skipCheck : bool)=>void);
        OnLogin(callback: (player : TSPlayer,firstLogin : bool)=>void);
        OnLogout(callback: (player : TSPlayer)=>void);
        OnCreate(callback: (player : TSPlayer)=>void);
        OnDelete(callback: (guid : uint64,accountId : uint32)=>void);
        OnFailedDelete(callback: (guid : uint64,accountId : uint32)=>void);
        OnSave(callback: (player : TSPlayer)=>void);
        OnBindToInstance(callback: (player : TSPlayer,difficulty : uint32,mapId : uint32,permanent : bool,extendState : uint8)=>void);
        OnUpdateZone(callback: (player : TSPlayer,newZone : uint32,newArea : uint32)=>void);
        OnMapChanged(callback: (player : TSPlayer)=>void);
        OnQuestObjectiveProgress(callback: (player : TSPlayer,quest : TSQuest,objectiveIndex : uint32,progress : uint16)=>void);
        OnQuestStatusChange(callback: (player : TSPlayer,questId : uint32)=>void);
        OnMovieComplete(callback: (player : TSPlayer,movieId : uint32)=>void);
        OnPlayerRepop(callback: (player : TSPlayer)=>void);
    }

    export class Account {
        OnAccountLogin(callback: (accountId : uint32)=>void);
        OnFailedAccountLogin(callback: (accountId : uint32)=>void);
        OnEmailChange(callback: (accountId : uint32)=>void);
        OnFailedEmailChange(callback: (accountId : uint32)=>void);
        OnPasswordChange(callback: (accountId : uint32)=>void);
        OnFailedPasswordChange(callback: (accountId : uint32)=>void);
    }

    export class Guild {
        OnAddMember(callback: (guild : TSGuild,player : TSPlayer,plRank : TSMutable<uint8>)=>void);
        OnRemoveMember(callback: (guild : TSGuild,player : TSPlayer,isDisbanding : bool,isKicked : bool)=>void);
        OnMOTDChanged(callback: (guild : TSGuild,newMotd : string)=>void);
        OnInfoChanged(callback: (guild : TSGuild,newInfo : string)=>void);
        OnCreate(callback: (guild : TSGuild,leader : TSPlayer,name : string)=>void);
        OnDisband(callback: (guild : TSGuild)=>void);
        OnMemberWitdrawMoney(callback: (guild : TSGuild,player : TSPlayer,amount : TSMutable<uint32>,isRepair : bool)=>void);
        OnMemberDepositMoney(callback: (guild : TSGuild,player : TSPlayer,amount : TSMutable<uint32>)=>void);
        OnEvent(callback: (guild : TSGuild,eventType : uint8,playerGuid1 : uint32,playerGuid2 : uint32,newRank : uint8)=>void);
        OnBankEvent(callback: (guild : TSGuild,eventType : uint8,tabId : uint8,playerGuid : uint32,itemOrMoney : uint32,itemStackCount : uint16,destTabId : uint8)=>void);
    }

    export class Group {
        OnAddMember(callback: (group : TSGroup,guid : uint64)=>void);
        OnInviteMember(callback: (group : TSGroup,guid : uint64)=>void);
        OnRemoveMember(callback: (group : TSGroup,guid : uint64,method : uint32,kicker : uint64,reason : string)=>void);
        OnChangeLeader(callback: (group : TSGroup,newLeaderGuid : uint64,oldLeaderGuid : uint64)=>void);
        OnDisband(callback: (group : TSGroup)=>void);
    }

    export class Spells {
        OnCast(spell: uint32, callback : (spell: TSSpell)=>void);
        OnDispel(spell: uint32, callback: (spell: TSSpell, dispelType: uint32)=>void);
        OnHit(spell: uint32, callback: (spell: TSSpell)=>void);
        OnTick(spell: uint32, callback: (caster: TSUnit, target: TSUnit)=>void);
    }
}

declare class TSEventHandlers {
    World: _hidden.World;
    Formula: _hidden.Formula;
    //Item: _hidden.Item;
    Unit: _hidden.Unit;
    //AreaTrigger: _hidden.AreaTrigger;
    //Vehicle: _hidden.Vehicle;
    //AchievementCriteria: _hidden.AchievementCriteria;
    Player: _hidden.Player;
    Account: _hidden.Account;
    Guild: _hidden.Guild;
    Group: _hidden.Group;
    Spells: _hidden.Spells;
}

declare class TSDictionary<K,V> {
    get(key: K) : V;
    set(key: K, value: V);
    contains(key: K): boolean;
    forEach(callback: (key: K, value: V)=>void);
    reduce<T>(callback: (previous: T,key: K, value: V)=>T, initial: T) : T;
    filter(callback: (key: K, value: V)=>boolean): TSDictionary<K,V>
}

declare function MakeDictionary<K,V>(obj: {[key: string]: V}) : TSDictionary<K,V>

declare function GetID(table: string, mod: string, name: string);
declare function GetIDRange(table: string, mod: string, name: string);