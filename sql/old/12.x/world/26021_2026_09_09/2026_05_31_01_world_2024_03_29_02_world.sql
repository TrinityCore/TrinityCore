-- Missing Gossip Otions for "Galaen's Journal"
DELETE FROM `gossip_menu_option` WHERE `MenuID`IN (7493,7492,7491);
INSERT INTO `gossip_menu_option` (`MenuID`, `GossipOptionID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextID`, `Language`, `Flags`, `ActionMenuID`, `ActionPoiID`, `GossipNpcOptionID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `OverrideIconID`, `VerifiedBuild`) VALUES
(7493,34920,0,0,'<Turn to the next page.>',14429,0,0,7492,0,NULL,0,0,NULL,0,NULL,NULL,67823),
(7492,34919,0,0,'<Turn to the next page.>',14429,0,0,7491,0,NULL,0,0,NULL,0,NULL,NULL,67823),
(7491,34141,0,0,'<Turn to the next page.>',14429,0,0,7490,0,NULL,0,0,NULL,0,NULL,NULL,67823);

UPDATE `gossip_menu_option` SET `GossipOptionID`=31606, `VerifiedBuild`=67823 WHERE (`MenuID`=7459 AND `OptionID`=0);
