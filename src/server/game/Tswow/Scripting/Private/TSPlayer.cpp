/*
 * Copyright (C) 2020 tswow <https://github.com/tswow/>
 * Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
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

#include <memory.h>
#include "TSIncludes.h"
#include "Object.h"
#include "Player.h"
#include "TSIncludes.h"
#include "TSPlayer.h"
#include "Player.h"
#include "ArenaTeam.h"
#include "SpellMgr.h"
#include "GuildMgr.h"
#include "AccountMgr.h"
#include "AuctionHouseMgr.h"
#include "Guild.h"
#include "Item.h"
#include "SpellHistory.h"
#include "Group.h"
#include "GroupMgr.h"
#include "GridNotifiers.h"
#include "ReputationMgr.h"
#include "Chat.h"
#include "GossipDef.h"
#include "Mail.h"

#include "TSUnit.h"
#include "TSItem.h"
#include "TSGroup.h"
#include "TSQuest.h"
#include "TSWorldObject.h"
#include "TSGuild.h"
#include "TSCorpse.h"
#include "TSObject.h"
#include "TSWorldPacket.h"
#include "TSCreature.h"
#include "TSMail.h"


TSPlayer::TSPlayer(Player *player) : TSUnit(player)
{
    this->player = player;
}

TSPlayer::TSPlayer() : TSUnit()
{
    this->player = nullptr;
}

#if (!defined(TBC) && !defined(CLASSIC))
/**
 * Returns 'true' if the [Player] can Titan Grip, 'false' otherwise.
 *
 * @return bool canTitanGrip
 */
bool TSPlayer::CanTitanGrip() 
{
    return player->CanTitanGrip();
}
    
/**
 * Returns 'true' if the [Player] has a talent by ID in specified spec, 'false' otherwise.
 *
 * @param uint32 spellId : talent spellId to check
 * @param uint8 spec : specified spec. 0 for primary, 1 for secondary.
 * @return bool hasTalent
 */
bool TSPlayer::HasTalent(uint32 spellId,uint8 spec) 
{
#ifdef MANGOS
    uint8 maxSpecs = MAX_TALENT_SPEC_COUNT;
#else
    uint8 maxSpecs = MAX_TALENT_SPECS;
#endif
    return player->HasTalent(spellId, spec);
}
    
/**
 * Returns 'true' if the [Player] has completed the specified achievement, 'false' otherwise.
 *
 * @param uint32 achievementId
 * @return bool hasAchieved
 */
bool TSPlayer::HasAchieved(uint32 achievementId) 
{
#if defined TRINITY || AZEROTHCORE
    return player->HasAchieved(achievementId);
#else
    return player->GetAchievementMgr().HasAchievement(achievementId);
#endif
}
#endif
    
/**
 * Returns 'true' if the [Player] has an active [Quest] by specific ID, 'false' otherwise.
 *
 * @param uint32 questId
 * @return bool hasQuest
 */
bool TSPlayer::HasQuest(uint32 quest) 
{
    return player->IsActiveQuest(quest);
}
    
/**
 * Returns 'true' if the [Player] has a skill by specific ID, 'false' otherwise.
 *
 * @param uint32 skill
 * @return bool hasSkill
 */
bool TSPlayer::HasSkill(uint32 skill) 
{
    return player->HasSkill(skill);
}
    
/**
 * Returns 'true' if the [Player] has a [Spell] by specific ID, 'false' otherwise.
 *
 * @param uint32 spellId
 * @return bool hasSpell
 */
bool TSPlayer::HasSpell(uint32 id) 
{
    return player->HasSpell(id);
}
    
/**
 * Returns true if [Player] has specified login flag
 *
 * @param uint32 flag
 * @return bool hasLoginFlag
 */
bool TSPlayer::HasAtLoginFlag(uint32 flag) 
{
    return player->HasAtLoginFlag((AtLoginFlags)flag);
}
    
/**
 * Returns true if [Player] has [Quest] for [GameObject]
 *
 * @param int32 entry : entry of a [GameObject]
 * @return bool hasQuest
 */
bool TSPlayer::HasQuestForGO(int32 entry) 
{
    return player->HasQuestForGO(entry);
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Player] has a title by specific ID, 'false' otherwise.
 *
 * @param uint32 titleId
 * @return bool hasTitle
 */
bool TSPlayer::HasTitle(uint32 id) 
{
    CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
    if (titleInfo)
        return player->HasTitle(titleInfo);
}
#endif

/**
 * Returns 'true' if the [Player] has the given amount of item entry specified, 'false' otherwise.
 *
 * @param uint32 itemId : entry of the item
 * @param uint32 count = 1 : amount of items the player needs should have
 * @param bool check_bank = false : determines if the item can be in player bank
 * @return bool hasItem
 */
bool TSPlayer::HasItem(uint32 itemId,uint32 count,bool check_bank) 
{
    return player->HasItemCount(itemId, count, check_bank);
}

/**
 * Returns 'true' if the [Player] has a quest for the item entry specified, 'false' otherwise.
 *
 * @param uint32 entry : entry of the item
 * @return bool hasQuest
 */
bool TSPlayer::HasQuestForItem(uint32 entry) 
{
    return player->HasQuestForItem(entry);
}

/**
 * Returns 'true' if the [Player] can use the item or item entry specified, 'false' otherwise.
 *
 * @proto canUse = (item)
 * @proto canUse = (entry)
 * @param [Item] item : an instance of an item
 * @param uint32 entry : entry of the item
 * @return bool canUse
 */
bool TSPlayer::CanUseItem(TSItem _item,uint32 entry)
{
    auto item = _item.item;
    if (item)
        return player->CanUseItem(item) == EQUIP_ERR_OK;
    else
    {
        const ItemTemplate* temp = eObjectMgr->GetItemTemplate(entry);
        if (temp)
            return player->CanUseItem(temp) == EQUIP_ERR_OK;
        else
            return false;
    }
}
    
/**
 * Returns 'true' if the [Spell] specified by ID is currently on cooldown for the [Player], 'false' otherwise.
 *
 * @param uint32 spellId
 * @return bool hasSpellCooldown
 */
bool TSPlayer::HasSpellCooldown(uint32 spellId) 
{
    
#ifdef TRINITY
    return player->GetSpellHistory()->HasCooldown(spellId);
#else
    return player->HasSpellCooldown(spellId);
#endif
}
    
/**
 * Returns 'true' if the [Player] can share [Quest] specified by ID, 'false' otherwise.
 *
 * @param uint32 entryId
 * @return bool hasSpellCooldown
 */
bool TSPlayer::CanShareQuest(uint32 entry) 
{
    return player->CanShareQuest(entry);
}
    
/**
 * Returns 'true' if the [Player] can currently communicate through chat, 'false' otherwise.
 *
 * @return bool canSpeak
 */
bool TSPlayer::CanSpeak() 
{
#ifdef TRINITY
    return player->GetSession()->CanSpeak();
#else
    return player->CanSpeak();
#endif
}
    
/**
 * Returns 'true' if the [Player] has permission to uninvite others from the current group, 'false' otherwise.
 *
 * @return bool canUninviteFromGroup
 */
bool TSPlayer::CanUninviteFromGroup() 
{
    return player->CanUninviteFromGroup() == ERR_PARTY_RESULT_OK;
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Player] can fly, 'false' otherwise.
 *
 * @return bool canFly
 */
bool TSPlayer::CanFly() 
{
    return player->CanFly();
}
#endif
    
#ifdef CLASSIC
/**
 * Returns [Player] kills
 *
 * @param bool honorable = true : if victims are honorable
 * @return uint32 kills
 */
uint32 TSPlayer::GetHonorStoredKills(bool honorable) 
{
    return player->GetHonorStoredKills(honorable);
}
    
/**
 * Returns rank points
 *
 * @return float rankPoints
 */
float TSPlayer::GetRankPoints() 
{
    return player->GetRankPoints();
}
    
/**
 * Returns last week's standing position
 *
 * @return int32 standingPos
 */
int32 TSPlayer::GetHonorLastWeekStandingPos() 
{
    return player->GetHonorLastWeekStandingPos();
}
#endif
    
/**
 * Returns 'true' if the [Player] is currently in water, 'false' otherwise.
 *
 * @return bool isInWater
 */
bool TSPlayer::IsInWater() 
{
    return player->IsInWater();
}
    
/**
 * Returns 'true' if the [Player] is currently moving, 'false' otherwise.
 *
 * @return bool isMoving
 */
bool TSPlayer::IsMoving() 
{
    return player->isMoving();
}
    
#ifdef CLASSIC
/**
 * Updates the [Player]s weekly honor status
 */
void TSPlayer::UpdateHonor() 
{
    player->UpdateHonor();
}
    
/**
 * Resets the [Player]s weekly honor status
 */
void TSPlayer::ResetHonor() 
{
    player->ResetHonor();
}
    
/**
 * Clears all of [Player]s weekly honor status
 */
void TSPlayer::ClearHonorInfo() 
{
    player->ClearHonorInfo();
}
#endif
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Player] is currently flying, 'false' otherwise.
 *
 * @return bool isFlying
 */
bool TSPlayer::IsFlying() 
{
    return player->IsFlying();
}
#endif
    
/**
 * Returns 'true' if the [Player] is in a [Group], 'false' otherwise.
 *
 * @return bool isInGroup
 */
bool TSPlayer::IsInGroup() 
{
    return (player->GetGroup() != NULL);
}
    
/**
 * Returns 'true' if the [Player] is in a [Guild], 'false' otherwise.
 *
 * @return bool isInGuild
 */
bool TSPlayer::IsInGuild() 
{
    return (player->GetGuildId() != 0);
}
    
/**
 * Returns 'true' if the [Player] is a Game Master, 'false' otherwise.
 *
 * Note: This is only true when GM tag is activated! For alternative see [Player:GetGMRank]
 *
 * @return bool isGM
 */
bool TSPlayer::IsGM() 
{
#if defined TRINITY || AZEROTHCORE
    return player->IsGameMaster();
#else
    return player->isGameMaster();
#endif
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Player] is in an arena team specified by type, 'false' otherwise.
 *
 * @param uint32 type
 * @return bool isInArenaTeam
 */
bool TSPlayer::IsInArenaTeam(uint32 type) 
{
    if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
        return true;
    else
        return false;
}
#endif

/**
 * Returns 'true' if the [Player] is immune to everything.
 *
 * @return bool isImmune
 */
bool TSPlayer::IsImmuneToDamage() 
{
    return player->isTotalImmune();
}
    
/**
 * Returns 'true' if the [Player] satisfies all requirements to complete the quest entry.
 *
 * @param uint32 entry
 * @return bool canComplete
 */
bool TSPlayer::CanCompleteQuest(uint32 entry) 
{
    return player->CanCompleteQuest(entry);
}
    
/**
 * Returns 'true' if the [Player] is a part of the Horde faction, 'false' otherwise.
 *
 * @return bool isHorde
 */
bool TSPlayer::IsHorde() 
{
#ifdef AZEROTHCORE
    return (player->GetTeamId() == TEAM_HORDE);
#else
    return (player->GetTeam() == HORDE);
#endif
}
    
/**
 * Returns 'true' if the [Player] is a part of the Alliance faction, 'false' otherwise.
 *
 * @return bool isAlliance
 */
bool TSPlayer::IsAlliance() 
{
#ifdef AZEROTHCORE
    return (player->GetTeamId() == TEAM_ALLIANCE);
#else
    return (player->GetTeam() == ALLIANCE);
#endif
}
    
/**
 * Returns 'true' if the [Player] is 'Do Not Disturb' flagged, 'false' otherwise.
 *
 * @return bool isDND
 */
bool TSPlayer::IsDND() 
{
    return player->isDND();
}
    
/**
 * Returns 'true' if the [Player] is 'Away From Keyboard' flagged, 'false' otherwise.
 *
 * @return bool isAFK
 */
bool TSPlayer::IsAFK() 
{
    return player->isAFK();
}
    
/**
 * Returns 'true' if the [Player] is currently falling, 'false' otherwise.
 *
 * @return bool isFalling
 */
bool TSPlayer::IsFalling() 
{
    return player->IsFalling();
}
    
bool TSPlayer::IsGroupVisibleFor(TSPlayer _target)
{
    auto target = _target.player;
    return player->IsGroupVisibleFor(target);
}
    
/**
 * Returns 'true' if the [Player] is currently in the same raid as another [Player] by object, 'false' otherwise.
 *
 * @param [Player] player
 * @return bool isInSameRaidWith
 */
bool TSPlayer::IsInSameRaidWith(TSPlayer _target)
{
    auto target = _target.player;
    return player->IsInSameRaidWith(target);
}
    
/**
 * Returns 'true' if the [Player] is currently in the same [Group] as another [Player] by object, 'false' otherwise.
 *
 * @param [Player] player
 * @return bool isInSameGroupWith
 */
bool TSPlayer::IsInSameGroupWith(TSPlayer _target)
{
    auto target = _target.player;
    return player->IsInSameGroupWith(target);
}
    
/**
 * Returns 'true' if the [Player] is eligible for Honor or XP gain by [Unit] specified, 'false' otherwise.
 *
 * @param [Unit] unit
 * @return bool isHonorOrXPTarget
 */
bool TSPlayer::IsHonorOrXPTarget(TSUnit _victim)
{
    auto victim = _victim.unit;
    return player->isHonorOrXPTarget(victim);
}
    
/**
 * Returns 'true' if the [Player] can see anoter [Player] specified by object, 'false' otherwise.
 *
 * @param [Player] player
 * @return bool isVisibleForPlayer
 */
bool TSPlayer::IsVisibleForPlayer(TSPlayer _target)
{
    auto target = _target.player;
    return player->IsVisibleGloballyFor(target);
}
    
bool TSPlayer::IsGMVisible() 
{
    return player->isGMVisible();
}
    
/**
 * Returns 'true' if the [Player] has taxi cheat activated, 'false' otherwise.
 *
 * @return bool isTaxiCheater
 */
bool TSPlayer::IsTaxiCheater() 
{
#ifdef MANGOS
    return player->IsTaxiCheater();
#else
    return player->isTaxiCheater();
#endif
}
    
bool TSPlayer::IsGMChat() 
{
    return player->isGMChat();
}
    
/**
 * Returns 'true' if the [Player] is accepting whispers, 'false' otherwise.
 *
 * @return bool isAcceptingWhispers
 */
bool TSPlayer::IsAcceptingWhispers() 
{
    return player->isAcceptWhispers();
}
    
/**
 * Returns 'true' if the [Player] is currently rested, 'false' otherwise.
 *
 * @return bool isRested
 */
bool TSPlayer::IsRested() 
{
    return player->GetRestBonus() > 0.0f;
}
    
/**
 * Returns 'true' if the [Player] is currently in a [BattleGround] queue, 'false' otherwise.
 *
 * @return bool inBattlegroundQueue
 */
bool TSPlayer::InBattlegroundQueue() 
{
#if defined TRINITY || AZEROTHCORE
    return player->InBattlegroundQueue();
#else
    return player->InBattleGroundQueue();
#endif
}
    
#ifndef CLASSIC
/**
 * Returns 'true' if the [Player] is currently in an arena, 'false' otherwise.
 *
 * @return bool inArena
 */
bool TSPlayer::InArena() 
{
    return player->InArena();
}
#endif
    
/**
 * Returns 'true' if the [Player] is currently in a [BattleGround], 'false' otherwise.
 *
 * @return bool inBattleGround
 */
bool TSPlayer::InBattleground() 
{
#if defined TRINITY || AZEROTHCORE
    return player->InBattleground();
#else
    return player->InBattleGround();
#endif
}
    
/**
 * Returns 'true' if the [Player] can block incomming attacks, 'false' otherwise.
 *
 * @return bool canBlock
 */
bool TSPlayer::CanBlock() 
{
    return player->CanBlock();
}
    
/**
 * Returns 'true' if the [Player] can parry incomming attacks, 'false' otherwise.
 *
 * @return bool canParry
 */
bool TSPlayer::CanParry() 
{
    return player->CanParry();
}
    
/*int TSPlayer::HasReceivedQuestReward(lua_State* L, Player* player)
{
    return player->IsQuestRewarded(entry);
}*/
    
/*int TSPlayer::IsOutdoorPvPActive(lua_State* L, Player* player)
{
    return player->IsOutdoorPvPActive();
}*/
    
/*int TSPlayer::IsImmuneToEnvironmentalDamage(lua_State* L, Player* player)
{
    return player->IsImmuneToEnvironmentalDamage();
}*/
    
/*int TSPlayer::InRandomLfgDungeon(lua_State* L, Player* player)
{
    return player->inRandomLfgDungeon();
}*/
    
/*int TSPlayer::IsUsingLfg(lua_State* L, Player* player)
{
    return player->isUsingLfg();
}*/
    
/*int TSPlayer::IsNeverVisible(lua_State* L, Player* player)
{
    return player->IsNeverVisible();
}*/
    
/*int TSPlayer::CanFlyInZone(lua_State* L, Player* player)
{
    return player->IsKnowHowFlyIn(mapid, zone);
}*/
    
/*int TSPlayer::HasPendingBind(lua_State* L, Player* player)
{
    return player->PendingHasPendingBind();
}*/
    
/*int TSPlayer::IsARecruiter(lua_State* L, Player* player)
{
    return player->GetSession()->IsARecruiter() || (player->GetSession()->GetRecruiterId() != 0);
}*/
    
#if (!defined(TBC) && !defined(CLASSIC))
/**
 * Returns the amount of available specs the [Player] currently has
 *
 * @return uint8 specCount
 */
uint8 TSPlayer::GetSpecsCount(uint32 entry,uint32 mapid,uint32 zone) 
{
    return player->GetSpecsCount();
}
    
/**
 * Returns the [Player]s active spec ID
 *
 * @return uint32 specId
 */
uint32 TSPlayer::GetActiveSpec() 
{
    return player->GetActiveSpec();
}
#endif
    
#ifdef WOTLK
/**
 * Returns the normal phase of the player instead of the actual phase possibly containing GM phase
 *
 * @return uint32 phasemask
 */
uint32 TSPlayer::GetPhaseMaskForSpawn() 
{
    return player->GetPhaseMaskForSpawn();
}
#endif
    
#if defined(TBC) || defined (WOTLK)
/**
 * Returns the [Player]s current amount of Arena Points
 *
 * @return uint32 arenaPoints
 */
uint32 TSPlayer::GetArenaPoints() 
{
    return player->GetArenaPoints();
}
    
/**
 * Returns the [Player]s current amount of Honor Points
 *
 * @return uint32 honorPoints
 */
uint32 TSPlayer::GetHonorPoints() 
{
    return player->GetHonorPoints();
}
#endif
#if defined(CLASSIC) || defined(TBC) || defined (WOTLK)
/**
 * Returns the [Player]s current shield block value
 *
 * @return uint32 blockValue
 */
uint32 TSPlayer::GetShieldBlockValue() 
{
    return player->GetShieldBlockValue();
}
#endif
    
/**
 * Returns the [Player]s cooldown delay by specified [Spell] ID
 *
 * @param uint32 spellId
 * @return uint32 spellCooldownDelay
 */
uint32 TSPlayer::GetSpellCooldownDelay(uint32 spellId) 
{
    
#ifdef TRINITY
    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
        return player->GetSpellHistory()->GetRemainingCooldown(spellInfo);
    else
        return 0;
#else
    return uint32(player->GetSpellCooldownDelay(spellId));
#endif
}
    
/**
 * Returns the [Player]s current latency in MS
 *
 * @return uint32 latency
 */
uint32 TSPlayer::GetLatency() 
{
    return player->GetSession()->GetLatency();
}
    
#if defined TRINITY || AZEROTHCORE
/**
 * Returns the faction ID the [Player] is currently flagged as champion for
 *
 * @return uint32 championingFaction
 */
uint32 TSPlayer::GetChampioningFaction() 
{
    return player->GetChampioningFaction();
}
#endif
    
/**
 * Returns [Player]s original sub group
 *
 * @return uint8 subGroup
 */
uint8 TSPlayer::GetOriginalSubGroup() 
{
    return player->GetOriginalSubGroup();
}
    
/**
 * Returns [Player]s original [Group] object
 *
 * @return [Group] group
 */
TSGroup  TSPlayer::GetOriginalGroup() 
{
     return TSGroup(player->GetOriginalGroup());
}
    
/**
 * Returns a random Raid Member [Player] object within radius specified of [Player]
 *
 * @param float radius
 * @return [Player] player
 */
TSPlayer  TSPlayer::GetNextRandomRaidMember(float radius) 
{
     return TSPlayer(player->GetNextRandomRaidMember(radius));
}
    
/**
 * Returns [Player]s current sub group
 *
 * @return uint8 subGroup
 */
uint8 TSPlayer::GetSubGroup() 
{
    return player->GetSubGroup();
}
    
/**
 * Returns [Group] invitation
 *
 * @return [Group] group
 */
TSGroup  TSPlayer::GetGroupInvite() 
{
     return TSGroup(player->GetGroupInvite());
}
    
/**
 * Returns rested experience bonus
 *
 * @param uint32 xp
 * @return uint32 xpBonus
 */
uint32 TSPlayer::GetXPRestBonus(uint32 xp) 
{
    return player->GetXPRestBonus(xp);
}
    
/**
 * Returns the [Player]s current [BattleGround] type ID
 *
 * @return [BattleGroundTypeId] typeId
 */
uint32 TSPlayer::GetBattlegroundTypeId() 
{
#if defined TRINITY || AZEROTHCORE
    return player->GetBattlegroundTypeId();
#else
    return player->GetBattleGroundTypeId();
#endif
}
    
/**
 * Returns the [Player]s current [BattleGround] ID
 *
 * @return uint32 battleGroundId
 */
uint32 TSPlayer::GetBattlegroundId() 
{
#if defined TRINITY || AZEROTHCORE
    return player->GetBattlegroundId();
#else
    return player->GetBattleGroundId();
#endif
}
    
/**
 * Returns the [Player]s reputation rank of faction specified
 *
 * @param uint32 faction
 * @return [ReputationRank] rank
 */
uint32 TSPlayer::GetReputationRank(uint32 faction) 
{
    return player->GetReputationRank(faction);
}
    
/**
 * Returns the [Player]s current level of intoxication
 *
 * @return uint16 drunkValue
 */
uint16 TSPlayer::GetDrunkValue() 
{
    return player->GetDrunkValue();
}
    
/**
 * Returns skill temporary bonus value
 *
 * @param uint32 skill
 * @param int16 bonusVal
 */
int16 TSPlayer::GetSkillTempBonusValue(uint32 skill) 
{
    return player->GetSkillTempBonusValue(skill);
}
    
/**
 * Returns skill permanent bonus value
 *
 * @param uint32 skill
 * @param int16 bonusVal
 */
int16 TSPlayer::GetSkillPermBonusValue(uint32 skill) 
{
    return player->GetSkillPermBonusValue(skill);
}
    
/**
 * Returns skill value without bonus'
 *
 * @param uint32 skill
 * @return uint16 pureVal
 */
uint16 TSPlayer::GetPureSkillValue(uint32 skill) 
{
    return player->GetPureSkillValue(skill);
}
    
/**
 * Returns base skill value
 *
 * @param uint32 skill
 * @return uint16 baseVal
 */
uint16 TSPlayer::GetBaseSkillValue(uint32 skill) 
{
    return player->GetBaseSkillValue(skill);
}
    
/**
 * Returns skill value
 *
 * @param uint32 skill
 * @return uint16 val
 */
uint16 TSPlayer::GetSkillValue(uint32 skill) 
{
    return player->GetSkillValue(skill);
}
    
/**
 * Returns max value of specified skill without bonus'
 *
 * @param uint32 skill
 * @return uint16 pureVal
 */
uint16 TSPlayer::GetPureMaxSkillValue(uint32 skill) 
{
    return player->GetPureMaxSkillValue(skill);
}
    
/**
 * Returns max value of specified skill
 *
 * @param uint32 skill
 * @return uint16 val
 */
uint16 TSPlayer::GetMaxSkillValue(uint32 skill) 
{
    return player->GetMaxSkillValue(skill);
}
    
/**
 * Returns mana bonus from amount of intellect
 *
 * @return float bonus
 */
float TSPlayer::GetManaBonusFromIntellect() 
{
    return player->GetManaBonusFromIntellect();
}
    
/**
 * Returns health bonus from amount of stamina
 *
 * @return float bonus
 */
float TSPlayer::GetHealthBonusFromStamina() 
{
    return player->GetHealthBonusFromStamina();
}
    
/**
 * Returns raid or dungeon difficulty
 *
 * @param bool isRaid = true : argument is TrinityCore only
 * @return int32 difficulty
 */
int32 TSPlayer::GetDifficulty(bool isRaid) 
{
#ifdef TBC
    return player->GetDifficulty();
#elif defined(CLASSIC)
    return (Difficulty)0;
#else
    return player->GetDifficulty(isRaid);
#endif
}
    
/**
 * Returns the [Player]s current guild rank
 *
 * @return uint32 guildRank
 */
uint32 TSPlayer::GetGuildRank() 
{
    return player->GetRank();
}
    
/**
 * Returns the [Player]s free talent point amount
 *
 * @return uint32 freeTalentPointAmt
 */
uint32 TSPlayer::GetFreeTalentPoints() 
{
    return player->GetFreeTalentPoints();
}
    
/**
 * Returns the name of the [Player]s current [Guild]
 *
 * @return string guildName
 */
TSString TSPlayer::GetGuildName()
{
     return TSString(eGuildMgr->GetGuildNameById(player->GetGuildId()));
}
    
/**
 * Returns the amount of reputation the [Player] has with the faction specified
 *
 * @param uint32 faction
 * @return int32 reputationAmt
 */
int32 TSPlayer::GetReputation(uint32 faction) 
{
    return player->GetReputationMgr().GetReputation(faction);
}
    
/**
 * Returns [Unit] target combo points are on
 *
 * @return [Unit] target
 */
TSUnit  TSPlayer::GetComboTarget() 
{
#if defined TRINITY || AZEROTHCORE
     return TSUnit(ObjectAccessor::GetUnit(*player,player->GetComboTarget()->GetGUID()));
#else
     return TSUnit(player->GetMap()->GetUnit(player->GetComboTargetGuid()));
#endif
}
    
/**
 * Returns [Player]'s combo points
 *
 * @return uint8 comboPoints
 */
uint8 TSPlayer::GetComboPoints() 
{
    return player->GetComboPoints();
}
    
/**
 * Returns the amount of time the [Player] has spent ingame
 *
 * @return uint32 inGameTime
 */
uint32 TSPlayer::GetInGameTime() 
{
    return player->GetInGameTime();
}
    
/**
 * Returns the status of the [Player]s [Quest] specified by entry ID
 *
 * @param uint32 questId
 * @return [QuestStatus] questStatus
 */
uint32 TSPlayer::GetQuestStatus(uint32 entry) 
{
    return player->GetQuestStatus(entry);
}
    
/**
 * Returns 'true' if the [Player]s [Quest] specified by entry ID has been rewarded, 'false' otherwise.
 *
 * @param uint32 questId
 * @return bool questRewardStatus
 */
bool TSPlayer::GetQuestRewardStatus(uint32 questId) 
{
    return player->GetQuestRewardStatus(questId);
}
    
/**
 * Returns [Quest] required [Creature] or [GameObject] count
 *
 * @param uint32 quest : entry of a quest
 * @param int32 entry : entry of required [Creature]
 * @return uint16 count
 */
uint16 TSPlayer::GetReqKillOrCastCurrentCount(uint32 questId,int32 entry) 
{
    return player->GetReqKillOrCastCurrentCount(questId, entry);
}
    
/**
 * Returns the quest level of the [Player]s [Quest] specified by object
 *
 * @param uint32 questId
 * @return [QuestStatus] questRewardStatus
 */
uint32 TSPlayer::GetQuestLevel(TSQuest _quest)
{
    auto quest = _quest.quest;
    
#if defined TRINITY || AZEROTHCORE
    return player->GetQuestLevel(quest);
#else
    return player->GetQuestLevelForPlayer(quest);
#endif
}
    
/**
 * Returns a [Player]s [Item] object by gear slot specified
 *
 * @param uint8 slot
 * @return [Item] item
 */
TSItem  TSPlayer::GetEquippedItemBySlot(uint8 slot) 
{
    
    Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
     return TSItem(item);
}
    
/**
 * Returns the [Player]s current resting bonus
 *
 * @return float restBonus
 */
float TSPlayer::GetRestBonus() 
{
    return player->GetRestBonus();
}
    
/**
 * Returns active GM chat tag
 *
 * @return uint8 tag
 */
uint8 TSPlayer::GetChatTag() 
{
    return player->GetChatTag();
}
    
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
TSItem  TSPlayer::GetItemByPos(uint8 bag,uint8 slot) 
{
     return TSItem(player->GetItemByPos(bag, slot));
}
    
/**
 * Returns an [Item] from the player by guid.
 *
 * The item can be equipped, in bags or in bank.
 *
 * @param uint64 guid : an item guid
 * @return [Item] item
 */
TSItem  TSPlayer::GetItemByGUID(uint64 guid) 
{
     return TSItem(player->GetItemByGuid(ObjectGuid(guid)));
}
    
/**
 * Returns an [Item] from the player by entry.
 *
 * The item can be equipped, in bags or in bank.
 *
 * @param uint32 entryId
 * @return [Item] item
 */
TSItem  TSPlayer::GetItemByEntry(uint32 entry) 
{
     return TSItem(player->GetItemByEntry(entry));
}

/**
 * Returns the database textID of the [WorldObject]'s gossip header text for the [Player]
 *
 * @return uint32 textId : key to npc_text database table
 */
uint32 TSPlayer::GetGossipTextId(TSWorldObject _obj)
{
    auto obj = _obj.obj;
    return player->GetGossipTextId(obj);
}
    
/**
 * Returns the [Player]s currently selected [Unit] object
 *
 * @return [Unit] unit
 */
TSUnit  TSPlayer::GetSelection() 
{
#if defined TRINITY || AZEROTHCORE
     return TSUnit(player->GetSelectedUnit());
#else
     return TSUnit(player->GetMap()->GetUnit(player->GetSelectionGuid()));
#endif
}
    
/**
 * Returns the [Player]s GM Rank
 *
 * @return [AccountTypes] gmRank
 */
uint32 TSPlayer::GetGMRank() 
{
    return player->GetSession()->GetSecurity();
}
    
/**
 * Returns the [Player]s amount of money in copper
 *
 * @return uint32 money
 */
uint32 TSPlayer::GetMoney() 
{
    return player->GetMoney();
}
    
/**
 * Returns the [Player]s current [Guild] ID
 *
 * @return uint32 guildId
 */
uint32 TSPlayer::GetGuildId() 
{
    return player->GetGuildId();
}
    
/**
 * Returns the [Player]s [TeamId]
 *
 * @return [TeamId] teamId
 */
uint32 TSPlayer::GetTeam() 
{
    return player->GetTeamId();
}

/**
 * Returns amount of the specified [Item] the [Player] has.
 *
 * @param uint32 entry : entry of the item
 * @param bool checkinBank = false : also counts the items in player's bank if true
 * @return uint32 itemamount
 */
uint32 TSPlayer::GetItemCount(uint32 entry,bool checkinBank) 
{
    return player->GetItemCount(entry, checkinBank);
}
    
/**
 * Returns the [Player]s lifetime Honorable Kills
 *
 * @return uint32 lifeTimeKils
 */
uint32 TSPlayer::GetLifetimeKills() 
{
    return player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
}
    
/**
 * Returns the [Player]s IP address
 *
 * @return string ip
 */
TSString TSPlayer::GetPlayerIP()
{
     return TSString(player->GetSession()->GetRemoteAddress());
}
    
/**
 * Returns the [Player]s time played at current level
 *
 * @return uint32 currLevelPlayTime
 */
uint32 TSPlayer::GetLevelPlayedTime() 
{
    return player->GetLevelPlayedTime();
}
    
/**
 * Returns the [Player]s total time played
 *
 * @return uint32 totalPlayTime
 */
uint32 TSPlayer::GetTotalPlayedTime() 
{
    return player->GetTotalPlayedTime();
}
    
/**
 * Returns the [Player]s [Guild] object
 *
 * @return [Guild] guild
 */
TSGuild  TSPlayer::GetGuild() 
{
     return TSGuild(eGuildMgr->GetGuildById(player->GetGuildId()));
}
    
/**
 * Returns the [Player]s [Group] object
 *
 * @return [Group] group
 */
TSGroup  TSPlayer::GetGroup() 
{
     return TSGroup(player->GetGroup());
}
    
/**
 * Returns the [Player]s account ID
 *
 * @return uint32 accountId
 */
uint32 TSPlayer::GetAccountId() 
{
    return player->GetSession()->GetAccountId();
}
    
/**
 * Returns the [Player]s account name
 *
 * @return string accountName
 */
TSString TSPlayer::GetAccountName()
{
    std::string accName;
#ifndef AZEROTHCORE
    if (eAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
#else
    if (AccountMgr::GetName(player->GetSession()->GetAccountId(), accName))
#endif
         return TSString(accName);
}
    
/**
 * Returns the [Player]s [Corpse] object
 *
 * @return [Corpse] corpse
 */
TSCorpse  TSPlayer::GetCorpse() 
{
     return TSCorpse(player->GetCorpse());
}
    
/**
 * Returns the [Player]s database locale index
 *
 * @return int localeIndex
 */
int TSPlayer::GetDbLocaleIndex() 
{
    return player->GetSession()->GetSessionDbLocaleIndex();
}
    
/**
 * Returns the [Player]s game client locale
 *
 * @return [LocaleConstant] locale
 */
uint32 TSPlayer::GetDbcLocale() 
{
    return player->GetSession()->GetSessionDbcLocale();
}
    
/*int TSPlayer::GetRecruiterId(lua_State* L, Player* player)
{
    return player->GetSession()->GetRecruiterId();
}*/
    
/*int TSPlayer::GetSelectedPlayer(lua_State* L, Player* player)
{
    return player->GetSelectedPlayer();
}*/
    
/*int TSPlayer::GetSelectedUnit(lua_State* L, Player* player)
{
    return player->GetSelectedUnit();
}*/
    
/*int TSPlayer::GetNearbyGameObject(lua_State* L, Player* player)
{
    return ChatHandler(player->GetSession()).GetNearbyGameObject();
}*/

/**
 * Locks the player controls and disallows all movement and casting.
 *
 * @param bool apply = true : lock if true and unlock if false
 */
void TSPlayer::SetPlayerLock(bool apply) 
{
    
    if (apply)
    {
        player->SetFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
        player->SetClientControl(player, 0);
    }
    else
    {
        player->RemoveFlag(UNIT_FIELD_FLAGS, UNIT_FLAG_PACIFIED | UNIT_FLAG_SILENCED);
        player->SetClientControl(player, 1);
    }
}
    
/**
 * Sets the [Player]s login flag to the flag specified
 *
 * @param uint32 flag
 */
void TSPlayer::SetAtLoginFlag(uint32 flag) 
{
    
    player->SetAtLoginFlag((AtLoginFlags)flag);
}
    
/**
 * Sets the [Player]s sheathe state to the state specified
 *
 * @param uint32 sheatheState
 */
void TSPlayer::SetSheath(uint32 sheathed) 
{
    
    player->SetSheath((SheathState)sheathed);
}
    
/**
 * Sets the [Player]s intoxication level to the level specified
 *
 * @param uint8 drunkValue
 */
void TSPlayer::SetDrunkValue(uint8 newDrunkValue) 
{
    
    player->SetDrunkValue(newDrunkValue);
}
    
/**
 * Sets the [Player]s faction standing to that of the race specified
 *
 * @param uint8 raceId
 */
void TSPlayer::SetFactionForRace(uint8 race) 
{
    
#ifdef TRINITY
    player->SetFactionForRace(race);
#else
    player->setFactionForRace(race);
#endif
}
    
/**
 * Sets (increases) skill of the [Player]
 *
 * @param uint16 id
 * @param uint16 step
 * @param uint16 currVal
 * @param uint16 maxVal
 */
void TSPlayer::SetSkill(uint16 id,uint16 step,uint16 currVal,uint16 maxVal) 
{
    
#ifdef TRINITY
    player->SetSkill(id, step, currVal, maxVal);
#else
    player->SetSkill(id, currVal, maxVal, step);
#endif
}
    
/**
 * Sets the [Player]s guild rank to the rank specified
 *
 * @param uint8 rank
 */
void TSPlayer::SetGuildRank(uint8 rank) 
{
    
    
    player->SetRank(rank);
}
    
/**
 * Sets the [Player]s free talent points to the amount specified for the current spec
 *
 * @param uint32 talentPointAmt
 */
void TSPlayer::SetFreeTalentPoints(uint32 points) 
{
    
    player->SetFreeTalentPoints(points);
#if (!defined(TBC) && !defined(CLASSIC))
    player->SendTalentsInfoData(false);
#endif
}
    
/**
 * Sets the [Player]s reputation amount for the faction specified
 *
 * @param uint32 factionId
 * @param int32 reputationValue
 */
void TSPlayer::SetReputation(uint32 faction,int32 value) 
{
    
    FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
    player->GetReputationMgr().SetReputation(factionEntry, value);
}
    
/**
 * Sets [Quest] state
 *
 * @param uint32 entry : entry of a quest
 * @param uint32 status
 */
void TSPlayer::SetQuestStatus(uint32 entry,uint32 status) 
{
    
    player->SetQuestStatus(entry, (QuestStatus)status);
}
    
/**
 * Sets the [Player]s rest bonus to the amount specified
 *
 * @param float restBonus
 */
void TSPlayer::SetRestBonus(float bonus) 
{
    
    player->SetRestBonus(bonus);
}
    
/**
 * Toggles whether the [Player] accepts whispers or not
 *
 * @param bool acceptWhispers = true
 */
void TSPlayer::SetAcceptWhispers(bool on) 
{
    
    player->SetAcceptWhispers(on);
}
    
/**
 * Toggles PvP Death
 *
 * @param bool on = true
 */
void TSPlayer::SetPvPDeath(bool on) 
{
    
    player->SetPvPDeath(on);
}
    
/**
 * Toggles whether the [Player] has GM visibility on or off
 *
 * @param bool gmVisible = true
 */
void TSPlayer::SetGMVisible(bool on) 
{
    
    player->SetGMVisible(on);
}
    
/**
 * Toggles whether the [Player] has taxi cheat enabled or not
 *
 * @param bool taxiCheat = true
 */
void TSPlayer::SetTaxiCheat(bool on) 
{
    
    player->SetTaxiCheater(on);
}
    
/**
 * Toggle Blizz (GM) tag
 *
 * @param bool on = true
 */
void TSPlayer::SetGMChat(bool on) 
{
    
    player->SetGMChat(on);
}
    
/**
 * Toggles the [Player]s GM mode on or off
 *
 * @param bool setGmMode = true
 */
void TSPlayer::SetGameMaster(bool on) 
{
    
    player->SetGameMaster(on);
}
    
/**
 * Sets the [Player]s gender to gender specified
 *
 * - GENDER_MALE    = 0
 * - GENDER_FEMALE  = 1
 *
 * @param [Gender] gender
 */
void TSPlayer::SetGender(uint32 _gender) 
{
    
    Gender gender;
    switch (_gender)
    {
        case 0:
            gender = GENDER_MALE;
            break;
        case 1:
            gender = GENDER_FEMALE;
            break;
    
    }
    
    player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
    player->SetByteValue(PLAYER_BYTES_3, 0, gender);
    player->InitDisplayIds();
}
    
#if defined(TBC) || defined(WOTLK)
/**
 * Sets the [Player]s Arena Points to the amount specified
 *
 * @param uint32 arenaPoints
 */
void TSPlayer::SetArenaPoints(uint32 arenaP) 
{
    player->SetArenaPoints(arenaP);
}
    
/**
 * Sets the [Player]s Honor Points to the amount specified
 *
 * @param uint32 honorPoints
 */
void TSPlayer::SetHonorPoints(uint32 honorP) 
{
    player->SetHonorPoints(honorP);
}
#endif
    
#ifdef CLASSIC
/**
 * Sets kills
 *
 * @param uint32 kills
 * @param bool honorable = true : if victims were honorable
 */
void TSPlayer::SetHonorStoredKills(uint32 kills,bool honorable) 
{
    
    player->SetHonorStoredKills(kills, honorable);
}
    
/**
 * Sets rank points
 *
 * @param float rankPoints
 */
void TSPlayer::SetRankPoints(float rankPoints) 
{
    
    player->SetRankPoints(rankPoints);
}
    
/**
 * Sets last week's honor standing position
 *
 * @param int32 standingPos
 */
void TSPlayer::SetHonorLastWeekStandingPos(int32 standingPos) 
{
    
    player->SetHonorLastWeekStandingPos(standingPos);
}
#endif
    
/**
 * Sets the [Player]s amount of Lifetime Honorable Kills to the value specified
 *
 * @param uint32 honorableKills
 */
void TSPlayer::SetLifetimeKills(uint32 val) 
{
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
}
    
/**
 * Sets the [Player]s amount of money to copper specified
 *
 * @param uint32 copperAmt
 */
void TSPlayer::SetCoinage(uint32 amt) 
{
    player->SetMoney(amt);
}
    
/**
 * Sets the [Player]s home location to the location specified
 *
 * @param float x : X Coordinate
 * @param float y : Y Coordinate
 * @param float z : Z Coordinate
 * @param uint32 mapId : Map ID
 * @param uint32 areaId : Area ID
 */
void TSPlayer::SetBindPoint(float x,float y,float z,uint32 mapId,uint32 areaId) 
{
    
WorldLocation loc(mapId, x, y, z);
#if defined TRINITY || AZEROTHCORE
    player->SetHomebind(loc, areaId);
#else
    player->SetHomebindToLocation(loc, areaId);
#endif
}
    
#ifndef CLASSIC
/**
 * Adds the specified title to the [Player]s list of known titles
 *
 * @param uint32 titleId
 */
void TSPlayer::SetKnownTitle(uint32 id) 
{
    CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
    if (t)
        player->SetTitle(t, false);
}
#endif
    
#if !defined TRINITY && !AZEROTHCORE
/**
 * Toggle the [Player]s FFA flag
 *
 * @param bool applyFFA = true
 */
void TSPlayer::SetFFA(bool apply) 
{
    
    player->SetFFAPvP(apply);
}
#endif
    
/*int TSPlayer::SetMovement(lua_State* L, Player* player)
{
    
    player->SetMovement((PlayerMovementType)pType);
}*/
    
#if (!defined(TBC) && !defined(CLASSIC))
/**
 * Resets the [Player]s pets talent points
 */
void TSPlayer::ResetPetTalents(int32 pType) 
{
#ifndef TRINITY
    Pet* pet = player->GetPet();
    Pet::resetTalentsForAllPetsOf(player, pet);
    if (pet)
        player->SendTalentsInfoData(true);
#else
    player->ResetPetTalents();
    player->SendTalentsInfoData(true);
#endif
}
    
/**
 * Reset the [Player]s completed achievements
 */
void TSPlayer::ResetAchievements() 
{
#if defined TRINITY || AZEROTHCORE
    player->ResetAchievements();
#else
    player->GetAchievementMgr().Reset();
#endif
}
#endif

/**
 * Shows the mailbox window to the player from specified guid.
 *
 * @param uint64 guid = playerguid : guid of the mailbox window sender
 */
void TSPlayer::SendShowMailBox(uint64 guid) 
{
    
#if (defined(CLASSIC) || defined(TBC))
WorldPacket data(CMSG_GET_MAIL_LIST, 8);
    data << uint64(guid);
    player->GetSession()->HandleGetMailList(data);
#else
    player->GetSession()->SendShowMailBox(ObjectGuid(guid));
#endif
}
    
#if defined(TBC) || defined(WOTLK)
/**
 * Adds or detracts from the [Player]s current Arena Points
 *
 * @param int32 amount
 */
void TSPlayer::ModifyArenaPoints(int32 amount) 
{
    
    player->ModifyArenaPoints(amount);
}
    
/**
 * Adds or detracts from the [Player]s current Honor Points
 *
 * @param int32 amount
 */
void TSPlayer::ModifyHonorPoints(int32 amount) 
{
    
    player->ModifyHonorPoints(amount);
}
#endif
    
/**
 * Saves the [Player] to the database
 */
void TSPlayer::SaveToDB() 
{
#ifndef AZEROTHCORE
    player->SaveToDB();
#else
    player->SaveToDB(false, false);
#endif
}
    
/**
 * Sends a summon request to the player from the given summoner
 *
 * @param [Unit] summoner
 */
void TSPlayer::SummonPlayer(TSUnit _summoner)
{
    auto summoner = _summoner.unit;
    
#ifdef TRINITY
    player->SendSummonRequestFrom(summoner);
#else
    float x, y, z;
    summoner->GetPosition(x,y,z);
    player->SetSummonPoint(summoner->GetMapId(), x, y, z);
    
WorldPacket data(SMSG_SUMMON_REQUEST, 8 + 4 + 4);
    data << uint64(summoner->GetGUIDLow());
    data << uint32(summoner->GetZoneId());
    data << uint32(MAX_PLAYER_SUMMON_DELAY * IN_MILLISECONDS);
#ifdef CMANGOS
    player->GetSession()->SendPacket(data);
#else
    player->GetSession()->SendPacket(&data);
#endif
#endif
}
    
/**
 * Mutes the [Player] for the amount of seconds specified
 *
 * @param uint32 muteTime
 */
void TSPlayer::Mute(uint32 muteseconds) 
{
    /*const char* reason = luaL_checkstring(E, 2);*/ // Mangos does not have a reason field in database.
    
    time_t muteTime = time(NULL) + muteseconds;
    player->GetSession()->m_muteTime = muteTime;
    std::ostringstream oss;
    oss << "UPDATE account SET mutetime = " << muteTime << " WHERE id = " << player->GetSession()->GetAccountId();
    LoginDatabase.PExecute("%s", oss.str().c_str());
}
    
/**
 * Rewards the given quest entry for the [Player] if he has completed it.
 *
 * @param uint32 entry : quest entry
 */
void TSPlayer::RewardQuest(uint32 entry) 
{
    
    Quest const* quest = eObjectMgr->GetQuestTemplate(entry);
    
    // If player doesn't have the quest
    
    player->RewardQuest(quest, 0, player);
}
    
/**
 * Sends an auction house window to the [Player] from the [Unit] specified
 *
 * @param [Unit] sender
 */
void TSPlayer::SendAuctionMenu(TSUnit _unit)
{
    auto unit = _unit.unit;
    
#ifdef TRINITY
    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->GetFaction());
#elif AZEROTHCORE
    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->getFaction());
#else
    AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit);
#endif
    
WorldPacket data(MSG_AUCTION_HELLO, 12);
#ifdef TRINITY
    data << uint64(unit->GetGUID().GetCounter());
#else
    data << uint64(unit->GetGUIDLow());
#endif
    data << uint32(ahEntry->ID);
    data << uint8(1);
#ifdef CMANGOS
    player->GetSession()->SendPacket(data);
#else
    player->GetSession()->SendPacket(&data);
#endif
}
    
/**
 * Sends a flightmaster window to the [Player] from the [Creature] specified
 *
 * @param [Creature] sender
 */
void TSPlayer::SendTaxiMenu(TSCreature _creature)
{
    auto creature = _creature.creature;
    
    player->GetSession()->SendTaxiMenu(creature);
}
    
/**
 * Sends a spirit resurrection request to the [Player]
 */
void TSPlayer::SendSpiritResurrect() 
{
    player->GetSession()->SendSpiritResurrect();
}
    
/**
 * Sends a tabard vendor window to the [Player] from the [WorldObject] specified
 *
 * @param [WorldObject] sender
 */
void TSPlayer::SendTabardVendorActivate(TSWorldObject _obj)
{
    auto obj = _obj.obj;
    
    player->GetSession()->SendTabardVendorActivate(obj->TS_GET_GUID());
}
    
/**
 * Sends a bank window to the [Player] from the [WorldObject] specified.
 *
 * @param [WorldObject] sender
 */
void TSPlayer::SendShowBank(TSWorldObject _obj)
{
    auto obj = _obj.obj;
    
    player->GetSession()->SendShowBank(obj->TS_GET_GUID());
}

/**
 * Sends a vendor window to the [Player] from the [WorldObject] specified.
 *
 * @param [WorldObject] sender
 */
void TSPlayer::SendListInventory(TSWorldObject _obj)
{
    auto obj = _obj.obj;
    
    player->GetSession()->SendListInventory(obj->TS_GET_GUID());
}
    
/**
 * Sends a trainer window to the [Player] from the [Creature] specified
 *
 * @param [Creature] sender
 */
void TSPlayer::SendTrainerList(TSCreature _obj)
{
    auto obj = _obj.creature;
    
#ifdef TRINITY
    player->GetSession()->SendTrainerList(obj);
#else
    player->GetSession()->SendTrainerList(obj->TS_GET_GUID());
#endif
}
    
/**
 * Sends a guild invitation from the [Player]s [Guild] to the [Player] object specified
 *
 * @param [Player] invitee
 */
void TSPlayer::SendGuildInvite(TSPlayer _plr)
{
    auto plr = _plr.player;
    
#if defined TRINITY || AZEROTHCORE
    if (Guild* guild = player->GetGuild())
        guild->HandleInviteMember(player->GetSession(), plr->GetName());
#else
    player->GetSession()->SendGuildInvite(plr);
#endif
}
    
/**
 * Forces the [Player] to log out
 *
 * @param bool saveToDb = true
 */
void TSPlayer::LogoutPlayer(bool save) 
{
    
    player->GetSession()->LogoutPlayer(save);
}
    
/**
 * Forcefully removes the [Player] from a [BattleGround] raid group
 */
void TSPlayer::RemoveFromBattlegroundRaid() 
{
#if defined TRINITY || AZEROTHCORE
    player->RemoveFromBattlegroundOrBattlefieldRaid();
#else
    player->RemoveFromBattleGroundRaid();
#endif
}
    
/**
 * Unbinds the [Player] from his instances except the one he currently is in.
 *
 * Difficulty is not used on classic.
 *
 * @param uint32 map = true
 * @param uint32 difficulty = 0
 */
void TSPlayer::UnbindInstance(uint32 map,uint32 difficulty) 
{
#ifndef CLASSIC
    
    if (difficulty < MAX_DIFFICULTY)
#ifndef AZEROTHCORE
        player->UnbindInstance(map, (Difficulty)difficulty);
#else
        sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUIDLow(), map, Difficulty(difficulty), true, player);
#endif//AZEROTHCORE
#else//CLASSIC
    player->UnbindInstance(map);
#endif
}
    
/**
 * Unbinds the [Player] from his instances except the one he currently is in.
 */
void TSPlayer::UnbindAllInstances() 
{
#ifdef CLASSIC
    Player::BoundInstancesMap& binds = player->GetBoundInstances();
    for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
    {
        if (itr->first != player->GetMapId())
            player->UnbindInstance(itr);
        else
            ++itr;
    }
#elif defined AZEROTHCORE
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        const BoundInstancesMap& binds = sInstanceSaveMgr->PlayerGetBoundInstances(player->GetGUIDLow(), Difficulty(i));
        for (BoundInstancesMap::const_iterator itr = binds.begin(); itr != binds.end();)
        {
            if (itr->first != player->GetMapId())
                //player->UnbindInstance(itr, Difficulty(i));
                sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUIDLow(), itr->first, Difficulty(i), true, player);
            else
                ++itr;
        }
    }
#else
    for (uint8 i = 0; i < MAX_DIFFICULTY; ++i)
    {
        Player::BoundInstancesMap& binds = player->GetBoundInstances(Difficulty(i));
        for (Player::BoundInstancesMap::iterator itr = binds.begin(); itr != binds.end();)
        {
            if (itr->first != player->GetMapId())
                player->UnbindInstance(itr, Difficulty(i));
            else
                ++itr;
        }
    }
#endif
}
    
/**
 * Forces the [Player] to leave a [BattleGround]
 *
 * @param bool teleToEntry = true
 */
void TSPlayer::LeaveBattleground(bool teleToEntryPoint) 
{
    
#ifndef AZEROTHCORE
    player->LeaveBattleground(teleToEntryPoint);
#else
    player->LeaveBattleground();
#endif
}
    
/**
 * Repairs [Item] at specified position. Returns total repair cost 
 *
 * @param uint16 position
 * @param bool cost = true
 * @param float discountMod
 * @param bool guildBank = false
 * @return uint32 totalCost
 */
uint32 TSPlayer::DurabilityRepair(uint16 position,bool cost,float discountMod,bool guildBank) 
{
    
#ifdef CLASSIC
    return player->DurabilityRepair(position, cost, discountMod);
#else
    return player->DurabilityRepair(position, cost, discountMod, guildBank);
#endif
}
    
/**
 * Repairs all [Item]s. Returns total repair cost
 *
 * @param bool cost = true
 * @param float discountMod = 1
 * @param bool guidBank = false
 * @return uint32 totalCost
 */
uint32 TSPlayer::DurabilityRepairAll(bool cost,float discountMod,bool guildBank) 
{
    
#ifdef CLASSIC
    return player->DurabilityRepairAll(cost, discountMod);
#else
    return player->DurabilityRepairAll(cost, discountMod, guildBank);
#endif
}
    
/**
 * Sets durability loss for an [Item] in the specified slot
 *
 * @param int32 slot
 */
void TSPlayer::DurabilityPointLossForEquipSlot(int32 slot) 
{
    
    if (slot >= EQUIPMENT_SLOT_START && slot < EQUIPMENT_SLOT_END)
        player->DurabilityPointLossForEquipSlot((EquipmentSlots)slot);
}
    
/**
 * Sets durability loss on all [Item]s equipped
 *
 * If inventory is true, sets durability loss for [Item]s in bags
 *
 * @param int32 points
 * @param bool inventory = true
 */
void TSPlayer::DurabilityPointsLossAll(int32 points,bool inventory) 
{
    
    player->DurabilityPointsLossAll(points, inventory);
}
    
/**
 * Sets durability loss for the specified [Item]
 *
 * @param [Item] item
 * @param int32 points
 */
void TSPlayer::DurabilityPointsLoss(TSItem _item,int32 points)
{
    auto item = _item.item;
    
    player->DurabilityPointsLoss(item, points);
}
    
/**
 * Damages specified [Item]
 *
 * @param [Item] item
 * @param double percent
 */
void TSPlayer::DurabilityLoss(TSItem _item,double percent)
{
    auto item = _item.item;
    
    player->DurabilityLoss(item, percent);
}
    
/**
 * Damages all [Item]s equipped. If inventory is true, damages [Item]s in bags
 *
 * @param double percent
 * @param bool inventory = true
 */
void TSPlayer::DurabilityLossAll(double percent,bool inventory) 
{
    
    player->DurabilityLossAll(percent, inventory);
}
    
/**
 * Kills the [Player]
 */
void TSPlayer::KillPlayer() 
{
    player->KillPlayer();
}
    
/**
 * Forces the [Player] to leave a [Group]
 */
void TSPlayer::RemoveFromGroup() 
{
    
    player->RemoveFromGroup();
}
    
/**
 * Returns the [Player]s accumulated talent reset cost
 *
 * @return uint32 resetCost
 */
uint32 TSPlayer::ResetTalentsCost() 
{
#ifdef CATA
    return player->GetNextResetTalentsCost();
#else
#ifdef TRINITY
    return player->ResetTalentsCost();
#else
    return player->resetTalentsCost();
#endif
#endif
}
    
/**
 * Resets the [Player]s talents
 *
 * @param bool noCost = true
 */
void TSPlayer::ResetTalents(bool no_cost) 
{
    
#ifdef CATA
    player->ResetTalents(no_cost);
#else
#ifdef TRINITY
    player->ResetTalents(no_cost);
#else
    player->resetTalents(no_cost);
#endif
#endif
#if (!defined(TBC) && !defined(CLASSIC))
    player->SendTalentsInfoData(false);
#endif
}
    
/**
 * Removes the [Spell] from the [Player]
 *
 * @param uint32 entry : entry of a [Spell]
 * @param bool disabled = false
 * @param bool learnLowRank = true
 */
void TSPlayer::RemoveSpell(uint32 entry,bool disabled,bool learn_low_rank) 
{
    
#ifdef TRINITY
    player->RemoveSpell(entry, disabled, learn_low_rank);
#else
    player->removeSpell(entry, disabled, learn_low_rank);
#endif
}
    
/**
 * Clears the [Player]s combo points
 */
void TSPlayer::ClearComboPoints() 
{
    player->ClearComboPoints();
}
    
/**
 * Adds combo points to the [Player]
 *
 * @param [Unit] target
 * @param int8 count
 */
void TSPlayer::AddComboPoints(TSUnit _target,int8 count)
{
    auto target = _target.unit;
    
    player->AddComboPoints(target, count);
}
    
/**
 * Gives [Quest] monster talked to credit
 *
 * @param uint32 entry : entry of a [Creature]
 * @param [Creature] creature
 */
void TSPlayer::TalkedToCreature(uint32 entry,TSCreature _creature)
{
    auto creature = _creature.creature;
    
    player->TalkedToCreature(entry, creature->TS_GET_GUID());
}
    
/**
 * Gives [Quest] monster killed credit
 *
 * @param uint32 entry : entry of a [Creature]
 */
void TSPlayer::KilledMonsterCredit(uint32 entry) 
{
    
    player->KilledMonsterCredit(entry, player->TS_GET_GUID());
}
    
/**
 * Completes a [Quest] if in a [Group]
 *
 * @param uint32 quest : entry of a quest
 * @param [WorldObject] obj
 */
void TSPlayer::GroupEventHappens(uint32 questId,TSWorldObject _obj)
{
    auto obj = _obj.obj;
    
    player->GroupEventHappens(questId, obj);
}
    
/**
 * Completes the [Quest] if a [Quest] area is explored, or completes the [Quest]
 *
 * @param uint32 quest : entry of a [Quest]
 */
void TSPlayer::AreaExploredOrEventHappens(uint32 questId) 
{
    
    player->AreaExploredOrEventHappens(questId);
}
    
/**
 * Sets the given [Quest] entry failed for the [Player].
 *
 * @param uint32 entry : entry of a [Quest]
 */
void TSPlayer::FailQuest(uint32 entry) 
{
    
    player->FailQuest(entry);
}
    
/**
 * Sets the given quest entry incomplete for the [Player].
 *
 * @param uint32 entry : quest entry
 */
void TSPlayer::IncompleteQuest(uint32 entry) 
{
    
    player->IncompleteQuest(entry);
}
    
/**
 * Completes the given quest entry for the [Player] and tries to satisfy all quest requirements.
 *
 * The player should have the quest to complete it.
 *
 * @param uint32 entry : quest entry
 */
void TSPlayer::CompleteQuest(uint32 entry) 
{
    
    Quest const* quest = eObjectMgr->GetQuestTemplate(entry);
    
    // If player doesn't have the quest
    
    // Add quest items for quests that require items
    for (uint8 x = 0; x < QUEST_ITEM_OBJECTIVES_COUNT; ++x)
    {
#if defined TRINITY || AZEROTHCORE
        uint32 id = quest->RequiredItemId[x];
        uint32 count = quest->RequiredItemCount[x];
#else
        uint32 id = quest->ReqItemId[x];
        uint32 count = quest->ReqItemCount[x];
#endif
    
        if (!id || !count)
            continue;
    
        uint32 curItemCount = player->GetItemCount(id, true);
    
        ItemPosCountVec dest;
        uint8 msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, id, count - curItemCount);
        if (msg == EQUIP_ERR_OK)
        {
            Item* item = player->StoreNewItem(dest, id, true);
            player->SendNewItem(item, count - curItemCount, true, false);
        }
    }
    
    // All creature/GO slain/cast (not required, but otherwise it will display "Creature slain 0/10")
    for (uint8 i = 0; i < QUEST_OBJECTIVES_COUNT; ++i)
    {
#if defined TRINITY || AZEROTHCORE
        int32 creature = quest->RequiredNpcOrGo[i];
        uint32 creatureCount = quest->RequiredNpcOrGoCount[i];
    
        if (creature > 0)
        {
            if (CreatureTemplate const* creatureInfo = sObjectMgr->GetCreatureTemplate(creature))
                for (uint16 z = 0; z < creatureCount; ++z)
#ifndef AZEROTHCORE
                    player->KilledMonster(creatureInfo, ObjectGuid::Empty);
#else
                    player->KilledMonster(creatureInfo, 0);
#endif
        }
        else if (creature < 0)
            for (uint16 z = 0; z < creatureCount; ++z)
                player->KillCreditGO(creature);
#else
        int32 creature = quest->ReqCreatureOrGOId[i];
        uint32 creaturecount = quest->ReqCreatureOrGOCount[i];
    
        if (uint32 spell_id = quest->ReqSpell[i])
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                player->CastedCreatureOrGO(creature, ObjectGuid(), spell_id);
        }
        else if (creature > 0)
        {
            if (CreatureInfo const* cInfo = ObjectMgr::GetCreatureTemplate(creature))
                for (uint16 z = 0; z < creaturecount; ++z)
                    player->KilledMonster(cInfo, ObjectGuid());
        }
        else if (creature < 0)
        {
            for (uint16 z = 0; z < creaturecount; ++z)
                player->CastedCreatureOrGO(-creature, ObjectGuid(), 0);
        }
#endif
    }
    
    
    // If the quest requires reputation to complete
    if (uint32 repFaction = quest->GetRepObjectiveFaction())
    {
        uint32 repValue = quest->GetRepObjectiveValue();
        uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
        if (curRep < repValue)
            if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(repFaction))
                player->GetReputationMgr().SetReputation(factionEntry, repValue);
    }
    
#if defined TRINITY || AZEROTHCORE
    // If the quest requires a SECOND reputation to complete
    if (uint32 repFaction = quest->GetRepObjectiveFaction2())
    {
        uint32 repValue2 = quest->GetRepObjectiveValue2();
        uint32 curRep = player->GetReputationMgr().GetReputation(repFaction);
        if (curRep < repValue2)
            if (FactionEntry const* factionEntry = sFactionStore.LookupEntry(repFaction))
                player->GetReputationMgr().SetReputation(factionEntry, repValue2);
    }
#endif
    
    // If the quest requires money
    int32 ReqOrRewMoney = quest->GetRewOrReqMoney();
    if (ReqOrRewMoney < 0)
        player->ModifyMoney(-ReqOrRewMoney);
    
#ifdef TRINITY
    if (sWorld->getBoolConfig(CONFIG_QUEST_ENABLE_QUEST_TRACKER)) // check if Quest Tracker is enabled
    {
        // prepare Quest Tracker datas
        CharacterDatabasePreparedStatement* stmt = CharacterDatabase.GetPreparedStatement(CHAR_UPD_QUEST_TRACK_GM_COMPLETE);
        stmt->setUInt32(0, quest->GetQuestId());
        stmt->setUInt32(1, player->GetGUID().GetCounter());
    
        // add to Quest Tracker
        CharacterDatabase.Execute(stmt);
    }
#endif
    
    player->CompleteQuest(entry);
}
    
/**
 * Tries to add the given quest entry for the [Player].
 *
 * @param uint32 entry : quest entry
 */
void TSPlayer::AddQuest(uint32 entry) 
{
    
    Quest const* quest = eObjectMgr->GetQuestTemplate(entry);
    
    
#if defined TRINITY || AZEROTHCORE
    // check item starting quest (it can work incorrectly if added without item in inventory)
#ifndef AZEROTHCORE
    ItemTemplateContainer const& itc = sObjectMgr->GetItemTemplateStore();

    auto itr = std::find_if(std::begin(itc), std::end(itc), [quest](ItemTemplateContainer::value_type const& value)
    {
        // TODO: Fix
        return false;
    });
    
#else
    ItemTemplateContainer const* itc = sObjectMgr->GetItemTemplateStore();
    ItemTemplateContainer::const_iterator result = find_if(itc->begin(), itc->end(), Finder<uint32, ItemTemplate>(entry, &ItemTemplate::StartQuest));
    
#endif
    // ok, normal (creature/GO starting) quest
    if (player->CanAddQuest(quest, true))
        player->AddQuestAndCheckCompletion(quest, NULL);
#else
    // check item starting quest (it can work incorrectly if added without item in inventory)
    for (uint32 id = 0; id < sItemStorage.GetMaxEntry(); ++id)
    {
        ItemPrototype const* pProto = sItemStorage.LookupEntry<ItemPrototype>(id);
        if (!pProto)
            continue;
    
    }
    
    // ok, normal (creature/GO starting) quest
    if (player->CanAddQuest(quest, true))
    {
        player->AddQuest(quest, NULL);
    
        if (player->CanCompleteQuest(entry))
            player->CompleteQuest(entry);
    }
#endif
    
}
    
/**
 * Removes the given quest entry from the [Player].
 *
 * @param uint32 entry : quest entry
 */
void TSPlayer::RemoveQuest(uint32 entry) 
{
    
    Quest const* quest = eObjectMgr->GetQuestTemplate(entry);
    
    
    // remove all quest entries for 'entry' from quest log
    for (uint8 slot = 0; slot < MAX_QUEST_LOG_SIZE; ++slot)
    {
        uint32 logQuest = player->GetQuestSlotQuestId(slot);
        if (logQuest == entry)
        {
            player->SetQuestSlot(slot, 0);
    
            // we ignore unequippable quest items in this case, its' still be equipped
            player->TakeQuestSourceItem(logQuest, false);
    
#if defined TRINITY || AZEROTHCORE
            if (quest->HasFlag(QUEST_FLAGS_FLAGS_PVP))
            {
                player->pvpInfo.IsHostile = player->pvpInfo.IsInHostileArea || player->HasPvPForcingQuest();
                player->UpdatePvPState();
            }
#endif
        }
    }
    
#if defined TRINITY || AZEROTHCORE
    player->RemoveActiveQuest(entry, false);
    player->RemoveRewardedQuest(entry);
#else
    // set quest status to not started (will updated in DB at next save)
    player->SetQuestStatus(entry, QUEST_STATUS_NONE);
    
    // reset rewarded for restart repeatable quest
    player->getQuestStatusMap()[entry].m_rewarded = false;
#endif
}
    
/**
 * Sends whisper text from the [Player]
 *
 * @param string text
 * @param uint32 lang : language the [Player] will speak
 * @param [Player] receiver : is the [Player] that will receive the whisper, if TrinityCore
 * @param uint64 guid : is the GUID of a [Player] that will receive the whisper, not TrinityCore
 */
void TSPlayer::Whisper(TSString _text,uint32 lang,TSPlayer _receiver,uint64 guid)
{
    auto receiver = _receiver.player;
    auto text = _text._value;
#ifdef TRINITY
#else
#endif
#ifdef TRINITY
    player->Whisper(text, (Language)lang, receiver);
#else
    player->Whisper(text, lang, ObjectGuid(guid));
#endif
}
    
/**
 * Sends a text emote from the [Player]
 *
 * @param string emoteText
 */
void TSPlayer::TextEmote(TSString _text)
{
    auto text = _text._value;
    
    player->TextEmote(text);
}
    
/**
 * Sends yell text from the [Player]
 *
 * @param string text : text for the [Player] to yells
 * @param uint32 lang : language the [Player] will speak
 */
void TSPlayer::Yell(TSString _text,uint32 lang)
{
    auto text = _text._value;
#ifdef TRINITY
    player->Yell(text, (Language)lang);
#else
    player->Yell(text, lang);
#endif
}
    
/**
 * Sends say text from the [Player]
 *
 * @param string text : text for the [Player] to say
 * @param uint32 lang : language the [Player] will speak
 */
void TSPlayer::Say(TSString _text,uint32 lang)
{
    auto text = _text._value;
#ifdef TRINITY
    player->Say(text, (Language)lang);
#else
    player->Say(text, lang);
#endif
}
    
/**
 * Gives the [Player] experience
 *
 * @param uint32 xp : experience to give
 * @param [Unit] victim = nil
 */
void TSPlayer::GiveXP(uint32 xp,TSUnit _victim)
{
    auto victim = _victim.unit;
    player->GiveXP(xp, victim);
}

/**
 * Sets the [Player] experience
 * 
 * @param uint32 xp : experience to set
 */
void TSPlayer::SetXP(uint32 xp)
{
    uint32 nextLvlXP = player->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    uint32 newXP = player->GetXP() + xp;
    uint8 level = player->GetLevel();

    while (newXP >= nextLvlXP && !player->IsMaxLevel())
    {
        newXP -= nextLvlXP;
        if (!player->IsMaxLevel())
            player->GiveLevel(level + 1);
        level = player->GetLevel();
        nextLvlXP = player->GetUInt32Value(PLAYER_NEXT_LEVEL_XP);
    }

    player->SetXP(newXP);
}

uint32 TSPlayer::GetXP()
{
    return player->GetXP();
}

void TSPlayer::AddXP(uint32 xp)
{
    this->SetXP(this->GetXP()+xp);
}

/**
 * Toggle the [Player]s 'Do Not Disturb' flag
 */
void TSPlayer::ToggleDND() 
{
    player->ToggleDND();
}
    
/**
 * Toggle the [Player]s 'Away From Keyboard' flag
 */
void TSPlayer::ToggleAFK() 
{
    player->ToggleAFK();
}
    
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
TSItem TSPlayer::EquipItem(TSItem _item,uint32 slot,uint32 entry)
{
    auto item = _item.item;
    uint16 dest = 0;
    
    
    if (!item)
    {
        item = Item::CreateItem(entry, 1, player);
    
        InventoryResult result = player->CanEquipItem(slot, dest, item, false);
        if (result != EQUIP_ERR_OK)
        {
            delete item;
        }
        player->ItemAddedQuestCheck(entry, 1);
#if (!defined(TBC) && !defined(CLASSIC))
        player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, entry, 1);
#endif
    }
    else
    {
        InventoryResult result = player->CanEquipItem(slot, dest, item, false);
        player->RemoveItem(item->GetBagSlot(), item->GetSlot(), true);
    }
     return TSItem(player->EquipItem(dest, item, true));
    player->AutoUnequipOffhandIfNeed();
}

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
bool TSPlayer::CanEquipItem(TSItem _item,uint32 slot,uint32 entry)
{
    auto item = _item.item;
    if (slot >= EQUIPMENT_SLOT_END)
    {
        return false;
    }
    
    if (!item)
    {
        uint16 dest;
        InventoryResult msg = player->CanEquipNewItem(slot, dest, entry, false);
        if (msg != EQUIP_ERR_OK)
        {
            return false;
        }
    }
    else
    {
        uint16 dest;
        InventoryResult msg = player->CanEquipItem(slot, dest, item, false);
        if (msg != EQUIP_ERR_OK)
        {
            return false;
        }
    }
    return true;
}
    
#ifndef CLASSIC
/**
 * Removes a title by ID from the [Player]s list of known titles
 *
 * @param uint32 titleId
 */
void TSPlayer::UnsetKnownTitle(uint32 id) 
{
    CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
    if (t)
        player->SetTitle(t, true);
}
#endif
    
/**
 * Advances all of the [Player]s weapon skills to the maximum amount available
 */
void TSPlayer::AdvanceSkillsToMax() 
{
#ifdef TRINITY
    player->UpdateWeaponsSkillsToMaxSkillsForLevel();
#else
    player->UpdateSkillsToMaxSkillsForLevel();
#endif
}
    
/**
 * Advances all of the [Player]s skills to the amount specified
 *
 * @param uint32 skillStep
 */
void TSPlayer::AdvanceAllSkills(uint32 step) 
{
    
    
    for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
    {
        if (SkillLineEntry const* entry = sSkillLineStore.LookupEntry(i))
        {
            if (entry->CategoryID == SKILL_CATEGORY_LANGUAGES || entry->CategoryID == SKILL_CATEGORY_GENERIC)
                continue;
    
            if (player->HasSkill(entry->ID))
                player->UpdateSkill(entry->ID, step);
        }
    }
    
}
    
/**
 * Advances a [Player]s specific skill to the amount specified
 *
 * @param uint32 skillId
 * @param uint32 skillStep
 */
void TSPlayer::AdvanceSkill(uint32 _skillId,uint32 _step) 
{
    if (_skillId && _step)
    {
        if (player->HasSkill(_skillId))
            player->UpdateSkill(_skillId, _step);
    }
}
    
/**
 * Teleports a [Player] to the location specified
 *
 * @param uint32 mappId
 * @param float xCoord
 * @param float yCoord
 * @param float zCoord
 * @param float orientation
 */
bool TSPlayer::Teleport(uint32 mapId,float x,float y,float z,float o) 
{
#if defined AZEROTHCORE
    if (player->IsInFlight())
    {
        player->GetMotionMaster()->MovementExpired();
        player->m_taxi.ClearTaxiDestinations();
    }
#elif defined TRINITY
    if (player->IsInFlight())
        player->FinishTaxiFlight();
    else
        player->SaveRecallPosition();
#else
    if (player->IsTaxiFlying())
    {
        player->GetMotionMaster()->MovementExpired();
        player->m_taxi.ClearTaxiDestinations();
    }
#endif
    return player->TeleportTo(mapId, x, y, z, o);
}
    
void TSPlayer::AddLifetimeKills(uint32 val) 
{
    uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
}

/**
 * Adds the given amount of the specified item entry to the player.
 *
 * @param uint32 entry : entry of the item to add
 * @param uint32 itemCount = 1 : amount of the item to add
 * @return [Item] item : the item that was added or nil
 */
TSItem  TSPlayer::AddItem(uint32 itemId,uint32 itemCount) 
{
    
#if defined TRINITY || AZEROTHCORE
    uint32 noSpaceForCount = 0;
    ItemPosCountVec dest;
    InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, itemCount, &noSpaceForCount);
    if (msg != EQUIP_ERR_OK)
        itemCount -= noSpaceForCount;
    
#ifndef AZEROTHCORE
    Item* item = player->StoreNewItem(dest, itemId, true, GenerateItemRandomPropertyId(itemId));
#else
    Item* item = player->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
#endif
    if (item)
        player->SendNewItem(item, itemCount, true, false);
     return TSItem(item);
#else
     return TSItem(player->StoreNewItemInInventorySlot(itemId, itemCount));
#endif
}

/**
 * Removes the given amount of the specified [Item] from the player.
 *
 * @proto (item, itemCount)
 * @proto (entry, itemCount)
 * @param [Item] item : item to remove
 * @param uint32 entry : entry of the item to remove
 * @param uint32 itemCount = 1 : amount of the item to remove
 */
void TSPlayer::RemoveItem(TSItem _item,uint32 itemCount,uint32 itemId)
{
    auto item = _item.item;
    if (!item)
    {
        player->DestroyItemCount(itemId, itemCount, true);
    }
    else
    {
        bool all = itemCount >= item->GetCount();
        player->DestroyItemCount(item, itemCount, true);
    }
}
    
/**
 * Removes specified amount of lifetime kills
 *
 * @param uint32 val : kills to remove
 */
void TSPlayer::RemoveLifetimeKills(uint32 val) 
{
    uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
    if (val > currentKills)
        val = currentKills;
    player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
}
    
/**
 * Resets cooldown of the specified spell
 *
 * @param uint32 spellId
 * @param bool update = true
 */
void TSPlayer::ResetSpellCooldown(uint32 spellId,bool update) 
{
#ifdef TRINITY
    player->GetSpellHistory()->ResetCooldown(spellId, update);
#else
    player->RemoveSpellCooldown(spellId, update);
#endif
}
    
/**
 * Resets cooldown of the specified category
 *
 * @param uint32 category
 * @param bool update = true
 */
void TSPlayer::ResetTypeCooldowns(uint32 category,bool update) 
{
    (void)update; // ensure that the variable is referenced in order to pass compiler checks
    
#ifdef TRINITY
    player->GetSpellHistory()->ResetCooldowns([category](SpellHistory::CooldownStorageType::iterator itr) -> bool
    {
        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
        // TODO: Fix
        return false;
    }, update);
#else
#ifndef AZEROTHCORE
    player->RemoveSpellCategoryCooldown(category, update);
#else
    player->RemoveCategoryCooldown(category);
#endif
#endif
}
    
/**
 * Resets all of the [Player]'s cooldowns
 */
void TSPlayer::ResetAllCooldowns() 
{
#ifdef TRINITY
    player->GetSpellHistory()->ResetAllCooldowns();
#else
    player->RemoveAllSpellCooldown();
#endif
}
    
/**
 * Sends a Broadcast Message to the [Player]
 *
 * @param string message
 */
void TSPlayer::SendBroadcastMessage(TSString message) 
{
    if (message.length() > 0)
        ChatHandler(player->GetSession()).SendSysMessage(message._value.c_str());
}
    
/**
 * Sends an Area Trigger Message to the [Player]
 *
 * @param string message
 */
void TSPlayer::SendAreaTriggerMessage(TSString _msg)
{
    auto msg = _msg._value;
    if (msg.length() > 0)
        player->GetSession()->SendAreaTriggerMessage("%s", msg.c_str());
}
    
/**
 * Sends a Notification to the [Player]
 *
 * @param string message
 */
void TSPlayer::SendNotification(TSString _msg)
{
    auto msg = _msg._value;
    if (msg.length() > 0)
        player->GetSession()->SendNotification("%s", msg.c_str());
}
    
/**
 * Sends a [WorldPacket] to the [Player]
 *
 * @param [WorldPacket] packet
 * @param bool selfOnly = true
 */
void TSPlayer::SendPacketPlayer(TSWorldPacket _data,bool selfOnly)
{
    auto data = _data.packet;
#ifdef CMANGOS
    if (selfOnly)
        player->GetSession()->SendPacket(*data);
    else
        player->SendMessageToSet(*data, true);
#else
    if (selfOnly)
        player->GetSession()->SendPacket(data);
    else
        player->SendMessageToSet(data, true);
#endif
}
    
/**
 * Sends addon message to the [Player] receiver
 *
 * @param string prefix
 * @param string message
 * @param [ChatMsg] channel
 * @param [Player] receiver
 *
 */
void TSPlayer::SendAddonMessage(TSString _prefix,TSString _message,uint8 channel,TSPlayer _receiver)
{
    auto receiver = _receiver.player;
    auto prefix = _prefix._value;
    auto message = _message._value;
    
    std::string fullmsg = prefix + "\t" + message;
    
WorldPacket data(SMSG_MESSAGECHAT, 100);
    data << uint8(channel);
    data << int32(LANG_ADDON);
    data << uint64(player->TS_GET_GUID());
#ifndef CLASSIC
    data << uint32(0);
    data << uint64(receiver->TS_GET_GUID());
#endif
    data << uint32(fullmsg.length() + 1);
    data << fullmsg;
    data << uint8(0);
#ifdef CMANGOS
    receiver->GetSession()->SendPacket(data);
#else
    receiver->GetSession()->SendPacket(&data);
#endif
}
    
/**
 * Kicks the [Player] from the server
 */
void TSPlayer::KickPlayer() 
{
#ifdef TRINITY
    player->GetSession()->KickPlayer("PlayerMethods::KickPlayer Kick the player");
#else
    player->GetSession()->KickPlayer();
#endif
}
    
/**
 * Adds or subtracts from the [Player]s money in copper
 *
 * @param int32 copperAmt : negative to remove, positive to add
 */
void TSPlayer::ModifyMoney(int32 amt) 
{
    
    player->ModifyMoney(amt);
}
    
/**
 * Teaches the [Player] the [Spell] specified by entry ID
 *
 * @param uint32 spellId
 */
void TSPlayer::LearnSpell(uint32 id) 
{
    
#ifdef TRINITY
    player->LearnSpell(id, false);
#elif AZEROTHCORE
    player->learnSpell(id);
#else
    player->learnSpell(id, false);
#endif
}
    
/**
 * Learn the [Player] the talent specified by talent_id and talentRank
 *
 * @param uint32 talent_id
 * @param uint32 talentRank
 */
void TSPlayer::LearnTalent(uint32 id,uint32 rank) 
{
    
    player->LearnTalent(id, rank);
#if (!defined(TBC) && !defined(CLASSIC))
    player->SendTalentsInfoData(false);
#endif
    
#if !defined TRINITY && !AZEROTHCORE
    // if player has a pet, update owner talent auras
    if (player->GetPet())
        player->GetPet()->CastOwnerTalentAuras();
#endif
}
    
/**
 * Resurrects the [Player].
 *
 * @param float healthPercent = 100.0f
 * @param bool ressSickness = false
 */
void TSPlayer::ResurrectPlayer(float percent,bool sickness) 
{
    player->ResurrectPlayer(percent, sickness);
    player->SpawnCorpseBones();
}
    
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
void TSPlayer::GossipMenuAddItem(uint32 _icon,TSString msg,uint32 _sender,uint32 _intid,bool _code,TSString _promptMsg,uint32 _money) 
{
#if defined TRINITY || AZEROTHCORE
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, _icon, msg._value, _sender, _intid, _promptMsg._value, _money, _code);
#else
#ifndef CLASSIC
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg._value, _sender, _intid, _promptMsg._value, _money, _code);
#else
    player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg._value, _sender, _intid, _promptMsg._value, _code);
#endif
#endif//TRINITY
}
    
/**
 * Closes the [Player]s currently open Gossip Menu.
 *
 * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipSendMenu], [Player:GossipClearMenu]
 */
void TSPlayer::GossipComplete() 
{
#if defined TRINITY || AZEROTHCORE
    player->PlayerTalkClass->SendCloseGossip();
#else
    player->PlayerTalkClass->CloseGossip();
#endif
}
    
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
void TSPlayer::GossipSendMenu(uint32 npc_text,TSObject _sender,uint32 menu_id)
{
    auto sender = _sender.obj;
    if (sender->GetTypeId() == TYPEID_PLAYER)
    {
        player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
    }
    player->PlayerTalkClass->SendGossipMenu(npc_text, sender->TS_GET_GUID());
}
    
/**
 * Clears the [Player]s current gossip item list.
 *
 * See also: [Player:GossipMenuAddItem], [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete]
 * 
 *     Note: This is needed when you show a gossip menu without using gossip hello or select hooks which do this automatically.
 *     Usually this is needed when using [Player] is the sender of a Gossip Menu.
 */
void TSPlayer::GossipClearMenu() 
{
    player->PlayerTalkClass->ClearMenus();
}
    
/**
 * Attempts to start the taxi/flying to the given pathID
 *
 * @param uint32 pathId : pathId from DBC or [Global:AddTaxiPath]
 */
void TSPlayer::StartTaxi(uint32 pathId) 
{
    
    player->ActivateTaxiPathTo(pathId);
}
    
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
void TSPlayer::GossipSendPOI(float x,float y,uint32 icon,uint32 flags,uint32 data,TSString _iconText)
{
    auto iconText = _iconText._value;
    
WorldPacket packet(SMSG_GOSSIP_POI, 4 + 4 + 4 + 4 + 4 + 10);
    packet << flags;
    packet << x;
    packet << y;
    packet << icon;
    packet << data;
    packet << iconText;
#ifdef CMANGOS
    player->GetSession()->SendPacket(packet);
#else
    player->GetSession()->SendPacket(&packet);
#endif
}
    
/**
 * Adds the gossip items to the [Player]'s gossip for the quests the given [WorldObject] can offer to the player.
 *
 * @param [WorldObject] source : a questgiver with quests
 */
void TSPlayer::GossipAddQuests(TSWorldObject _source)
{
    auto source = _source.obj;
    
    if (source->GetTypeId() == TYPEID_UNIT)
    {
        if (source->GetUInt32Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_QUESTGIVER)
            player->PrepareQuestMenu(source->TS_GET_GUID());
    }
    else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
    {
        if (source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
            player->PrepareQuestMenu(source->TS_GET_GUID());
    }
}
    
/**
 * Shows a quest accepting window to the [Player] for the given quest.
 *
 * @param uint32 questId : entry of a quest
 * @param bool activateAccept = true : auto finish the quest
 */
void TSPlayer::SendQuestTemplate(uint32 questId,bool activateAccept) 
{
    
    Quest const* quest = eObjectMgr->GetQuestTemplate(questId);
    
    player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->TS_GET_GUID(), activateAccept);
}
    
/**
 * Converts [Player]'s corpse to bones
 */
void TSPlayer::SpawnBones() 
{
    player->SpawnCorpseBones();
}
    
/**
 * Loots [Player]'s bones for insignia
 *
 * @param [Player] looter
 */
void TSPlayer::RemovedInsignia(TSPlayer _looter)
{
    auto looter = _looter.player;
    player->RemovedInsignia(looter);
}
    
/**
 * Makes the [Player] invite another player to a group.
 *
 * @param [Player] invited : player to invite to group
 * @return bool success : true if the player was invited to a group
 */
bool TSPlayer::GroupInvite(TSPlayer _invited)
{
    auto invited = _invited.player;
    
    if (invited->GetGroup() || invited->GetGroupInvite())
    {
        return false;
    }
    
    // Get correct existing group if any
    Group* group = player->GetGroup();
    if (group && group->isBGGroup())
        group = player->GetOriginalGroup();
    
    bool success = false;
    
    // Try invite if group found
    if (group)
        success = !group->IsFull() && group->AddInvite(invited);
    else
    {
        // Create new group if one not found
        group = new Group;
        success = group->AddLeaderInvite(player) && group->AddInvite(invited);
        if (!success)
            delete group;
    }
    
    if (success)
    {
#if defined(CLASSIC) || defined(TBC)
WorldPacket data(SMSG_GROUP_INVITE, 10);                // guess size
        data << player->GetName();
#ifdef CMANGOS
        invited->GetSession()->SendPacket(data);
#else
        invited->GetSession()->SendPacket(&data);
#endif
#else
WorldPacket data(SMSG_GROUP_INVITE, 10);                // guess size
        data << uint8(1);                                       // invited/already in group flag
        data << player->GetName();                              // max len 48
        data << uint32(0);                                      // unk
        data << uint8(0);                                       // count
        data << uint32(0);                                      // unk
#ifdef CMANGOS
        invited->GetSession()->SendPacket(data);
#else
        invited->GetSession()->SendPacket(&data);
#endif
#endif
    }
    return success;
}
    
/**
 * Creates a new [Group] with the creator [Player] as leader.
 *
 * @param [Player] invited : player to add to group
 * @return [Group] createdGroup : the created group or nil
 */
TSGroup TSPlayer::GroupCreate(TSPlayer _invited)
{
    auto invited = _invited.player;
    
    
    if (player->GetGroupInvite())
        player->UninviteFromGroup();
    if (invited->GetGroupInvite())
        invited->UninviteFromGroup();
    
    // Try create new group
    Group* group = new Group;
    if (!group->AddLeaderInvite(player))
    {
        delete group;
    }
    
    // Forming a new group, create it
    if (!group->IsCreated())
    {
        group->RemoveInvite(player);
#if defined TRINITY || AZEROTHCORE
        group->Create(player);
        sGroupMgr->AddGroup(group);
#else
        sObjectMgr.AddGroup(group);
#endif
    }
    
#if defined TRINITY || AZEROTHCORE
    group->BroadcastGroupUpdate();
#else
#endif
     return TSGroup(group);
}
    
/**
 * Starts a cinematic for the [Player]
 *
 * @param uint32 CinematicSequenceId : entry of a cinematic
 */
void TSPlayer::SendCinematicStart(uint32 CinematicSequenceId) 
{
    
    player->SendCinematicStart(CinematicSequenceId);
}
    
#if !defined(CLASSIC) && !defined(TBC)
/**
 * Starts a movie for the [Player]
 *
 * @param uint32 MovieId : entry of a movie
 */
void TSPlayer::SendMovieStart(uint32 MovieId) 
{
    player->SendMovieStart(MovieId);
}
#endif

void TSPlayer::SendMail(uint8 senderType, uint64 from, TSString subject, TSString body, uint32 money, uint32 cod, uint32 delay, TSArray<TSItem> items) 
{
    MailSender sender(MailMessageType(senderType),from);
    MailDraft draft(subject.std_str(),body.std_str());
    draft.AddMoney(money);
    draft.AddCOD(cod);
    CharacterDatabaseTransaction trans = CharacterDatabase.BeginTransaction();

    for(int i=0;i<items.get_length();++i)
    {
        auto item = items.get(i);
        item->item->SaveToDB(trans);
        draft.AddItem(item.item);
    }

    draft.SendMailTo(trans,MailReceiver(player,player->GetGUID().GetCounter()),sender, MAIL_CHECK_MASK_NONE, delay);
    CharacterDatabase.CommitTransaction(trans);
}

TSArray<TSMail> TSPlayer::GetMails()
{
    TSArray<TSMail> arr;
    for(auto &i : player->GetMails())
    {
        arr.push(i);
    }
    return arr;
}

void TSPlayer::RemoveMail(uint32 id)
{
    player->RemoveMail(id);
}

/*int TSPlayer::BindToInstance(lua_State* L, Player* player)
{
player->BindToInstance();
}*/
    
/*int TSPlayer::AddTalent(lua_State* L, Player* player)
{
if (spec >= MAX_TALENT_SPECS)
return false;
else
return player->AddTalent(spellId, spec, learning);
}*/
    
/*int TSPlayer::GainSpellComboPoints(lua_State* L, Player* player)
{
    
player->GainSpellComboPoints(count);
}*/
    
/*int TSPlayer::KillGOCredit(lua_State* L, Player* player)
{
player->KillCreditGO(entry, guid);
}*/
    
/*int TSPlayer::KilledPlayerCredit(lua_State* L, Player* player)
{
player->KilledPlayerCredit();
}*/
    
/*int TSPlayer::RemoveRewardedQuest(lua_State* L, Player* player)
{
    
player->RemoveRewardedQuest(entry);
}*/
    
/*int TSPlayer::RemoveActiveQuest(lua_State* L, Player* player)
{
    
player->RemoveActiveQuest(entry);
}*/
    
/*int TSPlayer::SummonPet(lua_State* L, Player* player)
{
    
    
player->SummonPet(entry, x, y, z, o, (PetType)petType, despwtime);
}*/
    
/*int TSPlayer::RemovePet(lua_State* L, Player* player)
{
    
    
player->RemovePet(player->GetPet(), (PetSaveMode)mode, returnreagent);
}*/
// Inherited from Unit
// Inherited from WorldObject
// Inherited from Object