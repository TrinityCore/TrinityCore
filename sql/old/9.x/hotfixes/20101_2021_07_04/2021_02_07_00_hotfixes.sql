--
-- Table structure for table `global_curve`
--
DROP TABLE IF EXISTS `global_curve`;
CREATE TABLE `global_curve` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `CurveID` int(11) NOT NULL DEFAULT '0',
  `Type` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
