ALTER TABLE `character_queststatus`
  ADD `itemcount5` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount4`,
  ADD `itemcount6` smallint(5) unsigned NOT NULL DEFAULT '0' AFTER `itemcount5`;
