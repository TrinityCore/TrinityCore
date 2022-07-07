ALTER TABLE `creature_template_outfits`
	ADD COLUMN `spellvisualkitid` INT(10) NOT NULL DEFAULT 0 AFTER `gender`,
	ADD COLUMN `customizations` TEXT NULL DEFAULT NULL AFTER `spellvisualkitid`,
	DROP COLUMN `skin`,
	DROP COLUMN `face`,
	DROP COLUMN `hair`,
	DROP COLUMN `haircolor`,
	DROP COLUMN `facialhair`,
	DROP COLUMN `feature1`,
	DROP COLUMN `feature2`,
	DROP COLUMN `feature3`;
