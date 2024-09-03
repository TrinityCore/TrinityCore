DELETE FROM `creature` WHERE `guid` IN (450465, 450538, 450454, 450543, 450595, 450606, 450542, 450463, 450525, 450588, 450592, 450541, 450479, 450609, 450586); -- Reusable guids

UPDATE `creature` SET `spawntimesecs` = 30 WHERE `guid` IN (450610, 450597);

DELETE FROM `creature_addon` WHERE `guid`IN (450551, 450587, 450577, 450556);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(450551, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450587, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450577, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL),
(450556, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, NULL);

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450553 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450553, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450547 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450547, 0, 0, 0, '', 1, 0, 100, 0, 6000, 6000, 6000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 6 seconds - Fe-Feng Leaper - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450552 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450552, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450554 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450554, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450546 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450546, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450545 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450545, 0, 0, 0, '', 1, 0, 100, 0, 2000, 2400, 2000, 2400, 0, '', 10, 35, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 2 - 2.4 seconds - Fe-Feng Leaper - OOC - Do emote 35');

-- I think these npcs have wrong emote on retail (should be 35 instead of 53) but here we are
DELETE FROM `smart_scripts` WHERE `entryorguid`=-450544 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450544, 0, 0, 0, '', 1, 0, 100, 0, 5000, 6000, 5000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds - Fe-Feng Hozen - OOC - Do emote 53');

DELETE FROM `smart_scripts` WHERE `entryorguid`=-450537 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `Difficulties`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `action_param7`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450537, 0, 0, 0, '', 1, 0, 100, 0, 5000, 6000, 5000, 6000, 0, '', 10, 53, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Every 5 - 6 seconds - Fe-Feng Hozen - OOC - Do emote 53');

-- Fe-Feng Brewthief 1
SET @ENTRY := 56730;
SET @PATHOFFSET := 4;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to steal brew 1');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1377.052, 3802.752, 86.05312, NULL, 0),
(@PATH, 1, 1384.057, 3779.156, 83.25222, NULL, 0),
(@PATH, 2, 1386.589, 3757.36, 84.33394, NULL, 0),
(@PATH, 3, 1393.135, 3745.388, 84.63531, NULL, 78);

SET @ENTRY := 56730;
SET @PATHOFFSET := 5;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to steal brew 2');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1379.793, 3787.59, 84.01439, NULL, 0),
(@PATH, 1, 1379.019, 3807.806, 86.91505, NULL, 0),
(@PATH, 2, 1380.738, 3829.742, 87.99515, NULL, 0),
(@PATH, 3, 1380.879, 3848.524, 93.4976, NULL, 227);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450610 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (5673000, 5673001, 5673002);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450610, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (56730 * 100), 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Just Created - Self: Start timed action list'),
(-450610, 0, 1, 0, 58, 0, 100, 0, 3, 5673004, 0, 0, 0, '', 80, (56730 * 100) + 1, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Self: Start timed action list'),
(-450610, 0, 2, 0, 58, 0, 100, 0, 3, 5673005, 0, 0, 0, '', 80, (56730 * 100) + 2, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Self: Start timed action list'),

((56730 * 100), 9, 0, 0, 0, 0, 100, 0x20, 500, 500, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1380.98, 3846.78, 93.4798, 0, 'After 0.5 seconds - Self: Jump To Pos'),
((56730 * 100), 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673004, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #5673004, run, do not repeat, Aggresive'),

((56730 * 100) + 1, 9, 0, 0, 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1401.19, 3736.55, 87.4988, 0, 'After 0 seconds - Self: Jump To Pos'),
((56730 * 100) + 1, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 85, 107747, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast to Self spell 107747'),
((56730 * 100) + 1, 9, 2, 0, 0, 0, 100, 0x20, 4000, 4000, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1393.03, 3746.33, 84.6671, 0, 'After 3 seconds - Self: Jump To Pos'),
((56730 * 100) + 1, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673005, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #5673005, run, do not repeat, Aggresive'),

((56730 * 100) + 2, 9, 0, 0, 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1380.9, 3863.48, 100.405, 0, 'After 0 seconds - Self: Jump To Pos'),
((56730 * 100) + 2, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Despawn');

-- Fe-Feng Brewthief 2
SET @ENTRY := 56730;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to steal brew 3');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1376.896, 3812.387, 87.55208, NULL, 0),
(@PATH, 1, 1376.342, 3789.305, 84.46112, NULL, 0),
(@PATH, 2, 1377.7, 3770.052, 84.21375, NULL, 0),
(@PATH, 3, 1383.566, 3752.828, 83.47913, NULL, 0),
(@PATH, 4, 1390.667, 3744.428, 84.28326, NULL, 158);

SET @ENTRY := 56730;
SET @PATHOFFSET := 7;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Brewthief - Waypoint to steal brew 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1378.795, 3767.181, 84.29975, NULL, 0),
(@PATH, 1, 1376.438, 3789.023, 84.41727, NULL, 0),
(@PATH, 2, 1381.368, 3809.92, 87.31419, NULL, 0),
(@PATH, 3, 1390.418, 3833.358, 86.94251, NULL, 0),
(@PATH, 4, 1396.009, 3847.9, 90.90401, NULL, 221);

DELETE FROM `smart_scripts` WHERE `entryorguid`= -450597 AND `source_type`= 0;
DELETE FROM `smart_scripts` WHERE `source_type` = 9 AND `entryOrGuid` IN (5673003, 5673004, 5673005);
INSERT INTO `smart_scripts` (`entryorguid`, `source_type`, `id`, `link`, `event_type`, `event_phase_mask`, `event_chance`, `event_flags`, `event_param1`, `event_param2`, `event_param3`, `event_param4`, `event_param5`, `event_param_string`, `action_type`, `action_param1`, `action_param2`, `action_param3`, `action_param4`, `action_param5`, `action_param6`, `target_type`, `target_param1`, `target_param2`, `target_param3`, `target_param4`, `target_x`, `target_y`, `target_z`, `target_o`, `comment`) VALUES
(-450597, 0, 0, 0, 63, 0, 100, 0, 0, 0, 0, 0, 0, '', 80, (56730 * 100) + 3, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Just Created - Self: Start timed action list'),
(-450597, 0, 1, 0, 58, 0, 100, 0, 4, 5673006, 0, 0, 0, '', 80, (56730 * 100) + 4, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Self: Start timed action list'),
(-450597, 0, 2, 0, 58, 0, 100, 0, 4, 5673007, 0, 0, 0, '', 80, (56730 * 100) + 5, 2, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'Fe-Feng Brewthief - On Waypoint Finished - Self: Start timed action list'),

((56730 * 100) + 3, 9, 0, 0, 0, 0, 100, 0x20, 500, 500, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1390.44, 3846, 91.4894, 0, 'After 0.5 seconds - Self: Jump To Pos'),
((56730 * 100) + 3, 9, 1, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673006, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #5673004, run, do not repeat, Aggresive'),

((56730 * 100) + 4, 9, 0, 0, 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1402.4, 3737.49, 87.1755, 0, 'After 0 seconds - Self: Jump To Pos'),
((56730 * 100) + 4, 9, 1, 0, 0, 0, 100, 0, 3000, 3000, 0, 0, 0, '', 85, 107747, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 3 seconds - Self: Cast to Self spell 107747'),
((56730 * 100) + 4, 9, 2, 0, 0, 0, 100, 0x20, 4000, 4000, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1395.43, 3743.21, 84.791, 0, 'After 3 seconds - Self: Jump To Pos'),
((56730 * 100) + 4, 9, 3, 0, 0, 0, 100, 0, 0, 0, 0, 0, 0, '', 53, 1, 5673007, 0, 0, 0, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'After 0 seconds - Self: Start path #5673005, run, do not repeat, Aggresive'),

((56730 * 100) + 5, 9, 0, 0, 0, 0, 100, 0x20, 0, 0, 0, 0, 0, '', 97, 20, 9, 0, 0, 0, 0, 8, 0, 0, 0, 0, 1399.77, 3859.49, 100.569, 0, 'After 0 seconds - Self: Jump To Pos'),
((56730 * 100) + 5, 9, 1, 0, 0, 0, 100, 0, 1000, 1000, 0, 0, 0, '', 41, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 'After 1 seconds - Self: Despawn');

-- Fe-Feng Hozen
SET @ENTRY := 57205;
SET @PATHOFFSET := 6;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Comment`) VALUES
(@PATH, 1, 0, 'Fe-Feng Hozen - Waypoint 4');

DELETE FROM `waypoint_path_node` WHERE `PathId`= @PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, 1372.106, 3740.393, 76.431, NULL, 61),
(@PATH, 1, 1349.958, 3741.615, 78.44532, NULL, 0),
(@PATH, 2, 1341.099, 3745.504, 77.86064, NULL, 0),
(@PATH, 3, 1336.149, 3749.592, 77.6916, NULL, 0),
(@PATH, 4, 1330.002, 3755.87, 76.78313, NULL, 0),
(@PATH, 5, 1327.401, 3771.976, 76.90037, NULL, 0),
(@PATH, 6, 1330.542, 3783.554, 81.22856, NULL, 0),
(@PATH, 7, 1326.892, 3797.945, 85.61081, NULL, 0),
(@PATH, 8, 1309.026, 3801.955, 79.50826, NULL, 0),
(@PATH, 9, 1291.641, 3811.724, 77.48859, NULL, 0),
(@PATH, 10, 1286.974, 3817.953, 81.05396, NULL, 31),
(@PATH, 11, 1309.026, 3801.955, 79.50826, NULL, 0),
(@PATH, 12, 1326.892, 3797.945, 85.61081, NULL, 0),
(@PATH, 13, 1330.564, 3783.626, 81.11723, NULL, 0),
(@PATH, 14, 1330.002, 3755.87, 76.78313, NULL, 0),
(@PATH, 15, 1336.149, 3749.592, 77.6916, NULL, 0),
(@PATH, 16, 1349.958, 3741.615, 78.44532, NULL, 0),
(@PATH, 17, 1363.657, 3738.729, 76.73334, NULL, 0);

UPDATE `creature` SET `position_x`= 1372.106, `position_y`= 3740.393, `position_z`= 76.431, `orientation`= 0, `wander_distance`= 0, `MovementType`= 2 WHERE `guid`= 450528;
DELETE FROM `creature_addon` WHERE `guid`= 450528;
INSERT INTO `creature_addon` (`guid`, `PathId`, `SheathState`) VALUES
(450528, @PATH, 1);
