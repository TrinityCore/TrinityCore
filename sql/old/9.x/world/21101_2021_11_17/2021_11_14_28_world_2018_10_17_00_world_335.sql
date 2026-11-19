-- 
DELETE FROM `gossip_menu` WHERE (`MenuId`=6045 AND `TextId`=7199) OR (`MenuId`=6046 AND `TextId`=7198) OR (`MenuId`=5981 AND `TextId`=7134) OR (`MenuId`=21332 AND `TextId`=7199) OR (`MenuId`=21333 AND `TextId`=7156) OR (`MenuId`=21334 AND `TextId`=7256);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(6045, 7199, 41031), -- 10162 (Lord Victor Nefarius)
(6046, 7198, 41031), -- 10162 (Lord Victor Nefarius)
(5981, 7134, 41031); -- 10162 (Lord Victor Nefarius)

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=0 WHERE `MenuId` IN (21334,21333);

DELETE FROM `gossip_menu_option` WHERE `MenuId` IN (6045,6046,5981,6101,6021,6001,21332);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(6045, 0, 0, 'Please do.', 9906, 41031),
(6046, 0, 0, 'You have lost your mind, Nefarius. You speak in riddles.', 9904, 41031),
(5981, 0, 0, 'I\'ve made no mistakes.', 9902, 41031),
(6101, 0, 0, 'Vaelastrasz, no!!!', 10011, 41031),
(6021, 0, 0, 'I cannot, Vaelastrasz! Surely something can be done to heal you!', 9847, 41031),
(6001, 0, 0, '<Place my hand on the orb.>', 9859, 41031);

DELETE FROM `gossip_menu_option_action` WHERE (`OptionIndex`=0 AND `MenuId` IN (6046,5981,6021));
INSERT INTO `gossip_menu_option_action` (`MenuId`, `OptionIndex`, `ActionMenuId`, `ActionPoiId`) VALUES
(6046, 0, 6045, 0),
(5981, 0, 6046, 0),
(6021, 0, 6101, 0);

UPDATE `creature_template` SET `gossip_menu_id`=6021 WHERE `entry`=13020;
