UPDATE `creature_template` SET `gossip_menu_id`=0 WHERE `entry`=5119; -- Hegnar Swiftaxe
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=15722; -- Squire Leoren Mal'derath
UPDATE `creature_template` SET `gossip_menu_id`=9821 WHERE `entry`=19019; -- Luftasia
UPDATE `creature_template` SET `gossip_menu_id`=15134 WHERE `entry`=26377; -- Squire Percy
UPDATE `creature_template` SET `gossip_menu_id`=23691 WHERE `entry`=6727; -- Innkeeper Brianna

DELETE FROM `gossip_menu` WHERE (`MenuID`=20405 AND `TextID`=29878) OR (`MenuID`=20356 AND `TextID`=30445) OR (`MenuID`=23691 AND `TextID`=820);
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(20405, 29878, 45745), -- 110810 (Almenis)
(20356, 30445, 45745), -- 112323 (Amurra Thistledew)
(23691, 820, 45745); -- 6727 (Innkeeper Brianna)

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=0 AND `MenuID` IN (20356,20405,6568)) OR (`OptionID`=1 AND `MenuID` IN (20004,20177));
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(20356, 0, 1, 'Let\'s see what you have.', 11820, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(20405, 0, 28, 'I can help you procure some valuable items.', 119001, 68719476736, 0, 0, 0, 0, 0, NULL, 0, 45745),
(6568, 0, 1, 'Show me what I can learn.', 10761, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(20004, 1, 28, 'We await your request.', 121509, 68719476736, 0, 0, 0, 0, 0, NULL, 0, 45745),
(20177, 1, 0, 'Why can\'t I research Artifact Knowledge?', 130505, 1, 0, 21664, 0, 0, 0, NULL, 0, 45745);

DELETE FROM `gossip_menu_option` WHERE (`OptionID`=1 AND `MenuID` IN (23691,14674,23608)) OR (`OptionID`=0 AND `MenuID` IN (11100,14674,11095,2464,23691)) OR (`OptionID`=12 AND `MenuID`=15125) OR (`OptionID`=13 AND `MenuID`=15125) OR (`OptionID`=11 AND `MenuID`=15125);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(23691, 1, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(14674, 1, 1, 'What do you have for sale?', 10182, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(11100, 0, 1, 'I wish to browse your wares.', 4424, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(15125, 12, 0, 'Tell me about production professions.', 47107, 1, 0, 12186, 0, 0, 0, NULL, 0, 45745),
(15125, 13, 1, 'Show me your wares, please.', 41360, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(14674, 0, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(11095, 0, 1, 'I wish to browse your wares.', 4424, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(2464, 0, 1, 'Let me browse your goods.', 2823, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(23608, 1, 1, 'I wish to trade.', 122362, 128, 0, 0, 0, 0, 0, NULL, 0, 45745),
(23691, 0, 5, 'Make this inn your home.', 2822, 65536, 0, 0, 0, 0, 0, NULL, 0, 45745),
(15125, 11, 0, 'Tell me about gathering professions.', 47106, 1, 0, 12185, 0, 0, 0, NULL, 0, 45745);
