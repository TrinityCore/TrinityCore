DELETE FROM `gossip_menu` WHERE `MenuID` IN (13921, 14200);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES
(13921, 4433),
(14200, 16570);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (13921, 14200, 12529);
INSERT INTO `gossip_menu_option`(`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcflag`) VALUES
(13921, 0, 3, 'I seek more training in the priestly ways.', 7169, 5, 16),
(14200, 0, 3, 'I seek training in the ways of the Hunter.', 7643, 5, 16),
(12529, 0, 3, 'Teach me the ways of the spirits.', 7658, 5, 16),
(12529, 1, 0, 'I wish to unlearn my talents.', 62295, 16, 16),
(12529, 2, 0, 'I wish to know about Dual Talent Specialization.', 33762, 20, 1);

DELETE FROM `gossip_menu_option_trainer` WHERE `MenuId` IN (13921, 14200, 8110, 12529);
INSERT INTO `gossip_menu_option_trainer` (`MenuId`, `OptionIndex`, `TrainerId`) VALUES
(13921, 0, 3),
(14200, 0, 15),
(8110, 0, 124),
(12529, 0, 124);

UPDATE `creature_template` SET `gossip_menu_id`= 13921 WHERE `entry`= 375;
UPDATE `creature_template` SET `gossip_menu_id`= 14200 WHERE `entry`= 43278;
UPDATE `creature_template` SET `gossip_menu_id`= 12529 WHERE `entry`= 44394;
