ALTER TABLE `game_event_save`
CHANGE `event_id` `event_id` SMALLINT(5) UNSIGNED NOT NULL,
CHANGE `next_start` `next_start` INT(10) UNSIGNED DEFAULT '0' NOT NULL;