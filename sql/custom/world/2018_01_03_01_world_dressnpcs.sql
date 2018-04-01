ALTER TABLE `creature_template_outfits`
	ADD COLUMN `head_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `head`,
	ADD COLUMN `shoulders_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `shoulders`,
	ADD COLUMN `body_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `body`,
	ADD COLUMN `chest_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `chest`,
	ADD COLUMN `waist_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `waist`,
	ADD COLUMN `legs_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `legs`,
	ADD COLUMN `feet_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `feet`,
	ADD COLUMN `wrists_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `wrists`,
	ADD COLUMN `hands_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `hands`,
	ADD COLUMN `back_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `back`,
	ADD COLUMN `tabard_appearance` INT UNSIGNED NOT NULL DEFAULT '0' AFTER `tabard`;
