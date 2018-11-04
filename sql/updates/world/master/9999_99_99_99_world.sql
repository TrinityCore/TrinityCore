DROP TABLE IF EXISTS `achievement_reward_locale`;
CREATE TABLE `achievement_reward_locale` (
	`ID` INT(10) UNSIGNED NOT NULL DEFAULT '0',
	`Locale` VARCHAR(4) NOT NULL,
	`Subject` TEXT NULL,
	`Text` TEXT NULL,
	PRIMARY KEY (`ID`, `Locale`)
);

-- The old table is empty on default, but migrate data to new table just in case
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "koKR", `subject_loc1`, `text_loc1` FROM `locales_achievement_reward` WHERE `text_loc1` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "frFR", `subject_loc2`, `text_loc2` FROM `locales_achievement_reward` WHERE `text_loc2` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "deDE", `subject_loc3`, `text_loc3` FROM `locales_achievement_reward` WHERE `text_loc3` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "zhCN", `subject_loc4`, `text_loc4` FROM `locales_achievement_reward` WHERE `text_loc4` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "zhTW", `subject_loc5`, `text_loc5` FROM `locales_achievement_reward` WHERE `text_loc5` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "esES", `subject_loc6`, `text_loc6` FROM `locales_achievement_reward` WHERE `text_loc6` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "esMX", `subject_loc7`, `text_loc7` FROM `locales_achievement_reward` WHERE `text_loc7` != "";
INSERT INTO `achievement_reward_locale` (`ID`, `Locale`, `Subject`, `Text`) SELECT `entry`, "ruRU", `subject_loc8`, `text_loc8` FROM `locales_achievement_reward` WHERE `text_loc8` != "";

DROP TABLE IF EXISTS `locales_achievement_reward`;
