-- 
UPDATE `creature` SET `id`=5624, `equipment_id`=0 WHERE `guid` IN (41956,38305,41964);
DELETE FROM `creature_addon`  WHERE `guid` IN (41956,38305,41964);
DELETE FROM `creature_template_addon` WHERE `entry` IN (5624);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES
(5624, 0, 0, 0, 257, 0, '12187'); -- 5624 - 12187

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (2849);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(2849, 0, 0, "The auction house", 5515, 1, 1, 10737, 318, 0, 0, "", 0, 0),
(2849, 1, 0, "The bank", 4888, 1, 1, 10738, 319, 0, 0, "", 0, 0),
(2849, 2, 0, "Barber", 45376, 1, 1, 10739, 320, 0, 0, "", 0, 0),
(2849, 3, 0, "The bat handler", 6790, 1, 1, 10740, 321, 0, 0, "", 0, 0),
(2849, 4, 0, "The battlemaster", 10359, 1, 1, 10741, 322, 0, 0, "", 0, 0),
(2849, 5, 0, "The guild master", 7072, 1, 1, 10748, 323, 0, 0, "", 0, 0),
(2849, 6, 0, "The inn", 4893, 1, 1, 10750, 324, 0, 0, "", 0, 0),
(2849, 7, 0, "Locksmith", 33141, 1, 1, 10753, 325, 0, 0, "", 0, 0),
(2849, 8, 0, "The mailbox", 5093, 1, 1, 10755, 326, 0, 0, "", 0, 0),
(2849, 9, 0, "The stable master", 8521, 1, 1, 10761, 327, 0, 0, "", 0, 0),
(2849, 10, 0, "The weapon master", 7259, 1, 1, 10765, 328, 0, 0, "", 0, 0),
(2849, 11, 0, "The zeppelin master", 5518, 1, 1, 10766, 329, 0, 0, "", 0, 0),
(2849, 12, 0, "A class trainer", 6792, 1, 1, 10768, 0, 0, 0, "", 0, 0),
(2849, 13, 0, "A profession trainer", 6793, 1, 1, 10767, 0, 0, 0, "", 0, 0);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=7072 WHERE `MenuID`=10769 AND `OptionID`=5;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5518 WHERE `MenuID`=10769 AND `OptionID`=11;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=7259 WHERE `MenuID`=10769 AND `OptionID`=10;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5093 WHERE `MenuID`=10769 AND `OptionID`=8;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=10359 WHERE `MenuID`=10769 AND `OptionID`=4;
UPDATE `gossip_menu_option` SET `OptionBroadcastTextID`=5515 WHERE `MenuID`=10769 AND `OptionID`=0;
