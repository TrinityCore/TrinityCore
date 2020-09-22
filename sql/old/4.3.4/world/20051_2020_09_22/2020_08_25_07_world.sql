DELETE FROM `gossip_menu_option` WHERE (`MenuId`=12523 AND `OptionIndex`=1) OR (`MenuId`=12523 AND `OptionIndex`=0) OR (`MenuId`=11906 AND `OptionIndex`=0) OR (`MenuId`=12554 AND `OptionIndex`=0) OR (`MenuId`=12555 AND `OptionIndex`=0) OR (`MenuId`=12556 AND `OptionIndex`=0) OR (`MenuId`=12557 AND `OptionIndex`=0) OR (`MenuId`=12558 AND `OptionIndex`=0) OR (`MenuId`=12559 AND `OptionIndex`=0) OR (`MenuId`=12560 AND `OptionIndex`=0) OR (`MenuId`=10698 AND `OptionIndex`=1) OR (`MenuId`=10698 AND `OptionIndex`=0) OR (`MenuId`=12192 AND `OptionIndex`=4) OR (`MenuId`=12192 AND `OptionIndex`=0) OR (`MenuId`=12186 AND `OptionIndex`=0) OR (`MenuId`=10835 AND `OptionIndex`=0) OR (`MenuId`=4156 AND `OptionIndex`=0) OR (`MenuId`=11230 AND `OptionIndex`=0) OR (`MenuId`=11229 AND `OptionIndex`=0) OR (`MenuId`=11231 AND `OptionIndex`=0);
INSERT INTO `gossip_menu_option` (`MenuId`, `OptionIndex`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `VerifiedBuild`) VALUES
(12523, 1, 0, 'I wish to unlearn my talents.', 8271, 14333), -- OptionBroadcastTextID: 8271 - 8273 - 29630
(12523, 0, 3, 'I require warrior training.', 3147, 14333),
(11906, 0, 3, 'I wish to learn more of the earth spirits\' secrets. Please train me.', 45124, 14333),
(12554, 0, 0, 'So are the loa still holding to their side of the deal?', 49883, 14333),
(12555, 0, 0, 'So what happened then?', 49881, 14333),
(12556, 0, 0, 'How did the other loa react to this?', 49879, 14333),
(12557, 0, 0, 'What did the spirit want?', 49876, 14333),
(12558, 0, 0, 'What was the vision?', 49871, 14333),
(12559, 0, 0, 'How did you escape Zalazane?', 49869, 14333),
(12560, 0, 0, 'What were you before you were druids, then?', 49867, 14333),
(10698, 1, 3, 'I seek further training in the old ways of the druids.', 36060, 14333),
(10698, 0, 3, 'I seek further training.', 36067, 14333),
(12192, 4, 3, 'Train me in Herbalism.', 47112, 14333),
(12192, 0, 3, 'Train me in Alchemy.', 47109, 14333),
(12186, 0, 3, 'Train me in Alchemy.', 47109, 14333),
(10835, 0, 3, 'I seek further training.', 36067, 14333),
(4156, 0, 3, 'Train me.', 3266, 14333),
(11230, 0, 0, 'I\'m here to challenge you in combat.', 39519, 14333),
(11229, 0, 0, 'I\'m here to challenge you in combat.', 39519, 14333),
(11231, 0, 0, 'I\'m here to challenge you in combat.', 39519, 14333);
