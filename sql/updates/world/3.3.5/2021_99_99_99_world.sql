--
ALTER TABLE `creature_template_movement` CHANGE `Ground` `Ground` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` CHANGE `Swim` `Swim` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` CHANGE `Flight` `Flight` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` CHANGE `Rooted` `Rooted` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` CHANGE `Chase` `Chase` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` CHANGE `Random` `Random` TINYINT(3) UNSIGNED DEFAULT NULL NULL;
ALTER TABLE `creature_template_movement` ADD COLUMN `InteractionPauseTimer` INT(10) UNSIGNED DEFAULT NULL NULL COMMENT 'Time (in milliseconds) during which creature will not move after interaction with player' AFTER `Random`;
