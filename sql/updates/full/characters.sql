ALTER TABLE `arena_team_member` ADD COLUMN `points_to_add` int(10) UNSIGNED NOT NULL DEFAULT '0';
DROP TABLE IF EXISTS `saved_variables`;
CREATE TABLE `saved_variables` (                                                                             
    `NextArenaPointDistributionTime` timestamp NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8 ROW_FORMAT=FIXED COMMENT='Variable Saves';

CREATE TABLE `game_event_save` (
 `event_id` mediumint(8) unsigned NOT NULL,
 `state` tinyint(3) unsigned NOT NULL default '1',
 `next_start` timestamp NOT NULL default '0000-00-00 00:00:00',
 PRIMARY KEY  (`event_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

CREATE TABLE `game_event_condition_save` (                    
 `event_id` mediumint(8) unsigned NOT NULL,
 `condition_id` mediumint(8) unsigned NOT NULL default '0',
 `done` float default '0',
 PRIMARY KEY  (`event_id`,`condition_id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

ALTER TABLE `characters`
    ADD `latency` int(11) unsigned NOT NULL default '0' AFTER `taxi_path`;
	
ALTER TABLE `guild_bank_tab`
  CHANGE COLUMN `TabText` `TabText` text;

ALTER TABLE `character_aura` ADD `stackcount` INT NOT NULL DEFAULT '1' AFTER `effect_index` ;
ALTER TABLE `pet_aura` ADD `stackcount` INT NOT NULL DEFAULT '1' AFTER `effect_index` ;	

