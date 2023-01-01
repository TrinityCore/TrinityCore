SET @CGUID := 850719;

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 155011, 0, 1519, 5390, 0, 0, 0, 0, 1, -8611.9345703125, 398, 104.1984786987304687, 5.367740631103515625, 120, 0, 0, 11791, 0, 0, 0, 0, 0, 45338); -- Daphne Funkybeats (Area: The Canals - Difficulty: 0) (Auras: 263410 - Cosmetic - Hold Mug Kul Tiras Tankard)

DELETE FROM `creature_template_addon` WHERE `entry` IN  (155011 /*155011 (Daphne Funkybeats) - Cosmetic - Hold Mug Kul Tiras Tankard*/);
INSERT INTO `creature_template_addon` (`entry`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(155011, 0, 0, 0, 0, 0, 14677, 0, 0, 0, '263410'); -- 155011 (Daphne Funkybeats) - Cosmetic - Hold Mug Kul Tiras Tankard

DELETE FROM `creature_text` WHERE (`CreatureID` = 1275 AND `GroupID` = 0) OR(`CreatureID` = 1286 AND `GroupID` = 0) OR (`CreatureID` = 1295 AND `GroupID` = 0) OR (`CreatureID` = 1299 AND `GroupID` IN(0, 1)) OR (`CreatureID` = 1319 AND `GroupID` = 0) OR (`CreatureID` = 1324 AND `GroupID` = 0) OR (`CreatureID` = 1333 AND `GroupID` = 0) OR (`CreatureID` = 1341 AND `GroupID` = 0) OR (`CreatureID` = 4981 AND `GroupID` = 0) OR (`CreatureID` = 155011 AND `GroupID` IN(0, 1));
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(1275, 0, 0, 'Welcome!', 12, 7, 100, 3, 0, 0, 32807, 0, 'Kyra Boucher to Player'), -- BroadcastTextID: 32807 - 43329 - 43339 - 53806 - 62063 - 150126 - 190665
(1275, 0, 1, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, 'Kyra Boucher to Player'), -- BroadcastTextID: 32811 - 43336 - 43343
(1286, 0, 0, 'Greetings! Please have a look around.', 12, 7, 100, 3, 0, 0, 32809, 0, 'Edna Mullby to Player'), -- BroadcastTextID: 32809 - 43333 - 43341
(1295, 0, 0, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, 'Lara Moore to Player'), -- BroadcastTextID: 7130 - 7131 - 7132 - 13306 - 29493 - 32808 - 43330 - 43340 - 49696 - 50721
(1299, 0, 0, 'Welcome!', 12, 7, 100, 3, 0, 0, 32807, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 32807 - 43329 - 43339 - 53806 - 62063 - 150126 - 190665
(1299, 0, 1, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 32811 - 43336 - 43343
(1299, 0, 2, 'Greetings, $c.', 12, 7, 100, 3, 0, 85643, 32808, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 7130 - 7131 - 7132 - 13306 - 29493 - 32808 - 43330 - 43340 - 49696 - 50721
(1299, 0, 3, 'Greetings! Please have a look around.', 12, 7, 100, 3, 0, 0, 32809, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 32809 - 43333 - 43341
(1299, 0, 4, 'Welcome.', 12, 7, 100, 3, 0, 0, 32936, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: w32936 - 43338 - 43345 - 62085 - 116569 - 159547 - 189866 - 192447
(1299, 0, 5, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 30620 - 32935 - 33692 - 43337 - 43344 - 67987 - 113432 - 113724 - 113743 - 116805 - 116848 - 116855 - 116862 - 116869 - 116876 - 116883 - 116891 - 118963 - 119094 - 122350 - 125597 - 128601 - 131095 - 132552 - 140147 - 140149 - 142445 - 142489 - 144213 - 145447 - 145856 - 147420 - 176298 - 181403 - 181457 - 182009 - 182946 - 183959 - 189421 - 189817 - 189841 - 189877 - 189904 - 192271 - 192272 - 195237 - 209103 - 216530
(1299, 0, 6, 'Let me know if you need help finding anything, $c.', 12, 7, 100, 3, 0, 0, 32810, 0, 'Lisbeth Schneider to Player'), -- BroadcastTextID: 32810 - 43335 - 43342
(1319, 0, 0, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, 'Bryan Cross to Player'), -- BroadcastTextID: 30620 - 32935 - 33692 - 43337 - 43344 - 67987 - 113432 - 113724 - 113743 - 116805 - 116848 - 116855 - 116862 - 116869 - 116876 - 116883 - 116891 - 118963 - 119094 - 122350 - 125597 - 128601 - 131095 - 132552 - 140147 - 140149 - 142445 - 142489 - 144213 - 145447 - 145856 - 147420 - 176298 - 181403 - 181457 - 182009 - 182946 - 183959 - 189421 - 189817 - 189841 - 189877 - 189904 - 192271 - 192272 - 195237 - 209103 - 216530
(1324, 0, 0, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, 'Heinrich Stone to Player'), -- BroadcastTextID: 32811 - 43336 - 43343
(1333, 0, 0, 'Greetings, $c.', 12, 7, 100, 3, 0, 0, 32808, 0, 'Gerik Koen to Player'), -- BroadcastTextID: 7130 - 7131 - 7132 - 13306 - 29493 - 32808 - 43330 - 43340 - 49696 - 50721
(1341, 0, 0, 'Welcome. May I help you find something?', 12, 7, 100, 3, 0, 0, 32811, 0, 'Wilhelm Strang to Player'), -- BroadcastTextID: 32811 - 43336 - 43343
(4981, 0, 0, 'Greetings.', 12, 7, 100, 3, 0, 0, 32935, 0, 'Ben Trias to Player'), -- BroadcastTextID: 30620 - 32935 - 33692 - 43337 - 43344 - 67987 - 113432 - 113724 - 113743 - 116805 - 116848 - 116855 - 116862 - 116869 - 116876 - 116883 - 116891 - 118963 - 119094 - 122350 - 125597 - 128601 - 131095 - 132552 - 140147 - 140149 - 142445 - 142489 - 144213 - 145447 - 145856 - 147420 - 176298 - 181403 - 181457 - 182009 - 182946 - 183959 - 189421 - 189817 - 189841 - 189877 - 189904 - 192271 - 192272 - 195237 - 209103 - 216530
(155011, 0, 0, 'Come on everyone, let\'s get funky!', 14, 0, 100, 15, 0, 85886, 177277, 0, 'Daphne Funkybeats'),
(155011, 0, 1, 'That was great! Time for a cold refreshment.', 12, 0, 100, 25, 0, 6594, 177278, 0, 'Daphne Funkybeats');

-- Ben Trias smart ai
SET @ENTRY := 4981;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings. (0) to invoker');

-- Thomas Miller smart ai
SET @ENTRY := 3518;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 1, 0, 100, 0, 26000, 26000, 26000, 26000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Every 26 seconds (OOC) - Self: Talk Freshly baked bread for sale! (0) to invoker');

-- Wilhelm Strang smart ai
SET @ENTRY := 1341;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Welcome. May I help you find something? (0) to invoker');

-- Gerik Koen smart ai
SET @ENTRY := 1333;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings, $c. (0) to invoker');

-- Heinrich Stone smart ai
SET @ENTRY := 1324;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Welcome. May I help you find something? (0) to invoker');

-- Kyra Boucher smart ai
SET @ENTRY := 1275;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Welcome! (0) to invoker');

-- Edna Mullby smart ai
SET @ENTRY := 1286;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings! Please have a look around. (0) to invoker');

-- Lara Moore smart ai
SET @ENTRY := 1295;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings, $c. (0) to invoker');

-- Lisbeth Schneider smart ai
SET @ENTRY := 1299;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Welcome! (0) to invoker');

-- Bryan Cross smart ai
SET @ENTRY := 1319;
DELETE FROM `smart_scripts` WHERE `source_type` = 0 AND `entryOrGuid` = @ENTRY;
UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = @ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(@ENTRY, 0, 0, 0, 10, 0, 100, 0, 1, 15, 60000, 300000, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'On only non hostile unit in line of sight (OOC) - Self: Talk Greetings. (0) to invoker');
