-- NPC ID 37596, Lady Sylvanas Windrunner
DELETE FROM `gossip_menu_option` WHERE `menu_id`= 10971;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`,`VerifiedBuild`) VALUES
(10971, 0, 0, "What would you have of me, Banshee Queen?", 37549, 1, 1, 0, 0, 0, 0, '', 0, 0);
