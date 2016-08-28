-- NPC ID / entry 35646 Wormhole (summoned by item 48933 Wormhole Generator: Northrend)

DELETE FROM `gossip_menu_option` WHERE `menu_id`= 10668;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10668, 0, 0, 'Borean Tundra',  35939, 1, 1, 0, 0, 0, 0, '', 0, 0),
(10668, 1, 0, 'Howling Fjord',  35943, 1, 1, 0, 0, 0, 0, '', 0, 0),
(10668, 2, 0, 'Sholazar Basin', 35940, 1, 1, 0, 0, 0, 0, '', 0, 0),
(10668, 3, 0, 'Icecrown',       35941, 1, 1, 0, 0, 0, 0, '', 0, 0),
(10668, 4, 0, 'Storm Peaks',    35942, 1, 1, 0, 0, 0, 0, '', 0, 0),
(10668, 5, 0, 'Underground...', 36022, 1, 1, 0, 0, 0, 0, '', 0, 0);
