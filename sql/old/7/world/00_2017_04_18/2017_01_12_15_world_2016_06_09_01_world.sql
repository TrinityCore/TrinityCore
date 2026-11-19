-- Majordomo Executus' gossip when friendly (entry 12018 in 3.3.5)
UPDATE `creature_template` SET `gossip_menu_id` = 4093 WHERE `entry` = 12018;

DELETE FROM `gossip_menu` WHERE `entry` IN (4108,4109,4093) AND `text_id` IN (4995,5011,5012);
INSERT INTO gossip_menu (`entry`,`text_id`) VALUES
(4093, 4995), -- 54404 (Majordomo Executus' DB entry ID from retail)
(4109, 5011), -- 54404 (Majordomo Executus' DB entry ID from retail)
(4108, 5012); -- 54404 (Majordomo Executus' DB entry ID from retail)

DELETE FROM `gossip_menu_option` WHERE (`menu_id`=4108 AND `id`=0) OR (`menu_id`=4109 AND `id`=0) OR (`menu_id`=4093 AND `id`=0);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(4093,0,0, 'Tell me more.',                                                            7675,1,1,4109,0,0,0,'',0), -- menu_id + text in TDB 6.04
(4109,0,0, 'What else do you have to say?',                                            7673,1,1,4108,0,0,0,'',0), -- menu_id + text in TDB 6.04
(4108,0,0, 'You challenged us and we have come. Where is this master you speak of?\n', 7646,1,1,   0,0,0,0,'',0); -- menu_id + text in TDB 6.04
