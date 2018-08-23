DROP TABLE IF EXISTS `garr_mission`;
CREATE TABLE `garr_mission` (
    `Name` text NOT NULL,
    `Description` text NOT NULL,
    `Location` text NOT NULL,
    `MissionDuration` int(10) unsigned NOT NULL,
    `OfferDuration` int(10) unsigned NOT NULL,
    `MapPosX` float NOT NULL,
    `MapPosY` float NOT NULL,
    `WorldPosX` float NOT NULL,
    `WorldPosY` float NOT NULL,
    `TargetItemLevel` smallint(5) unsigned NOT NULL,
    `UiTextureKitId` smallint(5) unsigned NOT NULL,
    `MissionCostCurrencyTypesId` smallint(5) unsigned NOT NULL,
    `TargetLevel` tinyint(3) unsigned NOT NULL,
    `EnvGarrMechanicTypeId` tinyint(3) unsigned NOT NULL,
    `MaxFollowers` tinyint(3) unsigned NOT NULL,
    `OfferedGarrMissionTextureId` tinyint(3) unsigned NOT NULL,
    `GarrMissionTypeId` tinyint(3) unsigned NOT NULL,
    `GarrFollowerTypeId` tinyint(3) unsigned NOT NULL,
    `BaseCompletionChance` tinyint(3) unsigned NOT NULL,
    `FollowerDeathChance` tinyint(3) unsigned NOT NULL,
    `GarrTypeID` tinyint(3) unsigned NOT NULL,
    `ID` int(10) unsigned NOT NULL,
    `TravelDuration` int(10) unsigned NOT NULL,
    `PlayerConditionId` int(10) unsigned NOT NULL,
    `SubCategory1` int(10) unsigned NOT NULL,
    `MissionCost` int(10) unsigned NOT NULL,
    `Flags` int(10) unsigned NOT NULL,
    `BaseFollowerXP` int(10) unsigned NOT NULL,
    `AreaId` int(10) unsigned NOT NULL,
    `OvermaxRewardPackId` int(10) unsigned NOT NULL,
    `EnvGarrMechanicId` int(10) unsigned NOT NULL,
    `VerifiedBuild` smallint(6) unsigned NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `garr_mission_locale`;
CREATE TABLE `garr_mission_locale` (
    `ID` int(10) unsigned NOT NULL,
    `locale` varchar(4) NOT NULL,
    `Name_lang` text NOT NULL,
    `Description_lang` text NOT NULL,
    `Location_lang` text NOT NULL,
    `VerifiedBuild` smallint(6) unsigned NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `garr_follower_type`;
CREATE TABLE `garr_follower_type`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `MaxItemLevel` SMALLINT(6) UNSIGNED NOT NULL DEFAULT 0,
    `MaxFollowers` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `MaxFollowerBuildingType` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `GarrTypeId` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `LevelRangeBias` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `ItemLevelRangeBias` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `Flags` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `VerifiedBuild` smallint(6) unsigned NOT NULL,
    PRIMARY KEY (`ID`)
);

DROP TABLE IF EXISTS `garr_follower_level_xp`;
CREATE TABLE `garr_follower_level_xp`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `XpToNextLevel` SMALLINT(5) UNSIGNED,
    `ShipmentXP` SMALLINT(5) UNSIGNED,
    `FollowerLevel` TINYINT(3) UNSIGNED,
    `GarrFollowerTypeId` TINYINT(3) UNSIGNED,
    `VerifiedBuild` smallint(6) unsigned NOT NULL,
    PRIMARY KEY (`ID`)
); 

DROP TABLE IF EXISTS `garr_follower_quality`;
CREATE TABLE `garr_follower_quality`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `XpToNextQuality` INT(10) UNSIGNED NOT NULL,
    `ShipmentXP` SMALLINT(5) UNSIGNED NOT NULL,
    `Quality` TINYINT(3) UNSIGNED NOT NULL,
    `AbilityCount` TINYINT(3) UNSIGNED NOT NULL,
    `TraitCount` TINYINT(3) UNSIGNED NOT NULL,
    `GarrFollowerTypeId` TINYINT(3) UNSIGNED NOT NULL,
    `ClassSpecId` INT(10) UNSIGNED NOT NULL,
    `VerifiedBuild` smallint(6) unsigned NOT NULL,
    PRIMARY KEY (`ID`)
); 
