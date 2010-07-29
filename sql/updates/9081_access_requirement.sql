ALTER TABLE `access_requirement`
 DROP PRIMARY KEY,
 CHANGE `id` `mapId` mediumint(8) unsigned NOT NULL FIRST,
 ADD `difficulty` tinyint(3) unsigned NOT NULL DEFAULT '0' AFTER `mapId`,
 DROP `heroic_level_min`,
 DROP `heroic_key`,
 DROP `heroic_key2`,
 CHANGE `quest_done` `quest_done_A` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `item2`,
 CHANGE `heroic_quest_done` `quest_done_H` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `quest_done_A`,
 ADD `completed_achievement` mediumint(8) unsigned NOT NULL DEFAULT '0' AFTER `quest_done_H`,
 DROP `heroic_quest_failed_text`,
 ADD PRIMARY KEY(`mapId`,`difficulty`);
