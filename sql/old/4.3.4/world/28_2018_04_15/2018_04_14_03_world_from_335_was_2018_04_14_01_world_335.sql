/*
-- Korfax, Champion of the Light --> Add gossip chatter
DELETE FROM `gossip_menu` WHERE `MenuID` IN (7106,7107,7108);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(7106,8363,0),
(7107,8364,0),
(7108,8365,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=7099 AND `OptionID`=0;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (7106,7107);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7099,0,0,"What is Dreadnaught armor?",11960,1,1,7106,0,0,0,"",0,0),
(7106,0,0,"Continue please.",11962,1,1,7107,0,0,0,"",0,0),
(7107,0,0,"Anything else?",11964,1,1,7108,0,0,0,"",0,0);

UPDATE `npc_text` SET `em0_1`=1, `em0_3`=1, `em0_5`=1 WHERE `ID`=8363;
UPDATE `npc_text` SET `em0_1`=1, `em0_3`=1, `em0_5`=1 WHERE `ID`=8364;
DELETE FROM `npc_text` WHERE `ID`=8365;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`,`em0_1`,`em0_2`,`em0_3`,`em0_4`,`em0_5`) VALUES
(8365,"During your battles with the Scourge in Naxxramas, should you come across desecrated battlements and wartorn plate scraps, return them to me and I shall craft for you a piece of this armor worn by heroes.","",11965,0,1,0,1,0,1,0,0);
*/
