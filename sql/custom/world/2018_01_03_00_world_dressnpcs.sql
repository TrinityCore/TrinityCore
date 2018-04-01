ALTER TABLE `creature_template_outfits`
	ADD COLUMN `guildid` BIGINT(20) UNSIGNED NOT NULL DEFAULT '0' AFTER `tabard`;
