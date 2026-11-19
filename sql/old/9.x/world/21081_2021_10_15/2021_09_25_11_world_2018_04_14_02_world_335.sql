-- Rimblat Earthshatter --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuId` IN (7113,7114,7115);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7113,8371,0),
(7114,8372,0),
(7115,8373,0);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (7103,7113,7114);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7103,0,0,"What brings a tauren to the Plaguelands?",11983,1,1,0),
(7113,0,0,"Continue please.",11985,1,1,0),
(7114,0,0,"Continue please.",11985,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (7103,7113,7114);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7103,0,7113,0),
(7113,0,7114,0),
(7114,0,7115,0);

DELETE FROM `npc_text` WHERE `ID` IN (8371,8372,8373);
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(8371,11984,1),
(8372,11986,1),
(8373,11987,1);
