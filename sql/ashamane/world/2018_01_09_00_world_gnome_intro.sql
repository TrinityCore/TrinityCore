UPDATE `creature_template` SET `ScriptName` = 'npc_nevin_twistwrench' WHERE `entry` = 45966;
UPDATE `creature_template` SET `ScriptName` = 'npc_carvo_blastbolt' WHERE `entry` = 47250;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 46363;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 46447;
UPDATE `creature_template` SET `InhabitType` = 4, `HoverHeight` = 0 WHERE `entry` = 46165;
UPDATE `creature_template` SET `InhabitType` = 4 WHERE `entry` = 46012;

DELETE FROM `creature_text` WHERE `CreatureID` = 47836;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `comment`, `BroadcastTextId`) VALUES
(47836, 0, 0, 'You can follow me to the Loading Room, $N', 12, 0, 100, 0, 0, 0, '', 48091);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (46363, 46447);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(46363, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 80653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Irradiation Aura'),
(46447, 0, 0, 0, 11, 0, 100, 0, 0, 0, 0, 0, 11, 80653, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Irradiation Aura');
 
DELETE FROM `waypoint_data` WHERE `id` = 4783600;
INSERT INTO `waypoint_data` (`id`, `point`, `position_x`, `position_y`, `position_z`, `orientation`, `delay`, `move_type`, `action`, `action_chance`, `wpguid`) VALUES
(4783600, 1, -4981.25, 780.992, 288.485, 0, 2000, 1, 0, 100, 0),
(4783600, 2, -4989.39, 779.806, 288.485, 0, 0, 1, 0, 100, 0),
(4783600, 3, -5002.69, 769.878, 288.485, 0, 0, 1, 0, 100, 0),
(4783600, 4, -5004.79, 770.036, 287.237, 0, 0, 1, 0, 100, 0),
(4783600, 5, -5031.01, 772.175, 283.101, 0, 0, 1, 0, 100, 0),
(4783600, 6, -5105.9, 775.347, 283.315, 0, 0, 1, 0, 100, 0),
(4783600, 7, -5111.33, 773.41, 287.398, 0, 0, 1, 0, 100, 0),
(4783600, 8, -5133.34, 763.884, 287.373, 0, 0, 1, 0, 100, 0),
(4783600, 9, -5157.74, 765.17, 287.395, 0, 0, 1, 0, 100, 0),
(4783600, 10, -5161.05, 765.459, 285.474, 0, 0, 1, 0, 100, 0),
(4783600, 11, -5174, 767.117, 285.474, 0, 3000, 1, 154599041, 100, 0),
(4783600, 12, -5174, 767.117, 285.474, 0, 0, 1, 154599042, 100, 0);


DELETE FROM `waypoint_scripts` WHERE `guid` IN (154599041, 154599042);
INSERT INTO `waypoint_scripts` (`id`, `delay`, `command`, `datalong`, `datalong2`, `dataint`, `x`, `y`, `z`, `o`, `guid`) VALUES
(154599041, 0, 1, 66, 0, 0, 0, 0, 0, 0, 154599041),
(154599042, 0, 18, 0, 0, 0, 0, 0, 0, 0, 154599042);
