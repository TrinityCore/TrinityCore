--
-- Table structure for table `battle_pet_breed_quality`
--
ALTER TABLE `battle_pet_breed_quality` ADD `MaxQualityRoll` int NOT NULL DEFAULT 0 AFTER `ID`;

--
-- Table structure for table `battle_pet_species`
--
ALTER TABLE `battle_pet_species` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `PetTypeEnum`;

--
-- Table structure for table `battlemaster_list`
--
ALTER TABLE `battlemaster_list` MODIFY `MaxPlayers` int NOT NULL DEFAULT 0 AFTER `MinPlayers`;

--
-- Table structure for table `battlemaster_list`
--
ALTER TABLE `character_loadout` MODIFY `Purpose` int NOT NULL DEFAULT 0 AFTER `ChrClassID`;
ALTER TABLE `character_loadout` CHANGE `Unused910` `ItemContext` tinyint NOT NULL DEFAULT 0 AFTER `Purpose`;

--
-- Table structure for table `chr_customization_choice`
--
ALTER TABLE `chr_customization_choice` ADD `ChrCustomizationVisReqID` int NOT NULL DEFAULT 0 AFTER `ChrCustomizationReqID`;

--
-- Table structure for table `chr_customization_element`
--
ALTER TABLE `chr_customization_element` ADD `ChrCustomizationVoiceID` int NOT NULL DEFAULT 0 AFTER `ChrCustItemGeoModifyID`;

--
-- Table structure for table `chr_customization_req`
--
ALTER TABLE `chr_customization_req`
  ADD `ReqSource` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `ID`,
  ADD `QuestID` int NOT NULL DEFAULT 0 AFTER `AchievementID`;

--
-- Table structure for table `chr_customization_req_locale`
--
DROP TABLE IF EXISTS `chr_customization_req_locale`;
CREATE TABLE `chr_customization_req_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `ReqSource_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB);

--
-- Table structure for table `chr_model`
--
ALTER TABLE `chr_model` MODIFY `DisplayID` int NOT NULL DEFAULT 0 AFTER `Sex`;

--
-- Table structure for table `chr_model`
--
ALTER TABLE `chr_race_x_chr_model`
  ADD `Sex` int NOT NULL DEFAULT 0 AFTER `ChrModelID`,
  ADD `AllowedTransmogSlots` int NOT NULL DEFAULT 0 AFTER `Sex`;

--
-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races` ADD `Unknown1000` int NOT NULL DEFAULT 0 AFTER `Unknown910_23`;

--
-- Table structure for table `cinematic_camera`
--
ALTER TABLE `cinematic_camera` CHANGE `Unknown915` `ConversationID` int unsigned NOT NULL DEFAULT 0 AFTER `FileDataID`;

--
-- Table structure for table `creature_display_info`
--
ALTER TABLE `creature_display_info` ADD `TextureVariationFileDataID4` int NOT NULL DEFAULT 0 AFTER `TextureVariationFileDataID3`;

--
-- Table structure for table `currency_types`
--
ALTER TABLE `currency_types`
  ADD `RechargingAmountPerCycle` int unsigned NOT NULL DEFAULT 0 AFTER `MaxQtyWorldStateID`,
  ADD `RechargingCycleDurationMS` int unsigned NOT NULL DEFAULT 0 AFTER `RechargingAmountPerCycle`;

--
-- Table structure for table `curve_point`
--
ALTER TABLE `curve_point` MODIFY `ID` int unsigned NOT NULL DEFAULT 0 AFTER `PreSLSquishPosY`;

--
-- Table structure for table `dungeon_encounter`
--
ALTER TABLE `dungeon_encounter` DROP `CreatureDisplayID`;

--
-- Table structure for table `faction`
--
ALTER TABLE `faction`
  ADD `RenownFactionID` int NOT NULL DEFAULT 0 AFTER `ParagonFactionID`,
  ADD `RenownCurrencyID` int NOT NULL DEFAULT 0 AFTER `RenownFactionID`,
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `FriendshipRepID`;

--
-- Table structure for table `faction_template`
--
ALTER TABLE `faction_template`
  ADD `Enemies5` smallint unsigned NOT NULL DEFAULT 0 AFTER `Enemies4`,
  ADD `Enemies6` smallint unsigned NOT NULL DEFAULT 0 AFTER `Enemies5`,
  ADD `Enemies7` smallint unsigned NOT NULL DEFAULT 0 AFTER `Enemies6`,
  ADD `Enemies8` smallint unsigned NOT NULL DEFAULT 0 AFTER `Enemies7`,
  ADD `Friend5` smallint unsigned NOT NULL DEFAULT 0 AFTER `Friend4`,
  ADD `Friend6` smallint unsigned NOT NULL DEFAULT 0 AFTER `Friend5`,
  ADD `Friend7` smallint unsigned NOT NULL DEFAULT 0 AFTER `Friend6`,
  ADD `Friend8` smallint unsigned NOT NULL DEFAULT 0 AFTER `Friend7`;

--
-- Table structure for table `garr_talent_tree`
--
ALTER TABLE `garr_talent_tree` MODIFY `FeatureTypeIndex` tinyint unsigned NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

--
-- Table structure for table `gossip_npc_option`
--
DROP TABLE IF EXISTS `gossip_npc_option`;
CREATE TABLE `gossip_npc_option` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `GossipNpcOption` int NOT NULL DEFAULT '0',
  `LFGDungeonsID` int NOT NULL DEFAULT '0',
  `TrainerID` int NOT NULL DEFAULT '0',
  `GarrFollowerTypeID` int NOT NULL DEFAULT '0',
  `CharShipmentID` int NOT NULL DEFAULT '0',
  `GarrTalentTreeID` int NOT NULL DEFAULT '0',
  `UiMapID` int NOT NULL DEFAULT '0',
  `UiItemInteractionID` int NOT NULL DEFAULT '0',
  `Unknown_1000_8` int NOT NULL DEFAULT '0',
  `Unknown_1000_9` int NOT NULL DEFAULT '0',
  `CovenantID` int NOT NULL DEFAULT '0',
  `GossipOptionID` int NOT NULL DEFAULT '0',
  `TraitTreeID` int NOT NULL DEFAULT '0',
  `ProfessionID` int NOT NULL DEFAULT '0',
  `Unknown_1002_14` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `item`
--
ALTER TABLE `item` ADD `CraftingQualityID` int NOT NULL DEFAULT 0 AFTER `ModifiedCraftingReagentItemID`;

--
-- Table structure for table `item_extended_cost`
--
ALTER TABLE `item_extended_cost` MODIFY `MinReputation` int NOT NULL DEFAULT 0 AFTER `MinFactionID`;

--
-- Table structure for table `item_search_name`
--
ALTER TABLE `item_search_name` MODIFY `MinReputation` int NOT NULL DEFAULT 0 AFTER `MinFactionID`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse` MODIFY `MinReputation` int NOT NULL DEFAULT 0 AFTER `MaxCount`;

--
-- Table structure for table `journal_instance`
--
ALTER TABLE `journal_instance` DROP `OrderIndex`;

--
-- Table structure for table `map`
--
ALTER TABLE `map` ADD `NavigationMaxDistance` int NOT NULL DEFAULT 0 AFTER `WdtFileDataID`;

--
-- Table structure for table `mount_capability`
--
ALTER TABLE `mount_capability` ADD `FlightCapabilityID` int NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;

--
-- Table structure for table `player_condition`
--
ALTER TABLE `player_condition`
  ADD `TraitNodeEntryLogic` int unsigned NOT NULL DEFAULT 0 AFTER `CovenantID`,
  ADD `TraitNodeEntryID1` int NOT NULL DEFAULT 0 AFTER `MovementFlags2`,
  ADD `TraitNodeEntryID2` int NOT NULL DEFAULT 0 AFTER `TraitNodeEntryID1`,
  ADD `TraitNodeEntryID3` int NOT NULL DEFAULT 0 AFTER `TraitNodeEntryID2`,
  ADD `TraitNodeEntryID4` int NOT NULL DEFAULT 0 AFTER `TraitNodeEntryID3`,
  ADD `TraitNodeEntryMinRank1` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryID4`,
  ADD `TraitNodeEntryMinRank2` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMinRank1`,
  ADD `TraitNodeEntryMinRank3` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMinRank2`,
  ADD `TraitNodeEntryMinRank4` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMinRank3`,
  ADD `TraitNodeEntryMaxRank1` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMinRank4`,
  ADD `TraitNodeEntryMaxRank2` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMaxRank1`,
  ADD `TraitNodeEntryMaxRank3` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMaxRank2`,
  ADD `TraitNodeEntryMaxRank4` smallint unsigned NOT NULL DEFAULT 0 AFTER `TraitNodeEntryMaxRank3`;

--
-- Table structure for table `power_type`
--
ALTER TABLE `power_type`
  MODIFY `MinPower` int NOT NULL DEFAULT 0 AFTER `PowerTypeEnum`,
  MODIFY `MaxBasePower` int NOT NULL DEFAULT 0 AFTER `MinPower`,
  MODIFY `CenterPower` int NOT NULL DEFAULT 0 AFTER `MaxBasePower`,
  MODIFY `DefaultPower` int NOT NULL DEFAULT 0 AFTER `CenterPower`,
  MODIFY `DisplayModifier` int NOT NULL DEFAULT 0 AFTER `DefaultPower`,
  MODIFY `RegenInterruptTimeMS` int NOT NULL DEFAULT 0 AFTER `DisplayModifier`;

--
-- Table structure for table `pvp_talent`
--
ALTER TABLE `pvp_talent` ADD `PlayerConditionID` int NOT NULL DEFAULT 0 AFTER `LevelRequired`;

--
-- Table structure for table `quest_info`
--
ALTER TABLE `quest_info` MODIFY `Profession` int NOT NULL DEFAULT 0 AFTER `Modifiers`;

--
-- Table structure for table `quest_v2`
--
ALTER TABLE `quest_v2` ADD `UiQuestDetailsTheme` int NOT NULL DEFAULT 0 AFTER `UniqueBitFlag`;

--
-- Table structure for table `quest_v2`
--
ALTER TABLE `skill_line`
  ADD `ExpansionNameSharedStringID` int NOT NULL DEFAULT 0 AFTER `SpellBookSpellID`,
  ADD `HordeExpansionNameSharedStringID` int NOT NULL DEFAULT 0 AFTER `ExpansionNameSharedStringID`;

--
-- Table structure for table `quest_v2`
--
ALTER TABLE `skill_line_ability`
  ADD `AbilityVerb` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `RaceMask`,
  ADD `AbilityAllVerb` text CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NULL AFTER `AbilityVerb`;

--
-- Table structure for table `skill_line_ability_locale`
--
DROP TABLE IF EXISTS `skill_line_ability_locale`;
CREATE TABLE `skill_line_ability_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `AbilityVerb_lang` text,
  `AbilityAllVerb_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB);

--
-- Table structure for table `skill_line_ability_locale`
--
ALTER TABLE `sound_kit`
  MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `VolumeFloat`,
  ADD `SoundMixGroupID` int unsigned NOT NULL DEFAULT 0 AFTER `MaxInstances`;

--
-- Table structure for table `spell_aura_restrictions`
--
ALTER TABLE `spell_aura_restrictions`
  MODIFY `DifficultyID` int NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `CasterAuraState` int NOT NULL DEFAULT 0 AFTER `DifficultyID`,
  MODIFY `TargetAuraState` int NOT NULL DEFAULT 0 AFTER `CasterAuraState`,
  MODIFY `ExcludeCasterAuraState` int NOT NULL DEFAULT 0 AFTER `TargetAuraState`,
  MODIFY `ExcludeTargetAuraState` int NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraState`,
  ADD `CasterAuraType` int NOT NULL DEFAULT 0 AFTER `ExcludeTargetAuraSpell`,
  ADD `TargetAuraType` int NOT NULL DEFAULT 0 AFTER `CasterAuraType`,
  ADD `ExcludeCasterAuraType` int NOT NULL DEFAULT 0 AFTER `TargetAuraType`,
  ADD `ExcludeTargetAuraType` int NOT NULL DEFAULT 0 AFTER `ExcludeCasterAuraType`;

--
-- Table structure for table `spell_casting_requirements`
--
ALTER TABLE `spell_casting_requirements` MODIFY `MinReputation` int NOT NULL DEFAULT 0 AFTER `MinFactionID`;

--
-- Table structure for table `spell_cooldowns`
--
ALTER TABLE `spell_cooldowns` ADD `AuraSpellID` int NOT NULL DEFAULT 0 AFTER `StartRecoveryTime`;

--
-- Table structure for table `spell_item_enchantment`
--
ALTER TABLE `spell_item_enchantment` ADD `Duration` int NOT NULL DEFAULT 0 AFTER `HordeName`;

--
-- Table structure for table `spell_power`
--
ALTER TABLE `spell_power` ADD `OptionalCostPct` float NOT NULL DEFAULT 0 AFTER `PowerCostMaxPct`;

--
-- Table structure for table `spell_power`
--
ALTER TABLE `spell_reagents` ADD `ReagentRecraftCount1` smallint NOT NULL DEFAULT 0 AFTER `ReagentCount8`,
  ADD `ReagentRecraftCount2` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount1`,
  ADD `ReagentRecraftCount3` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount2`,
  ADD `ReagentRecraftCount4` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount3`,
  ADD `ReagentRecraftCount5` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount4`,
  ADD `ReagentRecraftCount6` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount5`,
  ADD `ReagentRecraftCount7` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount6`,
  ADD `ReagentRecraftCount8` smallint NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount7`,
  ADD `ReagentSource1` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentRecraftCount8`,
  ADD `ReagentSource2` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource1`,
  ADD `ReagentSource3` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource2`,
  ADD `ReagentSource4` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource3`,
  ADD `ReagentSource5` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource4`,
  ADD `ReagentSource6` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource5`,
  ADD `ReagentSource7` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource6`,
  ADD `ReagentSource8` tinyint unsigned NOT NULL DEFAULT 0 AFTER `ReagentSource7`;

--
-- Table structure for table `spell_x_spell_visual`
--
ALTER TABLE `spell_x_spell_visual` ADD `Flags` int NOT NULL DEFAULT 0 AFTER `Probability`;

--
-- Table structure for table `ui_map_link`
--
ALTER TABLE `ui_map_link` ADD `PlayerConditionID` int NOT NULL DEFAULT 0 AFTER `ChildUiMapID`;
