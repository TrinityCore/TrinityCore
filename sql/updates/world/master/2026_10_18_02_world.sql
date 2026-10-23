SET @CGUID := 11800200;

-- Prince Liam Greymane: one line every 20.6 s, 61.8 s per round
DELETE FROM `smart_scripts` WHERE `entryorguid`=34850 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34850,0,0,0,60,0,100,0,5000,5000,61800,61800,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 0'),
(34850,0,1,0,60,0,100,0,25600,25600,61800,61800,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 1'),
(34850,0,2,0,60,0,100,0,46200,46200,61800,61800,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - On Update - Say Line 2');

-- Panicked Citizen: the eight cowering ones now and then ask about the rooftops
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376247,-376249,-376252,-376313,-376333,-376341,-376354,-376355) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376247,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376249,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376252,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376313,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376333,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376341,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376354,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0'),
(-376355,0,0,0,1,0,10,0,10000,60000,60000,60000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Say Line 0');

-- Panicked Citizen at the gate: fixed 161 s conversation with the gate guard
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376285,-376310) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid`=4408600 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376285,0,0,0,1,0,100,0,1000,6000,6000,9000,0,10,1,5,18,20,430,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Play Random Emote (1, 5, 18, 20, 430)'),
(-376285,0,1,0,1,0,100,0,0,0,161000,161000,0,80,4408600,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Out of Combat - Run Script'),
(4408600,9,0,0,0,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 0'),
(4408600,9,1,0,0,0,100,0,40000,40000,0,0,0,1,1,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1 (Gilneas City Guard)'),
(4408600,9,2,0,0,0,100,0,16000,16000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1'),
(4408600,9,3,0,0,0,100,0,33000,33000,0,0,0,1,2,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 2 (Gilneas City Guard)'),
(4408600,9,4,0,0,0,100,0,25000,25000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 2'),
(4408600,9,5,0,0,0,100,0,28000,28000,0,0,0,1,1,0,0,0,0,0,10,376310,34864,0,0,0,0,0,0,'Panicked Citizen - Actionlist - Say Line 1 (Gilneas City Guard)');

-- Creature Text
DELETE FROM `creature_text` WHERE `CreatureID` IN (34850, 34851, 34864, 44086);
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `TextRange`, `comment`) VALUES
(34850, 0, 0, 'Stand ready, guards!  We don''t know how many intruders we''re dealing with, but the Headlands are overrun and we''re cut off from the harbor towns.  Expect to be outnumbered.', 12, 0, 100, 1, 0, 19614, 36124, 0, 'Prince Liam Greymane'),
(34850, 1, 0, 'I want the perimeter secured and the gates manned by two guards at all times.  No one gets in, no one gets out.', 12, 0, 100, 1, 0, 19615, 36125, 0, 'Prince Liam Greymane'),
(34850, 2, 0, 'We protected Gilneas from the Scourge.  We protected Gilneas during the Northgate rebellion.  We will protect Gilneas from whatever this new threat may be.', 12, 0, 100, 25, 0, 19616, 36126, 0, 'Prince Liam Greymane'),
(34851, 0, 0, 'What... what are those things on the rooftops?', 12, 0, 100, 0, 0, 0, 39313, 0, 'Panicked Citizen'),
(34864, 0, 0, 'No one''s allowed to leave. Prince Liam''s orders.', 12, 0, 100, 1, 0, 0, 44373, 0, 'Gilneas City Guard'),
(34864, 1, 0, 'It isn''t safe to leave, there''s something lurking out there in the woods.', 12, 0, 100, 1, 0, 0, 44374, 0, 'Gilneas City Guard to Panicked Citizen'),
(34864, 2, 0, 'Stay calm. We have everything under control.', 12, 0, 100, 1, 0, 0, 44375, 0, 'Gilneas City Guard to Panicked Citizen'),
(44086, 0, 0, 'What''s going on? I thought I saw something on the rooftops.', 12, 0, 100, 0, 0, 0, 44379, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 1, 0, 'You can''t do this to us!', 12, 0, 100, 0, 0, 0, 44377, 0, 'Panicked Citizen to Gilneas City Guard'),
(44086, 2, 0, 'My children are in Stormglen alone! I have to get to them!', 12, 0, 100, 0, 0, 0, 44378, 0, 'Panicked Citizen to Gilneas City Guard');

-- Gilneas City Guard, Slain Guard: rooted without the hover animation
UPDATE `creature_template_difficulty` SET `StaticFlags1`=0x10000100 WHERE `Entry` IN (34864, 39095) AND `DifficultyID`=0; -- Sessile, CanSwim

-- Panicked Citizen: the eight runners set off from their spawn point instead of first stepping back to a stray point 1-9 yd behind it, and come back 30 s after reaching their destination
DELETE FROM `waypoint_path_node` WHERE `PathId` BETWEEN 3485100 AND 3485107;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(3485100, 1, -1557.66, 1333.98, 35.6392, NULL, 0),
(3485100, 2, -1557.92, 1335.35, 35.5559, NULL, 0),
(3485100, 3, -1554.15, 1358.49, 35.5559, NULL, 0),
(3485100, 4, -1550.9, 1378.59, 35.5559, NULL, 0),
(3485100, 5, -1541.37, 1388, 35.5559, NULL, 0),
(3485100, 6, -1513.98, 1391.66, 35.5559, NULL, 0),
(3485100, 7, -1487.98, 1390.54, 35.5559, NULL, 0),
(3485100, 8, -1463.45, 1392.06, 35.5559, NULL, 0),
(3485100, 9, -1446.19, 1381.4, 35.5559, NULL, 0),
(3485100, 10, -1441.45, 1364.22, 35.5559, NULL, 0),
(3485100, 11, -1449.31, 1355.35, 35.5559, NULL, 0),
(3485100, 12, -1477.94, 1346.39, 35.5559, NULL, 0),
(3485100, 13, -1486.14, 1337.41, 35.7059, NULL, 0),
(3485100, 14, -1486.14, 1337.41, 35.7059, NULL, 0),
(3485101, 1, -1566.02, 1390.84, 36.0863, NULL, 0),
(3485101, 2, -1569.98, 1389.74, 35.5559, NULL, 0),
(3485101, 3, -1559.13, 1390.55, 35.5559, NULL, 0),
(3485101, 4, -1537.62, 1390.67, 35.5559, NULL, 0),
(3485101, 5, -1520.14, 1391.87, 35.5559, NULL, 0),
(3485101, 6, -1481.07, 1396.95, 35.5559, NULL, 0),
(3485101, 7, -1455.03, 1398.93, 35.5559, NULL, 0),
(3485101, 8, -1433.56, 1376.98, 35.5559, NULL, 0),
(3485101, 9, -1414.52, 1369.89, 35.5559, NULL, 0),
(3485101, 10, -1403.79, 1391.56, 35.5559, NULL, 0),
(3485101, 11, -1396.45, 1403.75, 35.9607, NULL, 0),
(3485101, 12, -1396.45, 1403.75, 35.9607, NULL, 0),
(3485102, 1, -1517.18, 1358.68, 35.6754, NULL, 0),
(3485102, 2, -1517.26, 1350.08, 35.5901, NULL, 0),
(3485102, 3, -1499.89, 1346.24, 35.5559, NULL, 0),
(3485102, 4, -1485.78, 1346.5, 35.5559, NULL, 0),
(3485102, 5, -1465.35, 1349.66, 35.5559, NULL, 0),
(3485102, 6, -1455.58, 1362.03, 35.5559, NULL, 0),
(3485102, 7, -1452.57, 1376.58, 35.9835, NULL, 0),
(3485102, 8, -1435.38, 1399.62, 35.5559, NULL, 0),
(3485102, 9, -1436.97, 1418.23, 35.5559, NULL, 0),
(3485102, 10, -1423.03, 1417.85, 35.5559, NULL, 0),
(3485102, 11, -1421.27, 1413.57, 36.7882, NULL, 0),
(3485102, 12, -1421.27, 1413.57, 36.7882, NULL, 0),
(3485103, 1, -1398.11, 1431.06, 35.6393, NULL, 0),
(3485103, 2, -1401.11, 1430.01, 35.5559, NULL, 0),
(3485103, 3, -1403.94, 1423.49, 35.5559, NULL, 0),
(3485103, 4, -1404.24, 1395.62, 35.5559, NULL, 0),
(3485103, 5, -1406.97, 1376.44, 35.5559, NULL, 0),
(3485103, 6, -1412.89, 1366.29, 35.5559, NULL, 0),
(3485103, 7, -1446.92, 1358.18, 35.5559, NULL, 0),
(3485103, 8, -1479.68, 1349.59, 35.5559, NULL, 0),
(3485103, 9, -1512.6, 1340.97, 35.5559, NULL, 0),
(3485103, 10, -1545.62, 1331.46, 35.5559, NULL, 0),
(3485103, 11, -1578.93, 1316.89, 35.5559, NULL, 0),
(3485103, 12, -1603.45, 1312.64, 18.282, NULL, 0),
(3485103, 13, -1628.11, 1308.6, 20.2663, NULL, 0),
(3485103, 14, -1649.92, 1307.35, 19.7823, NULL, 0),
(3485103, 15, -1682.45, 1305.86, 19.7823, NULL, 0),
(3485103, 16, -1689.48, 1304.64, 19.7823, NULL, 0),
(3485103, 17, -1692.36, 1297.53, 20.2841, NULL, 0),
(3485103, 18, -1692.36, 1297.53, 20.2841, NULL, 0),
(3485104, 1, -1475.92, 1355.62, 35.6393, NULL, 0),
(3485104, 2, -1473.32, 1354.51, 35.5559, NULL, 0),
(3485104, 3, -1464.36, 1353.61, 35.5559, NULL, 0),
(3485104, 4, -1456.92, 1359.33, 35.5559, NULL, 0),
(3485104, 5, -1453.67, 1382.23, 35.8605, NULL, 0),
(3485104, 6, -1472.68, 1390.39, 35.5559, NULL, 0),
(3485104, 7, -1515.83, 1398.98, 35.5559, NULL, 0),
(3485104, 8, -1540.99, 1399.34, 35.5559, NULL, 0),
(3485104, 9, -1553.08, 1387.47, 35.576, NULL, 0),
(3485104, 10, -1560.19, 1364.88, 35.6707, NULL, 0),
(3485104, 11, -1579.16, 1364.87, 35.7491, NULL, 0),
(3485104, 12, -1583.47, 1360.97, 35.9987, NULL, 0),
(3485104, 13, -1583.47, 1360.97, 35.9987, NULL, 0),
(3485105, 1, -1545.53, 1436.92, 35.8738, NULL, 0),
(3485105, 2, -1537.68, 1431.86, 35.5559, NULL, 0),
(3485105, 3, -1508.56, 1420.95, 35.5559, NULL, 0),
(3485105, 4, -1502.36, 1410.74, 35.5559, NULL, 0),
(3485105, 5, -1499.89, 1397.3, 35.5559, NULL, 0),
(3485105, 6, -1500.02, 1375.36, 35.5559, NULL, 0),
(3485105, 7, -1496.69, 1351.53, 35.5559, NULL, 0),
(3485105, 8, -1474.15, 1349.49, 35.5559, NULL, 0),
(3485105, 9, -1455.94, 1353.31, 35.5559, NULL, 0),
(3485105, 10, -1442.34, 1370.33, 35.5559, NULL, 0),
(3485105, 11, -1443.8, 1397.67, 35.5559, NULL, 0),
(3485105, 12, -1446.98, 1419.57, 35.5559, NULL, 0),
(3485105, 13, -1463.31, 1441.83, 35.9913, NULL, 0),
(3485105, 14, -1463.31, 1441.83, 35.9913, NULL, 0),
(3485106, 1, -1476.81, 1439.62, 35.6393, NULL, 0),
(3485106, 2, -1484.13, 1434.9, 35.5559, NULL, 0),
(3485106, 3, -1494.22, 1427.02, 35.5559, NULL, 0),
(3485106, 4, -1513.02, 1419.3, 35.5559, NULL, 0),
(3485106, 5, -1533.98, 1421.55, 35.5559, NULL, 0),
(3485106, 6, -1546.87, 1412.98, 35.5559, NULL, 0),
(3485106, 7, -1555.8, 1380.94, 35.5559, NULL, 0),
(3485106, 8, -1559.86, 1361.95, 35.5559, NULL, 0),
(3485106, 9, -1564.81, 1348.47, 35.5559, NULL, 0),
(3485106, 10, -1565.94, 1326.43, 35.5559, NULL, 0),
(3485106, 11, -1575.71, 1319.45, 35.6596, NULL, 0),
(3485106, 12, -1603.97, 1314.38, 18.2702, NULL, 0),
(3485106, 13, -1627.99, 1309.86, 20.2902, NULL, 0),
(3485106, 14, -1656.35, 1307.08, 19.7823, NULL, 0),
(3485106, 15, -1675.74, 1314.08, 20.2918, NULL, 0),
(3485106, 16, -1675.74, 1314.08, 20.2918, NULL, 0),
(3485107, 1, -1432.88, 1431.65, 35.6393, NULL, 0),
(3485107, 2, -1438.83, 1430.13, 35.5559, NULL, 0),
(3485107, 3, -1460.7, 1424.34, 35.5559, NULL, 0),
(3485107, 4, -1484.46, 1424.62, 35.5559, NULL, 0),
(3485107, 5, -1495.32, 1424.44, 35.5559, NULL, 0),
(3485107, 6, -1519.17, 1424.15, 35.5559, NULL, 0),
(3485107, 7, -1537.38, 1418.97, 35.5559, NULL, 0),
(3485107, 8, -1546.26, 1405.81, 35.5559, NULL, 0),
(3485107, 9, -1542.06, 1392.99, 35.5559, NULL, 0),
(3485107, 10, -1516.75, 1390.39, 35.5559, NULL, 0),
(3485107, 11, -1505.28, 1381.6, 35.5559, NULL, 0),
(3485107, 12, -1500.97, 1364.63, 35.5559, NULL, 0),
(3485107, 13, -1505.45, 1345.69, 35.5559, NULL, 0),
(3485107, 14, -1516.72, 1340.1, 35.5559, NULL, 0),
(3485107, 15, -1528.84, 1334.56, 35.5559, NULL, 0),
(3485107, 16, -1530.02, 1325.19, 35.8444, NULL, 0),
(3485107, 17, -1530.02, 1325.19, 35.8444, NULL, 0);

UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=14, `comment`='Panicked Citizen - On Waypoint 14 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376371 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=14, `comment`='Panicked Citizen - On Waypoint 14 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376369 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=12, `comment`='Panicked Citizen - On Waypoint 12 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376367 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=13, `comment`='Panicked Citizen - On Waypoint 13 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376353 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=17, `comment`='Panicked Citizen - On Waypoint 17 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376349 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=18, `comment`='Panicked Citizen - On Waypoint 18 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376345 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=16, `comment`='Panicked Citizen - On Waypoint 16 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376344 AND `source_type`=0 AND `id`=1;
UPDATE `smart_scripts` SET `action_param2`=30, `event_param1`=12, `comment`='Panicked Citizen - On Waypoint 12 Ended - Despawn (respawn in 30 seconds)' WHERE `entryorguid`=-376318 AND `source_type`=0 AND `id`=1;

-- Shadowy Figure: the pacer starts kneeling on the north end of its ridge, the high jumper on its jump-off point
UPDATE `creature` SET `position_x`=-1421.68, `position_y`=1391.15, `position_z`=71.27, `orientation`=1.59584 WHERE `guid`=376284;
UPDATE `creature` SET `position_x`=-1420.115, `position_y`=1433.424, `position_z`=71.269 WHERE `guid`=376319;

DELETE FROM `creature_addon` WHERE `guid`=376284;
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `MountCreatureID`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvPFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(376284, 0, 0, 0, 8, 0, 0, 1, 0, 0, 0, 0, 0, 0, '39662'); -- Shadowy Figure - UNIT_STAND_STATE_KNEEL

-- Shadowy Figure: the roof figures as on retail (roar every 2.4 s; pacer every 7.3 s; shuffler every 6.1 s; jump pairs every 7.3 / 8.5 / 7.3 s at 16 yd/s)
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376284,-376306,-376319,-376323,-376334,-376337) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3486700 AND 3486704 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376323,0,0,0,1,0,100,0,2400,2400,2400,2400,0,5,15,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Play Emote 15'),
(-376284,0,0,0,1,0,100,0,1000,7300,14600,14600,0,80,3486700,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Run Script'),
(-376337,0,0,0,1,0,100,0,1000,6100,6100,6100,0,80,3486701,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Run Script'),
(-376319,0,0,0,1,0,100,0,1000,7300,14600,14600,0,80,3486702,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Run Script'),
(-376334,0,0,0,1,0,100,0,1000,8500,17000,17000,0,80,3486703,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Run Script'),
(-376306,0,0,0,1,0,100,0,1000,7300,14600,14600,0,80,3486704,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Out of Combat - Run Script'),
(3486700,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Remove Stand State Kneel'),
(3486700,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Set Walk'),
(3486700,9,2,0,0,0,100,0,0,0,0,0,0,69,0,0,1,0,0,0,8,0,0,0,0,-1421.56,1386.36,71.8755,0,'Shadowy Figure - Actionlist - Move To Position'),
(3486700,9,3,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Set Stand State Kneel'),
(3486700,9,4,0,0,0,100,0,5300,5300,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Remove Stand State Kneel'),
(3486700,9,5,0,0,0,100,0,0,0,0,0,0,69,0,0,1,0,0,0,8,0,0,0,0,-1421.68,1391.15,71.27,0,'Shadowy Figure - Actionlist - Move To Position'),
(3486700,9,6,0,0,0,100,0,2000,2000,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Set Stand State Kneel'),
(3486701,9,0,0,0,0,100,0,0,0,0,0,0,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Remove Stand State Kneel'),
(3486701,9,1,0,0,0,100,0,0,0,0,0,0,59,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Set Walk'),
(3486701,9,2,0,0,0,100,0,0,0,0,0,0,69,0,0,1,0,0,0,8,0,0,0,0,-1445.241,1337.629,71.136,0,'Shadowy Figure - Actionlist - Move To Position'),
(3486701,9,3,0,0,0,100,0,1400,1400,0,0,0,69,0,0,1,0,0,0,8,0,0,0,0,-1446.231,1340.991,71.157,0,'Shadowy Figure - Actionlist - Move To Position'),
(3486701,9,4,0,0,0,100,0,1400,1400,0,0,0,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - Actionlist - Set Stand State Kneel'),
(3486702,9,0,0,0,0,100,0,0,0,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1421.311,1409.007,63.297,0,'Shadowy Figure - Actionlist - Jump To Position'),
(3486702,9,1,0,0,0,100,0,7300,7300,0,0,0,97,16,6,6,0,0,0,8,0,0,0,0,-1420.115,1433.424,71.269,0,'Shadowy Figure - Actionlist - Jump To Position'),
(3486703,9,0,0,0,0,100,0,0,0,0,0,0,97,16,9,9,0,0,0,8,0,0,0,0,-1506.57,1451.028,71.198,0,'Shadowy Figure - Actionlist - Jump To Position'),
(3486703,9,1,0,0,0,100,0,8500,8500,0,0,0,97,16,6,6,0,0,0,8,0,0,0,0,-1464.9,1450.8,71.7703,0,'Shadowy Figure - Actionlist - Jump To Position'),
(3486704,9,0,0,0,0,100,0,0,0,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1488.443,1327.366,71.063,0,'Shadowy Figure - Actionlist - Jump To Position'),
(3486704,9,1,0,0,0,100,0,7300,7300,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1513.76,1319.59,72.6899,0,'Shadowy Figure - Actionlist - Jump To Position');

-- Panicked Citizen: the ninth runner, from the south-east gate to the north-east corner, 187 s spawn to spawn
DELETE FROM `creature` WHERE `guid`=@CGUID+0;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `phaseUseFlags`, `PhaseId`, `PhaseGroup`, `terrainSwapMap`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `curHealthPct`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+0, 34851, 654, 4755, 4756, '0', 0, 169, 0, -1, 0, 0, -1393.288, 1339.969, 35.583, 0.0862, 120, 0, 0, NULL, 0, NULL, NULL, NULL, NULL, '', NULL, 69875); -- Panicked Citizen

DELETE FROM `waypoint_path` WHERE `PathId`=3485108;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(3485108, 1, 0, NULL, 'Panicked Citizen - On Respawn');

DELETE FROM `waypoint_path_node` WHERE `PathId`=3485108;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(3485108, 1, -1389.493, 1340.2969, 35.739315, NULL, 0),
(3485108, 2, -1378.7031, 1343.5365, 35.739315, NULL, 0),
(3485108, 3, -1370.5122, 1349.1875, 36.15272, NULL, 0),
(3485108, 4, -1369.3663, 1387.1163, 36.15333, NULL, 0),
(3485108, 5, -1368.8368, 1434.4548, 36.15403, NULL, 0),
(3485108, 6, -1377.1372, 1463.5312, 36.15446, NULL, 0),
(3485108, 7, -1385.4774, 1463.4584, 36.154453, NULL, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=-(@CGUID+0) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-(@CGUID+0),0,0,0,11,0,100,0,0,0,0,0,0,53,0,3485108,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - On Respawn - Start Waypoint Path 3485108'),
(-(@CGUID+0),0,1,0,11,0,100,0,0,0,0,0,0,12,34867,3,30000,0,0,0,8,0,0,0,0,-1397.469,1340.787,35.706,3.606,'Panicked Citizen - On Respawn - Summon Creature Shadowy Figure'),
(-(@CGUID+0),0,2,0,58,0,100,0,7,3485108,0,0,0,41,1,168,0,0,0,0,1,0,0,0,0,0,0,0,0,'Panicked Citizen - On Waypoint 7 Ended - Despawn (respawn in 168 seconds)');

-- Shadowy Figure: the one summoned by the gate runner chases it to the north-east corner and vanishes
DELETE FROM `waypoint_path` WHERE `PathId`=3486700;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(3486700, 1, 0, NULL, 'Shadowy Figure - Just Summoned');

DELETE FROM `waypoint_path_node` WHERE `PathId`=3486700;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(3486700, 1, -1404.6007, 1337.2153, 35.73932, NULL, 0),
(3486700, 2, -1382.9098, 1342.0052, 35.73932, NULL, 0),
(3486700, 3, -1371.1198, 1351.3264, 36.152756, NULL, 0),
(3486700, 4, -1368.8629, 1377.066, 36.15317, NULL, 0),
(3486700, 5, -1368.0781, 1411.8125, 36.15368, NULL, 0),
(3486700, 6, -1367.7848, 1445.033, 36.15417, NULL, 0),
(3486700, 7, -1378.724, 1461.1528, 36.154457, NULL, 0);

DELETE FROM `smart_scripts` WHERE `entryorguid`=34867 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34867,0,0,0,54,0,100,0,0,0,0,0,0,53,0,3486700,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - On Just Summoned - Start Waypoint Path 3486700'),
(34867,0,1,0,58,0,100,0,7,3486700,0,0,0,41,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Shadowy Figure - On Waypoint 7 Ended - Despawn');

-- Rat: the four Merchant Square rats of the default phase run their own routes (the 170 rats keep theirs)
SET @ENTRY := 4075;

-- Rat (-1585, 1365): out to the square's west corner and back past the fountain, was running the phase 170 route 407500
SET @PATHOFFSET := 9;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1566.352, 1366.950, 35.890, NULL, 0),
(@PATH, 1, -1555.754, 1370.865, 35.770, NULL, 0),
(@PATH, 2, -1542.465, 1384.807, 35.995, NULL, 0),
(@PATH, 3, -1542.089, 1408.861, 35.556, NULL, 0),
(@PATH, 4, -1533.207, 1420.983, 35.556, NULL, 0),
(@PATH, 5, -1528.009, 1414.783, 35.553, NULL, 0),
(@PATH, 6, -1539.750, 1416.844, 35.556, NULL, 0),
(@PATH, 7, -1542.465, 1384.807, 35.995, NULL, 0),
(@PATH, 8, -1555.754, 1370.865, 35.770, NULL, 0),
(@PATH, 9, -1566.352, 1366.950, 35.890, NULL, 0),
(@PATH, 10, -1585.214, 1365.340, 35.710, NULL, 0);

UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=376325;

-- Rat (-1573, 1401): along the north side to the gate and back, with the spur at the west steps, was running the phase 170 route 407501
SET @PATHOFFSET := 10;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1565.655, 1400.969, 36.158, NULL, 0),
(@PATH, 1, -1559.969, 1422.285, 35.719, NULL, 0),
(@PATH, 2, -1555.533, 1433.922, 35.810, NULL, 0),
(@PATH, 3, -1547.986, 1438.767, 35.902, NULL, 0),
(@PATH, 4, -1529.497, 1441.524, 35.980, NULL, 0),
(@PATH, 5, -1524.859, 1436.375, 35.767, NULL, 0),
(@PATH, 6, -1507.276, 1435.762, 35.749, NULL, 0),
(@PATH, 7, -1492.830, 1437.661, 35.844, NULL, 0),
(@PATH, 8, -1480.974, 1437.476, 35.852, NULL, 0),
(@PATH, 9, -1468.632, 1440.254, 35.968, NULL, 0),
(@PATH, 10, -1454.483, 1437.776, 35.877, NULL, 0),
(@PATH, 11, -1430.311, 1439.118, 35.935, NULL, 0),
(@PATH, 12, -1454.483, 1437.776, 35.877, NULL, 0),
(@PATH, 13, -1468.632, 1440.254, 35.968, NULL, 0),
(@PATH, 14, -1480.974, 1437.476, 35.852, NULL, 0),
(@PATH, 15, -1492.830, 1437.661, 35.844, NULL, 0),
(@PATH, 16, -1507.276, 1435.762, 35.749, NULL, 0),
(@PATH, 17, -1518.118, 1436.016, 35.748, NULL, 0),
(@PATH, 18, -1529.497, 1441.524, 35.980, NULL, 0),
(@PATH, 19, -1547.986, 1438.767, 35.902, NULL, 0),
(@PATH, 20, -1555.533, 1433.922, 35.810, NULL, 0),
(@PATH, 21, -1559.858, 1411.417, 35.922, NULL, 0),
(@PATH, 22, -1565.655, 1400.969, 36.158, NULL, 0),
(@PATH, 23, -1573.142, 1401.139, 36.619, NULL, 0);

UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=376346;

-- Rat: the loop round the east half of the square, was standing still at (-1563, 1319) next to the route of 407503
SET @PATHOFFSET := 11;
SET @PATH := @ENTRY * 100 + @PATHOFFSET;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`, `MoveType`, `Flags`, `Velocity`, `Comment`) VALUES
(@PATH, 1, 0x0, NULL, 'Rat - Cosmetic Path');

DELETE FROM `waypoint_path_node` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path_node` (`PathId`, `NodeId`, `PositionX`, `PositionY`, `PositionZ`, `Orientation`, `Delay`) VALUES
(@PATH, 0, -1495.269, 1408.132, 35.556, NULL, 0),
(@PATH, 1, -1502.300, 1380.554, 35.556, NULL, 0),
(@PATH, 2, -1500.208, 1350.625, 35.556, NULL, 0),
(@PATH, 3, -1461.733, 1354.517, 35.556, NULL, 0),
(@PATH, 4, -1433.222, 1362.076, 35.556, NULL, 0),
(@PATH, 5, -1401.542, 1368.288, 35.556, NULL, 0),
(@PATH, 6, -1402.983, 1385.648, 35.556, NULL, 0),
(@PATH, 7, -1402.665, 1413.415, 35.556, NULL, 0),
(@PATH, 8, -1416.502, 1420.439, 35.556, NULL, 0),
(@PATH, 9, -1435.352, 1423.688, 35.556, NULL, 0),
(@PATH, 10, -1448.543, 1425.035, 35.556, NULL, 0),
(@PATH, 11, -1465.648, 1425.059, 35.556, NULL, 0),
(@PATH, 12, -1489.217, 1426.361, 35.556, NULL, 0);

UPDATE `creature` SET `position_x`=-1489.217, `position_y`=1426.361, `position_z`=35.556, `orientation`=4.39184, `wander_distance`=0, `MovementType`=2 WHERE `guid`=376364;
UPDATE `creature_addon` SET `PathId`=@PATH WHERE `guid`=376364;

-- Gilneas City: phase 170 covers the whole city from the Lockdown! turn-in, not only Merchant Square
UPDATE `spell_area` SET `quest_start`=14078, `quest_start_status`=64 WHERE `spell`=59073 AND `area` IN (4714,4755,4757) AND `quest_start`=14099;

-- Gilneas City Guard: the 30th retail post; Rampaging Worgen: the retail leap spawn points TDB lacks (Jump13-Jump20)
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+10 AND @CGUID+18;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnDifficulties`, `PhaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `wander_distance`, `currentwaypoint`, `MovementType`, `npcflag`, `unit_flags`, `unit_flags2`, `unit_flags3`, `ScriptName`, `StringId`, `VerifiedBuild`) VALUES
(@CGUID+10,34916,654,4755,4756,'0',170,0,0,1,-1556.21,1354.52,35.56,5.206,120,0,0,0,NULL,NULL,NULL,NULL,'',NULL,63305), -- Gilneas City Guard
(@CGUID+11,34884,654,4755,4756,'0',170,0,0,0,-1522.747,1458.594,63.983,4.868,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump13',63305), -- Rampaging Worgen
(@CGUID+12,34884,654,4755,4756,'0',170,0,0,0,-1572.33,1441.46,71.896,4.858,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump14',63305), -- Rampaging Worgen
(@CGUID+13,34884,654,4755,4756,'0',170,0,0,0,-1539.394,1370.75,63.336,3.168,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump15',63305), -- Rampaging Worgen
(@CGUID+14,34884,654,4755,4756,'0',170,0,0,0,-1558.84,1306.861,73.162,0.345,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump16',63305), -- Rampaging Worgen
(@CGUID+15,34884,654,4755,4756,'0',170,0,0,0,-1477.299,1322.504,65.578,2.029,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump17',63305), -- Rampaging Worgen
(@CGUID+16,34884,654,4755,4756,'0',170,0,0,0,-1583.057,1333.057,63.347,1.494,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump18',63305), -- Rampaging Worgen
(@CGUID+17,34884,654,4755,4756,'0',170,0,0,0,-1386.695,1436.627,71.88,4.654,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump19',63305), -- Rampaging Worgen
(@CGUID+18,34884,654,4755,4756,'0',170,0,0,0,-1371.455,1346.75,36.236,1.594,120,0,0,0,NULL,NULL,NULL,NULL,'','Jump20',63305); -- Rampaging Worgen

DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID+10, 3000060, 3000062);
INSERT INTO `creature_addon` (`guid`, `PathId`, `mount`, `StandState`, `AnimTier`, `VisFlags`, `SheathState`, `PvpFlags`, `emote`, `aiAnimKit`, `movementAnimKit`, `meleeAnimKit`, `visibilityDistanceType`, `auras`) VALUES
(@CGUID+10, 0, 0, 0, 0, 0, 1, 0, 333, 0, 0, 0, 0, ''), -- Gilneas City Guard - EMOTE_STATE_READY1H
(3000060, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''), -- Rampaging Worgen - EMOTE_STATE_WORK
(3000062, 0, 0, 0, 0, 0, 1, 0, 173, 0, 0, 0, 3, ''); -- Rampaging Worgen - EMOTE_STATE_WORK

-- Rampaging Worgen: the fourth stall attacker onto its retail spot
UPDATE `creature` SET `position_x`=-1497.306, `position_y`=1439.811, `position_z`=36.055, `orientation`=0.82 WHERE `guid`=3000063;

-- Rampaging Worgen: StringId for the ground spawn behind the east houses
UPDATE `creature` SET `StringId`='Jump21' WHERE `guid`=3000058;

-- Rampaging Worgen: the leap runs once per spawn (On Respawn fires on grid load and on respawn), no longer on every reset / evade
DELETE FROM `smart_scripts` WHERE `entryorguid`=34884 AND `source_type`=0 AND `id` BETWEEN 2 AND 22;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34884,0,2,0,11,0,100,0,0,0,0,0,0,80,3488400,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump1)'),
(34884,0,3,0,11,0,100,0,0,0,0,0,0,80,3488401,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump2)'),
(34884,0,4,0,11,0,100,0,0,0,0,0,0,80,3488402,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump3)'),
(34884,0,5,0,11,0,100,0,0,0,0,0,0,80,3488403,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump4)'),
(34884,0,6,0,11,0,100,0,0,0,0,0,0,80,3488404,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump5)'),
(34884,0,7,0,11,0,100,0,0,0,0,0,0,80,3488405,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump6)'),
(34884,0,8,0,11,0,100,0,0,0,0,0,0,80,3488406,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump7)'),
(34884,0,9,0,11,0,100,0,0,0,0,0,0,80,3488407,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump8)'),
(34884,0,10,0,11,0,100,0,0,0,0,0,0,80,3488408,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump9)'),
(34884,0,11,0,11,0,100,0,0,0,0,0,0,80,3488409,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump10)'),
(34884,0,12,0,11,0,100,0,0,0,0,0,0,80,3488410,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump11)'),
(34884,0,13,0,11,0,100,0,0,0,0,0,0,80,3488411,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump12)'),
(34884,0,14,0,11,0,100,0,0,0,0,0,0,80,3488412,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump13)'),
(34884,0,15,0,11,0,100,0,0,0,0,0,0,80,3488413,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump14)'),
(34884,0,16,0,11,0,100,0,0,0,0,0,0,80,3488414,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump15)'),
(34884,0,17,0,11,0,100,0,0,0,0,0,0,80,3488415,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump16)'),
(34884,0,18,0,11,0,100,0,0,0,0,0,0,80,3488416,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump17)'),
(34884,0,19,0,11,0,100,0,0,0,0,0,0,80,3488417,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump18)'),
(34884,0,20,0,11,0,100,0,0,0,0,0,0,80,3488418,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump19)'),
(34884,0,21,0,11,0,100,0,0,0,0,0,0,80,3488419,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump20)'),
(34884,0,22,0,11,0,100,0,0,0,0,0,0,80,3488420,2,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - On Respawn - Run Script (Jump21)');

DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3488400 AND 3488420 AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(3488400,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488400,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1518.545,1381.559,40.911,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488400,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1527.77,1397.33,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488400,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488400,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488400,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488401,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488401,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1461.004,1370.682,64.398,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488401,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1459.82,1386.06,36.004,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488401,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488401,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488401,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488402,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488402,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1421.379,1378.561,73.314,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488402,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1437.56,1364.63,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488402,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488402,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488402,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488403,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488403,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1476.776,1440.854,60.718,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488403,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1491.3,1412.48,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488403,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488403,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488403,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488404,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488404,9,1,0,0,0,100,32,1000,1000,0,0,0,97,8,11,11,0,0,0,8,0,0,0,0,-1476.055,1342.712,64.172,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488404,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1501.05,1347.99,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488404,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488404,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488404,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488405,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488405,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1573.484,1333.042,58.794,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488405,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1535.17,1332.43,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488405,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488405,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488405,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488406,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488406,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1573.226,1333.057,58.871,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488406,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1539.02,1335.85,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488406,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488406,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488406,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488407,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488407,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1425.561,1358.085,65.881,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488407,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1447.21,1394.15,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488407,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488407,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488407,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488408,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488408,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1523.646,1411.805,39.712,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488408,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1517.4,1425.16,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488408,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488408,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488408,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488409,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488409,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1528.896,1381.031,58.566,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488409,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1508.87,1395.77,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488409,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488409,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488409,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488410,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488410,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,2,2,0,0,0,8,0,0,0,0,-1421.38,1413.828,64.132,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488410,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1437.75,1394.52,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488410,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488410,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488410,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488411,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488411,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1387.14,1426.55,71.656,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488411,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1417.49,1417.12,42.589,0,'Rampaging Worgen - Actionlist - Jump To Pos (ledge)'),
(3488411,9,3,0,0,0,100,32,3000,3000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1446.68,1420.5,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488411,9,4,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488411,9,5,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488411,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488412,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488412,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1521.51,1450.69,71.236,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488412,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1521.33,1408.15,40.118,0,'Rampaging Worgen - Actionlist - Jump To Pos (ledge)'),
(3488412,9,3,0,0,0,100,32,3000,3000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1522.18,1395.39,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488412,9,4,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488412,9,5,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488412,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488413,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488413,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1560.042,1433.979,69.055,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488413,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1538.95,1427.15,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488413,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488413,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488413,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488414,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488414,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1561.24,1380.073,55.512,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488414,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1553.06,1397.02,35.565,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488414,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488414,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488414,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488415,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488415,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,2,2,0,0,0,8,0,0,0,0,-1535.139,1328.153,66.558,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488415,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1532.06,1346.52,35.668,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488415,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488415,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488415,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488416,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488416,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1477.748,1329.99,70.823,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488416,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1485.25,1358.22,61.231,0,'Rampaging Worgen - Actionlist - Jump To Pos (ledge)'),
(3488416,9,3,0,0,0,100,32,3000,3000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1511.61,1340.52,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488416,9,4,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488416,9,5,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488416,9,6,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488417,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488417,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,3,3,0,0,0,8,0,0,0,0,-1571.002,1351.12,61.18,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488417,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1564.1,1361.27,35.567,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488417,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488417,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488417,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488418,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488418,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,12,12,0,0,0,8,0,0,0,0,-1421.267,1380.352,72.883,0,'Rampaging Worgen - Actionlist - Jump To Pos (roof edge)'),
(3488418,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1444.52,1388.68,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488418,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488418,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488418,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488419,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488419,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,4,4,0,0,0,8,0,0,0,0,-1388.774,1370.519,35.808,0,'Rampaging Worgen - Actionlist - Jump To Pos (arch)'),
(3488419,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1442.83,1381.44,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488419,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488419,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488419,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard'),
(3488420,9,0,0,0,0,100,0,0,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Passive'),
(3488420,9,1,0,0,0,100,32,1000,1000,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1398.736,1363.804,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (arch)'),
(3488420,9,2,0,0,0,100,32,2500,2500,0,0,0,97,16,5,5,0,0,0,8,0,0,0,0,-1435.17,1356.01,35.556,0,'Rampaging Worgen - Actionlist - Jump To Pos (landing)'),
(3488420,9,3,0,0,0,100,0,1000,1000,0,0,0,8,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Reactstate Aggressive'),
(3488420,9,4,0,0,0,100,0,0,0,0,0,0,101,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Set Home Position'),
(3488420,9,5,0,0,0,100,0,0,0,0,0,0,49,0,0,0,0,0,0,11,34916,40,0,0,0,0,0,0,'Rampaging Worgen - Actionlist - Start Attack Closest Gilneas City Guard');

DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=22 AND `SourceEntry`=34884 AND `SourceId`=0 AND `SourceGroup` BETWEEN 3 AND 23;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ConditionStringValue1`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(22,3,34884,0,0,58,1,0,0,0,'Jump1',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump1'),
(22,4,34884,0,0,58,1,0,0,0,'Jump2',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump2'),
(22,5,34884,0,0,58,1,0,0,0,'Jump3',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump3'),
(22,6,34884,0,0,58,1,0,0,0,'Jump4',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump4'),
(22,7,34884,0,0,58,1,0,0,0,'Jump5',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump5'),
(22,8,34884,0,0,58,1,0,0,0,'Jump6',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump6'),
(22,9,34884,0,0,58,1,0,0,0,'Jump7',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump7'),
(22,10,34884,0,0,58,1,0,0,0,'Jump8',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump8'),
(22,11,34884,0,0,58,1,0,0,0,'Jump9',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump9'),
(22,12,34884,0,0,58,1,0,0,0,'Jump10',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump10'),
(22,13,34884,0,0,58,1,0,0,0,'Jump11',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump11'),
(22,14,34884,0,0,58,1,0,0,0,'Jump12',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump12'),
(22,15,34884,0,0,58,1,0,0,0,'Jump13',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump13'),
(22,16,34884,0,0,58,1,0,0,0,'Jump14',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump14'),
(22,17,34884,0,0,58,1,0,0,0,'Jump15',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump15'),
(22,18,34884,0,0,58,1,0,0,0,'Jump16',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump16'),
(22,19,34884,0,0,58,1,0,0,0,'Jump17',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump17'),
(22,20,34884,0,0,58,1,0,0,0,'Jump18',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump18'),
(22,21,34884,0,0,58,1,0,0,0,'Jump19',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump19'),
(22,22,34884,0,0,58,1,0,0,0,'Jump20',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump20'),
(22,23,34884,0,0,58,1,0,0,0,'Jump21',0,0,0,'','Rampaging Worgen - Run Script only for the spawn with StringId Jump21');

-- Prince Liam Greymane: a yell from his group every 20-24 s while fighting, the first 5-20 s in, silent out of combat
DELETE FROM `smart_scripts` WHERE `entryorguid`=34913 AND `source_type`=0 AND `id`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(34913,0,0,0,0,0,100,0,5000,20000,20000,24000,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Prince Liam Greymane - In Combat - Say Line 0');

-- Gilnean Crow on the bridge west of Merchant Square: one crow per retail spot, a single Crow Scatter Trap
DELETE FROM `creature` WHERE `guid` IN (376473,376474,376475,376476,376477,376601,376604,376606,376607,376629,376630,376631,376633,376634,376635,376636,376637,376648,376649,376650,376651,376652);
DELETE FROM `creature_addon` WHERE `guid` IN (376473,376474,376475,376476,376477,376601,376604,376606,376607,376629,376630,376631,376633,376634,376635,376636,376637,376648,376649,376650,376651,376652);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376473,-376474,-376475,-376476,-376477,-376601,-376604,-376606,-376607,-376629,-376630,-376631,-376633,-376634,-376635,-376636,-376637,-376648,-376649,-376650,-376651,-376652) AND `source_type`=0;
DELETE FROM `gameobject` WHERE `guid` IN (235552,235557,235558);

-- Gilnean Crow on the bridge: scatter when pinged by the Crow Scatter Trap, back 30 s later
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-376469,-376470,-376471,-376472,-376573,-376576,-376603,-376605,-376632) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-376469,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026008,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026008'),
(-376469,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376469,0,2,0,58,0,100,0,3,5026008,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026008 Ended - Despawn (Respawn 30 s)'),
(-376470,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026009,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026009'),
(-376470,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376470,0,2,0,58,0,100,0,3,5026009,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026009 Ended - Despawn (Respawn 30 s)'),
(-376471,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026010,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026010'),
(-376471,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376471,0,2,0,58,0,100,0,3,5026010,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026010 Ended - Despawn (Respawn 30 s)'),
(-376472,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026011,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026011'),
(-376472,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376472,0,2,0,58,0,100,0,3,5026011,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026011 Ended - Despawn (Respawn 30 s)'),
(-376573,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026012,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026012'),
(-376573,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376573,0,2,0,58,0,100,0,3,5026012,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026012 Ended - Despawn (Respawn 30 s)'),
(-376576,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026013,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026013'),
(-376576,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376576,0,2,0,58,0,100,0,3,5026013,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026013 Ended - Despawn (Respawn 30 s)'),
(-376603,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026014,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026014'),
(-376603,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376603,0,2,0,58,0,100,0,3,5026014,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026014 Ended - Despawn (Respawn 30 s)'),
(-376605,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026015,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026015'),
(-376605,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376605,0,2,0,58,0,100,0,3,5026015,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026015 Ended - Despawn (Respawn 30 s)'),
(-376632,0,0,0,8,0,100,0,93275,0,0,0,0,53,0,5026016,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Start Waypoint Path 5026016'),
(-376632,0,1,0,8,0,100,0,93275,0,0,0,0,91,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Spellhit ''Ping Gilnean Crow'' - Remove Stand State Sit'),
(-376632,0,2,0,58,0,100,0,3,5026016,0,0,0,41,1,30,0,0,0,0,1,0,0,0,0,0,0,0,0,'Gilnean Crow - On Waypoint 3 of Path 5026016 Ended - Despawn (Respawn 30 s)');

-- Gilnean Crow on the bridge: retail scatter flights
DELETE FROM `waypoint_path` WHERE `PathId` BETWEEN 5026008 AND 5026016;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Velocity`,`Comment`) VALUES
(5026008,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026009,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026010,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026011,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026012,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026013,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026014,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026015,1,0,NULL,'Gilnean Crow - Market Square bridge'),
(5026016,1,0,NULL,'Gilnean Crow - Market Square bridge');

DELETE FROM `waypoint_path_node` WHERE `PathId` BETWEEN 5026008 AND 5026016;
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(5026008,1,-1620.6810,1317.1345,25.9589,NULL,0),
(5026008,2,-1616.1359,1311.7178,33.0300,NULL,0),
(5026008,3,-1626.3057,1311.4620,34.0399,NULL,0),
(5026009,1,-1612.0432,1308.0608,25.5897,NULL,0),
(5026009,2,-1610.0942,1314.8579,32.6607,NULL,0),
(5026009,3,-1626.3888,1312.5868,34.1352,NULL,0),
(5026010,1,-1615.6330,1304.7509,26.3522,NULL,0),
(5026010,2,-1614.0424,1311.6406,33.4233,NULL,0),
(5026010,3,-1626.2814,1311.4043,34.3075,NULL,0),
(5026011,1,-1620.4708,1314.8779,25.9962,NULL,0),
(5026011,2,-1616.0209,1309.3827,33.0672,NULL,0),
(5026011,3,-1626.3402,1310.3156,34.0672,NULL,0),
(5026012,1,-1622.1329,1306.1013,26.6632,NULL,0),
(5026012,2,-1616.4124,1310.2576,33.7342,NULL,0),
(5026012,3,-1626.2863,1310.7324,34.3780,NULL,0),
(5026013,1,-1612.4999,1317.9827,26.5722,NULL,0),
(5026013,2,-1619.1445,1315.5642,33.6433,NULL,0),
(5026013,3,-1636.2535,1311.2118,35.0279,NULL,0),
(5026014,1,-1609.4090,1310.2886,26.4030,NULL,0),
(5026014,2,-1616.1711,1312.3560,33.4741,NULL,0),
(5026014,3,-1626.2994,1311.7789,34.2577,NULL,0),
(5026015,1,-1614.4396,1315.4319,26.9290,NULL,0),
(5026015,2,-1620.9485,1312.6690,34.0001,NULL,0),
(5026015,3,-1636.2535,1311.2118,35.0279,NULL,0),
(5026016,1,-1622.3785,1314.3230,26.7719,NULL,0),
(5026016,2,-1620.4294,1307.5259,33.8430,NULL,0),
(5026016,3,-1636.2535,1311.2118,35.0279,NULL,0);

-- Evacuate the Merchant Square 14098: knock summons land on the door's trigger, the Rampaging Worgen gets a script
-- 68087 (Frightened Citizen 34981), 68070 (Frightened Citizen 35836 + trigger 80281) and 80281 (Rampaging Worgen 35660)
-- target TARGET_DEST_NEARBY_ENTRY: give them the door's Generic Trigger LAB - Multiphase 35374 inside the house
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (68087,68070,80281);
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`NegativeCondition`,`ErrorType`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,68087,0,0,31,0,3,35374,0,0,0,0,'','Summon Frightened Citizen - Target Generic Trigger LAB - Multiphase'),
(13,3,68070,0,0,31,0,3,35374,0,0,0,0,'','Summon Frightened Citizen and Worgen - Target Generic Trigger LAB - Multiphase'),
(13,1,80281,0,0,31,0,3,35374,0,0,0,0,'','Summon Rampaging Worgen - Target Generic Trigger LAB - Multiphase');

-- Rampaging Worgen 35660: C++ script instead of SmartAI, created immune to PC and NPC (unit_flags 33536 on retail create)
UPDATE `creature_template` SET `AIName`='', `ScriptName`='npc_rampaging_worgen_evacuation', `unit_flags`=`unit_flags`|0x300 WHERE `entry`=35660;
DELETE FROM `smart_scripts` WHERE `entryorguid`=35660 AND `source_type`=0;

-- Frightened Citizen 35836 cowers with its line
UPDATE `creature_text` SET `Emote`=430 WHERE `CreatureID`=35836 AND `GroupID`=0;

-- Frightened Citizen 34981: missing line
DELETE FROM `creature_text` WHERE `CreatureID`=34981 AND `GroupID`=0 AND `ID`=7;
INSERT INTO `creature_text` (`CreatureID`,`GroupID`,`ID`,`Text`,`Type`,`Language`,`Probability`,`Emote`,`Duration`,`Sound`,`SoundPlayType`,`BroadcastTextId`,`TextRange`,`comment`) VALUES
(34981,0,7,'Thank you!',12,0,100,1,0,0,0,35230,0,'Frightened Citizen to Player');
