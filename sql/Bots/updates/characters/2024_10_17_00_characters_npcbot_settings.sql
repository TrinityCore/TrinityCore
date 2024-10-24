--
SET FOREIGN_KEY_CHECKS=0;
DROP TABLE IF EXISTS `characters_npcbot_settings`;
CREATE TABLE `characters_npcbot_settings` (
  `owner` int unsigned NOT NULL,
  `dist_follow` tinyint unsigned NOT NULL DEFAULT '30',
  `dist_attack` tinyint unsigned NOT NULL DEFAULT '0',
  `attack_range_mode` tinyint unsigned NOT NULL DEFAULT '1',
  `attack_angle_mode` tinyint unsigned NOT NULL DEFAULT '1',
  `engage_delay_dps` int unsigned NOT NULL DEFAULT '0',
  `engage_delay_heal` int unsigned NOT NULL DEFAULT '0',
  `flags` int unsigned NOT NULL DEFAULT '0',
  PRIMARY KEY (`owner`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
