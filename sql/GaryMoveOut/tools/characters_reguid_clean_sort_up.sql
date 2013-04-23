-- Based on https://raw.github.com/TGM/characters_optimization/master/1.%20characters%20optimization.sql
-- Thanks to original authors!

-- Variables, which define guid to start with
SELECT MAX(`guid`) FROM `characters2`.`characters` INTO @START_GUID_CHARS;
SELECT MAX(`guid`) FROM `characters2`.`item_instance` INTO @START_GUID_ITEMS;
SELECT MAX(`guid`) FROM `characters2`.`groups` INTO @START_GUID_GROUP;
SELECT MAX(`id`) FROM `characters2`.`character_pet` INTO @START_GUID_PETS;
SELECT MAX(`id`) FROM `characters2`.`mail` INTO @START_GUID_MAILS;
SELECT MAX(`setguid`) FROM `characters2`.`character_equipmentsets` INTO @START_GUID_EQUIP;


-- ====== STEP 1: Cleanup ======
-- Execute in characters-database
-- REPLACE: `auth` with your auth database name
-- REPLACE: `world` with your world database name

-- AUTH SECTION
DELETE FROM `characters` WHERE `account` NOT IN (SELECT `id` FROM `realmd`.`account`);
DELETE FROM `account_data` WHERE `accountId` NOT IN (SELECT `id` FROM `realmd`.`account`);
DELETE FROM `account_instance_times` WHERE `accountId` NOT IN (SELECT `id` FROM `realmd`.`account`);
DELETE FROM `account_tutorial` WHERE `accountId` NOT IN (SELECT `id` FROM `realmd`.`account`);

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
/*
DELETE FROM `armory_character_stats` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `armory_game_chart` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
DELETE FROM `character_feed_log` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
*/

-- CUSTOM - LOG
/*
DELETE FROM `castle_log` WHERE `player_guid` NOT IN (SELECT `guid` FROM `characters`);
*/

-- CUSTOM - ANTI-CHEAT BACKLOG
/*
DELETE FROM `cheaters` WHERE UNIX_TIMESTAMP(NOW()) - UNIX_TIMESTAMP(`last_date`) >= 60 * 60 * 24 * 7 * 4;
*/

-- CUSTOM - TRINICHAT AUTOINVITE
/*
DELETE FROM `world`.`irc_inchan` WHERE `guid` NOT IN (SELECT `guid` FROM `characters`);
UPDATE `world`.`irc_inchan` SET `name` = (SELECT `name` FROM `characters` WHERE `characters`.`guid` = `world`.`irc_inchan`.`guid`);
*/



-- ====== BEGIN PROCESSING - CHAR GUID ======

-- TABLE: arena_team
UPDATE `arena_team` SET `arena_team`.`captainGuid` = `arena_team`.`captainGuid` + @START_GUID_CHARS ORDER BY `arena_team`.`captainGuid` DESC;

-- TABLE: arena_team_member
UPDATE `arena_team_member` SET `arena_team_member`.`guid` = `arena_team_member`.`guid` + @START_GUID_CHARS ORDER BY `arena_team_member`.`guid` DESC;

-- TABLE: auctionhouse
UPDATE `auctionhouse` SET `auctionhouse`.`buyguid` = `auctionhouse`.`buyguid` + @START_GUID_CHARS WHERE `auctionhouse`.`buyguid` != 0 ORDER BY `auctionhouse`.`buyguid` DESC;
UPDATE `auctionhouse` SET `auctionhouse`.`itemowner` = `auctionhouse`.`itemowner` + @START_GUID_CHARS ORDER BY `auctionhouse`.`itemowner` DESC;

-- TABLE: character_account_data
UPDATE `character_account_data` SET `character_account_data`.`guid` = `character_account_data`.`guid` + @START_GUID_CHARS ORDER BY `character_account_data`.`guid` DESC;

-- TABLE: character_achievement
UPDATE `character_achievement` SET `character_achievement`.`guid` = `character_achievement`.`guid` + @START_GUID_CHARS ORDER BY `character_achievement`.`guid` DESC;

-- TABLE: character_achievement_progress
UPDATE `character_achievement_progress` SET `character_achievement_progress`.`guid` = `character_achievement_progress`.`guid` + @START_GUID_CHARS ORDER BY `character_achievement_progress`.`guid` DESC;

-- TABLE: character_action
UPDATE `character_action` SET `character_action`.`guid` = `character_action`.`guid` + @START_GUID_CHARS ORDER BY `character_action`.`guid` DESC;

-- TABLE: character_arena_stats
UPDATE `character_arena_stats` SET `character_arena_stats`.`guid` = `character_arena_stats`.`guid` + @START_GUID_CHARS ORDER BY `character_arena_stats`.`guid` DESC;

-- TABLE: character_aura
ALTER TABLE `character_aura` ADD INDEX `idx_caster` (`caster_guid`);
UPDATE `character_aura` SET `character_aura`.`guid` = `character_aura`.`guid` + @START_GUID_CHARS ORDER BY `character_aura`.`guid` DESC;
UPDATE `character_aura` SET `character_aura`.`caster_guid` = `character_aura`.`caster_guid` + @START_GUID_CHARS WHERE `character_aura`.`caster_guid` != 0 AND `character_aura`.`caster_guid` IN (SELECT `guid` FROM `characters`) ORDER BY `character_aura`.`caster_guid` DESC;
ALTER TABLE `character_aura` DROP INDEX `idx_caster`;

-- TABLE: character_banned
UPDATE `character_banned` SET `character_banned`.`guid` = `character_banned`.`guid` + @START_GUID_CHARS ORDER BY `character_banned`.`guid` DESC;

-- TABLE: character_battleground_data
UPDATE `character_battleground_data` SET `character_battleground_data`.`guid` = `character_battleground_data`.`guid` + @START_GUID_CHARS ORDER BY `character_battleground_data`.`guid` DESC;

-- TABLE: character_battleground_random
UPDATE `character_battleground_random` SET `character_battleground_random`.`guid` = `character_battleground_random`.`guid` + @START_GUID_CHARS ORDER BY `character_battleground_random`.`guid` DESC;

-- TABLE: character_equipmentsets
UPDATE `character_equipmentsets` SET `character_equipmentsets`.`guid` = `character_equipmentsets`.`guid` + @START_GUID_CHARS ORDER BY `character_equipmentsets`.`guid` DESC;

-- TABLE: character_gifts
UPDATE `character_gifts` SET `character_gifts`.`guid` = `character_gifts`.`guid` + @START_GUID_CHARS ORDER BY `character_gifts`.`guid` DESC;

-- TABLE: character_glyphs
UPDATE `character_glyphs` SET `character_glyphs`.`guid` = `character_glyphs`.`guid` + @START_GUID_CHARS ORDER BY `character_glyphs`.`guid` DESC;

-- TABLE: character_homebind
UPDATE `character_homebind` SET `character_homebind`.`guid` = `character_homebind`.`guid` + @START_GUID_CHARS ORDER BY `character_homebind`.`guid` DESC;

-- TABLE: character_instance
UPDATE `character_instance` SET `character_instance`.`guid` = `character_instance`.`guid` + @START_GUID_CHARS ORDER BY `character_instance`.`guid` DESC;

-- TABLE: character_inventory
UPDATE `character_inventory` SET `character_inventory`.`guid` = `character_inventory`.`guid` + @START_GUID_CHARS ORDER BY `character_inventory`.`guid` DESC;

-- TABLE: character_pet
UPDATE `character_pet` SET `character_pet`.`owner` = `character_pet`.`owner` + @START_GUID_CHARS ORDER BY `character_pet`.`owner` DESC;

-- TABLE: character_queststatus
UPDATE `character_queststatus` SET `character_queststatus`.`guid` = `character_queststatus`.`guid` + @START_GUID_CHARS ORDER BY `character_queststatus`.`guid` DESC;

-- TABLE: character_queststatus_daily
UPDATE `character_queststatus_daily` SET `character_queststatus_daily`.`guid` = `character_queststatus_daily`.`guid` + @START_GUID_CHARS ORDER BY `character_queststatus_daily`.`guid` DESC;

-- TABLE: character_queststatus_rewarded
UPDATE `character_queststatus_rewarded` SET `character_queststatus_rewarded`.`guid` = `character_queststatus_rewarded`.`guid` + @START_GUID_CHARS ORDER BY `character_queststatus_rewarded`.`guid` DESC;

-- TABLE: character_queststatus_seasonal
UPDATE `character_queststatus_seasonal` SET `character_queststatus_seasonal`.`guid` = `character_queststatus_seasonal`.`guid` + @START_GUID_CHARS ORDER BY `character_queststatus_seasonal`.`guid` DESC;

-- TABLE: character_queststatus_weekly
UPDATE `character_queststatus_weekly` SET `character_queststatus_weekly`.`guid` = `character_queststatus_weekly`.`guid` + @START_GUID_CHARS ORDER BY `character_queststatus_weekly`.`guid` DESC;

-- TABLE: character_reputation
UPDATE `character_reputation` SET `character_reputation`.`guid` = `character_reputation`.`guid` + @START_GUID_CHARS ORDER BY `character_reputation`.`guid` DESC;

-- TABLE: character_skills
UPDATE `character_skills` SET `character_skills`.`guid` = `character_skills`.`guid` + @START_GUID_CHARS ORDER BY `character_skills`.`guid` DESC;

-- TABLE: character_social
UPDATE `character_social` SET `character_social`.`guid` = `character_social`.`guid` + @START_GUID_CHARS ORDER BY `character_social`.`guid` DESC;
UPDATE `character_social` SET `character_social`.`friend` = `character_social`.`friend` + @START_GUID_CHARS ORDER BY `character_social`.`friend` DESC;

-- TABLE: character_spell
UPDATE `character_spell` SET `character_spell`.`guid` = `character_spell`.`guid` + @START_GUID_CHARS ORDER BY `character_spell`.`guid` DESC;

-- TABLE: character_spell_cooldown
UPDATE `character_spell_cooldown` SET `character_spell_cooldown`.`guid` = `character_spell_cooldown`.`guid` + @START_GUID_CHARS ORDER BY `character_spell_cooldown`.`guid` DESC;

-- TABLE: character_stats
UPDATE `character_stats` SET `character_stats`.`guid` = `character_stats`.`guid` + @START_GUID_CHARS ORDER BY `character_stats`.`guid` DESC;

-- TABLE: character_talent
UPDATE `character_talent` SET `character_talent`.`guid` = `character_talent`.`guid` + @START_GUID_CHARS ORDER BY `character_talent`.`guid` DESC;

-- TABLE: characters
UPDATE `characters` SET `characters`.`guid` = `characters`.`guid` + @START_GUID_CHARS ORDER BY `characters`.`guid` DESC;

-- TABLE: gm_tickets
UPDATE `gm_tickets` SET `gm_tickets`.`guid` = `gm_tickets`.`guid` + @START_GUID_CHARS ORDER BY `gm_tickets`.`guid` DESC;
UPDATE `gm_tickets` SET `gm_tickets`.`closedBy` = `gm_tickets`.`closedBy` + @START_GUID_CHARS WHERE `gm_tickets`.`closedBy` != 0 ORDER BY `gm_tickets`.`closedBy` DESC;
UPDATE `gm_tickets` SET `gm_tickets`.`assignedTo` = `gm_tickets`.`assignedTo` + @START_GUID_CHARS WHERE `gm_tickets`.`assignedTo` != 0 ORDER BY `gm_tickets`.`assignedTo` DESC;

-- TABLE: group_member
UPDATE `group_member` SET `group_member`.`memberGuid` = `group_member`.`memberGuid` + @START_GUID_CHARS ORDER BY `group_member`.`memberGuid` DESC;

-- TABLE: groups
UPDATE `groups` SET `groups`.`leaderGuid` = `groups`.`leaderGuid` + @START_GUID_CHARS ORDER BY `groups`.`leaderGuid` DESC;
UPDATE `groups` SET `groups`.`looterGuid` = `groups`.`looterGuid` + @START_GUID_CHARS ORDER BY `groups`.`looterGuid` DESC;

-- TABLE: guild
UPDATE `guild` SET `guild`.`leaderguid` = `guild`.`leaderguid` + @START_GUID_CHARS ORDER BY `guild`.`leaderguid` DESC;

-- TABLE: guild_bank_eventlog
UPDATE `guild_bank_eventlog` SET `guild_bank_eventlog`.`PlayerGuid` = `guild_bank_eventlog`.`PlayerGuid` + @START_GUID_CHARS ORDER BY `guild_bank_eventlog`.`PlayerGuid` DESC;

-- TABLE: guild_eventlog
UPDATE `guild_eventlog` SET `guild_eventlog`.`PlayerGuid1` = `guild_eventlog`.`PlayerGuid1` + @START_GUID_CHARS ORDER BY `guild_eventlog`.`PlayerGuid1` DESC;
UPDATE `guild_eventlog` SET `guild_eventlog`.`PlayerGuid2` = `guild_eventlog`.`PlayerGuid2` + @START_GUID_CHARS WHERE `guild_eventlog`.`PlayerGuid2` != 0 ORDER BY `guild_eventlog`.`PlayerGuid2` DESC;

-- TABLE: guild_member
UPDATE `guild_member` SET `guild_member`.`guid` = `guild_member`.`guid` + @START_GUID_CHARS ORDER BY `guild_member`.`guid` DESC;

-- TABLE: item_instance
-- Add some keys for better performance
ALTER TABLE `item_instance` ADD INDEX `idx_creator` (`creatorGuid`);
ALTER TABLE `item_instance` ADD INDEX `idx_gift` (`giftCreatorGuid`);
UPDATE `item_instance` SET `item_instance`.`owner_guid` = `item_instance`.`owner_guid` + @START_GUID_CHARS ORDER BY `item_instance`.`owner_guid` DESC;
UPDATE `item_instance` SET `item_instance`.`creatorGuid` = `item_instance`.`creatorGuid` + @START_GUID_CHARS WHERE `item_instance`.`creatorGuid` != 0 ORDER BY `item_instance`.`creatorGuid` DESC;
UPDATE `item_instance` SET `item_instance`.`giftCreatorGuid` = `item_instance`.`giftCreatorGuid` + @START_GUID_CHARS WHERE `item_instance`.`giftCreatorGuid` != 0 ORDER BY `item_instance`.`giftCreatorGuid` DESC;
ALTER TABLE `item_instance` DROP INDEX `idx_gift`;
ALTER TABLE `item_instance` DROP INDEX `idx_creator`;

-- TABLE: item_refund_instance
UPDATE `item_refund_instance` SET `item_refund_instance`.`player_guid` = `item_refund_instance`.`player_guid` + @START_GUID_CHARS ORDER BY `item_refund_instance`.`player_guid` DESC;

-- TABLE: mail
-- Add some keys for better performance
ALTER TABLE `mail` ADD INDEX `idx_sender` (`sender`);
UPDATE `mail` SET `mail`.`sender` = `mail`.`sender` + @START_GUID_CHARS WHERE `mail`.`messageType` = 0 AND `mail`.`stationery` = 41 ORDER BY `mail`.`sender` DESC;
UPDATE `mail` SET `mail`.`receiver` = `mail`.`receiver` + @START_GUID_CHARS ORDER BY `mail`.`receiver` DESC;
ALTER TABLE `mail` DROP INDEX `idx_sender`;

-- TABLE: mail_items
UPDATE `mail_items` SET `mail_items`.`receiver` = `mail_items`.`receiver` + @START_GUID_CHARS ORDER BY `mail_items`.`receiver` DESC;

-- TABLE: petition
UPDATE `petition` SET `petition`.`ownerguid` = `petition`.`ownerguid` + @START_GUID_CHARS ORDER BY `petition`.`ownerguid` DESC;

-- TABLE: petition_sign
UPDATE `petition_sign` SET `petition_sign`.`ownerguid` = `petition_sign`.`ownerguid` + @START_GUID_CHARS ORDER BY `petition_sign`.`ownerguid` DESC;
UPDATE `petition_sign` SET `petition_sign`.`playerguid` = `petition_sign`.`playerguid` + @START_GUID_CHARS ORDER BY `petition_sign`.`playerguid` DESC;



-- ====== BEGIN PROCESSING - ITEM GUID ======

-- TABLE: auctionhouse
UPDATE `auctionhouse` SET `auctionhouse`.`itemguid` = `auctionhouse`.`itemguid` + @START_GUID_ITEMS ORDER BY `auctionhouse`.`itemguid` DESC;

-- TABLE: character_aura
ALTER TABLE `character_aura` ADD INDEX `idx_item` (`item_guid`);
UPDATE `character_aura` SET `character_aura`.`item_guid` = `character_aura`.`item_guid` + @START_GUID_ITEMS WHERE `character_aura`.`item_guid` != 0 ORDER BY `character_aura`.`item_guid` DESC;
ALTER TABLE `character_aura` DROP INDEX `idx_item`;

-- TABLE: character_gifts
UPDATE `character_gifts` SET `character_gifts`.`item_guid` = `character_gifts`.`item_guid` + @START_GUID_ITEMS ORDER BY `character_gifts`.`item_guid` DESC;

-- TABLE: character_inventory
-- Add some keys for better performance
ALTER TABLE `character_inventory` ADD INDEX `idx_bag` (`bag`);
UPDATE `character_inventory` SET `character_inventory`.`item` = `character_inventory`.`item` + @START_GUID_ITEMS ORDER BY `character_inventory`.`item` DESC;
UPDATE `character_inventory` SET `character_inventory`.`bag` = `character_inventory`.`bag` + @START_GUID_ITEMS WHERE `character_inventory`.`bag` != 0 ORDER BY `character_inventory`.`bag` DESC;
ALTER TABLE `character_inventory` DROP INDEX `idx_bag`;

-- TABLE: guild_bank_item
UPDATE `guild_bank_item` SET `guild_bank_item`.`item_guid` = `guild_bank_item`.`item_guid` + @START_GUID_ITEMS ORDER BY `guild_bank_item`.`item_guid` DESC;

-- TABLE: item_instance
UPDATE `item_instance` SET `item_instance`.`guid` = `item_instance`.`guid` + @START_GUID_ITEMS ORDER BY `item_instance`.`guid` DESC;

-- TABLE: item_refund_instance
UPDATE `item_refund_instance` SET `item_refund_instance`.`item_guid` = `item_refund_instance`.`item_guid` + @START_GUID_ITEMS ORDER BY `item_refund_instance`.`item_guid` DESC;

-- TABLE: mail_items
UPDATE `mail_items` SET `mail_items`.`item_guid` = `mail_items`.`item_guid` + @START_GUID_ITEMS ORDER BY `mail_items`.`item_guid` DESC;

-- TABLE: petition
UPDATE `petition` SET `petition`.`petitionguid` = `petition`.`petitionguid` + @START_GUID_ITEMS ORDER BY `petition`.`petitionguid` DESC;

-- TABLE: petition_sign
UPDATE `petition_sign` SET `petition_sign`.`petitionguid` = `petition_sign`.`petitionguid` + @START_GUID_ITEMS ORDER BY `petition_sign`.`petitionguid` DESC;



-- ====== BEGIN PROCESSING - GROUP GUID ======

-- TABLE: group_instance
UPDATE `group_instance` SET `group_instance`.`guid` = `group_instance`.`guid` + @START_GUID_GROUP ORDER BY `group_instance`.`guid` DESC;

-- TABLE: group_member
UPDATE `group_member` SET `group_member`.`guid` = `group_member`.`guid` + @START_GUID_GROUP ORDER BY `group_member`.`guid` DESC;

-- TABLE: groups
UPDATE `groups` SET `groups`.`guid` = `groups`.`guid` + @START_GUID_GROUP ORDER BY `groups`.`guid` DESC;



-- ====== BEGIN PROCESSING - PET GUID ======

-- TABLE: character_pet
UPDATE `character_pet` SET `character_pet`.`id` = `character_pet`.`id` + @START_GUID_PETS ORDER BY `character_pet`.`id` DESC;

-- TABLE: pet_aura
UPDATE `pet_aura` SET `pet_aura`.`guid` = `pet_aura`.`guid` + @START_GUID_PETS ORDER BY `pet_aura`.`guid` DESC;

-- TABLE: pet_spell
UPDATE `pet_spell` SET `pet_spell`.`guid` = `pet_spell`.`guid` + @START_GUID_PETS ORDER BY `pet_spell`.`guid` DESC;

-- TABLE: pet_spell_cooldown
UPDATE `pet_spell_cooldown` SET `pet_spell_cooldown`.`guid` = `pet_spell_cooldown`.`guid` + @START_GUID_PETS ORDER BY `pet_spell_cooldown`.`guid` DESC;



-- ====== BEGIN PROCESSING - MAIL GUID ======

-- TABLE: mail
UPDATE `mail` SET `mail`.`id` = `mail`.`id` + @START_GUID_MAILS ORDER BY `mail`.`id` DESC;

-- TABLE: mail_items
UPDATE `mail_items` SET `mail_items`.`mail_id` = `mail_items`.`mail_id` + @START_GUID_MAILS ORDER BY `mail_items`.`mail_id` DESC;



-- ====== BEGIN PROCESSING - EQUIP GUID ======

-- TABLE: character_equipmentsets
UPDATE `character_equipmentsets` SET `character_equipmentsets`.`setguid` = `character_equipmentsets`.`setguid` + @START_GUID_EQUIP ORDER BY `character_equipmentsets`.`setguid` DESC;


-- ====== BEGIN PROCESSING - AUTO_INCREMENT VALUES ======

-- TABLE: character_equipmentsets
SELECT MAX(`setguid`)+1 FROM `character_equipmentsets` INTO @VAR;
SET @s = CONCAT('ALTER TABLE `character_equipmentsets` AUTO_INCREMENT = ', @VAR);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;



-- ====== CUSTOM - CHAR GUID ======

-- TABLE: armory_character_stats (CUSTOM - ARMORY)
/*
UPDATE `armory_character_stats` SET `armory_character_stats`.`guid` = `armory_character_stats`.`guid` + @START_GUID_CHARS, `armory_character_stats`.`data` = CONCAT(`armory_character_stats`.`guid` + @START_GUID_CHARS, SUBSTRING(`armory_character_stats`.`data`, LOCATE(' ', `armory_character_stats`.`data`))) ORDER BY `armory_character_stats`.`guid` DESC;
*/

-- TABLE: armory_game_chart (CUSTOM - ARMORY)
/*
UPDATE `armory_game_chart` SET `armory_game_chart`.`guid` = `armory_game_chart`.`guid` + @START_GUID_CHARS ORDER BY `armory_game_chart`.`guid` DESC;
*/

-- TABLE: castle_log (CUSTOM - LOG)
-- Add some keys for better performance
/*
ALTER TABLE `castle_log` ADD INDEX `idx_guid` (`player_guid`);
UPDATE `castle_log` SET `castle_log`.`player_guid` = `castle_log`.`player_guid` + @START_GUID_CHARS ORDER BY `castle_log`.`player_guid` DESC;
ALTER TABLE `castle_log` DROP INDEX `idx_guid`;
*/

-- TABLE: character_feed_log (CUSTOM - ARMORY)
-- Add some keys for better performance
/*
ALTER TABLE `character_feed_log` ADD INDEX `idx_guid` (`guid`);
UPDATE `character_feed_log` SET `character_feed_log`.`guid` = `character_feed_log`.`guid` + @START_GUID_CHARS ORDER BY `character_feed_log`.`guid` DESC;
ALTER TABLE `character_feed_log` DROP INDEX `idx_guid`;
*/

-- TABLE: world.irc_inchan (CUSTOM - TRINICHAT AUTOINVITE)
/*
UPDATE `world`.`irc_inchan` SET `world`.`irc_inchan`.`irc_inchan`.`guid` = `world`.`irc_inchan`.`irc_inchan`.`guid` + @START_GUID_CHARS ORDER BY `world`.`irc_inchan`.`irc_inchan`.`guid` DESC;
*/



-- ====== CUSTOM - ITEM GUID ======

-- TABLE: castle_log (CUSTOM - LOG)
-- Add some keys for better performance
/*
ALTER TABLE `castle_log` ADD INDEX `idx_data` (`data2`);
UPDATE `castle_log` SET `castle_log`.`data2` = `castle_log`.`data2` + @START_GUID_ITEMS WHERE `castle_log`.`type` = 2 ORDER BY `castle_log`.`data2` DESC;
ALTER TABLE `castle_log` DROP INDEX `idx_data`;
*/

-- TABLE: character_feed_log (CUSTOM - ARMORY)
-- Add some keys for better performance
/*
ALTER TABLE `character_feed_log` ADD INDEX `idx_item` (`item_guid`);
UPDATE `character_feed_log` SET `character_feed_log`.`item_guid` = `character_feed_log`.`item_guid` + @START_GUID_ITEMS ORDER BY `character_feed_log`.`item_guid` DESC;
ALTER TABLE `character_feed_log` DROP INDEX `idx_item`;
*/



-- ====== CUSTOM - MISC ======

-- TABLE: cheaters (CUSTOM - ANTI-CHEAT BACKLOG) (Only works because there are nearly no gaps in entry column)
/*
SELECT MIN(`entry`) FROM `cheaters` INTO @CHEATERS_MIN;
UPDATE `cheaters` SET `entry` = `entry` - (@CHEATERS_MIN - 1) ORDER BY `entry` ASC;
SELECT MAX(`entry`)+1 FROM `cheaters` INTO @CHEATERS_MAX;
SET @CHEATERS_MAX = IFNULL(@CHEATERS_MAX, 1);
SET @s = CONCAT('ALTER TABLE `cheaters` AUTO_INCREMENT = ', @CHEATERS_MAX);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;
*/