-- Vekjik, Avatar of Freya, Adventurous Dwarf, Bushwhacker
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (27801, 28315, 28604, 28317);

-- Add immune to PC/NPC flag for Bushwhacker
UPDATE `creature_template` SET `unit_flags` = `unit_flags` | 768 WHERE `entry` = 28317;

DELETE FROM `event_scripts` WHERE `id` = 18503;
INSERT INTO `event_scripts` (`id`,`delay`,`command`,`datalong`,`datalong2`,`dataint`,`x`,`y`,`z`,`o`) VALUES
(18503,0,10,28317,360000,0,5439.275, 4853.403, -202.332, 1.4199417);

DELETE FROM `creature_text` WHERE `CreatureID` = 28317;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextID`, `TextRange`, `Comment`) VALUES
(28317, 0, 0, '%s sniffs the air, catching the scent of something unusual.', 16, 0, 100, 0, 0, 0, 27731, 0, 'Bushwhacker');

DELETE FROM `gossip_menu_option` WHERE `MenuID` = 9724 AND `OptionID` IN (0, 2); -- 1 is already present in DB
INSERT INTO `gossip_menu_option` (`MenuID`, `OptionID`, `OptionIcon`, `OptionText`, `OptionBroadcastTextID`, `OptionType`, `OptionNpcFlag`, `ActionMenuID`, `ActionPoiID`, `BoxCoded`, `BoxMoney`, `BoxText`, `BoxBroadcastTextID`, `VerifiedBuild`) VALUES
(9724, 0, 0, 'Can you spare an orange?', 28594, 1, 1, 0, 0, 0, 0, '', 0, 0),
(9724, 2, 0, 'I could really use a papaya.', 28596, 1, 1, 0, 0, 0, 0, '', 0, 0);

UPDATE `creature_text` SET `emote`=5 WHERE `CreatureID`=28604 AND `GroupID`=0 AND `ID`=0;
UPDATE `creature_text` SET `emote`=3 WHERE `CreatureID`=28604 AND `GroupID`=1 AND `ID`=0;

DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryorguid` IN (27801, 28315, 28604, 28317);
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryorguid` IN (2860400, 2831700);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28315, 0, 0, 1, 62, 0, 100, 0, 9686, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Close Gossip'),
(28315, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Say Line 0'),
(28315, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 15, 12573, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Quest Credit \'Making Peace\''),
(28315, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51469, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Cast \'Frenzyheart\'s Fury\''),
(27801, 0, 0, 1, 62, 0, 100, 0, 9722, 0, 0, 0, 85, 52045, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Freya - On Gossip Option 0 Selected - Invoker Cast \'Freya Conversation Credit\''),
(27801, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Freya - On Gossip Option 0 Selected - Close Gossip'),
(28604, 0, 0, 3, 62, 0, 100, 0, 9724, 0, 0, 0, 85, 52073, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 0 Selected - Cast \'Dwarf Gives Orange\''),
(28604, 0, 1, 3, 62, 0, 100, 0, 9724, 1, 0, 0, 85, 52074, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 1 Selected - Cast \'Dwarf Gives Banana\''),
(28604, 0, 2, 3, 62, 0, 100, 0, 9724, 2, 0, 0, 85, 52076, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option 2 Selected - Cast \'Dwarf Gives Papaya\''),
(28604, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 80, 2860400, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Gossip Option Selected - Action list'),
(2860400, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Action list - Close Gossip'),
(2860400, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 83, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Action list - Remove Gossip Flag'),
(2860400, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 66, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Action list - Set Orientation'),
(2860400, 9, 3, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Action list - Say Line 1'),
(2860400, 9, 4, 0, 0, 0, 100, 0, 2000, 2000, 0, 0, 114, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 25, 0, 0, 'Adventurous Dwarf - On Action list - Move offset 25 Yards'),
(2860400, 9, 5, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - On Action list - Despawn In 3000 ms'),
(28604, 0, 4, 0, 1, 0, 100, 1, 1000, 1000, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Adventurous Dwarf - OOC No Repeat - Say Line 0'),
(28317, 0, 0, 1, 54, 0, 100, 0, 0, 0, 0, 0, 69, 1, 0, 0, 2, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - On Summon - Move To Summoner'),
(28317, 0, 1, 0, 61, 0, 100, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - On summon - Play Emote 0'),
(28317, 0, 2, 0, 34, 0, 100, 1, 0, 1, 0, 0, 80, 2831700, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - On Movement Inform - Run Timed Actionlist 2831700'),
(2831700, 9, 0, 0, 0, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - Timed Actionlist - Say Line 0'),
(2831700, 9, 1, 0, 0, 0, 100, 0, 1500, 1500, 0, 0, 19, 768, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - Timed Actionlist - Remove Flags Immune to PC/NPC'),
(2831700, 9, 2, 0, 0, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - Timed Actionlist - Start Attacking Summoner'),
(28317, 0, 3, 0, 7, 0, 100, 0, 0, 0, 0, 0, 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Bushwhacker - On evade - Despawn');

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
