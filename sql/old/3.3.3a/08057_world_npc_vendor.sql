ALTER TABLE `npc_vendor` ADD `slot` SMALLINT(6) NOT NULL DEFAULT '0' AFTER `entry`;
ALTER TABLE `npc_vendor` ADD INDEX (`slot`);
