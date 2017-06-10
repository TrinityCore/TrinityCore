ALTER TABLE `characters`
  ADD `honor` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `deleteDate`,
  ADD `honorLevel` INT(10) UNSIGNED NOT NULL DEFAULT '1' AFTER `honor`,
  ADD `prestigeLevel` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `honorLevel`,
  ADD `honorRestState` TINYINT UNSIGNED NOT NULL DEFAULT '2' AFTER `prestigeLevel`,
  ADD `honorRestBonus` FLOAT NOT NULL DEFAULT '0' AFTER `honorRestState`;
