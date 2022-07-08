-- Rayne --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7123,7124,7125);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7123,8385,0),
(7124,8386,0),
(7125,8387,0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=7104 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (7123,7124);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7104,0,0,"Hello, Rayne. What brings the Cenarion Circle to the Plaguelands?",12015,1,1,0),
(7123,0,0,"Are these lands not beyond healing? They look pretty beat up.",12017,1,1,0),
(7124,0,0,"What kind of services?",12019,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=7104 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (7123,7124);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuID`, `ActionPoiID`) VALUES
(7104,0,7123,0),
(7123,0,7124,0),
(7124,0,7125,0);

DELETE FROM `npc_text` WHERE `ID` IN (8385,8386,8387);
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(8385,12016,1),
(8386,12018,1),
(8387,12020,1);
