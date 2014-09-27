--
DELETE FROM `gossip_menu` WHERE `entry`=10318 AND `text_id`=14324;
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(10318, 14324); -- 33238

DELETE FROM `gossip_menu_option` WHERE `menu_id`=10318 AND `id`=7;
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(10318, 7, 0, 'Stormwind Champion''s Pennant', 0, 0, ''); -- 33238
