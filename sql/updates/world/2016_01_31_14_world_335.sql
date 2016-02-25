-- new gossip_menu for NPC 1855 Tirion Fordring:
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3502,3681,3682,3683) AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3502,0,0,'I am ready to hear your tale, Tirion.',    7219,1,1,3681,0,0,0,'',0),
(3681,0,0,'Thank you, Tirion. What of your identity?',7221,1,1,3682,0,0,0,'',0),
(3682,0,0,'That is terrible.',                        7223,1,1,3683,0,0,0,'',0),
(3683,0,0,'I will, Tirion.',                          7225,1,1,   0,0,0,0,'',0);
