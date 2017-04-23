DROP TABLE IF EXISTS `broadcast_text_locale`;
CREATE TABLE IF NOT EXISTS `broadcast_text_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `MaleText` TEXT,
  `FemaleText` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "koKR", `MaleText_loc1`, `FemaleText_loc1` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc1) > 0 OR LENGTH(FemaleText_loc1) > 0);

-- frFR
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "frFR", `MaleText_loc2`, `FemaleText_loc2` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc2) > 0 OR LENGTH(FemaleText_loc2) > 0);

-- deDE
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "deDE", `MaleText_loc3`, `FemaleText_loc3` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc3) > 0 OR LENGTH(FemaleText_loc3) > 0);

-- zhCN
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "zhCN", `MaleText_loc4`, `FemaleText_loc4` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc4) > 0 OR LENGTH(FemaleText_loc4) > 0);

-- zhTW
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "zhTW", `MaleText_loc5`, `FemaleText_loc5` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc5) > 0 OR LENGTH(FemaleText_loc5) > 0);

-- esES
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "esES", `MaleText_loc6`, `FemaleText_loc6` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc6) > 0 OR LENGTH(FemaleText_loc6) > 0);

-- esMX
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "esMX", `MaleText_loc7`, `FemaleText_loc7` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc7) > 0 OR LENGTH(FemaleText_loc7) > 0);

-- ruRU
INSERT INTO `broadcast_text_locale` (`ID`, `locale`, `MaleText`, `FemaleText`)
  (SELECT `entry`, "ruRU", `MaleText_loc8`, `FemaleText_loc8` FROM `locales_broadcast_text` WHERE LENGTH(MaleText_loc8) > 0 OR LENGTH(FemaleText_loc8) > 0);

DROP TABLE IF EXISTS `locales_broadcast_text`;
