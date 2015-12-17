-- Prepare account_muted structure
ALTER TABLE `account_muted` CHANGE `guid` `accountid` INT(10) UNSIGNED DEFAULT 0 NOT NULL COMMENT 'Global Unique Identifier';
ALTER TABLE `account_muted` ADD COLUMN `active` TINYINT(3) UNSIGNED DEFAULT 1 NOT NULL AFTER `mutereason`;

-- Insert all mutes to new structure
INSERT INTO `account_muted` SELECT `id`, '0', `mutetime`, `muteby`, `mutereason`, '1' FROM `account`;

-- Drop unneeded columns
ALTER TABLE `account` DROP COLUMN `mutetime`, DROP COLUMN `mutereason`, DROP COLUMN `muteby`;
