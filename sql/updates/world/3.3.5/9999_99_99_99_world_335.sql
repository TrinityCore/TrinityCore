-- Vekjik, Avatar of Freya
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` IN (27801, 28315);

DELETE FROM `smart_scripts` WHERE source_type = 0 AND entryorguid IN (27801, 28315);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(28315, 0, 0, 1, 62, 0, 100, 0, 9686, 0, 0, 0, 72, 9686, 13138, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Close Gossip'),
(28315, 0, 1, 2, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Say Line 0'),
(28315, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 15, 12573, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Quest Credit \'Making Peace\''),
(28315, 0, 3, 0, 61, 0, 100, 0, 0, 0, 0, 0, 11, 51469, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Shaman Vekjik - On Gossip Option 0 Selected - Cast \'Frenzyheart\'s Fury\''),
(27801, 0, 0, 0, 62, 0, 100, 0, 9722, 0, 0, 0, 85, 52045, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Avatar of Freya - On Gossip Option 0 Selected - Invoker Cast \'Freya Conversation Credit\'');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14, 15) AND `SourceGroup` IN (9678, 9720);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 9678, 13136, 0, 0, 9, 0, 12573, 0, 0, 1, 0, 0, '', 'Show gossip menu 9678 text id 13136 if quest Making Peace has not been taken.'),
(14, 9678, 13137, 0, 0, 9, 0, 12573, 0, 0, 0, 0, 0, '', 'Show gossip menu 9678 text id 13137 if quest Making Peace has been taken.'),
(15, 9678, 0, 0, 0, 9, 0, 12573, 0, 0, 0, 0, 0, '', 'Show gossip menu 9678 option id 0 if quest Making Peace has been taken.'),
(15, 9720, 0, 0, 0, 9, 0, 12621, 0, 0, 0, 0, 0, '', 'Show gossip menu 9720 option id 0 if quest Freya\'s Pact has been taken.');

