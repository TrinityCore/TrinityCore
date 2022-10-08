CREATE TABLE IF NOT EXISTS `account_battle_pet_slots` (
    `accountId` int(10) unsigned NOT NULL DEFAULT '0',
    `slot1` bigint(20) unsigned NOT NULL DEFAULT '0',
    `slot2` bigint(20) unsigned NOT NULL DEFAULT '0',
    `slot3` bigint(20) unsigned NOT NULL DEFAULT '0',
    `flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
PRIMARY KEY (`accountId`));
