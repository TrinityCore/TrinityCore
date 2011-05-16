ALTER TABLE `game_event_condition_save`
CHANGE `event_id` `event_id` SMALLINT(5) UNSIGNED NOT NULL,
CHANGE `condition_id` `condition_id` INT(10) UNSIGNED DEFAULT '0' NOT NULL;