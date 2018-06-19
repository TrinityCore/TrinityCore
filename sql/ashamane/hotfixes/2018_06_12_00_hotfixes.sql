DROP TABLE IF EXISTS `map_challenge_mode`;
CREATE TABLE `map_challenge_mode`(
    `Name` TEXT NOT NULL,
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `MapID` SMALLINT(5) UNSIGNED NOT NULL DEFAULT 0,
    `CriteriaCount1` SMALLINT(5) NOT NULL DEFAULT 0,
    `CriteriaCount2` SMALLINT(5) NOT NULL DEFAULT 0,
    `CriteriaCount3` SMALLINT(5) NOT NULL DEFAULT 0,
    `Flags` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `VerifiedBuild` SMALLINT(6) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
); 

DROP TABLE IF EXISTS `map_challenge_mode_locale`;
CREATE TABLE `map_challenge_mode_locale`(
    `ID` INT(10) UNSIGNED NOT NULL,
    `locale` VARCHAR(4) NOT NULL,
    `Name_lang` TEXT NOT NULL,
    `VerifiedBuild` SMALLINT(6) UNSIGNED NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`, `locale`)
); 
