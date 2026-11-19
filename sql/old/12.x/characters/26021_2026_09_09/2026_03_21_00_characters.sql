ALTER TABLE `characters`
  ADD `transmogOutfitEquippedId` int NOT NULL DEFAULT 2 AFTER `personalTabardBackgroundColor`,
  ADD `transmogOutfitLocked` tinyint(1) NOT NULL DEFAULT 0 AFTER `transmogOutfitEquippedId`;

--
-- Table structure for table `character_transmog_outfit`
--
DROP TABLE IF EXISTS `character_transmog_outfit`;
CREATE TABLE `character_transmog_outfit` (
  `guid` bigint NOT NULL,
  `transmogOutfitId` int NOT NULL,
  `name` varchar(16) COLLATE utf8mb4_unicode_ci NOT NULL,
  `icon` int NOT NULL,
  `situationsEnabled` tinyint(1) NOT NULL,
  PRIMARY KEY (`guid`,`transmogOutfitId`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `character_transmog_outfit_situation`
--
DROP TABLE IF EXISTS `character_transmog_outfit_situation`;
CREATE TABLE `character_transmog_outfit_situation` (
  `guid` bigint NOT NULL,
  `transmogOutfitId` int NOT NULL,
  `situationID` int NOT NULL,
  `specID` int NOT NULL,
  `loadoutID` int NOT NULL,
  `equipmentSetID` int NOT NULL,
  PRIMARY KEY (`guid`,`transmogOutfitId`,`situationID`,`specID`,`loadoutID`,`equipmentSetID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Table structure for table `character_transmog_outfit_slot`
--
DROP TABLE IF EXISTS `character_transmog_outfit_slot`;
CREATE TABLE `character_transmog_outfit_slot` (
  `guid` bigint NOT NULL,
  `transmogOutfitId` int NOT NULL,
  `slot` tinyint NOT NULL,
  `slotOption` tinyint NOT NULL,
  `itemModifiedAppearanceID` int NOT NULL,
  `appearanceDisplayType` tinyint NOT NULL,
  `spellItemEnchantmentID` int NOT NULL,
  `illusionDisplayType` tinyint NOT NULL,
  `flags` int NOT NULL,
  PRIMARY KEY (`guid`,`transmogOutfitId`,`slot`,`slotOption`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
