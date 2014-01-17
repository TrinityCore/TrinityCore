ALTER TABLE `conditions` ADD COLUMN `ConditionTarget` tinyint(3) UNSIGNED NOT NULL default '0' AFTER `ConditionTypeOrReference`;
