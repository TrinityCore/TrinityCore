-- update template
UPDATE `creature_template` SET `ScriptName` = '' WHERE `entry` = 19232;

-- Gossip Menu Options
DELETE FROM `gossip_menu_option` WHERE `MenuID`=7949;
INSERT INTO `gossip_menu_option` (`GossipOptionID`, `MenuID`, `OptionID`, `OptionNpc`, `OptionText`, `OptionBroadcastTextId`, `Language`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `SpellID`, `Flags`, `OverrideIconID`, `GossipNpcOptionID`, `VerifiedBuild`) VALUES
(35008, 7949, 1, 1, 'Let me browse your goods.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, NULL, 50747), -- for Innkeeper Haelthol
(35007, 7949, 0, 5, 'Make this inn your home.', 0, 0, 0, 0, 0, 0, NULL, 0, NULL, 0, NULL, 28861, 50747); -- for Innkeeper Haelthol
