--
-- Table structure for table `item_display_info`
--

DROP TABLE IF EXISTS `item_display_info`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `item_display_info` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ItemVisual` int(11) NOT NULL DEFAULT '0',
  `ParticleColorID` int(11) NOT NULL DEFAULT '0',
  `ItemRangedDisplayInfoID` int(10) unsigned NOT NULL DEFAULT '0',
  `OverrideSwooshSoundKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `SheatheTransformMatrixID` int(11) NOT NULL DEFAULT '0',
  `StateSpellVisualKitID` int(11) NOT NULL DEFAULT '0',
  `SheathedSpellVisualKitID` int(11) NOT NULL DEFAULT '0',
  `UnsheathedSpellVisualKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `ModelResourcesID1` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelResourcesID2` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelMaterialResourcesID1` int(11) NOT NULL DEFAULT '0',
  `ModelMaterialResourcesID2` int(11) NOT NULL DEFAULT '0',
  `Field_8_2_0_30080_0111` int(11) NOT NULL DEFAULT '0',
  `Field_8_2_0_30080_0112` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup1` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup2` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup3` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup4` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup5` int(11) NOT NULL DEFAULT '0',
  `GeosetGroup6` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup1` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup2` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup3` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup4` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup5` int(11) NOT NULL DEFAULT '0',
  `AttachmentGeosetGroup6` int(11) NOT NULL DEFAULT '0',
  `HelmetGeosetVis1` int(11) NOT NULL DEFAULT '0',
  `HelmetGeosetVis2` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping data for table `item_display_info`
--

LOCK TABLES `item_display_info` WRITE;
/*!40000 ALTER TABLE `item_display_info` DISABLE KEYS */;
/*!40000 ALTER TABLE `item_display_info` ENABLE KEYS */;
UNLOCK TABLES;

