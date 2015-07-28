ALTER TABLE `game_event`
ADD COLUMN `announce` tinyint(3) unsigned NULL DEFAULT 2 COMMENT '0 dont announce, 1 announce, 2 value from config' AFTER `world_event`;
