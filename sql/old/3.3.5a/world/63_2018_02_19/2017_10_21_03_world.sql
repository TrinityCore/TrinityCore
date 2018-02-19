-- Raliq the Drunk
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 18585;

DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18585);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18585, 0, 0, 0, 0, 0, 100, 0, 5000, 5000, 15000, 15000, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - In Combat - Cast \'Uppercut\''),
(18585, 0, 1, 2, 62, 0, 100, 0, 7729, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - On Gossip Option 0 Selected - Close Gossip'),
(18585, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 2, 45, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - On Gossip Option 0 Selected - Set Faction Ogre'),
(18585, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - On Gossip Option 0 Selected - Say Line 0'),
(18585, 0, 4, 0, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - On Gossip Option 0 Selected - Start Attacking'),
(18585, 0, 5, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Raliq the Drunk - On Reset - Set Default Faction');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` = 7729;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7729, 9440, 0, 0, 9, 0, 10009, 0, 0, 0, 0, 0, '', 'Show gossip menu 7729 text id 9440 if quest Crackin\' Some Skulls has been taken.'),
(15, 7729, 0, 0, 0, 9, 0, 10009, 0, 0, 0, 0, 0, '', 'Show gossip menu 7729 option id 0 if quest Crackin\' Some Skulls has been taken.');

-- Sal\'salabim
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 18584;

-- Table smart_scripts
DELETE FROM `smart_scripts` WHERE (source_type = 0 AND entryorguid = 18584);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(18584, 0, 0, 0, 0, 0, 100, 0, 15000, 15000, 15000, 15000, 11, 31705, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - In Combat - Cast \'Magnetic Pull\''),
(18584, 0, 1, 2, 62, 0, 100, 0, 7725, 0, 0, 0, 72, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Gossip Option 0 Selected - Close Gossip'),
(18584, 0, 2, 3, 61, 0, 100, 0, 0, 0, 0, 0, 2, 90, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Gossip Option 0 Selected - Set Faction Demon'),
(18584, 0, 3, 4, 61, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Gossip Option 0 Selected - Say Line 0'),
(18584, 0, 4, 5, 61, 0, 100, 0, 0, 0, 0, 0, 49, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Gossip Option 0 Selected - Start Attacking'),
(18584, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 42, 0, 19, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Gossip Option 0 Selected - Set Invincibility Hp 19%'),
(18584, 0, 6, 7, 2, 0, 100, 1, 0, 20, 0, 0, 15, 10004, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Health Below 20% - Quest Credit \'Patience and Understanding\''),
(18584, 0, 7, 0, 61, 0, 100, 0, 0, 0, 0, 0, 24, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Health Below 20% - Evade'),
(18584, 0, 8, 0, 25, 0, 100, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Sal\'salabim - On Reset - Set Default Faction');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` IN (14,15) AND `SourceGroup` = 7725;
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId` = 22 AND `SourceGroup` = 6 AND `SourceEntry` = 18584;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(14, 7725, 9435, 0, 0, 9, 0, 10004, 0, 0, 0, 0, 0, '', 'Show gossip menu 7725 text id 9440 if quest Patience and Understanding has been taken.'),
(15, 7725, 0, 0, 0, 9, 0, 10004, 0, 0, 0, 0, 0, '', 'Show gossip menu 7725 option id 0 if quest Patience and Understanding has been taken.');
