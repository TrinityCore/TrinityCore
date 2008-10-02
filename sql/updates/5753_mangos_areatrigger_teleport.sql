ALTER TABLE `areatrigger_teleport`
  ADD COLUMN `required_item2` mediumint(8) unsigned NOT NULL default '0' AFTER `required_item`,
  ADD COLUMN `heroic_key` mediumint(8) unsigned NOT NULL default '0' AFTER `required_item2`,
  ADD COLUMN `heroic_key2` mediumint(8) unsigned NOT NULL default '0' AFTER `heroic_key`,
  ADD COLUMN `required_quest_done` int(11) unsigned NOT NULL default '0' AFTER `heroic_key2`,
  ADD COLUMN `required_failed_text` text AFTER `required_quest_done`;