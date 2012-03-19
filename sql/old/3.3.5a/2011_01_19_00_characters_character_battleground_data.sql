ALTER TABLE `character_battleground_data`
ROW_FORMAT=DEFAULT,
CHANGE `guid` `guid` INT(10) UNSIGNED DEFAULT '0' NOT NULL COMMENT 'Global Unique Identifier',
CHANGE `instance_id` `instance_id` INT(10) UNSIGNED NOT NULL, 
CHANGE `team` `team` SMALLINT(5) UNSIGNED NOT NULL,
CHANGE `join_map` `join_map` SMALLINT(5) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `taxi_start` `taxi_start` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `taxi_end` `taxi_end` INT(10) UNSIGNED DEFAULT '0' NOT NULL,
CHANGE `mount_spell` `mount_spell` MEDIUMINT(8) UNSIGNED DEFAULT '0' NOT NULL;