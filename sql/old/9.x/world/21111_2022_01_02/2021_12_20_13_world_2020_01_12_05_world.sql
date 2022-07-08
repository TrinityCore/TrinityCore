-- 
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6815) AND `OptionIndex`=4;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6899) AND `OptionIndex`=2;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES 
(6815, 4, 0, "Where is Elder Darkhorn?", 11584, 1, 1, 0),
(6899, 2, 0, "Where is Elder Wheathoof?", 11582, 1, 1, 0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuID` IN (6815) AND `OptionIndex`=4;
DELETE FROM `gossip_menu_option_action` WHERE `MenuID` IN (6899) AND `OptionIndex` IN (1,2);
INSERT INTO `gossip_menu_option_action` (`MenuID`, `OptionIndex`, `ActionMenuID`, `ActionPoiID`) VALUES 
(6815, 4, 6896, 0),
(6899, 1, 6854, 0),
(6899, 2, 6895, 0);

-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21097 WHERE `MenuID` = 6815 AND `OptionIndex` = 1;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21107 WHERE `MenuID` = 6815 AND `OptionIndex` = 2;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21147 WHERE `MenuID` = 6815 AND `OptionIndex` = 3;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21086 WHERE `MenuID` = 6899 AND `OptionIndex` = 0;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 6854  WHERE `MenuID` = 6899 AND `OptionIndex` = 1;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21122 WHERE `MenuID` = 6899 AND `OptionIndex` = 3;
-- UPDATE `gossip_menu_option_action` SET `ActionMenuID` = 21147 WHERE `MenuID` = 6899 AND `OptionIndex` = 4;
