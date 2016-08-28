-- NPC 25288 Turida Coldwind, update existing gossip menu option with missing values
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`= 53141, `option_id`= 4,
 `npc_option_npcflag`= 8192 WHERE `menu_id`= 13048;

-- insert missing gossip menu
DELETE FROM `gossip_menu` WHERE `entry` = 13048 AND `text_id`= 18324;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (13048,18324);
