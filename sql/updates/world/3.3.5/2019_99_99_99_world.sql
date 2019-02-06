ALTER TABLE `creature_template_addon`
	CHANGE COLUMN `visibilityDistanceType` `visibilityDistanceType` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `emote`;
