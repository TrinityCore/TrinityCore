-- Add some missing gossip for winterspring
UPDATE `creature_template` SET `gossip_menu_id`=3049 WHERE `entry`=10918;
DELETE FROM `gossip_menu` WHERE `entry`=3049;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (3049,3758);
UPDATE `creature_template` SET `gossip_menu_id`=7046 WHERE `entry`=16015;
DELETE FROM `gossip_menu` WHERE `entry`=7046;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (7046,8292);
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7046 AND `id` IN (0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(7046,0,1, 'Hey Vi''el, show me your wares!',3,128,0,0,0,0, '');
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=11119;
UPDATE `creature_template` SET `gossip_menu_id`=6092 WHERE `entry`=14742;
DELETE FROM `gossip_menu` WHERE `entry`=6092;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6092,7249);
UPDATE `creature_template` SET `gossip_menu_id`=6091 WHERE `entry`=11193;
DELETE FROM `gossip_menu` WHERE `entry`=6091;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6091,7247);
UPDATE `creature_template` SET `gossip_menu_id`=6089 WHERE `entry`=11192;
DELETE FROM `gossip_menu` WHERE `entry`=6089;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6089,7243);
UPDATE `creature_template` SET `gossip_menu_id`=6090 WHERE `entry`=11191;
DELETE FROM `gossip_menu` WHERE `entry`=6090;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES (6090,7245);
