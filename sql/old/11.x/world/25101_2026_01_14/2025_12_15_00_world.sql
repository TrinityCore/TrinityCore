ALTER TABLE `gameobject_template` ADD `RequiredLevel` int NOT NULL DEFAULT 0 AFTER `ContentTuningId`;

ALTER TABLE `quest_objectives`
  ADD `SecondaryAmount` int NOT NULL DEFAULT 0 AFTER `Amount`,
  ADD `ParentObjectiveID` int NOT NULL DEFAULT 0 AFTER `ProgressBarWeight`,
  ADD `Visible` tinyint(1) unsigned NOT NULL DEFAULT 1 AFTER `ParentObjectiveID`;

DROP TABLE IF EXISTS `quest_reward_house_room`;
CREATE TABLE `quest_reward_house_room` (
  `QuestID` int unsigned NOT NULL,
  `OrderIndex` int NOT NULL,
  `HouseRoomID` int NOT NULL,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestID`,`OrderIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

DROP TABLE IF EXISTS `quest_reward_house_decor`;
CREATE TABLE `quest_reward_house_decor` (
  `QuestID` int unsigned NOT NULL,
  `OrderIndex` int NOT NULL,
  `HouseDecorID` int NOT NULL,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestID`,`OrderIndex`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
