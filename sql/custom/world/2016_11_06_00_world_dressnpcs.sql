ALTER TABLE `creature_template_outfits`
	ADD COLUMN `feature1` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `facialhair`,
	ADD COLUMN `feature2` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `feature1`,
	ADD COLUMN `feature3` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `feature2`;

ALTER TABLE `creature_template_outfits`
	COMMENT='Use positive values for item entries and negative to use item displayid for head, shoulders etc.\r\nTo use special appearances either find the displayid for it or use ((AppearanceModID << 32) | item_entry). The appearance IDs are usually from 0 to 10.',
	CHANGE COLUMN `head` `head` BIGINT NOT NULL DEFAULT '0' AFTER `feature3`,
	CHANGE COLUMN `shoulders` `shoulders` BIGINT NOT NULL DEFAULT '0' AFTER `head`,
	CHANGE COLUMN `body` `body` BIGINT NOT NULL DEFAULT '0' AFTER `shoulders`,
	CHANGE COLUMN `chest` `chest` BIGINT NOT NULL DEFAULT '0' AFTER `body`,
	CHANGE COLUMN `waist` `waist` BIGINT NOT NULL DEFAULT '0' AFTER `chest`,
	CHANGE COLUMN `legs` `legs` BIGINT NOT NULL DEFAULT '0' AFTER `waist`,
	CHANGE COLUMN `feet` `feet` BIGINT NOT NULL DEFAULT '0' AFTER `legs`,
	CHANGE COLUMN `wrists` `wrists` BIGINT NOT NULL DEFAULT '0' AFTER `feet`,
	CHANGE COLUMN `hands` `hands` BIGINT NOT NULL DEFAULT '0' AFTER `wrists`,
	CHANGE COLUMN `back` `back` BIGINT NOT NULL DEFAULT '0' AFTER `hands`,
	CHANGE COLUMN `tabard` `tabard` BIGINT NOT NULL DEFAULT '0' AFTER `back`;
