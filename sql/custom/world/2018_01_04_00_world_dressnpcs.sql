ALTER TABLE `creature_template_outfits`
	ADD COLUMN `npcsoundsid` INT(10) UNSIGNED NOT NULL DEFAULT '0' COMMENT 'entry from NPCSounds.dbc/db2' AFTER `entry`;
