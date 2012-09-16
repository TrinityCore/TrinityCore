-- Gossip Menu
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13759;
DELETE FROM `gossip_menu` WHERE `entry`=9904 AND `text_id`=13761;
DELETE FROM `gossip_menu` WHERE `entry`=9923 AND `text_id`=14172;
DELETE FROM `gossip_menu` WHERE `entry`=10229 AND `text_id`=14221;
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(9904,13759),
(9904,13761),
(9923,14172),
(10229,14221);

-- Gossip Menu Option
DELETE FROM `gossip_menu_option` WHERE `menu_id`=9904;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=10129 AND `id` IN (2,4);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`) VALUES
(9904,0,0, 'I would like to build a catapult.',1,1,0,0,0,0, ''),
(9904,1,0, 'I would like to build a demolisher.',1,1,0,0,0,0, ''),
(9904,2,0, 'I would like to build a siege engine.',1,1,0,0,0,0, ''),
(10129,2,0, 'Guide me to the Broken Temple Graveyard.',1,1,0,0,0,0, ''),
(10129,4,0, 'Guide me to the Eastspark Graveyard.',1,1,0,0,0,0, '');
