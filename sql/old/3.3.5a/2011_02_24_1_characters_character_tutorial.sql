RENAME TABLE `character_tutorial` TO `account_tutorial`;
ALTER TABLE `account_tutorial` CHANGE COLUMN `account` `accountId` int(10) unsigned NOT NULL DEFAULT '0' COMMENT 'Account Identifier';
