-- Huntsman Leopold --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuId` IN (7112,7111);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(7111,8369,0),
(7112,8370,0);

DELETE FROM `gossip_menu_option` WHERE `MenuId`=7102 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuId`=7111;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `VerifiedBuild`) VALUES
(7102,0,0,"What is Cryptstalker armor?",11978,1,1,0),
(7111,0,0,"Continue please.",11980,1,1,0);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=7102 AND `OptionIndex`=0;
DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=7111;
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(7102,0,7111,0),
(7111,0,7112,0);

DELETE FROM `npc_text` WHERE `ID` IN (8369,8370);
INSERT INTO `npc_text` (`ID`, `BroadcastTextID0`, `Probability0`) VALUES
(8369,11979,1),
(8370,11981,1);
