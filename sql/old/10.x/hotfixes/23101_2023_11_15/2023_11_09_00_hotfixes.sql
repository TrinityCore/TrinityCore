ALTER TABLE `area_trigger` MODIFY `PhaseUseFlags` int NOT NULL DEFAULT 0 AFTER `ContinentID`;

ALTER TABLE `chr_customization_display_info` ADD `BarberShopCameraZoomOffset` float NOT NULL DEFAULT 0 AFTER `BarberShopHeightOffset`;

ALTER TABLE `chr_customization_element` ADD `ChrCustGeoComponentLinkID` int NOT NULL DEFAULT 0 AFTER `ParticleColorID`;

ALTER TABLE `conversation_line` ADD `Unused1020` int unsigned NOT NULL DEFAULT 0 AFTER `BroadcastTextID`;

ALTER TABLE `curve_point` MODIFY `CurveID` int unsigned NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `mount` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `MountTypeID`;

ALTER TABLE `mount_capability` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `movie` MODIFY `SubtitleFileFormat` int unsigned NOT NULL DEFAULT 0 AFTER `SubtitleFileDataID`;

ALTER TABLE `phase` MODIFY `Flags` int NOT NULL DEFAULT 0 AFTER `ID`;

ALTER TABLE `player_condition` MODIFY `PhaseUseFlags` int NOT NULL DEFAULT 0 AFTER `MaxAvgEquippedItemLevel`;

--
-- Table structure for table `server_messages`
--
DROP TABLE IF EXISTS `server_messages`;
CREATE TABLE `server_messages` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `Text` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `server_messages_locale`
--
DROP TABLE IF EXISTS `server_messages_locale`;
CREATE TABLE `server_messages_locale` (
  `ID` int unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) NOT NULL,
  `Text_lang` text,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`locale`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci
/*!50500 PARTITION BY LIST  COLUMNS(locale)
(PARTITION deDE VALUES IN ('deDE') ENGINE = InnoDB,
 PARTITION esES VALUES IN ('esES') ENGINE = InnoDB,
 PARTITION esMX VALUES IN ('esMX') ENGINE = InnoDB,
 PARTITION frFR VALUES IN ('frFR') ENGINE = InnoDB,
 PARTITION itIT VALUES IN ('itIT') ENGINE = InnoDB,
 PARTITION koKR VALUES IN ('koKR') ENGINE = InnoDB,
 PARTITION ptBR VALUES IN ('ptBR') ENGINE = InnoDB,
 PARTITION ruRU VALUES IN ('ruRU') ENGINE = InnoDB,
 PARTITION zhCN VALUES IN ('zhCN') ENGINE = InnoDB,
 PARTITION zhTW VALUES IN ('zhTW') ENGINE = InnoDB) */;

ALTER TABLE `spell_shapeshift_form` CHANGE `CreatureDisplayID1` `CreatureDisplayID` int unsigned NOT NULL DEFAULT 0 AFTER `Name`;

ALTER TABLE `ui_map` MODIFY `System` tinyint NOT NULL DEFAULT 0 AFTER `Flags`;
