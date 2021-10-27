-- 
ALTER TABLE `creature_addon` ADD COLUMN `noNPCDamageBelowHealthPct` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `auras`;
ALTER TABLE `creature_template_addon` ADD COLUMN `noNPCDamageBelowHealthPct` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `auras`;
