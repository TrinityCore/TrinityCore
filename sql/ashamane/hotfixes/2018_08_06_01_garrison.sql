DROP TABLE IF EXISTS `garr_follower_level_xp`;
CREATE TABLE `garr_follower_level_xp`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `XpToNextLevel` SMALLINT(5) UNSIGNED,
    `ShipmentXP` SMALLINT(5) UNSIGNED,
    `FollowerLevel` TINYINT(3) UNSIGNED,
    `GarrFollowerTypeId` TINYINT(3) UNSIGNED,
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
    PRIMARY KEY (`ID`)
); 
