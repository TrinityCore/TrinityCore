-- run if dropping and creating the tables for the first time or wanting to start fresh on anticheat stats
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
  `op_ack_hack_reports` bigint unsigned NOT NULL DEFAULT 0,
  `counter_measures_reports` bigint unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

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
  `op_ack_hack_reports` bigint unsigned NOT NULL DEFAULT 0,
  `counter_measures_reports` bigint unsigned NOT NULL DEFAULT 0,
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

CREATE TABLE IF NOT EXISTS `lua_cheaters` (
  `guid` int unsigned NOT NULL DEFAULT 0,
  `account` int unsigned NOT NULL DEFAULT 0,
  `macro` varchar(255) NOT NULL DEFAULT '',
    PRIMARY KEY (`guid`,`account`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;

-- run only if updating from previous table versions
ALTER TABLE `daily_players_reports`
	ADD COLUMN `teleport_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `climb_reports`,
	ADD COLUMN `ignorecontrol_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `teleport_reports`,
	ADD COLUMN `zaxis_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `ignorecontrol_reports`,
    ADD COLUMN `antiswim_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `zaxis_reports`,
    ADD COLUMN `gravity_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `antiswim_reports`;
    ADD COLUMN `antiknockback_reports` bigint unsigned NOT NULL DEFAULT 0 AFTER `gravity_reports`;
    ADD COLUMN `no_fall_damage_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `antiknockback_reports`;
	ADD COLUMN `op_ack_hack_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `no_fall_damage_reports`;
	ADD COLUMN `counter_measures_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `op_ack_hack_reports`;
	
ALTER TABLE `players_reports_status`
    ADD COLUMN `teleport_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `climb_reports`,
    ADD COLUMN `ignorecontrol_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `teleport_reports`,
    ADD COLUMN `zaxis_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `ignorecontrol_reports`,
    ADD COLUMN `antiswim_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `zaxis_reports`,
    ADD COLUMN `gravity_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `antiswim_reports`;
	ADD COLUMN `antiknockback_reports` bigint unsigned NOT NULL DEFAULT 0 AFTER `gravity_reports`;
    ADD COLUMN `no_fall_damage_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `antiknockback_reports`;
	ADD COLUMN `op_ack_hack_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `no_fall_damage_reports`;
	ADD COLUMN `counter_measures_reports` BIGINT UNSIGNED NOT NULL DEFAULT 0 AFTER `op_ack_hack_reports`;
