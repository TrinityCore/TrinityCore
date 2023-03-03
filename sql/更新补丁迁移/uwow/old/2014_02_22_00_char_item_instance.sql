ALTER TABLE `item_instance`
ADD `upgradeId` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL AFTER transmogrifyId;