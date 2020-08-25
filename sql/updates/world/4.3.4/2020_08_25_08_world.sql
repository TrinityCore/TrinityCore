DELETE FROM `gossip_menu_option` WHERE (`MenuId`=5041 AND `OptionIndex`=0) OR (`MenuId`=9989 AND `OptionIndex`=0) OR (`MenuId`=10469 AND `OptionIndex`=3) OR (`MenuId`=10940 AND `OptionIndex`=0) OR (`MenuId`=10472 AND `OptionIndex`=3) OR (`MenuId`=12447 AND `OptionIndex`=0) OR (`MenuId`=10343 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(5041, 0, 0, 'How much more blood is needed, Commander?', 8641, 14007),
(9989, 0, 0, 'I\'m ready to ride.', 31366, 14007), -- OptionBroadcastTextID: 31366 - 50996
(10469, 3, 0, 'I am ready to fight!', 33430, 14007),
(10940, 0, 0, 'Mahka wants you to come see her, Mankrik.', 37755, 14007),
(10472, 3, 0, 'I am ready to fight!', 33430, 14007),
(12447, 0, 0, 'I lost my Blackrock Disguise, sir.  May I have another?', 48851, 14007),
(10343, 1, 0, 'I am ready to fight!', 33430, 14007);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=41055, `VerifiedBuild`=14007 WHERE (`MenuId`=11460 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47954, `VerifiedBuild`=14007 WHERE (`MenuId`=12296 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47975, `VerifiedBuild`=14007 WHERE (`MenuId`=12298 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=47976, `VerifiedBuild`=14007 WHERE (`MenuId`=12297 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=37720, `VerifiedBuild`=14007 WHERE (`MenuId`=10958 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=52088, `VerifiedBuild`=14007 WHERE (`MenuId`=12880 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44578, `VerifiedBuild`=14007 WHERE (`MenuId`=11832 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=35051, `VerifiedBuild`=14007 WHERE (`MenuId`=10567 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=35050, `VerifiedBuild`=14007 WHERE (`MenuId`=10567 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=35020, `VerifiedBuild`=14007 WHERE (`MenuId`=10560 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=35012, `VerifiedBuild`=14007 WHERE (`MenuId`=10556 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=40425, `VerifiedBuild`=14007 WHERE (`MenuId`=9157 AND `OptionIndex`=1);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=4652, `VerifiedBuild`=14007 WHERE (`MenuId`=1667 AND `OptionIndex`=0);
UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=2822, `VerifiedBuild`=14007 WHERE (`MenuId`=8884 AND `OptionIndex`=0);
