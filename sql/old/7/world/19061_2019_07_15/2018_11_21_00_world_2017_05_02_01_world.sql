-- achievement_reward
ALTER TABLE `achievement_reward` CHANGE `entry` `ID` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_A` `TitleA` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_H` `TitleH` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `item` `ItemID` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `sender` `Sender` int(10) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `subject` `Subject` varchar(255) DEFAULT NULL;
ALTER TABLE `achievement_reward` CHANGE `text` `Body` text;
ALTER TABLE `achievement_reward` CHANGE `mailTemplate` `MailTemplateID` int(10) unsigned DEFAULT '0';

-- achievement_reward_locale
DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE IF NOT EXISTS `achievement_reward_locale` (
  `ID` int(10) unsigned NOT NULL DEFAULT '0',
  `Locale` varchar(4) NOT NULL,
  `Subject` text,
  `Body` text,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8;

-- koKR
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Body`)
  (SELECT `entry`, "koKR", `subject_loc1`, `text_loc1` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc1) > 0 OR LENGTH(text_loc1) > 0);

-- frFR
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "frFR", `subject_loc2`, `text_loc2` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc2) > 0 OR LENGTH(text_loc2) > 0);

-- deDE
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "deDE", `subject_loc3`, `text_loc3` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc3) > 0 OR LENGTH(text_loc3) > 0);

-- zhCN
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "zhCN", `subject_loc4`, `text_loc4` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc4) > 0 OR LENGTH(text_loc4) > 0);

-- zhTW
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "zhTW", `subject_loc5`, `text_loc5` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc5) > 0 OR LENGTH(text_loc5) > 0);

-- esES
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "esES", `subject_loc6`, `text_loc6` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc6) > 0 OR LENGTH(text_loc6) > 0);

-- esMX
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "esMX", `subject_loc7`, `text_loc7` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc7) > 0 OR LENGTH(text_loc7) > 0);

-- ruRU
INSERT INTO `achievement_reward_locale` (`ID`, `locale`, `Subject`, `Body`)
  (SELECT `entry`, "ruRU", `subject_loc8`, `text_loc8` FROM `locales_achievement_reward` WHERE LENGTH(subject_loc8) > 0 OR LENGTH(text_loc8) > 0);

DROP TABLE IF EXISTS `locales_achievement_reward`;
