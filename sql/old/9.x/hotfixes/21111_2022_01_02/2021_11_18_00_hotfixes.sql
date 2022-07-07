--
-- Table structure for table `spell_visual`
--
DROP TABLE IF EXISTS `spell_visual`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `MissileCastOffset1` float NOT NULL DEFAULT '0',
  `MissileCastOffset2` float NOT NULL DEFAULT '0',
  `MissileCastOffset3` float NOT NULL DEFAULT '0',
  `MissileImpactOffset1` float NOT NULL DEFAULT '0',
  `MissileImpactOffset2` float NOT NULL DEFAULT '0',
  `MissileImpactOffset3` float NOT NULL DEFAULT '0',
  `AnimEventSoundID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(11) NOT NULL DEFAULT '0',
  `MissileAttachment` tinyint(4) NOT NULL DEFAULT '0',
  `MissileDestinationAttachment` tinyint(4) NOT NULL DEFAULT '0',
  `MissileCastPositionerID` int(10) unsigned NOT NULL DEFAULT '0',
  `MissileImpactPositionerID` int(10) unsigned NOT NULL DEFAULT '0',
  `MissileTargetingKit` int(11) NOT NULL DEFAULT '0',
  `HostileSpellVisualID` int(10) unsigned NOT NULL DEFAULT '0',
  `CasterSpellVisualID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualMissileSetID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `DamageNumberDelay` smallint(5) unsigned NOT NULL DEFAULT '0',
  `LowViolenceSpellVisualID` int(10) unsigned NOT NULL DEFAULT '0',
  `RaidSpellVisualMissileSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `ReducedUnexpectedCameraMovementSpellVisualID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_visual_effect_name`
--
DROP TABLE IF EXISTS `spell_visual_effect_name`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual_effect_name` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `ModelFileDataID` int(11) NOT NULL DEFAULT '0',
  `BaseMissileSpeed` float NOT NULL DEFAULT '0',
  `Scale` float NOT NULL DEFAULT '0',
  `MinAllowedScale` float NOT NULL DEFAULT '0',
  `MaxAllowedScale` float NOT NULL DEFAULT '0',
  `Alpha` float NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `TextureFileDataID` int(11) NOT NULL DEFAULT '0',
  `EffectRadius` float NOT NULL DEFAULT '0',
  `Type` int(10) unsigned NOT NULL DEFAULT '0',
  `GenericID` int(11) NOT NULL DEFAULT '0',
  `RibbonQualityID` int(10) unsigned NOT NULL DEFAULT '0',
  `DissolveEffectID` int(11) NOT NULL DEFAULT '0',
  `ModelPosition` int(11) NOT NULL DEFAULT '0',
  `Unknown901` tinyint(4) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `spell_visual_missile`
--
DROP TABLE IF EXISTS `spell_visual_missile`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `spell_visual_missile` (
  `CastOffset1` float NOT NULL DEFAULT '0',
  `CastOffset2` float NOT NULL DEFAULT '0',
  `CastOffset3` float NOT NULL DEFAULT '0',
  `ImpactOffset1` float NOT NULL DEFAULT '0',
  `ImpactOffset2` float NOT NULL DEFAULT '0',
  `ImpactOffset3` float NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellVisualEffectNameID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `SoundEntriesID` int(10) unsigned NOT NULL DEFAULT '0',
  `Attachment` tinyint(4) NOT NULL DEFAULT '0',
  `DestinationAttachment` tinyint(4) NOT NULL DEFAULT '0',
  `CastPositionerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `ImpactPositionerID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `FollowGroundHeight` int(11) NOT NULL DEFAULT '0',
  `FollowGroundDropSpeed` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowGroundApproach` smallint(5) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `SpellMissileMotionID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `AnimKitID` int(10) unsigned NOT NULL DEFAULT '0',
  `ClutterLevel` tinyint(4) NOT NULL DEFAULT '0',
  `DecayTimeAfterImpact` int(11) NOT NULL DEFAULT '0',
  `SpellVisualMissileSetID` int(10) unsigned NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
