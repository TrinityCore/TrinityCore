ALTER TABLE `quest_template`
ADD COLUMN `QuestLevel` SMALLINT NOT NULL DEFAULT '1' AFTER `QuestType`,
ADD COLUMN `ScalingFactionGroup` INT NOT NULL DEFAULT '0' AFTER `QuestLevel`,
ADD COLUMN `MaxScalingLevel` INT NOT NULL DEFAULT '0' AFTER `ScalingFactionGroup`,
ADD COLUMN `MinLevel` TINYINT NOT NULL DEFAULT 0 AFTER `QuestPackageID`,
DROP COLUMN `ContentTuningID`,
DROP COLUMN `ManagedWorldStateID`,
DROP COLUMN `QuestSessionBonus`;
