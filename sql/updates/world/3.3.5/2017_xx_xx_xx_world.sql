-- achievement_reward
ALTER TABLE `achievement_reward` CHANGE `entry` `ID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_A` `TitleA` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `title_H` `TitleH` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `item` `ItemID` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `sender` `Sender` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `achievement_reward` CHANGE `subject` `Subject` varchar(255) DEFAULT NULL;
ALTER TABLE `achievement_reward` CHANGE `text` `Text` text;
ALTER TABLE `achievement_reward` CHANGE `mailTemplate` `MailTemplate` mediumint(8) unsigned DEFAULT '0';

-- achievement_reward_locale
DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE IF NOT EXISTS `achievement_reward_locale` (
  `ID` MEDIUMINT(8) UNSIGNED NOT NULL DEFAULT '0',
  `Locale` VARCHAR(4) NOT NULL,
  `Subject` TEXT,
  `Text` TEXT,
  PRIMARY KEY (`ID`, `Locale`)
) ENGINE=MYISAM DEFAULT CHARSET=utf8mb4;

DROP TABLE IF EXISTS `locales_achievement_reward`;
