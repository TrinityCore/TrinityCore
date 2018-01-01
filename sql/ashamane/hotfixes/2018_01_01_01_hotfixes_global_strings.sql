DROP TABLE IF EXISTS `global_strings`;
CREATE TABLE `global_strings`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `StringName` TEXT,
    `StringValue` TEXT,
    `Unknown` TINYINT(3) UNSIGNED NOT NULL DEFAULT 0,
    `VerifiedBuild` SMALLINT(6) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`)
); 

DROP TABLE IF EXISTS `global_strings_locale`;
CREATE TABLE `global_strings_locale`(
    `ID` INT(10) UNSIGNED NOT NULL DEFAULT 0,
    `locale` VARCHAR(4) NOT NULL,
    `StringValue_lang` TEXT, 
    `VerifiedBuild` SMALLINT(6) NOT NULL DEFAULT 0,
    PRIMARY KEY (`ID`, `locale`)
); 
