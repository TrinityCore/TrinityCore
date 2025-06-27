-- Vinchaxa
UPDATE `creature_template` SET `gossip_menu_id`=6424 WHERE `entry`=15070;

DELETE FROM `gossip_menu` WHERE `MenuID`=6424;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6424,7717,0);

-- Servant of the Hand
UPDATE `creature_template` SET `gossip_menu_id`=6425 WHERE `entry`=15080;

DELETE FROM `gossip_menu` WHERE `MenuID`=6425;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(6425,7718,0);

-- Rin'wosho the Trader
DELETE FROM `gossip_menu_option` WHERE `MenuID`=6381;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6381,0,1,"Let us barter, Rin'wosho. Show me what goods are available!",10441,3,128,0,0,0,0,"",0,0);
