DROP TABLE IF EXISTS `robot`;
CREATE TABLE `character_trinity_core`.`robot` (
  `entry` int(11) NOT NULL AUTO_INCREMENT,
  `robot_id` int(11) NOT NULL DEFAULT '0',
  `account_id` int(11) NOT NULL DEFAULT '0',
  `character_id` int(11) NOT NULL DEFAULT '0',
  `target_level` int(11) NOT NULL DEFAULT '0',
  `robot_type` int(11) DEFAULT '0',
  PRIMARY KEY (`entry`));
