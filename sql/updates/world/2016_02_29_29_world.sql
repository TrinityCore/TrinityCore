-- Create gossip_menu_option 7731,7732 for NPC 18588 Floon in Terokkar Forest
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (7731,7732) AND `id` = 0;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(7731,0,0,'He wants his "golds." Pay up or die... again...',15564,1,1,0,0,0,0,'',0),
(7732,0,0,"I have been sent by Sal'salabim to collect a debt that you owe. Pay up or I'm going to have to hurt you.",15560,1,1,0,0,0,0,'',0);
