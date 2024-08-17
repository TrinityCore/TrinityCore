ALTER TABLE `creature_template`
  CHANGE COLUMN `rank` `Classification` TINYINT(3) UNSIGNED NOT NULL DEFAULT '0' AFTER `scale`;
