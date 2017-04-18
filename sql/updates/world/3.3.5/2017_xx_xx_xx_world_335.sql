DROP TABLE IF EXISTS `points_of_interest_locale`;
CREATE TABLE IF NOT EXISTS `points_of_interest_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "koKR", `icon_name_loc1` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc1) > 0);

-- frFR
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "frFR", `icon_name_loc2` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc2) > 0);

-- deDE
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "deDE", `icon_name_loc3` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc3) > 0);

-- zhCN
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "zhCN", `icon_name_loc4` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc4) > 0);

-- zhTW
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "zhTW", `icon_name_loc5` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc5) > 0);

-- esES
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "esES", `icon_name_loc6` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc6) > 0);

-- esMX
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "esMX", `icon_name_loc7` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc7) > 0);

-- ruRU
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `entry`, "ruRU", `icon_name_loc8` FROM `locales_points_of_interest` WHERE LENGTH(icon_name_loc8) > 0);

DROP TABLE IF EXISTS `locales_points_of_interest`;

DROP TABLE IF EXISTS `page_text_locale`;
CREATE TABLE IF NOT EXISTS `page_text_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Text` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0',
  PRIMARY KEY (`ID`, `locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "koKR", `text_loc1` FROM `locales_page_text` WHERE LENGTH(text_loc1) > 0);

-- frFR
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "frFR", `text_loc2` FROM `locales_page_text` WHERE LENGTH(text_loc2) > 0);

-- deDE
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "deDE", `text_loc3` FROM `locales_page_text` WHERE LENGTH(text_loc3) > 0);

-- zhCN
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "zhCN", `text_loc4` FROM `locales_page_text` WHERE LENGTH(text_loc4) > 0);

-- zhTW
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "zhTW", `text_loc5` FROM `locales_page_text` WHERE LENGTH(text_loc5) > 0);

-- esES
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "esES", `text_loc6` FROM `locales_page_text` WHERE LENGTH(text_loc6) > 0);

-- esMX
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "esMX", `text_loc7` FROM `locales_page_text` WHERE LENGTH(text_loc7) > 0);

-- ruRU
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `entry`, "ruRU", `text_loc8` FROM `locales_page_text` WHERE LENGTH(text_loc8) > 0);

DROP TABLE IF EXISTS `locales_page_text`;

ALTER TABLE `points_of_interest` CHANGE `data` `Importance` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
