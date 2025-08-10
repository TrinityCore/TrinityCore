DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (9827,9830,9828,9829));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9827, 0, 9, 'I would like to go to the battleground.', 10355, 1048576, 0, 0, 0, 0, 0, NULL, 0, 45745),
(9830, 0, 9, 'I would like to go to the battleground.', 10355, 1048576, 0, 0, 0, 0, 0, NULL, 0, 45745),
(9828, 0, 9, 'I would like to go to the battleground.', 10355, 1048576, 0, 0, 0, 0, 0, NULL, 0, 45745),
(9829, 0, 9, 'I would like to go to the battleground.', 10355, 1048576, 0, 0, 0, 0, 0, NULL, 0, 45745);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=10355, `VerifiedBuild`=45745 WHERE (`MenuID`=10602 AND `OptionID`=0);
