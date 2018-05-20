/*
-- 
-- Quintis Jonespyre --> Add Gossip Text
UPDATE `creature_template` SET `gossip_menu_id`=1922 WHERE `entry`=7879;

DELETE FROM `gossip_menu_option` WHERE `MenuID`=1922;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1922,0,1,"I'd like to purchase more Tharlendris seeds.",4851,3,128,0,0,0,0,"",0,0);
*/
