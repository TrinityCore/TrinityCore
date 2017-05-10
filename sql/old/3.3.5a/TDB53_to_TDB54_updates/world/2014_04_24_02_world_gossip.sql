--
DELETE FROM `gossip_menu` WHERE `entry`=8725 AND `text_id`=11030;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(8725, 11030); -- 23093

DELETE FROM `gossip_menu_option` WHERE `menu_id`=8725 AND `id`=0;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(8725, 0, 0, 'I am an envoy of Balthas. He has sent me to collect a flawless arcane essence.', 0, 0, ''); -- 23093
