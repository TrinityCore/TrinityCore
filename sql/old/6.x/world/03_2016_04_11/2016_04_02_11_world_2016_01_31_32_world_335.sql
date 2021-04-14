-- Create new gossip_menu_option 3223 for Apothecary Dithers and 3228 for Alchemist Arbington:
DELETE FROM `gossip_menu_option` WHERE `menu_id` IN (3223,3228,3229) AND `OptionBroadcastTextID` IN (6516,6517,6518,6519,6531);
INSERT INTO `gossip_menu_option` (`menu_id`,`id`,`option_icon`,`option_text`,`OptionBroadcastTextID`,`option_id`,`npc_option_npcflag`,`action_menu_id`,`action_poi_id`,`box_coded`,`box_money`,`box_text`,`BoxBroadcastTextID`) VALUES
(3223,0,0,"What's needed for the cauldron at Felstone Field?",6516,3,131,0,0,0,0,'',0),
(3223,1,0,"What's needed for the cauldron at Dalson's Tears?",6517,3,131,0,0,0,0,'',0),
(3223,2,0,"What's needed for the cauldron at the Writhing Haunt?",6518,3,131,0,0,0,0,'',0),
(3223,3,0,"What's needed for the cauldron at Gahrron's Withering?",6519,3,131,0,0,0,0,'',0),
(3228,0,0,"What's needed for the cauldron at Felstone Field?",6516,3,131,0,0,0,0,'',0),
(3228,1,0,"What's needed for the cauldron at Dalson's Tears?",6517,3,131,0,0,0,0,'',0),
(3228,2,0,"What's needed for the cauldron at the Writhing Haunt?",6518,3,131,0,0,0,0,'',0),
(3228,3,0,"What's needed for the cauldron at Gahrron's Withering?",6519,3,131,0,0,0,0,'',0),
(3229,0,0,"I need a Vitreous Focuser.",6531,3,131,0,0,0,0,'',0);
