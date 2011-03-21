-- Update game_event_save
ALTER TABLE `game_event_save` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL;

-- Update game_event_condition_save
ALTER TABLE `game_event_condition_save` CHANGE `event_id` `eventEntry` TINYINT(3) UNSIGNED NOT NULL;
