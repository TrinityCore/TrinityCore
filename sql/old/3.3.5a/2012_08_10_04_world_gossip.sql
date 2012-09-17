-- -18754 Barim Splithoof Leather working trainer
DELETE FROM `gossip_menu_option` WHERE `menu_id`=7816;
INSERT INTO `gossip_menu_option` VALUES
(7816,0,3, 'I would like to train.', 5,16,0,0,0,0,NULL),
(7816,1,1, 'Let me browse your goods.', 3,128,0,0,0,0,NULL);
