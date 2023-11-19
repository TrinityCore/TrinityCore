ALTER TABLE `characters_10x`.`characters`   
	DROP COLUMN `activeTalentGroup`, 
	CHANGE `primarySpecialization` `activeTalentGroup` TINYINT UNSIGNED DEFAULT 0 NOT NULL,
	ADD COLUMN `bonusTalentGroups` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `activeTalentGroup`;
