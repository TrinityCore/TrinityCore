-- Insert missing gossip_menu_option 21213 for Sorcerer Ashcrombe and 21214 for Deathstalker Adamant:
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (21213,21214) AND `OptionBroadcastTextID`= 2802;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(21213,0,0,'Please unlock the courtyard door.',2802,1,1,0,0,0,0,'',0),
(21214,0,0,'Please unlock the courtyard door.',2802,1,1,0,0,0,0,'',0);
