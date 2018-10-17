-- 
DELETE FROM `gossip_menu` WHERE `MenuId`=6045 AND `TextId`=7199;
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(6045, 7199, 0);

DELETE FROM `gossip_menu` WHERE `MenuId` IN (21334,21333,21332);
DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (6045,6021,6101,21334,21333,21332);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(6021, 0, 0, "I cannot Vaelastraz! Surely something can be done to heal you!", 9847, 1, 1, 6101, 0, 0, 0, "", 0, 0),
(6101, 0, 0, "Vaelastraz,, no!!", 10011, 1, 1, 0, 0, 0, 0, "", 0, 0);
UPDATE `creature_template` SET `gossip_menu_id`=6021 WHERE `entry`=13020;
