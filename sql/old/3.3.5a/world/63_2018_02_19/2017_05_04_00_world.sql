-- creature_text
ALTER TABLE `creature_text` CHANGE `entry` `CreatureID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `groupid` `GroupID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `id` `ID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `text` `Text` LONGTEXT;
ALTER TABLE `creature_text` CHANGE `type` `Type` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `language` `Language` TINYINT(3) NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `probability` `Probability` FLOAT UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `emote` `Emote` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `duration` `Duration` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';
ALTER TABLE `creature_text` CHANGE `sound` `Sound` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0';

-- creature_text_locale
DROP TABLE IF EXISTS `creature_text_locale`;
CREATE TABLE IF NOT EXISTS `creature_text_locale` (
  `CreatureID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `GroupID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `ID` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Text` TEXT,
  PRIMARY KEY (`CreatureID`, `GroupID`, `ID`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "koKR", `text_loc1` FROM `locales_creature_text` WHERE LENGTH(text_loc1) > 0);

-- frFR
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "frFR", `text_loc2` FROM `locales_creature_text` WHERE LENGTH(text_loc2) > 0);

-- deDE
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "deDE", `text_loc3` FROM `locales_creature_text` WHERE LENGTH(text_loc3) > 0);

-- zhCN
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "zhCN", `text_loc4` FROM `locales_creature_text` WHERE LENGTH(text_loc4) > 0);

-- zhTW
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "zhTW", `text_loc5` FROM `locales_creature_text` WHERE LENGTH(text_loc5) > 0);

-- esES
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "esES", `text_loc6` FROM `locales_creature_text` WHERE LENGTH(text_loc6) > 0);

-- esMX
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "esMX", `text_loc7` FROM `locales_creature_text` WHERE LENGTH(text_loc7) > 0);

-- ruRU
INSERT INTO `creature_text_locale` (`CreatureID`, `GroupID`, `ID`, `Locale`, `Text`)
  (SELECT `entry`, `groupid`, `id`, "ruRU", `text_loc8` FROM `locales_creature_text` WHERE LENGTH(text_loc8) > 0);

DROP TABLE IF EXISTS `locales_creature_text`;
