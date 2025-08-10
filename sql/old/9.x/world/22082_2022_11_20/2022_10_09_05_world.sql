
DELETE FROM `gossip_menu` WHERE (`MenuID`=26904 AND `TextID`=42825);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(26904, 42825, 45745); -- 178170 (Night Guardian Vekraala)

DELETE FROM `gossip_menu_option` WHERE (`MenuID`=7811 AND `OptionID`=0) OR (`MenuID`=26904 AND `OptionID` IN (0,1));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7811, 0, 6, 'I would like to check my deposit box.', 3398, 131072, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26904, 0, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(26904, 1, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745);
