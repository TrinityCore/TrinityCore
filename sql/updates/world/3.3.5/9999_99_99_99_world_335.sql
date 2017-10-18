-- Vekjik, Avatar of Freya, Adventurous Dwarf
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (27801, 28315, 28604);

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 9724 AND `OptionID` IN (0, 2); -- 1 is already present in DB
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9724, 0, 0, 'Can you spare an orange?', 28594, 1, 1, 0, 0, 0, 0, '', 0, 0),
(9724, 2, 0, 'I could really use a papaya.', 28596, 1, 1, 0, 0, 0, 0, '', 0, 0);

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (27801, 28315, 28604);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28315, 0, 0, 1, 62, 0, 100, 0, 9686, 0, 0, 0, 72, 9686, 13138, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Close Gossip'),
(28315, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Say Line 0'),
(28315, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 15, 12573, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Quest Credit \'Making Peace\''),
(28315, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51469, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Cast \'Frenzyheart\'s Fury\''),
(27801, 0, 0, 0, 62, 0, 100, 0, 9722, 0, 0, 0, 85, 52045, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Freya - On Gossip Option 0 Selected - Invoker Cast \'Freya Conversation Credit\''),
(28604, 0, 0, 3, 62, 0, 100, 0, 9724, 0, 0, 0, 11, 52073, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 0 Selected - Cast \'Dwarf Gives Orange\''),
(28604, 0, 1, 3, 62, 0, 100, 0, 9724, 1, 0, 0, 11, 52074, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 1 Selected - Cast \'Dwarf Gives Banana\''),
(28604, 0, 2, 3, 62, 0, 100, 0, 9724, 2, 0, 0, 11, 52076, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 2 Selected - Cast \'Dwarf Gives Papaya\''),
(28604, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 0 Selected - Say Line 1'),
(28604, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 0 Selected - Despawn Instant'),
(28604, 0, 5, 0, 37, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Initialize - Say Line 0');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (9678, 9720, 9724);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9678, 13136, 0, 0, 9, 0, 12573, 0, 0, 1, 0, 0, '', 'Show gossip menu 9678 text id 13136 if quest Making Peace has not been taken.'),
(14, 9678, 13137, 0, 0, 9, 0, 12573, 0, 0, 0, 0, 0, '', 'Show gossip menu 9678 text id 13137 if quest Making Peace has been taken.'),
(15, 9678, 0, 0, 0, 9, 0, 12573, 0, 0, 0, 0, 0, '', 'Show gossip menu 9678 option id 0 if quest Making Peace has been taken.'),
(15, 9720, 0, 0, 0, 9, 0, 12621, 0, 0, 0, 0, 0, '', 'Show gossip menu 9720 option id 0 if quest Freya\'s Pact has been taken.'),
(15, 9724, 0, 0, 0, 9, 0, 12634, 0, 0, 0, 0, 0, '', 'Show gossip menu 9724 option id 0 if quest Some Make Lemonade, Some Make Liquor has been taken.'),
(15, 9724, 0, 0, 0, 2, 0, 38656, 1, 0, 1, 0, 0, '', 'Show gossip menu 9724 option id 0 if player does not have 1 of Orange.'),
(15, 9724, 1, 0, 0, 9, 0, 12634, 0, 0, 0, 0, 0, '', 'Show gossip menu 9724 option id 1 if quest Some Make Lemonade, Some Make Liquor has been taken.'),
(15, 9724, 1, 0, 0, 2, 0, 38653, 2, 0, 1, 0, 0, '', 'Show gossip menu 9724 option id 1 if player does not have 2 of Banana Bunch.'),
(15, 9724, 2, 0, 0, 9, 0, 12634, 0, 0, 0, 0, 0, '', 'Show gossip menu 9724 option id 2 if quest Some Make Lemonade, Some Make Liquor has been taken.'),
(15, 9724, 2, 0, 0, 2, 0, 38655, 1, 0, 1, 0, 0, '', 'Show gossip menu 9724 option id 2 if player does not have 1 of Papaya.');



