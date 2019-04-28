ALTER TABLE `creature_template_outfits`
	ADD COLUMN `class` TINYINT(3) UNSIGNED NOT NULL DEFAULT '1' AFTER `race`;
