ALTER TABLE `quest_template`   
	DROP COLUMN `ContentTuningID`, 
	ADD COLUMN `QuestLevel` INT DEFAULT 0 NOT NULL AFTER `QuestType`,
	ADD COLUMN `QuestScalingFactionGroup` INT DEFAULT 0 NOT NULL AFTER `QuestLevel`,
	ADD COLUMN `QuestMaxScalingLevel` INT DEFAULT 0 NOT NULL AFTER `QuestScalingFactionGroup`,
	ADD COLUMN `MinLevel` INT DEFAULT 0 NOT NULL AFTER `QuestPackageID`;
