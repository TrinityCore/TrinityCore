ALTER TABLE `achievement` ADD COLUMN `RewardItemID` int(11) NOT NULL DEFAULT 0 AFTER `IconFileID`;

ALTER TABLE `artifact_appearance` ADD COLUMN `UsablePlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `UiCameraID`;

ALTER TABLE `battle_pet_species_state` MODIFY COLUMN `BattlePetStateID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `broadcast_text` MODIFY COLUMN `ChatBubbleDurationMs` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;
ALTER TABLE `broadcast_text` MODIFY COLUMN `SoundEntriesID1` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `ChatBubbleDurationMs`;
ALTER TABLE `broadcast_text` MODIFY COLUMN `SoundEntriesID2` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundEntriesID1`;
ALTER TABLE `broadcast_text` MODIFY COLUMN `EmoteID1` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `SoundEntriesID2`;

ALTER TABLE `cfg_regions` ADD COLUMN `ChallengeTimeOffset1` int(11) NOT NULL DEFAULT 0 AFTER `ChallengeOrigin`;
ALTER TABLE `cfg_regions` ADD COLUMN `ChallengeTimeOffset2` int(11) NOT NULL DEFAULT 0 AFTER `ChallengeTimeOffset1`;

ALTER TABLE `chr_classes` ADD COLUMN `SpellTextureBlobFileDataID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `StartingLevel`;

ALTER TABLE `chr_races` MODIFY COLUMN `HelmVisFallbackRaceID` int(11) NOT NULL DEFAULT 0 AFTER `MaleSkeletonFileDataID`;
ALTER TABLE `chr_races` MODIFY COLUMN `FactionID` smallint(6) NOT NULL DEFAULT 0 AFTER `HelmVisFallbackRaceID`;
ALTER TABLE `chr_races` MODIFY COLUMN `CinematicSequenceID` smallint(6) NOT NULL DEFAULT 0 AFTER `FactionID`;

ALTER TABLE `creature_display_info` MODIFY COLUMN `DissolveOutEffectID` int(11) NOT NULL DEFAULT 0 AFTER `Gender`;
ALTER TABLE `creature_display_info` MODIFY COLUMN `CreatureModelMinLod` tinyint(4) NOT NULL DEFAULT 0 AFTER `DissolveOutEffectID`;

ALTER TABLE `currency_types` ADD COLUMN `ItemGroupSoundsID` int(11) NOT NULL DEFAULT 0 AFTER `FactionID`;

ALTER TABLE `difficulty` MODIFY COLUMN `Flags` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPlayers`;

ALTER TABLE `dungeon_encounter` ADD COLUMN `CompleteWorldStateID` int(11) NOT NULL DEFAULT 0 AFTER `OrderIndex`;
ALTER TABLE `dungeon_encounter` ADD COLUMN `Faction` int(11) NOT NULL DEFAULT 0 AFTER `SpellIconFileID`;

ALTER TABLE `faction` MODIFY COLUMN `FriendshipRepID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Expansion`;

ALTER TABLE `heirloom` ADD COLUMN `UpgradeItemID4` int(11) NOT NULL DEFAULT 0 AFTER `UpgradeItemID3`;
ALTER TABLE `heirloom` ADD COLUMN `UpgradeItemBonusListID4` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `UpgradeItemBonusListID3`;

ALTER TABLE `holidays` ADD COLUMN `Date17` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date16`;
ALTER TABLE `holidays` ADD COLUMN `Date18` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date17`;
ALTER TABLE `holidays` ADD COLUMN `Date19` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date18`;
ALTER TABLE `holidays` ADD COLUMN `Date20` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date19`;
ALTER TABLE `holidays` ADD COLUMN `Date21` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date20`;
ALTER TABLE `holidays` ADD COLUMN `Date22` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date21`;
ALTER TABLE `holidays` ADD COLUMN `Date23` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date22`;
ALTER TABLE `holidays` ADD COLUMN `Date24` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date23`;
ALTER TABLE `holidays` ADD COLUMN `Date25` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date24`;
ALTER TABLE `holidays` ADD COLUMN `Date26` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Date25`;

ALTER TABLE `item_child_equipment` MODIFY COLUMN `ParentItemID` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_level_selector` ADD COLUMN `AzeriteUnlockMappingSet` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemLevelSelectorQualitySetID`;

DROP TABLE `item_random_properties`;

DROP TABLE `item_random_properties_locale`;

DROP TABLE `item_random_suffix`;

DROP TABLE `item_random_suffix_locale`;

ALTER TABLE `item_search_name` MODIFY COLUMN `Flags4` int(11) NOT NULL DEFAULT 0 AFTER `Flags3`;

ALTER TABLE `item_sparse` MODIFY COLUMN `Flags2` int(11) NOT NULL DEFAULT 0 AFTER `Flags1`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Flags3` int(11) NOT NULL DEFAULT 0 AFTER `Flags2`;
ALTER TABLE `item_sparse` MODIFY COLUMN `Flags4` int(11) NOT NULL DEFAULT 0 AFTER `Flags3`;
ALTER TABLE `item_sparse` MODIFY COLUMN `FactionRelated` int(11) NOT NULL DEFAULT 0 AFTER `Flags4`;
ALTER TABLE `item_sparse` MODIFY COLUMN `ItemNameDescriptionID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `FactionRelated`;
ALTER TABLE `item_sparse` MODIFY COLUMN `RequiredTransmogHoliday` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`;
ALTER TABLE `item_sparse` MODIFY COLUMN `RequiredHoliday` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredTransmogHoliday`;
ALTER TABLE `item_sparse` MODIFY COLUMN `LimitCategory` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `RequiredHoliday`;
ALTER TABLE `item_sparse` MODIFY COLUMN `GemProperties` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `LimitCategory`;
ALTER TABLE `item_sparse` MODIFY COLUMN `SocketMatchEnchantmentId` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `GemProperties`;
ALTER TABLE `item_sparse` MODIFY COLUMN `TotemCategoryID` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `SocketMatchEnchantmentId`;
ALTER TABLE `item_sparse` MODIFY COLUMN `InstanceBound` smallint(5) UNSIGNED NOT NULL DEFAULT 0 AFTER `TotemCategoryID`;
ALTER TABLE `item_sparse` DROP COLUMN `ItemRandomSuffixGroupID`;
ALTER TABLE `item_sparse` DROP COLUMN `RandomSelect`;

ALTER TABLE `liquid_type` MODIFY COLUMN `MinimapStaticCol` int(11) NOT NULL DEFAULT 0 AFTER `MaterialID`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture1` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `MinimapStaticCol`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture2` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture1`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture3` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture2`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture4` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture3`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture5` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture4`;
ALTER TABLE `liquid_type` MODIFY COLUMN `FrameCountTexture6` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `FrameCountTexture5`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Color1` int(11) NOT NULL DEFAULT 0 AFTER `FrameCountTexture6`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Color2` int(11) NOT NULL DEFAULT 0 AFTER `Color1`;
ALTER TABLE `liquid_type` MODIFY COLUMN `Float1` float NOT NULL DEFAULT 0 AFTER `Color2`;

ALTER TABLE `map` ADD COLUMN `WdtFileDataID` int(11) NOT NULL DEFAULT 0 AFTER `ZmpFileDataID`;
ALTER TABLE `map` MODIFY COLUMN `MaxPlayers` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `CorpseMapID`;
ALTER TABLE `map` MODIFY COLUMN `WindSettingsID` smallint(6) NOT NULL DEFAULT 0 AFTER `MaxPlayers`;

ALTER TABLE `map_difficulty` MODIFY COLUMN `DifficultyID` int(11) NOT NULL DEFAULT 0 AFTER `Message`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `LockID` int(11) NOT NULL DEFAULT 0 AFTER `DifficultyID`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `ResetInterval` tinyint(4) NOT NULL DEFAULT 0 AFTER `LockID`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `MaxPlayers` int(11) NOT NULL DEFAULT 0 AFTER `ResetInterval`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `ItemContext` int(11) NOT NULL DEFAULT 0 AFTER `MaxPlayers`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `ItemContextPickerID` int(11) NOT NULL DEFAULT 0 AFTER `ItemContext`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `Flags` int(11) NOT NULL DEFAULT 0 AFTER `ItemContextPickerID`;
ALTER TABLE `map_difficulty` MODIFY COLUMN `MapID` int(11) NOT NULL DEFAULT 0 AFTER `ContentTuningID`;

ALTER TABLE `pvp_talent` MODIFY COLUMN `Flags` int(11) NOT NULL DEFAULT 0 AFTER `OverridesSpellID`;
ALTER TABLE `pvp_talent` MODIFY COLUMN `ActionBarSpellID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `scenario` MODIFY COLUMN `UiTextureKitID` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `skill_line` MODIFY COLUMN `SpellBookSpellID` int(11) NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `sound_kit` MODIFY COLUMN `SoundType` int(11) NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `spell_misc` MODIFY COLUMN `MinDuration` float NOT NULL DEFAULT 0 AFTER `LaunchDelay`;

ALTER TABLE `taxi_nodes` ADD COLUMN `MinimapAtlasMemberID` int(11) NOT NULL DEFAULT 0 AFTER `UiTextureKitID`;
ALTER TABLE `taxi_nodes` MODIFY COLUMN `ConditionID` int(11) NOT NULL DEFAULT 0 AFTER `ContinentID`;

ALTER TABLE `taxi_path_node` MODIFY COLUMN `ArrivalEventID` int(11) NOT NULL DEFAULT 0 AFTER `Delay`;
ALTER TABLE `taxi_path_node` MODIFY COLUMN `DepartureEventID` int(11) NOT NULL DEFAULT 0 AFTER `ArrivalEventID`;

ALTER TABLE `transmog_set` ADD COLUMN `Unknown810` tinyint(3) UNSIGNED NOT NULL DEFAULT 0 AFTER `ParentTransmogSetID`;
ALTER TABLE `transmog_set` ADD COLUMN `PatchID` int(11) NOT NULL DEFAULT 0 AFTER `ExpansionID`;

ALTER TABLE `world_effect` MODIFY COLUMN `TargetType` tinyint(4) NOT NULL DEFAULT 0 AFTER `WhenToDisplay`;
