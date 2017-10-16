--
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (25967,23483,23484);

DELETE FROM `gossip_menu` WHERE `MenuID` = 8752 AND `TextID` = 11085;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`, `VerifiedBuild`) VALUES
(8752,11085,0);

DELETE FROM `gossip_menu_option` WHERE `MenuID` IN (8751,8752);
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(8751, 0, 1, 'I have marks to redeem.', 21915, 3, 128, 0, 0, 0, 0, '', 0, 0),
(8752, 0, 1, 'I have marks to redeem.', 21915, 3, 128, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 25967);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(25967, 0, 0, 0, 62, 0, 100, 0, 9205, 0, 0, 0, 11, 37778, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Zephyr - On Gossip Option 0 Selected - Cast \'Quest - Teleport: Caverns of Time\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` IN (8751,8752,9205);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(15, 9205, 0, 0, 0, 5, 0, 989, 192, 0, 0, 0, 0, '', 'Show gossip menu 9205 option id 0 if player is Revered or Exalted with faction Keepers of Time.'),
(14, 8751, 11085, 0, 1, 5, 0, 932, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 text id 11085 if player is Exalted with faction The Aldor.'),
(14, 8751, 11085, 0, 1, 5, 0, 935, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 text id 11085 if player is Exalted with faction The Sha\'tar.'),
(14, 8751, 11085, 0, 1, 5, 0, 942, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 text id 11085 if player is Exalted with faction Cenarion Expedition.'),
(14, 8752, 11085, 0, 1, 5, 0, 934, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 text id 11085 if player is Exalted with faction The Scryers.'),
(14, 8752, 11085, 0, 1, 5, 0, 935, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 text id 11085 if player is Exalted with faction The Sha\'tar.'),
(14, 8752, 11085, 0, 1, 5, 0, 942, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 text id 11085 if player is Exalted with faction Cenarion Expedition.'),
(15, 8751, 0, 0, 1, 5, 0, 932, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 option id 0 if player is Exalted with faction The Aldor.'),
(15, 8751, 0, 0, 1, 5, 0, 935, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 option id 0 if player is Exalted with faction The Sha\'tar.'),
(15, 8751, 0, 0, 1, 5, 0, 942, 128, 0, 0, 0, 0, '', 'Show gossip menu 8751 option id 0 if player is Exalted with faction Cenarion Expedition.'),
(15, 8752, 0, 0, 1, 5, 0, 934, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 option id 0 if player is Exalted with faction The Scryers.'),
(15, 8752, 0, 0, 1, 5, 0, 935, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 option id 0 if player is Exalted with faction The Sha\'tar.'),
(15, 8752, 0, 0, 1, 5, 0, 942, 128, 0, 0, 0, 0, '', 'Show gossip menu 8752 option id 0 if player is Exalted with faction Cenarion Expedition.');
