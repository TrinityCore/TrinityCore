-- 
DELETE FROM `gossip_menu_option`  WHERE `MenuID` IN (6620);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`) VALUES
(6620, 0, 0, "Trick or Treat!", 10693, 1, 1),
(6620, 1, 5, "Make this inn your home.", 2822, 8, 65536),
(6620, 2, 1, "I want to browse your goods.", 3370, 3, 128);
