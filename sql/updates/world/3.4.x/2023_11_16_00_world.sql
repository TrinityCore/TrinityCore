ALTER TABLE `quest_template`   
	ADD COLUMN `QuestLevel` INT DEFAULT 0 NOT NULL AFTER `QuestType`,
	ADD COLUMN `QuestScalingFactionGroup` INT DEFAULT 0 NOT NULL AFTER `QuestLevel`,
	ADD COLUMN `QuestMaxScalingLevel` INT DEFAULT 0 NOT NULL AFTER `QuestScalingFactionGroup`,
	CHANGE `ContentTuningID` `QuestMinLevel` INT UNSIGNED DEFAULT 0 NOT NULL;
