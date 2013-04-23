-- Based on https://raw.github.com/TGM/characters_optimization/master/1.%20characters%20optimization.sql
-- Thanks to original authors!

-- Execute in characters-database
-- REPLACE: `auth` with your auth database name
-- REPLACE: `world` with your world database name

-- AUTH SECTION
DELETE FROM `characters` WHERE `account` NOT IN (SELECT `id` FROM `auth`.`account`);
DELETE FROM `account_data` WHERE `accountId` NOT IN (SELECT `id` FROM `auth`.`account`);
DELETE FROM `account_instance_times` WHERE `accountId` NOT IN (SELECT `id` FROM `auth`.`account`);
DELETE FROM `account_tutorial` WHERE `accountId` NOT IN (SELECT `id` FROM `auth`.`account`);

-- WORLD SECTION
DELETE FROM `creature_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `world`.`creature`);
DELETE FROM `gameobject_respawn` WHERE `guid` NOT IN (SELECT `guid` FROM `world`.`gameobject`);
DELETE FROM `item_instance` WHERE `itemEntry` NOT IN (SELECT `entry` FROM `world`.`item_template`);
DELETE FROM `character_queststatus` WHERE `quest` NOT IN (SELECT `Id` FROM `world`.`quest_template`);
DELETE FROM `character_queststatus_daily` WHERE `quest` NOT IN (SELECT `Id` FROM `world`.`quest_template`);
DELETE FROM `character_queststatus_rewarded` WHERE `quest` NOT IN (SELECT `Id` FROM `world`.`quest_template`);
DELETE FROM `character_queststatus_seasonal` WHERE `quest` NOT IN (SELECT `Id` FROM `world`.`quest_template`);
DELETE FROM `character_queststatus_weekly` WHERE `quest` NOT IN (SELECT `Id` FROM `world`.`quest_template`);

DELETE FROM `creature_respawn` WHERE `instanceId` > 0 AND `instanceId` NOT IN (SELECT `instanceId` FROM `instance`);
DELETE FROM `gameobject_respawn` WHERE `instanceId` > 0 AND `instanceId` NOT IN (SELECT `instanceId` FROM `instance`);

-- CHARACTERS SECTION
DELETE FROM `arena_team` WHERE `captainGuid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `arena_team_member` WHERE `arenaTeamId` NOT IN (SELECT `arenaTeamId` FROM `arena_team`);
DELETE FROM `arena_team_member` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);

DELETE FROM `auctionhouse` WHERE `itemowner` NOT IN (SELECT `guid` FROM `characters`);

DELETE FROM `character_account_data` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_achievement` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_achievement_progress` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_action` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_arena_stats` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_aura` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_banned` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_battleground_data` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_battleground_random` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_equipmentsets` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_gifts` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_glyphs` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_homebind` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_instance` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_inventory` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_pet` WHERE `owner` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_queststatus` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_queststatus_daily` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_queststatus_rewarded` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_queststatus_seasonal` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_queststatus_weekly` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_reputation` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_skills` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_social` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_social` WHERE `friend` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_spell` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_spell_cooldown` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_stats` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_talent` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
TRUNCATE TABLE `corpse`; -- Revive all dead characters

DELETE FROM `groups` WHERE `leaderGuid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `group_member` WHERE `guid` NOT IN (SELECT `guid` FROM `groups`);
DELETE FROM `group_member` WHERE `memberGuid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `group_instance` WHERE `guid` NOT IN (SELECT `guid` FROM `groups`);
-- TRUNCATE TABLE `instance_reset`; -- use only if you want to reschredule cooldowns

DELETE FROM `guild` WHERE `leaderguid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `guild_bank_eventlog` WHERE `playerGuid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `guild_bank_eventlog` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);
DELETE FROM `guild_bank_item` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);
DELETE FROM `guild_bank_right` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);
DELETE FROM `guild_bank_tab` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);
DELETE FROM `guild_eventlog` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);
DELETE FROM `guild_member` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `guild_rank` WHERE `guildid` NOT IN (SELECT `guildid` FROM `guild`);

DELETE FROM `item_instance` WHERE `owner_guid` NOT IN (SELECT `guid` FROM `characters`) AND `owner_guid` != 0;
DELETE FROM `item_refund_instance` WHERE `player_guid` NOT IN (SELECT `guid` FROM `characters`);
TRUNCATE `item_soulbound_trade_data`;

TRUNCATE TABLE `lag_reports`;
TRUNCATE TABLE `lfg_data`;

DELETE FROM `mail` WHERE `receiver` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `mail_items` WHERE `mail_id` NOT IN (SELECT `id` FROM `mail`);

DELETE FROM `pet_aura` WHERE `guid` NOT IN (SELECT `id` FROM `character_pet`);
DELETE FROM `pet_spell` WHERE `guid` NOT IN (SELECT `id` FROM `character_pet`);
DELETE FROM `pet_spell_cooldown` WHERE `guid` NOT IN (SELECT `id` FROM `character_pet`);

DELETE FROM `petition` WHERE `ownerguid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `petition_sign` WHERE `ownerguid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `petition_sign` WHERE `playerguid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `petition_sign` WHERE `petitionguid` NOT IN (SELECT `petitionguid` FROM `petition`);

-- CLEANUP ITEMS
DELETE FROM `auctionhouse` WHERE `itemguid` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `character_aura` WHERE `item_guid` != 0 AND `item_guid` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `character_gifts` WHERE `item_guid` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `character_inventory` WHERE `item` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `guild_bank_item` WHERE `item_guid` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `mail_items` WHERE `item_guid` NOT IN (SELECT `guid` FROM `item_instance`);

DELETE FROM `item_instance` WHERE
    `guid` NOT IN (SELECT `itemguid` FROM `auctionhouse`)
    AND `guid` NOT IN (SELECT `item_guid` FROM `character_gifts`)
 	 AND `guid` NOT IN (SELECT `item` FROM `character_inventory`)
 	 AND `guid` NOT IN (SELECT `item_guid` FROM `guild_bank_item`)
 	 AND `guid` NOT IN (SELECT `item_guid` FROM `mail_items`);

DELETE FROM `petition` WHERE `petitionguid` NOT IN (SELECT `guid` FROM `item_instance`);
DELETE FROM `petition_sign` WHERE `petitionguid` NOT IN (SELECT `petitionguid` FROM `petition`);
DELETE FROM `item_refund_instance` WHERE `item_guid` NOT IN (SELECT `guid` FROM `item_instance`);

-- CUSTOM - ARMORY
-- DELETE FROM `armory_character_stats` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
-- DELETE FROM `armory_game_chart` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
-- DELETE FROM `character_feed_log` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);

-- CUSTOM - LOG
-- DELETE FROM `castle_log` WHERE `player_guid` NOT IN (SELECT `guid` FROM `characters`);

-- CUSTOM - ANTI-CHEAT BACKLOG
-- DELETE FROM `cheaters` WHERE UNIX_TIMESTAMP(NOW()) - UNIX_TIMESTAMP(`last_date`) >= 60 * 60 * 24 * 7 * 4;

-- CUSTOM - TRINICHAT AUTOINVITE
-- DELETE FROM `world`.`irc_inchan` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
-- UPDATE `world`.`irc_inchan` SET `name` = (SELECT `name` FROM `characters` WHERE `characters`.`guid` = `world`.`irc_inchan`.`guid`);