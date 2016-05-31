ALTER TABLE `locales_creature_text` CHANGE `entry` `entry` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `locales_creature_text` CHANGE `textGroup` `groupid` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `locales_creature_text` CHANGE `id` `id` tinyint(3) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `locales_npc_text` CHANGE `entry` `ID` mediumint(8) unsigned NOT NULL DEFAULT '0';
