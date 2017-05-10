ALTER TABLE `characters`
  ADD `customDisplay1` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `facialStyle`,
  ADD `customDisplay2` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `customDisplay1`,
  ADD `customDisplay3` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `customDisplay2`;
