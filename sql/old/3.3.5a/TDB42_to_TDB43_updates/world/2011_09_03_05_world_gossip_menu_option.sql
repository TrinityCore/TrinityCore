DELETE FROM `gossip_menu_option` WHERE `menu_id`=1293 AND `id`=1;
DELETE FROM `gossip_menu_option` WHERE `menu_id`=1293 AND `id`=2;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`) VALUES
(1293,1,0, 'Make this inn my home!',8,66179,0,0,0,0,NULL),
(1293,2,1, 'I want to browse your goods!',3,66179,0,0,0,0,NULL);