DROP TABLE IF EXISTS `item_template_locale`;
CREATE TABLE IF NOT EXISTS `item_template_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `Description` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "koKR", `name_loc1`, `description_loc1`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc1) > 0 OR LENGTH(description_loc1) > 0);

-- frFR
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "frFR", `name_loc2`, `description_loc2`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc2) > 0 OR LENGTH(description_loc2) > 0);

-- deDE
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "deDE", `name_loc3`, `description_loc3`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc3) > 0 OR LENGTH(description_loc3) > 0);

-- zhCN
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "zhCN", `name_loc4`, `description_loc4`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc4) > 0 OR LENGTH(description_loc4) > 0);

-- zhTW
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "zhTW", `name_loc5`, `description_loc5`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc5) > 0 OR LENGTH(description_loc5) > 0);

-- esES
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "esES", `name_loc6`, `description_loc6`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc6) > 0 OR LENGTH(description_loc6) > 0);

-- esMX
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "esMX", `name_loc7`, `description_loc7`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc7) > 0 OR LENGTH(description_loc7) > 0);

-- ruRU
INSERT INTO `item_template_locale` (`ID`, `locale`, `Name`, `Description`, `VerifiedBuild`)
  (SELECT `entry`, "ruRU", `name_loc8`, `description_loc8`, `VerifiedBuild` FROM `locales_item` WHERE LENGTH(name_loc8) > 0 OR LENGTH(description_loc8) > 0);

DROP TABLE IF EXISTS `locales_item`;

DROP TABLE IF EXISTS `item_set_names_locale`;
CREATE TABLE IF NOT EXISTS `item_set_names_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "koKR", `name_loc1`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc1) > 0);

-- frFR
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "frFR", `name_loc2`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc2) > 0);

-- deDE
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "deDE", `name_loc3`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc3) > 0);

-- zhCN
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "zhCN", `name_loc4`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc4) > 0);

-- zhTW
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "zhTW", `name_loc5`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc5) > 0);

-- esES
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "esES", `name_loc6`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc6) > 0);

-- esMX
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "esMX", `name_loc7`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc7) > 0);

-- ruRU
INSERT INTO `item_set_names_locale` (`ID`, `locale`, `Name`, `VerifiedBuild`)
  (SELECT `entry`, "ruRU", `name_loc8`, `VerifiedBuild` FROM `locales_item_set_names` WHERE LENGTH(name_loc8) > 0);

DROP TABLE IF EXISTS `locales_item_set_names`;
