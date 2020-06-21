ALTER TABLE `character_trinity_core`.`character_pet` 
CHANGE COLUMN `name` `name` VARCHAR(100) NOT NULL DEFAULT 'Pet' ;

DROP TABLE IF EXISTS `joker_hunter_pet`;
CREATE TABLE `joker_hunter_pet` (
  `entry` int(11) NOT NULL AUTO_INCREMENT,
  `pet_guid` int(11) NOT NULL DEFAULT '0',
  `accompany_time` int(11) NOT NULL DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8;

DROP TABLE IF EXISTS `robot`;
CREATE TABLE `robot` (
  `entry` int(11) NOT NULL AUTO_INCREMENT,
  `robot_id` int(11) NOT NULL DEFAULT '0',
  `account_id` int(11) NOT NULL DEFAULT '0',
  `character_id` int(11) NOT NULL DEFAULT '0',
  `target_level` int(11) NOT NULL DEFAULT '0',
  `robot_type` int(11) DEFAULT '0',
  PRIMARY KEY (`entry`)
) ENGINE=InnoDB AUTO_INCREMENT=6051 DEFAULT CHARSET=utf8;
