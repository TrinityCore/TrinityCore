ALTER TABLE `adventure_journal` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `chr_classes` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `LowResScreenFileDataID`;

ALTER TABLE `chr_model` MODIFY `Sex` tinyint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `curve_point` CHANGE `PosPreSquishX` `PreSLSquishPosX` float NOT NULL DEFAULT 0 AFTER `PosY`;
ALTER TABLE `curve_point` CHANGE `PosPreSquishY` `PreSLSquishPosY` float NOT NULL DEFAULT 0 AFTER `PreSLSquishPosX`;

ALTER TABLE `item_bonus_tree_node` CHANGE `ItemBonusListGroupID` `ChildItemBonusListGroupID` int NOT NULL DEFAULT 0 AFTER `ChildItemLevelSelectorID`;
ALTER TABLE `item_bonus_tree_node` CHANGE `ParentItemBonusTreeNodeID` `IblGroupPointsModSetID` int NOT NULL DEFAULT 0 AFTER `ChildItemBonusListGroupID`;

ALTER TABLE `item_sparse` MODIFY `StartQuestID` int NOT NULL DEFAULT 0 AFTER `BagFamily`;
ALTER TABLE `item_sparse` MODIFY `LanguageID` int NOT NULL DEFAULT 0 AFTER `StartQuestID`;
ALTER TABLE `item_sparse` MODIFY `ItemRange` float NOT NULL DEFAULT 0 AFTER `LanguageID`;

ALTER TABLE `journal_encounter` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `MapDisplayConditionID`;

ALTER TABLE `journal_encounter_section` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `IconFileDataID`;
ALTER TABLE `journal_encounter_section` MODIFY `IconFlags` int NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `journal_instance` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `lfg_dungeons` MODIFY `Subtype` tinyint NOT NULL DEFAULT 0 AFTER `TypeID`;

ALTER TABLE `map` ADD `Flags3` int NOT NULL DEFAULT 0 AFTER `Flags2`;

ALTER TABLE `summon_properties` CHANGE `Flags` `Flags1` int NOT NULL DEFAULT 0 AFTER `Slot`;
ALTER TABLE `summon_properties` ADD `Flags2` int NOT NULL DEFAULT 0 AFTER `Flags1`;
