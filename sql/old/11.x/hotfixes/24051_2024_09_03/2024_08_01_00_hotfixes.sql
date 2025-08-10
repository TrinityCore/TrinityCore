ALTER TABLE `animation_data` MODIFY `BehaviorID` smallint NOT NULL DEFAULT 0 AFTER `BehaviorTier`;

ALTER TABLE `artifact_power` MODIFY `Tier` tinyint NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `battlemaster_list`
  DROP `MapID1`,
  DROP `MapID2`,
  DROP `MapID3`,
  DROP `MapID4`,
  DROP `MapID5`,
  DROP `MapID6`,
  DROP `MapID7`,
  DROP `MapID8`,
  DROP `MapID9`,
  DROP `MapID10`,
  DROP `MapID11`,
  DROP `MapID12`,
  DROP `MapID13`,
  DROP `MapID14`,
  DROP `MapID15`,
  DROP `MapID16`;

DROP TABLE IF EXISTS `battlemaster_list_x_map`;
CREATE TABLE `battlemaster_list_x_map` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `MapID` int NOT NULL DEFAULT '0',
  `BattlemasterListID` int unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

ALTER TABLE `challenge_mode_item_bonus_override`
  ADD `RequiredTimeEventPassed` int NOT NULL DEFAULT 0 AFTER `Value`,
  DROP `Type`,
  DROP `MythicPlusSeasonID`,
  DROP `PvPSeasonID`;

ALTER TABLE `character_loadout` MODIFY `ItemContext` tinyint NOT NULL DEFAULT 0 AFTER `Purpose`;

ALTER TABLE `chr_classes` MODIFY `DisplayPower` tinyint NOT NULL DEFAULT 0 AFTER `PrimaryStatPriority`;

ALTER TABLE `chr_customization_option`
  ADD `ChrRacesID` int NOT NULL DEFAULT 0 AFTER `Flags`,
  ADD `Sex` int NOT NULL DEFAULT 0 AFTER `ChrRacesID`;

ALTER TABLE `creature_display_info`
  ADD `ConditionalCreatureModelID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `CreatureModelMinLod`,
  ADD `Unknown_1100_1` float NOT NULL DEFAULT 0 AFTER `ConditionalCreatureModelID`,
  ADD `Unknown_1100_2` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `Unknown_1100_1`,
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `AnimReplacementSetID`;

ALTER TABLE `creature_model_data`
  CHANGE `Unknown820_1` `MountScaleOtherIndex` tinyint NOT NULL DEFAULT 0 AFTER `TamedPetBaseScale`,
  CHANGE `Unknown820_2` `MountScaleSelf` float NOT NULL DEFAULT 0 AFTER `MountScaleOtherIndex`,
  CHANGE `Unknown820_31` `MountScaleOther1` float NOT NULL DEFAULT 0 AFTER `MountScaleOtherIndex`,
  CHANGE `Unknown820_32` `MountScaleOther2` float NOT NULL DEFAULT 0 AFTER `MountScaleOther1`,
  ADD `Unknown1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `MountScaleSelf`,
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `GeoBox6`;

ALTER TABLE `currency_types` ADD `AccountTransferPercentage` float NOT NULL DEFAULT 0 AFTER `RechargingCycleDurationMS`;

ALTER TABLE `difficulty` MODIFY `ItemContext` tinyint NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `emotes`
  MODIFY `AnimID` smallint NOT NULL DEFAULT 0 AFTER `EmoteSlashCommand`,
  MODIFY `EmoteFlags` int NOT NULL DEFAULT 0 AFTER `AnimID`,
  MODIFY `EmoteSpecProc` int NOT NULL DEFAULT 0 AFTER `EmoteFlags`;

ALTER TABLE `faction_template` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Faction`;

ALTER TABLE `gameobject_display_info` ADD `Unknown1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `ClientItemID`;

ALTER TABLE `gameobjects` ADD `Unknown1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `PhaseGroupID`;

ALTER TABLE `garr_follower` MODIFY `Quality` int NOT NULL DEFAULT 0 AFTER `AllianceGarrClassSpecID`;

ALTER TABLE `garr_plot` MODIFY `PlotType` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `glyph_properties` MODIFY `GlyphType` tinyint NOT NULL DEFAULT 0 AFTER `SpellID`;

ALTER TABLE `gossip_npc_option` MODIFY `GarrFollowerTypeID` tinyint NOT NULL DEFAULT 0 AFTER `TrainerID`;

ALTER TABLE `item_appearance` MODIFY `DisplayType` tinyint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_context_picker_entry` MODIFY `ItemCreationContext` tinyint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `item_search_name` ADD `Flags5` int NOT NULL DEFAULT 0 AFTER `Flags4`;

ALTER TABLE `item_sparse`
  ADD `Flags5` int NOT NULL DEFAULT 0 AFTER `Flags4`,
  MODIFY `StatModifierBonusStat1` int NOT NULL DEFAULT 0 AFTER `StatPercentEditor10`,
  MODIFY `StatModifierBonusStat2` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat1`,
  MODIFY `StatModifierBonusStat3` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat2`,
  MODIFY `StatModifierBonusStat4` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat3`,
  MODIFY `StatModifierBonusStat5` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat4`,
  MODIFY `StatModifierBonusStat6` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat5`,
  MODIFY `StatModifierBonusStat7` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat6`,
  MODIFY `StatModifierBonusStat8` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat7`,
  MODIFY `StatModifierBonusStat9` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat8`,
  MODIFY `StatModifierBonusStat10` int NOT NULL DEFAULT 0 AFTER `StatModifierBonusStat9`;

ALTER TABLE `journal_tier` ADD `Expansion` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `map` ADD `PreloadFileDataID` int NOT NULL DEFAULT 0 AFTER `NavigationMaxDistance`;

ALTER TABLE `map_difficulty` MODIFY `ItemContext` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `MaxPlayers`;

ALTER TABLE `mount_x_display` ADD `Unknown1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

ALTER TABLE `mythic_plus_season` ADD `StartTimeEvent` int NOT NULL DEFAULT 0 AFTER `MilestoneSeason`;

ALTER TABLE `player_condition` MODIFY `PowerTypeComp` tinyint NOT NULL DEFAULT 0 AFTER `PowerType`;

ALTER TABLE `power_display` MODIFY `ActualType` tinyint NOT NULL DEFAULT 0 AFTER `GlobalStringBaseTag`;

ALTER TABLE `power_type` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `RegenCombat`;

ALTER TABLE `scenario_step` MODIFY `ID` int UNSIGNED NOT NULL DEFAULT 0 AFTER `Title`;

ALTER TABLE `skill_line` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ParentTierIndex`;

ALTER TABLE `skill_line_ability` MODIFY `AcquireMethod` int NOT NULL DEFAULT 0 AFTER `SupercedesSpell`;

ALTER TABLE `skill_race_class_info`
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ClassMask`,
  MODIFY `Availability` int NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `spell_item_enchantment` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `EffectArg3`;

ALTER TABLE `spell_misc` ADD `PvPDurationIndex` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `DurationIndex`;

ALTER TABLE `spell_visual_effect_name` ADD `Unknown1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `Unknown901`;

ALTER TABLE `spell_visual_kit`
  ADD `ClutterLevel` int NOT NULL DEFAULT 0 AFTER `ID`,
  DROP `FallbackPriority`;

ALTER TABLE `spell_visual_missile`
  ADD `Unused1100` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `DecayTimeAfterImpact`,
  MODIFY `ClutterLevel` int NOT NULL DEFAULT 0 AFTER `AnimKitID`;

ALTER TABLE `trait_cond` ADD `TraitCondAccountElementID` int NOT NULL DEFAULT 0 AFTER `SpendMoreSharedStringID`;

ALTER TABLE `trait_node`
  MODIFY `Type` tinyint unsigned NOT NULL DEFAULT 0 AFTER `PosY`,
  ADD `TraitSubTreeID` int NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `trait_node_entry` ADD `TraitSubTreeID` int NOT NULL DEFAULT 0 AFTER `NodeEntryType`;

ALTER TABLE `trait_node_entry_x_trait_cond` MODIFY `TraitNodeEntryID` int NOT NULL DEFAULT 0 AFTER `TraitCondID`;

ALTER TABLE `transmog_set`
  MODIFY `TrackingQuestID` int NOT NULL DEFAULT 0 AFTER `ClassMask`,
  MODIFY `TransmogSetGroupID` int NOT NULL DEFAULT 0 AFTER `Flags`,
  MODIFY `ParentTransmogSetID` int NOT NULL DEFAULT 0 AFTER `ItemNameDescriptionID`,
  MODIFY `Unknown810` int NOT NULL DEFAULT 0 AFTER `ParentTransmogSetID`,
  MODIFY `ExpansionID` int NOT NULL DEFAULT 0 AFTER `Unknown810`,
  MODIFY `UiOrder` int NOT NULL DEFAULT 0 AFTER `PatchID`;

ALTER TABLE `ui_map` ADD COLUMN `AdventureMapTextureKitID` int NOT NULL DEFAULT 0 AFTER `ContentTuningID`;

ALTER TABLE `unit_condition`
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Op1` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Variable8`,
  MODIFY `Op2` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op1`,
  MODIFY `Op3` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op2`,
  MODIFY `Op4` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op3`,
  MODIFY `Op5` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op4`,
  MODIFY `Op6` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op5`,
  MODIFY `Op7` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op6`,
  MODIFY `Op8` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Op7`;

ALTER TABLE `vehicle_seat`
  MODIFY `AttachmentID` int NOT NULL DEFAULT 0 AFTER `FlagsC`,
  MODIFY `EnterAnimStart` smallint NOT NULL DEFAULT 0 AFTER `EnterMaxArcHeight`,
  MODIFY `EnterAnimLoop` smallint NOT NULL DEFAULT 0 AFTER `EnterAnimStart`,
  MODIFY `RideAnimStart` smallint NOT NULL DEFAULT 0 AFTER `EnterAnimLoop`,
  MODIFY `RideAnimLoop` smallint NOT NULL DEFAULT 0 AFTER `RideAnimStart`,
  MODIFY `RideUpperAnimStart` smallint NOT NULL DEFAULT 0 AFTER `RideAnimLoop`,
  MODIFY `RideUpperAnimLoop` smallint NOT NULL DEFAULT 0 AFTER `RideUpperAnimStart`,
  MODIFY `ExitAnimStart` smallint NOT NULL DEFAULT 0 AFTER `ExitMaxArcHeight`,
  MODIFY `ExitAnimLoop` smallint NOT NULL DEFAULT 0 AFTER `ExitAnimStart`,
  MODIFY `ExitAnimEnd` smallint NOT NULL DEFAULT 0 AFTER `ExitAnimLoop`;
