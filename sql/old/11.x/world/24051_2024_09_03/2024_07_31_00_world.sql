ALTER TABLE `gossip_menu_addon` ADD `LfgDungeonsID` int NOT NULL DEFAULT '0' AFTER `FriendshipFactionID`;

DROP TABLE IF EXISTS `quest_treasure_pickers`;
CREATE TABLE `quest_treasure_pickers` (
  `QuestID` int unsigned NOT NULL,
  `TreasurePickerID` int NOT NULL,
  `OrderIndex` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`QuestID`,`TreasurePickerID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `quest_treasure_pickers` SELECT `ID`, `TreasurePickerID`, 0 FROM `quest_template` WHERE `TreasurePickerID` <> 0;

ALTER TABLE `quest_template`
  ADD `ResetByScheduler` tinyint NOT NULL DEFAULT '0' AFTER `QuestCompletionLog`,
  DROP `TreasurePickerID`;
