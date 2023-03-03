/*Table structure for table `garr_mission` */

DROP TABLE IF EXISTS `garr_mission`;

CREATE TABLE `garr_mission` (
  `Name` text COLLATE utf8mb4_unicode_ci,
  `Description` text COLLATE utf8mb4_unicode_ci,
  `Location` text COLLATE utf8mb4_unicode_ci,
  `MapPos1` float NOT NULL DEFAULT '0',
  `MapPos2` float NOT NULL DEFAULT '0',
  `WorldPos1` float NOT NULL DEFAULT '0',
  `WorldPos2` float NOT NULL DEFAULT '0',
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `GarrTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrMissionTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `GarrFollowerTypeID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MaxFollowers` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `MissionCost` int(10) unsigned NOT NULL DEFAULT '0',
  `MissionCostCurrencyTypesID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `OfferedGarrMissionTextureID` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `UiTextureKitID` smallint(5) unsigned NOT NULL DEFAULT '0',
  `EnvGarrMechanicID` int(10) unsigned NOT NULL DEFAULT '0',
  `EnvGarrMechanicTypeID` int(11) NOT NULL DEFAULT '0',
  `PlayerConditionID` int(10) unsigned NOT NULL DEFAULT '0',
  `TargetLevel` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `TargetItemLevel` smallint(5) unsigned NOT NULL DEFAULT '0',
  `MissionDuration` int(11) NOT NULL DEFAULT '0',
  `TravelDuration` int(11) NOT NULL DEFAULT '0',
  `OfferDuration` int(10) unsigned NOT NULL DEFAULT '0',
  `BaseCompletionChance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `BaseFollowerXP` int(10) unsigned NOT NULL DEFAULT '0',
  `OvermaxRewardPackID` int(10) unsigned NOT NULL DEFAULT '0',
  `FollowerDeathChance` tinyint(3) unsigned NOT NULL DEFAULT '0',
  `AreaID` int(10) unsigned NOT NULL DEFAULT '0',
  `Flags` int(10) unsigned NOT NULL DEFAULT '0',
  `AutoMissionScalar` float NOT NULL DEFAULT '0',
  `AutoMissionScalarCurveID` int(11) NOT NULL DEFAULT '0',
  `AutoCombatantEnvCasterID` int(11) NOT NULL DEFAULT '0',
  `GarrMissionSetID` int(11) NOT NULL DEFAULT '0',
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`,`VerifiedBuild`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

/*Data for the table `garr_mission` */

/*Table structure for table `garr_mission_locale` */

DROP TABLE IF EXISTS `garr_mission_locale`;

CREATE TABLE `garr_mission_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `locale` varchar(4) COLLATE utf8mb4_unicode_ci NOT NULL,
  `Name_lang` text COLLATE utf8mb4_unicode_ci,
  `Description_lang` text COLLATE utf8mb4_unicode_ci,
  `Location_lang` text COLLATE utf8mb4_unicode_ci,
  `VerifiedBuild` int(11) NOT NULL DEFAULT '0',
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

/*Data for the table `garr_mission_locale` */