-- new gossip_menu_option entries for Quest 6566 What The Wind Carries
DELETE FROM `gossip_menu_option` WHERE `menu_id`  IN (3664,3665,3666,3667,3668,3669,3670);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3664,0,0,'Please share your wisdom with me, Warchief.',8308,1,1,3665,0,0,0,'',0),
(3665,0,0,'What discoveries?',8310,1,1,3666,0,0,0,'',0),
(3666,0,0,'Usurper?',8312,1,1,3667,0,0,0,'',0),
(3667,0,0,'With all due respect, Warchief - why not allow them to be destroyed? Does this not strengthen our position?',8314,1,1,3668,0,0,0,'',0),
(3668,0,0,'I... I did not think of it that way, Warchief.',8316,1,1,3669,0,0,0,'',0),
(3669,0,0,'I live only to serve, Warchief! My life is empty and meaningless without your guidance.',8318,1,1,3670,0,0,0,'',0),
(3670,0,0,'Of course, Warchief!',8320,1,1,3664,0,0,0,'',0);

-- link gossip_menu_option menu_id to npc_text ID via gossip_menu (3664,4477 already exists)
DELETE FROM `gossip_menu` WHERE `entry` IN (3665,3666,3667,3668,3669,3670);
INSERT INTO `gossip_menu` (`entry`,`text_id`) VALUES
(3665,5733),
(3666,5734),
(3667,5735),
(3668,5736),
(3669,5737),
(3670,5738);
