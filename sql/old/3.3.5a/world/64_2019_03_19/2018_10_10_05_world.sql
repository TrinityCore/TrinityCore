-- 
DELETE FROM `gossip_menu_option` WHERE (`MenuID`=9165 AND `OptionID`=1) OR (`MenuID`=9165 AND `OptionID`=0) OR (`MenuID`=9219 AND `OptionID`=0) OR (`MenuID`=9218 AND `OptionID`=0) OR (`MenuID`=9217 AND `OptionID`=0);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `VerifiedBuild`) VALUES
(9165, 1, 0, 'Crafty, I need another Warsong banner.', 24760, 26365),   -- need condition SAI
(9165, 0, 0, 'Crafty, I lost my Warsong orc disguise.', 24759, 26365),   -- need condition SAI
(9219, 0, 0, 'How long have you worked for the Cult of the Damned?', 25242, 26365), -- need conditions an maybe convert the cpp to SAI
(9218, 0, 0, 'I have reason to believe you\'re involved in cultist activity.', 25239, 26365), -- need conditions an maybe convert the cpp to SAI
(9217, 0, 0, 'What do you know about the Cult of the Damned?', 25237, 26365); -- need conditions an maybe convert the cpp to SAI
