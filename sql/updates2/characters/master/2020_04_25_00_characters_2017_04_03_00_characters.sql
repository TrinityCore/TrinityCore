ALTER TABLE `character_arena_stats`
CHANGE `guid` `guid` BIGINT(20) unsigned NOT NULL DEFAULT '0',
CHANGE `slot` `slot` TINYINT(3) unsigned NOT NULL DEFAULT '0',
CHANGE `matchMakerRating` `matchMakerRating` SMALLINT(5) unsigned NOT NULL DEFAULT 0;

ALTER TABLE `character_equipmentsets`
CHANGE `guid` `guid` BIGINT(20) unsigned NOT NULL DEFAULT '0',
CHANGE `setguid` `setguid` BIGINT(20) unsigned NOT NULL AUTO_INCREMENT;

ALTER TABLE `item_loot_money`
CHANGE `container_id` `container_id` BIGINT(20) unsigned NOT NULL DEFAULT '0' COMMENT 'guid of container (item_instance.guid)';
