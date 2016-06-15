-- new gossip_menu for NPC 3678 Disciple of Naralex:
DELETE FROM `gossip_menu_option` WHERE `menu_id`= 201 AND `OptionBroadcastTextID`= 2662;
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(201, 0, 0, 'Let the event begin!', 2662, 1, 1, 0, 0, 0, 0, '', 0);
