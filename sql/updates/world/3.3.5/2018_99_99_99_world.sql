ALTER TABLE `creature_addon`
	ADD COLUMN `visibilityDistanceType` TINYINT UNSIGNED NOT NULL AFTER `emote`;

ALTER TABLE `creature_template_addon`
	ADD COLUMN `visibilityDistanceType` TINYINT UNSIGNED NOT NULL AFTER `emote`;
