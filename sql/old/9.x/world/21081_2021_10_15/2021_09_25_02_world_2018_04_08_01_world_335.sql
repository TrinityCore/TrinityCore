-- Rohan the Assassin --> Add gossip option
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7118,7119,7120,7121,7122);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7118,8380,0),
(7119,8381,0),
(7120,8382,0),
(7121,8383,0),
(7122,8384,0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=7101 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (7118,7119,7120,7121);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7101,0,0,"What is it that you do exactly, Rohan?",12003,1,1,0),
(7118,0,0,"So what brings you to Light's Hope?",12005,1,1,0),
(7119,0,0,"What? Bonescythe?",12007,1,1,0),
(7120,0,0,"Wow, you're insane, aren't you?",12009,1,1,0),
(7121,0,0,"Hey wait, Gadgetzan has a disco?",12011,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=7101 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (7118,7119,7120,7121);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7101,0,7118,0),
(7118,0,7119,0),
(7119,0,7120,0),
(7120,0,7121,0),
(7121,0,7122,0);

DELETE FROM `npc_text` WHERE `ID` IN (8380,8381,8382,8383,8384);
INSERT INTO `npc_text` (`ID`,`BroadcastTextID0`,`Probability0`) VALUES
(8380,12004,1),
(8381,12006,1),
(8382,12008,1),
(8383,12010,1),
(8384,12012,1);
