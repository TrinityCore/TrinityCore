-- 
UPDATE `creature_template` SET `gossip_menu_id`=5981 WHERE `entry`=10162;
DELETE FROM `gossip_menu_option` WHERE `MenuID`IN (21331,21330);
DELETE FROM `gossip_menu` WHERE `MenuID`IN (21331,21330);
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6045,5981,6046);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`) VALUES 
(6045, 0, 0, 'Please do.', 9906, 1, 1, 0),
(5981, 0, 0, "I've made no mistakes.", 9902, 1, 1, 6046),
(6046, 0, 0, "You have lost your mind, Nefarius. You speak in riddles.", 9904, 1, 1, 6045);

DELETE FROM `gossip_menu` WHERE `MenuId` IN (5981,6046) AND `TextId` IN (7134,7198);
INSERT INTO `gossip_menu` (`MenuId`, `TextId`, `VerifiedBuild`) VALUES
(5981, 7134, 0),
(6046, 7198, 0);
