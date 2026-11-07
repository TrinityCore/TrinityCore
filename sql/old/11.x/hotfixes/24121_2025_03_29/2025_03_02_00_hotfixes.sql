ALTER TABLE `azerite_power_set_member` MODIFY `Class` tinyint NOT NULL DEFAULT 0 AFTER `AzeritePowerID`;

ALTER TABLE `barber_shop_style`
  MODIFY `Race` tinyint NOT NULL DEFAULT 0 AFTER `CostModifier`,
  MODIFY `Sex` tinyint NOT NULL DEFAULT 0 AFTER `Race`;

ALTER TABLE `challenge_mode_item_bonus_override` ADD `RequiredTimeEventNotPassed` int NOT NULL DEFAULT 0 AFTER `RequiredTimeEventPassed`;

ALTER TABLE `char_base_info` MODIFY `OtherFactionRaceID` tinyint NOT NULL DEFAULT 0 AFTER `ClassID`;

ALTER TABLE `chat_channels` MODIFY `FactionGroup` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `chr_class_ui_display` MODIFY `ChrClassesID` tinyint NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `chr_classes` MODIFY `ID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `DefaultSpec`;

ALTER TABLE `chr_customization_req` ADD `RegionGroupMask` int NOT NULL DEFAULT 0 AFTER `ClassMask`;

ALTER TABLE `chr_race_x_chr_model`
  MODIFY `ChrRacesID` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `Sex` tinyint NOT NULL DEFAULT 0 AFTER `ChrModelID`;

ALTER TABLE `chr_races`
  MODIFY `BaseLanguage` tinyint NOT NULL DEFAULT 0 AFTER `Unknown910_23`,
  MODIFY `CreatureType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `BaseLanguage`,
  MODIFY `Alliance` tinyint NOT NULL DEFAULT 0 AFTER `CreatureType`,
  MODIFY `RaceRelated` tinyint NOT NULL DEFAULT 0 AFTER `Alliance`,
  MODIFY `UnalteredVisualRaceID` tinyint NOT NULL DEFAULT 0 AFTER `RaceRelated`,
  MODIFY `DefaultClassID` tinyint NOT NULL DEFAULT 0 AFTER `UnalteredVisualRaceID`,
  MODIFY `NeutralRaceID` tinyint NOT NULL DEFAULT 0 AFTER `DefaultClassID`,
  MODIFY `MaleModelFallbackRaceID` tinyint NOT NULL DEFAULT 0 AFTER `NeutralRaceID`,
  MODIFY `FemaleModelFallbackRaceID` tinyint NOT NULL DEFAULT 0 AFTER `MaleModelFallbackSex`,
  MODIFY `FemaleModelFallbackSex` tinyint NOT NULL DEFAULT 0 AFTER `FemaleModelFallbackRaceID`,
  MODIFY `MaleTextureFallbackRaceID` tinyint NOT NULL DEFAULT 0 AFTER `FemaleModelFallbackSex`,
  MODIFY `FemaleTextureFallbackRaceID` tinyint NOT NULL DEFAULT 0 AFTER `MaleTextureFallbackSex`,
  MODIFY `FemaleTextureFallbackSex` tinyint NOT NULL DEFAULT 0 AFTER `FemaleTextureFallbackRaceID`,
  MODIFY `HelmetAnimScalingRaceID` tinyint NOT NULL DEFAULT 0 AFTER `FemaleTextureFallbackSex`,
  MODIFY `UnalteredVisualCustomizationRaceID` tinyint NOT NULL DEFAULT 0 AFTER `HelmetAnimScalingRaceID`,
  DROP `Unknown1000`;

ALTER TABLE `creature_display_info_extra` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `DisplayClassID`;

ALTER TABLE `creature_type` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `currency_types` ADD `OrderIndex` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `AccountTransferPercentage`;

ALTER TABLE `emotes_text_sound`
  MODIFY `RaceID` tinyint NOT NULL DEFAULT 0 AFTER `ID`,
  MODIFY `ClassID` tinyint NOT NULL DEFAULT 0 AFTER `RaceID`,
  MODIFY `SexID` tinyint NOT NULL DEFAULT 0 AFTER `ClassID`;

ALTER TABLE `garr_follower` MODIFY `Gender` tinyint NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `gossip_npc_option` ADD `SkillLineID` int NOT NULL DEFAULT 0 AFTER `Unknown_1002_14`;

ALTER TABLE `item_sparse` MODIFY `RequiredPVPRank` tinyint NOT NULL DEFAULT 0 AFTER `RequiredPVPMedal`;

ALTER TABLE `journal_instance` ADD `CovenantID` smallint UNSIGNED NOT NULL DEFAULT 0 AFTER `AreaID`;

ALTER TABLE `liquid_type` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Texture6`;

ALTER TABLE `mount_capability` ADD `DriveCapabilityID` int NOT NULL DEFAULT 0 AFTER `FlightCapabilityID`;

ALTER TABLE `name_gen`
  MODIFY `RaceID` tinyint NOT NULL DEFAULT 0 AFTER `Name`,
  MODIFY `Sex` tinyint NOT NULL DEFAULT 0 AFTER `RaceID`;

ALTER TABLE `path` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `Alpha`;

ALTER TABLE `player_condition`
  MODIFY `LifetimeMaxPVPRank` tinyint NOT NULL DEFAULT 0 AFTER `PartyStatus`,
  MODIFY `MinPVPRank` tinyint NOT NULL DEFAULT 0 AFTER `MinExpansionTier`,
  MODIFY `MaxPVPRank` tinyint NOT NULL DEFAULT 0 AFTER `MinPVPRank`;

ALTER TABLE `quest_line_x_quest` ADD `Unknown1110` int NOT NULL DEFAULT 0 AFTER `Flags`;

ALTER TABLE `spell_shapeshift_form` MODIFY `CreatureType` tinyint UNSIGNED NOT NULL DEFAULT 0 AFTER `CreatureDisplayID`;

ALTER TABLE `talent` MODIFY `ClassID` tinyint NOT NULL DEFAULT 0 AFTER `ColumnIndex`;

ALTER TABLE `world_effect` MODIFY `WhenToDisplay` int NOT NULL DEFAULT 0 AFTER `QuestFeedbackEffectID`;

ALTER TABLE `world_map_overlay` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `PlayerConditionID`;
