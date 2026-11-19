--
-- Table structure for table `chat_channels`
--
DROP TABLE IF EXISTS `chat_channels`;
CREATE TABLE `chat_channels` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Shortcut` text,
  `FactionGroup` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chat_channels_locale`
--
DROP TABLE IF EXISTS `chat_channels_locale`;
CREATE TABLE `chat_channels_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Shortcut_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_specialization`
--
DROP TABLE IF EXISTS `chr_specialization`;
CREATE TABLE `chr_specialization` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MasterySpellID1` int(10) unsigned NOT NULL DEFAULT '0',
  `MasterySpellID2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimReplacementSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `Name2` text,
  `Description` text,
  `BackgroundFile` text,
  `SpellIconID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ClassID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `OrderIndex` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PetTalentType` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Role` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `PrimaryStatOrder` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `chr_specialization_locale`
--

DROP TABLE IF EXISTS `chr_specialization_locale`;
CREATE TABLE `chr_specialization_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `Name2_lang` text,
  `Description_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `creature_display_info_extra`
--
ALTER TABLE `creature_display_info_extra`
  DROP `NPCItemDisplay1`,
  DROP `NPCItemDisplay2`,
  DROP `NPCItemDisplay3`,
  DROP `NPCItemDisplay4`,
  DROP `NPCItemDisplay5`,
  DROP `NPCItemDisplay6`,
  DROP `NPCItemDisplay7`,
  DROP `NPCItemDisplay8`,
  DROP `NPCItemDisplay9`,
  DROP `NPCItemDisplay10`;

--
-- Table structure for table `emotes`
--
DROP TABLE IF EXISTS `emotes`;
CREATE TABLE `emotes` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteSlashCommand` text,
  `SpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `EmoteFlags` int(10) unsigned NOT NULL DEFAULT '0',
  `AnimID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteSoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EmoteSpecProc` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `EmoteSpecProcParam` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;


--
-- Table structure for table `gameobject_display_info`
--
ALTER TABLE `gameobject_display_info`
  DROP `Sound1`,
  DROP `Sound2`,
  DROP `Sound3`,
  DROP `Sound4`,
  DROP `Sound5`,
  DROP `Sound6`,
  DROP `Sound7`,
  DROP `Sound8`,
  DROP `Sound9`,
  DROP `Sound10`;

--
-- Table structure for table `garr_class_spec`
--
ALTER TABLE `garr_class_spec` ADD COLUMN `Unknown700` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `GarrFollItemSetID`;

--
-- Table structure for table `gem_properties`
--
DROP TABLE IF EXISTS `gem_properties`;
CREATE TABLE `gem_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `EnchantID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MinItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MaxCountInv` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxCountItem` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `glyph_properties`
--
DROP TABLE IF EXISTS `glyph_properties`;
CREATE TABLE `glyph_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellIconID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GlyphExclusiveCategoryID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_set`
--
DROP TABLE IF EXISTS `item_set`;
CREATE TABLE `item_set` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Name` text,
  `ItemID1` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID3` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID4` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID5` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID6` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID7` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID8` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID9` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID10` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID11` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID12` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID13` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID14` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID15` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID16` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemID17` int(10) unsigned NOT NULL DEFAULT '0',
  `RequiredSkillRank` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RequiredSkill` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `item_set_locale`
--
DROP TABLE IF EXISTS `item_set_locale`;
CREATE TABLE `item_set_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Name_lang` text,
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `lock`
--
DROP TABLE IF EXISTS `lock`;
CREATE TABLE `lock` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Index1` int(10) unsigned NOT NULL DEFAULT '0',
  `Index2` int(10) unsigned NOT NULL DEFAULT '0',
  `Index3` int(10) unsigned NOT NULL DEFAULT '0',
  `Index4` int(10) unsigned NOT NULL DEFAULT '0',
  `Index5` int(10) unsigned NOT NULL DEFAULT '0',
  `Index6` int(10) unsigned NOT NULL DEFAULT '0',
  `Index7` int(10) unsigned NOT NULL DEFAULT '0',
  `Index8` int(10) unsigned NOT NULL DEFAULT '0',
  `Skill1` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill2` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill3` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill4` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill5` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill6` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill7` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Skill8` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Type1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Type8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Action8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `pvp_difficulty`
--

DROP TABLE IF EXISTS `pvp_difficulty`;
CREATE TABLE `pvp_difficulty` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MapID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `BracketID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MinLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `spell_levels`
--
ALTER TABLE `spell_levels` ADD COLUMN `MaxUsableLevel` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `DifficultyID`;

--
-- Table structure for table `summon_properties`
--
DROP TABLE IF EXISTS `summon_properties`;
CREATE TABLE `summon_properties` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Category` int(10) unsigned NOT NULL DEFAULT '0',
  `Faction` int(10) unsigned NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `Slot` int(11) NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

--
-- Table structure for table `vehicle_seat`
--
DROP TABLE IF EXISTS `vehicle_seat`;
CREATE TABLE `vehicle_seat` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags1` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags2` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags3` int(10) unsigned NOT NULL DEFAULT '0',
  `AttachmentOffsetX` float NOT NULL DEFAULT '0',
  `AttachmentOffsetY` float NOT NULL DEFAULT '0',
  `AttachmentOffsetZ` float NOT NULL DEFAULT '0',
  `EnterPreDelay` float NOT NULL DEFAULT '0',
  `EnterSpeed` float NOT NULL DEFAULT '0',
  `EnterGravity` float NOT NULL DEFAULT '0',
  `EnterMinDuration` float NOT NULL DEFAULT '0',
  `EnterMaxDuration` float NOT NULL DEFAULT '0',
  `EnterMinArcHeight` float NOT NULL DEFAULT '0',
  `EnterMaxArcHeight` float NOT NULL DEFAULT '0',
  `ExitPreDelay` float NOT NULL DEFAULT '0',
  `ExitSpeed` float NOT NULL DEFAULT '0',
  `ExitGravity` float NOT NULL DEFAULT '0',
  `ExitMinDuration` float NOT NULL DEFAULT '0',
  `ExitMaxDuration` float NOT NULL DEFAULT '0',
  `ExitMinArcHeight` float NOT NULL DEFAULT '0',
  `ExitMaxArcHeight` float NOT NULL DEFAULT '0',
  `PassengerYaw` float NOT NULL DEFAULT '0',
  `PassengerPitch` float NOT NULL DEFAULT '0',
  `PassengerRoll` float NOT NULL DEFAULT '0',
  `VehicleEnterAnimDelay` float NOT NULL DEFAULT '0',
  `VehicleExitAnimDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDelay` float NOT NULL DEFAULT '0',
  `CameraEnteringDuration` float NOT NULL DEFAULT '0',
  `CameraExitingDelay` float NOT NULL DEFAULT '0',
  `CameraExitingDuration` float NOT NULL DEFAULT '0',
  `CameraOffsetX` float NOT NULL DEFAULT '0',
  `CameraOffsetY` float NOT NULL DEFAULT '0',
  `CameraOffsetZ` float NOT NULL DEFAULT '0',
  `CameraPosChaseRate` float NOT NULL DEFAULT '0',
  `CameraFacingChaseRate` float NOT NULL DEFAULT '0',
  `CameraEnteringZoom` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMin` float NOT NULL DEFAULT '0',
  `CameraSeatZoomMax` float NOT NULL DEFAULT '0',
  `UISkinFileDataID` int(10) unsigned NOT NULL DEFAULT '0',
  `EnterAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `EnterAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `RideAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `RideAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `RideUpperAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `RideUpperAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimStart` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `ExitAnimEnd` smallint(6) NOT NULL DEFAULT '0',
  `VehicleEnterAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleExitAnim` smallint(6) NOT NULL DEFAULT '0',
  `VehicleRideAnimLoop` smallint(6) NOT NULL DEFAULT '0',
  `EnterUISoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ExitUISoundID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `RideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleEnterAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleRideAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VehicleExitAnimKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CameraModeID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AttachmentID` tinyint(4) NOT NULL DEFAULT '0',
  `PassengerAttachmentID` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleEnterAnimBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleExitAnimBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleRideAnimLoopBone` tinyint(4) NOT NULL DEFAULT '0',
  `VehicleAbilityDisplay` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` smallint(6) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;
