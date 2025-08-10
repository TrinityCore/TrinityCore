DELETE FROM `gossip_menu_option` WHERE (`MenuID`=1626 AND `OptionID` IN (1,0)) OR (`MenuID`=5461 AND `OptionID` IN (0,1)) OR  (`MenuID`=7487 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1626, 0, 8, 'I want to create a guild crest.', 3415, 524288, 0, 0, 0, 0, 0, NULL, 0, 45745),
(1626, 1, 7, 'How do I form a guild?', 3413, 262144, 0, 0, 0, 0, 0, NULL, 0, 45745),
(5461, 0, 8, 'I want to create a guild crest.', 3415, 524288, 0, 0, 0, 0, 0, NULL, 0, 45745),
(5461, 1, 7, 'How do I form a guild?', 3413, 262144, 0, 0, 0, 0, 0, NULL, 0, 45745),
(7487, 0, 7, 'How do I form a guild?', 3413, 262144, 0, 0, 0, 0, 0, NULL, 0, 45745),
(7487, 1, 8, 'I want to create a guild crest.', 3415, 524288, 0, 0, 0, 0, 0, NULL, 0, 45745);
