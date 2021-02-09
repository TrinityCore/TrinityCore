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
type TSString = string;

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

declare class TSChatChannel {
    GetName(locale?: uint32) : string;
    GetID() : uint32;
    IsConstant(): bool;
    IsLFG(): bool;
    IsAnnounce(): bool;
    SetAnnounce(announce: bool): void;
    SetDirty();
    SetPassword(password: string): void;
    CheckPassword(password: string): bool;
    GetNumPlayers(): uint32;
    GetFlags(): uint8;
    HasFlag(flag: uint8): bool;
    JoinChannel(player: TSPlayer, send?: boolean): void;
    SetInvisible(player: TSPlayer, on: bool): void;
    SetOwner(guid: uint64, exclaim?: bool): void;
    Say(guid: uint64, what: string, lang: uint32): void;
}

declare class TSPlayer extends TSUnit {
    SendData(data: any)

    IsNull() : bool

    /**
     * Immediately sends a mail to this player
     * @param senderType 
     * @param from 
     * @param subject 
     * @param body 
     * @param money 
     * @param cod 
     * @param items 
     */
	SendMail(senderType: uint8, from: uint64, subject: string, body: string, money? : uint32, cod? : uint32, items? : TSArray<TSItem>);

    /**
     * Returns 'true' if the [Player] can Titan Grip, 'false' otherwise.
     *
     * @return bool canTitanGrip
     */
    CanTitanGrip() : bool

    /**
     * Returns 'true' if the [Player] has a talent by ID in specified spec, 'false' otherwise.
     *
     * @param uint32 spellId : talent spellId to check
     * @param uint8 spec : specified spec. 0 for primary, 1 for secondary.
     * @return bool hasTalent
     */
    HasTalent(spellId : uint32,spec : uint8) : bool

    /**
     * Returns 'true' if the [Player] has completed the specified achievement, 'false' otherwise.
     *
     * @param uint32 achievementId
     * @return bool hasAchieved
     */
    HasAchieved(achievementId : uint32) : bool

    /**
     * Returns 'true' if the [Player] has an active [Quest] by specific ID, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool hasQuest
     */
    HasQuest(quest : uint32) : bool

    /**
     * Returns 'true' if the [Player] has a skill by specific ID, 'false' otherwise.
     *
     * @param uint32 skill
     * @return bool hasSkill
     */
    HasSkill(skill : uint32) : bool

    /**
     * Returns 'true' if the [Player] has a [Spell] by specific ID, 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpell
     */
    HasSpell(id : uint32) : bool

    /**
     * Returns true if [Player] has specified login flag
     *
     * @param uint32 flag
     * @return bool hasLoginFlag
     */
    HasAtLoginFlag(flag : uint32) : bool

    /**
     * Returns true if [Player] has [Quest] for [GameObject]
     *
     * @param int32 entry : entry of a [GameObject]
     * @return bool hasQuest
     */
    HasQuestForGO(entry : int32) : bool

    /**
     * Returns 'true' if the [Player] has a title by specific ID, 'false' otherwise.
     *
     * @param uint32 titleId
     * @return bool hasTitle
     */
    HasTitle(id : uint32) : bool

    /**
     * Returns 'true' if the [Player] has the given amount of item entry specified, 'false' otherwise.
     *
     * @param uint32 itemId : entry of the item
     * @param uint32 count = 1 : amount of items the player needs should have
     * @param bool check_bank = false : determines if the item can be in player bank
     * @return bool hasItem
     */
    HasItem(itemId : uint32,count : uint32,check_bank : bool) : bool

    /**
     * Returns 'true' if the [Player] has a quest for the item entry specified, 'false' otherwise.
     *
     * @param uint32 entry : entry of the item
     * @return bool hasQuest
     */
    HasQuestForItem(entry : uint32) : bool

    /**
     * Returns 'true' if the [Player] can use the item or item entry specified, 'false' otherwise.
     *
     * @proto canUse = (item)
     * @proto canUse = (entry)
     * @param [Item] item : an instance of an item
     * @param uint32 entry : entry of the item
     * @return bool canUse
     */
    CanUseItem(item : TSItem,entry : uint32) : bool

    /**
     * Returns 'true' if the [Spell] specified by ID is currently on cooldown for the [Player], 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpellCooldown
     */
    HasSpellCooldown(spellId : uint32) : bool

    /**
     * Returns 'true' if the [Player] can share [Quest] specified by ID, 'false' otherwise.
     *
     * @param uint32 entryId
     * @return bool hasSpellCooldown
     */
    CanShareQuest(entry : uint32) : bool

    /**
     * Returns 'true' if the [Player] can currently communicate through chat, 'false' otherwise.
     *
     * @return bool canSpeak
     */
    CanSpeak() : bool

    /**
     * Returns 'true' if the [Player] has permission to uninvite others from the current group, 'false' otherwise.
     *
     * @return bool canUninviteFromGroup
     */
    CanUninviteFromGroup() : bool

    /**
     * Returns 'true' if the [Player] can fly, 'false' otherwise.
     *
     * @return bool canFly
     */
    CanFly() : bool

    /**
     * Returns 'true' if the [Player] is currently in water, 'false' otherwise.
     *
     * @return bool isInWater
     */
    IsInWater() : bool

    /**
     * Returns 'true' if the [Player] is currently moving, 'false' otherwise.
     *
     * @return bool isMoving
     */
    IsMoving() : bool

    /**
     * Returns 'true' if the [Player] is currently flying, 'false' otherwise.
     *
     * @return bool isFlying
     */
    IsFlying() : bool

    /**
     * Returns 'true' if the [Player] is in a [Group], 'false' otherwise.
     *
     * @return bool isInGroup
     */
    IsInGroup() : bool

    /**
     * Returns 'true' if the [Player] is in a [Guild], 'false' otherwise.
     *
     * @return bool isInGuild
     */
    IsInGuild() : bool

    /**
     * Returns 'true' if the [Player] is a Game Master, 'false' otherwise.
     *
     * Note: This is only true when GM tag is activated! For alternative see [Player:GetGMRank]
     *
     * @return bool isGM
     */
    IsGM() : bool

    /**
     * Returns 'true' if the [Player] is in an arena team specified by type, 'false' otherwise.
     *
     * @param uint32 type
     * @return bool isInArenaTeam
     */
    IsInArenaTeam(type : uint32) : bool

    /**
     * Returns 'true' if the [Player] is immune to everything.
     *
     * @return bool isImmune
     */
    IsImmuneToDamage() : bool

    /**
     * Returns 'true' if the [Player] satisfies all requirements to complete the quest entry.
     *
     * @param uint32 entry
     * @return bool canComplete
     */
    CanCompleteQuest(entry : uint32) : bool

    /**
     * Returns 'true' if the [Player] is a part of the Horde faction, 'false' otherwise.
     *
     * @return bool isHorde
     */
    IsHorde() : bool

    /**
     * Returns 'true' if the [Player] is a part of the Alliance faction, 'false' otherwise.
     *
     * @return bool isAlliance
     */
    IsAlliance() : bool

    /**
     * Returns 'true' if the [Player] is 'Do Not Disturb' flagged, 'false' otherwise.
     *
     * @return bool isDND
     */
    IsDND() : bool

    /**
     * Returns 'true' if the [Player] is 'Away From Keyboard' flagged, 'false' otherwise.
     *
     * @return bool isAFK
     */
    IsAFK() : bool

    /**
     * Returns 'true' if the [Player] is currently falling, 'false' otherwise.
     *
     * @return bool isFalling
     */
    IsFalling() : bool
    IsGroupVisibleFor(target : TSPlayer) : bool

    /**
     * Returns 'true' if the [Player] is currently in the same raid as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameRaidWith
     */
    IsInSameRaidWith(target : TSPlayer) : bool

    /**
     * Returns 'true' if the [Player] is currently in the same [Group] as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameGroupWith
     */
    IsInSameGroupWith(target : TSPlayer) : bool

    /**
     * Returns 'true' if the [Player] is eligible for Honor or XP gain by [Unit] specified, 'false' otherwise.
     *
     * @param [Unit] unit
     * @return bool isHonorOrXPTarget
     */
    IsHonorOrXPTarget(victim : TSUnit) : bool

    /**
     * Returns 'true' if the [Player] can see anoter [Player] specified by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isVisibleForPlayer
     */
    IsVisibleForPlayer(target : TSPlayer) : bool
    IsGMVisible() : bool

    /**
     * Returns 'true' if the [Player] has taxi cheat activated, 'false' otherwise.
     *
     * @return bool isTaxiCheater
     */
    IsTaxiCheater() : bool
    IsGMChat() : bool

    /**
     * Returns 'true' if the [Player] is accepting whispers, 'false' otherwise.
     *
     * @return bool isAcceptingWhispers
     */
    IsAcceptingWhispers() : bool

    /**
     * Returns 'true' if the [Player] is currently rested, 'false' otherwise.
     *
     * @return bool isRested
     */
    IsRested() : bool

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround] queue, 'false' otherwise.
     *
     * @return bool inBattlegroundQueue
     */
    InBattlegroundQueue() : bool

    /**
     * Returns 'true' if the [Player] is currently in an arena, 'false' otherwise.
     *
     * @return bool inArena
     */
    InArena() : bool

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround], 'false' otherwise.
     *
     * @return bool inBattleGround
     */
    InBattleground() : bool

    /**
     * Returns 'true' if the [Player] can block incomming attacks, 'false' otherwise.
     *
     * @return bool canBlock
     */
    CanBlock() : bool

    /**
     * Returns 'true' if the [Player] can parry incomming attacks, 'false' otherwise.
     *
     * @return bool canParry
     */
    CanParry() : bool

    /**
     * Returns the amount of available specs the [Player] currently has
     *
     * @return uint8 specCount
     */
    GetSpecsCount(entry : uint32,mapid : uint32,zone : uint32) : uint8

    /**
     * Returns the [Player]s active spec ID
     *
     * @return uint32 specId
     */
    GetActiveSpec() : uint32

    /**
     * Returns the normal phase of the player instead of the actual phase possibly containing GM phase
     *
     * @return uint32 phasemask
     */
    GetPhaseMaskForSpawn() : uint32

    /**
     * Returns the [Player]s current amount of Arena Points
     *
     * @return uint32 arenaPoints
     */
    GetArenaPoints() : uint32

    /**
     * Returns the [Player]s current amount of Honor Points
     *
     * @return uint32 honorPoints
     */
    GetHonorPoints() : uint32

    /**
     * Returns the [Player]s current shield block value
     *
     * @return uint32 blockValue
     */
    GetShieldBlockValue() : uint32

    /**
     * Returns the [Player]s cooldown delay by specified [Spell] ID
     *
     * @param uint32 spellId
     * @return uint32 spellCooldownDelay
     */
    GetSpellCooldownDelay(spellId : uint32) : uint32

    /**
     * Returns the [Player]s current latency in MS
     *
     * @return uint32 latency
     */
    GetLatency() : uint32

    /**
     * Returns the faction ID the [Player] is currently flagged as champion for
     *
     * @return uint32 championingFaction
     */
    GetChampioningFaction() : uint32

    /**
     * Returns [Player]s original sub group
     *
     * @return uint8 subGroup
     */
    GetOriginalSubGroup() : uint8

    /**
     * Returns [Player]s original [Group] object
     *
     * @return [Group] group
     */
    GetOriginalGroup() : TSGroup

    /**
     * Returns a random Raid Member [Player] object within radius specified of [Player]
     *
     * @param float radius
     * @return [Player] player
     */
    GetNextRandomRaidMember(radius : float) : TSPlayer

    /**
     * Returns [Player]s current sub group
     *
     * @return uint8 subGroup
     */
    GetSubGroup() : uint8

    /**
     * Returns [Group] invitation
     *
     * @return [Group] group
     */
    GetGroupInvite() : TSGroup

    /**
     * Returns rested experience bonus
     *
     * @param uint32 xp
     * @return uint32 xpBonus
     */
    GetXPRestBonus(xp : uint32) : uint32

    /**
     * Returns the [Player]s current [BattleGround] type ID
     *
     * @return [BattleGroundTypeId] typeId
     */
    GetBattlegroundTypeId() : uint32

    /**
     * Returns the [Player]s current [BattleGround] ID
     *
     * @return uint32 battleGroundId
     */
    GetBattlegroundId() : uint32

    /**
     * Returns the [Player]s reputation rank of faction specified
     *
     * @param uint32 faction
     * @return [ReputationRank] rank
     */
    GetReputationRank(faction : uint32) : uint32

    /**
     * Returns the [Player]s current level of intoxication
     *
     * @return uint16 drunkValue
     */
    GetDrunkValue() : uint16

    /**
     * Returns skill temporary bonus value
     *
     * @param uint32 skill
     * @param int16 bonusVal
     */
    GetSkillTempBonusValue(skill : uint32) : int16

    /**
     * Returns skill permanent bonus value
     *
     * @param uint32 skill
     * @param int16 bonusVal
     */
    GetSkillPermBonusValue(skill : uint32) : int16

    /**
     * Returns skill value without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    GetPureSkillValue(skill : uint32) : uint16

    /**
     * Returns base skill value
     *
     * @param uint32 skill
     * @return uint16 baseVal
     */
    GetBaseSkillValue(skill : uint32) : uint16

    /**
     * Returns skill value
     *
     * @param uint32 skill
     * @return uint16 val
     */
    GetSkillValue(skill : uint32) : uint16

    /**
     * Returns max value of specified skill without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    GetPureMaxSkillValue(skill : uint32) : uint16

    /**
     * Returns max value of specified skill
     *
     * @param uint32 skill
     * @return uint16 val
     */
    GetMaxSkillValue(skill : uint32) : uint16

    /**
     * Returns mana bonus from amount of intellect
     *
     * @return float bonus
     */
    GetManaBonusFromIntellect() : float

    /**
     * Returns health bonus from amount of stamina
     *
     * @return float bonus
     */
    GetHealthBonusFromStamina() : float

    /**
     * Returns raid or dungeon difficulty
     *
     * @param bool isRaid = true : argument is TrinityCore only
     * @return int32 difficulty
     */
    GetDifficulty(isRaid : bool) : int32

    /**
     * Returns the [Player]s current guild rank
     *
     * @return uint32 guildRank
     */
    GetGuildRank() : uint32

    /**
     * Returns the [Player]s free talent point amount
     *
     * @return uint32 freeTalentPointAmt
     */
    GetFreeTalentPoints() : uint32

    /**
     * Returns the name of the [Player]s current [Guild]
     *
     * @return string guildName
     */
    GetGuildName() : string

    /**
     * Returns the amount of reputation the [Player] has with the faction specified
     *
     * @param uint32 faction
     * @return int32 reputationAmt
     */
    GetReputation(faction : uint32) : int32

    /**
     * Returns [Unit] target combo points are on
     *
     * @return [Unit] target
     */
    GetComboTarget() : TSUnit

    /**
     * Returns [Player]'s combo points
     *
     * @return uint8 comboPoints
     */
    GetComboPoints() : uint8

    /**
     * Returns the amount of time the [Player] has spent ingame
     *
     * @return uint32 inGameTime
     */
    GetInGameTime() : uint32

    /**
     * Returns the status of the [Player]s [Quest] specified by entry ID
     *
     * @param uint32 questId
     * @return [QuestStatus] questStatus
     */
    GetQuestStatus(entry : uint32) : uint32

    /**
     * Returns 'true' if the [Player]s [Quest] specified by entry ID has been rewarded, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool questRewardStatus
     */
    GetQuestRewardStatus(questId : uint32) : bool

    /**
     * Returns [Quest] required [Creature] or [GameObject] count
     *
     * @param uint32 quest : entry of a quest
     * @param int32 entry : entry of required [Creature]
     * @return uint16 count
     */
    GetReqKillOrCastCurrentCount(questId : uint32,entry : int32) : uint16

    /**
     * Returns the quest level of the [Player]s [Quest] specified by object
     *
     * @param uint32 questId
     * @return [QuestStatus] questRewardStatus
     */
    GetQuestLevel(quest : TSQuest) : uint32

    /**
     * Returns a [Player]s [Item] object by gear slot specified
     *
     * @param uint8 slot
     * @return [Item] item
     */
    GetEquippedItemBySlot(slot : uint8) : TSItem

    /**
     * Returns the [Player]s current resting bonus
     *
     * @return float restBonus
     */
    GetRestBonus() : float

    /**
     * Returns active GM chat tag
     *
     * @return uint8 tag
     */
    GetChatTag() : uint8

    /**
     * Returns an item in given bag on given slot.
     *
     * <pre>
     * Possible and most commonly used combinations:
     *
     * bag = 255
     * slots 0-18 equipment
     * slots 19-22 equipped bag slots
     * slots 23-38 backpack
     * slots 39-66 bank main slots
     * slots 67-74 bank bag slots
     * slots 86-117 keyring
     *
     * bag = 19-22
     * slots 0-35 for equipped bags
     *
     * bag = 67-74
     * slots 0-35 for bank bags
     * </pre>
     *
     * @param uint8 bag : the bag the [Item] is in, you can get this with [Item:GetBagSlot]
     * @param uint8 slot : the slot the [Item] is in within the bag, you can get this with [Item:GetSlot]
     * @return [Item] item : [Item] or nil
     */
    GetItemByPos(bag : uint8,slot : uint8) : TSItem

    /**
     * Returns an [Item] from the player by guid.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param uint64 guid : an item guid
     * @return [Item] item
     */
    GetItemByGUID(guid : uint64) : TSItem

    /**
     * Returns an [Item] from the player by entry.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param uint32 entryId
     * @return [Item] item
     */
    GetItemByEntry(entry : uint32) : TSItem

    /**
     * Returns the database textID of the [WorldObject]'s gossip header text for the [Player]
     *
     * @return uint32 textId : key to npc_text database table
     */
    GetGossipTextId(obj : TSWorldObject) : uint32

    /**
     * Returns the [Player]s currently selected [Unit] object
     *
     * @return [Unit] unit
     */
    GetSelection() : TSUnit

    /**
     * Returns the [Player]s GM Rank
     *
     * @return [AccountTypes] gmRank
     */
    GetGMRank() : uint32

    /**
     * Returns the [Player]s amount of money in copper
     *
     * @return uint32 money
     */
    GetMoney() : uint32

    /**
     * Returns the [Player]s current [Guild] ID
     *
     * @return uint32 guildId
     */
    GetGuildId() : uint32

    /**
     * Returns the [Player]s [TeamId]
     *
     * @return [TeamId] teamId
     */
    GetTeam() : uint32

    /**
     * Returns amount of the specified [Item] the [Player] has.
     *
     * @param uint32 entry : entry of the item
     * @param bool checkinBank = false : also counts the items in player's bank if true
     * @return uint32 itemamount
     */
    GetItemCount(entry : uint32,checkinBank : bool) : uint32

    /**
     * Returns the [Player]s lifetime Honorable Kills
     *
     * @return uint32 lifeTimeKils
     */
    GetLifetimeKills() : uint32

    /**
     * Returns the [Player]s IP address
     *
     * @return string ip
     */
    GetPlayerIP() : string

    /**
     * Returns the [Player]s time played at current level
     *
     * @return uint32 currLevelPlayTime
     */
    GetLevelPlayedTime() : uint32

    /**
     * Returns the [Player]s total time played
     *
     * @return uint32 totalPlayTime
     */
    GetTotalPlayedTime() : uint32

    /**
     * Returns the [Player]s [Guild] object
     *
     * @return [Guild] guild
     */
    GetGuild() : TSGuild

    /**
     * Returns the [Player]s [Group] object
     *
     * @return [Group] group
     */
    GetGroup() : TSGroup

    /**
     * Returns the [Player]s account ID
     *
     * @return uint32 accountId
     */
    GetAccountId() : uint32

    /**
     * Returns the [Player]s account name
     *
     * @return string accountName
     */
    GetAccountName() : string

    /**
     * Returns the [Player]s [Corpse] object
     *
     * @return [Corpse] corpse
     */
    GetCorpse() : TSCorpse

    /**
     * Returns the [Player]s database locale index
     *
     * @return int localeIndex
     */
    GetDbLocaleIndex() : int

    /**
     * Returns the [Player]s game client locale
     *
     * @return [LocaleConstant] locale
     */
    GetDbcLocale() : uint32

    /**
     * Locks the player controls and disallows all movement and casting.
     *
     * @param bool apply = true : lock if true and unlock if false
     */
    SetPlayerLock(apply : bool) : void

    /**
     * Sets the [Player]s login flag to the flag specified
     *
     * @param uint32 flag
     */
    SetAtLoginFlag(flag : uint32) : void

    /**
     * Sets the [Player]s sheathe state to the state specified
     *
     * @param uint32 sheatheState
     */
    SetSheath(sheathed : uint32) : void

    /**
     * Sets the [Player]s intoxication level to the level specified
     *
     * @param uint8 drunkValue
     */
    SetDrunkValue(newDrunkValue : uint8) : void

    /**
     * Sets the [Player]s faction standing to that of the race specified
     *
     * @param uint8 raceId
     */
    SetFactionForRace(race : uint8) : void

    /**
     * Sets (increases) skill of the [Player]
     *
     * @param uint16 id
     * @param uint16 step
     * @param uint16 currVal
     * @param uint16 maxVal
     */
    SetSkill(id : uint16,step : uint16,currVal : uint16,maxVal : uint16) : void

    /**
     * Sets the [Player]s guild rank to the rank specified
     *
     * @param uint8 rank
     */
    SetGuildRank(rank : uint8) : void

    /**
     * Sets the [Player]s free talent points to the amount specified for the current spec
     *
     * @param uint32 talentPointAmt
     */
    SetFreeTalentPoints(points : uint32) : void

    /**
     * Sets the [Player]s reputation amount for the faction specified
     *
     * @param uint32 factionId
     * @param int32 reputationValue
     */
    SetReputation(faction : uint32,value : int32) : void

    /**
     * Sets [Quest] state
     *
     * @param uint32 entry : entry of a quest
     * @param uint32 status
     */
    SetQuestStatus(entry : uint32,status : uint32) : void

    /**
     * Sets the [Player]s rest bonus to the amount specified
     *
     * @param float restBonus
     */
    SetRestBonus(bonus : float) : void

    /**
     * Toggles whether the [Player] accepts whispers or not
     *
     * @param bool acceptWhispers = true
     */
    SetAcceptWhispers(on : bool) : void

    /**
     * Toggles PvP Death
     *
     * @param bool on = true
     */
    SetPvPDeath(on : bool) : void

    /**
     * Toggles whether the [Player] has GM visibility on or off
     *
     * @param bool gmVisible = true
     */
    SetGMVisible(on : bool) : void

    /**
     * Toggles whether the [Player] has taxi cheat enabled or not
     *
     * @param bool taxiCheat = true
     */
    SetTaxiCheat(on : bool) : void

    /**
     * Toggle Blizz (GM) tag
     *
     * @param bool on = true
     */
    SetGMChat(on : bool) : void

    /**
     * Toggles the [Player]s GM mode on or off
     *
     * @param bool setGmMode = true
     */
    SetGameMaster(on : bool) : void

    /**
     * Sets the [Player]s gender to gender specified
     *
     * - GENDER_MALE    = 0
     * - GENDER_FEMALE  = 1
     *
     * @param [Gender] gender
     */
    SetGender(_gender : uint32) : void

    /**
     * Sets the [Player]s Arena Points to the amount specified
     *
     * @param uint32 arenaPoints
     */
    SetArenaPoints(arenaP : uint32) : void

    /**
     * Sets the [Player]s Honor Points to the amount specified
     *
     * @param uint32 honorPoints
     */
    SetHonorPoints(honorP : uint32) : void

    /**
     * Sets the [Player]s amount of Lifetime Honorable Kills to the value specified
     *
     * @param uint32 honorableKills
     */
    SetLifetimeKills(val : uint32) : void

    /**
     * Sets the [Player]s amount of money to copper specified
     *
     * @param uint32 copperAmt
     */
    SetCoinage(amt : uint32) : void

    /**
     * Sets the [Player]s home location to the location specified
     *
     * @param float x : X Coordinate
     * @param float y : Y Coordinate
     * @param float z : Z Coordinate
     * @param uint32 mapId : Map ID
     * @param uint32 areaId : Area ID
     */
    SetBindPoint(x : float,y : float,z : float,mapId : uint32,areaId : uint32) : void

    /**
     * Adds the specified title to the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    SetKnownTitle(id : uint32) : void

    /**
     * Resets the [Player]s pets talent points
     */
    ResetPetTalents(pType : int32) : void

    /**
     * Reset the [Player]s completed achievements
     */
    ResetAchievements() : void

    /**
     * Shows the mailbox window to the player from specified guid.
     *
     * @param uint64 guid = playerguid : guid of the mailbox window sender
     */
    SendShowMailBox(guid : uint64) : void

    /**
     * Adds or detracts from the [Player]s current Arena Points
     *
     * @param int32 amount
     */
    ModifyArenaPoints(amount : int32) : void

    /**
     * Adds or detracts from the [Player]s current Honor Points
     *
     * @param int32 amount
     */
    ModifyHonorPoints(amount : int32) : void

    /**
     * Saves the [Player] to the database
     */
    SaveToDB() : void

    /**
     * Sends a summon request to the player from the given summoner
     *
     * @param [Unit] summoner
     */
    SummonPlayer(summoner : TSUnit) : void

    /**
     * Mutes the [Player] for the amount of seconds specified
     *
     * @param uint32 muteTime
     */
    Mute(muteseconds : uint32) : void

    /**
     * Rewards the given quest entry for the [Player] if he has completed it.
     *
     * @param uint32 entry : quest entry
     */
    RewardQuest(entry : uint32) : void

    /**
     * Sends an auction house window to the [Player] from the [Unit] specified
     *
     * @param [Unit] sender
     */
    SendAuctionMenu(unit : TSUnit) : void

    /**
     * Sends a flightmaster window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    SendTaxiMenu(creature : TSCreature) : void

    /**
     * Sends a spirit resurrection request to the [Player]
     */
    SendSpiritResurrect() : void

    /**
     * Sends a tabard vendor window to the [Player] from the [WorldObject] specified
     *
     * @param [WorldObject] sender
     */
    SendTabardVendorActivate(obj : TSWorldObject) : void

    /**
     * Sends a bank window to the [Player] from the [WorldObject] specified.
     *
     * @param [WorldObject] sender
     */
    SendShowBank(obj : TSWorldObject) : void

    /**
     * Sends a vendor window to the [Player] from the [WorldObject] specified.
     *
     * @param [WorldObject] sender
     */
    SendListInventory(obj : TSWorldObject) : void

    /**
     * Sends a trainer window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    SendTrainerList(obj : TSCreature) : void

    /**
     * Sends a guild invitation from the [Player]s [Guild] to the [Player] object specified
     *
     * @param [Player] invitee
     */
    SendGuildInvite(plr : TSPlayer) : void

    /**
     * Forces the [Player] to log out
     *
     * @param bool saveToDb = true
     */
    LogoutPlayer(save : bool) : void

    /**
     * Forcefully removes the [Player] from a [BattleGround] raid group
     */
    RemoveFromBattlegroundRaid() : void

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     *
     * Difficulty is not used on classic.
     *
     * @param uint32 map = true
     * @param uint32 difficulty = 0
     */
    UnbindInstance(map : uint32,difficulty : uint32) : void

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     */
    UnbindAllInstances() : void

    /**
     * Forces the [Player] to leave a [BattleGround]
     *
     * @param bool teleToEntry = true
     */
    LeaveBattleground(teleToEntryPoint : bool) : void

    /**
     * Repairs [Item] at specified position. Returns total repair cost 
     *
     * @param uint16 position
     * @param bool cost = true
     * @param float discountMod
     * @param bool guildBank = false
     * @return uint32 totalCost
     */
    DurabilityRepair(position : uint16,cost : bool,discountMod : float,guildBank : bool) : uint32

    /**
     * Repairs all [Item]s. Returns total repair cost
     *
     * @param bool cost = true
     * @param float discountMod = 1
     * @param bool guidBank = false
     * @return uint32 totalCost
     */
    DurabilityRepairAll(cost : bool,discountMod : float,guildBank : bool) : uint32

    /**
     * Sets durability loss for an [Item] in the specified slot
     *
     * @param int32 slot
     */
    DurabilityPointLossForEquipSlot(slot : int32) : void

    /**
     * Sets durability loss on all [Item]s equipped
     *
     * If inventory is true, sets durability loss for [Item]s in bags
     *
     * @param int32 points
     * @param bool inventory = true
     */
    DurabilityPointsLossAll(points : int32,inventory : bool) : void

    /**
     * Sets durability loss for the specified [Item]
     *
     * @param [Item] item
     * @param int32 points
     */
    DurabilityPointsLoss(item : TSItem,points : int32) : void

    /**
     * Damages specified [Item]
     *
     * @param [Item] item
     * @param double percent
     */
    DurabilityLoss(item : TSItem,percent : double) : void

    /**
     * Damages all [Item]s equipped. If inventory is true, damages [Item]s in bags
     *
     * @param double percent
     * @param bool inventory = true
     */
    DurabilityLossAll(percent : double,inventory : bool) : void

    /**
     * Kills the [Player]
     */
    KillPlayer() : void

    /**
     * Forces the [Player] to leave a [Group]
     */
    RemoveFromGroup() : void

    /**
     * Returns the [Player]s accumulated talent reset cost
     *
     * @return uint32 resetCost
     */
    ResetTalentsCost() : uint32

    /**
     * Resets the [Player]s talents
     *
     * @param bool noCost = true
     */
    ResetTalents(no_cost : bool) : void

    /**
     * Removes the [Spell] from the [Player]
     *
     * @param uint32 entry : entry of a [Spell]
     * @param bool disabled = false
     * @param bool learnLowRank = true
     */
    RemoveSpell(entry : uint32,disabled : bool,learn_low_rank : bool) : void

    /**
     * Clears the [Player]s combo points
     */
    ClearComboPoints() : void

    /**
     * Adds combo points to the [Player]
     *
     * @param [Unit] target
     * @param int8 count
     */
    AddComboPoints(target : TSUnit,count : int8) : void

    /**
     * Gives [Quest] monster talked to credit
     *
     * @param uint32 entry : entry of a [Creature]
     * @param [Creature] creature
     */
    TalkedToCreature(entry : uint32,creature : TSCreature) : void

    /**
     * Gives [Quest] monster killed credit
     *
     * @param uint32 entry : entry of a [Creature]
     */
    KilledMonsterCredit(entry : uint32) : void

    /**
     * Completes a [Quest] if in a [Group]
     *
     * @param uint32 quest : entry of a quest
     * @param [WorldObject] obj
     */
    GroupEventHappens(questId : uint32,obj : TSWorldObject) : void

    /**
     * Completes the [Quest] if a [Quest] area is explored, or completes the [Quest]
     *
     * @param uint32 quest : entry of a [Quest]
     */
    AreaExploredOrEventHappens(questId : uint32) : void

    /**
     * Sets the given [Quest] entry failed for the [Player].
     *
     * @param uint32 entry : entry of a [Quest]
     */
    FailQuest(entry : uint32) : void

    /**
     * Sets the given quest entry incomplete for the [Player].
     *
     * @param uint32 entry : quest entry
     */
    IncompleteQuest(entry : uint32) : void

    /**
     * Completes the given quest entry for the [Player] and tries to satisfy all quest requirements.
     *
     * The player should have the quest to complete it.
     *
     * @param uint32 entry : quest entry
     */
    CompleteQuest(entry : uint32) : void
    //AddQuest(entry : uint32) : void

    /**
     * Removes the given quest entry from the [Player].
     *
     * @param uint32 entry : quest entry
     */
    RemoveQuest(entry : uint32) : void

    /**
     * Sends whisper text from the [Player]
     *
     * @param string text
     * @param uint32 lang : language the [Player] will speak
     * @param [Player] receiver : is the [Player] that will receive the whisper, if TrinityCore
     * @param uint64 guid : is the GUID of a [Player] that will receive the whisper, not TrinityCore
     */
    Whisper(text : string,lang : uint32,receiver : TSPlayer,guid : uint64) : void

    /**
     * Sends a text emote from the [Player]
     *
     * @param string emoteText
     */
    TextEmote(text : string) : void

    /**
     * Sends yell text from the [Player]
     *
     * @param string text : text for the [Player] to yells
     * @param uint32 lang : language the [Player] will speak
     */
    Yell(text : string,lang : uint32) : void

    /**
     * Sends say text from the [Player]
     *
     * @param string text : text for the [Player] to say
     * @param uint32 lang : language the [Player] will speak
     */
    Say(text : string,lang : uint32) : void

    /**
     * Gives the [Player] experience
     *
     * @param uint32 xp : experience to give
     * @param [Unit] victim = nil
     */
    GiveXP(xp : uint32,victim : TSUnit) : void

    /**
     * Toggle the [Player]s 'Do Not Disturb' flag
     */
    ToggleDND() : void

    /**
     * Toggle the [Player]s 'Away From Keyboard' flag
     */
    ToggleAFK() : void

    /**
     * Equips the given item or item entry to the given slot. Returns the equipped item or nil.
     *
     *     enum EquipmentSlots // 19 slots
     *     {
     *         EQUIPMENT_SLOT_START        = 0,
     *         EQUIPMENT_SLOT_HEAD         = 0,
     *         EQUIPMENT_SLOT_NECK         = 1,
     *         EQUIPMENT_SLOT_SHOULDERS    = 2,
     *         EQUIPMENT_SLOT_BODY         = 3,
     *         EQUIPMENT_SLOT_CHEST        = 4,
     *         EQUIPMENT_SLOT_WAIST        = 5,
     *         EQUIPMENT_SLOT_LEGS         = 6,
     *         EQUIPMENT_SLOT_FEET         = 7,
     *         EQUIPMENT_SLOT_WRISTS       = 8,
     *         EQUIPMENT_SLOT_HANDS        = 9,
     *         EQUIPMENT_SLOT_FINGER1      = 10,
     *         EQUIPMENT_SLOT_FINGER2      = 11,
     *         EQUIPMENT_SLOT_TRINKET1     = 12,
     *         EQUIPMENT_SLOT_TRINKET2     = 13,
     *         EQUIPMENT_SLOT_BACK         = 14,
     *         EQUIPMENT_SLOT_MAINHAND     = 15,
     *         EQUIPMENT_SLOT_OFFHAND      = 16,
     *         EQUIPMENT_SLOT_RANGED       = 17,
     *         EQUIPMENT_SLOT_TABARD       = 18,
     *         EQUIPMENT_SLOT_END          = 19
     *
     *     enum InventorySlots // 4 slots
     *     {
     *         INVENTORY_SLOT_BAG_START    = 19,
     *         INVENTORY_SLOT_BAG_END      = 23
     *
     * @proto equippedItem = (item, slot)
     * @proto equippedItem = (entry, slot)
     * @param [Item] item : item to equip
     * @param uint32 entry : entry of the item to equip
     * @param uint32 slot : equipment slot to equip the item to The slot can be [EquipmentSlots] or [InventorySlots]
     * @return [Item] equippedItem : item or nil if equipping failed
     */
    EquipItem(item : TSItem,slot : uint32,entry : uint32) : TSItem

    /**
     * Returns true if the player can equip the given [Item] or item entry to the given slot, false otherwise.
     *
     * @proto canEquip = (item, slot)
     * @proto canEquip = (entry, slot)
     * @param [Item] item : item to equip
     * @param uint32 entry : entry of the item to equip
     * @param uint32 slot : equipment slot to test
     * @return bool canEquip
     */
    CanEquipItem(item : TSItem,slot : uint32,entry : uint32) : bool

    /**
     * Removes a title by ID from the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    UnsetKnownTitle(id : uint32) : void

    /**
     * Advances all of the [Player]s weapon skills to the maximum amount available
     */
    AdvanceSkillsToMax() : void

    /**
     * Advances all of the [Player]s skills to the amount specified
     *
     * @param uint32 skillStep
     */
    AdvanceAllSkills(step : uint32) : void

    /**
     * Advances a [Player]s specific skill to the amount specified
     *
     * @param uint32 skillId
     * @param uint32 skillStep
     */
    AdvanceSkill(_skillId : uint32,_step : uint32) : void

    /**
     * Teleports a [Player] to the location specified
     *
     * @param uint32 mappId
     * @param float xCoord
     * @param float yCoord
     * @param float zCoord
     * @param float orientation
     */
    Teleport(mapId : uint32,x : float,y : float,z : float,o : float) : bool
    AddLifetimeKills(val : uint32) : void

    /**
     * Adds the given amount of the specified item entry to the player.
     *
     * @param uint32 entry : entry of the item to add
     * @param uint32 itemCount = 1 : amount of the item to add
     * @return [Item] item : the item that was added or nil
     */
    AddItem(itemId : uint32,itemCount : uint32) : TSItem

    /**
     * Removes the given amount of the specified [Item] from the player.
     *
     * @proto (item, itemCount)
     * @proto (entry, itemCount)
     * @param [Item] item : item to remove
     * @param uint32 entry : entry of the item to remove
     * @param uint32 itemCount = 1 : amount of the item to remove
     */
    RemoveItem(item : TSItem,itemCount : uint32,itemId : uint32) : void

    /**
     * Removes specified amount of lifetime kills
     *
     * @param uint32 val : kills to remove
     */
    RemoveLifetimeKills(val : uint32) : void

    /**
     * Resets cooldown of the specified spell
     *
     * @param uint32 spellId
     * @param bool update = true
     */
    ResetSpellCooldown(spellId : uint32,update : bool) : void
    //ResetTypeCooldowns(category : uint32,update : bool) : void

    /**
     * Resets all of the [Player]'s cooldowns
     */
    ResetAllCooldowns() : void

    /**
     * Sends a Broadcast Message to the [Player]
     *
     * @param string message
     */
    SendBroadcastMessage(message : string) : void

    /**
     * Sends an Area Trigger Message to the [Player]
     *
     * @param string message
     */
    SendAreaTriggerMessage(msg : string) : void

    /**
     * Sends a Notification to the [Player]
     *
     * @param string message
     */
    SendNotification(msg : string) : void

    /**
     * Sends a [WorldPacket] to the [Player]
     *
     * @param [WorldPacket] packet
     * @param bool selfOnly = true
     */
    SendPacketPlayer(data : TSWorldPacket,selfOnly : bool) : void

    /**
     * Sends addon message to the [Player] receiver
     *
     * @param string prefix
     * @param string message
     * @param [ChatMsg] channel
     * @param [Player] receiver
     *
     */
    SendAddonMessage(prefix : string,message : string,channel : uint8,receiver : TSPlayer) : void

    /**
     * Kicks the [Player] from the server
     */
    KickPlayer() : void

    /**
     * Adds or subtracts from the [Player]s money in copper
     *
     * @param int32 copperAmt : negative to remove, positive to add
     */
    ModifyMoney(amt : int32) : void

    /**
     * Teaches the [Player] the [Spell] specified by entry ID
     *
     * @param uint32 spellId
     */
    LearnSpell(id : uint32) : void

    /**
     * Learn the [Player] the talent specified by talent_id and talentRank
     *
     * @param uint32 talent_id
     * @param uint32 talentRank
     */
    LearnTalent(id : uint32,rank : uint32) : void

    /**
     * Resurrects the [Player].
     *
     * @param float healthPercent = 100.0f
     * @param bool ressSickness = false
     */
    ResurrectPlayer(percent : float,sickness : bool) : void

    /**
     * Adds a new item to the gossip menu shown to the [Player] on next call to [Player:GossipSendMenu].
     *
     * sender and intid are numbers which are passed directly to the gossip selection handler. Internally they are partly used for the database gossip handling.  
     * code specifies whether to show a box to insert text to. The player inserted text is passed to the gossip selection handler.  
     * money specifies an amount of money the player needs to have to click the option. An error message is shown if the player doesn't have enough money.  
     * Note that the money amount is only checked client side and is not removed from the player either. You will need to check again in your code before taking action.
     *
     * See also: [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete], [Player:GossipClearMenu]
     *
     * @param uint32 icon : number that specifies used icon
     * @param string msg : label on the gossip item
     * @param uint32 sender : number passed to gossip handlers
     * @param uint32 intid : number passed to gossip handlers
     * @param bool code = false : show text input on click if true
     * @param string popup = nil : if non empty string, a popup with given text shown on click
     * @param uint32 money = 0 : required money in copper
     */
    GossipMenuAddItem(_icon : uint32,msg : string,_sender : uint32,_intid : uint32,_code : bool,_promptMsg : string,_money : uint32) : void

    /**
     * Closes the [Player]s currently open Gossip Menu.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipSendMenu], [Player:GossipClearMenu]
     */
    GossipComplete() : void

    /**
     * Sends the current gossip items of the player to him as a gossip menu with header text from the given textId.
     *
     * If sender is a [Player] then menu_id is mandatory, otherwise it is not used for anything.
     * menu_id is the ID used to trigger the OnGossipSelect registered for players. See [Global:RegisterPlayerGossipEvent]
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipComplete], [Player:GossipClearMenu]
     *
     * @proto (npc_text, sender)
     * @proto (npc_text, sender, menu_id)
     * @param uint32 npc_text : entry ID of a header text in npc_text database table, common default is 100
     * @param [Object] sender : object acting as the source of the sent gossip menu
     * @param uint32 menu_id : if sender is a [Player] then menu_id is mandatory
     */
    GossipSendMenu(npc_text : uint32,sender : TSObject,menu_id : uint32) : void

    /**
     * Clears the [Player]s current gossip item list.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete]
     * 
     *     Note: This is needed when you show a gossip menu without using gossip hello or select hooks which do this automatically.
     *     Usually this is needed when using [Player] is the sender of a Gossip Menu.
     */
    GossipClearMenu() : void

    /**
     * Attempts to start the taxi/flying to the given pathID
     *
     * @param uint32 pathId : pathId from DBC or [Global:AddTaxiPath]
     */
    StartTaxi(pathId : uint32) : void

    /**
     * Sends POI to the location on your map
     *
     * @param float x
     * @param float y
     * @param uint32 icon : map icon to show
     * @param uint32 flags
     * @param uint32 data
     * @param string iconText
     */
    GossipSendPOI(x : float,y : float,icon : uint32,flags : uint32,data : uint32,iconText : string) : void

    /**
     * Adds the gossip items to the [Player]'s gossip for the quests the given [WorldObject] can offer to the player.
     *
     * @param [WorldObject] source : a questgiver with quests
     */
    GossipAddQuests(source : TSWorldObject) : void

    /**
     * Shows a quest accepting window to the [Player] for the given quest.
     *
     * @param uint32 questId : entry of a quest
     * @param bool activateAccept = true : auto finish the quest
     */
    SendQuestTemplate(questId : uint32,activateAccept : bool) : void

    /**
     * Converts [Player]'s corpse to bones
     */
    SpawnBones() : void

    /**
     * Loots [Player]'s bones for insignia
     *
     * @param [Player] looter
     */
    RemovedInsignia(looter : TSPlayer) : void

    /**
     * Makes the [Player] invite another player to a group.
     *
     * @param [Player] invited : player to invite to group
     * @return bool success : true if the player was invited to a group
     */
    GroupInvite(invited : TSPlayer) : bool

    /**
     * Creates a new [Group] with the creator [Player] as leader.
     *
     * @param [Player] invited : player to add to group
     * @return [Group] createdGroup : the created group or nil
     */
    GroupCreate(invited : TSPlayer) : TSGroup

    /**
     * Starts a cinematic for the [Player]
     *
     * @param uint32 CinematicSequenceId : entry of a cinematic
     */
    SendCinematicStart(CinematicSequenceId : uint32) : void

    /**
     * Starts a movie for the [Player]
     *
     * @param uint32 MovieId : entry of a movie
     */
    SendMovieStart(MovieId : uint32) : void    
}

declare class TSCorpse extends TSWorldObject {
    IsNull() : bool

    GetLoot(): TSLoot;

    /**
     * Returns the GUID of the [Player] that left the [Corpse] behind.
     *
     * @return uint64 ownerGUID
     */
    GetOwnerGUID() : uint64

    /**
     * Returns the time when the [Player] became a ghost and spawned this [Corpse].
     *
     * @return uint32 ghostTime
     */
    GetGhostTime() : uint32

    /**
     * Returns the [CorpseType] of a [Corpse].
     *
     *     enum CorpseType
     *     {
     *         CORPSE_BONES             = 0,
     *         CORPSE_RESURRECTABLE_PVE = 1,
     *         CORPSE_RESURRECTABLE_PVP = 2
     *
     * @return [CorpseType] corpseType
     */
    GetType() : uint32

    /**
     * Sets the "ghost time" to the current time.
     *
     * See [Corpse:GetGhostTime].
     */
    ResetGhostTime() : void

    /**
     * Saves the [Corpse] to the database.
     */
    SaveToDB() : void    
}

declare class TSCreature extends TSUnit {
    GetLoot(): TSLoot;

    IsNull() : bool

    /**
     * Returns `true` if the [Creature] is set to not give reputation when killed,
     *   and returns `false` otherwise.
     *
     * @return bool reputationDisabled
     */
    IsReputationGainDisabled() : bool

    /**
     * Returns `true` if the [Creature] completes the [Quest] with the ID `questID`,
     *   and returns `false` otherwise.
     *
     * @param uint32 questID : the ID of a [Quest]
     * @return bool completesQuest
     */
    CanCompleteQuest(quest_id : uint32) : bool

    /**
     * Returns `true` if the [Creature] can be targeted for attack,
     *   and returns `false` otherwise.
     *
     * @param bool mustBeDead = false : if `true`, only returns `true` if the [Creature] is also dead. Otherwise, it must be alive.
     * @return bool targetable
     */
    IsTargetableForAttack(mustBeDead : bool) : bool

    /**
     * Returns `true` if the [Creature] can assist `friend` in combat against `enemy`,
     *   and returns `false` otherwise.
     *
     * @param [Unit] friend : the Unit we will be assisting
     * @param [Unit] enemy : the Unit that we would attack if we assist `friend`
     * @param bool checkFaction = true : if `true`, the [Creature] must be the same faction as `friend` to assist
     * @return bool canAssist
     */
    CanAssistTo(u : TSUnit,enemy : TSUnit,checkfaction : bool) : bool

    /**
     * Returns `true` if the [Creature] has searched for combat assistance already,
     *   and returns `false` otherwise.
     *
     * @return bool searchedForAssistance
     */
    HasSearchedAssistance() : bool

    /**
     * Returns `true` if the [Creature] will give its loot to `player`,
     *   and returns `false` otherwise.
     *
     * @return bool tapped
     */
    IsTappedBy(player : TSPlayer) : bool

    /**
     * Returns `true` if the [Creature] will give its loot to a [Player] or [Group],
     *   and returns `false` otherwise.
     *
     * @return bool hasLootRecipient
     */
    HasLootRecipient() : bool

    /**
     * Returns `true` if the [Creature] can start attacking nearby hostile [Unit]s,
     *   and returns `false` otherwise.
     *
     * @return bool canAggro
     */
    CanAggro() : bool

    /**
     * Returns `true` if the [Creature] can move through deep water,
     *   and returns `false` otherwise.
     *
     * @return bool canSwim
     */
    CanSwim() : bool

    /**
     * Returns `true` if the [Creature] can move on land,
     *   and returns `false` otherwise.
     *
     * @return bool canWalk
     */
    CanWalk() : bool

    /**
     * Returns `true` if the [Creature] is returning to its spawn position from combat,
     *   and returns `false` otherwise.
     *
     * @return bool inEvadeMode
     */
    IsInEvadeMode() : bool

    /**
     * Returns `true` if the [Creature]'s rank is Elite or Rare Elite,
     *   and returns `false` otherwise.
     *
     * @return bool isElite
     */
    IsElite() : bool

    /**
     * Returns `true` if the [Creature] is a city guard,
     *   and returns `false` otherwise.
     *
     * @return bool isGuard
     */
    IsGuard() : bool

    /**
     * Returns `true` if the [Creature] is a civilian,
     *   and returns `false` otherwise.
     *
     * @return bool isCivilian
     */
    IsCivilian() : bool

    /**
     * Returns `true` if the [Creature] is the leader of a player faction,
     *   and returns `false` otherwise.
     *
     * @return bool isLeader
     */
    IsRacialLeader() : bool

    /**
     * Returns `true` if the [Creature]'s rank is Boss,
     *   and returns `false` otherwise.
     *
     * @return bool isWorldBoss
     */
    IsWorldBoss() : bool

    /**
     * Returns `true` if the [Creature] cannot cast `spellId` due to a category cooldown,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasCooldown
     */
    HasCategoryCooldown(spell : uint32) : bool

    /**
     * Returns `true` if the [Creature] can cast `spellId` when mind-controlled,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasSpell
     */
    HasSpell(id : uint32) : bool

    /**
     * Returns `true` if the [Creature] starts the [Quest] `questId`,
     *   and returns `false` otherwise.
     *
     * @param uint32 questId : the ID of a [Quest]
     * @return bool hasQuest
     */
    HasQuest(questId : uint32) : bool

    /**
     * Returns `true` if the [Creature] has `spellId` on cooldown,
     *   and returns `false` otherwise.
     *
     * @param uint32 spellId : the ID of a [Spell]
     * @return bool hasCooldown
     */
    HasSpellCooldown(spellId : uint32) : bool

    /**
     * Returns `true` if the [Creature] can fly,
     *   and returns `false` otherwise.
     *
     * @return bool canFly
     */
    CanFly() : bool

    /**
     * Returns `true` if the [Creature] is an invisible trigger,
     *   and returns `false` otherwise.
     *
     * @return bool canFly
     */
    IsTrigger() : bool

    /**
     * Returns true if the [Creature] is damaged enough for looting
     *
     * @return bool isDamagedEnough
     */
    IsDamageEnoughForLootingAndReward() : bool

    /**
     * Returns true if the [Creature] can start attacking specified target
     *
     * Does not work on most targets
     *
     * @param [Unit] target
     * @param bool force = true : force [Creature] to attack
     */
    CanStartAttack(target : TSUnit,force : bool) : bool

    /**
     * Returns true if [Creature] has the specified loot mode
     *
     * @param uint16 lootMode
     * @return bool hasLootMode
     */
    HasLootMode(lootMode : uint16) : bool

    /**
     * Returns the time it takes for this [Creature] to respawn once killed.
     *
     * This value does not usually change over a [Creature]'s lifespan,
     *   but can be modified by [Creature:SetRespawnDelay].
     *
     * @return uint32 respawnDelay : the respawn delay, in seconds
     */
    GetRespawnDelay() : uint32

    /**
     * Returns the radius the [Creature] is permitted to wander from its
     *   respawn point.
     *
     * @return float wanderRadius
     */
    GetWanderRadius() : float

    /**
     * Returns the current waypoint path ID of the [Creature].
     *
     * @return uint32 pathId
     */
    GetWaypointPath() : uint32

    /**
     * Returns the current waypoint ID of the [Creature].
     *
     * @return uint32 wpId
     */
    GetCurrentWaypointId() : uint32

    /**
     * Returns the default movement type for this [Creature].
     *
     * @return [MovementGeneratorType] defaultMovementType
     */
    GetDefaultMovementType() : uint32

    /**
     * Returns the aggro range of the [Creature] for `target`.
     *
     * @param [Unit] target
     * @return float aggroRange
     */
    GetAggroRange(target : TSUnit) : float

    /**
     * Returns the [Group] that can loot this [Creature].
     *
     * @return [Group] lootRecipientGroup : the group or `nil`
     */
    GetLootRecipientGroup() : TSGroup

    /**
     * Returns the [Player] that can loot this [Creature].
     *
     * @return [Player] lootRecipient : the player or `nil`
     */
    GetLootRecipient() : TSPlayer

    /**
     * Returns the [Creature]'s script name.
     *
     * This is used by the core to apply C++ scripts to the Creature.
     *
     * It is not used by Eluna. Eluna will  AI scripts.
     *
     * @return string scriptName
     */
    GetScriptName() : string

    /**
     * Returns the [Creature]'s AI name.
     *
     * This is used by the core to assign the Creature's default AI.
     *
     * If the Creature is scripted by Eluna, the AI is n.
     *
     * @return string AIName
     */
    GetAIName() : string

    /**
     * Returns the [Creature]'s script ID.
     *
     * Every C++ script name is assigned a unique ID by the core.
     *   This returns the ID for this [Creature]'s script name.
     *
     * @return uint32 scriptID
     */
    GetScriptId() : uint32

    /**
     * Returns the [Creature]'s cooldown for `spellID`.
     *
     * @param uint32 spellID
     * @return uint32 cooldown : the cooldown, in milliseconds
     */
    GetCreatureSpellCooldownDelay(spell : uint32) : uint32

    /**
     * Returns the delay between when the [Creature] dies and when its body despawns.
     *
     * @return uint32 corpseDelay : the delay, in seconds
     */
    GetCorpseDelay() : uint32

    /**
     * Returns position the [Creature] returns to when evading from combat
     *   or respawning.
     *
     * @return float x
     * @return float y
     * @return float z
     * @return float o
     */
    GetHomePosition() : TSPosition

    /**
     * Sets the position the [Creature] returns to when evading from combat
     *   or respawning.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float o
     */
    SetHomePosition(x : float,y : float,z : float,o : float) : void
    //GetAITarget(targetType : uint32,playerOnly : bool,position : uint32,dist : float,aura : int32) : TSUnit
    //GetAITargets() : TSArray<TSUnit>

    /**
     * Returns the number of [Unit]s in this [Creature]'s threat list.
     *
     * @return int targetsCount
     */
    GetAITargetsCount() : int

    /**
     * Returns the [Creature]'s NPC flags.
     *
     * These are used to control whether the NPC is a vendor, can repair items,
     *   can give quests, etc.
     *
     * @return [NPCFlags] npcFlags
     */
    GetNPCFlags() : uint32

    /**
     * Returns the [Creature]'s shield block value.
     *
     * @return uint32 shieldBlockValue
     */
    GetShieldBlockValue() : uint32
    GetLootMode() : uint16

    /**
     * Returns the guid of the [Creature] that is used as the ID in the database
     *
     * @return uint32 dbguid
     */
    GetDBTableGUIDLow() : uint32

    /**
     * Sets the [Creature]'s NPC flags to `flags`.
     *
     * @param [NPCFlags] flags
     */
    SetNPCFlags(flags : uint32) : void

    /**
     * Makes the [Creature] able to fly if enabled.
     *
     * @param bool disable
     */
    SetDisableGravity(disable : bool) : void
    SetLootMode(lootMode : uint16) : void

    /**
     * Sets the [Creature]'s death state to `deathState`.
     *
     * @param [DeathState] deathState
     */
    SetDeathState(state : int32) : void

    /**
     * Sets whether the [Creature] is currently walking or running.
     *
     * @param bool enable = true : `true` to enable walking, `false` for running
     */
    SetWalk(enable : bool) : void

    /**
     * Equips given [Item]s to the [Unit]. Using 0 removes the equipped [Item]
     *
     * @param uint32 main_hand : main hand [Item]'s entry
     * @param uint32 off_hand : off hand [Item]'s entry
     * @param uint32 ranged : ranged [Item]'s entry
     */
    SetEquipmentSlots(main_hand : uint32,off_hand : uint32,ranged : uint32) : void

    /**
     * Sets whether the [Creature] can be aggroed.
     *
     * @param bool allow = true : `true` to allow aggro, `false` to disable aggro
     */
    SetAggroEnabled(allow : bool) : void

    /**
     * Sets whether the [Creature] gives reputation or not.
     *
     * @param bool disable = true : `true` to disable reputation, `false` to enable
     */
    SetDisableReputationGain(disable : bool) : void

    /**
     * Sets the [Creature] as in combat with all [Player]s in the dungeon instance.
     *
     * This is used by raid bosses to prevent Players from using out-of-combat
     *   actions once the encounter has begun.
     */
    SetInCombatWithZone() : void

    /**
     * Sets the distance the [Creature] can wander from it's spawn point.
     *
     * @param float distance
     */
    SetWanderRadius(dist : float) : void

    /**
     * Sets the time it takes for the [Creature] to respawn when killed.
     *
     * @param uint32 delay : the delay, in seconds
     */
    SetRespawnDelay(delay : uint32) : void

    /**
     * Sets the default movement type of the [Creature].
     *
     * @param [MovementGeneratorType] type
     */
    SetDefaultMovementType(type : int32) : void

    /**
     * Sets whether the [Creature] can search for assistance at low health or not.
     *
     * @param bool enable = true : `true` to disable searching, `false` to allow
     */
    SetNoSearchAssistance(val : bool) : void

    /**
     * Sets whether the [Creature] can call nearby enemies for help in combat or not.
     *
     * @param bool enable = true : `true` to disable calling for help, `false` to enable
     */
    SetNoCallAssistance(val : bool) : void

    /**
     * Sets whether the creature is hovering / levitating or not.
     *
     * @param bool enable = true : `true` to enable hovering, `false` to disable
     */
    SetHover(enable : bool) : void

    /**
     * Despawn this [Creature].
     *
     * @param uint32 delay = 0 : dely to despawn in milliseconds
     */
    DespawnOrUnsummon(msTimeToDespawn : uint32) : void

    /**
     * Respawn this [Creature].
     */
    Respawn() : void

    /**
     * Remove this [Creature]'s corpse.
     */
    RemoveCorpse() : void

    /**
     * Make the [Creature] start following its waypoint path.
     */
    MoveWaypoint() : void

    /**
     * Make the [Creature] call for assistance in combat from other nearby [Creature]s.
     */
    CallAssistance() : void

    /**
     * Make the [Creature] call for help in combat from friendly [Creature]s within `radius`.
     *
     * @param float radius
     */
    CallForHelp(radius : float) : void

    /**
     * Make the [Creature] flee combat to get assistance from a nearby friendly [Creature].
     */
    FleeToGetAssistance() : void

    /**
     * Make the [Creature] attack `target`.
     *
     * @param [Unit] target
     */
    AttackStart(target : TSUnit) : void

    /**
     * Save the [Creature] in the database.
     */
    SaveToDB() : void

    /**
     * Make the [Creature] try to find a new target.
     *
     * This should be called every update cycle for the Creature's AI.
     */
    SelectVictim() : TSUnit

    /**
     * Transform the [Creature] into another Creature.
     *
     * @param uint32 entry : the Creature ID to transform into
     * @param uint32 dataGUIDLow = 0 : use this Creature's model and equipment instead of the defaults
     */
    UpdateEntry(entry : uint32,dataGuidLow : uint32) : void

    /**
     * Resets [Creature]'s loot mode to default
     */
    ResetLootMode() : void

    /**
     * Removes specified loot mode from [Creature]
     *
     * @param uint16 lootMode
     */
    RemoveLootMode(lootMode : uint16) : void

    /**
     * Adds a loot mode to the [Creature]
     *
     * @param uint16 lootMode
     */
    AddLootMode(lootMode : uint16) : void

    /**
     * Returns the [Creature]'s creature family ID (enumerated in CreatureFamily.dbc).
     *
     *     enum CreatureFamily
     *     {
     *         CREATURE_FAMILY_NONE                = 0,    // TrinityCore only
     *         CREATURE_FAMILY_WOLF                = 1,
     *         CREATURE_FAMILY_CAT                 = 2,
     *         CREATURE_FAMILY_SPIDER              = 3,
     *         CREATURE_FAMILY_BEAR                = 4,
     *         CREATURE_FAMILY_BOAR                = 5,
     *         CREATURE_FAMILY_CROCOLISK           = 6,
     *         CREATURE_FAMILY_CARRION_BIRD        = 7,
     *         CREATURE_FAMILY_CRAB                = 8,
     *         CREATURE_FAMILY_GORILLA             = 9,
     *         CREATURE_FAMILY_HORSE_CUSTOM        = 10,   // Does not exist in DBC but used for horse like beasts in DB
     *         CREATURE_FAMILY_RAPTOR              = 11,
     *         CREATURE_FAMILY_TALLSTRIDER         = 12,
     *         CREATURE_FAMILY_FELHUNTER           = 15,
     *         CREATURE_FAMILY_VOIDWALKER          = 16,
     *         CREATURE_FAMILY_SUCCUBUS            = 17,
     *         CREATURE_FAMILY_DOOMGUARD           = 19,
     *         CREATURE_FAMILY_SCORPID             = 20,
     *         CREATURE_FAMILY_TURTLE              = 21,
     *         CREATURE_FAMILY_IMP                 = 23,
     *         CREATURE_FAMILY_BAT                 = 24,
     *         CREATURE_FAMILY_HYENA               = 25,
     *         CREATURE_FAMILY_BIRD_OF_PREY        = 26,   // Named CREATURE_FAMILY_OWL in Mangos
     *         CREATURE_FAMILY_WIND_SERPENT        = 27,
     *         CREATURE_FAMILY_REMOTE_CONTROL      = 28,
     *         CREATURE_FAMILY_FELGUARD            = 29,   // This and below is TBC+
     *         CREATURE_FAMILY_DRAGONHAWK          = 30,
     *         CREATURE_FAMILY_RAVAGER             = 31,
     *         CREATURE_FAMILY_WARP_STALKER        = 32,
     *         CREATURE_FAMILY_SPOREBAT            = 33,
     *         CREATURE_FAMILY_NETHER_RAY          = 34,
     *         CREATURE_FAMILY_SERPENT             = 35,
     *         CREATURE_FAMILY_SEA_LION            = 36,   // TBC only
     *         CREATURE_FAMILY_MOTH                = 37,   // This and below is WotLK+
     *         CREATURE_FAMILY_CHIMAERA            = 38,
     *         CREATURE_FAMILY_DEVILSAUR           = 39,
     *         CREATURE_FAMILY_GHOUL               = 40,
     *         CREATURE_FAMILY_SILITHID            = 41,
     *         CREATURE_FAMILY_WORM                = 42,
     *         CREATURE_FAMILY_RHINO               = 43,
     *         CREATURE_FAMILY_WASP                = 44,
     *         CREATURE_FAMILY_CORE_HOUND          = 45,
     *         CREATURE_FAMILY_SPIRIT_BEAST        = 46
     *     }
     * @return [CreatureFamily] creatureFamily
     */
    GetCreatureFamily() : uint32    
}

declare class TSAura {
    IsNull() : bool

    /**
     * Returns all active applications of this aura.
     * 
     * @return [TSAuraApplication[]] applications
     */
    GetApplications(): TSArray<TSAuraApplication>

    /**
     * Returns the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return [Unit] caster
     */
    GetCaster() : TSWorldObject

    /**
     * Returns the GUID of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return string caster_guid : the GUID of the Unit as a decimal string
     */
    GetCasterGUID() : uint64

    /**
     * Returns the level of the [Unit] that casted the [Spell] that caused this [Aura] to be applied.
     *
     * @return uint32 caster_level
     */
    GetCasterLevel() : uint32

    /**
     * Returns the amount of time left until the [Aura] expires.
     *
     * @return int32 duration : amount of time left in milliseconds
     */
    GetDuration() : int32

    /**
     * Returns the ID of the [Spell] that caused this [Aura] to be applied.
     *
     * @return uint32 aura_id
     */
    GetAuraId() : uint32

    /**
     * Returns the amount of time this [Aura] lasts when applied.
     *
     * To determine how much time has passed since this Aura was applied,
     *   subtract the result of [Aura]:GetDuration from the result of this method.
     *
     * @return int32 max_duration : the maximum duration of the Aura, in milliseconds
     */
    GetMaxDuration() : int32

    /**
     * Returns the number of times the [Aura] has "stacked".
     *
     * This is the same as the number displayed on the [Aura]'s icon in-game.
     *
     * @return uint32 stack_amount
     */
    GetStackAmount() : uint32

    /**
     * Returns the [Unit] that the [Aura] has been applied to.
     *
     * @return [Unit] owner
     */
    GetOwner() : TSWorldObject

    /**
     * Change the amount of time before the [Aura] expires.
     *
     * @param int32 duration : the new duration of the Aura, in milliseconds
     */
    SetDuration(duration : int32) : void

    /**
     * Change the maximum amount of time before the [Aura] expires.
     *
     * This does not affect the current duration of the [Aura], but if the [Aura]
     *   is reset to the maximum duration, it will instead change to `duration`.
     *
     * @param int32 duration : the new maximum duration of the Aura, in milliseconds
     */
    SetMaxDuration(duration : int32) : void

    /**
     * Change the amount of times the [Aura] has "stacked" on the [Unit].
     *
     * If `amount` is greater than or equal to the current number of stacks,
     *   then the [Aura] has its duration reset to the maximum duration.
     *
     * @param uint32 amount
     */
    SetStackAmount(amount : uint8) : void

    /**
     * Remove this [Aura] from the [Unit] it is applied to.
     */
    Remove() : void    
}

declare class TSAuraEffect {
    GetCaster(): TSUnit;
    GetCasterGUID(): uint64;
    GetAura(): TSAura;
    GetSpellInfo(): TSSpellInfo;
    GetID(): uint32;
    GetEffectIndex(): uint32;
    GetAmplitude(): uint32;
    GetMiscValueB(): int32;
    GetMiscValue(): int32;
    GetAuraType(): uint32;
    GetAmount(): int32;
    SetAmount(amount: int32): void;
    GetPeriodicTimer(): int32;
    SetPeriodicTimer(periodicTimer: int32): void;
    GetTickNumber(): uint32;
    GetRemainingTicks(): uint32;
    GetTotalTicks(): uint32;
    ResetPeriodic(): void;
    ResetTicks(): void;
    IsPeriodic(): boolean;
}

declare class TSAuraApplication {
    GetTarget(): TSUnit;
    GetAura(): TSAura;
    GetSlot(): uint8;
    GetFlags(): uint8;
    GetEffectMask(): uint8;
    GetAppliedEffects(): uint8;
    IsPositive(): bool;
    IsSelfCast(): bool;
}

declare class TSGuild {
    IsNull() : bool

    /**
     * Returns a table with the [Player]s in this [Guild]
     *
     * Only the players that are online and on some map.
     *
     * @return table guildPlayers : table of [Player]s
     */
    GetMembers() : TSArray<TSPlayer>

    /**
     * Returns the member count of this [Guild]
     *
     * @return uint32 memberCount
     */
    GetMemberCount() : uint32

    /**
     * Finds and returns the [Guild] leader by their GUID if logged in
     *
     * @return [Player] leader
     */
    GetLeader() : TSPlayer

    /**
     * Returns [Guild] leader GUID
     *
     * @return uint64 leaderGUID
     */
    GetLeaderGUID() : uint64

    /**
     * Returns the [Guild]s entry ID
     *
     * @return uint32 entryId
     */
    GetId() : uint32

    /**
     * Returns the [Guild]s name
     *
     * @return string guildName
     */
    GetName() : string

    /**
     * Returns the [Guild]s current Message Of The Day
     *
     * @return string guildMOTD
     */
    GetMOTD() : string

    /**
     * Returns the [Guild]s current info
     *
     * @return string guildInfo
     */
    GetInfo() : string

    /**
     * Sets the leader of this [Guild]
     *
     * @param [Player] leader : the [Player] leader to change
     */
    SetLeader(player : TSPlayer) : void

    /**
     * Sets the information of the bank tab specified
     *
     * @param uint8 tabId : the ID of the tab specified
     * @param string info : the information to be set to the bank tab
     */
    SetBankTabText(tabId : uint8,text : string) : void

    /**
     * Sends a [WorldPacket] to all the [Player]s in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     */
    SendPacket(data : TSWorldPacket) : void

    /**
     * Sends a [WorldPacket] to all the [Player]s at the specified rank in the [Guild]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to be sent to the [Player]s
     * @param uint8 rankId : the rank ID
     */
    SendPacketToRanked(data : TSWorldPacket,ranked : uint8) : void

    /**
     * Disbands the [Guild]
     */
    Disband() : void

    /**
     * Adds the specified [Player] to the [Guild] at the specified rank.
     *
     * If no rank is specified, defaults to none.
     *
     * @param [Player] player : the [Player] to be added to the guild
     * @param uint8 rankId : the rank ID
     */
    AddMember(player : TSPlayer,rankId : uint8) : void

    /**
     * Removes the specified [Player] from the [Guild].
     *
     * @param [Player] player : the [Player] to be removed from the guild
     * @param bool isDisbanding : default 'false', should only be set to 'true' if the guild is triggered to disband
     */
    DeleteMember(player : TSPlayer,isDisbanding : bool) : void

    /**
     * Promotes/demotes the [Player] to the specified rank.
     *
     * @param [Player] player : the [Player] to be promoted/demoted
     * @param uint8 rankId : the rank ID
     */
    SetMemberRank(player : TSPlayer,newRank : uint8) : void    
}

declare class TSGroup {
    IsNull() : bool

    /**
     * Returns 'true' if the [Player] is the [Group] leader
     *
     * @param uint64 guid : guid of a possible leader
     * @return bool isLeader
     */
    IsLeader(guid : uint64) : bool

    /**
     * Returns 'true' if the [Group] is full
     *
     * @return bool isFull
     */
    IsFull() : bool

    /**
     * Returns 'true' if the [Group] is a raid [Group]
     *
     * @return bool isRaid
     */
    IsRaidGroup() : bool

    /**
     * Returns 'true' if the [Group] is a battleground [Group]
     *
     * @return bool isBG
     */
    IsBGGroup() : bool

    /**
     * Returns 'true' if the [Player] is a member of this [Group]
     *
     * @param uint64 guid : guid of a player
     * @return bool isMember
     */
    IsMember(guid : uint64) : bool

    /**
     * Returns 'true' if the [Player] is an assistant of this [Group]
     *
     * @param uint64 guid : guid of a player
     * @return bool isAssistant
     */
    IsAssistant(guid : uint64) : bool

    /**
     * Returns 'true' if the [Player]s are in the same subgroup in this [Group]
     *
     * @param [Player] player1 : first [Player] to check
     * @param [Player] player2 : second [Player] to check
     * @return bool sameSubGroup
     */
    SameSubGroup(player1 : TSPlayer,player2 : TSPlayer) : bool

    /**
     * Returns 'true' if the subgroup has free slots in this [Group]
     *
     * @param uint8 subGroup : subGroup ID to check
     * @return bool hasFreeSlot
     */
    HasFreeSlotSubGroup(subGroup : uint8) : bool

    /**
     * Adds a new member to the [Group]
     *
     * @param [Player] player : [Player] to add to the group
     * @return bool added : true if member was added
     */
    AddMember(player : TSPlayer) : bool

    /**
     * Returns a table with the [Player]s in this [Group]
     *
     * @return table groupPlayers : table of [Player]s
     */
    GetMembers() : TSArray<TSPlayer>

    /**
     * Returns [Group] leader GUID
     *
     * @return uint64 leaderGUID
     */
    GetLeaderGUID() : uint64

    /**
     * Returns the [Group]'s GUID
     *
     * @return uint64 groupGUID
     */
    GetGUID() : uint64

    /**
     * Returns a [Group] member's GUID by their name
     *
     * @param string name : the [Player]'s name
     * @return uint64 memberGUID
     */
    GetMemberGUID(name : string) : uint64

    /**
     * Returns the member count of this [Group]
     *
     * @return uint32 memberCount
     */
    GetMembersCount() : uint32

    /**
     * Returns the [Player]'s subgroup ID of this [Group]
     *
     * @param uint64 guid : guid of the player
     * @return uint8 subGroupID : a valid subgroup ID or MAX_RAID_SUBGROUPS+1
     */
    GetMemberGroup(guid : uint64) : uint8

    /**
     * Sets the leader of this [Group]
     *
     * @param uint64 guid : guid of the new leader
     */
    SetLeader(guid : uint64) : void

    /**
     * Sends a specified [WorldPacket] to this [Group]
     *
     * @param [WorldPacket] packet : the [WorldPacket] to send
     * @param bool ignorePlayersInBg : ignores [Player]s in a battleground
     * @param uint64 ignore : ignore a [Player] by their GUID
     */
    SendPacket(data : TSWorldPacket,ignorePlayersInBg : bool,ignore : uint64) : void

    /**
     * Removes a [Player] from this [Group] and returns 'true' if successful
     *
     *     enum RemoveMethod
     *     {
     *         GROUP_REMOVEMETHOD_DEFAULT  = 0,
     *         GROUP_REMOVEMETHOD_KICK     = 1,
     *         GROUP_REMOVEMETHOD_LEAVE    = 2,
     *         GROUP_REMOVEMETHOD_KICK_LFG = 3
     *     }
     *
     * @param uint64 guid : guid of the player to remove
     * @param [RemoveMethod] method : method used to remove the player
     * @return bool removed
     */
    RemoveMember(guid : uint64,method : uint32) : bool

    /**
     * Disbands this [Group]
     *
     */
    Disband() : void

    /**
     * Converts this [Group] to a raid [Group]
     *
     */
    ConvertToRaid() : void

    /**
     * Sets the member's subGroup
     *
     * @param uint64 guid : guid of the player to move
     * @param uint8 groupID : the subGroup's ID
     */
    SetMembersGroup(guid : uint64,subGroup : uint8) : void

    /**
     * Sets the target icon of an object for the [Group]
     *
     * @param uint8 icon : the icon (Skull, Square, etc)
     * @param uint64 target : GUID of the icon target, 0 is to clear the icon
     * @param uint64 setter : GUID of the icon setter
     */
    SetTargetIcon(icon : uint8,target : uint64,setter : uint64) : void    
}

declare class TSWorldPacket {
    IsNull() : bool

    /**
     * Returns the opcode of the [WorldPacket].
     *
     * @return uint16 opcode
     */
    GetOpcode() : uint16

    /**
     * Returns the size of the [WorldPacket].
     *
     * @return uint32 size
     */
    GetSize() : uint32

    /**
     * Sets the opcode of the [WorldPacket] to the specified opcode.
     *
     * @param [Opcodes] opcode : see Opcodes.h for all known opcodes
     */
    SetOpcode(opcode : uint32) : void

    /**
     * Reads and returns a signed 8-bit integer value from the [WorldPacket].
     *
     * @return int8 value
     */
    ReadByte() : int8

    /**
     * Reads and returns an unsigned 8-bit integer value from the [WorldPacket].
     *
     * @return uint8 value
     */
    ReadUByte() : uint8

    /**
     * Reads and returns a signed 16-bit integer value from the [WorldPacket].
     *
     * @return int16 value
     */
    ReadShort() : int16

    /**
     * Reads and returns an unsigned 16-bit integer value from the [WorldPacket].
     *
     * @return uint16 value
     */
    ReadUShort() : uint16

    /**
     * Reads and returns a signed 32-bit integer value from the [WorldPacket].
     *
     * @return int32 value
     */
    ReadLong() : int32

    /**
     * Reads and returns an unsigned 32-bit integer value from the [WorldPacket].
     *
     * @return uint32 value
     */
    ReadULong() : uint32

    /**
     * Reads and returns a single-precision floating-point value from the [WorldPacket].
     *
     * @return float value
     */
    ReadFloat() : float

    /**
     * Reads and returns a double-precision floating-point value from the [WorldPacket].
     *
     * @return double value
     */
    ReadDouble() : double

    /**
     * Reads and returns an unsigned 64-bit integer value from the [WorldPacket].
     *
     * @return uint64 value : value returned as string
     */
    ReadGUID() : uint64

    /**
     * Reads and returns a string value from the [WorldPacket].
     *
     * @return string value
     */
    ReadString() : string

    /**
     * Writes an unsigned 64-bit integer value to the [WorldPacket].
     *
     * @param uint64 value : the value to be written to the [WorldPacket]
     */
    WriteGUID(guid : uint64) : void

    /**
     * Writes a string to the [WorldPacket].
     *
     * @param string value : the string to be written to the [WorldPacket]
     */
    WriteString(_val : string) : void

    /**
     * Writes a signed 8-bit integer value to the [WorldPacket].
     *
     * @param int8 value : the int8 value to be written to the [WorldPacket]
     */
    WriteByte(byte : int8) : void

    /**
     * Writes an unsigned 8-bit integer value to the [WorldPacket].
     *
     * @param uint8 value : the uint8 value to be written to the [WorldPacket]
     */
    WriteUByte(byte : uint8) : void

    /**
     * Writes a signed 16-bit integer value to the [WorldPacket].
     *
     * @param int16 value : the int16 value to be written to the [WorldPacket]
     */
    WriteShort(_short : int16) : void

    /**
     * Writes an unsigned 16-bit integer value to the [WorldPacket].
     *
     * @param uint16 value : the uint16 value to be written to the [WorldPacket]
     */
    WriteUShort(_ushort : uint16) : void

    /**
     * Writes a signed 32-bit integer value to the [WorldPacket].
     *
     * @param int32 value : the int32 value to be written to the [WorldPacket]
     */
    WriteLong(_long : int32) : void

    /**
     * Writes an unsigned 32-bit integer value to the [WorldPacket].
     *
     * @param uint32 value : the uint32 value to be written to the [WorldPacket]
     */
    WriteULong(_ulong : uint32) : void

    /**
     * Writes a 32-bit floating-point value to the [WorldPacket].
     *
     * @param float value : the float value to be written to the [WorldPacket]
     */
    WriteFloat(_val : float) : void

    /**
     * Writes a 64-bit floating-point value to the [WorldPacket].
     *
     * @param double value : the double value to be written to the [WorldPacket]
     */
    WriteDouble(_val : double) : void    
}

declare class TSQuest {
    IsNull() : bool

    /**
     * Returns 'true' if the [Quest] has the specified flag, false otherwise.
     * Below flags are based off of 3.3.5a. Subject to change.
     *
     *     enum QuestFlags
     *     {
     *         // Flags used at server and sent to client
     *         QUEST_FLAGS_NONE                    = 0x0,
     *         QUEST_FLAGS_STAY_ALIVE              = 0x1,       // Not used currently
     *         QUEST_FLAGS_PARTY_ACCEPT            = 0x2,       // Not used currently. If player in party, all players that can accept this quest will receive confirmation box to accept quest CMSG_QUEST_CONFIRM_ACCEPT/SMSG_QUEST_CONFIRM_ACCEPT
     *         QUEST_FLAGS_EXPLORATION             = 0x4,       // Not used currently
     *         QUEST_FLAGS_SHARABLE                = 0x8,       // Can be shared: Player::CanShareQuest()
     *         QUEST_FLAGS_HAS_CONDITION           = 0x10,      // Not used currently
     *         QUEST_FLAGS_HIDE_REWARD_POI         = 0x20,      // Not used currently: Unsure of content
     *         QUEST_FLAGS_RAID                    = 0x40,      // Not used currently
     *         QUEST_FLAGS_TBC                     = 0x80,      // Not used currently: Available if TBC expansion enabled only
     *         QUEST_FLAGS_NO_MONEY_FROM_XP        = 0x100,     // Not used currently: Experience is not converted to gold at max level
     *         QUEST_FLAGS_TRACKING                = 0x400,     // These quests are automatically rewarded on quest complete and they will never appear in quest log client side.
     *         QUEST_FLAGS_DEPRECATE_REPUTATION    = 0x800,     // Not used currently
     *         QUEST_FLAGS_DAILY                   = 0x1000,    // Used to know quest is Daily one
     *         QUEST_FLAGS_FLAGS_PVP               = 0x2000,    // Having this quest in log forces PvP flag
     *         QUEST_FLAGS_UNAVAILABLE             = 0x4000,    // Used on quests that are not generically available
     *         QUEST_FLAGS_WEEKLY                  = 0x8000,
     *         QUEST_FLAGS_AUTOCOMPLETE            = 0x10000,   // auto complete
     *         QUEST_FLAGS_DISPLAY_ITEM_IN_TRACKER = 0x20000,   // Displays usable item in quest tracker
     *         QUEST_FLAGS_OBJ_TEXT                = 0x40000,   // use Objective text as Complete text
     *         QUEST_FLAGS_AUTO_ACCEPT             = 0x80000,   // The client recognizes this flag as auto-accept. However, NONE of the current quests (3.3.5a) have this flag. Maybe blizz used to use it, or will use it in the future.
     *
     *         // ... 4.x added flags up to 0x80000000 - all unknown for now
     *     }
     *
     * @param [QuestFlags] flag : all available flags can be seen above
     * @return bool hasFlag
     */
    HasFlag(flag : uint32) : bool

    /**
     * Returns 'true' if the [Quest] is a daily quest, false otherwise.
     *
     * @return bool isDaily
     */
    IsDaily() : bool

    /**
     * Returns 'true' if the [Quest] is repeatable, false otherwise.
     *
     * @return bool isRepeatable
     */
    IsRepeatable() : bool

    /**
     * Returns entry ID of the [Quest].
     *
     * @return uint32 entryId
     */
    GetId() : uint32

    /**
     * Returns the [Quest]'s level.
     *
     * @return uint32 level
     */
    GetLevel() : uint32

    /**
     * Returns the minimum level required to pick up the [Quest].
     *
     * @return uint32 minLevel
     */
    GetMinLevel() : uint32

    /**
     * Returns the next [Quest] entry ID.
     *
     * @return int32 entryId
     */
    GetNextQuestId() : int32

    /**
     * Returns the previous [Quest] entry ID.
     *
     * @return int32 entryId
     */
    GetPrevQuestId() : int32

    /**
     * Returns the next [Quest] entry ID in the specific [Quest] chain.
     *
     * @return int32 entryId
     */
    GetNextQuestInChain() : int32

    /**
     * Returns the [Quest]'s flags.
     *
     * @return [QuestFlags] flags
     */
    GetFlags() : uint32

    /**
     * Returns the [Quest]'s type.
     *
     * TODO: Document types available.
     *
     * @return uint32 type
     */
    GetType() : uint32    
}

declare class TSMap {
    IsNull() : bool

    GetTasks(): TSTasks<TSMap>;
    GetData(): TSStorage;

    /**
     * Returns `true` if the [Map] is an arena [BattleGround], `false` otherwise.
     *
     * @return bool isArena
     */
    IsArena() : bool

    /**
     * Returns `true` if the [Map] is a non-arena [BattleGround], `false` otherwise.
     *
     * @return bool isBattleGround
     */
    IsBattleground() : bool

    /**
     * Returns `true` if the [Map] is a dungeon, `false` otherwise.
     *
     * @return bool isDungeon
     */
    IsDungeon() : bool

    /**
     * Returns `true` if the [Map] has no [Player]s, `false` otherwise.
     *
     * @return bool isEmpty
     */
    IsEmpty() : bool

    /**
     * Returns `true` if the [Map] is a heroic, `false` otherwise.
     *
     * @return bool isHeroic
     */
    IsHeroic() : bool

    /**
     * Returns `true` if the [Map] is a raid, `false` otherwise.
     *
     * @return bool isRaid
     */
    IsRaid() : bool

    /**
     * Returns the name of the [Map].
     *
     * @return string mapName
     */
    GetName() : string

    /**
     * Returns the height of the [Map] at the given X and Y coordinates.
     *
     * In case of no height found nil is returned
     *
     * @param float x
     * @param float y
     * @return float z
     */
    GetHeight(x : float,y : float,phasemask : uint32) : float

    /**
     * Returns the difficulty of the [Map].
     *
     * Always returns 0 if the expansion is pre-TBC.
     *
     * @return int32 difficulty
     */
    GetDifficulty() : int32

    /**
     * Returns the instance ID of the [Map].
     *
     * @return uint32 instanceId
     */
    GetInstanceId() : uint32

    /**
     * Returns the player count currently on the [Map] (excluding GMs).
     *
     * @return uint32 playerCount
     */
    GetPlayerCount() : uint32

    /**
     * Returns the ID of the [Map].
     *
     * @return uint32 mapId
     */
    GetMapId() : uint32

    /**
    * Returns a table with all the current [Player]s in the map
    *
    *     enum TeamId
    *     {
    *         TEAM_ALLIANCE = 0,
    *         TEAM_HORDE = 1,
    *         TEAM_NEUTRAL = 2
    *
    * @param [TeamId] team : optional check team of the [Player], Alliance, Horde or Neutral (All)
    * @return table mapPlayers
    */
    GetPlayers(team : uint32) : TSArray<TSPlayer>

    /**
     * Returns the area ID of the [Map] at the specified X, Y, and Z coordinates.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param uint32 phasemask = PHASEMASK_NORMAL
     * @return uint32 areaId
     */
    GetAreaId(x : float,y : float,z : float,phasemask : float) : uint32

    /**
     * Returns a [WorldObject] by its GUID from the map if it is spawned.
     *
     * @param uint64 guid
     */
    GetWorldObject(guid : uint64) : TSWorldObject

    /**
     * Sets the [Weather] type based on [WeatherType] and grade supplied.
     *
     *     enum WeatherType
     *     {
     *         WEATHER_TYPE_FINE       = 0,
     *         WEATHER_TYPE_RAIN       = 1,
     *         WEATHER_TYPE_SNOW       = 2,
     *         WEATHER_TYPE_STORM      = 3,
     *         WEATHER_TYPE_THUNDERS   = 86,
     *         WEATHER_TYPE_BLACKRAIN  = 90
     *
     * @param uint32 zone : id of the zone to set the weather for
     * @param [WeatherType] type : the [WeatherType], see above available weather types
     * @param float grade : the intensity/grade of the [Weather], ranges from 0 to 1
     */
    SetWeather(zoneId : uint32,weatherType : uint32,grade : float) : void
}

declare class TSItem extends TSObject {
    IsNull() : bool

    /**
     * Returns 'true' if the [Item] is soulbound, 'false' otherwise
     *
     * @return bool isSoulBound
     */
    IsSoulBound() : bool

    /**
     * Returns 'true' if the [Item] is account bound, 'false' otherwise
     *
     * @return bool isAccountBound
     */
    IsBoundAccountWide() : bool

    /**
     * Returns 'true' if the [Item] is bound to a [Player] by an enchant, 'false' otehrwise
     *
     * @return bool isBoundByEnchant
     */
    IsBoundByEnchant() : bool

    /**
     * Returns 'true' if the [Item] is not bound to the [Player] specified, 'false' otherwise
     *
     * @param [Player] player : the [Player] object to check the item against
     * @return bool isNotBound
     */
    IsNotBoundToPlayer(player : TSPlayer) : bool

    /**
     * Returns 'true' if the [Item] is locked, 'false' otherwise
     *
     * @return bool isLocked
     */
    IsLocked() : bool

    /**
     * Returns 'true' if the [Item] is a bag, 'false' otherwise
     *
     * @return bool isBag
     */
    IsBag() : bool

    /**
     * Returns 'true' if the [Item] is a currency token, 'false' otherwise
     *
     * @return bool isCurrencyToken
     */
    IsCurrencyToken() : bool

    /**
     * Returns 'true' if the [Item] is a not an empty bag, 'false' otherwise
     *
     * @return bool isNotEmptyBag
     */
    IsNotEmptyBag() : bool

    /**
     * Returns 'true' if the [Item] is broken, 'false' otherwise
     *
     * @return bool isBroken
     */
    IsBroken() : bool

    /**
     * Returns 'true' if the [Item] can be traded, 'false' otherwise
     *
     * @return bool isTradeable
     */
    CanBeTraded(mail : bool) : bool

    /**
     * Returns 'true' if the [Item] is currently in a trade window, 'false' otherwise
     *
     * @return bool isInTrade
     */
    IsInTrade() : bool

    /**
     * Returns 'true' if the [Item] is currently in a bag, 'false' otherwise
     *
     * @return bool isInBag
     */
    IsInBag() : bool

    /**
     * Returns 'true' if the [Item] is currently equipped, 'false' otherwise
     *
     * @return bool isEquipped
     */
    IsEquipped() : bool

    /**
     * Returns 'true' if the [Item] has the [Quest] specified tied to it, 'false' otherwise
     *
     * @param uint32 questId : the [Quest] id to be checked
     * @return bool hasQuest
     */
    HasQuest(quest : uint32) : bool

    /**
     * Returns 'true' if the [Item] is a potion, 'false' otherwise
     *
     * @return bool isPotion
     */
    IsPotion() : bool

    /**
     * Returns 'true' if the [Item] is a weapon vellum, 'false' otherwise
     *
     * @return bool isWeaponVellum
     */
    IsWeaponVellum() : bool

    /**
     * Returns 'true' if the [Item] is an armor vellum, 'false' otherwise
     *
     * @return bool isArmorVellum
     */
    IsArmorVellum() : bool

    /**
     * Returns 'true' if the [Item] is a conjured consumable, 'false' otherwise
     *
     * @return bool isConjuredConsumable
     */
    IsConjuredConsumable() : bool
    //GetItemLink(locale : uint8) : string
    GetOwnerGUID() : uint64

    /**
     * Returns the [Player] who currently owns the [Item]
     *
     * @return [Player] player : the [Player] who owns the [Item]
     */
    GetOwner() : TSPlayer

    /**
     * Returns the [Item]s stack count
     *
     * @return uint32 count
     */
    GetCount() : uint32

    /**
     * Returns the [Item]s max stack count
     *
     * @return uint32 maxCount
     */
    GetMaxStackCount() : uint32

    /**
     * Returns the [Item]s current slot
     *
     * @return uint8 slot
     */
    GetSlot() : uint8

    /**
     * Returns the [Item]s current bag slot
     *
     * @return uint8 bagSlot
     */
    GetBagSlot() : uint8

    /**
     * Returns the [Item]s enchantment ID by enchant slot specified
     *
     * @param [EnchantmentSlot] enchantSlot : the enchant slot specified
     * @return uint32 enchantId : the id of the enchant slot specified
     */
    GetEnchantmentId(enchant_slot : uint32) : uint32

    /**
     * Returns the spell ID tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellId : the id of the spell
     */
    GetSpellId(index : uint32) : uint32

    /**
     * Returns the spell trigger tied to the [Item] by spell index
     *
     * @param uint32 spellIndex : the spell index specified
     * @return uint32 spellTrigger : the spell trigger of the specified index
     */
    GetSpellTrigger(index : uint32) : uint32

    /**
     * Returns class of the [Item]
     *
     * @return uint32 class
     */
    GetClass() : uint32

    /**
     * Returns subclass of the [Item]
     *
     * @return uint32 subClass
     */
    GetSubClass() : uint32

    /**
     * Returns the name of the [Item]
     *
     * @return string name
     */
    GetName() : string

    /**
     * Returns the display ID of the [Item]
     *
     * @return uint32 displayId
     */
    GetDisplayId() : uint32

    /**
     * Returns the quality of the [Item]
     *
     * @return uint32 quality
     */
    GetQuality() : uint32

    /**
     * Returns the default purchase count of the [Item]
     *
     * @return uint32 count
     */
    GetBuyCount() : uint32

    /**
     * Returns the purchase price of the [Item]
     *
     * @return uint32 price
     */
    GetBuyPrice() : uint32

    /**
     * Returns the sell price of the [Item]
     *
     * @return uint32 price
     */
    GetSellPrice() : uint32

    /**
     * Returns the inventory type of the [Item]
     *
     * @return uint32 inventoryType
     */
    GetInventoryType() : uint32

    /**
     * Returns the [Player] classes allowed to use this [Item]
     *
     * @return uint32 allowableClass
     */
    GetAllowableClass() : uint32

    /**
     * Returns the [Player] races allowed to use this [Item]
     *
     * @return uint32 allowableRace
     */
    GetAllowableRace() : uint32

    /**
     * Returns the [Item]s level
     *
     * @return uint32 itemLevel
     */
    GetItemLevel() : uint32

    /**
     * Returns the minimum level required to use this [Item]
     *
     * @return uint32 requiredLevel
     */
    GetRequiredLevel() : uint32
    GetStatsCount() : uint32

    /**
     * Returns the random property ID of this [Item]
     *
     * @return uint32 randomPropertyId
     */
    GetRandomProperty() : uint32
    GetRandomSuffix() : int32

    /**
     * Returns the item set ID of this [Item]
     *
     * @return uint32 itemSetId
     */
    GetItemSet() : uint32

    /**
     * Returns the bag size of this [Item], 0 if [Item] is not a bag
     *
     * @return uint32 bagSize
     */
    GetBagSize() : uint32

    /**
     * Sets the [Player] specified as the owner of the [Item]
     *
     * @param [Player] player : the [Player] specified
     */
    SetOwner(player : TSPlayer) : void

    /**
     * Sets the binding of the [Item] to 'true' or 'false'
     *
     * @param bool setBinding
     */
    SetBinding(soulbound : bool) : void

    /**
     * Sets the stack count of the [Item]
     *
     * @param uint32 count
     */
    SetCount(count : uint32) : void

    /**
     * Sets the specified enchantment of the [Item] to the specified slot
     *
     * @param uint32 enchantId : the ID of the enchant to be applied
     * @param uint32 enchantSlot : the slot for the enchant to be applied to
     * @return bool enchantmentSuccess : if enchantment is successfully set to specified (EnchantmentSlot)slot, returns 'true', otherwise 'false'
     */
    SetEnchantment(enchant : uint32,slot : uint32) : bool

    /**
     * Removes an enchant from the [Item] by the specified slot
     *
     * @param uint32 enchantSlot : the slot for the enchant to be removed from
     * @return bool enchantmentRemoved : if enchantment is successfully removed from specified (EnchantmentSlot)slot, returns 'true', otherwise 'false'
     */
    ClearEnchantment(slot : uint32) : bool

    /**
     * Saves the [Item] to the database
     */
    SaveToDB() : void    
}

declare class TSBattleground {
    IsNull() : bool

    /**
     * Returns the name of the [BattleGround].
     *
     * @return string name
     */
    GetName() : string

    /**
     * Returns the amount of alive players in the [BattleGround] by the team ID.
     *
     * @param [Team] team : team ID
     * @return uint32 count
     */
    GetAlivePlayersCountByTeam(team : uint32) : uint32

    /**
     * Returns the [Map] of the [BattleGround].
     *
     * @return [Map] map
     */
    GetMap() : TSMap

    /**
     * Returns the bonus honor given by amount of kills in the specific [BattleGround].
     *
     * @param uint32 kills : amount of kills
     * @return uint32 bonusHonor
     */
    GetBonusHonorFromKillCount(kills : uint32) : uint32

    /**
     * Returns the end time of the [BattleGround].
     *
     * @return uint32 endTime
     */
    GetEndTime() : uint32

    /**
     * Returns the amount of free slots for the selected team in the specific [BattleGround].
     *
     * @param [Team] team : team ID
     * @return uint32 freeSlots
     */
    GetFreeSlotsForTeam(team : uint32) : uint32

    /**
     * Returns the instance ID of the [BattleGround].
     *
     * @return uint32 instanceId
     */
    GetInstanceId() : uint32

    /**
     * Returns the map ID of the [BattleGround].
     *
     * @return uint32 mapId
     */
    GetMapId() : uint32

    /**
     * Returns the type ID of the [BattleGround].
     *
     * @return [BattleGroundTypeId] typeId
     */
    GetTypeId() : uint32

    /**
     * Returns the max allowed [Player] level of the specific [BattleGround].
     *
     * @return uint32 maxLevel
     */
    GetMaxLevel() : uint32

    /**
     * Returns the minimum allowed [Player] level of the specific [BattleGround].
     *
     * @return uint32 minLevel
     */
    GetMinLevel() : uint32

    /**
     * Returns the maximum allowed [Player] count of the specific [BattleGround].
     *
     * @return uint32 maxPlayerCount
     */
    GetMaxPlayers() : uint32

    /**
     * Returns the minimum allowed [Player] count of the specific [BattleGround].
     *
     * @return uint32 minPlayerCount
     */
    GetMinPlayers() : uint32

    /**
     * Returns the maximum allowed [Player] count per team of the specific [BattleGround].
     *
     * @return uint32 maxTeamPlayerCount
     */
    GetMaxPlayersPerTeam() : uint32

    /**
     * Returns the minimum allowed [Player] count per team of the specific [BattleGround].
     *
     * @return uint32 minTeamPlayerCount
     */
    GetMinPlayersPerTeam() : uint32

    /**
     * Returns the winning team of the specific [BattleGround].
     *
     * @return [Team] team
     */
    GetWinner() : uint32

    /**
     * Returns the status of the specific [BattleGround].
     *
     * @return [BattleGroundStatus] status
     */
    GetStatus() : uint32    
}

declare class TSGameObject extends TSWorldObject {
    IsNull() : bool

    GetLoot(): TSLoot;

    /**
     * Returns 'true' if the [GameObject] can give the specified [Quest]
     *
     * @param uint32 questId : quest entry Id to check
     * @return bool hasQuest
     */
    HasQuest(questId : uint32) : bool

    /**
     * Returns 'true' if the [GameObject] is spawned
     *
     * @return bool isSpawned
     */
    IsSpawned() : bool

    /**
     * Returns 'true' if the [GameObject] is a transport
     *
     * @return bool isTransport
     */
    IsTransport() : bool

    /**
     * Returns 'true' if the [GameObject] is active
     *
     * @return bool isActive
     */
    IsActive() : bool

    /**
     * Returns display ID of the [GameObject]
     *
     * @return uint32 displayId
     */
    GetDisplayId() : uint32

    /**
     * Returns the state of a [GameObject]
     * Below are client side [GOState]s off of 3.3.5a
     *
     *     enum GOState
     *     {
     *         GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
     *         GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
     *         GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
     *     }
     *
     * @return [GOState] goState
     */
    GetGoState() : uint32

    /**
     * Returns the [LootState] of a [GameObject]
     * Below are [LootState]s off of 3.3.5a
     *
     *     enum LootState
     *     {
     *         GO_NOT_READY = 0,
     *         GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
     *         GO_ACTIVATED,
     *         GO_JUST_DEACTIVATED
     *     }
     *
     * @return [LootState] lootState
     */
    GetLootState() : uint32

    /**
     * Returns the [Player] that can loot the [GameObject]
     *
     * Not the original looter and may be nil.
     *
     * @return [Player] player
     */
    GetLootRecipient() : TSPlayer

    /**
     * Returns the [Group] that can loot the [GameObject]
     *
     * Not the original looter and may be nil.
     *
     * @return [Group] group
     */
    GetLootRecipientGroup() : TSGroup

    /**
     * Returns the guid of the [GameObject] that is used as the ID in the database
     *
     * @return uint32 dbguid
     */
    GetDBTableGUIDLow() : uint32

    /**
     * Sets the state of a [GameObject]
     *
     *     enum GOState
     *     {
     *         GO_STATE_ACTIVE             = 0,                        // show in world as used and not reset (closed door open)
     *         GO_STATE_READY              = 1,                        // show in world as ready (closed door close)
     *         GO_STATE_ACTIVE_ALTERNATIVE = 2                         // show in world as used in alt way and not reset (closed door open by cannon fire)
     *     }
     *
     * @param [GOState] state : all available go states can be seen above
     */
    SetGoState(state : uint32) : void

    /**
     * Sets the [LootState] of a [GameObject]
     * Below are [LootState]s off of 3.3.5a
     *
     *     enum LootState
     *     {
     *         GO_NOT_READY = 0,
     *         GO_READY,                                               // can be ready but despawned, and then not possible activate until spawn
     *         GO_ACTIVATED,
     *         GO_JUST_DEACTIVATED
     *     }
     *
     * @param [LootState] state : all available loot states can be seen above
     */
    SetLootState(state : uint32) : void

    /**
     * Saves [GameObject] to the database
     *
     */
    SaveToDB() : void

    /**
     * Removes [GameObject] from the world
     *
     * The object is no longer reachable after this and it is not respawned.
     *
     * @param bool deleteFromDB : if true, it will delete the [GameObject] from the database
     */
    RemoveFromWorld(deldb : bool) : void

    /**
     * Activates a door or a button/lever
     *
     * @param uint32 delay = 0 : cooldown time in seconds to restore the [GameObject] back to normal. 0 for infinite duration
     */
    UseDoorOrButton(delay : uint32) : void

    /**
     * Despawns a [GameObject]
     *
     * The gameobject may be automatically respawned by the core
     */
    Despawn() : void

    /**
     * Respawns a [GameObject]
     */
    Respawn() : void

    /**
     * Sets the respawn or despawn time for the gameobject.
     *
     * Respawn time is also used as despawn time depending on gameobject settings
     *
     * @param int32 delay = 0 : cooldown time in seconds to respawn or despawn the object. 0 means never
     */
    SetRespawnTime(respawn : int32) : void    
}

declare class TSSpell {
    IsNull() : bool

    /**
     * Returns `true` if the [Spell] is automatically repeating, `false` otherwise.
     *
     * @return bool isAutoRepeating
     */
    IsAutoRepeat() : bool

    /**
     * Returns the [Unit] that casted the [Spell].
     *
     * @return [Unit] caster
     */
    GetCaster() : TSUnit

    /**
     * Returns the cast time of the [Spell].
     *
     * @return int32 castTime
     */
    GetCastTime() : int32

    /**
     * Returns the entry ID of the [Spell].
     *
     * @return uint32 entryId
     */
    GetEntry() : uint32

    /**
     * Returns the power cost of the [Spell].
     *
     * @return uint32 powerCost
     */
    GetPowerCost() : uint32

    /**
     * Returns the spell duration of the [Spell].
     *
     * @return int32 duration
     */
    GetDuration() : int32

    /**
     * Returns the target destination coordinates of the [Spell].
     *
     * @return float x : x coordinate of the [Spell]
     * @return float y : y coordinate of the [Spell]
     * @return float z : z coordinate of the [Spell]
     */
    GetTargetDest() : TSPosition

    /**
     * Returns the target [Object] of the [Spell].
     *
     * The target can be any of the following [Object] types:
     * - [Player]
     * - [Creature]
     * - [GameObject]
     * - [Item]
     * - [Corpse]
     *
     * @return [Object] target
     */
    GetTarget() : TSObject

    /**
     * Sets the [Spell] to automatically repeat.
     *
     * @param bool repeat : set variable to 'true' for spell to automatically repeat
     */
    SetAutoRepeat(repeat : bool) : void

    /**
     * Casts the [Spell].
     *
     * @param bool skipCheck = false : skips initial checks to see if the [Spell] can be casted or not, this is optional
     */
    Cast(skipCheck : bool) : void

    /**
     * Cancels the [Spell].
     */
    Cancel() : void

    /**
     * Finishes the [Spell].
     */
    Finish() : void    
}

declare class TSVehicle {
    IsNull() : bool

    /**
     * Returns true if the [Unit] passenger is on board
     *
     * @param [Unit] passenger
     * @return bool isOnBoard
     */
    IsOnBoard(passenger : TSUnit) : bool

    /**
     * Returns the [Vehicle]'s owner
     *
     * @return [Unit] owner
     */
    GetOwner() : TSUnit

    /**
     * Returns the [Vehicle]'s entry
     *
     * @return uint32 entry
     */
    GetEntry() : uint32

    /**
     * Returns the [Vehicle]'s passenger in the specified seat
     *
     * @param int8 seat
     * @return [Unit] passenger
     */
    GetPassenger(seatId : int8) : TSUnit

    /**
     * Adds [Unit] passenger to a specified seat in the [Vehicle]
     *
     * @param [Unit] passenger
     * @param int8 seat
     */
    AddPassenger(passenger : TSUnit,seatId : int8) : void

    /**
     * Removes [Unit] passenger from the [Vehicle]
     *
     * @param [Unit] passenger
     */
    RemovePassenger(passenger : TSUnit) : void    
}

declare class TSStorage {
    SetObject<T>(modid: uint32, key: string, obj: T): T;
    HasObject(modid: uint32, key: string): boolean;
    GetObject<T>(modid: uint32, key: string, creator?: ()=>T): T;

    SetInt(key: string, value: uint32): uint32;
    HasInt(key: string): boolean;
    GetInt(key: string): uint32;

    SetFloat(key: string, value: double): double;
    HasFloat(key: string): boolean;
    GetFloat(key: string): double;

    SetString(key: string, value: string): string;
    HasString(key: string): boolean;
    GetString(key: string): string;
}

declare class TSCollisionEntry {
    readonly name: string;
    maxHits: uint32;
    range: float;
    minDelay: uint64;
    hitmap: TSDictionary<uint64,uint32>
    Tick(value: TSWorldObject, force?: boolean)
}

declare class TSCollisions {
    Add(modid: uint32, id: string, range: float, minDelay: uint32, maxHits: uint32, callback: (entry: TSCollisionEntry, self: TSWorldObject, collided: TSWorldObject, cancel: TSMutable<uint32>)=>void)
    Contains(id: string): bool;
    Get(id: string): TSCollisionEntry;
}

declare class TSWorldObject extends TSObject {
    GetCollisions(): TSCollisions;
    IsNull() : bool
    GetCreaturesInRange(range : float,entry : uint32,hostile : uint32,dead : uint32) : TSArray<TSCreature>
    GetUnitsInRange(range : float,hostile : uint32,dead : uint32) : TSArray<TSUnit>
    GetPlayersInRange(range : float,hostile : uint32,dead : uint32) : TSArray<TSPlayer>
    GetGameObjectsInRange(range : float,entry : uint32,hostile : uint32) : TSArray<TSGameObject>

    GetData(): TSStorage;

    GetTasks(): TSTasks<TSWorldObject>

    /**
     * Returns the name of the [WorldObject]
     *
     * @return string name
     */
    GetName() : string

    /**
     * Returns the current [Map] object of the [WorldObject]
     *
     * @return [Map] mapObject
     */
    GetMap() : TSMap

    /**
     * Returns the current phase of the [WorldObject]
     *
     * @return uint32 phase
     */
    GetPhaseMask() : uint32

    /**
    * Sets the [WorldObject]'s phase mask.
    *
    * @param uint32 phaseMask
    * @param bool update = true : update visibility to nearby objects
    */
    SetPhaseMask(phaseMask : uint32,update : bool) : void

    /**
     * Returns the current instance ID of the [WorldObject]
     *
     * @return uint32 instanceId
     */
    GetInstanceId() : uint32

    /**
     * Returns the current area ID of the [WorldObject]
     *
     * @return uint32 areaId
     */
    GetAreaId() : uint32

    /**
     * Returns the current zone ID of the [WorldObject]
     *
     * @return uint32 zoneId
     */
    GetZoneId() : uint32

    /**
     * Returns the current map ID of the [WorldObject]
     *
     * @return uint32 mapId
     */
    GetMapId() : uint32

    /**
     * Returns the current X coordinate of the [WorldObject]
     *
     * @return float x
     */
    GetX() : float

    /**
     * Returns the current Y coordinate of the [WorldObject]
     *
     * @return float y
     */
    GetY() : float

    /**
     * Returns the current Z coordinate of the [WorldObject]
     *
     * @return float z
     */
    GetZ() : float

    /**
     * Returns the current orientation of the [WorldObject]
     *
     * @return float orientation / facing
     */
    GetO() : float
    GetLocation() : TSPosition
    GetNearestPlayer(range : float,hostile : uint32,dead : uint32) : TSPlayer
    GetNearestGameObject(range : float,entry : uint32,hostile : uint32) : TSGameObject
    GetNearestCreature(range : float,entry : uint32,hostile : uint32,dead : uint32) : TSCreature

    /**
     * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 3d space.
     *
     * The function takes into account the given object sizes. See also [WorldObject:GetExactDistance], [WorldObject:GetDistance2d]
     *
     * @proto dist = (obj)
     * @proto dist = (x, y, z)
     *
     * @param [WorldObject] obj
     * @param float x : the X-coordinate of the point
     * @param float y : the Y-coordinate of the point
     * @param float z : the Z-coordinate of the point
     *
     * @return float dist : the distance in yards
     */
    GetDistance(target : TSWorldObject,X : float,Y : float,Z : float) : float

    /**
     * Returns the distance from this [WorldObject] to another [WorldObject], or from this [WorldObject] to a point in 2d space.
     *
     * The function takes into account the given object sizes. See also [WorldObject:GetDistance], [WorldObject:GetExactDistance2d]
     *
     * @proto dist = (obj)
     * @proto dist = (x, y)
     *
     * @param [WorldObject] obj
     * @param float x : the X-coordinate of the point
     * @param float y : the Y-coordinate of the point
     *
     * @return float dist : the distance in yards
     */
    GetDistance2d(target : TSWorldObject,X : float,Y : float) : float

    /**
     * Returns the x, y and z of a point dist away from the [WorldObject].
     *
     * @param float distance : specifies the distance of the point from the [WorldObject] in yards
     * @param float angle : specifies the angle of the point relative to the orientation / facing of the [WorldObject] in radians
     *
     * @return float x
     * @return float y
     * @return float z
     */
    GetRelativePoint(dist : float,rad : float) : TSPosition

    /**
     * Sends a [WorldPacket] to [Player]s in sight of the [WorldObject].
     *
     * @param [WorldPacket] packet
     */
    SendPacket(data : TSWorldPacket) : void

    /**
     * Spawns a [GameObject] at specified location.
     *
     * @param uint32 entry : [GameObject] entry ID
     * @param float x
     * @param float y
     * @param float z
     * @param float o
     * @param uint32 respawnDelay = 30 : respawn time in seconds
     * @return [GameObject] gameObject
     */
    SummonGameObject(entry : uint32,x : float,y : float,z : float,o : float,respawnDelay : uint32) : TSGameObject

    /**
     * Spawns the creature at specified location.
     *
     *     enum TempSummonType
     *     {
     *         TEMPSUMMON_TIMED_OR_DEAD_DESPAWN       = 1, // despawns after a specified time OR when the creature disappears
     *         TEMPSUMMON_TIMED_OR_CORPSE_DESPAWN     = 2, // despawns after a specified time OR when the creature dies
     *         TEMPSUMMON_TIMED_DESPAWN               = 3, // despawns after a specified time
     *         TEMPSUMMON_TIMED_DESPAWN_OUT_OF_COMBAT = 4, // despawns after a specified time after the creature is out of combat
     *         TEMPSUMMON_CORPSE_DESPAWN              = 5, // despawns instantly after death
     *         TEMPSUMMON_CORPSE_TIMED_DESPAWN        = 6, // despawns after a specified time after death
     *         TEMPSUMMON_DEAD_DESPAWN                = 7, // despawns when the creature disappears
     *         TEMPSUMMON_MANUAL_DESPAWN              = 8, // despawnswhen TSWorldObject::UnSummon() is called
     *         TEMPSUMMON_TIMED_OOC_OR_CORPSE_DESPAWN = 9, // despawns after a specified time (OOC) OR when the creature dies
     *         TEMPSUMMON_TIMED_OOC_OR_DEAD_DESPAWN   = 10 // despawns after a specified time (OOC) OR when the creature disappears
     *
     * @param uint32 entry : [Creature]'s entry ID
     * @param float x
     * @param float y
     * @param float z
     * @param float o
     * @param [TempSummonType] spawnType = MANUAL_DESPAWN : defines how and when the creature despawns
     * @param uint32 despawnTimer = 0 : despawn time in milliseconds
     * @return [Creature] spawnedCreature
     */
    SpawnCreature(entry : uint32,x : float,y : float,z : float,o : float,spawnType : uint32,despawnTimer : uint32) : TSCreature

    /**
     * Returns true if the given [WorldObject] or coordinates are in the [WorldObject]'s line of sight
     *
     * @proto isInLoS = (worldobject)
     * @proto isInLoS = (x, y, z)
     *
     * @param [WorldObject] worldobject
     * @param float x
     * @param float y
     * @param float z
     * @return bool isInLoS
     */
    IsWithinLoS(target : TSWorldObject,x : float,y : float,z : float) : bool

    /**
     * Returns true if the [WorldObject]s are on the same map
     *
     * @param [WorldObject] worldobject
     * @return bool isInMap
     */
    IsInMap(target : TSWorldObject) : bool

    /**
     * Returns true if the point is in the given distance of the [WorldObject]
     *
     * Notice that the distance is measured from the edge of the [WorldObject].
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float distance
     * @return bool isInDistance
     */
    IsWithinDist3d(x : float,y : float,z : float,dist : float) : bool

    /**
     * Returns true if the point is in the given distance of the [WorldObject]
     *
     * The distance is measured only in x,y coordinates.
     * Notice that the distance is measured from the edge of the [WorldObject].
     *
     * @param float x
     * @param float y
     * @param float distance
     * @return bool isInDistance
     */
    IsWithinDist2d(x : float,y : float,dist : float) : bool

    /**
     * Returns true if the target is in the given distance of the [WorldObject]
     *
     * Notice that the distance is measured from the edge of the [WorldObject]s.
     *
     * @param [WorldObject] target
     * @param float distance
     * @param bool is3D = true : if false, only x,y coordinates used for checking
     * @return bool isInDistance
     */
    IsWithinDist(target : TSWorldObject,distance : float,is3D : bool) : bool

    /**
     * Returns true if the [WorldObject] is on the same map and within given distance
     *
     * Notice that the distance is measured from the edge of the [WorldObject]s.
     *
     * @param [WorldObject] target
     * @param float distance
     * @param bool is3D = true : if false, only x,y coordinates used for checking
     * @return bool isInDistance
     */
    IsWithinDistInMap(target : TSWorldObject,distance : float,is3D : bool) : bool

    /**
     * Returns true if the target is within given range
     *
     * Notice that the distance is measured from the edge of the [WorldObject]s.
     *
     * @param [WorldObject] target
     * @param float minrange
     * @param float maxrange
     * @param bool is3D = true : if false, only x,y coordinates used for checking
     * @return bool isInDistance
     */
    IsInRange(target : TSWorldObject,minrange : float,maxrange : float,is3D : bool) : bool

    /**
     * Returns true if the point is within given range
     *
     * Notice that the distance is measured from the edge of the [WorldObject].
     *
     * @param float x
     * @param float y
     * @param float minrange
     * @param float maxrange
     * @return bool isInDistance
     */
    IsInRange2d(x : float,y : float,minrange : float,maxrange : float) : bool

    /**
     * Returns true if the point is within given range
     *
     * Notice that the distance is measured from the edge of the [WorldObject].
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float minrange
     * @param float maxrange
     * @return bool isInDistance
     */
    IsInRange3d(x : float,y : float,z : float,minrange : float,maxrange : float) : bool

    /**
     * Returns true if the target is in the given arc in front of the [WorldObject]
     *
     * @param [WorldObject] target
     * @param float arc = pi
     * @return bool isInFront
     */
    IsInFront(target : TSWorldObject,arc : float) : bool

    /**
     * Returns true if the target is in the given arc behind the [WorldObject]
     *
     * @param [WorldObject] target
     * @param float arc = pi
     * @return bool isInBack
     */
    IsInBack(target : TSWorldObject,arc : float) : bool

    /**
     * The [WorldObject] plays music to a [Player]
     *
     * If no [Player] provided it will play the music to everyone near.
     * This method does not interrupt previously played music.
     *
     * See also [WorldObject:PlayDistanceSound], [WorldObject:PlayDirectSound]
     *
     * @param uint32 music : entry of a music
     * @param [Player] player = nil : [Player] to play the music to
     */
    PlayMusic(musicid : uint32,player : TSPlayer) : void

    /**
     * The [WorldObject] plays a sound to a [Player]
     *
     * If no [Player] provided it will play the sound to everyone near.
     * This method will play sound and does not interrupt prvious sound.
     *
     * See also [WorldObject:PlayDistanceSound], [WorldObject:PlayMusic]
     *
     * @param uint32 sound : entry of a sound
     * @param [Player] player = nil : [Player] to play the sound to
     */
    PlayDirectSound(soundId : uint32,player : TSPlayer) : void

    /**
     * The [WorldObject] plays a sound to a [Player]
     *
     * If no [Player] it will play the sound to everyone near.
     * Sound will fade the further you are from the [WorldObject].
     * This method interrupts previously playing sound.
     *
     * See also [WorldObject:PlayDirectSound], [WorldObject:PlayMusic]
     *
     * @param uint32 sound : entry of a sound
     * @param [Player] player = nil : [Player] to play the sound to
     */
    PlayDistanceSound(soundId : uint32,player : TSPlayer) : void    

    GetGameObject(guid: uint64): TSGameObject
    GetCorpse(guid: uint64): TSCorpse
    GetUnit(guid: uint64): TSUnit
    GetCreature(guid: uint64): TSCreature
    GetPlayer(guid: uint64): TSPlayer
}

declare class TSObject {
    IsNull() : bool
    IsUnit() : bool
    IsCreature() : bool
    IsGameObject() : bool
    IsPlayer() : bool
    IsCorpse() : bool

    /**
     * Returns `true` if the specified flag is set, otherwise `false`.
     *
     * @param uint16 index : the index of the flags data in the [Object]
     * @param uint32 flag : the flag to check for in the flags data
     * @return bool hasFlag
     */
    HasFlag(index : uint16,flag : uint32) : bool

    /**
     * Returns `true` if the [Object] has been added to its [Map], otherwise `false`.
     *
     * @return bool inWorld
     */
    IsInWorld() : bool

    /**
     * Returns the data at the specified index, casted to a signed 32-bit integer.
     *
     * @param uint16 index
     * @return int32 value
     */
    GetInt32Value(index : uint16) : int32

    /**
     * Returns the data at the specified index, casted to a unsigned 32-bit integer.
     *
     * @param uint16 index
     * @return uint32 value
     */
    GetUInt32Value(index : uint16) : uint32

    /**
     * Returns the data at the specified index, casted to a single-precision floating point value.
     *
     * @param uint16 index
     * @return float value
     */
    GetFloatValue(index : uint16) : float

    /**
     * Returns the data at the specified index and offset, casted to an unsigned 8-bit integer.
     *
     * E.g. if you want the second byte at index 10, you would pass in 1 as the offset.
     *
     * @param uint16 index
     * @param uint8 offset : should be 0, 1, 2, or 3
     * @return uint8 value
     */
    GetByteValue(index : uint16,offset : uint8) : uint8

    /**
     * Returns the data at the specified index and offset, casted to a signed 16-bit integer.
     *
     * E.g. if you want the second half-word at index 10, you would pass in 1 as the offset.
     *
     * @param uint16 index
     * @param uint8 offset : should be 0 or 1
     * @return uint16 value
     */
    GetUInt16Value(index : uint16,offset : uint8) : uint16

    /**
     * Returns the scale/size of the [Object].
     *
     * This affects the size of a [WorldObject] in-game, but [Item]s don't have a "scale".
     *
     * @return float scale
     */
    GetScale() : float

    /**
     * Returns the entry of the [Object].
     *
     * [Player]s do not have an "entry".
     *
     * @return uint32 entry
     */
    GetEntry() : uint32

    /**
     * Returns the GUID of the [Object].
     * 
     * GUID is an unique identifier for the object.
     * 
     * However on MaNGOS and cMangos creatures and gameobjects inside different maps can share
     * the same GUID but not on the same map.
     * 
     * On TrinityCore this value is unique across all maps
     *
     * @return uint64 guid
     */
    GetGUID() : uint64

    /**
     * Returns the low-part of the [Object]'s GUID.
     * 
     * On TrinityCore all low GUIDs are different for all objects of the same type.
     * For example creatures in instances are assigned new GUIDs when the Map is created.
     * 
     * On MaNGOS and cMaNGOS low GUIDs are unique only on the same map.
     * For example creatures in instances use the same low GUID assigned for that spawn in the database.
     * This is why to identify a creature you have to know the instanceId and low GUID. See [Map:GetIntstanceId]
     *
     * @return uint32 guidLow
     */
    GetGUIDLow() : uint32

    /**
     * Returns the TypeId of the [Object].
     *
     *     enum TypeID
     *     {
     *         TYPEID_OBJECT        = 0,
     *         TYPEID_ITEM          = 1,
     *         TYPEID_CONTAINER     = 2,
     *         TYPEID_UNIT          = 3,
     *         TYPEID_PLAYER        = 4,
     *         TYPEID_GAMEOBJECT    = 5,
     *         TYPEID_DYNAMICOBJECT = 6,
     *         TYPEID_CORPSE        = 7
     *
     * @return uint8 typeID
     */
    GetTypeId() : uint8

    /**
     * Returns the data at the specified index, casted to an unsigned 64-bit integer.
     *
     * @param uint16 index
     * @return uint64 value
     */
    GetUInt64Value(index : uint16) : uint64

    /**
     * Sets the specified flag in the data value at the specified index.
     *
     * If the flag was already set, it remains set.
     *
     * To remove a flag, use [Object:RemoveFlag].
     *
     * @param uint16 index
     * @param uint32 value
     */
    SetFlag(index : uint16,flag : uint32) : void

    /**
     * Sets the data at the specified index to the given value, converted to a signed 32-bit integer.
     *
     * @param uint16 index
     * @param int32 value
     */
    SetInt32Value(index : uint16,value : int32) : void

    /**
     * Sets the data at the specified index to the given value, converted to an unsigned 32-bit integer.
     *
     * @param uint16 index
     * @param uint32 value
     */
    SetUInt32Value(index : uint16,value : uint32) : void

    /**
     * Sets the data at the specified index to the given value, converted to an unsigned 32-bit integer.
     *
     * @param uint16 index
     * @param uint32 value
     */
    UpdateUInt32Value(index : uint16,value : uint32) : void

    /**
     * Sets the data at the specified index to the given value, converted to a single-precision floating point value.
     *
     * @param uint16 index
     * @param float value
     */
    SetFloatValue(index : uint16,value : float) : void

    /**
     * Sets the data at the specified index and offset to the given value, converted to an unsigned 8-bit integer.
     *
     * @param uint16 index
     * @param uint8 offset : should be 0, 1, 2, or 3
     * @param uint8 value
     */
    SetByteValue(index : uint16,offset : uint8,value : uint8) : void

    /**
     * Sets the data at the specified index to the given value, converted to an unsigned 16-bit integer.
     *
     * @param uint16 index
     * @param uint8 offset : should be 0 or 1
     * @param uint16 value
     */
    SetUInt16Value(index : uint16,offset : uint8,value : uint16) : void

    /**
     * Sets the data at the specified index to the given value, converted to a signed 16-bit integer.
     *
     * @param uint16 index
     * @param uint8 offset : should be 0 or 1
     * @param int16 value
     */
    SetInt16Value(index : uint16,offset : uint8,value : int16) : void

    /**
     * Sets the [Object]'s scale/size to the given value.
     *
     * @param float scale
     */
    SetScale(size : float) : void

    /**
     * Sets the data at the specified index to the given value, converted to an unsigned 64-bit integer.
     *
     * @param uint16 index
     * @param uint64 value
     */
    SetUInt64Value(index : uint16,value : uint64) : void

    /**
     * Removes a flag from the value at the specified index.
     *
     * @param uint16 index
     * @param uint32 flag
     */
    RemoveFlag(index : uint16,flag : uint32) : void
    ToCorpse() : TSCorpse
    ToGameObject() : TSGameObject
    ToUnit() : TSUnit
    ToCreature() : TSCreature
    ToPlayer() : TSPlayer    
}

declare class TSUnit extends TSWorldObject {
    IsNull() : bool

    /**
     * The [Unit] tries to attack a given target
     *
     * @param [Unit] who : [Unit] to attack
     * @param bool meleeAttack = false: attack with melee or not
     * @return didAttack : if the [Unit] did not attack
     */
    Attack(who : TSUnit,meleeAttack : bool) : bool

    /**
     * The [Unit] stops attacking its target
     *
     * @return bool isAttacking : if the [Unit] wasn't attacking already
     */
    AttackStop() : bool

    /**
     * Returns true if the [Unit] is standing.
     *
     * @return bool isStanding
     */
    IsStandState() : bool

    /**
     * Returns true if the [Unit] is mounted.
     *
     * @return bool isMounted
     */
    IsMounted() : bool

    /**
     * Returns true if the [Unit] is rooted.
     *
     * @return bool isRooted
     */
    IsRooted() : bool

    /**
     * Returns true if the [Unit] has full health.
     *
     * @return bool hasFullHealth
     */
    IsFullHealth() : bool

    /**
     * Returns true if the [Unit] is in an accessible place for the given [Creature].
     *
     * @param [WorldObject] obj
     * @param float radius
     * @return bool isAccessible
     */
    IsInAccessiblePlaceFor(creature : TSCreature) : bool

    /**
     * Returns true if the [Unit] an auctioneer.
     *
     * @return bool isAuctioneer
     */
    IsAuctioneer() : bool

    /**
     * Returns true if the [Unit] a guild master.
     *
     * @return bool isGuildMaster
     */
    IsGuildMaster() : bool

    /**
     * Returns true if the [Unit] an innkeeper.
     *
     * @return bool isInnkeeper
     */
    IsInnkeeper() : bool

    /**
     * Returns true if the [Unit] a trainer.
     *
     * @return bool isTrainer
     */
    IsTrainer() : bool

    /**
     * Returns true if the [Unit] is able to show a gossip window.
     *
     * @return bool hasGossip
     */
    IsGossip() : bool

    /**
     * Returns true if the [Unit] is a taxi master.
     *
     * @return bool isTaxi
     */
    IsTaxi() : bool

    /**
     * Returns true if the [Unit] is a spirit healer.
     *
     * @return bool isSpiritHealer
     */
    IsSpiritHealer() : bool

    /**
     * Returns true if the [Unit] is a spirit guide.
     *
     * @return bool isSpiritGuide
     */
    IsSpiritGuide() : bool

    /**
     * Returns true if the [Unit] is a tabard designer.
     *
     * @return bool isTabardDesigner
     */
    IsTabardDesigner() : bool

    /**
     * Returns true if the [Unit] provides services like vendor, training and auction.
     *
     * @return bool isTabardDesigner
     */
    IsServiceProvider() : bool

    /**
     * Returns true if the [Unit] is a spirit guide or spirit healer.
     *
     * @return bool isSpiritService
     */
    IsSpiritService() : bool

    /**
     * Returns true if the [Unit] is alive.
     *
     * @return bool isAlive
     */
    IsAlive() : bool

    /**
     * Returns true if the [Unit] is dead.
     *
     * @return bool isDead
     */
    IsDead() : bool

    /**
     * Returns true if the [Unit] is dying.
     *
     * @return bool isDying
     */
    IsDying() : bool

    /**
     * Returns true if the [Unit] is a banker.
     *
     * @return bool isBanker
     */
    IsBanker() : bool

    /**
     * Returns true if the [Unit] is a vendor.
     *
     * @return bool isVendor
     */
    IsVendor() : bool

    /**
     * Returns true if the [Unit] is a battle master.
     *
     * @return bool isBattleMaster
     */
    IsBattleMaster() : bool

    /**
     * Returns true if the [Unit] is a charmed.
     *
     * @return bool isCharmed
     */
    IsCharmed() : bool

    /**
     * Returns true if the [Unit] is an armorer and can repair equipment.
     *
     * @return bool isArmorer
     */
    IsArmorer() : bool

    /**
     * Returns true if the [Unit] is attacking a player.
     *
     * @return bool isAttackingPlayer
     */
    IsAttackingPlayer() : bool

    /**
     * Returns true if the [Unit] flagged for PvP.
     *
     * @return bool isPvP
     */
    IsPvPFlagged() : bool

    /**
     * Returns true if the [Unit] is on a [Vehicle].
     *
     * @return bool isOnVehicle
     */
    IsOnVehicle() : bool

    /**
     * Returns true if the [Unit] is in combat.
     *
     * @return bool inCombat
     */
    IsInCombat() : bool

    /**
     * Returns true if the [Unit] is under water.
     *
     * @return bool underWater
     */
    IsUnderWater() : bool

    /**
     * Returns true if the [Unit] is in water.
     *
     * @return bool inWater
     */
    IsInWater() : bool

    /**
     * Returns true if the [Unit] is not moving.
     *
     * @return bool notMoving
     */
    IsStopped() : bool

    /**
     * Returns true if the [Unit] is a quest giver.
     *
     * @return bool questGiver
     */
    IsQuestGiver() : bool

    /**
     * Returns true if the [Unit]'s health is below the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isBelow
     */
    HealthBelowPct(pct : int32) : bool

    /**
     * Returns true if the [Unit]'s health is above the given percentage.
     *
     * @param int32 healthpct : percentage in integer from
     * @return bool isAbove
     */
    HealthAbovePct(pct : int32) : bool

    /**
     * Returns true if the [Unit] has an aura from the given spell entry.
     *
     * @param uint32 spell : entry of the aura spell
     * @return bool hasAura
     */
    HasAura(spell : uint32) : bool

    /**
     * Returns true if the [Unit] is casting a spell
     *
     * @return bool isCasting
     */
    IsCasting() : bool

    /**
     * Returns true if the [Unit] has the given unit state.
     *
     * @param [UnitState] state : an unit state
     * @return bool hasState
     */
    HasUnitState(state : uint32) : bool

    /**
     * Returns the [Unit]'s owner.
     *
     * @return [Unit] owner
     */
    GetOwner() : TSUnit

    /**
     * Returns the [Unit]'s owner's GUID.
     *
     * @return uint64 ownerGUID
     */
    GetOwnerGUID() : uint64

    /**
     * Returns the [Unit]'s mount's modelID.
     *
     * @return uint32 mountId : displayId of the mount
     */
    GetMountId() : uint32

    /**
     * Returns the [Unit]'s creator's GUID.
     *
     * @return uint64 creatorGUID
     */
    GetCreatorGUID() : uint64

    /**
     * Returns the [Unit]'s charmer's GUID.
     *
     * @return uint64 charmerGUID
     */
    GetCharmerGUID() : uint64

    /**
     * Returns the GUID of the [Unit]'s charmed entity.
     *
     * @return uint64 charmedGUID
     */
    GetCharmGUID() : uint64

    /**
     * Returns the GUID of the [Unit]'s pet.
     *
     * @return uint64 petGUID
     */
    GetPetGUID(index?: number) : uint64

    /**
     * Returns the GUID of the [Unit]'s charmer or owner.
     *
     * @return uint64 controllerGUID
     */
    GetControllerGUID() : uint64

    /**
     * Returns the GUID of the [Unit]'s charmer or owner or its own GUID.
     *
     * @return uint64 controllerGUID
     */
    GetControllerGUIDS() : uint64

    /**
     * Returns [Unit]'s specified stat
     *
     * @param uint32 statType
     * @return float stat
     */
    GetStat(stat : uint32) : float

    /**
     * Returns the [Unit]'s base spell power
     *
     * @param uint32 spellSchool
     * @return uint32 spellPower
     */
    GetBaseSpellPower(spellschool : uint32) : uint32

    /**
     * Returns the [Unit]'s current victim target or nil.
     *
     * @return [Unit] victim
     */
    GetVictim() : TSUnit

    /**
     * Returns the currently casted [Spell] of given type or nil.
     *
     *     enum CurrentSpellTypes
     *     {
     *         CURRENT_MELEE_SPELL             = 0,
     *         CURRENT_GENERIC_SPELL           = 1,
     *         CURRENT_CHANNELED_SPELL         = 2,
     *         CURRENT_AUTOREPEAT_SPELL        = 3
     *     }
     *
     * @param [CurrentSpellTypes] spellType
     * @return [Spell] castedSpell
     */
    GetCurrentSpell(type : uint32) : TSSpell

    /**
     * Returns the [Unit]'s current stand state.
     *
     * @return uint8 standState
     */
    GetStandState() : uint8

    /**
     * Returns the [Unit]'s current display ID.
     *
     * @return uint32 displayId
     */
    GetDisplayId() : uint32

    /**
     * Returns the [Unit]'s native/original display ID.
     *
     * @return uint32 displayId
     */
    GetNativeDisplayId() : uint32

    /**
     * Returns the [Unit]'s level.
     *
     * @return uint8 level
     */
    GetLevel() : uint8

    /**
     * Returns the [Unit]'s health amount.
     *
     * @return uint32 healthAmount
     */
    GetHealth() : uint32
    PowerSelectorHelper(unit : TSUnit,powerType : int) : uint32

    /**
     * Returns the [Unit]'s power amount for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 powerAmount
     */
    GetPower(type : int) : uint32

    /**
     * Returns the [Unit]'s max power amount for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return uint32 maxPowerAmount
     */
    GetMaxPower(type : int) : uint32

    /**
     * Returns the [Unit]'s power percent for given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @return float powerPct
     */
    GetPowerPct(type : int) : float

    /**
     * Returns the [Unit]'s current power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @return [Powers] powerType
     */
    GetPowerType() : uint32

    /**
     * Returns the [Unit]'s max health.
     *
     * @return uint32 maxHealth
     */
    GetMaxHealth() : uint32

    /**
     * Returns the [Unit]'s health percent.
     *
     * @return float healthPct
     */
    GetHealthPct() : float

    /**
     * Returns the [Unit]'s gender.
     *
     * @return uint8 gender : 0 for male, 1 for female and 2 for none
     */
    GetGender() : uint8

    /**
     * Returns the [Unit]'s race ID.
     *
     * @return [Races] race
     */
    GetRace() : uint32

    /**
     * Returns the [Unit]'s class ID.
     *
     * @return [Classes] class
     */
    GetClass() : uint32

    /**
    * Returns the race mask
    *
    * @return uint32 racemask
    */
    GetRaceMask() : uint32

    /**
    * Returns the class mask
    *
    * @return uint32 classmask
    */
    GetClassMask() : uint32

    /**
     * Returns the [Unit]'s creature type ID (enumerated in CreatureType.dbc).
     *
     *     enum CreatureType
     *     {
     *         CREATURE_TYPE_BEAST            = 1
     *         CREATURE_TYPE_DRAGONKIN        = 2
     *         CREATURE_TYPE_DEMON            = 3
     *         CREATURE_TYPE_ELEMENTAL        = 4
     *         CREATURE_TYPE_GIANT            = 5
     *         CREATURE_TYPE_UNDEAD           = 6
     *         CREATURE_TYPE_HUMANOID         = 7
     *         CREATURE_TYPE_CRITTER          = 8
     *         CREATURE_TYPE_MECHANICAL       = 9
     *         CREATURE_TYPE_NOT_SPECIFIED    = 10
     *         CREATURE_TYPE_TOTEM            = 11
     *         CREATURE_TYPE_NON_COMBAT_PET   = 12
     *         CREATURE_TYPE_GAS_CLOUD        = 13
     *     }
     *
     * @return [CreatureType] creatureType
     */
    GetCreatureType() : uint32

    /**
     * Returns the [Unit]'s class' name in given or default locale or nil.
     *
     *     enum LocaleConstant
     *     {
     *         LOCALE_enUS = 0,
     *         LOCALE_koKR = 1,
     *         LOCALE_frFR = 2,
     *         LOCALE_deDE = 3,
     *         LOCALE_zhCN = 4,
     *         LOCALE_zhTW = 5,
     *         LOCALE_esES = 6,
     *         LOCALE_esMX = 7,
     *         LOCALE_ruRU = 8
     *     }
     *
     * @param [LocaleConstant] locale = DEFAULT_LOCALE
     * @return string className : class name or nil
     */
    GetClassAsString(locale : uint8) : string

    /**
     * Returns the [Unit]'s race's name in given or default locale or nil.
     *
     *     enum LocaleConstant
     *     {
     *         LOCALE_enUS = 0,
     *         LOCALE_koKR = 1,
     *         LOCALE_frFR = 2,
     *         LOCALE_deDE = 3,
     *         LOCALE_zhCN = 4,
     *         LOCALE_zhTW = 5,
     *         LOCALE_esES = 6,
     *         LOCALE_esMX = 7,
     *         LOCALE_ruRU = 8
     *     }
     * @param [LocaleConstant] locale = DEFAULT_LOCALE : locale to return the race name in
     * @return string raceName : race name or nil
     */
    GetRaceAsString(locale : uint8) : string

    /**
     * Returns the [Unit]'s faction ID.
     *
     * @return uint32 faction
     */
    GetFaction() : uint32

    /**
     * Returns the [Aura] of the given spell entry on the [Unit] or nil.
     *
     * @param uint32 spellID : entry of the aura spell
     * @return [Aura] aura : aura object or nil
     */
    GetAura(spellID : uint32) : TSAura

    /**
     * Returns [Unit]'s [Vehicle] methods
     *
     * @return [Vehicle] vehicle
     */
    GetVehicleKit() : TSVehicle
    GetVehicle() : TSVehicle

    /**
     * Returns the Critter Guid
     *
     * @return uint64 critterGuid
     */
    GetCritterGUID() : uint64

    /**
     * Returns the [Unit]'s speed of given [UnitMoveType].
     *
     *     enum UnitMoveType
     *     {
     *         MOVE_WALK           = 0,
     *         MOVE_RUN            = 1,
     *         MOVE_RUN_BACK       = 2,
     *         MOVE_SWIM           = 3,
     *         MOVE_SWIM_BACK      = 4,
     *         MOVE_TURN_RATE      = 5,
     *         MOVE_FLIGHT         = 6,
     *         MOVE_FLIGHT_BACK    = 7,
     *         MOVE_PITCH_RATE     = 8
     *     }
     *
     * @param [UnitMoveType] type
     * @return float speed
     */
    GetSpeed(type : uint32) : float

    /**
     * Returns the current movement type for this [Unit].
     *
     * enum MovementGeneratorType
     * {
     *     IDLE_MOTION_TYPE                = 0,
     *     RANDOM_MOTION_TYPE              = 1,
     *     WAYPOINT_MOTION_TYPE            = 2,
     *     MAX_DB_MOTION_TYPE              = 3,
     *     ANIMAL_RANDOM_MOTION_TYPE       = 3, // TC
     * 
     *     CONFUSED_MOTION_TYPE            = 4,
     *     CHASE_MOTION_TYPE               = 5,
     *     HOME_MOTION_TYPE                = 6,
     *     FLIGHT_MOTION_TYPE              = 7,
     *     POINT_MOTION_TYPE               = 8,
     *     FLEEING_MOTION_TYPE             = 9,
     *     DISTRACT_MOTION_TYPE            = 10,
     *     ASSISTANCE_MOTION_TYPE          = 11,
     *     ASSISTANCE_DISTRACT_MOTION_TYPE = 12,          
     *     TIMED_FLEEING_MOTION_TYPE       = 13,
     *     FOLLOW_MOTION_TYPE              = 14,
     *     EFFECT_MOTION_TYPE              = 15, // mangos
     *     ROTATE_MOTION_TYPE              = 15, // TC
     *     EFFECT_MOTION_TYPE              = 16, // TC
     *     NULL_MOTION_TYPE                = 17, // TC
     * }
     *
     * @return [MovementGeneratorType] movementType
     */
    GetMovementType() : uint32

    /**
     * Sets the [Unit]'s owner GUID to given GUID.
     *
     * @param uint64 guid : new owner guid
     */
    SetOwnerGUID(guid : uint64) : void

    /**
     * Sets the [Unit]'s PvP on or off.
     *
     * @param bool apply = true : true if set on, false if off
     */
    SetPvP(apply : bool) : void

    /**
     * Sets the [Unit]'s sheath state.
     *
     *     enum SheathState
     *     {
     *         SHEATH_STATE_UNARMED  = 0, // non prepared weapon
     *         SHEATH_STATE_MELEE    = 1, // prepared melee weapon
     *         SHEATH_STATE_RANGED   = 2  // prepared ranged weapon
     *
     * @param [SheathState] sheathState : valid SheathState
     */
    SetSheath(sheathed : uint32) : void

    /**
     * Sets the [Unit]'s name internally.
     *
     * @param string name : new name
     */
    SetName(name : string) : void

    /**
     * Sets the [Unit]'s speed of given [UnitMoveType] to given rate.
     * If forced, packets sent to clients forcing the visual change.
     *
     *     enum UnitMoveType
     *     {
     *         MOVE_WALK           = 0,
     *         MOVE_RUN            = 1,
     *         MOVE_RUN_BACK       = 2,
     *         MOVE_SWIM           = 3,
     *         MOVE_SWIM_BACK      = 4,
     *         MOVE_TURN_RATE      = 5,
     *         MOVE_FLIGHT         = 6,
     *         MOVE_FLIGHT_BACK    = 7,
     *         MOVE_PITCH_RATE     = 8
     *     }
     * @param [UnitMoveType] type
     * @param float rate
     * @param bool forced = false
     */
    SetSpeed(type : uint32,rate : float,forced : bool) : void

    /**
     * Sets the [Unit]'s faction.
     *
     * @param uint32 faction : new faction ID
     */
    SetFaction(factionId : uint32) : void

    /**
     * Sets the [Unit]'s level.
     *
     * @param uint8 level : new level
     */
    SetLevel(newlevel : uint8) : void

    /**
     * Sets the [Unit]'s health.
     *
     * @param uint32 health : new health
     */
    SetHealth(amt : uint32) : void

    /**
     * Sets the [Unit]'s max health.
     *
     * @param uint32 maxHealth : new max health
     */
    SetMaxHealth(amt : uint32) : void

    /**
     * Sets the [Unit]'s power amount for the given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param uint32 amount : new power amount
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     */
    SetPower(amt : uint32,type : int) : void

    /**
     * modifies the [Unit]'s power amount for the given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param int32 amount : amount to modify
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     */
    ModifyPower(amt : int32,type : int) : void

    /**
     * Sets the [Unit]'s max power amount for the given power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param int type = -1 : a valid power type from [Powers] or -1 for the [Unit]'s current power type
     * @param uint32 maxPower : new max power amount
     */
    SetMaxPower(type : int,amt : uint32) : void

    /**
     * Sets the [Unit]'s power type.
     *
     *     enum Powers
     *     {
     *         POWER_MANA        = 0,
     *         POWER_RAGE        = 1,
     *         POWER_FOCUS       = 2,
     *         POWER_ENERGY      = 3,
     *         POWER_HAPPINESS   = 4,
     *         POWER_RUNE        = 5,
     *         POWER_RUNIC_POWER = 6,
     *         MAX_POWERS        = 7,
     *         POWER_ALL         = 127,         // default for class?
     *         POWER_HEALTH      = 0xFFFFFFFE   // (-2 as signed value)
     *
     * @param [Powers] type : a valid power type
     */
    SetPowerType(type : uint32) : void

    /**
     * Sets the [Unit]'s modelID.
     *
     * @param uint32 displayId
     */
    SetDisplayId(model : uint32) : void

    /**
     * Sets the [Unit]'s native/default modelID.
     *
     * @param uint32 displayId
     */
    SetNativeDisplayId(model : uint32) : void

    /**
     * Sets the [Unit]'s facing/orientation.
     *
     * @param uint32 orientation
     */
    SetFacing(o : float) : void

    /**
     * Sets the [Unit] to face the given [WorldObject]'s direction.
     *
     * @param [WorldObject] target
     */
    SetFacingToObject(obj : TSWorldObject) : void

    /**
     * Sets creator GUID
     *
     * @param uint64 guid
     */
    SetCreatorGUID(guid : uint64) : void

    /**
     * Sets pet GUID
     *
     * @param uint64 guid
     */
    SetPetGUID(guid : uint64) : void

    /**
     * Toggles (Sets) [Unit]'s water walking
     *
     * @param bool enable = true
     */
    SetWaterWalk(enable : bool) : void

    /**
     * Sets the [Unit]'s stand state
     *
     * @param uint8 state : stand state
     */
    SetStandState(state : uint8) : void

    /**
     * Sets the [Unit]'s FFA flag on or off.
     *
     * @param bool apply = true
     */
    SetFFA(apply : bool) : void

    /**
     * Sets the [Unit]'s sanctuary flag on or off.
     *
     * @param bool apply = true
     */
    SetSanctuary(apply : bool) : void
    SetCritterGUID(guid : uint64) : void

    /**
     * Roots the [Unit] to the ground, if 'false' specified, unroots the [Unit].
     *
     * @param bool apply = true
     */
    SetRooted(apply : bool) : void

    /**
     * Confuses the [Unit], if 'false' specified, the [Unit] is no longer confused.
     *
     * @param bool apply = true
     */
    SetConfused(apply : bool) : void

    /**
     * Fears the [Unit], if 'false' specified, the [Unit] is no longer feared.
     *
     * @param bool apply = true
     */
    SetFeared(apply : bool) : void

    /**
     * Clears the [Unit]'s threat list.
     */
    ClearThreatList(apply : bool,x : bool) : void

    /**
     * Mounts the [Unit] on the given displayID/modelID.
     *
     * @param uint32 displayId
     */
    Mount(displayId : uint32) : void

    /**
     * Dismounts the [Unit].
     */
    Dismount() : void
    Emote(emoteId : uint32) : void

    /**
     * Makes the [Unit] perform the given emote continuously.
     *
     * @param uint32 emoteId
     */
    EmoteState(emoteId : uint32) : void

    /**
     * Returns calculated percentage from Health
     *
     * @return int32 percentage
     */
    CountPctFromCurHealth(health : int32) : int32

    /**
     * Returns calculated percentage from Max Health
     *
     * @return int32 percentage
     */
    CountPctFromMaxHealth(health : int32) : int32

    /**
     * Sends chat message to [Player]
     *
     * @param uint8 type : chat, whisper, etc
     * @param uint32 lang : language to speak
     * @param string msg
     * @param [Player] target
     */
    SendChatMessageToPlayer(type : uint8,lang : uint32,msg : string,target : TSPlayer) : void
    PrepareMove() : void

    /**
     * Stops the [Unit]'s movement
     */
    MoveStop() : void

    /**
     * The [Unit]'s movement expires and clears movement
     *
     * @param bool reset = true : cleans movement
     */
    MoveExpire(reset : bool) : void

    /**
     * Clears the [Unit]'s movement
     *
     * @param bool reset = true : clean movement
     */
    MoveClear(reset : bool) : void

    /**
     * The [Unit] will be idle
     */
    MoveIdle() : void

    /**
     * The [Unit] will move at random
     *
     * @param float radius : limit on how far the [Unit] will move at random
     */
    MoveRandom(radius : float) : void

    /**
     * The [Unit] will move to its set home location
     */
    MoveHome() : void

    /**
     * The [Unit] will follow the target
     *
     * @param [Unit] target : target to follow
     * @param float dist = 0 : distance to start following
     * @param float angle = 0
     */
    MoveFollow(target : TSUnit,dist : float,angle : float) : void

    /**
     * The [Unit] will chase the target
     *
     * @param [Unit] target : target to chase
     * @param float dist = 0 : distance start chasing
     * @param float angle = 0
     */
    MoveChase(target : TSUnit,dist : float,angle : float) : void

    /**
     * The [Unit] will move confused
     */
    MoveConfused() : void

    /**
     * The [Unit] will flee
     *
     * @param [Unit] target
     * @param uint32 time = 0 : flee delay
     */
    MoveFleeing(target : TSUnit,time : uint32) : void

    /**
     * The [Unit] will move to the coordinates
     *
     * @param uint32 id : unique waypoint Id
     * @param float x
     * @param float y
     * @param float z
     * @param bool genPath = true : if true, generates path
     */
    MoveTo(id : uint32,x : float,y : float,z : float,genPath : bool) : void

    /**
     * Makes the [Unit] jump to the coordinates
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float zSpeed : start velocity
     * @param float maxHeight : maximum height
     * @param uint32 id = 0 : unique movement Id
     */
    MoveJump(x : float,y : float,z : float,zSpeed : float,maxHeight : float,id : uint32) : void

    /**
     * The [Unit] will whisper the message to a [Player]
     *
     * @param string msg : message for the [Unit] to emote
     * @param uint32 lang : language for the [Unit] to speak
     * @param [Player] receiver : specific [Unit] to receive the message
     * @param bool bossWhisper = false : is a boss whisper
     */
    SendUnitWhisper(msg : string,lang : uint32,receiver : TSPlayer,bossWhisper : bool) : void

    /**
     * The [Unit] will emote the message
     *
     * @param string msg : message for the [Unit] to emote
     * @param [Unit] receiver = nil : specific [Unit] to receive the message
     * @param bool bossEmote = false : is a boss emote
     */
    SendUnitEmote(msg : string,receiver : TSUnit,bossEmote : bool) : void

    /**
     * The [Unit] will say the message
     *
     * @param string msg : message for the [Unit] to say
     * @param uint32 language : language for the [Unit] to speak
     */
    SendUnitSay(msg : string,language : uint32) : void

    /**
     * The [Unit] will yell the message
     *
     * @param string msg : message for the [Unit] to yell
     * @param uint32 language : language for the [Unit] to speak
     */
    SendUnitYell(msg : string,language : uint32) : void

    /**
     * Unmorphs the [Unit] setting it's display ID back to the native display ID.
     */
    DeMorph() : void

    /**
     * Makes the [Unit] cast the spell on the target.
     *
     * @param [Unit] target = nil : can be self or another unit
     * @param uint32 spell : entry of a spell
     * @param bool triggered = false : if true the spell is instant and has no cost
     */
    CastSpell(target : TSUnit,spell : uint32,triggered : bool) : void

    /**
     * Casts the [Spell] at target [Unit] with custom basepoints or casters.
     * See also [Unit:CastSpell].
     *
     * @param [Unit] target = nil
     * @param uint32 spell
     * @param bool triggered = false
     * @param int32 bp0 = nil : custom basepoints for [Spell] effect 1. If nil, no change is made
     * @param int32 bp1 = nil : custom basepoints for [Spell] effect 2. If nil, no change is made
     * @param int32 bp2 = nil : custom basepoints for [Spell] effect 3. If nil, no change is made
     * @param [Item] castItem = nil
     * @param uint64 originalCaster = 0
     */
    CastCustomSpell(target : TSUnit,spell : uint32,triggered : bool,bp0 : int32,bp1 : int32,bp2 : int32,castItem : TSItem,originalCaster : uint64) : void

    /**
     * Makes the [Unit] cast the spell to the given coordinates, used for area effect spells.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param uint32 spell : entry of a spell
     * @param bool triggered = false : if true the spell is instant and has no cost
     */
    CastSpellAoF(_x : float,_y : float,_z : float,spell : uint32,triggered : bool) : void

    /**
     * Clears the [Unit]'s combat
     */
    ClearInCombat() : void

    /**
     * Stops the [Unit]'s current spell cast
     *
     * @param uint32 spell = 0 : entry of a spell
     */
    StopSpellCast(spellId : uint32) : void

    /**
     * Interrupts [Unit]'s spell state, casting, etc.
     *
     * if spell is not interruptible, it will return
     *
     * @param int32 spellType : type of spell to interrupt
     * @param bool delayed = true : skips if the spell is delayed
     */
    InterruptSpell(spellType : int,delayed : bool) : void

    /**
     * Adds the [Aura] of the given spell entry on the given target from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     * @param [Unit] target : aura will be applied on the target
     * @return [Aura] aura
     */
    AddAura(spell : uint32,target : TSUnit) : TSAura

    /**
     * Removes [Aura] of the given spell entry from the [Unit].
     *
     * @param uint32 spell : entry of a spell
     */
    RemoveAura(spellId : uint32) : void

    /**
     * Removes all [Aura]'s from the [Unit].
     *
     *     Note: talents and racials are also auras, use with caution
     */
    RemoveAllAuras() : void

    /**
     * Adds the given unit state for the [Unit].
     *
     * @param [UnitState] state
     */
    AddUnitState(state : uint32) : void

    /**
     * Removes the given unit state from the [Unit].
     *
     * @param [UnitState] state
     */
    ClearUnitState(state : uint32) : void

    /**
     * Makes the [Unit] teleport to given coordinates within same map.
     *
     * @param float x
     * @param float y
     * @param float z
     * @param float o : orientation
     */
    NearTeleport(x : float,y : float,z : float,o : float) : void

    /**
     * Makes the [Unit] damage the target [Unit]
     *
     *     enum SpellSchools
     *     {
     *         SPELL_SCHOOL_NORMAL  = 0,
     *         SPELL_SCHOOL_HOLY    = 1,
     *         SPELL_SCHOOL_FIRE    = 2,
     *         SPELL_SCHOOL_NATURE  = 3,
     *         SPELL_SCHOOL_FROST   = 4,
     *         SPELL_SCHOOL_SHADOW  = 5,
     *         SPELL_SCHOOL_ARCANE  = 6,
     *         MAX_SPELL_SCHOOL     = 7
     *      }
     *
     * @param [Unit] target : [Unit] to damage
     * @param uint32 damage : amount to damage
     * @param bool durabilityloss = true : if false, the damage does not do durability damage
     * @param [SpellSchools] school = MAX_SPELL_SCHOOL : school the damage is done in or MAX_SPELL_SCHOOL for direct damage
     * @param uint32 spell = 0 : spell that inflicts the damage
     */
    DealDamage(target : TSUnit,damage : uint32,durabilityloss : bool,school : uint32,spell : uint32) : void

    /**
     * Makes the [Unit] heal the target [Unit] with given spell
     *
     * @param [Unit] target : [Unit] to heal
     * @param uint32 spell : spell that causes the healing
     * @param uint32 amount : amount to heal
     * @param bool critical = false : if true, heal is logged as critical
     */
    DealHeal(target : TSUnit,spell : uint32,amount : uint32,critical : bool) : void

    /**
     * Makes the [Unit] kill the target [Unit]
     *
     * @param [Unit] target : [Unit] to kill
     * @param bool durLoss = true : when true, the target's items suffer durability loss
     */
    Kill(target : TSUnit,durLoss : bool) : void

    /**
     * Adds threat to the [Unit] from the victim.
     *
     *     enum SpellSchoolMask
     *     {
     *         SPELL_SCHOOL_MASK_NONE    = 0,
     *         SPELL_SCHOOL_MASK_NORMAL  = 1,
     *         SPELL_SCHOOL_MASK_HOLY    = 2,
     *         SPELL_SCHOOL_MASK_FIRE    = 4,
     *         SPELL_SCHOOL_MASK_NATURE  = 8,
     *         SPELL_SCHOOL_MASK_FROST   = 16,
     *         SPELL_SCHOOL_MASK_SHADOW  = 32,
     *         SPELL_SCHOOL_MASK_ARCANE  = 64,
     *     }
     *
     * @param [Unit] victim : [Unit] that caused the threat
     * @param float threat : threat amount
     * @param [SpellSchoolMask] schoolMask = 0 : [SpellSchoolMask] of the threat causer
     * @param uint32 spell = 0 : spell entry used for threat
     */
    AddThreat(victim : TSUnit,threat : float,spell : uint32,schoolMask : uint32) : void    
}

declare class TSItemTemplate {
    IsNull() : bool
    Id() : uint32;
}

declare class TSSpellInfo {
    IsNull() : bool
    ID() : uint32;
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
        OnSay(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : TSMutableString)=>void);
        OnWhisper(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : TSMutableString,receiver : TSPlayer)=>void);
        OnChatGroup(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : TSMutableString,group : TSGroup)=>void);
        OnChatGuild(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : TSMutableString,guild : TSGuild)=>void);
        OnChat(callback: (player : TSPlayer,type : uint32,lang : uint32,msg : TSMutableString,channel : TSChatChannel)=>void);
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
        OnSendMail(callback: (player: TSPlayer, draft: TSMailDraft, delay: TSMutable<uint32>)=>void);
        OnGenerateItemLoot(callback: (player: TSPlayer, item: TSItem, loot: TSLoot, type: uint32)=>void);
        OnLootCorpse(callback: (player: TSPlayer, corpse: TSCorpse)=>void);
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

    export class SpellID {
        OnCast(spell: uint32, callback : (spell: TSSpell)=>void);
        OnDispel(spell: uint32, callback: (spell: TSSpell, dispelType: uint32)=>void);
        OnHit(spell: uint32, callback: (spell: TSSpell)=>void);
        OnTick(spell: uint32, callback: (effect: TSAuraEffect)=>void);
        OnRemove(spell: uint32, callback: (effect: TSAuraEffect, application: TSAuraApplication, type: uint32)=>void);
    }

    export class Spells {
        OnCast(callback : (spell: TSSpell)=>void);
        OnDispel(callback: (spell: TSSpell, dispelType: uint32)=>void);
        OnHit(callback: (spell: TSSpell)=>void);
        OnTick(callback: (effect: TSAuraEffect)=>void);
        OnRemove(callback: (effect: TSAuraEffect, application: TSAuraApplication, type: uint32)=>void);
    }

    export class CreatureID {
        OnGenerateLoot(creature: uint32, callback: (creature: TSCreature, killer: TSPlayer)=>void);
        OnMoveInLOS(creature: uint32, callback: (creature: TSCreature, seen: TSUnit)=>void);
        OnJustEnteredCombat(creature: uint32, callback: (creature: TSCreature, target: TSUnit)=>void);
        OnDeath(creature: uint32, callback: (creature: TSCreature, killer: TSUnit)=>void);
        OnKilledUnit(creature: uint32, callback: (creature: TSCreature, killed: TSUnit)=>void);
        OnSummoned(creature: uint32, callback: (creature: TSCreature, summon: TSCreature)=>void);
        OnIsSummoned(creature: uint32, callback: (creature: TSCreature, summoner: TSWorldObject)=>void);
        OnSummonDespawn(creature: uint32, callback: (creature: TSCreature, summon: TSCreature)=>void);
        OnSummonDies(creature: uint32, callback: (creature: TSCreature, summon: TSCreature, killer: TSUnit)=>void);
        OnHitBySpell(creature: uint32, callback: (creature: TSCreature, caster: TSWorldObject, spellInfo: TSSpellInfo)=>void);
        OnSpellHitTarget(creature: uint32, callback: (creature: TSCreature, target: TSWorldObject, spellInfo: TSSpellInfo)=>void);
        OnSpellCastFinished(creature: uint32, callback: (creature: TSCreature, spellInfo: TSSpellInfo, reason: uint32)=>void);
        OnJustAppeared(creature: uint32, callback: (creature: TSCreature)=>void);
        OnCharmed(creature: uint32, callback: (creature: TSCreature, isNew: boolean)=>void);
        OnReachedHome(creature: uint32, callback: (creature: TSCreature)=>void);
        OnReceiveEmote(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, emote: uint32)=>void);
        OnOwnerAttacked(creature: uint32, callback: (creature: TSCreature, attacker: TSUnit)=>void);
        OnOwnerAttacks(creature: uint32, callback: (creature: TSCreature, target: TSUnit)=>void);
        OnCorpseRemoved(creature: uint32, callback: (creature: TSCreature, delay: uint32)=>void);

        OnCreate(creature: uint32, callback: (creature: TSCreature, cancel: TSMutable<boolean>)=>void)
        OnRemove(creature: uint32, callback: (creature: TSCreature)=>void)

        OnWaypointStarted(creature: uint32, callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnWaypointReached(creature: uint32, callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnWaypointPathEnded(creature: uint32, callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnPassengerBoarded(creature: uint32, callback: (creature: TSCreature, passenger: TSUnit, seatId: int8, isFirst: boolean)=>void);

        OnSpellClick(creature: uint32, callback: (creature: TSCreature, clicker: TSUnit, isFirst: boolean)=>void);
        OnUpdateAI(creature: uint32, callback: (creature: TSCreature, diff: uint32)=>void);

        OnGossipHello(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, cancel: TSMutable<bool>)=>void)
        OnGossipSelect(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, menuId: number, selectionId: number, cancel: TSMutable<bool>)=>void)
        OnGossipSelectCode(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, menuId: number, selectionId: number, code: string, cancel: TSMutable<bool>)=>void)
        OnQuestAccept(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, quest: TSQuest)=>void)
        OnQuestReward(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, quest: TSQuest, selection: uint32)=>void)
        /**
         * NOTE: Only use this event to enable pickpocket loot
         * Use "CreatureOnGeneratePickPocketLoot" to actually generate loot
         */
        OnCanGeneratePickPocketLoot(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, canGenerate: TSMutable<bool>)=>void)
        /**
         * NOTE: You may need to also call "OnCanGeneratePickPocketLoot" if this doesn't fire for your specific creature
         */
        OnGeneratePickPocketLoot(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, loot: TSLoot)=>void)
        OnGenerateSkinningLoot(creature: uint32, callback: (creature: TSCreature, player: TSPlayer, loot: TSLoot)=>void)
    }

    export class Creatures {
        OnGenerateLoot(callback: (creature: TSCreature, killer: TSPlayer)=>void);
        OnMoveInLOS(callback: (creature: TSCreature, seen: TSUnit)=>void);
        OnJustEnteredCombat(callback: (creature: TSCreature, target: TSUnit)=>void);
        OnDeath(callback: (creature: TSCreature, killer: TSUnit)=>void);
        OnKilledUnit(callback: (creature: TSCreature, killed: TSUnit)=>void);
        OnSummoned(callback: (creature: TSCreature, summon: TSCreature)=>void);
        OnIsSummoned(callback: (creature: TSCreature, summoner: TSWorldObject)=>void);
        OnSummonDespawn(callback: (creature: TSCreature, summon: TSCreature)=>void);
        OnSummonDies(callback: (creature: TSCreature, summon: TSCreature, killer: TSUnit)=>void);
        OnHitBySpell(callback: (creature: TSCreature, caster: TSWorldObject, spellInfo: TSSpellInfo)=>void);
        OnSpellHitTarget(callback: (creature: TSCreature, target: TSWorldObject, spellInfo: TSSpellInfo)=>void);
        OnSpellCastFinished(callback: (creature: TSCreature, spellInfo: TSSpellInfo, reason: uint32)=>void);
        OnJustAppeared(callback: (creature: TSCreature)=>void);
        OnCharmed(callback: (creature: TSCreature, isNew: boolean)=>void);
        OnReachedHome(callback: (creature: TSCreature)=>void);
        OnReceiveEmote(callback: (creature: TSCreature, player: TSPlayer, emote: uint32)=>void);
        OnOwnerAttacked(callback: (creature: TSCreature, attacker: TSUnit)=>void);
        OnOwnerAttacks(callback: (creature: TSCreature, target: TSUnit)=>void);
        OnCorpseRemoved(callback: (creature: TSCreature, delay: uint32)=>void);

        OnWaypointStarted(callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnWaypointReached(callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnWaypointPathEnded(callback: (creature: TSCreature, id: uint32, path: uint32)=>void);
        OnPassengerBoarded(callback: (creature: TSCreature, passenger: TSUnit, seatId: int8, isFirst: boolean)=>void);

        OnSpellClick(callback: (creature: TSCreature, clicker: TSUnit, isFirst: boolean)=>void);
        OnUpdateAI(callback: (creature: TSCreature, diff: uint32)=>void);

        OnGossipHello(callback: (creature: TSCreature, player: TSPlayer, cancel: TSMutable<bool>)=>void)
        OnGossipSelect(callback: (creature: TSCreature, player: TSPlayer, menuId: number, selectionId: number, cancel: TSMutable<bool>)=>void)
        OnGossipSelectCode(callback: (creature: TSCreature, player: TSPlayer, menuId: number, selectionId: number, code: string, cancel: TSMutable<bool>)=>void)

        OnQuestAccept(callback: (creature: TSCreature, player: TSPlayer, quest: TSQuest)=>void)
        OnQuestReward(callback: (creature: TSCreature, player: TSPlayer, quest: TSQuest, selection: uint32)=>void)
        /**
         * NOTE: Only use this event to enable pickpocket loot
         * Use "CreatureOnGeneratePickPocketLoot" to actually generate loot
         */
        OnCanGeneratePickPocketLoot(callback: (creature: TSCreature, player: TSPlayer, canGenerate: TSMutable<bool>)=>void)
        /**
         * NOTE: You may need to also call "OnCanGeneratePickPocketLoot" if this doesn't fire for your specific creature
         */
        OnGeneratePickPocketLoot(callback: (creature: TSCreature, player: TSPlayer, loot: TSLoot)=>void)
        OnGenerateSkinningLoot(callback: (creature: TSCreature, player: TSPlayer, loot: TSLoot)=>void)
    }

    export class Items {
        OnUse(callback: (item: TSItem, player: TSPlayer, reserved: void, cancel: TSMutable<boolean>)=>void)
        OnExpire(callback: (template: TSItemTemplate, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnRemove(callback: (item: TSItem, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnCastSpell(callback: (item: TSItem, player: TSPlayer, unit: TSUnit, spell: TSSpellInfo, cancel: TSMutable<boolean>)=>void)
        OnQuestAccept(callback: (item: TSItem, player: TSPlayer, quest: TSQuest)=>void)
        OnGossipHello(callback: (item: TSItem, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnGossipSelect(callback: (item: TSItem, player: TSPlayer, menuId: uint32, selectionId: uint32, cancel: TSMutable<boolean>)=>void)
        OnGossipSelectCode(callback: (item: TSItem, player: TSPlayer, menuId: uint32, selectionId: uint32, text: string, cancel: TSMutable<boolean>)=>void)
    }

    export class ItemID {
        OnUse(callback: (item: TSItem, player: TSPlayer, reserved: void, cancel: TSMutable<boolean>)=>void)
        OnExpire(callback: (template: TSItemTemplate, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnRemove(callback: (item: TSItem, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnCastSpell(callback: (item: TSItem, player: TSPlayer, unit: TSUnit, spell: TSSpellInfo, cancel: TSMutable<boolean>)=>void)
        OnQuestAccept(callback: (item: TSItem, player: TSPlayer, quest: TSQuest)=>void)
        OnGossipHello(callback: (item: TSItem, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnGossipSelect(callback: (item: TSItem, player: TSPlayer, menuId: uint32, selectionId: uint32, cancel: TSMutable<boolean>)=>void)
        OnGossipSelectCode(callback: (item: TSItem, player: TSPlayer, menuId: uint32, selectionId: uint32, text: string, cancel: TSMutable<boolean>)=>void)
    }

    export class GameObjects {
        OnUpdate(callback: (obj: TSGameObject, diff: uint32)=>void)
        OnDialogStatus(callback: (obj: TSGameObject, player: TSPlayer)=>void)
        OnDestroyed(callback: (obj: TSGameObject, destroyer: TSWorldObject)=>void)
        OnDamaged(callback: (obj: TSGameObject, damagerOrHealer: TSWorldObject)=>void)
        OnLootStateChanged(callback: (obj: TSGameObject, state: uint32, changer: TSUnit)=>void)
        OnGOStateChanged(callback: (obj: TSGameObject, state: uint32)=>void)
        OnGossipHello(callback: (obj: TSGameObject, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnGossipSelect(callback: (obj:TSGameObject, player: TSPlayer, menuId: uint32, selection: uint32, cancel: TSMutable<boolean>)=>void)
        OnGossipSelectCode(callback: (obj:TSGameObject, player: TSPlayer, menuId: uint32, selection: uint32, text: string, cancel: TSMutable<boolean>)=>void)
        OnCreate(callback: (obj: TSGameObject, cancel: TSMutable<boolean>)=>void)
        OnRemove(callback: (obj: TSGameObject)=>void)
        OnUse(callback: (obj: TSGameObject, user: TSUnit, cancel: TSMutable<boolean>)=>void)
        OnQuestAccept(callback: (obj: TSGameObject, player: TSPlayer, quest: TSQuest)=>void)
        OnGenerateLoot(callback: (obj: TSGameObject, player: TSPlayer)=>void)
        OnGenerateFishLoot(callback: (obj: TSGameObject, player: TSPlayer, loot: TSLoot, isJunk: bool)=>void)
    }

    export class GameObejctID {
        OnUpdate(obj: uint32, callback: (obj: TSGameObject, diff: uint32)=>void)
        OnDialogStatus(obj: uint32, callback: (obj: TSGameObject, player: TSPlayer)=>void)
        OnDestroyed(obj: uint32, callback: (obj: TSGameObject, destroyer: TSWorldObject)=>void)
        OnDamaged(obj: uint32, callback: (obj: TSGameObject, damagerOrHealer: TSWorldObject)=>void)
        OnLootStateChanged(obj: uint32, callback: (obj: TSGameObject, state: uint32, changer: TSUnit)=>void)
        OnGOStateChanged(obj: uint32, callback: (obj: TSGameObject, state: uint32)=>void)
        OnGossipHello(obj: uint32, callback: (obj: TSGameObject, player: TSPlayer, cancel: TSMutable<boolean>)=>void)
        OnGossipSelect(obj: uint32, callback: (obj:TSGameObject, player: TSPlayer, menuId: uint32, selection: uint32, cancel: TSMutable<boolean>)=>void)
        OnGossipSelectCode(obj: uint32, callback: (obj:TSGameObject, player: TSPlayer, menuId: uint32, selection: uint32, text: string, cancel: TSMutable<boolean>)=>void)
        OnCreate(obj: uint32, callback: (obj: TSGameObject, cancel: TSMutable<boolean>)=>void)
        OnRemove(obj: uint32, callback: (obj: TSGameObject)=>void)
        OnUse(obj: uint32, callback: (obj: TSGameObject, user: TSUnit, cancel: TSMutable<boolean>)=>void)
        OnQuestAccept(obj: uint32, callback: (obj: TSGameObject, player: TSPlayer, quest: TSQuest)=>void)
    }

    export class Maps {
        OnCreate(callback: (map: TSMap)=>void)
        OnUpdate(callback: (map: TSMap, diff: uint32)=>void)
        OnPlayerEnter(callback: (map: TSMap, player: TSPlayer)=>void)
        OnPlayerLeave(callback: (map: TSMap, player: TSPlayer)=>void)
        OnCreatureCreate(callback: (map: TSMap, creature: TSCreature, cancel: TSMutable<bool>)=>void)
        OnCreatureRemove(callback: (map: TSMap, creature: TSCreature)=>void)

        OnGameObjectCreate(callback: (map: TSMap, obj: TSGameObject, cancel: TSMutable<bool>)=>void)
        OnGameObjectRemove(callback: (map: TSMap, obj: TSGameObject)=>void)
        OnCheckEncounter(callback: (map: TSMap, player: TSPlayer)=>void)
    }

    export class MapID {
        OnCreate(map: uint32, callback: (map: TSMap)=>void)
        OnUpdate(map: uint32, callback: (map: TSMap, diff: uint32)=>void)
        OnPlayerEnter(map: uint32, callback: (map: TSMap, player: TSPlayer)=>void)
        OnPlayerLeave(map: uint32, callback: (map: TSMap, player: TSPlayer)=>void)
        OnCreatureCreate(map: uint32, callback: (map: TSMap, creature: TSCreature, cancel: TSMutable<bool>)=>void)
        OnCreatureRemove(map: uint32, callback: (map: TSMap, creature: TSCreature)=>void)

        OnGameObjectCreate(map: uint32, callback: (map: TSMap, obj: TSGameObject, cancel: TSMutable<bool>)=>void)
        OnGameObjectRemove(map: uint32, callback: (map: TSMap, obj: TSGameObject)=>void)
        OnCheckEncounter(map: uint32, callback: (map: TSMap, player: TSPlayer)=>void)
    }

    export class AuctionHouse {
        OnAuctionAdd(callback: (obj: TSAuctionHouseObject, entry: TSAuctionEntry)=>void);
        OnAuctionRemove(callback: (obj: TSAuctionHouseObject, entry: TSAuctionEntry)=>void);
        OnAuctionSuccessful(callback: (obj: TSAuctionHouseObject, entry: TSAuctionEntry)=>void);
        OnAuctionExpire(callback: (obj: TSAuctionHouseObject, entry: TSAuctionEntry)=>void);
    }

    export class Addon {
        OnMessage(callback: (reader: any)=>void);
        OnMessageID<T>(cls: new()=>T, callback: (player: TSPlayer,message: T)=>void);
    }
}

declare class TSEventHandlers {
    World: _hidden.World;
    Formula: _hidden.Formula;
    Unit: _hidden.Unit;
    Addon: _hidden.Addon;
    //AreaTrigger: _hidden.AreaTrigger;
    //Vehicle: _hidden.Vehicle;
    //AchievementCriteria: _hidden.AchievementCriteria;
    Player: _hidden.Player;
    Account: _hidden.Account;
    Guild: _hidden.Guild;
    Group: _hidden.Group;
    Spells: _hidden.Spells;
    Creatures: _hidden.Creatures;
    CreatureID: _hidden.CreatureID;
    SpellID: _hidden.SpellID;
    Auction: _hidden.AuctionHouse;
    Maps: _hidden.Maps;
    MapID: _hidden.MapID;
    Items: _hidden.Items;
    ItemID: _hidden.ItemID;
    GameObjects: _hidden.GameObjects;
    GameObjectID: _hidden.GameObejctID;
}

declare class TSDictionary<K,V> {
    [custom: string]: V;
    // @ts-ignore
    set(key: K, value: V);
    // @ts-ignore
    contains(key: K): boolean;
    // @ts-ignore
    forEach(callback: (key: K, value: V)=>void);
    // @ts-ignore
    keys(): TSArray<K>
    // @ts-ignore
    reduce<T>(callback: (previous: T,key: K, value: V)=>T, initial: T) : T;
    // @ts-ignore
    filter(callback: (key: K, value: V)=>boolean): TSDictionary<K,V>
}

declare class TSLootItem {
    GetItemID(): uint32;
    GetRandomSuffix(): uint32;
    GetRandomPropertyID(): uint32;
    GetCount(): uint32;
    SetItemID(itemId: uint32);
    SetRandomPropertyID(propertyId: int32);
    SetCount(count: uint8);
}

declare class TSLoot {
    IsNull(): bool;
    Clear(): void;
    IsLooted(): bool;
    AddItem(id: uint32, minCount: uint8, maxCount: uint8, lootMode?: uint16, needsQuest?: bool, groupId?: uint8): void;
    AddLooter(looter: uint64): void;
    RemoveLooter(looter: uint64): void;
    SetLootType(lootType: uint32): void;
    SetMoney(money: uint32): void;
    GetLootType(): uint32;
    GetMoney(): uint32;
    GetLootOwner(): uint64;
    SetLootOwner(owner: uint64);
    GetItemCount(): uint32;
    GetQuestItemCount(): uint32;

    GetItem(index: uint32): TSLootItem;
    GetQuestItem(index: uint32): TSLootItem;
    Filter(predicate: (item: TSLootItem)=>bool);
    GetGeneratesNormally(): bool;
    SetGeneratesNormally(normal: bool);
}

declare class TSAuctionEntry {
    GetID(): uint32;
    GetHouseID(): uint8;
    /**
     * Returns the GUID of this item
     */
    GetItemID(): uint64;
    /**
     * Returns the item_template id of this item
     */
    GetItemEntry(): uint32;
    GetItemCount(): uint32;
    GetOwnerID(): uint64;
    GetStartBid(): uint32;
    GetBid(): uint32;
    GetBuyout(): uint32;
    GetExpireTime(): uint64;
    GetBidder(): uint64;
    GetDeposit(): uint32;
    GetETime(): uint32;
    GetBidders(): TSArray<uint64>
    GetFlags(): uint32;
    
    SetItemID(itemId: uint64);
    SetItemEntry(itemEntry: uint64);
    SetItemCount(itemCount: uint32);
    SetOwnerID(ownerId: uint64);
    SetStartBid(startBid: uint32);
    SetBid(bid: uint32);
    SetBuyout(buyout: uint32);
    SetBidder(bidder:uint64);
    SetDeposit(deposit: uint32);
    SetETime(eTime: uint32);
    SetFlags(flags: uint32);
}

declare class TSAuctionHouseObject {
    GetKeys() : TSArray<uint32>
    GetEntry(key: uint32): TSAuctionEntry
    RemoveAuction(key: uint32|TSAuctionEntry): bool
    GetCount(): uint32;
    AddAuction(entry: TSAuctionEntry);
}

declare class TSMailItemInfo {
    GetGUID(): uint64;
    GetItemTemplate(): uint32;
}

declare class TSMail {
    GetID(): uint32;
    GetType(): uint8;
    GetTemplateID(): uint16;
    GetSender(): uint64;
    GetReceiver(): uint64;
    GetState(): uint16;
    GetMoney(): uint32;
    GetCOD(): uint32;
    GetChecked(): uint32;
    GetSubject(): string;
    GetBody(): string;
    GetItems(): TSArray<TSMailItemInfo>
    GetItemCount(): uint32;
    FilterItems(predicate: (info: TSMailItemInfo)=>boolean);
    RemoveAllItems();
    AddItem(entry: uint32, count: uint8, player?: TSPlayer);
    SetMoney(money: uint32)
    SetCOD(cod: uint32)
    SetChecked(checked: uint32)
    SetSender(type: uint8, guid: uint64)
    SetSubject(subject: string)
    SetBody(body: string)
    SetState(state: uint8)
}

declare class TSMailDraft {
    GetTemplateID(): uint16
    GetSubject(): string
    GetBody(): string;
    GetMoney(): uint32;
    GetCOD(): uint32;
    GetItemKeys(): TSArray<uint64>
    GetItem(item: uint64): TSItem
    SetTemplateID(id: uint16);
    SetSubject(subject: string);
    SetBody(body: string);
    AddItem(enry: uint32, count: uint8, player?: TSPlayer);
    FilterItems(predicate: (item: TSItem)=>boolean);
}

// Global.h
declare function SendMail(senderType: uint8, from: uint64, subject: string, body: string, money?: uint32, cod?: uint32, delay?: uint32, items?: TSArray<TSItem>);
declare function SendWorldMessage(message: string);
// end of Global.h

declare function MakeDictionary<K,V>(obj: {[key: string]: V}) : TSDictionary<K,V>

declare function GetID(table: string, mod: string, name: string);
declare function GetIDRange(table: string, mod: string, name: string);

declare class TSTimer {
    delay: uint32;
    repeats: uint32;
    readonly name: string;
}

declare class TSTasks<T> {
    AddTimer(id: uint32, name: string, time: uint32, repeats: uint32, cb: (timer: TSTimer,owner: T, delay: uint32, cancel: TSMutable<bool>)=>void)
    RemoveTimer(name: string);
}

declare class BinReader<L extends number> {
    Read<T extends number>(offset: L) : T;
    Write<T extends number>(offset: L, value: T)
    ReadArray<T extends number>(offset: L, arr: TSArray<T>, max: L);
    WriteArray<T extends number>(offset: L, arr: TSArray<T>, max: L);
    ReadString(offset: L, max: L);
    WriteString(offset: L,str: string, max: L);
    WriteStringArray(offset: L, arr: TSArray<string>, arrMax: number, strMax: number);
    ReadStringArray(offset: L, arr: TSArray<string>, marMax: L, strMax: L);
    WriteDouble(offset: L, value: double);
    ReadDouble(offset: L): double;
    WriteArrayDouble(offset: L, arr: TSArray<double>, max: L);
    ReadArrayDouble(offset: L, arr: TSArray<double>, max: L);
    WriteClass<T>(offset: L, value: T);
    ReadClass<T>(offset: L, value: T);
    ReadClassArray<T>(offset: L, arr: TSArray<T>, max: L, ind_size: L, con : ()=>T);
    WriteClassArray<T>(offset: L, arr: TSArray<T>, max: L, ind_size: L);
}

declare class TSDatabaseResult {
    GetUInt8(index: int): uint8;
    GetUInt16(index: int): uint16;
    GetUInt32(index: int): uint32;
    GetUInt64(index: int): uint64;

    GetInt8(index: int): int8;
    GetInt16(index: int): int16;
    GetInt32(index: int): int32;
    GetInt64(index: int): int64;

    GetFloat(index: int): float;
    GetDouble(index: int): double;
    GetString(index: int): string;

    GetRow(): boolean;
    IsValid(): boolean;
}

declare class DBTable {
    saveQuery(): string;
    loadQuery(): string;
    save(): void;
    load(): boolean;
}

declare class TSClass {
    stringify(indention?: int): string;
}

declare function CreateLootItem(id: uint32, reference?: uint32, chance?: float, lootmode?: uint16, needsQuest?: bool, groupId?: uint8, minCount?: uint8, maxCount?: uint8)
declare function CreateItem(entry: uint32, count: uint32): TSItem;

declare function QueryWorld(query: string): TSDatabaseResult;
declare function QueryCharacters(query: string): TSDatabaseResult;
declare function QueryAuth(query: string): TSDatabaseResult;

declare function WorldTable(classTarget: any)
declare function CharactersTable(classTarget: any)
declare function AuthTable(classTarget: any)
declare function Field(fieldTarget: any, name: any)
declare function PrimaryKey(pkTarget: any, name: any)

declare function Message(classTarget: any)
declare function MsgClass(classTarget: any, name: string)
declare function MsgClassArray(size: number): (field: any, name: any)=>void
declare function MsgPrimitive(classTarget: any, name: string)
declare function MsgPrimitiveArray(capacity: number): (field: any, name: any)=>void;
declare function MsgString(size: number): (field: any, name: any)=>void
declare function MsgStringArray(arrSize: number, stringSize: number): (field: any, name: any)=>void

declare function GetTimers() : TSTasks<void>

declare function ModID(): uint32;

declare function LoadRows<T extends DBTable>(cls: {new (...args: any[]): T}, query: string): TSArray<T>