ALTER TABLE `item_instance_gems`
  CHANGE `gemItemId1` `gemItemId1` int(10) unsigned NOT NULL DEFAULT '0',
  CHANGE `gemBonuses1` `gemBonuses1` text,
  ADD `gemScalingLevel1` int(10) unsigned NOT NULL DEFAULT '0' AFTER `gemContext1`,
  CHANGE `gemItemId2` `gemItemId2` int(10) unsigned NOT NULL DEFAULT '0',
  CHANGE `gemBonuses2` `gemBonuses2` text,
  ADD `gemScalingLevel2` int(10) unsigned NOT NULL DEFAULT '0' AFTER `gemBonuses2`,
  CHANGE `gemItemId3` `gemItemId3` int(10) unsigned NOT NULL DEFAULT 0,
  CHANGE `gemBonuses3` `gemBonuses3` text,
  ADD `gemScalingLevel3` int(10) unsigned NOT NULL DEFAULT '0' AFTER `gemContext3`;
