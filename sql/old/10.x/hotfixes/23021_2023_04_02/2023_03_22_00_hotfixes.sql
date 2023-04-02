ALTER TABLE `area_trigger` MODIFY `AreaTriggerActionSetID` int NOT NULL DEFAULT 0 AFTER `ShapeID`;

ALTER TABLE `currency_container` MODIFY `ContainerQuality` tinyint NOT NULL DEFAULT 0 AFTER `ContainerIconID`;

ALTER TABLE `difficulty` MODIFY `GroupSizeHealthCurveID` int unsigned NOT NULL DEFAULT 0 AFTER `ToggleDifficultyID`;
ALTER TABLE `difficulty` MODIFY `GroupSizeDmgCurveID` int unsigned NOT NULL DEFAULT 0 AFTER `GroupSizeHealthCurveID`;
ALTER TABLE `difficulty` MODIFY `GroupSizeSpellPointsCurveID` int unsigned NOT NULL DEFAULT 0 AFTER `GroupSizeDmgCurveID`;

ALTER TABLE `garr_building` MODIFY `GarrTypeID` tinyint NOT NULL DEFAULT 0 AFTER `Tooltip`;

ALTER TABLE `garr_follower` MODIFY `GarrTypeID` tinyint NOT NULL DEFAULT 0 AFTER `TitleName`;

ALTER TABLE `garr_mission` MODIFY `GarrTypeID` tinyint NOT NULL DEFAULT 0 AFTER `WorldPosY`;

ALTER TABLE `garr_talent_tree` MODIFY `GarrTypeID` tinyint NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `languages` MODIFY `ID` int unsigned NOT NULL DEFAULT 0 AFTER `Name`;
ALTER TABLE `languages` ADD `LearningCurveID` int NOT NULL DEFAULT 0 AFTER `UiTextureKitElementCount`;

ALTER TABLE `quest_info` MODIFY `Profession` smallint unsigned NOT NULL DEFAULT 0 AFTER `Modifiers`;

ALTER TABLE `trait_node_x_trait_cost` MODIFY `TraitNodeID` int NOT NULL DEFAULT 0 AFTER `ID`;
