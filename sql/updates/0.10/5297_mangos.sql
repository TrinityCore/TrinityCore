ALTER TABLE `game_event`
    CHANGE COLUMN `start` `start_time` timestamp NOT NULL default '0000-00-00 00:00:00' COMMENT 'Absolute start date, the event will never start before',
    CHANGE COLUMN `end` `end_time` timestamp NOT NULL default '0000-00-00 00:00:00' COMMENT 'Absolute end date, the event will never start afler';

ALTER TABLE `pet_levelstats`
    CHANGE COLUMN `int` `inte` smallint(5) unsigned NOT NULL;

ALTER TABLE `player_levelstats`
    CHANGE COLUMN `int` `inte` smallint(5) unsigned NOT NULL;

ALTER TABLE `npc_option`
    CHANGE COLUMN `option` `option_text`  text;