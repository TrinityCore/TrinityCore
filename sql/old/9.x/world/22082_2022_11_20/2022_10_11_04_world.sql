--
-- Table structure for table `gossip_menu_option_addon`
--
DROP TABLE IF EXISTS `gossip_menu_option_addon`;
CREATE TABLE `gossip_menu_option_addon` (
  `MenuID` int unsigned NOT NULL DEFAULT '0',
  `OptionID` int unsigned NOT NULL DEFAULT '0',
  `GarrTalentTreeID` int DEFAULT NULL,
  `VerifiedBuild` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`MenuID`,`OptionID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
