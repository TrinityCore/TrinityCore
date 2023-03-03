ALTER TABLE `character_achievement_progress`   
  ADD COLUMN `achievID` INT(11) UNSIGNED DEFAULT 0  NOT NULL AFTER `date`;
ALTER TABLE `account_achievement_progress`   
  ADD COLUMN `achievID` INT(11) UNSIGNED DEFAULT 0  NOT NULL AFTER `date`;
ALTER TABLE `guild_achievement_progress`   
  ADD COLUMN `achievID` INT(0) UNSIGNED NOT NULL AFTER `completedGuid`;

ALTER TABLE `character_achievement_progress`
  ADD COLUMN `completed` INT(3) DEFAULT 0  NOT NULL AFTER `achievID`;
ALTER TABLE `account_achievement_progress`
  ADD COLUMN `completed` INT(3) DEFAULT 0  NOT NULL AFTER `achievID`;
ALTER TABLE `guild_achievement_progress`
  ADD COLUMN `completed` INT(3) DEFAULT 0  NOT NULL AFTER `achievID`;
