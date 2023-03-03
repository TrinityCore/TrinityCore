ALTER TABLE `character_queststatus` ADD `acceptTime` bigint(20) NOT NULL DEFAULT '0' AFTER `explored`;
ALTER TABLE `character_queststatus` CHANGE `timer` `endTime` bigint(20) NOT NULL DEFAULT '0' AFTER `acceptTime`;
