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

