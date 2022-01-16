--
-- Table structure for table `unit_condition`
--
DROP TABLE IF EXISTS `unit_condition`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `unit_condition` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable1` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable2` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable3` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable4` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable5` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable6` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable7` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Variable8` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `Op1` tinyint(4) NOT NULL DEFAULT '0',
  `Op2` tinyint(4) NOT NULL DEFAULT '0',
  `Op3` tinyint(4) NOT NULL DEFAULT '0',
  `Op4` tinyint(4) NOT NULL DEFAULT '0',
  `Op5` tinyint(4) NOT NULL DEFAULT '0',
  `Op6` tinyint(4) NOT NULL DEFAULT '0',
  `Op7` tinyint(4) NOT NULL DEFAULT '0',
  `Op8` tinyint(4) NOT NULL DEFAULT '0',
  `Value1` int(11) NOT NULL DEFAULT '0',
  `Value2` int(11) NOT NULL DEFAULT '0',
  `Value3` int(11) NOT NULL DEFAULT '0',
  `Value4` int(11) NOT NULL DEFAULT '0',
  `Value5` int(11) NOT NULL DEFAULT '0',
  `Value6` int(11) NOT NULL DEFAULT '0',
  `Value7` int(11) NOT NULL DEFAULT '0',
  `Value8` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
