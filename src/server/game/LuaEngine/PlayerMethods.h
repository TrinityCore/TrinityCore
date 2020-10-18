/*
* Copyright (C) 2010 - 2016 Eluna Lua Engine <http://emudevs.com/>
* This program is free software licensed under GPL version 3
* Please see the included DOCS/LICENSE.md for more information
*/

#ifndef PLAYERMETHODS_H
#define PLAYERMETHODS_H

/***
 * Inherits all methods from: [Object], [WorldObject], [Unit]
 */
namespace LuaPlayer
{
#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Returns 'true' if the [Player] can Titan Grip, 'false' otherwise.
     *
     * @return bool canTitanGrip
     */
    int CanTitanGrip(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanTitanGrip());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has a talent by ID in specified spec, 'false' otherwise.
     *
     * @param uint32 spellId : talent spellId to check
     * @param uint8 spec : specified spec. 0 for primary, 1 for secondary.
     * @return bool hasTalent
     */
    int HasTalent(lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
#ifdef MANGOS
        uint8 maxSpecs = MAX_TALENT_SPEC_COUNT;
#else
        uint8 maxSpecs = MAX_TALENT_SPECS;
#endif
        uint8 spec = Eluna::CHECKVAL<uint8>(L, 3);
        if (spec >= maxSpecs)
            return 1;
        Eluna::Push(L, player->HasTalent(spellId, spec));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has completed the specified achievement, 'false' otherwise.
     *
     * @param uint32 achievementId
     * @return bool hasAchieved
     */
    int HasAchieved(lua_State* L, Player* player)
    {
        uint32 achievementId = Eluna::CHECKVAL<uint32>(L, 2);
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->HasAchieved(achievementId));
#else
        Eluna::Push(L, player->GetAchievementMgr().HasAchievement(achievementId));
#endif
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Player] has an active [Quest] by specific ID, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool hasQuest
     */
    int HasQuest(lua_State* L, Player* player)
    {
        uint32 quest = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->IsActiveQuest(quest));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has a skill by specific ID, 'false' otherwise.
     *
     * @param uint32 skill
     * @return bool hasSkill
     */
    int HasSkill(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasSkill(skill));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has a [Spell] by specific ID, 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpell
     */
    int HasSpell(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasSpell(id));
        return 1;
    }

    /**
     * Returns true if [Player] has specified login flag
     *
     * @param uint32 flag
     * @return bool hasLoginFlag
     */
    int HasAtLoginFlag(lua_State* L, Player* player)
    {
        uint32 flag = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasAtLoginFlag((AtLoginFlags)flag));
        return 1;
    }

    /**
     * Returns true if [Player] has [Quest] for [GameObject]
     *
     * @param int32 entry : entry of a [GameObject]
     * @return bool hasQuest
     */
    int HasQuestForGO(lua_State* L, Player* player)
    {
        int32 entry = Eluna::CHECKVAL<int32>(L, 2);

        Eluna::Push(L, player->HasQuestForGO(entry));
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Player] has a title by specific ID, 'false' otherwise.
     *
     * @param uint32 titleId
     * @return bool hasTitle
     */
    int HasTitle(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* titleInfo = sCharTitlesStore.LookupEntry(id);
        if (titleInfo)
            Eluna::Push(L, player->HasTitle(titleInfo));
        return 1;
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
    int HasItem(lua_State* L, Player* player)
    {
        uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 count = Eluna::CHECKVAL<uint32>(L, 3, 1);
        bool check_bank = Eluna::CHECKVAL<bool>(L, 4, false);
        Eluna::Push(L, player->HasItemCount(itemId, count, check_bank));
        return 1;
    }
    
    /**
     * Returns 'true' if the [Player] has a quest for the item entry specified, 'false' otherwise.
     *
     * @param uint32 entry : entry of the item
     * @return bool hasQuest
     */
    int HasQuestForItem(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->HasQuestForItem(entry));
        return 1;
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
    int CanUseItem(lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        if (item)
            Eluna::Push(L, player->CanUseItem(item) == EQUIP_ERR_OK);
        else
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            const ItemTemplate* temp = eObjectMgr->GetItemTemplate(entry);
            if (temp)
                Eluna::Push(L, player->CanUseItem(temp) == EQUIP_ERR_OK);
            else
                Eluna::Push(L, false);
        }
        return 1;
    }

    /**
     * Returns 'true' if the [Spell] specified by ID is currently on cooldown for the [Player], 'false' otherwise.
     *
     * @param uint32 spellId
     * @return bool hasSpellCooldown
     */
    int HasSpellCooldown(lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);

#ifdef TRINITY
        Eluna::Push(L, player->GetSpellHistory()->HasCooldown(spellId));
#else
        Eluna::Push(L, player->HasSpellCooldown(spellId));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Player] can share [Quest] specified by ID, 'false' otherwise.
     *
     * @param uint32 entryId
     * @return bool hasSpellCooldown
     */
    int CanShareQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->CanShareQuest(entry));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] can currently communicate through chat, 'false' otherwise.
     *
     * @return bool canSpeak
     */
    int CanSpeak(lua_State* L, Player* player)
    {
#ifdef TRINITY
        Eluna::Push(L, player->GetSession()->CanSpeak());
#else
        Eluna::Push(L, player->CanSpeak());
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has permission to uninvite others from the current group, 'false' otherwise.
     *
     * @return bool canUninviteFromGroup
     */
    int CanUninviteFromGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanUninviteFromGroup() == ERR_PARTY_RESULT_OK);
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Player] can fly, 'false' otherwise.
     *
     * @return bool canFly
     */
    int CanFly(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanFly());
        return 1;
    }
#endif

#ifdef CLASSIC
    /**
     * Returns [Player] kills
     *
     * @param bool honorable = true : if victims are honorable
     * @return uint32 kills
     */
    int GetHonorStoredKills(lua_State* L, Player* player)
    {
        bool honorable = Eluna::CHECKVAL<bool>(L, 2, true);

        Eluna::Push(L, player->GetHonorStoredKills(honorable));
        return 1;
    }

    /**
     * Returns rank points
     *
     * @return float rankPoints
     */
    int GetRankPoints(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRankPoints());
        return 1;
    }

    /**
     * Returns last week's standing position
     *
     * @return int32 standingPos
     */
    int GetHonorLastWeekStandingPos(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHonorLastWeekStandingPos());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Player] is currently in water, 'false' otherwise.
     *
     * @return bool isInWater
     */
    int IsInWater(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsInWater());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently moving, 'false' otherwise.
     *
     * @return bool isMoving
     */
    int IsMoving(lua_State* L, Player* player) // enable for unit when mangos support it
    {
        Eluna::Push(L, player->isMoving());
        return 1;
    }

#ifdef CLASSIC
    /**
     * Updates the [Player]s weekly honor status
     */
    int UpdateHonor(lua_State* L, Player* player)
    {
        player->UpdateHonor();
        return 0;
    }

    /**
     * Resets the [Player]s weekly honor status
     */
    int ResetHonor(lua_State* L, Player* player)
    {
        player->ResetHonor();
        return 0;
    }

    /**
     * Clears all of [Player]s weekly honor status
     */
    int ClearHonorInfo(lua_State* L, Player* player)
    {
        player->ClearHonorInfo();
        return 0;
    }
#endif

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Player] is currently flying, 'false' otherwise.
     *
     * @return bool isFlying
     */
    int IsFlying(lua_State* L, Player* player) // enable for unit when mangos support it
    {
        Eluna::Push(L, player->IsFlying());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Player] is in a [Group], 'false' otherwise.
     *
     * @return bool isInGroup
     */
    int IsInGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetGroup() != NULL));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is in a [Guild], 'false' otherwise.
     *
     * @return bool isInGuild
     */
    int IsInGuild(lua_State* L, Player* player)
    {
        Eluna::Push(L, (player->GetGuildId() != 0));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is a Game Master, 'false' otherwise.
     *
     * Note: This is only true when GM tag is activated! For alternative see [Player:GetGMRank]
     *
     * @return bool isGM
     */
    int IsGM(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->IsGameMaster());
#else
        Eluna::Push(L, player->isGameMaster());
#endif
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Player] is in an arena team specified by type, 'false' otherwise.
     *
     * @param uint32 type
     * @return bool isInArenaTeam
     */
    int IsInArenaTeam(lua_State* L, Player* player)
    {
        uint32 type = Eluna::CHECKVAL<uint32>(L, 2);
        if (type < MAX_ARENA_SLOT && player->GetArenaTeamId(type))
            Eluna::Push(L, true);
        else
            Eluna::Push(L, false);
        return 1;
    }
#endif
    
    /**
     * Returns 'true' if the [Player] is immune to everything.
     *
     * @return bool isImmune
     */
    int IsImmuneToDamage(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isTotalImmune());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] satisfies all requirements to complete the quest entry.
     *
     * @param uint32 entry
     * @return bool canComplete
     */
    int CanCompleteQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->CanCompleteQuest(entry));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is a part of the Horde faction, 'false' otherwise.
     *
     * @return bool isHorde
     */
    int IsHorde(lua_State* L, Player* player)
    {
#ifdef AZEROTHCORE
        Eluna::Push(L, (player->GetTeamId() == TEAM_HORDE));
#else
        Eluna::Push(L, (player->GetTeam() == HORDE));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is a part of the Alliance faction, 'false' otherwise.
     *
     * @return bool isAlliance
     */
    int IsAlliance(lua_State* L, Player* player)
    {
#ifdef AZEROTHCORE
        Eluna::Push(L, (player->GetTeamId() == TEAM_ALLIANCE));
#else
        Eluna::Push(L, (player->GetTeam() == ALLIANCE));
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is 'Do Not Disturb' flagged, 'false' otherwise.
     *
     * @return bool isDND
     */
    int IsDND(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isDND());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is 'Away From Keyboard' flagged, 'false' otherwise.
     *
     * @return bool isAFK
     */
    int IsAFK(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isAFK());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently falling, 'false' otherwise.
     *
     * @return bool isFalling
     */
    int IsFalling(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsFalling());
        return 1;
    }

    int IsGroupVisibleFor(lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsGroupVisibleFor(target));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently in the same raid as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameRaidWith
     */
    int IsInSameRaidWith(lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsInSameRaidWith(target));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently in the same [Group] as another [Player] by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isInSameGroupWith
     */
    int IsInSameGroupWith(lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);
        Eluna::Push(L, player->IsInSameGroupWith(target));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is eligible for Honor or XP gain by [Unit] specified, 'false' otherwise.
     *
     * @param [Unit] unit
     * @return bool isHonorOrXPTarget
     */
    int IsHonorOrXPTarget(lua_State* L, Player* player)
    {
        Unit* victim = Eluna::CHECKOBJ<Unit>(L, 2);

        Eluna::Push(L, player->isHonorOrXPTarget(victim));
        return 1;
    }

    /**
     * Returns 'true' if the [Player] can see anoter [Player] specified by object, 'false' otherwise.
     *
     * @param [Player] player
     * @return bool isVisibleForPlayer
     */
    int IsVisibleForPlayer(lua_State* L, Player* player)
    {
        Player* target = Eluna::CHECKOBJ<Player>(L, 2);

        Eluna::Push(L, player->IsVisibleGloballyFor(target));
        return 1;
    }

    int IsGMVisible(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isGMVisible());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] has taxi cheat activated, 'false' otherwise.
     *
     * @return bool isTaxiCheater
     */
    int IsTaxiCheater(lua_State* L, Player* player)
    {
#ifdef MANGOS
        Eluna::Push(L, player->IsTaxiCheater());
#else
        Eluna::Push(L, player->isTaxiCheater());
#endif
        return 1;
    }

    int IsGMChat(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isGMChat());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is accepting whispers, 'false' otherwise.
     *
     * @return bool isAcceptingWhispers
     */
    int IsAcceptingWhispers(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isAcceptWhispers());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently rested, 'false' otherwise.
     *
     * @return bool isRested
     */
    int IsRested(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRestBonus() > 0.0f);
        return 1;
    }

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround] queue, 'false' otherwise.
     *
     * @return bool inBattlegroundQueue
     */
    int InBattlegroundQueue(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->InBattlegroundQueue());
#else
        Eluna::Push(L, player->InBattleGroundQueue());
#endif
        return 1;
    }

#ifndef CLASSIC
    /**
     * Returns 'true' if the [Player] is currently in an arena, 'false' otherwise.
     *
     * @return bool inArena
     */
    int InArena(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->InArena());
        return 1;
    }
#endif

    /**
     * Returns 'true' if the [Player] is currently in a [BattleGround], 'false' otherwise.
     *
     * @return bool inBattleGround
     */
    int InBattleground(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->InBattleground());
#else
        Eluna::Push(L, player->InBattleGround());
#endif
        return 1;
    }

    /**
     * Returns 'true' if the [Player] can block incomming attacks, 'false' otherwise.
     *
     * @return bool canBlock
     */
    int CanBlock(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanBlock());
        return 1;
    }

    /**
     * Returns 'true' if the [Player] can parry incomming attacks, 'false' otherwise.
     *
     * @return bool canParry
     */
    int CanParry(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->CanParry());
        return 1;
    }

    /*int HasReceivedQuestReward(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->IsQuestRewarded(entry));
        return 1;
    }*/

    /*int IsOutdoorPvPActive(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsOutdoorPvPActive());
        return 1;
    }*/

    /*int IsImmuneToEnvironmentalDamage(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsImmuneToEnvironmentalDamage());
        return 1;
    }*/

    /*int InRandomLfgDungeon(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->inRandomLfgDungeon());
        return 1;
    }*/

    /*int IsUsingLfg(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->isUsingLfg());
        return 1;
    }*/

    /*int IsNeverVisible(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->IsNeverVisible());
        return 1;
    }*/

    /*int CanFlyInZone(lua_State* L, Player* player)
    {
        uint32 mapid = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 zone = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->IsKnowHowFlyIn(mapid, zone));
        return 1;
    }*/

    /*int HasPendingBind(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->PendingHasPendingBind());
        return 1;
    }*/

    /*int IsARecruiter(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->IsARecruiter() || (player->GetSession()->GetRecruiterId() != 0));
        return 1;
    }*/

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Returns the amount of available specs the [Player] currently has
     *
     * @return uint8 specCount
     */
    int GetSpecsCount(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSpecsCount());
        return 1;
    }

    /**
     * Returns the [Player]s active spec ID
     *
     * @return uint32 specId
     */
    int GetActiveSpec(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetActiveSpec());
        return 1;
    }
#endif

#ifdef WOTLK
    /**
     * Returns the normal phase of the player instead of the actual phase possibly containing GM phase
     *
     * @return uint32 phasemask
     */
    int GetPhaseMaskForSpawn(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetPhaseMaskForSpawn());
        return 1;
    }
#endif

#if defined(TBC) || defined (WOTLK)
    /**
     * Returns the [Player]s current amount of Arena Points
     *
     * @return uint32 arenaPoints
     */
    int GetArenaPoints(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetArenaPoints());
        return 1;
    }

    /**
     * Returns the [Player]s current amount of Honor Points
     *
     * @return uint32 honorPoints
     */
    int GetHonorPoints(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHonorPoints());
        return 1;
    }
#endif
#if defined(CLASSIC) || defined(TBC) || defined (WOTLK)
    /**
     * Returns the [Player]s current shield block value
     *
     * @return uint32 blockValue
     */
    int GetShieldBlockValue(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetShieldBlockValue());
        return 1;
    }
#endif

    /**
     * Returns the [Player]s cooldown delay by specified [Spell] ID
     *
     * @param uint32 spellId
     * @return uint32 spellCooldownDelay
     */
    int GetSpellCooldownDelay(lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);

#ifdef TRINITY
        if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId))
            Eluna::Push(L, player->GetSpellHistory()->GetRemainingCooldown(spellInfo));
        else
            Eluna::Push(L, 0);
#else
        Eluna::Push(L, uint32(player->GetSpellCooldownDelay(spellId)));
#endif
        return 1;
    }

    /**
     * Returns the [Player]s current latency in MS
     *
     * @return uint32 latency
     */
    int GetLatency(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetLatency());
        return 1;
    }

#if defined TRINITY || AZEROTHCORE
    /**
     * Returns the faction ID the [Player] is currently flagged as champion for
     *
     * @return uint32 championingFaction
     */
    int GetChampioningFaction(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetChampioningFaction());
        return 1;
    }
#endif

    /**
     * Returns [Player]s original sub group
     *
     * @return uint8 subGroup
     */
    int GetOriginalSubGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetOriginalSubGroup());
        return 1;
    }

    /**
     * Returns [Player]s original [Group] object
     *
     * @return [Group] group
     */
    int GetOriginalGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetOriginalGroup());
        return 1;
    }

    /**
     * Returns a random Raid Member [Player] object within radius specified of [Player]
     *
     * @param float radius
     * @return [Player] player
     */
    int GetNextRandomRaidMember(lua_State* L, Player* player)
    {
        float radius = Eluna::CHECKVAL<float>(L, 2);

        Eluna::Push(L, player->GetNextRandomRaidMember(radius));
        return 1;
    }

    /**
     * Returns [Player]s current sub group
     *
     * @return uint8 subGroup
     */
    int GetSubGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSubGroup());
        return 1;
    }

    /**
     * Returns [Group] invitation
     *
     * @return [Group] group
     */
    int GetGroupInvite(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGroupInvite());
        return 1;
    }

    /**
     * Returns rested experience bonus
     *
     * @param uint32 xp
     * @return uint32 xpBonus
     */
    int GetXPRestBonus(lua_State* L, Player* player)
    {
        uint32 xp = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetXPRestBonus(xp));
        return 1;
    }

    /**
     * Returns the [Player]s current [BattleGround] type ID
     *
     * @return [BattleGroundTypeId] typeId
     */
    int GetBattlegroundTypeId(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->GetBattlegroundTypeId());
#else
        Eluna::Push(L, player->GetBattleGroundTypeId());
#endif
        return 1;
    }

    /**
     * Returns the [Player]s current [BattleGround] ID
     *
     * @return uint32 battleGroundId
     */
    int GetBattlegroundId(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->GetBattlegroundId());
#else
        Eluna::Push(L, player->GetBattleGroundId());
#endif
        return 1;
    }

    /**
     * Returns the [Player]s reputation rank of faction specified
     *
     * @param uint32 faction
     * @return [ReputationRank] rank
     */
    int GetReputationRank(lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetReputationRank(faction));
        return 1;
    }

    /**
     * Returns the [Player]s current level of intoxication
     *
     * @return uint16 drunkValue
     */
    int GetDrunkValue(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetDrunkValue());
        return 1;
    }

    /**
     * Returns skill temporary bonus value
     *
     * @param uint32 skill
     * @param int16 bonusVal
     */
    int GetSkillTempBonusValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillTempBonusValue(skill));
        return 1;
    }

    /**
     * Returns skill permanent bonus value
     *
     * @param uint32 skill
     * @param int16 bonusVal
     */
    int GetSkillPermBonusValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillPermBonusValue(skill));
        return 1;
    }

    /**
     * Returns skill value without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    int GetPureSkillValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetPureSkillValue(skill));
        return 1;
    }

    /**
     * Returns base skill value
     *
     * @param uint32 skill
     * @return uint16 baseVal
     */
    int GetBaseSkillValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetBaseSkillValue(skill));
        return 1;
    }

    /**
     * Returns skill value
     *
     * @param uint32 skill
     * @return uint16 val
     */
    int GetSkillValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetSkillValue(skill));
        return 1;
    }

    /**
     * Returns max value of specified skill without bonus'
     *
     * @param uint32 skill
     * @return uint16 pureVal
     */
    int GetPureMaxSkillValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetPureMaxSkillValue(skill));
        return 1;
    }

    /**
     * Returns max value of specified skill
     *
     * @param uint32 skill
     * @return uint16 val
     */
    int GetMaxSkillValue(lua_State* L, Player* player)
    {
        uint32 skill = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetMaxSkillValue(skill));
        return 1;
    }

    /**
     * Returns mana bonus from amount of intellect
     *
     * @return float bonus
     */
    int GetManaBonusFromIntellect(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetManaBonusFromIntellect());
        return 1;
    }

    /**
     * Returns health bonus from amount of stamina
     *
     * @return float bonus
     */
    int GetHealthBonusFromStamina(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetHealthBonusFromStamina());
        return 1;
    }

    /**
     * Returns raid or dungeon difficulty
     *
     * @param bool isRaid = true : argument is TrinityCore only
     * @return int32 difficulty
     */
    int GetDifficulty(lua_State* L, Player* player)
    {
#ifdef TBC
        Eluna::Push(L, player->GetDifficulty());
#elif defined(CLASSIC)
        Eluna::Push(L, (Difficulty)0);
#else
        bool isRaid = Eluna::CHECKVAL<bool>(L, 2, true);
        Eluna::Push(L, player->GetDifficulty(isRaid));
#endif
        return 1;
    }

    /**
     * Returns the [Player]s current guild rank
     *
     * @return uint32 guildRank
     */
    int GetGuildRank(lua_State* L, Player* player) // TODO: Move to Guild Methods
    {
        Eluna::Push(L, player->GetRank());
        return 1;
    }

    /**
     * Returns the [Player]s free talent point amount
     *
     * @return uint32 freeTalentPointAmt
     */
    int GetFreeTalentPoints(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetFreeTalentPoints());
        return 1;
    }

    /**
     * Returns the name of the [Player]s current [Guild]
     *
     * @return string guildName
     */
    int GetGuildName(lua_State* L, Player* player)
    {
        if (!player->GetGuildId())
            return 1;
        Eluna::Push(L, eGuildMgr->GetGuildNameById(player->GetGuildId()));
        return 1;
    }

    /**
     * Returns the amount of reputation the [Player] has with the faction specified
     *
     * @param uint32 faction
     * @return int32 reputationAmt
     */
    int GetReputation(lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetReputationMgr().GetReputation(faction));
        return 1;
    }

    /**
     * Returns [Unit] target combo points are on
     *
     * @return [Unit] target
     */
    int GetComboTarget(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->GetComboTarget());
#else
        Eluna::Push(L, player->GetMap()->GetUnit(player->GetComboTargetGuid()));
#endif
        return 1;
    }

    /**
     * Returns [Player]'s combo points
     *
     * @return uint8 comboPoints
     */
    int GetComboPoints(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetComboPoints());
        return 1;
    }

    /**
     * Returns the amount of time the [Player] has spent ingame
     *
     * @return uint32 inGameTime
     */
    int GetInGameTime(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetInGameTime());
        return 1;
    }

    /**
     * Returns the status of the [Player]s [Quest] specified by entry ID
     *
     * @param uint32 questId
     * @return [QuestStatus] questStatus
     */
    int GetQuestStatus(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetQuestStatus(entry));
        return 1;
    }

    /**
     * Returns 'true' if the [Player]s [Quest] specified by entry ID has been rewarded, 'false' otherwise.
     *
     * @param uint32 questId
     * @return bool questRewardStatus
     */
    int GetQuestRewardStatus(lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetQuestRewardStatus(questId));
        return 1;
    }

    /**
     * Returns [Quest] required [Creature] or [GameObject] count
     *
     * @param uint32 quest : entry of a quest
     * @param int32 entry : entry of required [Creature]
     * @return uint16 count
     */
    int GetReqKillOrCastCurrentCount(lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        int32 entry = Eluna::CHECKVAL<int32>(L, 3);

        Eluna::Push(L, player->GetReqKillOrCastCurrentCount(questId, entry));
        return 1;
    }

    /**
     * Returns the quest level of the [Player]s [Quest] specified by object
     *
     * @param uint32 questId
     * @return [QuestStatus] questRewardStatus
     */
    int GetQuestLevel(lua_State* L, Player* player)
    {
        Quest* quest = Eluna::CHECKOBJ<Quest>(L, 2);

#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->GetQuestLevel(quest));
#else
        Eluna::Push(L, player->GetQuestLevelForPlayer(quest));
#endif
        return 1;
    }

    /**
     * Returns a [Player]s [Item] object by gear slot specified
     *
     * @param uint8 slot
     * @return [Item] item
     */
    int GetEquippedItemBySlot(lua_State* L, Player* player)
    {
        uint8 slot = Eluna::CHECKVAL<uint8>(L, 2);
        if (slot >= EQUIPMENT_SLOT_END)
            return 1;

        Item* item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, slot);
        Eluna::Push(L, item);
        return 1;
    }

    /**
     * Returns the [Player]s current resting bonus
     *
     * @return float restBonus
     */
    int GetRestBonus(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetRestBonus());
        return 1;
    }

    /**
     * Returns active GM chat tag
     *
     * @return uint8 tag
     */
    int GetChatTag(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetChatTag());
        return 1;
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
    int GetItemByPos(lua_State* L, Player* player)
    {
        uint8 bag = Eluna::CHECKVAL<uint8>(L, 2);
        uint8 slot = Eluna::CHECKVAL<uint8>(L, 3);

        Eluna::Push(L, player->GetItemByPos(bag, slot));
        return 1;
    }

    /**
     * Returns an [Item] from the player by guid.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param uint64 guid : an item guid
     * @return [Item] item
     */
    int GetItemByGUID(lua_State* L, Player* player)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2);

        Eluna::Push(L, player->GetItemByGuid(ObjectGuid(guid)));
        return 1;
    }

    /**
     * Returns an [Item] from the player by entry.
     *
     * The item can be equipped, in bags or in bank.
     *
     * @param uint32 entryId
     * @return [Item] item
     */
    int GetItemByEntry(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Eluna::Push(L, player->GetItemByEntry(entry));
        return 1;
    }
    
    /**
     * Returns the database textID of the [WorldObject]'s gossip header text for the [Player]
     *
     * @return uint32 textId : key to npc_text database table
     */
    int GetGossipTextId(lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);
        Eluna::Push(L, player->GetGossipTextId(obj));
        return 1;
    }

    /**
     * Returns the [Player]s currently selected [Unit] object
     *
     * @return [Unit] unit
     */
    int GetSelection(lua_State* L, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        Eluna::Push(L, player->GetSelectedUnit());
#else
        Eluna::Push(L, player->GetMap()->GetUnit(player->GetSelectionGuid()));
#endif
        return 1;
    }

    /**
     * Returns the [Player]s GM Rank
     *
     * @return [AccountTypes] gmRank
     */
    int GetGMRank(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSecurity());
        return 1;
    }

    /**
     * Returns the [Player]s amount of money in copper
     *
     * @return uint32 coinage
     */
    int GetCoinage(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetMoney());
        return 1;
    }

    /**
     * Returns the [Player]s current [Guild] ID
     *
     * @return uint32 guildId
     */
    int GetGuildId(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGuildId());
        return 1;
    }

    /**
     * Returns the [Player]s [TeamId]
     *
     * @return [TeamId] teamId
     */
    int GetTeam(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetTeamId());
        return 1;
    }
    
    /**
     * Returns amount of the specified [Item] the [Player] has.
     *
     * @param uint32 entry : entry of the item
     * @param bool checkinBank = false : also counts the items in player's bank if true
     * @return uint32 itemamount
     */
    int GetItemCount(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        bool checkinBank = Eluna::CHECKVAL<bool>(L, 3, false);
        Eluna::Push(L, player->GetItemCount(entry, checkinBank));
        return 1;
    }

    /**
     * Returns the [Player]s lifetime Honorable Kills
     *
     * @return uint32 lifeTimeKils
     */
    int GetLifetimeKills(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS));
        return 1;
    }

    /**
     * Returns the [Player]s IP address
     *
     * @return string ip
     */
    int GetPlayerIP(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetRemoteAddress());
        return 1;
    }

    /**
     * Returns the [Player]s time played at current level
     *
     * @return uint32 currLevelPlayTime
     */
    int GetLevelPlayedTime(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetLevelPlayedTime());
        return 1;
    }

    /**
     * Returns the [Player]s total time played
     *
     * @return uint32 totalPlayTime
     */
    int GetTotalPlayedTime(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetTotalPlayedTime());
        return 1;
    }

    /**
     * Returns the [Player]s [Guild] object
     *
     * @return [Guild] guild
     */
    int GetGuild(lua_State* L, Player* player)
    {
        Eluna::Push(L, eGuildMgr->GetGuildById(player->GetGuildId()));
        return 1;
    }

    /**
     * Returns the [Player]s [Group] object
     *
     * @return [Group] group
     */
    int GetGroup(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetGroup());
        return 1;
    }

    /**
     * Returns the [Player]s account ID
     *
     * @return uint32 accountId
     */
    int GetAccountId(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetAccountId());
        return 1;
    }

    /**
     * Returns the [Player]s account name
     *
     * @return string accountName
     */
    int GetAccountName(lua_State* L, Player* player)
    {
        std::string accName;
#ifndef AZEROTHCORE
        if (eAccountMgr->GetName(player->GetSession()->GetAccountId(), accName))
#else
        if (AccountMgr::GetName(player->GetSession()->GetAccountId(), accName))
#endif
            Eluna::Push(L, accName);
        return 1;
    }

    /**
     * Returns the [Player]s [Corpse] object
     *
     * @return [Corpse] corpse
     */
    int GetCorpse(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetCorpse());
        return 1;
    }

    /**
     * Returns the [Player]s database locale index
     *
     * @return int localeIndex
     */
    int GetDbLocaleIndex(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSessionDbLocaleIndex());
        return 1;
    }

    /**
     * Returns the [Player]s game client locale
     *
     * @return [LocaleConstant] locale
     */
    int GetDbcLocale(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetSessionDbcLocale());
        return 1;
    }

    /*int GetRecruiterId(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSession()->GetRecruiterId());
        return 1;
    }*/

    /*int GetSelectedPlayer(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSelectedPlayer());
        return 1;
    }*/

    /*int GetSelectedUnit(lua_State* L, Player* player)
    {
        Eluna::Push(L, player->GetSelectedUnit());
        return 1;
    }*/

    /*int GetNearbyGameObject(lua_State* L, Player* player)
    {
        Eluna::Push(L, ChatHandler(player->GetSession()).GetNearbyGameObject());
        return 1;
    }*/
    
    /**
     * Locks the player controls and disallows all movement and casting.
     *
     * @param bool apply = true : lock if true and unlock if false
     */
    int SetPlayerLock(lua_State* L, Player* player)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

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
        return 0;
    }

    /**
     * Sets the [Player]s login flag to the flag specified
     *
     * @param uint32 flag
     */
    int SetAtLoginFlag(lua_State* L, Player* player)
    {
        uint32 flag = Eluna::CHECKVAL<uint32>(L, 2);

        player->SetAtLoginFlag((AtLoginFlags)flag);
        return 0;
    }

    /**
     * Sets the [Player]s sheathe state to the state specified
     *
     * @param uint32 sheatheState
     */
    int SetSheath(lua_State* L, Player* player)
    {
        uint32 sheathed = Eluna::CHECKVAL<uint32>(L, 2);
        if (sheathed >= MAX_SHEATH_STATE)
            return 0;

        player->SetSheath((SheathState)sheathed);
        return 0;
    }

    /**
     * Sets the [Player]s intoxication level to the level specified
     *
     * @param uint8 drunkValue
     */
    int SetDrunkValue(lua_State* L, Player* player)
    {
        uint8 newDrunkValue = Eluna::CHECKVAL<uint8>(L, 2);

        player->SetDrunkValue(newDrunkValue);
        return 0;
    }

    /**
     * Sets the [Player]s faction standing to that of the race specified
     *
     * @param uint8 raceId
     */
    int SetFactionForRace(lua_State* L, Player* player)
    {
        uint8 race = Eluna::CHECKVAL<uint8>(L, 2);

#ifdef TRINITY
        player->SetFactionForRace(race);
#else
        player->setFactionForRace(race);
#endif
        return 0;
    }

    /**
     * Sets (increases) skill of the [Player]
     *
     * @param uint16 id
     * @param uint16 step
     * @param uint16 currVal
     * @param uint16 maxVal
     */
    int SetSkill(lua_State* L, Player* player)
    {
        uint16 id = Eluna::CHECKVAL<uint16>(L, 2);
        uint16 step = Eluna::CHECKVAL<uint16>(L, 3);
        uint16 currVal = Eluna::CHECKVAL<uint16>(L, 4);
        uint16 maxVal = Eluna::CHECKVAL<uint16>(L, 5);

#ifdef TRINITY
        player->SetSkill(id, step, currVal, maxVal);
#else
        player->SetSkill(id, currVal, maxVal, step);
#endif
        return 0;
    }

    /**
     * Sets the [Player]s guild rank to the rank specified
     *
     * @param uint8 rank
     */
    int SetGuildRank(lua_State* L, Player* player) // TODO: Move to Guild Methods
    {
        uint8 rank = Eluna::CHECKVAL<uint8>(L, 2);

        if (!player->GetGuildId())
            return 0;

        player->SetRank(rank);
        return 0;
    }

    /**
     * Sets the [Player]s free talent points to the amount specified for the current spec
     *
     * @param uint32 talentPointAmt
     */
    int SetFreeTalentPoints(lua_State* L, Player* player)
    {
        uint32 points = Eluna::CHECKVAL<uint32>(L, 2);

        player->SetFreeTalentPoints(points);
#if (!defined(TBC) && !defined(CLASSIC))
        player->SendTalentsInfoData(false);
#endif
        return 0;
    }

    /**
     * Sets the [Player]s reputation amount for the faction specified
     *
     * @param uint32 factionId
     * @param int32 reputationValue
     */
    int SetReputation(lua_State* L, Player* player)
    {
        uint32 faction = Eluna::CHECKVAL<uint32>(L, 2);
        int32 value = Eluna::CHECKVAL<int32>(L, 3);

        FactionEntry const* factionEntry = sFactionStore.LookupEntry(faction);
        player->GetReputationMgr().SetReputation(factionEntry, value);
        return 0;
    }

    /**
     * Sets [Quest] state
     *
     * @param uint32 entry : entry of a quest
     * @param uint32 status
     */
    int SetQuestStatus(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 status = Eluna::CHECKVAL<uint32>(L, 3);
        if (status >= MAX_QUEST_STATUS)
            return 0;

        player->SetQuestStatus(entry, (QuestStatus)status);
        return 0;
    }

    /**
     * Sets the [Player]s rest bonus to the amount specified
     *
     * @param float restBonus
     */
    int SetRestBonus(lua_State* L, Player* player)
    {
        float bonus = Eluna::CHECKVAL<float>(L, 2);

        player->SetRestBonus(bonus);
        return 0;
    }

    /**
     * Toggles whether the [Player] accepts whispers or not
     *
     * @param bool acceptWhispers = true
     */
    int SetAcceptWhispers(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetAcceptWhispers(on);
        return 0;
    }

    /**
     * Toggles PvP Death
     *
     * @param bool on = true
     */
    int SetPvPDeath(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetPvPDeath(on);
        return 0;
    }

    /**
     * Toggles whether the [Player] has GM visibility on or off
     *
     * @param bool gmVisible = true
     */
    int SetGMVisible(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGMVisible(on);
        return 0;
    }

    /**
     * Toggles whether the [Player] has taxi cheat enabled or not
     *
     * @param bool taxiCheat = true
     */
    int SetTaxiCheat(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetTaxiCheater(on);
        return 0;
    }

    /**
     * Toggle Blizz (GM) tag
     *
     * @param bool on = true
     */
    int SetGMChat(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGMChat(on);
        return 0;
    }

    /**
     * Toggles the [Player]s GM mode on or off
     *
     * @param bool setGmMode = true
     */
    int SetGameMaster(lua_State* L, Player* player)
    {
        bool on = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetGameMaster(on);
        return 0;
    }

    /**
     * Sets the [Player]s gender to gender specified
     *
     * - GENDER_MALE    = 0
     * - GENDER_FEMALE  = 1
     *
     * @param [Gender] gender
     */
    int SetGender(lua_State* L, Player* player)
    {
        uint32 _gender = Eluna::CHECKVAL<uint32>(L, 2);

        Gender gender;
        switch (_gender)
        {
            case 0:
                gender = GENDER_MALE;
                break;
            case 1:
                gender = GENDER_FEMALE;
                break;
            default:
                return luaL_argerror(L, 2, "valid Gender expected");
        }

        player->SetByteValue(UNIT_FIELD_BYTES_0, 2, gender);
        player->SetByteValue(PLAYER_BYTES_3, 0, gender);
        player->InitDisplayIds();
        return 0;
    }

#if defined(TBC) || defined(WOTLK)
    /**
     * Sets the [Player]s Arena Points to the amount specified
     *
     * @param uint32 arenaPoints
     */
    int SetArenaPoints(lua_State* L, Player* player)
    {
        uint32 arenaP = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetArenaPoints(arenaP);
        return 0;
    }

    /**
     * Sets the [Player]s Honor Points to the amount specified
     *
     * @param uint32 honorPoints
     */
    int SetHonorPoints(lua_State* L, Player* player)
    {
        uint32 honorP = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetHonorPoints(honorP);
        return 0;
    }
#endif

#ifdef CLASSIC
    /**
     * Sets kills
     *
     * @param uint32 kills
     * @param bool honorable = true : if victims were honorable
     */
    int SetHonorStoredKills(lua_State* L, Player* player)
    {
        uint32 kills = Eluna::CHECKVAL<uint32>(L, 2);
        bool honorable = Eluna::CHECKVAL<bool>(L, 3, true);

        player->SetHonorStoredKills(kills, honorable);
        return 0;
    }

    /**
     * Sets rank points
     *
     * @param float rankPoints
     */
    int SetRankPoints(lua_State* L, Player* player)
    {
        float rankPoints = Eluna::CHECKVAL<float>(L, 2);

        player->SetRankPoints(rankPoints);
        return 0;
    }

    /**
     * Sets last week's honor standing position
     *
     * @param int32 standingPos
     */
    int SetHonorLastWeekStandingPos(lua_State* L, Player* player)
    {
        int32 standingPos = Eluna::CHECKVAL<int32>(L, 2);

        player->SetHonorLastWeekStandingPos(standingPos);
        return 0;
    }
#endif

    /**
     * Sets the [Player]s amount of Lifetime Honorable Kills to the value specified
     *
     * @param uint32 honorableKills
     */
    int SetLifetimeKills(lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, val);
        return 0;
    }

    /**
     * Sets the [Player]s amount of money to copper specified
     *
     * @param uint32 copperAmt
     */
    int SetCoinage(lua_State* L, Player* player)
    {
        uint32 amt = Eluna::CHECKVAL<uint32>(L, 2);
        player->SetMoney(amt);
        return 0;
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
    int SetBindPoint(lua_State* L, Player* player)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        float z = Eluna::CHECKVAL<float>(L, 4);
        uint32 mapId = Eluna::CHECKVAL<uint32>(L, 5);
        uint32 areaId = Eluna::CHECKVAL<uint32>(L, 6);

        WorldLocation loc(mapId, x, y, z);
#if defined TRINITY || AZEROTHCORE
        player->SetHomebind(loc, areaId);
#else
        player->SetHomebindToLocation(loc, areaId);
#endif
        return 0;
    }

#ifndef CLASSIC
    /**
     * Adds the specified title to the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    int SetKnownTitle(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, false);
        return 0;
    }
#endif

#if !defined TRINITY && !AZEROTHCORE
    /**
     * Toggle the [Player]s FFA flag
     *
     * @param bool applyFFA = true
     */
    int SetFFA(lua_State* L, Player* player)
    {
        bool apply = Eluna::CHECKVAL<bool>(L, 2, true);

        player->SetFFAPvP(apply);
        return 0;
    }
#endif

    /*int SetMovement(lua_State* L, Player* player)
    {
        int32 pType = Eluna::CHECKVAL<int32>(L, 2);

        player->SetMovement((PlayerMovementType)pType);
        return 0;
    }*/

#if (!defined(TBC) && !defined(CLASSIC))
    /**
     * Resets the [Player]s pets talent points
     */
    int ResetPetTalents(lua_State* /*L*/, Player* player)
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
        return 0;
    }

    /**
     * Reset the [Player]s completed achievements
     */
    int ResetAchievements(lua_State* /*L*/, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        player->ResetAchievements();
#else
        player->GetAchievementMgr().Reset();
#endif
        return 0;
    }
#endif
    
    /**
     * Shows the mailbox window to the player from specified guid.
     *
     * @param uint64 guid = playerguid : guid of the mailbox window sender
     */
    int SendShowMailBox(lua_State* L, Player* player)
    {
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 2, player->GET_GUID());

#if (defined(CLASSIC) || defined(TBC))
        WorldPacket data(CMSG_GET_MAIL_LIST, 8);
        data << uint64(guid);
        player->GetSession()->HandleGetMailList(data);
#else
        player->GetSession()->SendShowMailBox(ObjectGuid(guid));
#endif
        return 0;
    }

#if defined(TBC) || defined(WOTLK)
    /**
     * Adds or detracts from the [Player]s current Arena Points
     *
     * @param int32 amount
     */
    int ModifyArenaPoints(lua_State* L, Player* player)
    {
        int32 amount = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyArenaPoints(amount);
        return 0;
    }

    /**
     * Adds or detracts from the [Player]s current Honor Points
     *
     * @param int32 amount
     */
    int ModifyHonorPoints(lua_State* L, Player* player)
    {
        int32 amount = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyHonorPoints(amount);
        return 0;
    }
#endif

    /**
     * Saves the [Player] to the database
     */
    int SaveToDB(lua_State* /*L*/, Player* player)
    {
#ifndef AZEROTHCORE
        player->SaveToDB();
#else
        player->SaveToDB(false, false);
#endif
        return 0;
    }

    /**
     * Sends a summon request to the player from the given summoner
     *
     * @param [Unit] summoner
     */
    int SummonPlayer(lua_State* L, Player* player)
    {
        Unit* summoner = Eluna::CHECKOBJ<Unit>(L, 2);

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
        return 0;
    }

    /**
     * Mutes the [Player] for the amount of seconds specified
     *
     * @param uint32 muteTime
     */
    int Mute(lua_State* L, Player* player)
    {
        uint32 muteseconds = Eluna::CHECKVAL<uint32>(L, 2);
        /*const char* reason = luaL_checkstring(E, 2);*/ // Mangos does not have a reason field in database.

        time_t muteTime = time(NULL) + muteseconds;
        player->GetSession()->m_muteTime = muteTime;
        std::ostringstream oss;
        oss << "UPDATE account SET mutetime = " << muteTime << " WHERE id = " << player->GetSession()->GetAccountId();
        LoginDatabase.PExecute("%s", oss.str().c_str());
        return 0;
    }

    /**
     * Rewards the given quest entry for the [Player] if he has completed it.
     *
     * @param uint32 entry : quest entry
     */
    int RewardQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Quest const* quest = eObjectMgr->GetQuestTemplate(entry);

        // If player doesn't have the quest
        if (!quest || player->GetQuestStatus(entry) != QUEST_STATUS_COMPLETE)
            return 0;

        player->RewardQuest(quest, 0, player);
        return 0;
    }

    /**
     * Sends an auction house window to the [Player] from the [Unit] specified
     *
     * @param [Unit] sender
     */
    int SendAuctionMenu(lua_State* L, Player* player)
    {
        Unit* unit = Eluna::CHECKOBJ<Unit>(L, 2);

#ifdef TRINITY
        AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->GetFaction());
#elif AZEROTHCORE
        AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit->getFaction());
#else
        AuctionHouseEntry const* ahEntry = AuctionHouseMgr::GetAuctionHouseEntry(unit);
#endif
        if (!ahEntry)
            return 0;

        WorldPacket data(MSG_AUCTION_HELLO, 12);
#ifdef TRINITY
        data << uint64(unit->GetGUID().GetCounter());
        data << uint32(ahEntry->ID);
#else
        data << uint64(unit->GetGUIDLow());
        data << uint32(ahEntry->houseId);
#endif
        data << uint8(1);
#ifdef CMANGOS
        player->GetSession()->SendPacket(data);
#else
        player->GetSession()->SendPacket(&data);
#endif
        return 0;
    }

    /**
     * Sends a flightmaster window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    int SendTaxiMenu(lua_State* L, Player* player)
    {
        Creature* creature = Eluna::CHECKOBJ<Creature>(L, 2);

        player->GetSession()->SendTaxiMenu(creature);
        return 0;
    }

    /**
     * Sends a spirit resurrection request to the [Player]
     */
    int SendSpiritResurrect(lua_State* /*L*/, Player* player)
    {
        player->GetSession()->SendSpiritResurrect();
        return 0;
    }

    /**
     * Sends a tabard vendor window to the [Player] from the [WorldObject] specified
     *
     * @param [WorldObject] sender
     */
    int SendTabardVendorActivate(lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendTabardVendorActivate(obj->GET_GUID());
        return 0;
    }

    /**
     * Sends a bank window to the [Player] from the [WorldObject] specified.
     *
     * @param [WorldObject] sender
     */
    int SendShowBank(lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendShowBank(obj->GET_GUID());
        return 0;
    }
    
    /**
     * Sends a vendor window to the [Player] from the [WorldObject] specified.
     *
     * @param [WorldObject] sender
     */
    int SendListInventory(lua_State* L, Player* player)
    {
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 2);

        player->GetSession()->SendListInventory(obj->GET_GUID());
        return 0;
    }

    /**
     * Sends a trainer window to the [Player] from the [Creature] specified
     *
     * @param [Creature] sender
     */
    int SendTrainerList(lua_State* L, Player* player)
    {
        Creature* obj = Eluna::CHECKOBJ<Creature>(L, 2);

#ifdef TRINITY
        player->GetSession()->SendTrainerList(obj);
#else
        player->GetSession()->SendTrainerList(obj->GET_GUID());
#endif
        return 0;
    }

    /**
     * Sends a guild invitation from the [Player]s [Guild] to the [Player] object specified
     *
     * @param [Player] invitee
     */
    int SendGuildInvite(lua_State* L, Player* player)
    {
        Player* plr = Eluna::CHECKOBJ<Player>(L, 2);

#if defined TRINITY || AZEROTHCORE
        if (Guild* guild = player->GetGuild())
            guild->HandleInviteMember(player->GetSession(), plr->GetName());
#else
        player->GetSession()->SendGuildInvite(plr);
#endif
        return 0;
    }

    /**
     * Forces the [Player] to log out
     *
     * @param bool saveToDb = true
     */
    int LogoutPlayer(lua_State* L, Player* player)
    {
        bool save = Eluna::CHECKVAL<bool>(L, 2, true);

        player->GetSession()->LogoutPlayer(save);
        return 0;
    }

    /**
     * Forcefully removes the [Player] from a [BattleGround] raid group
     */
    int RemoveFromBattlegroundRaid(lua_State* /*L*/, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        player->RemoveFromBattlegroundOrBattlefieldRaid();
#else
        player->RemoveFromBattleGroundRaid();
#endif
        return 0;
    }

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     *
     * Difficulty is not used on classic.
     *
     * @param uint32 map = true
     * @param uint32 difficulty = 0
     */
    int UnbindInstance(lua_State* L, Player* player)
    {
        uint32 map = Eluna::CHECKVAL<uint32>(L, 2);
#ifndef CLASSIC
        uint32 difficulty = Eluna::CHECKVAL<uint32>(L, 3, 0);

        if (difficulty < MAX_DIFFICULTY)
#ifndef AZEROTHCORE
            player->UnbindInstance(map, (Difficulty)difficulty);
#else
            sInstanceSaveMgr->PlayerUnbindInstance(player->GetGUIDLow(), map, Difficulty(difficulty), true, player);
#endif//AZEROTHCORE
#else//CLASSIC
        player->UnbindInstance(map);
#endif
        return 0;
    }

    /**
     * Unbinds the [Player] from his instances except the one he currently is in.
     */
    int UnbindAllInstances(lua_State* /*L*/, Player* player)
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
        return 0;
    }

    /**
     * Forces the [Player] to leave a [BattleGround]
     *
     * @param bool teleToEntry = true
     */
    int LeaveBattleground(lua_State* L, Player* player)
    {
        (void)L; // ensure that the variable is referenced in order to pass compiler checks
#ifndef AZEROTHCORE
        bool teleToEntryPoint = Eluna::CHECKVAL<bool>(L, 2, true);
        player->LeaveBattleground(teleToEntryPoint);
#else
        player->LeaveBattleground();
#endif
        return 0;
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
    int DurabilityRepair(lua_State* L, Player* player)
    {
        uint16 position = Eluna::CHECKVAL<uint16>(L, 2);
        bool cost = Eluna::CHECKVAL<bool>(L, 3, true);
        float discountMod = Eluna::CHECKVAL<float>(L, 4);
        bool guildBank = Eluna::CHECKVAL<bool>(L, 5, false);

#ifdef CLASSIC
        Eluna::Push(L, player->DurabilityRepair(position, cost, discountMod));
#else
        Eluna::Push(L, player->DurabilityRepair(position, cost, discountMod, guildBank));
#endif
        return 1;
    }

    /**
     * Repairs all [Item]s. Returns total repair cost
     *
     * @param bool cost = true
     * @param float discountMod = 1
     * @param bool guidBank = false
     * @return uint32 totalCost
     */
    int DurabilityRepairAll(lua_State* L, Player* player)
    {
        bool cost = Eluna::CHECKVAL<bool>(L, 2, true);
        float discountMod = Eluna::CHECKVAL<float>(L, 3, 1.0f);
        bool guildBank = Eluna::CHECKVAL<bool>(L, 4, false);

#ifdef CLASSIC
        Eluna::Push(L, player->DurabilityRepairAll(cost, discountMod));
#else
        Eluna::Push(L, player->DurabilityRepairAll(cost, discountMod, guildBank));
#endif
        return 1;
    }

    /**
     * Sets durability loss for an [Item] in the specified slot
     *
     * @param int32 slot
     */
    int DurabilityPointLossForEquipSlot(lua_State* L, Player* player)
    {
        int32 slot = Eluna::CHECKVAL<int32>(L, 2);

        if (slot >= EQUIPMENT_SLOT_START && slot < EQUIPMENT_SLOT_END)
            player->DurabilityPointLossForEquipSlot((EquipmentSlots)slot);
        return 0;
    }

    /**
     * Sets durability loss on all [Item]s equipped
     *
     * If inventory is true, sets durability loss for [Item]s in bags
     *
     * @param int32 points
     * @param bool inventory = true
     */
    int DurabilityPointsLossAll(lua_State* L, Player* player)
    {
        int32 points = Eluna::CHECKVAL<int32>(L, 2);
        bool inventory = Eluna::CHECKVAL<bool>(L, 3, true);

        player->DurabilityPointsLossAll(points, inventory);
        return 0;
    }

    /**
     * Sets durability loss for the specified [Item]
     *
     * @param [Item] item
     * @param int32 points
     */
    int DurabilityPointsLoss(lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2);
        int32 points = Eluna::CHECKVAL<int32>(L, 3);

        player->DurabilityPointsLoss(item, points);
        return 0;
    }

    /**
     * Damages specified [Item]
     *
     * @param [Item] item
     * @param double percent
     */
    int DurabilityLoss(lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2);
        double percent = Eluna::CHECKVAL<double>(L, 3);

        player->DurabilityLoss(item, percent);
        return 0;
    }

    /**
     * Damages all [Item]s equipped. If inventory is true, damages [Item]s in bags
     *
     * @param double percent
     * @param bool inventory = true
     */
    int DurabilityLossAll(lua_State* L, Player* player)
    {
        double percent = Eluna::CHECKVAL<double>(L, 2);
        bool inventory = Eluna::CHECKVAL<bool>(L, 3, true);

        player->DurabilityLossAll(percent, inventory);
        return 0;
    }

    /**
     * Kills the [Player]
     */
    int KillPlayer(lua_State* /*L*/, Player* player)
    {
        player->KillPlayer();
        return 0;
    }

    /**
     * Forces the [Player] to leave a [Group]
     */
    int RemoveFromGroup(lua_State* /*L*/, Player* player)
    {
        if (!player->GetGroup())
            return 0;

        player->RemoveFromGroup();
        return 0;
    }

    /**
     * Returns the [Player]s accumulated talent reset cost
     *
     * @return uint32 resetCost
     */
    int ResetTalentsCost(lua_State* L, Player* player)
    {
#ifdef CATA
        Eluna::Push(L, player->GetNextResetTalentsCost());
#else
#ifdef TRINITY
        Eluna::Push(L, player->ResetTalentsCost());
#else
        Eluna::Push(L, player->resetTalentsCost());
#endif
#endif
        return 1;
    }

    /**
     * Resets the [Player]s talents
     *
     * @param bool noCost = true
     */
    int ResetTalents(lua_State* L, Player* player)
    {
        bool no_cost = Eluna::CHECKVAL<bool>(L, 2, true);

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
        return 0;
    }

    /**
     * Removes the [Spell] from the [Player]
     *
     * @param uint32 entry : entry of a [Spell]
     * @param bool disabled = false
     * @param bool learnLowRank = true
     */
    int RemoveSpell(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        bool disabled = Eluna::CHECKVAL<bool>(L, 3, false);
        bool learn_low_rank = Eluna::CHECKVAL<bool>(L, 4, true);

#ifdef TRINITY
        player->RemoveSpell(entry, disabled, learn_low_rank);
#else
        player->removeSpell(entry, disabled, learn_low_rank);
#endif
        return 0;
    }

    /**
     * Clears the [Player]s combo points
     */
    int ClearComboPoints(lua_State* /*L*/, Player* player)
    {
        player->ClearComboPoints();
        return 0;
    }

    /**
     * Adds combo points to the [Player]
     *
     * @param [Unit] target
     * @param int8 count
     */
    int AddComboPoints(lua_State* L, Player* player)
    {
        Unit* target = Eluna::CHECKOBJ<Unit>(L, 2);
        int8 count = Eluna::CHECKVAL<int8>(L, 3);

        player->AddComboPoints(target, count);
        return 0;
    }

    /**
     * Gives [Quest] monster talked to credit
     *
     * @param uint32 entry : entry of a [Creature]
     * @param [Creature] creature
     */
    int TalkedToCreature(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
        Creature* creature = Eluna::CHECKOBJ<Creature>(L, 3);

        player->TalkedToCreature(entry, creature->GET_GUID());
        return 0;
    }

    /**
     * Gives [Quest] monster killed credit
     *
     * @param uint32 entry : entry of a [Creature]
     */
    int KilledMonsterCredit(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->KilledMonsterCredit(entry, player->GET_GUID());
        return 0;
    }

    /**
     * Completes a [Quest] if in a [Group]
     *
     * @param uint32 quest : entry of a quest
     * @param [WorldObject] obj
     */
    int GroupEventHappens(lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        WorldObject* obj = Eluna::CHECKOBJ<WorldObject>(L, 3);

        player->GroupEventHappens(questId, obj);
        return 0;
    }

    /**
     * Completes the [Quest] if a [Quest] area is explored, or completes the [Quest]
     *
     * @param uint32 quest : entry of a [Quest]
     */
    int AreaExploredOrEventHappens(lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);

        player->AreaExploredOrEventHappens(questId);
        return 0;
    }

    /**
     * Sets the given [Quest] entry failed for the [Player].
     *
     * @param uint32 entry : entry of a [Quest]
     */
    int FailQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->FailQuest(entry);
        return 0;
    }

    /**
     * Sets the given quest entry incomplete for the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int IncompleteQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        player->IncompleteQuest(entry);
        return 0;
    }

    /**
     * Completes the given quest entry for the [Player] and tries to satisfy all quest requirements.
     *
     * The player should have the quest to complete it.
     *
     * @param uint32 entry : quest entry
     */
    int CompleteQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Quest const* quest = eObjectMgr->GetQuestTemplate(entry);

        // If player doesn't have the quest
        if (!quest || player->GetQuestStatus(entry) == QUEST_STATUS_NONE)
            return 0;

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
        return 0;
    }

    /**
     * Tries to add the given quest entry for the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int AddQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Quest const* quest = eObjectMgr->GetQuestTemplate(entry);

        if (!quest)
            return 0;

#if defined TRINITY || AZEROTHCORE
        // check item starting quest (it can work incorrectly if added without item in inventory)
#ifndef AZEROTHCORE
        ItemTemplateContainer const& itc = sObjectMgr->GetItemTemplateStore();
        auto itr = std::find_if(std::begin(itc), std::end(itc), [quest](ItemTemplateContainer::value_type const& value)
        {
            return value.second.StartQuest == quest->GetQuestId();
        });

        if (itr != std::end(itc))
            return 0;
#else
        ItemTemplateContainer const* itc = sObjectMgr->GetItemTemplateStore();
        ItemTemplateContainer::const_iterator result = find_if(itc->begin(), itc->end(), Finder<uint32, ItemTemplate>(entry, &ItemTemplate::StartQuest));

        if (result != itc->end())
            return 0;
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

            if (pProto->StartQuest == entry)
                return 0;
        }

        // ok, normal (creature/GO starting) quest
        if (player->CanAddQuest(quest, true))
        {
            player->AddQuest(quest, NULL);

            if (player->CanCompleteQuest(entry))
                player->CompleteQuest(entry);
        }
#endif

        return 0;
    }

    /**
     * Removes the given quest entry from the [Player].
     *
     * @param uint32 entry : quest entry
     */
    int RemoveQuest(lua_State* L, Player* player)
    {
        uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

        Quest const* quest = eObjectMgr->GetQuestTemplate(entry);

        if (!quest)
            return 0;

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
        return 0;
    }

    /**
     * Sends whisper text from the [Player]
     *
     * @param string text
     * @param uint32 lang : language the [Player] will speak
     * @param [Player] receiver : is the [Player] that will receive the whisper, if TrinityCore
     * @param uint64 guid : is the GUID of a [Player] that will receive the whisper, not TrinityCore
     */
    int Whisper(lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        Player* receiver = Eluna::CHECKOBJ<Player>(L, 4);
#else
        uint64 guid = Eluna::CHECKVAL<uint64>(L, 4);
#endif
#ifdef TRINITY
        player->Whisper(text, (Language)lang, receiver);
#else
        player->Whisper(text, lang, ObjectGuid(guid));
#endif
        return 0;
    }

    /**
     * Sends a text emote from the [Player]
     *
     * @param string emoteText
     */
    int TextEmote(lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);

        player->TextEmote(text);
        return 0;
    }

    /**
     * Sends yell text from the [Player]
     *
     * @param string text : text for the [Player] to yells
     * @param uint32 lang : language the [Player] will speak
     */
    int Yell(lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        player->Yell(text, (Language)lang);
#else
        player->Yell(text, lang);
#endif
        return 0;
    }

    /**
     * Sends say text from the [Player]
     *
     * @param string text : text for the [Player] to say
     * @param uint32 lang : language the [Player] will speak
     */
    int Say(lua_State* L, Player* player)
    {
        std::string text = Eluna::CHECKVAL<std::string>(L, 2);
        uint32 lang = Eluna::CHECKVAL<uint32>(L, 3);
#ifdef TRINITY
        player->Say(text, (Language)lang);
#else
        player->Say(text, lang);
#endif
        return 0;
    }

    /**
     * Gives the [Player] experience
     *
     * @param uint32 xp : experience to give
     * @param [Unit] victim = nil
     */
    int GiveXP(lua_State* L, Player* player)
    {
        uint32 xp = Eluna::CHECKVAL<uint32>(L, 2);
        Unit* victim = Eluna::CHECKOBJ<Unit>(L, 3, false);

        player->GiveXP(xp, victim);
        return 0;
    }

    /**
     * Toggle the [Player]s 'Do Not Disturb' flag
     */
    int ToggleDND(lua_State* /*L*/, Player* player)
    {
        player->ToggleDND();
        return 0;
    }

    /**
     * Toggle the [Player]s 'Away From Keyboard' flag
     */
    int ToggleAFK(lua_State* /*L*/, Player* player)
    {
        player->ToggleAFK();
        return 0;
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
     *     };
     *
     *     enum InventorySlots // 4 slots
     *     {
     *         INVENTORY_SLOT_BAG_START    = 19,
     *         INVENTORY_SLOT_BAG_END      = 23
     *     };
     *
     * @proto equippedItem = (item, slot)
     * @proto equippedItem = (entry, slot)
     * @param [Item] item : item to equip
     * @param uint32 entry : entry of the item to equip
     * @param uint32 slot : equipment slot to equip the item to The slot can be [EquipmentSlots] or [InventorySlots]
     * @return [Item] equippedItem : item or nil if equipping failed
     */
    int EquipItem(lua_State* L, Player* player)
    {
        uint16 dest = 0;
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 slot = Eluna::CHECKVAL<uint32>(L, 3);

        if (slot >= INVENTORY_SLOT_BAG_END)
            return 1;

        if (!item)
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            item = Item::CreateItem(entry, 1, player);
            if (!item)
                return 1;

            InventoryResult result = player->CanEquipItem(slot, dest, item, false);
            if (result != EQUIP_ERR_OK)
            {
                delete item;
                return 1;
            }
            player->ItemAddedQuestCheck(entry, 1);
#if (!defined(TBC) && !defined(CLASSIC))
            player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, entry, 1);
#endif
        }
        else
        {
            InventoryResult result = player->CanEquipItem(slot, dest, item, false);
            if (result != EQUIP_ERR_OK)
                return 1;
            player->RemoveItem(item->GetBagSlot(), item->GetSlot(), true);
        }

        Eluna::Push(L, player->EquipItem(dest, item, true));
        player->AutoUnequipOffhandIfNeed();
        return 1;
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
    int CanEquipItem(lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 slot = Eluna::CHECKVAL<uint32>(L, 3);
        if (slot >= EQUIPMENT_SLOT_END)
        {
            Eluna::Push(L, false);
            return 1;
        }

        if (!item)
        {
            uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
            uint16 dest;
            InventoryResult msg = player->CanEquipNewItem(slot, dest, entry, false);
            if (msg != EQUIP_ERR_OK)
            {
                Eluna::Push(L, false);
                return 1;
            }
        }
        else
        {
            uint16 dest;
            InventoryResult msg = player->CanEquipItem(slot, dest, item, false);
            if (msg != EQUIP_ERR_OK)
            {
                Eluna::Push(L, false);
                return 1;
            }
        }
        Eluna::Push(L, true);
        return 1;
    }

#ifndef CLASSIC
    /**
     * Removes a title by ID from the [Player]s list of known titles
     *
     * @param uint32 titleId
     */
    int UnsetKnownTitle(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        CharTitlesEntry const* t = sCharTitlesStore.LookupEntry(id);
        if (t)
            player->SetTitle(t, true);
        return 0;
    }
#endif

    /**
     * Advances all of the [Player]s weapon skills to the maximum amount available
     */
    int AdvanceSkillsToMax(lua_State* /*L*/, Player* player)
    {
#ifdef TRINITY
        player->UpdateWeaponsSkillsToMaxSkillsForLevel();
#else
        player->UpdateSkillsToMaxSkillsForLevel();
#endif
        return 0;
    }

    /**
     * Advances all of the [Player]s skills to the amount specified
     *
     * @param uint32 skillStep
     */
    int AdvanceAllSkills(lua_State* L, Player* player)
    {
        uint32 step = Eluna::CHECKVAL<uint32>(L, 2);

        if (!step)
            return 0;

        for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i)
        {
            if (SkillLineEntry const* entry = sSkillLineStore.LookupEntry(i))
            {
#ifdef TRINITY
                if (entry->CategoryID == SKILL_CATEGORY_LANGUAGES || entry->CategoryID == SKILL_CATEGORY_GENERIC)
                    continue;

                if (player->HasSkill(entry->ID))
                    player->UpdateSkill(entry->ID, step);
#else
                if (entry->categoryId == SKILL_CATEGORY_LANGUAGES || entry->categoryId == SKILL_CATEGORY_GENERIC)
                    continue;

                if (player->HasSkill(entry->id))
                    player->UpdateSkill(entry->id, step);
#endif
            }
        }

        return 0;
    }

    /**
     * Advances a [Player]s specific skill to the amount specified
     *
     * @param uint32 skillId
     * @param uint32 skillStep
     */
    int AdvanceSkill(lua_State* L, Player* player)
    {
        uint32 _skillId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 _step = Eluna::CHECKVAL<uint32>(L, 3);
        if (_skillId && _step)
        {
            if (player->HasSkill(_skillId))
                player->UpdateSkill(_skillId, _step);
        }
        return 0;
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
    int Teleport(lua_State* L, Player* player)
    {
        uint32 mapId = Eluna::CHECKVAL<uint32>(L, 2);
        float x = Eluna::CHECKVAL<float>(L, 3);
        float y = Eluna::CHECKVAL<float>(L, 4);
        float z = Eluna::CHECKVAL<float>(L, 5);
        float o = Eluna::CHECKVAL<float>(L, 6);
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
        Eluna::Push(L, player->TeleportTo(mapId, x, y, z, o));
        return 1;
    }

    int AddLifetimeKills(lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills + val);
        return 0;
    }
    
    /**
     * Adds the given amount of the specified item entry to the player.
     *
     * @param uint32 entry : entry of the item to add
     * @param uint32 itemCount = 1 : amount of the item to add
     * @return [Item] item : the item that was added or nil
     */
    int AddItem(lua_State* L, Player* player)
    {
        uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 itemCount = Eluna::CHECKVAL<uint32>(L, 3, 1);

#if defined TRINITY || AZEROTHCORE
        uint32 noSpaceForCount = 0;
        ItemPosCountVec dest;
        InventoryResult msg = player->CanStoreNewItem(NULL_BAG, NULL_SLOT, dest, itemId, itemCount, &noSpaceForCount);
        if (msg != EQUIP_ERR_OK)
            itemCount -= noSpaceForCount;

        if (itemCount == 0 || dest.empty())
            return 1;
#ifndef AZEROTHCORE
        Item* item = player->StoreNewItem(dest, itemId, true, GenerateItemRandomPropertyId(itemId));
#else
        Item* item = player->StoreNewItem(dest, itemId, true, Item::GenerateItemRandomPropertyId(itemId));
#endif
        if (item)
            player->SendNewItem(item, itemCount, true, false);
        Eluna::Push(L, item);
#else
        Eluna::Push(L, player->StoreNewItemInInventorySlot(itemId, itemCount));
#endif
        return 1;
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
    int RemoveItem(lua_State* L, Player* player)
    {
        Item* item = Eluna::CHECKOBJ<Item>(L, 2, false);
        uint32 itemCount = Eluna::CHECKVAL<uint32>(L, 3);
        if (!item)
        {
            uint32 itemId = Eluna::CHECKVAL<uint32>(L, 2);
            player->DestroyItemCount(itemId, itemCount, true);
        }
        else
        {
            bool all = itemCount >= item->GetCount();
            player->DestroyItemCount(item, itemCount, true);
            if (all)
                Eluna::CHECKOBJ<ElunaObject>(L, 2)->Invalidate();
        }
        return 0;
    }

    /**
     * Removes specified amount of lifetime kills
     *
     * @param uint32 val : kills to remove
     */
    int RemoveLifetimeKills(lua_State* L, Player* player)
    {
        uint32 val = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 currentKills = player->GetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS);
        if (val > currentKills)
            val = currentKills;
        player->SetUInt32Value(PLAYER_FIELD_LIFETIME_HONORABLE_KILLS, currentKills - val);
        return 0;
    }

    /**
     * Resets cooldown of the specified spell
     *
     * @param uint32 spellId
     * @param bool update = true
     */
    int ResetSpellCooldown(lua_State* L, Player* player)
    {
        uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
        bool update = Eluna::CHECKVAL<bool>(L, 3, true);
#ifdef TRINITY
        player->GetSpellHistory()->ResetCooldown(spellId, update);
#else
        player->RemoveSpellCooldown(spellId, update);
#endif
        return 0;
    }

    /**
     * Resets cooldown of the specified category
     *
     * @param uint32 category
     * @param bool update = true
     */
    int ResetTypeCooldowns(lua_State* L, Player* player)
    {
        uint32 category = Eluna::CHECKVAL<uint32>(L, 2);
        bool update = Eluna::CHECKVAL<bool>(L, 3, true);
        (void)update; // ensure that the variable is referenced in order to pass compiler checks

#ifdef TRINITY
        player->GetSpellHistory()->ResetCooldowns([category](SpellHistory::CooldownStorageType::iterator itr) -> bool
        {
            SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(itr->first);
            return spellInfo && spellInfo->GetCategory() == category;
        }, update);
#else
#ifndef AZEROTHCORE
        player->RemoveSpellCategoryCooldown(category, update);
#else
        player->RemoveCategoryCooldown(category);
#endif
#endif
        return 0;
    }

    /**
     * Resets all of the [Player]'s cooldowns
     */
    int ResetAllCooldowns(lua_State* /*L*/, Player* player)
    {
#ifdef TRINITY
        player->GetSpellHistory()->ResetAllCooldowns();
#else
        player->RemoveAllSpellCooldown();
#endif
        return 0;
    }

    /**
     * Sends a Broadcast Message to the [Player]
     *
     * @param string message
     */
    int SendBroadcastMessage(lua_State* L, Player* player)
    {
        const char* message = Eluna::CHECKVAL<const char*>(L, 2);
        if (std::string(message).length() > 0)
            ChatHandler(player->GetSession()).SendSysMessage(message);
        return 0;
    }

    /**
     * Sends an Area Trigger Message to the [Player]
     *
     * @param string message
     */
    int SendAreaTriggerMessage(lua_State* L, Player* player)
    {
        std::string msg = Eluna::CHECKVAL<std::string>(L, 2);
        if (msg.length() > 0)
            player->GetSession()->SendAreaTriggerMessage("%s", msg.c_str());
        return 0;
    }

    /**
     * Sends a Notification to the [Player]
     *
     * @param string message
     */
    int SendNotification(lua_State* L, Player* player)
    {
        std::string msg = Eluna::CHECKVAL<std::string>(L, 2);
        if (msg.length() > 0)
            player->GetSession()->SendNotification("%s", msg.c_str());
        return 0;
    }

    /**
     * Sends a [WorldPacket] to the [Player]
     *
     * @param [WorldPacket] packet
     * @param bool selfOnly = true
     */
    int SendPacket(lua_State* L, Player* player)
    {
        WorldPacket* data = Eluna::CHECKOBJ<WorldPacket>(L, 2);
        bool selfOnly = Eluna::CHECKVAL<bool>(L, 3, true);
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
        return 0;
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
    int SendAddonMessage(lua_State* L, Player* player)
    {
        std::string prefix = Eluna::CHECKVAL<std::string>(L, 2);
        std::string message = Eluna::CHECKVAL<std::string>(L, 3);
        uint8 channel = Eluna::CHECKVAL<uint8>(L, 4);
        Player* receiver = Eluna::CHECKOBJ<Player>(L, 5);

        std::string fullmsg = prefix + "\t" + message;

        WorldPacket data(SMSG_MESSAGECHAT, 100);
        data << uint8(channel);
        data << int32(LANG_ADDON);
        data << uint64(player->GET_GUID());
#ifndef CLASSIC
        data << uint32(0);
        data << uint64(receiver->GET_GUID());
#endif
        data << uint32(fullmsg.length() + 1);
        data << fullmsg;
        data << uint8(0);
#ifdef CMANGOS
        receiver->GetSession()->SendPacket(data);
#else
        receiver->GetSession()->SendPacket(&data);
#endif
        return 0;
    }

    /**
     * Kicks the [Player] from the server
     */
    int KickPlayer(lua_State* /*L*/, Player* player)
    {
#ifdef TRINITY
        player->GetSession()->KickPlayer("PlayerMethods::KickPlayer Kick the player");
#else
        player->GetSession()->KickPlayer();
#endif
        return 0;
    }

    /**
     * Adds or subtracts from the [Player]s money in copper
     *
     * @param int32 copperAmt : negative to remove, positive to add
     */
    int ModifyMoney(lua_State* L, Player* player)
    {
        int32 amt = Eluna::CHECKVAL<int32>(L, 2);

        player->ModifyMoney(amt);
        return 1;
    }

    /**
     * Teaches the [Player] the [Spell] specified by entry ID
     *
     * @param uint32 spellId
     */
    int LearnSpell(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);

#ifdef TRINITY
        player->LearnSpell(id, false);
#elif AZEROTHCORE
        player->learnSpell(id);
#else
        player->learnSpell(id, false);
#endif
        return 0;
    }

    /**
     * Learn the [Player] the talent specified by talent_id and talentRank
     *
     * @param uint32 talent_id
     * @param uint32 talentRank
     */
    int LearnTalent(lua_State* L, Player* player)
    {
        uint32 id = Eluna::CHECKVAL<uint32>(L, 2);
        uint32 rank = Eluna::CHECKVAL<uint32>(L, 3);

        player->LearnTalent(id, rank);
#if (!defined(TBC) && !defined(CLASSIC))
        player->SendTalentsInfoData(false);
#endif

#if !defined TRINITY && !AZEROTHCORE
        // if player has a pet, update owner talent auras
        if (player->GetPet())
            player->GetPet()->CastOwnerTalentAuras();
#endif
        return 0;
    }

    /**
     * Resurrects the [Player].
     *
     * @param float healthPercent = 100.0f
     * @param bool ressSickness = false
     */
    int ResurrectPlayer(lua_State* L, Player* player)
    {
        float percent = Eluna::CHECKVAL<float>(L, 2, 100.0f);
        bool sickness = Eluna::CHECKVAL<bool>(L, 3, false);
        player->ResurrectPlayer(percent, sickness);
        player->SpawnCorpseBones();
        return 0;
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
    int GossipMenuAddItem(lua_State* L, Player* player)
    {
        uint32 _icon = Eluna::CHECKVAL<uint32>(L, 2);
        const char* msg = Eluna::CHECKVAL<const char*>(L, 3);
        uint32 _sender = Eluna::CHECKVAL<uint32>(L, 4);
        uint32 _intid = Eluna::CHECKVAL<uint32>(L, 5);
        bool _code = Eluna::CHECKVAL<bool>(L, 6, false);
        const char* _promptMsg = Eluna::CHECKVAL<const char*>(L, 7, "");
        uint32 _money = Eluna::CHECKVAL<uint32>(L, 8, 0);
#if defined TRINITY || AZEROTHCORE
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(-1, _icon, msg, _sender, _intid, _promptMsg, _money, _code);
#else
#ifndef CLASSIC
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg, _sender, _intid, _promptMsg, _money, _code);
#else
        player->PlayerTalkClass->GetGossipMenu().AddMenuItem(_icon, msg, _sender, _intid, _promptMsg, _code);
#endif
#endif//TRINITY
        return 0;
    }

    /**
     * Closes the [Player]s currently open Gossip Menu.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipAddQuests], [Player:GossipSendMenu], [Player:GossipClearMenu]
     */
    int GossipComplete(lua_State* /*L*/, Player* player)
    {
#if defined TRINITY || AZEROTHCORE
        player->PlayerTalkClass->SendCloseGossip();
#else
        player->PlayerTalkClass->CloseGossip();
#endif
        return 0;
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
    int GossipSendMenu(lua_State* L, Player* player)
    {
        uint32 npc_text = Eluna::CHECKVAL<uint32>(L, 2);
        Object* sender = Eluna::CHECKOBJ<Object>(L, 3);
        if (sender->GetTypeId() == TYPEID_PLAYER)
        {
            uint32 menu_id = Eluna::CHECKVAL<uint32>(L, 4);
            player->PlayerTalkClass->GetGossipMenu().SetMenuId(menu_id);
        }
        player->PlayerTalkClass->SendGossipMenu(npc_text, sender->GET_GUID());
        return 0;
    }

    /**
     * Clears the [Player]s current gossip item list.
     *
     * See also: [Player:GossipMenuAddItem], [Player:GossipSendMenu], [Player:GossipAddQuests], [Player:GossipComplete]
     * 
     *     Note: This is needed when you show a gossip menu without using gossip hello or select hooks which do this automatically.
     *     Usually this is needed when using [Player] is the sender of a Gossip Menu.
     */
    int GossipClearMenu(lua_State* /*L*/, Player* player)
    {
        player->PlayerTalkClass->ClearMenus();
        return 0;
    }

    /**
     * Attempts to start the taxi/flying to the given pathID
     *
     * @param uint32 pathId : pathId from DBC or [Global:AddTaxiPath]
     */
    int StartTaxi(lua_State* L, Player* player)
    {
        uint32 pathId = Eluna::CHECKVAL<uint32>(L, 2);

        player->ActivateTaxiPathTo(pathId);
        return 0;
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
    int GossipSendPOI(lua_State* L, Player* player)
    {
        float x = Eluna::CHECKVAL<float>(L, 2);
        float y = Eluna::CHECKVAL<float>(L, 3);
        uint32 icon = Eluna::CHECKVAL<uint32>(L, 4);
        uint32 flags = Eluna::CHECKVAL<uint32>(L, 5);
        uint32 data = Eluna::CHECKVAL<uint32>(L, 6);
        std::string iconText = Eluna::CHECKVAL<std::string>(L, 7);

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
        return 0;
    }

    /**
     * Adds the gossip items to the [Player]'s gossip for the quests the given [WorldObject] can offer to the player.
     *
     * @param [WorldObject] source : a questgiver with quests
     */
    int GossipAddQuests(lua_State* L, Player* player)
    {
        WorldObject* source = Eluna::CHECKOBJ<WorldObject>(L, 2);

        if (source->GetTypeId() == TYPEID_UNIT)
        {
            if (source->GetUInt32Value(UNIT_NPC_FLAGS) & UNIT_NPC_FLAG_QUESTGIVER)
                player->PrepareQuestMenu(source->GET_GUID());
        }
        else if (source->GetTypeId() == TYPEID_GAMEOBJECT)
        {
            if (source->ToGameObject()->GetGoType() == GAMEOBJECT_TYPE_QUESTGIVER)
                player->PrepareQuestMenu(source->GET_GUID());
        }
        return 0;
    }

    /**
     * Shows a quest accepting window to the [Player] for the given quest.
     *
     * @param uint32 questId : entry of a quest
     * @param bool activateAccept = true : auto finish the quest
     */
    int SendQuestTemplate(lua_State* L, Player* player)
    {
        uint32 questId = Eluna::CHECKVAL<uint32>(L, 2);
        bool activateAccept = Eluna::CHECKVAL<bool>(L, 3, true);

        Quest const* quest = eObjectMgr->GetQuestTemplate(questId);
        if (!quest)
            return 0;

        player->PlayerTalkClass->SendQuestGiverQuestDetails(quest, player->GET_GUID(), activateAccept);
        return 0;
    }

    /**
     * Converts [Player]'s corpse to bones
     */
    int SpawnBones(lua_State* /*L*/, Player* player)
    {
        player->SpawnCorpseBones();
        return 0;
    }

    /**
     * Loots [Player]'s bones for insignia
     *
     * @param [Player] looter
     */
    int RemovedInsignia(lua_State* L, Player* player)
    {
        Player* looter = Eluna::CHECKOBJ<Player>(L, 2);
        player->RemovedInsignia(looter);
        return 0;
    }

    /**
     * Makes the [Player] invite another player to a group.
     *
     * @param [Player] invited : player to invite to group
     * @return bool success : true if the player was invited to a group
     */
    int GroupInvite(lua_State* L, Player* player)
    {
        Player* invited = Eluna::CHECKOBJ<Player>(L, 2);

        if (invited->GetGroup() || invited->GetGroupInvite())
        {
            Eluna::Push(L, false);
            return 1;
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

        Eluna::Push(L, success);
        return 1;
    }

    /**
     * Creates a new [Group] with the creator [Player] as leader.
     *
     * @param [Player] invited : player to add to group
     * @return [Group] createdGroup : the created group or nil
     */
    int GroupCreate(lua_State* L, Player* player)
    {
        Player* invited = Eluna::CHECKOBJ<Player>(L, 2);

        if (player->GetGroup() || invited->GetGroup())
            return 0;

        if (player->GetGroupInvite())
            player->UninviteFromGroup();
        if (invited->GetGroupInvite())
            invited->UninviteFromGroup();

        // Try create new group
        Group* group = new Group;
        if (!group->AddLeaderInvite(player))
        {
            delete group;
            return 0;
        }

        // Forming a new group, create it
        if (!group->IsCreated())
        {
            group->RemoveInvite(player);
#if defined TRINITY || AZEROTHCORE
            group->Create(player);
            sGroupMgr->AddGroup(group);
#else
            if (!group->Create(group->GetLeaderGuid(), group->GetLeaderName()))
                return 0;
            sObjectMgr.AddGroup(group);
#endif
        }

#if defined TRINITY || AZEROTHCORE
        if (!group->AddMember(invited))
            return 0;
        group->BroadcastGroupUpdate();
#else
        if (!group->AddMember(invited->GetObjectGuid(), invited->GetName()))
            return 0;
#endif
        Eluna::Push(L, group);
        return 1;
    }

    /**
     * Starts a cinematic for the [Player]
     *
     * @param uint32 CinematicSequenceId : entry of a cinematic
     */
    int SendCinematicStart(lua_State* L, Player* player)
    {
        uint32 CinematicSequenceId = Eluna::CHECKVAL<uint32>(L, 2);

        player->SendCinematicStart(CinematicSequenceId);
        return 0;
    }

#if !defined(CLASSIC) && !defined(TBC)
    /**
     * Starts a movie for the [Player]
     *
     * @param uint32 MovieId : entry of a movie
     */
    int SendMovieStart(lua_State* L, Player* player)
    {
        uint32 MovieId = Eluna::CHECKVAL<uint32>(L, 2);

        player->SendMovieStart(MovieId);
        return 0;
    }
#endif

    /*int BindToInstance(lua_State* L, Player* player)
    {
    player->BindToInstance();
    return 0;
    }*/

    /*int AddTalent(lua_State* L, Player* player)
    {
    uint32 spellId = Eluna::CHECKVAL<uint32>(L, 2);
    uint8 spec = Eluna::CHECKVAL<uint8>(L, 3);
    bool learning = Eluna::CHECKVAL<bool>(L, 4, true);
    if (spec >= MAX_TALENT_SPECS)
    Eluna::Push(L, false);
    else
    Eluna::Push(L, player->AddTalent(spellId, spec, learning));
    return 1;
    }*/

    /*int GainSpellComboPoints(lua_State* L, Player* player)
    {
    int8 count = Eluna::CHECKVAL<int8>(L, 2);

    player->GainSpellComboPoints(count);
    return 0;
    }*/

    /*int KillGOCredit(lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
    uint64 guid = Eluna::CHECKVAL<uint64>(L, 3);
    player->KillCreditGO(entry, guid);
    return 0;
    }*/

    /*int KilledPlayerCredit(lua_State* L, Player* player)
    {
    player->KilledPlayerCredit();
    return 0;
    }*/

    /*int RemoveRewardedQuest(lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

    player->RemoveRewardedQuest(entry);
    return 0;
    }*/

    /*int RemoveActiveQuest(lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);

    player->RemoveActiveQuest(entry);
    return 0;
    }*/

    /*int SummonPet(lua_State* L, Player* player)
    {
    uint32 entry = Eluna::CHECKVAL<uint32>(L, 2);
    float x = Eluna::CHECKVAL<float>(L, 3);
    float y = Eluna::CHECKVAL<float>(L, 4);
    float z = Eluna::CHECKVAL<float>(L, 5);
    float o = Eluna::CHECKVAL<float>(L, 6);
    uint32 petType = Eluna::CHECKVAL<uint32>(L, 7);
    uint32 despwtime = Eluna::CHECKVAL<uint32>(L, 8);

    if (petType >= MAX_PET_TYPE)
    return 0;

    player->SummonPet(entry, x, y, z, o, (PetType)petType, despwtime);
    return 0;
    }*/

    /*int RemovePet(lua_State* L, Player* player)
    {
    int mode = Eluna::CHECKVAL<int>(L, 2, PET_SAVE_AS_DELETED);
    bool returnreagent = Eluna::CHECKVAL<bool>(L, 2, false);

    if (!player->GetPet())
    return 0;

    player->RemovePet(player->GetPet(), (PetSaveMode)mode, returnreagent);
    return 0;
    }*/
};
#endif
