ALTER TABLE `character_battleground_data` ADD `queueId` BIGINT UNSIGNED NULL DEFAULT '0' AFTER `mountSpell`;

ALTER TABLE `pvpstats_battlegrounds` CHANGE `type` `type` int unsigned NOT NULL;
