-- Missing Gossip Otions for "Galaen's Journal"
DELETE FROM `gossip_menu_option` WHERE `MenuID`IN (7493,7492,7491);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7493,0,0,"<Turn to the next page.>",14429,1,1,7492,0,0,0,"",0,0),
(7492,0,0,"<Turn to the next page.>",14429,1,1,7491,0,0,0,"",0,0),
(7491,0,0,"<Turn to the next page.>",14429,1,1,7490,0,0,0,"",0,0);
