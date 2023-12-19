ALTER TABLE `creature_template`   
	ADD COLUMN `PetSpellDataId` INT UNSIGNED DEFAULT 0 NOT NULL AFTER `type`;
