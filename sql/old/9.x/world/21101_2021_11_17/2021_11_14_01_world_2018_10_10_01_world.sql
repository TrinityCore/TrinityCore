-- 
UPDATE `gossip_menu_option` SET `OptionType`=1,`OptionNpcFlag`=1 WHERE `MenuId` IN (9013,9429,9761) AND `OptionIndex`=0;

DELETE FROM `gossip_menu_option` WHERE `MenuId`=9025;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(9025, 0, 0, "Food & Drink", 23755, 1, 1),
(9025, 1, 0, "Tokens & Souvenirs", 23756, 1, 1),
(9025, 2, 0, "Ram Racing", 23757, 1, 1),
(9025, 3, 0, "Brew of the Month Club", 26734, 1, 1),
(9025, 4, 0, "Dark Iron Dwarf Attacks", 23837, 1, 1);

DELETE FROM `gossip_menu_option_action` WHERE `MenuId`=9025;
INSERT INTO `gossip_menu_option_action` (`MenuID`, `OptionIndex`, `ActionMenuId`, `ActionPoiID`) VALUES
(9025, 0, 8995, 0),
(9025, 1, 8996, 448),
(9025, 2, 8997, 449),
(9025, 3, 9558, 450),
(9025, 4, 9018, 0);

-- UPDATE `creature_template` SET `gossip_menu_id`=9013 WHERE `entry`=24788;

DELETE FROM `gossip_menu` WHERE (`MenuId`=9025);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(9025, 12195, 26365);

UPDATE `smart_scripts` SET `event_param1`=9013 WHERE `entryorguid`=24788 AND `source_type`=0 AND `id`=3;
