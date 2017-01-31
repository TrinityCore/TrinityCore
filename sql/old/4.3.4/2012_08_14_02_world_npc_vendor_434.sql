ALTER TABLE `npc_vendor`            ADD `type` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `game_event_npc_vendor` ADD `type` tinyint(3) unsigned NOT NULL DEFAULT '1';
ALTER TABLE `npc_vendor`            CHANGE `maxcount` `maxcount` mediumint(8) unsigned NOT NULL DEFAULT '0';
ALTER TABLE `game_event_npc_vendor` CHANGE `maxcount` `maxcount` mediumint(8) unsigned NOT NULL DEFAULT '0';
UPDATE `trinity_string` SET `content_default` = 'Item \'%u\' (type %u) not found in database.' WHERE `entry`=207;
UPDATE `trinity_string` SET `content_default` = 'Item \'%u\' (with extended cost %u, type %u) already in vendor list' WHERE `entry`=210;
