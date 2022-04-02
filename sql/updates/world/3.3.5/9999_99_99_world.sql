--
ALTER TABLE `gossip_menu_option` MODIFY `VerifiedBuild` int(11) NOT NULL DEFAULT '0';

-- Quest Chasing the Moonstone (11194)
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (57025) AND `OptionID` IN (0);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(57025, 0, 0, 'Hand over the Southfury moonstone and I\'ll let you go.', 20723, 1, 1, 0, 0, 0, 0, NULL, 0, 0);

-- Quest Cairne's Hoofprint (925), credit: vmangos
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (5851) AND `OptionID` IN (0);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(5851, 0, 0, 'Chief Bloodhoof, this may sound like an odd request... but I have a young ward who is quite shy.  You are a hero to him, and he asked me to get your hoofprint.', 9670, 1, 1, 5852, 0, 0, 0, NULL, 0, 34219);

DELETE FROM `gossip_menu` WHERE `MenuID` = 5852 AND `TextID` = 7014;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(5852,7014,34219);

-- ZulAman
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8799,8874,8927,8881) AND `OptionID` IN (0);
INSERT INTO `gossip_menu_option`(`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8799, 0, 0, "Nalorakk is dead, you're free to go.", 23015, 1, 1, 0, 0, 0, 0, NULL, 0, 12340),
(8874, 0, 0, "The coast is clear. You're free!", 22965, 1, 1, 0, 0, 0, 0, NULL, 0, 11723),
(8927, 0, 0, "It's safe, little gnome. You can come out now.", 23154, 1, 1, 0, 0, 0, 0, NULL, 0, 0),
(8881, 0, 0, "We've killed your captors. You're free to go.
", 23090, 1, 1, 0, 0, 0, 0, NULL, 0, 0);

-- MGT
UPDATE `gossip_menu_option` SET `ActionMenuID` = 9200 WHERE `MenuID` = 9199 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 9297 WHERE `MenuID` = 9199 AND `OptionID` = 1;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 9201 WHERE `MenuID` = 9200 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 9295 WHERE `MenuID` = 9297 AND `OptionID` = 0;
UPDATE `gossip_menu_option` SET `ActionMenuID` = 9296 WHERE `MenuID` = 9297 AND `OptionID` = 1;
