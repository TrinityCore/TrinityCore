ALTER TABLE `azerite_power_set_member` MODIFY `Tier` tinyint(4) NOT NULL DEFAULT 0 AFTER `Class`;

ALTER TABLE `chr_customization_choice` ADD `AddedInPatch` int(11) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `chr_customization_option` ADD `AddedInPatch` int(11) NOT NULL DEFAULT 0 AFTER `UiOrderIndex`;

ALTER TABLE `cinematic_camera` ADD `Unknown915` int(11) NOT NULL DEFAULT 0 AFTER `FileDataID`;

ALTER TABLE `friendship_rep_reaction` ADD `OverrideColor` int(11) NOT NULL DEFAULT 0 AFTER `ReactionThreshold`;

ALTER TABLE `garr_ability` MODIFY `GarrFollowerTypeID` tinyint(4) NOT NULL DEFAULT 0 AFTER `GarrAbilityCategoryID`;
ALTER TABLE `garr_ability` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `FactionChangeGarrAbilityID`;

ALTER TABLE `garr_building` MODIFY `BuildingType` tinyint(4) NOT NULL DEFAULT 0 AFTER `GarrTypeID`;
ALTER TABLE `garr_building` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `GoldCost`;

ALTER TABLE `garr_class_spec` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `FollowerClassLimit`;

ALTER TABLE `garr_follower` MODIFY `GarrFollowerTypeID` tinyint(4) NOT NULL DEFAULT 0 AFTER `GarrTypeID`;
ALTER TABLE `garr_follower` MODIFY `Quality` tinyint(4) NOT NULL DEFAULT 0 AFTER `AllianceGarrClassSpecID`;
ALTER TABLE `garr_follower` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ChrClassID`;

ALTER TABLE `garr_follower` MODIFY `GarrFollowerTypeID` tinyint(4) NOT NULL DEFAULT 0 AFTER `GarrTypeID`;
ALTER TABLE `garr_mission` MODIFY `Flags` int(11) NOT NULL DEFAULT 0 AFTER `AreaID`;

ALTER TABLE `heirloom`
  ADD `UpgradeItemID5` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeItemID4`,
  ADD `UpgradeItemID6` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeItemID5`,
  ADD `UpgradeItemBonusListID5` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `UpgradeItemBonusListID4`,
  ADD `UpgradeItemBonusListID6` smallint(5) unsigned NOT NULL DEFAULT 0 AFTER `UpgradeItemBonusListID5`;

ALTER TABLE `item` ADD `ContentTuningID` int(11) NOT NULL DEFAULT 0 AFTER `ItemGroupSoundsID`;

ALTER TABLE `item_appearance` MODIFY `DisplayType` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_modified_appearance` MODIFY `ItemAppearanceModifierID` int(11) NOT NULL DEFAULT 0 AFTER `ItemID`;
ALTER TABLE `item_modified_appearance` MODIFY `ItemAppearanceID` int(11) NOT NULL DEFAULT 0 AFTER `ItemAppearanceModifierID`;
ALTER TABLE `item_modified_appearance` MODIFY `OrderIndex` int(11) NOT NULL DEFAULT 0 AFTER `ItemAppearanceID`;
ALTER TABLE `item_modified_appearance` MODIFY `TransmogSourceTypeEnum` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `item_sparse` MODIFY `InventoryType` tinyint(4) NOT NULL DEFAULT 0 AFTER `RequiredLevel`;
ALTER TABLE `item_sparse` MODIFY `OverallQualityID` tinyint(4) NOT NULL DEFAULT 0 AFTER `InventoryType`;

ALTER TABLE `keystone_affix` MODIFY `ID` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Description`;

ALTER TABLE `map_challenge_mode` ADD `RequiredWorldStateID` int(11) NOT NULL DEFAULT 0 AFTER `ExpansionLevel`;

ALTER TABLE `quest_info` MODIFY `Modifiers` int(11) NOT NULL DEFAULT 0 AFTER `Type`;

ALTER TABLE `quest_line_x_quest` ADD `Flags` int(11) NOT NULL DEFAULT 0 AFTER `OrderIndex`;

ALTER TABLE `scene_script` ADD `Unknown915` int(11) NOT NULL DEFAULT 0 AFTER `NextSceneScriptID`;

ALTER TABLE `scene_script_package` ADD `Unknown915` int(11) NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `spell_effect` MODIFY `Effect` int(10) unsigned NOT NULL DEFAULT 0 AFTER `EffectIndex`;

ALTER TABLE `ui_map` MODIFY `System` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Flags`;
ALTER TABLE `ui_map` MODIFY `Type` int(10) unsigned NOT NULL DEFAULT 0 AFTER `System`;

ALTER TABLE `world_effect` MODIFY `TargetType` tinyint(3) unsigned NOT NULL DEFAULT 0 AFTER `WhenToDisplay`;

ALTER TABLE `hotfix_data` ADD `UniqueId` int(10) unsigned NOT NULL DEFAULT 0 AFTER `Id`;
