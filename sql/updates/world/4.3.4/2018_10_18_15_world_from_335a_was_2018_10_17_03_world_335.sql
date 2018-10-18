/*
-- 
DELETE FROM `gossip_menu` WHERE `MenuId` IN (21253);
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (7771,21253);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(7771, 0, 0, "Private Weeks, I need another disguise.", 15788, 1, 1, 0, 0, 0, 0, "", 0, 0);

UPDATE `creature_template` SET `gossip_menu_id`=7771 WHERE `entry`=18715;
UPDATE `smart_scripts` SET `event_param1`=7771 WHERE `entryorguid` IN (18715) AND `source_type`=0 AND `id`=2;
*/
