DROP TABLE IF EXISTS `points_of_interest_locale`;
CREATE TABLE IF NOT EXISTS `points_of_interest_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `locale` VARCHAR(4) NOT NULL,
  `Name` TEXT,
  `VerifiedBuild` SMALLINT(5) DEFAULT '0'
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

ALTER TABLE `points_of_interest_locale`
ADD PRIMARY KEY (`ID`,`locale`);

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

ALTER TABLE `locales_page_text` CHANGE `entry` `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

ALTER TABLE `points_of_interest` CHANGE `data` `Importance` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
