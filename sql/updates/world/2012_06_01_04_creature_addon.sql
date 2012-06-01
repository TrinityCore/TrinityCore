ALTER TABLE `creature_addon` ADD COLUMN `movement_flags` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `bytes2`;
ALTER TABLE `creature_template_addon` ADD COLUMN `movement_flags` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `bytes2`;

ALTER TABLE `creature_addon` ADD COLUMN `extra_movement_flags` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `movement_flags`;
ALTER TABLE `creature_template_addon` ADD COLUMN `extra_movement_flags` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `movement_flags`;
