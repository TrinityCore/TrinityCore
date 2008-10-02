ALTER TABLE `game_event` CHANGE `occurence` `occurence` bigint(20) unsigned NOT NULL default '5184000' COMMENT 'Delay in minutes between occurences of the event';
ALTER TABLE `game_event` CHANGE `length` `length` bigint(20) unsigned NOT NULL default '2592000' COMMENT 'Length in minutes of the event';
UPDATE `game_event` SET `occurence` = `occurence` * 60;
UPDATE `game_event` SET `length` = `length` * 60;