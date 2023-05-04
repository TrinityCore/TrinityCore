ALTER TABLE `chr_customization_choice` ADD `SoundKitID` int NOT NULL DEFAULT 0 AFTER `AddedInPatch`;

ALTER TABLE `chr_customization_element` ADD `AnimKitID` int NOT NULL DEFAULT 0 AFTER `ChrCustomizationVoiceID`;

ALTER TABLE `content_tuning` ADD `QuestXpMultiplier` float NOT NULL DEFAULT 0 AFTER `MinItemLevel`;

ALTER TABLE `curve_point` MODIFY `CurveID` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_bonus_tree_node` ADD `Unknown1010_1` int NOT NULL DEFAULT 0 AFTER `IblGroupPointsModSetID`;
ALTER TABLE `item_bonus_tree_node` ADD `Unknown1010_2` int NOT NULL DEFAULT 0 AFTER `Unknown1010_1`;

ALTER TABLE `movie` ADD `SubtitleFileFormat` int NOT NULL DEFAULT 0 AFTER `SubtitleFileDataID`;

ALTER TABLE `ui_map` MODIFY `System` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;
ALTER TABLE `ui_map` MODIFY `Type` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `System`;

ALTER TABLE `vehicle` MODIFY `FlagsB` int NOT NULL DEFAULT 0 AFTER `Flags`;
