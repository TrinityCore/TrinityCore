ALTER TABLE `character_void_storage`
  ADD `upgradeId` INT(10) UNSIGNED NOT NULL DEFAULT '0' AFTER `suffixFactor`,
  ADD `bonusListIDs` TEXT AFTER `upgradeId`;
