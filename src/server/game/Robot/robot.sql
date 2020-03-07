CREATE TABLE `character_trinity_core`.`robot` (
  `entry` INT NOT NULL AUTO_INCREMENT,
  `account` INT NOT NULL DEFAULT 0,
  `character` INT NOT NULL DEFAULT 0,
  `class` INT NOT NULL DEFAULT 0,
  `race` INT NOT NULL DEFAULT 0,
  `level` INT NOT NULL DEFAULT 0,
  PRIMARY KEY (`entry`));
