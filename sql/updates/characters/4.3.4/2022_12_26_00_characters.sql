--
-- Table structure for table `world_state_value`
--
DROP TABLE IF EXISTS `world_state_value`;
CREATE TABLE `world_state_value` (
  `Id` int NOT NULL,
  `Value` int NOT NULL,
  PRIMARY KEY (`Id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
--
-- Table structure for table `world_state_value`
--
DROP TABLE IF EXISTS `world_variable`;
CREATE TABLE `world_variable` (
  `ID` varchar(64) CHARACTER SET utf8mb4 COLLATE utf8mb4_unicode_ci NOT NULL,
  `Value` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`ID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

INSERT INTO `world_state_value` SELECT `entry`, `value` FROM `worldstates` WHERE `entry` NOT BETWEEN 20001 AND 20009 AND `entry` <> 20050;

INSERT INTO `world_variable` SELECT 'NextCurrencyResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20001;
INSERT INTO `world_variable` SELECT 'NextWeeklyQuestResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20002;
INSERT INTO `world_variable` SELECT 'NextBGRandomDailyResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20003;
INSERT INTO `world_variable` SELECT 'PersistentCharacterCleanFlags', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20004;
INSERT INTO `world_variable` SELECT 'NextGuildDailyResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20006;
INSERT INTO `world_variable` SELECT 'NextMonthlyQuestResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20007;
INSERT INTO `world_variable` SELECT 'NextDailyQuestResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20008;
INSERT INTO `world_variable` SELECT 'NextOldCalendarEventDeletionTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20009;
INSERT INTO `world_variable` SELECT 'NextGuildWeeklyResetTime', ws.`value` FROM `worldstates` ws WHERE ws.entry = 20050;

DROP TABLE `worldstates`;
