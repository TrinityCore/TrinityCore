--
-- Table structure for table `achievement`
--
ALTER TABLE `achievement`
  MODIFY `Faction` tinyint(4) NOT NULL DEFAULT '0' AFTER `SharesCriteria`,
  MODIFY `Points` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Faction`,
  MODIFY `MinimumCriteria` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Points`,
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinimumCriteria`,
  MODIFY `IconFileDataID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `CriteriaTree` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `IconFileDataID`;

--
-- Table structure for table `chr_races`
--
ALTER TABLE `chr_races`
  MODIFY `MaleDisplayID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `FemaleDisplayID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaleDisplayID`,
  CHANGE `Unk1` `AlteredFormTransitionSpellVisualID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `HighResFemaleDisplayID`,
  CHANGE `Unk2` `AlteredFormTransitionSpellVisualID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AlteredFormTransitionSpellVisualID1`,
  CHANGE `Unk3` `AlteredFormTransitionSpellVisualID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AlteredFormTransitionSpellVisualID2`,
  ADD `AlteredFormTransitionSpellVisualKitID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AlteredFormTransitionSpellVisualID3`,
  ADD `AlteredFormTransitionSpellVisualKitID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AlteredFormTransitionSpellVisualKitID1`,
  ADD `AlteredFormTransitionSpellVisualKitID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AlteredFormTransitionSpellVisualKitID2`;

--
-- Table structure for table `conversation_line`
--
ALTER TABLE `conversation_line`
  MODIFY `BroadcastTextID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `SpellVisualKitID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `BroadcastTextID`,
  MODIFY `Duration` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellVisualKitID`,
  MODIFY `NextLineID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Duration`,
  MODIFY `Unk1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `NextLineID`,
  MODIFY `Yell` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Unk1`,
  MODIFY `Unk2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Yell`,
  MODIFY `Unk3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Unk2`,
  MODIFY `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0' AFTER `Unk3`;

--
-- Table structure for table `criteria`
--
ALTER TABLE `criteria` MODIFY `ModifierTreeId` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `FailAsset`;

--
-- Table structure for table `criteria_tree`
--
ALTER TABLE `criteria_tree` MODIFY `Parent` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CriteriaID`;

--
-- Table structure for table `item_level_selector`
--
ALTER TABLE `item_level_selector` ADD `ItemLevelSelectorQualitySetID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemLevel`;

--
-- Table structure for table `item_level_selector_quality`
--
DROP TABLE IF EXISTS `item_level_selector_quality`;
CREATE TABLE `item_level_selector_quality` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemBonusListID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelSelectorQualitySetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Quality` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_level_selector_quality_set`
--
DROP TABLE IF EXISTS `item_level_selector_quality_set`;
CREATE TABLE `item_level_selector_quality_set` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemLevelMin` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ItemLevelMax` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_search_name`
--
ALTER TABLE `item_search_name`
  MODIFY `RequiredReputationFaction` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `AllowableClass`,
  MODIFY `RequiredReputationRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequiredReputationFaction`,
  MODIFY `RequiredSkill` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequiredReputationRank`,
  MODIFY `RequiredSkillRank` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequiredSkill`,
  MODIFY `RequiredSpell` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `RequiredSkillRank`;

--
-- Table structure for table `item_sparse`
--
ALTER TABLE `item_sparse` ADD `Flags4` int(10) UNSIGNED NOT NULL DEFAULT 0 AFTER `Flags3`;

--
-- Table structure for table `keychain`
--
RENAME TABLE `key_chain` TO `keychain`;

--
-- Table structure for table `modifier_tree`
--
ALTER TABLE `modifier_tree` MODIFY `Parent` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Asset2`;

--
-- Table structure for table `player_condition`
--
ALTER TABLE `player_condition`
  MODIFY `Time1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `RaceMask`,
  MODIFY `Time2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Time1`,
  MODIFY `AuraSpellID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Time2`,
  MODIFY `AuraSpellID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraSpellID1`,
  MODIFY `AuraSpellID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraSpellID2`,
  MODIFY `AuraSpellID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraSpellID3`,
  MODIFY `FailureDescription` text CHARACTER SET utf8 COLLATE utf8_general_ci NULL AFTER `AuraSpellID4`,
  MODIFY `SkillID1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `FailureDescription`,
  MODIFY `SkillID2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `SkillID1`,
  MODIFY `SkillID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `SkillID2`,
  MODIFY `SkillID4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `SkillID3`,
  MODIFY `MinSkill1` smallint(6) NOT NULL DEFAULT '0' AFTER `SkillID4`,
  MODIFY `MinSkill2` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill1`,
  MODIFY `MinSkill3` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill2`,
  MODIFY `MinSkill4` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill3`,
  MODIFY `MaxSkill1` smallint(6) NOT NULL DEFAULT '0' AFTER `MinSkill4`,
  MODIFY `MaxSkill2` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill1`,
  MODIFY `MaxSkill3` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill2`,
  MODIFY `MaxSkill4` smallint(6) NOT NULL DEFAULT '0' AFTER `MaxSkill3`,
  MODIFY `PrevQuestID1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxSkill4`,
  MODIFY `PrevQuestID2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `PrevQuestID1`,
  MODIFY `PrevQuestID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `PrevQuestID2`,
  MODIFY `PrevQuestID4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `PrevQuestID3`,
  MODIFY `CurrQuestID1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `PrevQuestID4`,
  MODIFY `CurrQuestID2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrQuestID1`,
  MODIFY `CurrQuestID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrQuestID2`,
  MODIFY `CurrQuestID4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrQuestID3`,
  MODIFY `CurrentCompletedQuestID1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrQuestID4`,
  MODIFY `CurrentCompletedQuestID2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID1`,
  MODIFY `CurrentCompletedQuestID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID2`,
  MODIFY `CurrentCompletedQuestID4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID3`,
  MODIFY `Explored1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrentCompletedQuestID4`,
  MODIFY `Explored2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Explored1`,
  MODIFY `Achievement1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Explored2`,
  MODIFY `Achievement2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Achievement1`,
  MODIFY `Achievement3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Achievement2`,
  MODIFY `Achievement4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Achievement3`,
  MODIFY `AreaID1` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Achievement4`,
  MODIFY `AreaID2` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `AreaID1`,
  MODIFY `AreaID3` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `AreaID2`,
  MODIFY `AreaID4` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `AreaID3`,
  MODIFY `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `AreaID4`,
  MODIFY `MinReputation1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `MinReputation2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinReputation1`,
  MODIFY `MinReputation3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinReputation2`,
  MODIFY `AuraCount1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinReputation3`,
  MODIFY `AuraCount2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraCount1`,
  MODIFY `AuraCount3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraCount2`,
  MODIFY `AuraCount4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraCount3`,
  MODIFY `LfgStatus1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraCount4`,
  MODIFY `LfgStatus2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgStatus1`,
  MODIFY `LfgStatus3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgStatus2`,
  MODIFY `LfgStatus4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgStatus3`,
  MODIFY `LfgCompare1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgStatus4`,
  MODIFY `LfgCompare2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgCompare1`,
  MODIFY `LfgCompare3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgCompare2`,
  MODIFY `LfgCompare4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgCompare3`,
  MODIFY `CurrencyCount1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgCompare4`,
  MODIFY `CurrencyCount2` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyCount1`,
  MODIFY `CurrencyCount3` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyCount2`,
  MODIFY `CurrencyCount4` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyCount3`,
  MODIFY `ClassMask` int(11) NOT NULL DEFAULT '0' AFTER `CurrencyCount4`,
  MODIFY `MinFactionID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ClassMask`,
  MODIFY `MinFactionID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinFactionID1`,
  MODIFY `MinFactionID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinFactionID2`,
  MODIFY `SpellID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinFactionID3`,
  MODIFY `SpellID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID1`,
  MODIFY `SpellID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID2`,
  MODIFY `SpellID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID3`,
  MODIFY `ItemID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `SpellID4`,
  MODIFY `ItemID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemID1`,
  MODIFY `ItemID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemID2`,
  MODIFY `ItemID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemID3`,
  MODIFY `ItemCount1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemID4`,
  MODIFY `ItemCount2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemCount1`,
  MODIFY `ItemCount3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemCount2`,
  MODIFY `ItemCount4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemCount3`,
  MODIFY `LfgValue1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemCount4`,
  MODIFY `LfgValue2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgValue1`,
  MODIFY `LfgValue3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgValue2`,
  MODIFY `LfgValue4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgValue3`,
  MODIFY `CurrencyID1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `LfgValue4`,
  MODIFY `CurrencyID2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyID1`,
  MODIFY `CurrencyID3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyID2`,
  MODIFY `CurrencyID4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyID3`,
  MODIFY `QuestKillMonster1` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyID4`,
  MODIFY `QuestKillMonster2` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestKillMonster1`,
  MODIFY `QuestKillMonster3` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestKillMonster2`,
  MODIFY `QuestKillMonster4` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestKillMonster3`,
  MODIFY `QuestKillMonster5` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestKillMonster4`,
  MODIFY `QuestKillMonster6` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `QuestKillMonster5`,
  MODIFY `MovementFlags1` int(11) NOT NULL DEFAULT '0' AFTER `QuestKillMonster6`,
  MODIFY `MovementFlags2` int(11) NOT NULL DEFAULT '0' AFTER `MovementFlags1`,
  MODIFY `MinLevel` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `MovementFlags2`,
  MODIFY `MaxLevel` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinLevel`,
  MODIFY `Gender` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxLevel`,
  MODIFY `NativeGender` tinyint(4) NOT NULL DEFAULT '0' AFTER `Gender`,
  MODIFY `LanguageID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `SkillLogic`,
  MODIFY `MinLanguage` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `LanguageID`,
  MODIFY `MaxLanguage` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinLanguage`,
  MODIFY `MaxFactionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxLanguage`,
  MODIFY `MaxReputation` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxFactionID`,
  MODIFY `Unknown1` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `ReputationLogic`,
  MODIFY `MinPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `Unknown1`,
  MODIFY `MaxPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinPVPRank`,
  MODIFY `PvpMedal` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxPVPRank`,
  MODIFY `ItemFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `ItemLogic`,
  MODIFY `WorldStateExpressionID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `AuraSpellLogic`,
  MODIFY `WeatherID` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `WorldStateExpressionID`,
  MODIFY `PartyStatus` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `WeatherID`,
  MODIFY `LifetimeMaxPVPRank` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `PartyStatus`,
  MODIFY `LfgLogic` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AchievementLogic`,
  MODIFY `CurrencyLogic` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `AreaLogic`,
  MODIFY `QuestKillID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CurrencyLogic`,
  MODIFY `MinExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `QuestKillLogic`,
  MODIFY `MaxExpansionLevel` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionLevel`,
  MODIFY `MinExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxExpansionLevel`,
  MODIFY `MaxExpansionTier` tinyint(4) NOT NULL DEFAULT '0' AFTER `MinExpansionTier`,
  MODIFY `MinGuildLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxExpansionTier`,
  MODIFY `MaxGuildLevel` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinGuildLevel`,
  MODIFY `PhaseUseFlags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `MaxGuildLevel`,
  MODIFY `PhaseGroupID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PhaseID`,
  MODIFY `MinAvgItemLevel` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PhaseGroupID`,
  MODIFY `MaxAvgItemLevel` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `MinAvgItemLevel`,
  MODIFY `ChrSpecializationIndex` tinyint(4) NOT NULL DEFAULT '0' AFTER `MaxAvgEquippedItemLevel`,
  MODIFY `ChrSpecializationRole` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationIndex`,
  MODIFY `PowerType` tinyint(4) NOT NULL DEFAULT '0' AFTER `ChrSpecializationRole`,
  MODIFY `PowerTypeComp` tinyint(4) NOT NULL DEFAULT '0' AFTER `PowerType`,
  MODIFY `PowerTypeValue` tinyint(4) NOT NULL DEFAULT '0' AFTER `PowerTypeComp`,
  MODIFY `ModifierTreeID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `PowerTypeValue`;

--
-- Table structure for table `scenario_step`
--
ALTER TABLE `scenario_step` MODIFY `CriteriaTreeID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`;

--
-- Table structure for table `sound_kit`
--
ALTER TABLE `sound_kit`
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  MODIFY `Flags` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `DistanceCutoff`,
  MODIFY `SoundEntriesAdvancedID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `SoundType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `SoundEntriesAdvancedID`,
  MODIFY `DialogType` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `SoundType`,
  MODIFY `EAXDef` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `DialogType`,
  DROP `Name`;

DROP TABLE `sound_kit_locale`;

--
-- Table structure for table `spell_aura_options`
--
ALTER TABLE `spell_aura_options` MODIFY `SpellProcsPerMinuteID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `CumulativeAura`;

--
-- Table structure for table `spell_procs_per_minute_mod`
--
ALTER TABLE `spell_procs_per_minute_mod` MODIFY `SpellProcsPerMinuteID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Param`;

--
-- Table structure for table `taxi_nodes`
--
ALTER TABLE `taxi_nodes`
  MODIFY `ID` int(10) UNSIGNED NOT NULL DEFAULT '0' FIRST,
  ADD `Unk730` float NOT NULL DEFAULT '0' AFTER `MapOffsetY`,
  ADD `FlightMapOffsetX` float NOT NULL DEFAULT '0' AFTER `Unk730`,
  ADD `FlightMapOffsetY` float NOT NULL DEFAULT '0' AFTER `FlightMapOffsetX`,
  ADD `UiTextureKitPrefixID` int(11) NOT NULL DEFAULT '0' AFTER `Flags`,
  ADD `SpecialAtlasIconPlayerConditionID` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `UiTextureKitPrefixID`;

--
-- Table structure for table `taxi_path_node`
--
ALTER TABLE `taxi_path_node`
  MODIFY `Flags` tinyint(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `ID`,
  MODIFY `Delay` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `Flags`,
  MODIFY `ArrivalEventID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `Delay`,
  MODIFY `DepartureEventID` smallint(5) UNSIGNED NOT NULL DEFAULT '0' AFTER `ArrivalEventID`;

--
-- Table structure for table `vehicle`
--
ALTER TABLE `vehicle`
  ADD `MissileTargetingID` int(11) NOT NULL DEFAULT '0' AFTER `UILocomotionType`,
  DROP `MsslTrgtTurnLingering`,
  DROP `MsslTrgtPitchLingering`,
  DROP `MsslTrgtMouseLingering`,
  DROP `MsslTrgtEndOpacity`,
  DROP `MsslTrgtArcSpeed`,
  DROP `MsslTrgtArcRepeat`,
  DROP `MsslTrgtArcWidth`,
  DROP `MsslTrgtImpactRadius1`,
  DROP `MsslTrgtImpactRadius2`,
  DROP `MsslTrgtArcTexture`,
  DROP `MsslTrgtImpactTexture`,
  DROP `MsslTrgtImpactModel1`,
  DROP `MsslTrgtImpactModel2`,
  DROP `MsslTrgtImpactTexRadius`;

--
-- Table structure for table `world_map_area`
--
ALTER TABLE `world_map_area` MODIFY `Flags` int(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `LocBottom`;

--
-- Table structure for table `world_map_transforms`
--
ALTER TABLE `world_map_transforms` ADD `Priority` int(11) NOT NULL DEFAULT '0' AFTER `Flags`;
