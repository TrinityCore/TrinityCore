DELETE FROM `gossip_menu` WHERE (`entry`=9578 AND `text_id`=12926) OR (`entry`=4825 AND `text_id`=5881) OR (`entry`=8891 AND `text_id`=11645);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES
(9578, 12926), -- 27705
(4825, 5881), -- 5957
(8891, 11645); -- 186267

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=9578 AND `id`=0) OR (`menu_id`=4825 AND `id`=0) OR (`menu_id`=8891 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `box_coded`, `box_money`, `box_text`) VALUES
(9578, 0, 3, 'Please teach me.', 0, 0, ''), -- 27705
(4825, 0, 3, 'Please teach me.', 0, 0, ''), -- 5957
(8891, 0, 0, 'Call the Headless Horseman.', 0, 0, ''); -- 186267

UPDATE `creature_template` SET `gossip_menu_id`=9578 WHERE `entry`=27705;
UPDATE `creature_template` SET `gossip_menu_id`=4825 WHERE `entry`=5957;
