UPDATE `creature_template` SET `gossip_menu_id`=5708, `npcflag`=1 WHERE  `entry`=14353;
UPDATE `creature_template` SET `gossip_menu_id`=5733, `npcflag`=1 WHERE  `entry`=14323;
UPDATE `creature_template` SET `gossip_menu_id`=5746, `npcflag`=1 WHERE  `entry`=11441;
UPDATE `creature_template` SET `gossip_menu_id`=5735, `npcflag`=1 WHERE  `entry`=14326;

DELETE FROM `gossip_menu` WHERE `entry` IN(5708,5715,5740,5733,5746,5735);
INSERT INTO `gossip_menu` (`entry`, `text_id`) VALUES 
(5708, 6876), 
(5708, 6895), 
(5715, 6882), 
(5740, 6916), 
(5733, 6905), 
(5746, 6922), 
(5735, 6907); 

DELETE FROM `gossip_menu_option` WHERE `menu_id` IN(5708,5715,5740,5733,5746,5735);
INSERT INTO `gossip_menu_option` (`menu_id`, `id`, `option_icon`, `option_text`, `OptionBroadcastTextID`, `option_id`, `npc_option_npcflag`, `action_menu_id`, `action_poi_id`, `box_coded`, `box_money`, `box_text`, `BoxBroadcastTextID`) VALUES 
(5708, 0, 0, 'I''m the new king?  What are you talking about?', 9365, 1, 1, 5715, 0, 0, 0, NULL, 0), -- Entry: 14353
(5708, 1, 0, 'Henchmen?  Tribute?', 9440, 1, 1, 5740, 0, 0, 0, NULL, 0), -- Entry: 14353
(5715, 0, 0, 'It''s good to be the king!  Now, let''s get back to what you were talking about before...', 9441, 1, 1, 0, 0, 0, 0, NULL, 0), -- Entry: 14353
(5740, 0, 0, 'Well then... show me the tribute!', 9367, 1, 1, 0, 0, 0, 0, NULL, 0); -- Entry: 14353
