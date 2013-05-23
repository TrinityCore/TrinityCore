-- Variables, which define guid to start with
SELECT MAX(`id`)+1 FROM `auth2`.`account` INTO @START_ID_ACCS;


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



-- ====== BEGIN PROCESSING - ACCS IDS ======


-- TABLE: account
-- Add some keys to improve performance
ALTER TABLE `account` ADD INDEX `idx_recruiter` (`recruiter`);
UPDATE `account` SET `account`.`id` = `account`.`id` + @START_ID_ACCS ORDER BY `account`.`id` DESC;
UPDATE `account` SET `account`.`recruiter` = `account`.`recruiter` + @START_ID_ACCS WHERE `account`.`recruiter` != 0 ORDER BY `account`.`recruiter` DESC;
ALTER TABLE `account` DROP INDEX `idx_recruiter`;

-- TABLE: account_access
UPDATE `account_access` SET `account_access`.`id` = `account_access`.`id` + @START_ID_ACCS ORDER BY `account_access`.`id` DESC;

-- TABLE: account_banned
UPDATE `account_banned` SET `account_banned`.`id` = `account_banned`.`id` + @START_ID_ACCS ORDER BY `account_banned`.`id` DESC;

-- TABLE: realmcharacters
UPDATE `realmcharacters` SET `realmcharacters`.`acctid` = `realmcharacters`.`acctid` + @START_ID_ACCS ORDER BY `realmcharacters`.`acctid` DESC;

-- TABLE: `characters`.account_data
UPDATE `characters`.`account_data` SET `characters`.`account_data`.`accountId` = `characters`.`account_data`.`accountId` + @START_ID_ACCS ORDER BY `characters`.`account_data`.`accountId` DESC;

-- TABLE: `characters`.account_instance_times
UPDATE `characters`.`account_instance_times` SET `characters`.`account_instance_times`.`accountId` = `characters`.`account_instance_times`.`accountId` + @START_ID_ACCS ORDER BY `characters`.`account_instance_times`.`accountId` DESC;

-- TABLE: `characters`.account_tutorial
UPDATE `characters`.`account_tutorial` SET `characters`.`account_tutorial`.`accountId` = `characters`.`account_tutorial`.`accountId` + @START_ID_ACCS ORDER BY `characters`.`account_tutorial`.`accountId` DESC;

-- TABLE: `characters`.characters
-- Add some keys to improve performance
ALTER TABLE `characters`.`characters` ADD INDEX `idx_delAcc` (`deleteInfos_account`);
UPDATE `characters`.`characters` SET `characters`.`characters`.`account` = `characters`.`characters`.`account` + @START_ID_ACCS ORDER BY `characters`.`characters`.`account` DESC;
UPDATE `characters`.`characters` SET `characters`.`characters`.`deleteInfos_account` = `characters`.`characters`.`deleteInfos_account` + @START_ID_ACCS WHERE (`characters`.`characters`.`deleteInfos_account` != 0 AND `characters`.`characters`.`deleteInfos_account` IS NOT NULL) ORDER BY `characters`.`characters`.`deleteInfos_account` DESC;
ALTER TABLE `characters`.`characters` DROP INDEX `idx_delAcc`;

-- TABLE: `characters`.petition_sign
ALTER TABLE `characters`.`petition_sign` ADD INDEX `idx_acc` (`player_account`);
UPDATE `characters`.`petition_sign` SET `characters`.`petition_sign`.`player_account` = `characters`.`petition_sign`.`player_account` + @START_ID_ACCS ORDER BY `characters`.`petition_sign`.`player_account` DESC;
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
UPDATE `account_preserved` SET `account_preserved`.`account` = `account_preserved`.`account` + @START_ID_ACCS ORDER BY `account_preserved`.`account` DESC;
*/

-- TABLE: `characters`.cheaters (CUSTOM - ANTI-CHEAT BACKLOG)
/*
ALTER TABLE `characters`.`cheaters` ADD INDEX `idx_acc` (`acctid`);
UPDATE `characters`.`cheaters` SET `characters`.`cheaters`.`acctid` = `characters`.`cheaters`.`acctid` + @START_ID_ACCS ORDER BY `characters`.`cheaters`.`acctid` DESC;
ALTER TABLE `characters`.`cheaters` DROP INDEX `idx_acc`;
*/

-- TABLE: `voteshop`.voting (CUSTOM - VOTESHOP)
/*
UPDATE `voteshop`.`voting` SET `voteshop`.`voting`.`id` = `voteshop`.`voting`.`id` + @START_ID_ACCS ORDER BY `voteshop`.`voting`.`id` DESC;
*/