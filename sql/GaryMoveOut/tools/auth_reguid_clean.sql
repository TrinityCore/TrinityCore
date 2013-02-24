-- Variables, which define guid to start with
SET @START_ID_ACCS := 1; -- or use MAX(column)+1


-- ====== STEP 1: Cleanup ======
-- Execute in auth-database
-- REPLACE: `characters` with your characters database name
-- REPLACE: `voteshop` with your voteshop database name

-- CHARACTERS SECTION
DELETE FROM `characters`.`characters` WHERE `account` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_data` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_instance_times` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `characters`.`account_tutorial` WHERE `accountId` NOT IN (SELECT `id` FROM `account`);

-- AUTH SECTION
DELETE FROM `account_access` WHERE `id` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `account_access` WHERE `RealmID` != -1 AND `RealmID` NOT IN (SELECT `id` FROM `realmlist`);

DELETE FROM `account_banned` WHERE `id` NOT IN (SELECT `id` FROM `account`);

DELETE FROM `realmcharacters` WHERE `acctid` NOT IN (SELECT `id` FROM `account`);
DELETE FROM `realmcharacters` WHERE `realmid` NOT IN (SELECT `id` FROM `realmlist`);

-- CUSTOM - ACCOUNT SAVING
-- DELETE FROM `account_preserved` WHERE `account` NOT IN (SELECT `id` FROM `account`);

-- CUSTOM - VOTESHOP
-- DELETE FROM `voteshop`.`voting` WHERE `voteshop`.`voting`.`id` NOT IN (SELECT `id` FROM `account`);





-- ====== STEP 2: Reguid ======
-- ====== CREATE TEMP TABLE - ACCS IDS ======
DROP TABLE IF EXISTS `tmp_id_table`;
CREATE TABLE `tmp_id_table` (
	`id_new` INT(10) unsigned NOT NULL AUTO_INCREMENT PRIMARY KEY,
	`id` INT(10) unsigned NOT NULL
) ENGINE=INNODB DEFAULT CHARSET=utf8;

SET @s = CONCAT('ALTER TABLE `tmp_id_table` AUTO_INCREMENT = ', @START_ID_ACCS);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;

INSERT INTO `tmp_id_table` (`id`) SELECT `id` FROM `account` ORDER BY `id`;



-- ====== BEGIN PROCESSING - ACCS IDS ======


-- TABLE: account
-- Add some keys to improve performance
ALTER TABLE `account` ADD INDEX `idx_recruiter` (`recruiter`);
UPDATE `account` JOIN `tmp_id_table` ON `account`.`id` = `tmp_id_table`.`id` SET `account`.`id` = `tmp_id_table`.`id_new`;
UPDATE `account` JOIN `tmp_id_table` ON `account`.`recruiter` = `tmp_id_table`.`id` SET `account`.`recruiter` = `tmp_id_table`.`id_new`;
ALTER TABLE `account` DROP INDEX `idx_recruiter`;

-- TABLE: account_access
UPDATE `account_access` JOIN `tmp_id_table` ON `account_access`.`id` = `tmp_id_table`.`id` SET `account_access`.`id` = `tmp_id_table`.`id_new`;

-- TABLE: account_banned
UPDATE `account_banned` JOIN `tmp_id_table` ON `account_banned`.`id` = `tmp_id_table`.`id` SET `account_banned`.`id` = `tmp_id_table`.`id_new`;

-- TABLE: realmcharacters
UPDATE `realmcharacters` JOIN `tmp_id_table` ON `realmcharacters`.`acctid` = `tmp_id_table`.`id` SET `realmcharacters`.`acctid` = `tmp_id_table`.`id_new`;

-- TABLE: `characters`.account_data
UPDATE `characters`.`account_data` JOIN `tmp_id_table` ON `characters`.`account_data`.`accountId` = `tmp_id_table`.`id` SET `characters`.`account_data`.`accountId` = `tmp_id_table`.`id_new`;

-- TABLE: `characters`.account_instance_times
UPDATE `characters`.`account_instance_times` JOIN `tmp_id_table` ON `characters`.`account_instance_times`.`accountId` = `tmp_id_table`.`id` SET `characters`.`account_instance_times`.`accountId` = `tmp_id_table`.`id_new`;

-- TABLE: `characters`.account_tutorial
UPDATE `characters`.`account_tutorial` JOIN `tmp_id_table` ON `characters`.`account_tutorial`.`accountId` = `tmp_id_table`.`id` SET `characters`.`account_tutorial`.`accountId` = `tmp_id_table`.`id_new`;

-- TABLE: `characters`.characters
-- Add some keys to improve performance
ALTER TABLE `characters`.`characters` ADD INDEX `idx_delAcc` (`deleteInfos_account`);
UPDATE `characters`.`characters` JOIN `tmp_id_table` ON `characters`.`characters`.`account` = `tmp_id_table`.`id` SET `characters`.`characters`.`account` = `tmp_id_table`.`id_new`;
UPDATE `characters`.`characters` JOIN `tmp_id_table` ON `characters`.`characters`.`deleteInfos_account` = `tmp_id_table`.`id` SET `characters`.`characters`.`deleteInfos_account` = `tmp_id_table`.`id_new`;
ALTER TABLE `characters`.`characters` DROP INDEX `idx_delAcc`;

-- TABLE: `characters`.petition_sign
ALTER TABLE `characters`.`petition_sign` ADD INDEX `idx_acc` (`player_account`);
UPDATE `characters`.`petition_sign` JOIN `tmp_id_table` ON `characters`.`petition_sign`.`player_account` = `tmp_id_table`.`id` SET `characters`.`petition_sign`.`player_account` = `tmp_id_table`.`id_new`;
ALTER TABLE `characters`.`petition_sign` DROP INDEX `idx_acc`;



-- ====== BEGIN PROCESSING - AUTO_INCREMENT VALUES ======

-- TABLE: account
SELECT MAX(`id`)+1 FROM `account` INTO @VAR;
SET @s = CONCAT('ALTER TABLE `account` AUTO_INCREMENT = ', @VAR);
PREPARE stmt FROM @s;
EXECUTE stmt;
DEALLOCATE PREPARE stmt;



-- ====== CUSTOM - ACCS IDS ======

-- TABLE: account_preserved (CUSTOM - ACCOUNT SAVING)
/*
UPDATE `account_preserved` JOIN `tmp_id_table` ON `account_preserved`.`account` = `tmp_id_table`.`id` SET `account_preserved`.`account` = `tmp_id_table`.`id_new`;
*/

-- TABLE: `characters`.cheaters (CUSTOM - ANTI-CHEAT BACKLOG)
/*
ALTER TABLE `characters`.`cheaters` ADD INDEX `idx_acc` (`acctid`);
UPDATE `characters`.`cheaters` JOIN `tmp_id_table` ON `characters`.`cheaters`.`acctid` = `tmp_id_table`.`id` SET `characters`.`cheaters`.`acctid` = `tmp_id_table`.`id_new`;
ALTER TABLE `characters`.`cheaters` DROP INDEX `idx_acc`;
*/

-- TABLE: `voteshop`.voting (CUSTOM - VOTESHOP)
/*
UPDATE `voteshop`.`voting` JOIN `tmp_id_table` ON `voteshop`.`voting`.`id` = `tmp_id_table`.`id` SET `voteshop`.`voting`.`id` = `tmp_id_table`.`id_new`;
*/



-- ====== CLEANUP ======
DROP TABLE IF EXISTS `tmp_id_table`;