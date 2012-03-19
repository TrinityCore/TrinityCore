-- Gossip Menu insert
DELETE FROM `gossip_menu` WHERE `entry`=3067 AND `text_id`=3801;
DELETE FROM `gossip_menu` WHERE `entry`=3481 AND `text_id`=4953;
DELETE FROM `gossip_menu` WHERE `entry`=4061 AND `text_id`=4954;
DELETE FROM `gossip_menu` WHERE `entry`=4062 AND `text_id`=4955;
DELETE FROM `gossip_menu` WHERE `entry`=4063 AND `text_id`=4956;
DELETE FROM `gossip_menu` WHERE `entry`=4064 AND `text_id`=4957;
DELETE FROM `gossip_menu` WHERE `entry`=4065 AND `text_id`=4958;
DELETE FROM `gossip_menu` WHERE `entry`=6627 AND `text_id`=7881;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(3067,3801),
(3481,4953),
(4061,4954),
(4062,4955),
(4063,4956),
(4064,4957),
(4065,4958),
(6627,7881);
-- Creature Gossip_menu_id Update
UPDATE `creature_template` SET `gossip_menu_id`=4573 WHERE `entry`=4091;
UPDATE `creature_template` SET `gossip_menu_id`=3067 WHERE `entry`=7866;
UPDATE `creature_template` SET `gossip_menu_id`=3481 WHERE `entry`=11548;
UPDATE `creature_template` SET `gossip_menu_id`=6944 WHERE `entry`=12577;
-- Creature Gossip_menu_option Update
DELETE FROM `gossip_menu_option` WHERE `menu_id`=3481;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`action_script_id`,`box_coded`,`box_money`,`box_text`) VALUES
(3481,0,0, 'The land of Azshara.',1,1,4061,0,0,0,0, ''),
(3481,1,0, 'The Ruins of Eldarath.',1,1,4062,0,0,0,0, ''),
(3481,2,0, 'The mage tower to the north.',1,1,4063,0,0,0,0, ''),
(3481,3,0, 'The Timbermaw furbolgs.',1,1,4064,0,0,0,0, ''),
(3481,4,0, 'The presence of blue dragons.',1,1,4065,0,0,0,0, '');
