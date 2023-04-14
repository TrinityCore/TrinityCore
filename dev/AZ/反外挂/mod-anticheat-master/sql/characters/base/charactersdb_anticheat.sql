DROP TABLE IF EXISTS `daily_players_reports`;
CREATE TABLE IF NOT EXISTS `daily_players_reports` (
  `guid` int unsigned NOT NULL DEFAULT 0,
  `creation_time` int unsigned NOT NULL DEFAULT 0,
  `average` float NOT NULL DEFAULT 0,
  `total_reports` bigint unsigned NOT NULL DEFAULT 0,
  `speed_reports` bigint unsigned NOT NULL DEFAULT 0,
  `fly_reports` bigint unsigned NOT NULL DEFAULT 0,
  `jump_reports` bigint unsigned NOT NULL DEFAULT 0,
  `waterwalk_reports` bigint unsigned NOT NULL DEFAULT 0,
  `teleportplane_reports` bigint unsigned NOT NULL DEFAULT 0,
  `climb_reports` bigint unsigned NOT NULL DEFAULT 0,
  `teleport_reports` bigint unsigned NOT NULL DEFAULT 0,
  `ignorecontrol_reports` bigint unsigned NOT NULL DEFAULT 0,
  `zaxis_reports` bigint unsigned NOT NULL DEFAULT 0,
  `antiswim_reports` bigint unsigned NOT NULL DEFAULT 0,
  `gravity_reports` bigint unsigned NOT NULL DEFAULT 0,
  `antiknockback_reports` bigint unsigned NOT NULL DEFAULT 0,
  `no_fall_damage_reports` bigint unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

DROP TABLE IF EXISTS `players_reports_status`;
CREATE TABLE IF NOT EXISTS `players_reports_status` (
  `guid` int unsigned NOT NULL DEFAULT 0,
  `creation_time` int unsigned NOT NULL DEFAULT 0,
  `average` float NOT NULL DEFAULT 0,
  `total_reports` bigint unsigned NOT NULL DEFAULT 0,
  `speed_reports` bigint unsigned NOT NULL DEFAULT 0,
  `fly_reports` bigint unsigned NOT NULL DEFAULT 0,
  `jump_reports` bigint unsigned NOT NULL DEFAULT 0,
  `waterwalk_reports` bigint unsigned NOT NULL DEFAULT 0,
  `teleportplane_reports` bigint unsigned NOT NULL DEFAULT 0,
  `climb_reports` bigint unsigned NOT NULL DEFAULT 0,
  `teleport_reports` bigint unsigned NOT NULL DEFAULT 0,
  `ignorecontrol_reports` bigint unsigned NOT NULL DEFAULT 0,
  `zaxis_reports` bigint unsigned NOT NULL DEFAULT 0,
  `antiswim_reports` bigint unsigned NOT NULL DEFAULT 0,
  `gravity_reports` bigint unsigned NOT NULL DEFAULT 0,
  `antiknockback_reports` bigint unsigned NOT NULL DEFAULT 0,
  `no_fall_damage_reports` bigint unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;
