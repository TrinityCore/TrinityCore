/*
-- Brumn Winterhoof
UPDATE `creature_template` SET `gossip_menu_id`=3069 WHERE `entry`=7869;

DELETE FROM `gossip_menu` WHERE `MenuID`=3069;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(3069,3803,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=3069;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(3069,0,3,"I would like to train.",5597,5,16,0,0,0,0,"",0,0);
*/
