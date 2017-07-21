DROP TABLE IF EXISTS `creature_template_scaling`;
CREATE TABLE `creature_template_scaling` (
  `Entry` MEDIUMINT (8) UNSIGNED NOT NULL,
  `LevelScalingMin` SMALLINT (5) UNSIGNED NOT NULL DEFAULT 0,
  `LevelScalingMax` SMALLINT (5) UNSIGNED NOT NULL DEFAULT 0,
  `LevelScalingDelta` SMALLINT (5) NOT NULL DEFAULT 0,
  `VerifiedBuild` SMALLINT (5) DEFAULT NULL,
  PRIMARY KEY (`Entry`)
);
