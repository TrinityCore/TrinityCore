ALTER TABLE `creature_template` 
  MODIFY COLUMN `name` text AFTER `KillCredit2`,
  MODIFY COLUMN `femaleName` text AFTER `name`,
  MODIFY COLUMN `subname` text AFTER `femaleName`,
  MODIFY COLUMN `TitleAlt` text AFTER `subname`,
  MODIFY COLUMN `IconName` varchar(64) DEFAULT NULL AFTER `TitleAlt`,
  MODIFY COLUMN `AIName` varchar(64) NOT NULL DEFAULT '' AFTER `maxgold`,
  MODIFY COLUMN `ScriptName` varchar(64) NOT NULL DEFAULT '' AFTER `flags_extra`,
  DROP INDEX `idx_name`;
