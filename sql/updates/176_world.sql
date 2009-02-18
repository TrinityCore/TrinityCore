ALTER TABLE `npc_option`
  CHANGE COLUMN `id` `id` mediumint(8) unsigned NOT NULL default '0',
  CHANGE COLUMN `gossip_id` `gossip_id` mediumint(8) unsigned NOT NULL default '0',
  CHANGE COLUMN `action` `action` mediumint(8) unsigned NOT NULL default '0',
  ADD COLUMN `box_money` int(10) unsigned NOT NULL default '0' AFTER `action`,
  ADD COLUMN `coded` tinyint(3) unsigned NOT NULL default '0' AFTER `box_money`,
  ADD COLUMN `box_text` text AFTER `option_text`;

CREATE TABLE `locales_npc_option` (
  `entry` mediumint(8) unsigned NOT NULL default '0',
  `option_text_loc1` text,
  `option_text_loc2` text,
  `option_text_loc3` text,
  `option_text_loc4` text,
  `option_text_loc5` text,
  `option_text_loc6` text,
  `option_text_loc7` text,
  `option_text_loc8` text,
  `box_text_loc1` text,
  `box_text_loc2` text,
  `box_text_loc3` text,
  `box_text_loc4` text,
  `box_text_loc5` text,
  `box_text_loc6` text,
  `box_text_loc7` text,
  `box_text_loc8` text,
  PRIMARY KEY  (`entry`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

ALTER TABLE `creature_template`
  CHANGE COLUMN `flags` `unit_flags` int(10) unsigned NOT NULL default '0',
  CHANGE COLUMN `flag1` `type_flags` int(10) unsigned NOT NULL default '0';

