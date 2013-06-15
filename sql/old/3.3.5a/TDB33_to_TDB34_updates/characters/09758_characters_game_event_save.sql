ALTER TABLE `game_event_save` ADD `next_start_timestamp` BIGINT(11) UNSIGNED NOT NULL DEFAULT '0';
UPDATE `game_event_save` SET `next_start_timestamp` = UNIX_TIMESTAMP(`next_start`);
ALTER TABLE `game_event_save` DROP `next_start`;
ALTER TABLE `game_event_save` CHANGE `next_start_timestamp` `next_start` BIGINT(11) UNSIGNED NOT NULL DEFAULT '0';
