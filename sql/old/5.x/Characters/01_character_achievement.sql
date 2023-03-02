ALTER TABLE `character_achievement` DROP COLUMN `accountID`;
ALTER TABLE `character_achievement` ADD COLUMN `accountID` INT(10) NOT NULL DEFAULT 0 AFTER `achievement`;

UPDATE `character_achievement` SET `accountID` = (SELECT `account` FROM `characters` WHERE characters.guid = character_achievement.guid LIMIT 1);
UPDATE `character_achievement` SET `accountID` = (SELECT `deleteInfos_account` FROM `characters` WHERE characters.guid = character_achievement.guid LIMIT 1) WHERE `accountID` = 0 OR `accountID` IS NULL;
