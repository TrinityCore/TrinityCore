/*
-- Witch Doctor Uzer'i --> Add Gossip Option
DELETE FROM `gossip_menu` WHERE `MenuID`=1289;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1289,1924,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=1141;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1141,0,0,"Tell me more about muisek.",4419,1,1,1289,0,0,0,"",0,0);
*/
