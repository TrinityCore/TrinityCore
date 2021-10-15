--
-- Table structure for table `spell_reagents_currency`
--
DROP TABLE IF EXISTS `spell_reagents_currency`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_reagents_currency` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellID` int(11) NOT NULL DEFAULT '0',
  `CurrencyTypesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `CurrencyCount` smallint(5) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table data for table `spell_reagents_currency`
--
INSERT INTO `spell_reagents_currency`
SELECT hb.`RecordId`, CONV(HEX(SUBSTRING(hb.`Blob`, 1, 4)), 16, 10), CONV(HEX(SUBSTRING(hb.`Blob`, 5, 2)), 16, 10), CONV(HEX(SUBSTRING(hb.`Blob`, 7, 2)), 16, 10), hb.`VerifiedBuild` FROM `hotfix_blob` hb WHERE hb.`TableHash`=0x2049B60C AND hb.`locale`='enUS';

DELETE FROM `hotfix_blob` WHERE `TableHash`=0x2049B60C;
