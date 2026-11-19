DELETE FROM `gossip_menu` WHERE `entry`=12941;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(12941,18205);

DELETE FROM `gossip_menu_option` WHERE `menu_id`=12941 AND `id`=1;
UPDATE `gossip_menu_option` SET `option_id`=13, `npc_option_npcflag`=2097152 WHERE `menu_id`=12941 AND `id`=0;
UPDATE `npc_text` SET `BroadcastTextID0`=52634 WHERE `ID`=18205;
UPDATE `creature_template` SET `npcflag` = `npcflag`|0x200000 WHERE `entry`=8719;
