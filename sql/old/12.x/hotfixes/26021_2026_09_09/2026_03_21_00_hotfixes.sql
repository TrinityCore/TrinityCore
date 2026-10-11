--
-- Table structure for table `transmog_outfit_entry`
--
DROP TABLE IF EXISTS `transmog_outfit_entry`;
CREATE TABLE `transmog_outfit_entry` (
  `Cost` bigint unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `Source` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SetType` tinyint unsigned NOT NULL DEFAULT '0',
  `OverrideCostModifier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_outfit_entry_locale`
--
DROP TABLE IF EXISTS `transmog_outfit_entry_locale`;
CREATE TABLE `transmog_outfit_entry_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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
-- Table structure for table `transmog_outfit_slot_info`
--
DROP TABLE IF EXISTS `transmog_outfit_slot_info`;
CREATE TABLE `transmog_outfit_slot_info` (
  `InventorySlotName` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `TransmogOutfitSlotEnum` tinyint NOT NULL DEFAULT '0',
  `InventorySlotEnum` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `Unused1200` tinyint unsigned NOT NULL DEFAULT '0',
  `TransmogCollectionType` tinyint unsigned NOT NULL DEFAULT '0',
  `SecondarySlotID` int NOT NULL DEFAULT '0',
  `InventorySlotID` int NOT NULL DEFAULT '0',
  `UnassignedAtlasID` int NOT NULL DEFAULT '0',
  `UnassignedDisplayAtlasID` int NOT NULL DEFAULT '0',
  `ItemCostMultiplier` float NOT NULL DEFAULT '0',
  `IllusionCostMultiplier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_outfit_slot_option`
--
DROP TABLE IF EXISTS `transmog_outfit_slot_option`;
CREATE TABLE `transmog_outfit_slot_option` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `OptionEnum` tinyint unsigned NOT NULL DEFAULT '0',
  `TransmogOutfitSlotInfoID` int unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `SecondaryOptionID` int NOT NULL DEFAULT '0',
  `ItemCostMultiplier` float NOT NULL DEFAULT '0',
  `IllusionCostMultiplier` float NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_outfit_slot_option_locale`
--
DROP TABLE IF EXISTS `transmog_outfit_slot_option_locale`;
CREATE TABLE `transmog_outfit_slot_option_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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
-- Table structure for table `transmog_situation`
--
DROP TABLE IF EXISTS `transmog_situation`;
CREATE TABLE `transmog_situation` (
  `Name` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `SituationEnum` tinyint NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `TransmogSituationGroupID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_situation_locale`
--
DROP TABLE IF EXISTS `transmog_situation_locale`;
CREATE TABLE `transmog_situation_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
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
-- Table structure for table `transmog_situation_group`
--
DROP TABLE IF EXISTS `transmog_situation_group`;
CREATE TABLE `transmog_situation_group` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `TransmogSituationTriggerID` int unsigned NOT NULL DEFAULT '0',
  `OrderIndex` int NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_situation_trigger`
--
DROP TABLE IF EXISTS `transmog_situation_trigger`;
CREATE TABLE `transmog_situation_trigger` (
  `Name` text,
  `Description` text,
  `ID` int unsigned NOT NULL DEFAULT '0',
  `TriggerEnum` tinyint unsigned NOT NULL DEFAULT '0',
  `Flags` int NOT NULL DEFAULT '0',
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `transmog_situation_trigger_locale`
--
DROP TABLE IF EXISTS `transmog_situation_trigger_locale`;
CREATE TABLE `transmog_situation_trigger_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Description_lang` text,
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
