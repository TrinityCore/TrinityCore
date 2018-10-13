/*
-- Franclorn Forgewright
DELETE FROM `gossip_menu` WHERE `MenuID`=1667;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(1667,2319,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID`=1666;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1666,0,0,"Just show me the way, Franclorn.",4654,1,1,1667,0,0,0,"",0,0);

DELETE FROM `npc_text` WHERE `ID`=2319;
INSERT INTO `npc_text` (`ID`, `text0_0`, `text0_1`, `BroadcastTextID0`, `lang0`, `Probability0`, `em0_0`, `em0_1`, `em0_2`, `em0_3`, `em0_4`, `em0_5`) VALUES
(2319,"You will find Fineous Darkvire beyond the Ring of Law, in the Hall of Crafting. Kill the miserable cur and recover Ironfel.$B$BTake Ironfel to the Shrine of Thaurissan and place the hammer in its rightful place: In the hands of the statue erected in my honor.$B$BWhen this is done, the compartment in which I stored the master key will open. More importantly, Ironfel will remain forever in my grasp. Should they make an attempt to remove the hammer; both the statue and hammer will shatter, lost forever.","",4655,0,1,0,0,0,0,0,0);
*/
