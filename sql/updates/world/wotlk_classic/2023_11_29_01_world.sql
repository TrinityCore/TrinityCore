ALTER TABLE `creature_template`   
	ADD COLUMN `Civilian` TINYINT UNSIGNED DEFAULT 0 NOT NULL AFTER `ExperienceModifier`;
