-- NPC ID 17603 Grandmother gossip_menu_option (new rows)
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7441,7442,7443);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(7441,0,0,"Oh, grandmother, what big ears you have.",  14217,0,0,7442,0,0,0,'',0),
(7442,0,0,"Oh, grandmother, what big eyes you have.",  14219,0,0,7443,0,0,0,'',0),
(7443,0,0,"Oh, grandmother, what phat lewts you have.",14221,0,0,   0,0,0,0,'',0);
