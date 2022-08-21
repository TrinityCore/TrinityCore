ALTER TABLE `creature_template_addon` ADD `PlayHoverAnim` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `meleeAnimKit`;
ALTER TABLE `creature_addon` ADD `PlayHoverAnim` TINYINT UNSIGNED NOT NULL DEFAULT '0' AFTER `meleeAnimKit`;
