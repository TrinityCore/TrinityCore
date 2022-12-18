--
-- Table structure for table `skill_line_x_trait_tree`
--
DROP TABLE IF EXISTS `skill_line_x_trait_tree`;
CREATE TABLE `skill_line_x_trait_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SkillLineID` int(11) NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_cond`
--
DROP TABLE IF EXISTS `trait_cond`;
CREATE TABLE `trait_cond` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CondType` int(11) NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `GrantedRanks` int(11) NOT NULL DEFAULT '0',
  `QuestID` int(11) NOT NULL DEFAULT '0',
  `AchievementID` int(11) NOT NULL DEFAULT '0',
  `SpecSetID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeGroupID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeID` int(11) NOT NULL DEFAULT '0',
  `TraitCurrencyID` int(11) NOT NULL DEFAULT '0',
  `SpentAmountRequired` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `RequiredLevel` int(11) NOT NULL DEFAULT '0',
  `FreeSharedStringID` int(11) NOT NULL DEFAULT '0',
  `SpendMoreSharedStringID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_cost`
--
DROP TABLE IF EXISTS `trait_cost`;
CREATE TABLE `trait_cost` (
  `InternalName` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Amount` int(11) NOT NULL DEFAULT '0',
  `TraitCurrencyID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_currency`
--
DROP TABLE IF EXISTS `trait_currency`;
CREATE TABLE `trait_currency` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `CurrencyTypesID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `Icon` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_currency_source`
--
DROP TABLE IF EXISTS `trait_currency_source`;
CREATE TABLE `trait_currency_source` (
  `Requirement` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCurrencyID` int(11) NOT NULL DEFAULT '0',
  `Amount` int(11) NOT NULL DEFAULT '0',
  `QuestID` int(11) NOT NULL DEFAULT '0',
  `AchievementID` int(11) NOT NULL DEFAULT '0',
  `PlayerLevel` int(11) NOT NULL DEFAULT '0',
  `TraitNodeEntryID` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_currency_source_locale`
--
DROP TABLE IF EXISTS `trait_currency_source_locale`;
CREATE TABLE `trait_currency_source_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Requirement_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
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
-- Table structure for table `trait_definition`
--
DROP TABLE IF EXISTS `trait_definition`;
CREATE TABLE `trait_definition` (
  `OverrideName` text,
  `OverrideSubtext` text,
  `OverrideDescription` text,
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `OverrideIcon` int(11) NOT NULL DEFAULT '0',
  `OverridesSpellID` int(11) NOT NULL DEFAULT '0',
  `VisibleSpellID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_definition_locale`
--
DROP TABLE IF EXISTS `trait_definition_locale`;
CREATE TABLE `trait_definition_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `OverrideName_lang` text,
  `OverrideSubtext_lang` text,
  `OverrideDescription_lang` text,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
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
-- Table structure for table `trait_definition_effect_points`
--
DROP TABLE IF EXISTS `trait_definition_effect_points`;
CREATE TABLE `trait_definition_effect_points` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitDefinitionID` int(11) NOT NULL DEFAULT '0',
  `EffectIndex` int(11) NOT NULL DEFAULT '0',
  `OperationType` int(11) NOT NULL DEFAULT '0',
  `CurveID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_edge`
--
DROP TABLE IF EXISTS `trait_edge`;
CREATE TABLE `trait_edge` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `VisualStyle` int(11) NOT NULL DEFAULT '0',
  `LeftTraitNodeID` int(11) NOT NULL DEFAULT '0',
  `RightTraitNodeID` int(11) NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node`
--
DROP TABLE IF EXISTS `trait_node`;
CREATE TABLE `trait_node` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `PosX` int(11) NOT NULL DEFAULT '0',
  `PosY` int(11) NOT NULL DEFAULT '0',
  `Type` tinyint(4) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_entry`
--
DROP TABLE IF EXISTS `trait_node_entry`;
CREATE TABLE `trait_node_entry` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitDefinitionID` int(11) NOT NULL DEFAULT '0',
  `MaxRanks` int(11) NOT NULL DEFAULT '0',
  `NodeEntryType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_entry_x_trait_cond`
--
DROP TABLE IF EXISTS `trait_node_entry_x_trait_cond`;
CREATE TABLE `trait_node_entry_x_trait_cond` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCondID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeEntryID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_entry_x_trait_cost`
--
DROP TABLE IF EXISTS `trait_node_entry_x_trait_cost`;
CREATE TABLE `trait_node_entry_x_trait_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitNodeEntryID` int(11) NOT NULL DEFAULT '0',
  `TraitCostID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_group`
--
DROP TABLE IF EXISTS `trait_node_group`;
CREATE TABLE `trait_node_group` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_group_x_trait_cond`
--
DROP TABLE IF EXISTS `trait_node_group_x_trait_cond`;
CREATE TABLE `trait_node_group_x_trait_cond` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCondID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeGroupID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_group_x_trait_cost`
--
DROP TABLE IF EXISTS `trait_node_group_x_trait_cost`;
CREATE TABLE `trait_node_group_x_trait_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitNodeGroupID` int(11) NOT NULL DEFAULT '0',
  `TraitCostID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_group_x_trait_node`
--
DROP TABLE IF EXISTS `trait_node_group_x_trait_node`;
CREATE TABLE `trait_node_group_x_trait_node` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitNodeGroupID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeID` int(11) NOT NULL DEFAULT '0',
  `Index` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_x_trait_cond`
--
DROP TABLE IF EXISTS `trait_node_x_trait_cond`;
CREATE TABLE `trait_node_x_trait_cond` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCondID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_x_trait_cost`
--
DROP TABLE IF EXISTS `trait_node_x_trait_cost`;
CREATE TABLE `trait_node_x_trait_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitNodeID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCostID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_node_x_trait_node_entry`
--
DROP TABLE IF EXISTS `trait_node_x_trait_node_entry`;
CREATE TABLE `trait_node_x_trait_node_entry` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitNodeID` int(11) NOT NULL DEFAULT '0',
  `TraitNodeEntryID` int(11) NOT NULL DEFAULT '0',
  `Index` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_tree`
--
DROP TABLE IF EXISTS `trait_tree`;
CREATE TABLE `trait_tree` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitSystemID` int(11) NOT NULL DEFAULT '0',
  `Unused1000_1` int(11) NOT NULL DEFAULT '0',
  `FirstTraitNodeID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(11) NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `Unused1000_2` float NOT NULL DEFAULT '0',
  `Unused1000_3` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_tree_loadout`
--
DROP TABLE IF EXISTS `trait_tree_loadout`;
CREATE TABLE `trait_tree_loadout` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `ChrSpecializationID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;


--
-- Table structure for table `trait_tree_loadout_entry`
--
DROP TABLE IF EXISTS `trait_tree_loadout_entry`;
CREATE TABLE `trait_tree_loadout_entry` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitTreeLoadoutID` int(11) NOT NULL DEFAULT '0',
  `SelectedTraitNodeID` int(11) NOT NULL DEFAULT '0',
  `SelectedTraitNodeEntryID` int(11) NOT NULL DEFAULT '0',
  `NumPoints` int(11) NOT NULL DEFAULT '0',
  `OrderIndex` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_tree_x_trait_cost`
--
DROP TABLE IF EXISTS `trait_tree_x_trait_cost`;
CREATE TABLE `trait_tree_x_trait_cost` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitTreeID` int(10) unsigned NOT NULL DEFAULT '0',
  `TraitCostID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `trait_tree_x_trait_currency`
--
DROP TABLE IF EXISTS `trait_tree_x_trait_currency`;
CREATE TABLE `trait_tree_x_trait_currency` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Index` int(11) NOT NULL DEFAULT '0',
  `TraitTreeID` int(11) NOT NULL DEFAULT '0',
  `TraitCurrencyID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
