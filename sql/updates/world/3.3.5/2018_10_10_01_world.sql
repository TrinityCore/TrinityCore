-- 
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (9025,9013,9429,9761);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `ActionMenuId`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionPoiID`) VALUES
(9013, 0, 0, "<Discreetly search the pirate's pockets for Taruk's payment.>",0, 23824, 1, 1,0),
(9429, 0, 0, "I'll show you!  Give me that practice parachute!",0, 25923, 1, 1,0),
(9761, 0, 0, "I require water breathing, Garren.",0, 29212, 1, 1,0),
(9025, 0, 0, "Food & Drink", 8995, 23755, 1, 1,0),
(9025, 1, 0, "Tokens & Souvenirs", 8996, 23756, 1, 1,448),
(9025, 2, 0, "Ram Racing", 8997, 23757, 1, 1,449),
(9025, 3, 0, "Brew of the Month Club", 9558, 26734, 1, 1,450),
(9025, 4, 0, "Dark Iron Dwarf Attacks", 9018, 0, 1, 1,0);

UPDATE `creature_template` SET `gossip_menu_id`=9013 WHERE `entry`=24788;

DELETE FROM `gossip_menu` WHERE (`MenuId`=9025);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(9025, 12195, 26365);

UPDATE `smart_scripts` SET `event_param1`=9013 WHERE `entryorguid`=24788 AND `source_type`=0 AND `id`=3;
