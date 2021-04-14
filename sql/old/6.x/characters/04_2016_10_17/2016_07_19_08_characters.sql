ALTER TABLE `item_instance_gems`
  ADD `gemBonuses1` TEXT AFTER `gemItemId1`,
  ADD `gemContext1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `gemBonuses1`,
  ADD `gemBonuses2` TEXT AFTER `gemItemId2`,
  ADD `gemContext2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `gemBonuses2`,
  ADD `gemBonuses3` TEXT AFTER `gemItemId3`,
  ADD `gemContext3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `gemBonuses3`;
