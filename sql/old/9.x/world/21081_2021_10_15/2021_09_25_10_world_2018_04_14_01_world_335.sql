-- Korfax, Champion of the Light --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuId` IN (7106,7107,7108);
INSERT INTO `gossip_menu` (`MenuId`, `TextID`, `VerifiedBuild`) VALUES
(7106,8363,0),
(7107,8364,0),
(7108,8365,0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=7099 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (7106,7107);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7099,0,0,"What is Dreadnaught armor?",11960,1,1,0),
(7106,0,0,"Continue please.",11962,1,1,0),
(7107,0,0,"Anything else?",11964,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=7099 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option_action` WHERE `MenuId` IN (7106,7107);
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7099,0,7106,0),
(7106,0,7107,0),
(7107,0,7108,0);

DELETE FROM `npc_text` WHERE `ID`=8365;
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(8365,11965,1);
