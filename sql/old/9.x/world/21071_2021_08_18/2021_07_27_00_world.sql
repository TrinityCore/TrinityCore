ALTER TABLE `creature_template` ADD `CreatureDifficultyID` int(11) NOT NULL DEFAULT '0' AFTER `movementId`;
ALTER TABLE `creature_template_scaling` DROP `LevelScalingMin`, DROP `LevelScalingMax`;
ALTER TABLE `points_of_interest` ADD `PositionZ` float NOT NULL DEFAULT '0' AFTER `PositionY`;
ALTER TABLE `quest_template` ADD `PortraitGiverModelSceneID` int(11) NOT NULL DEFAULT '0' AFTER `PortraitGiverMount`;

DELETE FROM `creature_template_scaling` WHERE `ContentTuningID`=0;
