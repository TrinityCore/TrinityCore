ALTER TABLE `creature_addon` ADD COLUMN `mountInhabitType` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `mount`;
ALTER TABLE `creature_template_addon` ADD COLUMN `mountInhabitType` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `mount`;
