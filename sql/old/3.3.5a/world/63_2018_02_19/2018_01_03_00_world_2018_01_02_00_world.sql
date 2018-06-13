SET @sql_mode = @@session.sql_mode;
SET SESSION sql_mode = '';

ALTER TABLE `game_event`
  CHANGE `start_time` `start_time` TIMESTAMP NULL COMMENT 'Absolute start date, the event will never start before',
  CHANGE `end_time` `end_time` TIMESTAMP NULL COMMENT 'Absolute end date, the event will never start after';

UPDATE `game_event` SET `start_time`=NULL WHERE `start_time`='0000-00-00 00:00:00';
UPDATE `game_event` SET `end_time`=NULL WHERE `end_time`='0000-00-00 00:00:00';

SET SESSION sql_mode = @@sql_mode;
