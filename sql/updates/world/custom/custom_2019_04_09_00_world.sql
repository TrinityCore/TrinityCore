-- Whack-a-Gnoll!
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (13018, 13065);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(13018, 0, 0, 'How do I play Whack-a-Gnoll?', 53320, 1, 1, 13065, 0),
(13018, 1, 0, 'Ready to whack! |cFF0008E8(Darkmoon Game Token)|r', 53057, 1, 1, 0, 0),
(13018, 2, 0, 'Ready to whack! |cFF0008E8(Darkmoon Game Token)|r', 53057, 1, 1, 13064, 460),
(13065, 0, 0, 'I understand.', 53318, 1, 1, 13018, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry` IN (54601, 54485) AND SourceId = 0;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=13018 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 13018, 1, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "Show gossip if player has 1 of item 71083 in backpack"),
(15, 13018, 2, 0, 0, 2, 0, 71083, 1, 0, 0, 1, "", "Show gossip if player has 0 of item 71083 in backpack");

-- Ring Toss!
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (13012, 13013);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(13012, 0, 0, 'How do I play the Ring Toss?', 53317, 1, 1, 13013, 0),
(13012, 1, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 53028, 1, 1, 0, 0),
(13012, 2, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 53028, 1, 1, 13064, 460),
(13013, 0, 0, 'I understand.', 53318, 1, 1, 13012, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=13012 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 13012, 1, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "Show gossip if player has 1 of item 71083 in backpack"),
(15, 13012, 2, 0, 0, 2, 0, 71083, 1, 0, 0, 1, "", "Show gossip if player has 0 of item 71083 in backpack");

-- The Darkmoon Cannon!
UPDATE `creature_template` SET `gossip_menu_id`= 6575 WHERE `entry`= 15303;
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6575, 6574);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(6575, 0, 0, 'How do I use the cannon?', 10769, 1, 1, 6574, 0),
(6575, 1, 0, 'Launch me! |cFF0008E8(Darkmoon Game Token)|r', 53038, 1, 1, 0, 0),
(6575, 2, 0, 'Launch me! |cFF0008E8(Darkmoon Game Token)|r', 53038, 1, 1, 13064, 460),
(6574, 0, 0, 'I understand.', 53318, 1, 1, 6575, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6575 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 6575, 1, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "Show gossip if player has 1 of item 71083 in backpack"),
(15, 6575, 2, 0, 0, 2, 0, 71083, 1, 0, 0, 1, "", "Show gossip if player has 0 of item 71083 in backpack");

-- Tonk Challenge!
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (13019, 13066);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(13019, 0, 0, 'How do I play the Tonk Challenge?', 53321, 1, 1, 13066, 0),
(13019, 1, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 53028, 1, 1, 0, 0),
(13019, 2, 0, 'Ready to play! |cFF0008E8(Darkmoon Game Token)|r', 53028, 1, 1, 13064, 460),
(13066, 0, 0, 'I understand.', 53318, 1, 1, 13019, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=13019 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 13019, 1, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "Show gossip if player has 1 of item 71083 in backpack"),
(15, 13019, 2, 0, 0, 2, 0, 71083, 1, 0, 0, 1, "", "Show gossip if player has 0 of item 71083 in backpack");

-- Shooting Gallery!
DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (6225, 13068);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`) VALUES
(6225, 0, 0, 'How does the Shooting Gallery work?', 53329, 1, 1, 13068, 0),
(6225, 1, 0, 'Let''s shoot! |cFF0008E8(Darkmoon Game Token)|r', 53042, 1, 1, 0, 0),
(6225, 2, 0, 'Let''s shoot! |cFF0008E8(Darkmoon Game Token)|r', 53042, 1, 1, 13064, 460),
(13068, 0, 0, 'I understand.', 53318, 1, 1, 6225, 0);

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=15 AND `SourceGroup`=6225 AND SourceId = 0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`, `NegativeCondition`, `ScriptName`,`Comment`) VALUES
(15, 6225, 1, 0, 0, 2, 0, 71083, 1, 0, 0, 0, "", "Show gossip if player has 1 of item 71083 in backpack"),
(15, 6225, 2, 0, 0, 2, 0, 71083, 1, 0, 0, 1, "", "Show gossip if player has 0 of item 71083 in backpack");
