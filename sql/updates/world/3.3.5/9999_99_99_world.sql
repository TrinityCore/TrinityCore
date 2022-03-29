-- Quest Chasing the Moonstone (11194)
UPDATE `creature_template` SET `gossip_menu_id`=8658 WHERE `entry`=23002;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8658) AND `OptionID` IN (1);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8658, 1, 0, 'Hand over the Southfury moonstone and I\'ll let you go.', 20723, 0, 0, 0, 0, 0, 0, NULL, 0, 0);

-- Quest Cairne's Hoofprint (925)
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5851) AND `OptionID` IN (1);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5851, 1, 0, 'Chief Bloodhoof, this may sound like an odd request... but I have a young ward who is quite shy.  You are a hero to him, and he asked me to get your hoofprint.', 9670, 0, 0, 0, 0, 0, 0, NULL, 0, 0);

-- ZulAman
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8799,8874,8927,8881) AND `OptionID` IN (1);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8799, 1, 0, 'It\'s safe to come out now.', 61264, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(8874, 1, 0, 'It\'s safe to come out now.', 61264, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(8927, 1, 0, 'It\'s safe, little gnome. You can come out now.', 23154, 0, 0, 0, 0, 0, 0, NULL, 0, 0),
(8881, 1, 0, 'It\'s safe to come out now.', 61264, 0, 0, 0, 0, 0, 0, NULL, 0, 0);
