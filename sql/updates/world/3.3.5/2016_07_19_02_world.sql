-- 
DELETE FROM `creature_template_addon` WHERE `entry`=27267;
INSERT INTO `creature_template_addon` (`entry`, `bytes1`, `bytes2`, `emote`) VALUES (27267, 256, 257, 233);
UPDATE `creature_template` SET `unit_flags`=32768 WHERE `entry`=27267;
UPDATE `gossip_menu_option` SET `option_id`=3, `npc_option_npcflag`=128 WHERE `menu_id`=9487;
