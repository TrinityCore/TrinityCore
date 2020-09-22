DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12341 AND `OptionIndex`=1) OR (`MenuId`=11198 AND `OptionIndex`=0) OR (`MenuId`=10028 AND `OptionIndex`=1) OR (`MenuId`=10708 AND `OptionIndex`=1);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(12341, 1, 0, 'I wish to unlearn my talents.', 8271, 15005), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(11198, 0, 0, 'Greely, can you get me back into that footbomb uniform?', 48152, 15005),
(10028, 1, 0, '<Seize control of an Eidolon Watcher through the eye.>', 31719, 15005),
(10708, 1, 0, 'I need to borrow your tamed jungle cat to get to the cliffs, Kilag.', 36519, 15005);

UPDATE `gossip_menu_option` SET `OptionBroadcastTextId`=44455, `VerifiedBuild`=15005 WHERE (`MenuId`=11809 AND `OptionIndex`=0);
