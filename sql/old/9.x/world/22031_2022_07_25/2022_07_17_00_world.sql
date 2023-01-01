-- Gossip: 1291 NPC: 291 Innkeeper Farley (Area: Lion's Pride Inn - Difficulty: 0)
DELETE FROM `gossip_menu_option` WHERE `MenuID`=1291;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(1291, 0, 0, 'What can I do at an inn?', 4308, 1, 1, 0, 1221, 0, 0, 0, NULL, 0, 44325),
(1291, 2, 1, 'I want to browse your goods.', 3370, 3, 512, 0, 0, 0, 0, 0, NULL, 0, 44325),
(1291, 1, 5, 'Make this inn your home.', 2822, 8, 65536, 0, 0, 0, 0, 0, NULL, 0, 44325);

-- Gossip 342 NPC: 6740 Innkeeper Allison (Area: Trade District - Difficulty: 0)
DELETE FROM `gossip_menu_option` WHERE `MenuID`=342;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(342, 1, 1, 'Let me browse your goods.', 2823, 3, 512, 0, 0, 0, 0, 0, NULL, 0, 44325), -- OptionBroadcastTextID: 2823 - 7509 - 8097
(342, 0, 5, 'Make this inn your home.', 2822, 8, 65536, 0, 0, 0, 0, 0, NULL, 0, 44325); -- OptionBroadcastTextID: 2822 - 162070

-- Gossip 345 NPC: 44235 Thaegra Tillstone (Area: The Canals - Difficulty: 0)
DELETE FROM `gossip_menu_option` WHERE `MenuID`=345;
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextId`, `OptionType`, `OptionNpcFlag`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(345, 0, 5, 'Make this inn your home.', 2822, 8, 65536, 0, 0, 0, 0, 0, NULL, 0, 44325), -- OptionBroadcastTextID: 2822 - 162070
(345, 1, 1, 'Let me browse your goods.', 2823, 3, 512, 0, 0, 0, 0, 0, NULL, 0, 44325); -- OptionBroadcastTextID: 2823 - 7509 - 8097

-- remove old condition for Trick & Treat Hallows End
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 15 AND `SourceGroup` IN (1291, 342, 345);
