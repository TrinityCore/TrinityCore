DELETE FROM `gossip_menu_option` WHERE `MenuId`=1291;
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `VerifiedBuild`) VALUES
(1291, 3, 1, 'I want to browse your goods.', 2823, 3, 128,   0,    28153),
(1291, 2, 5, 'Make this inn your home.',     2822, 8, 65536, 0,    28153),
(1291, 1, 0, 'What can I do at an inn?',     4308, 1, 1,     1221, 28153);
