-- achievement_reward
ALTER TABLE `achievement_reward` CHANGE `entry` `ID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_A` `TitleA` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_H` `TitleH` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `item` `ItemID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `sender` `Sender` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `subject` `Subject` varchar(255) DEFAULT NULL;
ALTER TABLE `achievement_reward` CHANGE `text` `Text` text;
ALTER TABLE `achievement_reward` CHANGE `mailTemplate` `MailTemplateID` mediumint(8) unsigned DEFAULT '0';

-- achievement_reward_locale
DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE IF NOT EXISTS `achievement_reward_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Subject` TEXT,
  `Text` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`)
  (SELECT `entry`, "koKR", `subject_loc1`, `text_loc1` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc1) > 0 OR LENGTH(text_loc1) > 0);

-- frFR
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "frFR", `subject_loc2`, `text_loc2` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc2) > 0 OR LENGTH(text_loc2) > 0);

-- deDE
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "deDE", `subject_loc3`, `text_loc3` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc3) > 0 OR LENGTH(text_loc3) > 0);

-- zhCN
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "zhCN", `subject_loc4`, `text_loc4` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc4) > 0 OR LENGTH(text_loc4) > 0);

-- zhTW
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "zhTW", `subject_loc5`, `text_loc5` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc5) > 0 OR LENGTH(text_loc5) > 0);

-- esES
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "esES", `subject_loc6`, `text_loc6` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc6) > 0 OR LENGTH(text_loc6) > 0);

-- esMX
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "esMX", `subject_loc7`, `text_loc7` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc7) > 0 OR LENGTH(text_loc7) > 0);

-- ruRU
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Text`)
  (SELECT `entry`, "ruRU", `subject_loc8`, `text_loc8` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc8) > 0 OR LENGTH(text_loc8) > 0);

DROP TABLE IF EXISTS `locales_achievement_reward`;
