--
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
    (SELECT `ID`, "koKR", `Name_loc1` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc1) > 0);

-- frFR
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "frFR", `Name_loc2` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc2) > 0);

-- deDE
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "deDE", `Name_loc3` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc3) > 0);

-- zhCN
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "zhCN", `Name_loc4` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc4) > 0);

-- zhTW
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "zhTW", `Name_loc5` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc5) > 0);

-- esES
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "esES", `Name_loc6` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc6) > 0);

-- esMX
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "esMX", `Name_loc7` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc7) > 0);

-- ruRU
INSERT INTO `points_of_interest_locale` (`ID`, `locale`, `Name`)
    (SELECT `ID`, "ruRU", `Name_loc8` FROM `locales_points_of_interest` WHERE LENGTH(Name_loc8) > 0);

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
    (SELECT `ID`, "koKR", `Text_loc1` FROM `locales_page_text` WHERE LENGTH(Text_loc1) > 0);

-- frFR
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "frFR", `Text_loc2` FROM `locales_page_text` WHERE LENGTH(Text_loc2) > 0);

-- deDE
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "deDE", `Text_loc3` FROM `locales_page_text` WHERE LENGTH(Text_loc3) > 0);

-- zhCN
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "zhCN", `Text_loc4` FROM `locales_page_text` WHERE LENGTH(Text_loc4) > 0);

-- zhTW
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "zhTW", `Text_loc5` FROM `locales_page_text` WHERE LENGTH(Text_loc5) > 0);

-- esES
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "esES", `Text_loc6` FROM `locales_page_text` WHERE LENGTH(Text_loc6) > 0);

-- esMX
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "esMX", `Text_loc7` FROM `locales_page_text` WHERE LENGTH(Text_loc7) > 0);

-- ruRU
INSERT INTO `page_text_locale` (`ID`, `locale`, `Text`)
    (SELECT `ID`, "ruRU", `Text_loc8` FROM `locales_page_text` WHERE LENGTH(Text_loc8) > 0);

DROP TABLE IF EXISTS `locales_page_text`;
