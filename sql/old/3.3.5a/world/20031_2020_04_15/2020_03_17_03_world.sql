-- Calliard 16159 random Talk 
DELETE FROM `creature_text` WHERE `CreatureID`=16159;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES 
(16159, 0, 0, 'Am I hearing things?', 12, 0, 100, 0, 0, 0, 13252, 0, 'Calliard random talk'),
(16159, 0, 1, 'Who goes there?', 12, 0, 100, 0, 0, 0, 13251, 0, 'Calliard random talk'),
(16159, 0, 2, 'All quiet.', 12, 0, 100, 0, 0, 0, 13250, 0, 'Calliard random talk');
-- Calliard 16159 random Talk SAI
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE  `entry`=16159;
DELETE FROM `smart_scripts` WHERE (`entryorguid`=16159 AND `source_type`=0);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES 
(16159, 0, 0, 0, 1, 0, 100, 0, 0, 0, 60000, 60000, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, "Calliard random talk ooc");
