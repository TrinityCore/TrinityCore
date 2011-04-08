ALTER TABLE `account`
  ADD COLUMN `last_module` char(32) default '' AFTER `last_login`,
  ADD COLUMN `module_day` mediumint(8) unsigned NOT NULL default 0 AFTER `last_module`,
  ADD COLUMN `os` int(10) unsigned NOT NULL DEFAULT '0' AFTER `locale`;
