ALTER TABLE `creature_addon`
	ADD COLUMN `visibilityDistanceType` TINYINT UNSIGNED NOT NULL AFTER `meleeAnimKit`;

ALTER TABLE `creature_template_addon`
	ADD COLUMN `visibilityDistanceType` TINYINT UNSIGNED NOT NULL AFTER `meleeAnimKit`;
