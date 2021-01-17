--
ALTER TABLE `creature_template_movement` ADD COLUMN `InteractionPauseTimer` INT(10) UNSIGNED DEFAULT 180000 NOT NULL COMMENT 'Time (in milliseconds) during which creature will not move after interaction with player' AFTER `Random`;
