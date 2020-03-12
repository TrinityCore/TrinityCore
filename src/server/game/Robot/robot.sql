CREATE TABLE `character_trinity_core`.`robot` (
  `entry` INT NOT NULL AUTO_INCREMENT,
  `robot_id` INT NOT NULL DEFAULT 0,
  `account_id` INT NOT NULL DEFAULT 0,
  `character_id` INT NOT NULL DEFAULT 0,  
  `target_level` INT NOT NULL DEFAULT 0,
  PRIMARY KEY (`entry`));
