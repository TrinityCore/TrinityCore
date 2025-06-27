DELETE FROM `gossip_menu` WHERE `entry` in(10355,10366,10477);

INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(10355, 14369),
(10366, 14375),
(10477, 14496);

DELETE FROM `gossip_menu_option` WHERE `menu_id` in(10355,10366,10477);

INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(10355, 0, 0, 'We''re ready. Begin the assault!', 33652, 1, 1, 0, 0, 0, 0, NULL, 0),
(10366, 0, 0, 'Activate secondary defensive systems.', 34420, 1, 1, 10477, 0, 0, 0, NULL, 0),
(10477, 0, 0, 'Confirmed.', 34421, 1, 1, 0, 0, 0, 0, NULL, 0);

UPDATE `creature_template` SET `gossip_menu_id`=10355 WHERE  `entry`=33579;
UPDATE `creature_template` SET `gossip_menu_id`=10366 WHERE  `entry`=33686;
