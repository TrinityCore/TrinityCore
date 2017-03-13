DROP TABLE IF EXISTS `creature_template_scaling`;
CREATE TABLE `creature_template_scaling` (
  `entry` MEDIUMINT (8) UNSIGNED NOT NULL,
  `levelScalingDelta` SMALLINT (5) NOT NULL DEFAULT 0,
  PRIMARY KEY (`entry`)
);
