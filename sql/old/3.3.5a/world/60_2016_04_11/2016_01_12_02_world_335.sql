-- Insert missing gossip_menu_option 3801 for Myranda the Hag:
DELETE FROM `gossip_menu_option` WHERE `menu_id`= 3801 AND `OptionBroadcastTextID`= 7306;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3801,0,0,'I am ready for the illusion, Myranda.',7306,2,3,0,0,0,0,'',0);
