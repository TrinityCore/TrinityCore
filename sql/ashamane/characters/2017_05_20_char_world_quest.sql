DROP TABLE IF EXISTS `world_quest`;
CREATE TABLE `world_quest` (
  `id` INT (10) UNSIGNED NOT NULL,
  `starttime` INT (10) UNSIGNED NOT NULL,
  `remaining` INT (10) UNSIGNED NOT NULL,
  PRIMARY KEY (`id`)
);
