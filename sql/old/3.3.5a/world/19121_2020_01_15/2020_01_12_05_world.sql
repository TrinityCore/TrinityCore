-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6815) AND `OptionID`=4;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6899) AND `OptionID`=2;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES 
(6815, 4, 0, "Where is Elder Darkhorn?", 11584, 1, 1, 6896, 0, 0, 0, '', 0, 0),
(6899, 2, 0, "Where is Elder Wheathoof?", 11582, 1, 1, 6895, 0, 0, 0, '', 0, 0);

UPDATE `gossip_menu_option` SET `ActionMenuID` = 21097 WHERE `MenuID` = 6815 AND `OptionID` = 1;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 21107 WHERE `MenuID` = 6815 AND `OptionID` = 2;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 21147 WHERE `MenuID` = 6815 AND `OptionID` = 3;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 21086 WHERE `MenuID` = 6899 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 6854  WHERE `MenuID` = 6899 AND `OptionID` = 1;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 21122 WHERE `MenuID` = 6899 AND `OptionID` = 3;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 21147 WHERE `MenuID` = 6899 AND `OptionID` = 4;
