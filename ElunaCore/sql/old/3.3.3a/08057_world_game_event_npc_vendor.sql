ALTER TABLE `game_event_npc_vendor` ADD `slot` SMALLINT(6) NOT NULL DEFAULT '0' AFTER `guid`;
ALTER TABLE `game_event_npc_vendor` ADD INDEX (`slot`);
