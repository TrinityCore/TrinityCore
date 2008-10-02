ALTER TABLE `character` 
  ADD COLUMN `at_login` int(11) unsigned NOT NULL default '0' AFTER `rename`;

UPDATE `character` SET `at_login` = 1 WHERE `rename` <> 0;

ALTER TABLE `character` 
  DROP COLUMN `rename`;