ALTER TABLE `character_queststatus` ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER guid;
ALTER TABLE `character_queststatus` ADD KEY `account` (`account`);
ALTER TABLE `character_queststatus_daily` ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER guid;
ALTER TABLE `character_queststatus_daily` ADD KEY `account` (`account`);
ALTER TABLE `character_queststatus_rewarded` ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER guid;
ALTER TABLE `character_queststatus_rewarded` ADD KEY `account` (`account`);
ALTER TABLE `character_queststatus_seasonal` ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER guid;
ALTER TABLE `character_queststatus_seasonal` ADD KEY `account` (`account`);
ALTER TABLE `character_queststatus_weekly` ADD `account` INT(11) DEFAULT '0' NOT NULL AFTER guid;
ALTER TABLE `character_queststatus_weekly` ADD KEY `account` (`account`);

UPDATE character_queststatus a JOIN characters b ON a.guid = b.guid AND b.account > 0 SET a.`account` = b.account;
UPDATE character_queststatus_daily a JOIN characters b ON a.guid = b.guid AND b.account > 0 SET a.`account` = b.account;
UPDATE character_queststatus_rewarded a JOIN characters b ON a.guid = b.guid AND b.account > 0 SET a.`account` = b.account;
UPDATE character_queststatus_seasonal a JOIN characters b ON a.guid = b.guid AND b.account > 0 SET a.`account` = b.account;
UPDATE character_queststatus_weekly a JOIN characters b ON a.guid = b.guid AND b.account > 0 SET a.`account` = b.account;

UPDATE character_queststatus a JOIN characters b ON a.guid = b.guid AND b.deleteInfos_Account > 0 AND b.account = 0 SET a.`account` = b.deleteInfos_Account;
UPDATE character_queststatus_daily a JOIN characters b ON a.guid = b.guid AND b.deleteInfos_Account > 0 AND b.account = 0 SET a.`account` = b.deleteInfos_Account;
UPDATE character_queststatus_rewarded a JOIN characters b ON a.guid = b.guid AND b.deleteInfos_Account > 0 AND b.account = 0 SET a.`account` = b.deleteInfos_Account;
UPDATE character_queststatus_seasonal a JOIN characters b ON a.guid = b.guid AND b.deleteInfos_Account > 0 AND b.account = 0 SET a.`account` = b.deleteInfos_Account;
UPDATE character_queststatus_weekly a JOIN characters b ON a.guid = b.guid AND b.deleteInfos_Account > 0 AND b.account = 0 SET a.`account` = b.deleteInfos_Account;
