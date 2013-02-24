-- Based on https://raw.github.com/TGM/characters_optimization/master/1.%20characters%20optimization.sql
-- Thanks to original authors!

-- Variables, which define guid to start with
SET @START_GUID_CHARS := 1; -- or use MAX(column)+1
SET @START_GUID_ITEMS := 1; -- or use MAX(column)+1
SET @START_GUID_GROUP := 1; -- or use MAX(column)+1
SET @START_GUID_PETS  := 1; -- or use MAX(column)+1
SET @START_GUID_MAILS := 1; -- or use MAX(column)+1
SET @START_GUID_EQUIP := 1; -- or use MAX(column)+1


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





-- ====== STEP 2: Reguid ======
-- ====== CREATE TEMP TABLE - CHAR GUIDS ======
DROP TABLE IF EXISTS `tmp_guid_table`;
CREATE TABLE `tmp_guid_table` (
	`guid_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`guid` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_guid_table` AUTO_INCREMENT = ', @START_GUID_CHARS);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_guid_table` (`guid`) SELECT `guid` FROM `characters` ORDER BY `guid` ASC;

-- ====== CREATE TEMP TABLE - GROUP GUIDS ======
DROP TABLE IF EXISTS `tmp_groups_table`;
CREATE TABLE `tmp_groups_table` (
	`guid_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`guid` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_groups_table` AUTO_INCREMENT = ', @START_GUID_GROUP);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_groups_table` (`guid`) SELECT `guid` FROM `groups` ORDER BY `guid` ASC;

-- ====== CREATE TEMP TABLE - ITEM GUIDS ======
DROP TABLE IF EXISTS `tmp_item_instance_table`;
CREATE TABLE `tmp_item_instance_table` (
	`guid_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`guid` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_item_instance_table` AUTO_INCREMENT = ', @START_GUID_ITEMS);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_item_instance_table` (`guid`) SELECT `guid` FROM `item_instance` ORDER BY `guid` ASC;

-- ====== CREATE TEMP TABLE - PET GUIDS ======
DROP TABLE IF EXISTS `tmp_character_pet_table`;
CREATE TABLE `tmp_character_pet_table` (
	`id_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`id` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_character_pet_table` AUTO_INCREMENT = ', @START_GUID_PETS);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_character_pet_table` (`id`) SELECT `id` FROM `character_pet` ORDER BY `id` ASC;

-- ====== CREATE TEMP TABLE - MAIL GUIDS ======
DROP TABLE IF EXISTS `tmp_mail_table`;
CREATE TABLE `tmp_mail_table` (
	`id_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`id` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_mail_table` AUTO_INCREMENT = ', @START_GUID_MAILS);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_mail_table` (`id`) SELECT `id` FROM `mail` ORDER BY `id` ASC;

-- ====== CREATE TEMP TABLE - EQUIP GUIDS ======
DROP TABLE IF EXISTS `tmp_character_equipmentsets_table`;
CREATE TABLE `tmp_character_equipmentsets_table` (
  `setguid_new` bigint(20) NOT NULL AUTO_INCREMENT PRIMARY KEY,
  `setguid` bigint(20) NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_character_equipmentsets_table` AUTO_INCREMENT = ', @START_GUID_EQUIP);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_character_equipmentsets_table` (`setguid`) SELECT `setguid` FROM `character_equipmentsets` ORDER BY `setguid` ASC;


-- ====== BEGIN PROCESSING - CHAR GUID ======

-- TABLE: arena_team
UPDATE `arena_team` JOIN `tmp_guid_table` ON `arena_team`.`captainGuid` = `tmp_guid_table`.`guid` SET `arena_team`.`captainGuid` = `tmp_guid_table`.`guid_new`;

-- TABLE: arena_team_member
UPDATE `arena_team_member` JOIN `tmp_guid_table` ON `arena_team_member`.`guid` = `tmp_guid_table`.`guid` SET `arena_team_member`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: auctionhouse
UPDATE `auctionhouse` JOIN `tmp_guid_table` ON `auctionhouse`.`buyguid` = `tmp_guid_table`.`guid` SET `auctionhouse`.`buyguid` = `tmp_guid_table`.`guid_new`;
UPDATE `auctionhouse` JOIN `tmp_guid_table` ON `auctionhouse`.`itemowner` = `tmp_guid_table`.`guid` SET `auctionhouse`.`itemowner` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_account_data
UPDATE `character_account_data` JOIN `tmp_guid_table` ON `character_account_data`.`guid` = `tmp_guid_table`.`guid` SET `character_account_data`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_achievement
UPDATE `character_achievement` JOIN `tmp_guid_table` ON `character_achievement`.`guid` = `tmp_guid_table`.`guid` SET `character_achievement`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_achievement_progress
UPDATE `character_achievement_progress` JOIN `tmp_guid_table` ON `character_achievement_progress`.`guid` = `tmp_guid_table`.`guid` SET `character_achievement_progress`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_action
UPDATE `character_action` JOIN `tmp_guid_table` ON `character_action`.`guid` = `tmp_guid_table`.`guid` SET `character_action`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_arena_stats
UPDATE `character_arena_stats` JOIN `tmp_guid_table` ON `character_arena_stats`.`guid` = `tmp_guid_table`.`guid` SET `character_arena_stats`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_aura
UPDATE `character_aura` JOIN `tmp_guid_table` ON `character_aura`.`guid` = `tmp_guid_table`.`guid` SET `character_aura`.`guid` = `tmp_guid_table`.`guid_new`;
UPDATE `character_aura` JOIN `tmp_guid_table` ON `character_aura`.`caster_guid` = `tmp_guid_table`.`guid` SET `character_aura`.`caster_guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_banned
UPDATE `character_banned` JOIN `tmp_guid_table` ON `character_banned`.`guid` = `tmp_guid_table`.`guid` SET `character_banned`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_battleground_data
UPDATE `character_battleground_data` JOIN `tmp_guid_table` ON `character_battleground_data`.`guid` = `tmp_guid_table`.`guid` SET `character_battleground_data`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_battleground_random
UPDATE `character_battleground_random` JOIN `tmp_guid_table` ON `character_battleground_random`.`guid` = `tmp_guid_table`.`guid` SET `character_battleground_random`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_equipmentsets
UPDATE `character_equipmentsets` JOIN `tmp_guid_table` ON `character_equipmentsets`.`guid` = `tmp_guid_table`.`guid` SET `character_equipmentsets`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_gifts
UPDATE `character_gifts` JOIN `tmp_guid_table` ON `character_gifts`.`guid` = `tmp_guid_table`.`guid` SET `character_gifts`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_glyphs
UPDATE `character_glyphs` JOIN `tmp_guid_table` ON `character_glyphs`.`guid` = `tmp_guid_table`.`guid` SET `character_glyphs`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_homebind
UPDATE `character_homebind` JOIN `tmp_guid_table` ON `character_homebind`.`guid` = `tmp_guid_table`.`guid` SET `character_homebind`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_instance
UPDATE `character_instance` JOIN `tmp_guid_table` ON `character_instance`.`guid` = `tmp_guid_table`.`guid` SET `character_instance`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_inventory
UPDATE `character_inventory` JOIN `tmp_guid_table` ON `character_inventory`.`guid` = `tmp_guid_table`.`guid` SET `character_inventory`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_pet
UPDATE `character_pet` JOIN `tmp_guid_table` ON `character_pet`.`owner` = `tmp_guid_table`.`guid` SET `character_pet`.`owner` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_queststatus
UPDATE `character_queststatus` JOIN `tmp_guid_table` ON `character_queststatus`.`guid` = `tmp_guid_table`.`guid` SET `character_queststatus`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_queststatus_daily
UPDATE `character_queststatus_daily` JOIN `tmp_guid_table` ON `character_queststatus_daily`.`guid` = `tmp_guid_table`.`guid` SET `character_queststatus_daily`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_queststatus_rewarded
UPDATE `character_queststatus_rewarded` JOIN `tmp_guid_table` ON `character_queststatus_rewarded`.`guid` = `tmp_guid_table`.`guid` SET `character_queststatus_rewarded`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_queststatus_seasonal
UPDATE `character_queststatus_seasonal` JOIN `tmp_guid_table` ON `character_queststatus_seasonal`.`guid` = `tmp_guid_table`.`guid` SET `character_queststatus_seasonal`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_queststatus_weekly
UPDATE `character_queststatus_weekly` JOIN `tmp_guid_table` ON `character_queststatus_weekly`.`guid` = `tmp_guid_table`.`guid` SET `character_queststatus_weekly`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_reputation
UPDATE `character_reputation` JOIN `tmp_guid_table` ON `character_reputation`.`guid` = `tmp_guid_table`.`guid` SET `character_reputation`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_skills
UPDATE `character_skills` JOIN `tmp_guid_table` ON `character_skills`.`guid` = `tmp_guid_table`.`guid` SET `character_skills`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_social
UPDATE `character_social` JOIN `tmp_guid_table` ON `character_social`.`guid` = `tmp_guid_table`.`guid` SET `character_social`.`guid` = `tmp_guid_table`.`guid_new`;
UPDATE `character_social` JOIN `tmp_guid_table` ON `character_social`.`friend` = `tmp_guid_table`.`guid` SET `character_social`.`friend` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_spell
UPDATE `character_spell` JOIN `tmp_guid_table` ON `character_spell`.`guid` = `tmp_guid_table`.`guid` SET `character_spell`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_spell_cooldown
UPDATE `character_spell_cooldown` JOIN `tmp_guid_table` ON `character_spell_cooldown`.`guid` = `tmp_guid_table`.`guid` SET `character_spell_cooldown`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_stats
UPDATE `character_stats` JOIN `tmp_guid_table` ON `character_stats`.`guid` = `tmp_guid_table`.`guid` SET `character_stats`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: character_talent
UPDATE `character_talent` JOIN `tmp_guid_table` ON `character_talent`.`guid` = `tmp_guid_table`.`guid` SET `character_talent`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: characters
UPDATE `characters` JOIN `tmp_guid_table` ON `characters`.`guid` = `tmp_guid_table`.`guid` SET `characters`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: gm_tickets
UPDATE `gm_tickets` JOIN `tmp_guid_table` ON `gm_tickets`.`guid` = `tmp_guid_table`.`guid` SET `gm_tickets`.`guid` = `tmp_guid_table`.`guid_new`;
UPDATE `gm_tickets` JOIN `tmp_guid_table` ON `gm_tickets`.`closedBy` = `tmp_guid_table`.`guid` SET `gm_tickets`.`closedBy` = `tmp_guid_table`.`guid_new`;
UPDATE `gm_tickets` JOIN `tmp_guid_table` ON `gm_tickets`.`assignedTo` = `tmp_guid_table`.`guid` SET `gm_tickets`.`assignedTo` = `tmp_guid_table`.`guid_new`;

-- TABLE: group_member
UPDATE `group_member` JOIN `tmp_guid_table` ON `group_member`.`memberGuid` = `tmp_guid_table`.`guid` SET `group_member`.`memberGuid` = `tmp_guid_table`.`guid_new`;

-- TABLE: groups
UPDATE `groups` JOIN `tmp_guid_table` ON `groups`.`leaderGuid` = `tmp_guid_table`.`guid` SET `groups`.`leaderGuid` = `tmp_guid_table`.`guid_new`;
UPDATE `groups` JOIN `tmp_guid_table` ON `groups`.`looterGuid` = `tmp_guid_table`.`guid` SET `groups`.`looterGuid` = `tmp_guid_table`.`guid_new`;

-- TABLE: guild
UPDATE `guild` JOIN `tmp_guid_table` ON `guild`.`leaderguid` = `tmp_guid_table`.`guid` SET `guild`.`leaderguid` = `tmp_guid_table`.`guid_new`;

-- TABLE: guild_bank_eventlog
UPDATE `guild_bank_eventlog` JOIN `tmp_guid_table` ON `guild_bank_eventlog`.`PlayerGuid` = `tmp_guid_table`.`guid` SET `guild_bank_eventlog`.`PlayerGuid` = `tmp_guid_table`.`guid_new`;

-- TABLE: guild_eventlog
UPDATE `guild_eventlog` JOIN `tmp_guid_table` ON `guild_eventlog`.`PlayerGuid1` = `tmp_guid_table`.`guid` SET `guild_eventlog`.`PlayerGuid1` = `tmp_guid_table`.`guid_new`;
UPDATE `guild_eventlog` JOIN `tmp_guid_table` ON `guild_eventlog`.`PlayerGuid2` = `tmp_guid_table`.`guid` SET `guild_eventlog`.`PlayerGuid2` = `tmp_guid_table`.`guid_new`;

-- TABLE: guild_member
UPDATE `guild_member` JOIN `tmp_guid_table` ON `guild_member`.`guid` = `tmp_guid_table`.`guid` SET `guild_member`.`guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: item_instance
-- Add some keys for better performance
ALTER TABLE `item_instance` ADD INDEX `idx_creator` (`creatorGuid`);
ALTER TABLE `item_instance` ADD INDEX `idx_gift` (`giftCreatorGuid`);
UPDATE `item_instance` JOIN `tmp_guid_table` ON `item_instance`.`owner_guid` = `tmp_guid_table`.`guid` SET `item_instance`.`owner_guid` = `tmp_guid_table`.`guid_new`;
UPDATE `item_instance` JOIN `tmp_guid_table` ON `item_instance`.`creatorGuid` = `tmp_guid_table`.`guid` SET `item_instance`.`creatorGuid` = `tmp_guid_table`.`guid_new`;
UPDATE `item_instance` JOIN `tmp_guid_table` ON `item_instance`.`giftCreatorGuid` = `tmp_guid_table`.`guid` SET `item_instance`.`giftCreatorGuid` = `tmp_guid_table`.`guid_new`;
ALTER TABLE `item_instance` DROP INDEX `idx_gift`;
ALTER TABLE `item_instance` DROP INDEX `idx_creator`;

-- TABLE: item_refund_instance
UPDATE `item_refund_instance` JOIN `tmp_guid_table` ON `item_refund_instance`.`player_guid` = `tmp_guid_table`.`guid` SET `item_refund_instance`.`player_guid` = `tmp_guid_table`.`guid_new`;

-- TABLE: mail
-- Add some keys for better performance
ALTER TABLE `mail` ADD INDEX `idx_sender` (`sender`);
UPDATE `mail` JOIN `tmp_guid_table` ON `mail`.`sender` = `tmp_guid_table`.`guid` SET `mail`.`sender` = `tmp_guid_table`.`guid_new`;
UPDATE `mail` JOIN `tmp_guid_table` ON `mail`.`receiver` = `tmp_guid_table`.`guid` SET `mail`.`receiver` = `tmp_guid_table`.`guid_new`;
ALTER TABLE `mail` DROP INDEX `idx_sender`;

-- TABLE: mail_items
UPDATE `mail_items` JOIN `tmp_guid_table` ON `mail_items`.`receiver` = `tmp_guid_table`.`guid` SET `mail_items`.`receiver` = `tmp_guid_table`.`guid_new`;

-- TABLE: petition
UPDATE `petition` JOIN `tmp_guid_table` ON `petition`.`ownerguid` = `tmp_guid_table`.`guid` SET `petition`.`ownerguid` = `tmp_guid_table`.`guid_new`;

-- TABLE: petition_sign
UPDATE `petition_sign` JOIN `tmp_guid_table` ON `petition_sign`.`ownerguid` = `tmp_guid_table`.`guid` SET `petition_sign`.`ownerguid` = `tmp_guid_table`.`guid_new`;
UPDATE `petition_sign` JOIN `tmp_guid_table` ON `petition_sign`.`playerguid` = `tmp_guid_table`.`guid` SET `petition_sign`.`playerguid` = `tmp_guid_table`.`guid_new`;



-- ====== BEGIN PROCESSING - ITEM GUID ======

-- TABLE: auctionhouse
UPDATE `auctionhouse` JOIN `tmp_item_instance_table` ON `auctionhouse`.`itemguid` = `tmp_item_instance_table`.`guid` SET `auctionhouse`.`itemguid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: character_gifts
UPDATE `character_gifts` JOIN `tmp_item_instance_table` ON `character_gifts`.`item_guid` = `tmp_item_instance_table`.`guid` SET `character_gifts`.`item_guid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: character_inventory
-- Add some keys for better performance
ALTER TABLE `character_inventory` ADD INDEX `idx_bag` (`bag`);
UPDATE `character_inventory` JOIN `tmp_item_instance_table` ON `character_inventory`.`item` = `tmp_item_instance_table`.`guid` SET `character_inventory`.`item` = `tmp_item_instance_table`.`guid_new`;
UPDATE `character_inventory` JOIN `tmp_item_instance_table` ON `character_inventory`.`bag` = `tmp_item_instance_table`.`guid` SET `character_inventory`.`bag` = `tmp_item_instance_table`.`guid_new`;
ALTER TABLE `character_inventory` DROP INDEX `idx_bag`;

-- TABLE: item_instance
UPDATE `item_instance` JOIN `tmp_item_instance_table` ON `item_instance`.`guid` = `tmp_item_instance_table`.`guid` SET `item_instance`.`guid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: item_refund_instance
UPDATE `item_refund_instance` JOIN `tmp_item_instance_table` ON `item_refund_instance`.`item_guid` = `tmp_item_instance_table`.`guid` SET `item_refund_instance`.`item_guid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: mail_items
UPDATE `mail_items` JOIN `tmp_item_instance_table` ON `mail_items`.`item_guid` = `tmp_item_instance_table`.`guid` SET `mail_items`.`item_guid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: petition
UPDATE `petition`, `tmp_item_instance_table` SET `petition`.`petitionguid` = `tmp_item_instance_table`.`guid` WHERE `petition`.`petitionguid` = `tmp_item_instance_table`.`guid_new`;

-- TABLE: petition_sign
UPDATE `petition_sign`, `tmp_item_instance_table` SET `petition_sign`.`petitionguid` = `tmp_item_instance_table`.`guid` WHERE `petition_sign`.`petitionguid` = `tmp_item_instance_table`.`guid_new`;



-- ====== BEGIN PROCESSING - GROUP GUID ======

-- TABLE: group_instance
UPDATE `group_instance` JOIN `tmp_groups_table` ON `group_instance`.`guid` = `tmp_groups_table`.`guid` SET `group_instance`.`guid` = `tmp_groups_table`.`guid_new`;

-- TABLE: group_member
UPDATE `group_member` JOIN `tmp_groups_table` ON `group_member`.`guid` = `tmp_groups_table`.`guid` SET `group_member`.`guid` = `tmp_groups_table`.`guid_new`;

-- TABLE: groups
UPDATE `groups` JOIN `tmp_groups_table` ON `groups`.`guid` = `tmp_groups_table`.`guid` SET `groups`.`guid` = `tmp_groups_table`.`guid_new`;

-- TABLE: guild_bank_item
UPDATE `guild_bank_item` JOIN `tmp_item_instance_table` ON `guild_bank_item`.`item_guid` = `tmp_item_instance_table`.`guid` SET `guild_bank_item`.`item_guid` = `tmp_item_instance_table`.`guid_new`;



-- ====== BEGIN PROCESSING - PET GUID ======

-- TABLE: character_pet
UPDATE `character_pet` JOIN `tmp_character_pet_table` ON `character_pet`.`id` = `tmp_character_pet_table`.`id` SET `character_pet`.`id` = `tmp_character_pet_table`.`id_new`;

-- TABLE: pet_aura
UPDATE `pet_aura` JOIN `tmp_character_pet_table` ON `pet_aura`.`guid` = `tmp_character_pet_table`.`id` SET `pet_aura`.`guid` = `tmp_character_pet_table`.`id_new`;

-- TABLE: pet_spell
UPDATE `pet_spell` JOIN `tmp_character_pet_table` ON `pet_spell`.`guid` = `tmp_character_pet_table`.`id` SET `pet_spell`.`guid` = `tmp_character_pet_table`.`id_new`;

-- TABLE: pet_spell_cooldown
UPDATE `pet_spell_cooldown` JOIN `tmp_character_pet_table` ON `pet_spell_cooldown`.`guid` = `tmp_character_pet_table`.`id` SET `pet_spell_cooldown`.`guid` = `tmp_character_pet_table`.`id_new`;



-- ====== BEGIN PROCESSING - MAIL GUID ======

-- TABLE: mail
UPDATE `mail` JOIN `tmp_mail_table` ON `mail`.`id` = `tmp_mail_table`.`id` SET `mail`.`id` = `tmp_mail_table`.`id_new`;

-- TABLE: mail_items
UPDATE `mail_items` JOIN `tmp_mail_table` ON `mail_items`.`mail_id` = `tmp_mail_table`.`id` SET `mail_items`.`mail_id` = `tmp_mail_table`.`id_new`;



-- ====== BEGIN PROCESSING - EQUIP GUID ======

-- TABLE: character_equipmentsets
UPDATE `character_equipmentsets` JOIN `tmp_character_equipmentsets_table` ON `character_equipmentsets`.`setguid` = `tmp_character_equipmentsets_table`.`setguid` SET `character_equipmentsets`.`setguid` = `tmp_character_equipmentsets_table`.`setguid_new`;


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
UPDATE `armory_character_stats` JOIN `tmp_guid_table` ON `armory_character_stats`.`guid` = `tmp_guid_table`.`guid` SET `armory_character_stats`.`guid` = `tmp_guid_table`.`guid_new`, `armory_character_stats`.`data` = CONCAT(`tmp_guid_table`.`guid_new`, SUBSTRING(`armory_character_stats`.`data`, LOCATE(' ', `armory_character_stats`.`data`)));
*/

-- TABLE: armory_game_chart (CUSTOM - ARMORY)
/*
UPDATE `armory_game_chart` JOIN `tmp_guid_table` ON `armory_game_chart`.`guid` = `tmp_guid_table`.`guid` SET `armory_game_chart`.`guid` = `tmp_guid_table`.`guid_new`;
*/

-- TABLE: castle_log (CUSTOM - LOG)
-- Add some keys for better performance
/*
ALTER TABLE `castle_log` ADD INDEX `idx_guid` (`player_guid`);
UPDATE `castle_log` JOIN `tmp_guid_table` ON `castle_log`.`player_guid` = `tmp_guid_table`.`guid` SET `castle_log`.`player_guid` = `tmp_guid_table`.`guid_new`;
ALTER TABLE `castle_log` DROP INDEX `idx_guid`;
*/

-- TABLE: character_feed_log (CUSTOM - ARMORY)
-- Add some keys for better performance
/*
ALTER TABLE `character_feed_log` ADD INDEX `idx_guid` (`guid`);
UPDATE `character_feed_log` JOIN `tmp_guid_table` ON `character_feed_log`.`guid` = `tmp_guid_table`.`guid` SET `character_feed_log`.`guid` = `tmp_guid_table`.`guid_new`;
ALTER TABLE `character_feed_log` DROP INDEX `idx_guid`;
*/

-- TABLE: world.irc_inchan (CUSTOM - TRINICHAT AUTOINVITE)
/*
UPDATE `world`.`irc_inchan` JOIN `tmp_guid_table` ON `world`.`irc_inchan`.`guid` = `tmp_guid_table`.`guid` SET `world`.`irc_inchan`.`guid` = `tmp_guid_table`.`guid_new`;
*/



-- ====== CUSTOM - ITEM GUID ======

-- TABLE: castle_log (CUSTOM - LOG)
-- Add some keys for better performance
/*
ALTER TABLE `castle_log` ADD INDEX `idx_data` (`data2`);
UPDATE `castle_log` JOIN `tmp_item_instance_table` ON `castle_log`.`data2` = `tmp_item_instance_table`.`guid` SET `castle_log`.`data2` = `tmp_item_instance_table`.`guid_new` WHERE `castle_log`.`type` = 2;
ALTER TABLE `castle_log` DROP INDEX `idx_data`;
*/

-- TABLE: character_feed_log (CUSTOM - ARMORY)
-- Add some keys for better performance
/*
ALTER TABLE `character_feed_log` ADD INDEX `idx_item` (`item_guid`);
UPDATE `character_feed_log` JOIN `tmp_item_instance_table` ON `character_feed_log`.`item_guid` = `tmp_item_instance_table`.`guid` SET `character_feed_log`.`item_guid` = `tmp_item_instance_table`.`guid_new`;
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



-- ====== CLEANUP ======
DROP TABLE IF EXISTS `tmp_guid_table`;
DROP TABLE IF EXISTS `tmp_groups_table`;
DROP TABLE IF EXISTS `tmp_item_instance_table`;
DROP TABLE IF EXISTS `tmp_character_pet_table`;
DROP TABLE IF EXISTS `tmp_character_equipmentsets_table`;
DROP TABLE IF EXISTS `tmp_mail_table`;