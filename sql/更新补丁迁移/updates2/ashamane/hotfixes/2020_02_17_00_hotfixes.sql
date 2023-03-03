ALTER TABLE `chr_races` ADD `TransmogrifyDisabledSlotMask` int(11) NOT NULL DEFAULT '0' AFTER `HelmVisFallbackRaceID`;

ALTER TABLE `content_tuning_x_expected` ADD `MythicPlusSeasonID` int(11) NOT NULL DEFAULT '0' AFTER `ExpectedStatModID`;

ALTER TABLE `criteria_tree` MODIFY `Flags` int(11) NOT NULL DEFAULT '0' AFTER `OrderIndex`;

ALTER TABLE `currency_types`
  ADD `ConvertToPlayerExperience` int(11) NOT NULL DEFAULT '0' AFTER `ItemGroupSoundsID`,
  ADD `PlayerConditionID` int(11) NOT NULL DEFAULT '0' AFTER `ConvertToPlayerExperience`;

-- ALTER TABLE `item_appearance` DROP IF EXISTS `SubclassID`;

ALTER TABLE `mount`
  ADD `MountSpecialRiderAnimKitID` int(11) NOT NULL DEFAULT '0' AFTER `UiModelSceneID`,
  ADD `MountSpecialSpellVisualKitID` int(11) NOT NULL DEFAULT '0' AFTER `MountSpecialRiderAnimKitID`;

ALTER TABLE `spell_visual_kit` CHANGE `Flags` `Flags1` int(11) NOT NULL DEFAULT '0' AFTER `DelayMax`;
ALTER TABLE `spell_visual_kit` ADD `Flags2` int(11) NOT NULL DEFAULT '0' AFTER `Flags1`;
ALTER TABLE `spell_visual_kit` MODIFY `FallbackSpellVisualKitId` int(11) NOT NULL DEFAULT '0' AFTER `FallbackPriority`;

ALTER TABLE `ui_map` ADD `AlternateUiMapGroup` int(11) NOT NULL DEFAULT '0' AFTER `BkgAtlasID`;
