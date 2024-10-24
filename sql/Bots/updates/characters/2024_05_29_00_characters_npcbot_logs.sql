--
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `characters_npcbot_logs`;
CREATE TABLE `characters_npcbot_logs` (
  `id` bigint unsigned NOT NULL AUTO_INCREMENT,
  `entry` int unsigned NOT NULL DEFAULT '0',
  `owner` int NOT NULL DEFAULT '-1',
  `mapid` int NOT NULL DEFAULT '-1',
  `inmap` tinyint NOT NULL DEFAULT '-1',
  `inworld` tinyint NOT NULL DEFAULT '-1',
  `type` smallint unsigned NOT NULL DEFAULT '0',
  `param1` varchar(51) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `param2` varchar(51) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `param3` varchar(51) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `param4` varchar(51) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `param5` varchar(51) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
