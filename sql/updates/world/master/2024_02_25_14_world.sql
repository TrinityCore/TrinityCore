-- Add SAI to Panicked Citizen Entry: 34851
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=34851;

SET @RESPAWN := 2;

-- Pathing for Panicked Citizen 
SET @CGUID := 376371;
SET @PATH := 34851 * 100 + 0;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1557.4011,1332.6024,35.722572,NULL,0),
(@PATH,2,-1557.6598,1333.9774,35.63924,NULL,0),
(@PATH,3,-1557.9185,1335.3524,35.55591,NULL,0),
(@PATH,4,-1554.1493,1358.4913,35.555916,NULL,0),
(@PATH,5,-1550.8976,1378.5885,35.555916,NULL,0),
(@PATH,6,-1541.3663,1388.0035,35.555916,NULL,0),
(@PATH,7,-1513.9844,1391.6649,35.555916,NULL,0),
(@PATH,8,-1487.981,1390.5435,35.55591,NULL,0),
(@PATH,9,-1463.4462,1392.0591,35.555916,NULL,0),
(@PATH,10,-1446.1858,1381.3993,35.555935,NULL,0),
(@PATH,11,-1441.4531,1364.224,35.555935,NULL,0),
(@PATH,12,-1449.3108,1355.349,35.555935,NULL,0),
(@PATH,13,-1477.9427,1346.3942,35.555935,NULL,0),
(@PATH,14,-1486.1406,1337.4115,35.705914,NULL,0),
(@PATH,15,-1486.1406,1337.4115,35.705914,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,15,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 15 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376367;
SET @PATH := 34851 * 100 + 1;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1562.0626,1391.9254,36.616646,NULL,0),
(@PATH,2,-1566.0209,1390.8351,36.08628,NULL,0),
(@PATH,3,-1569.9791,1389.7448,35.555916,NULL,0),
(@PATH,4,-1559.1302,1390.5486,35.555916,NULL,0),
(@PATH,5,-1537.6163,1390.6666,35.555916,NULL,0),
(@PATH,6,-1520.1406,1391.868,35.555916,NULL,0),
(@PATH,7,-1481.0695,1396.9531,35.55591,NULL,0),
(@PATH,8,-1455.033,1398.9341,35.55591,NULL,0),
(@PATH,9,-1433.5642,1376.981,35.555935,NULL,0),
(@PATH,10,-1414.5192,1369.8872,35.555935,NULL,0),
(@PATH,11,-1403.7865,1391.5642,35.555923,NULL,0),
(@PATH,12,-1396.4462,1403.7483,35.96074,NULL,0),
(@PATH,13,-1396.4462,1403.7483,35.96074,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,13,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 13 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376318;
SET @PATH := 34851 * 100 + 2;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1517.1129,1367.2864,35.760757,NULL,0),
(@PATH,2,-1517.1841,1358.6823,35.675426,NULL,0),
(@PATH,3,-1517.2552,1350.0781,35.590096,NULL,0),
(@PATH,4,-1499.8942,1346.2361,35.555935,NULL,0),
(@PATH,5,-1485.7848,1346.5017,35.555935,NULL,0),
(@PATH,6,-1465.3541,1349.658,35.555935,NULL,0),
(@PATH,7,-1455.5764,1362.0295,35.555935,NULL,0),
(@PATH,8,-1452.5695,1376.5817,35.983498,NULL,0),
(@PATH,9,-1435.3837,1399.6216,35.555935,NULL,0),
(@PATH,10,-1436.967,1418.2291,35.555923,NULL,0),
(@PATH,11,-1423.0295,1417.8455,35.555935,NULL,0),
(@PATH,12,-1421.2673,1413.5712,36.78822,NULL,0),
(@PATH,13,-1421.2673,1413.5712,36.78822,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,13,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 13 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376345;
SET @PATH := 34851 * 100 + 3;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1395.1199,1432.106,35.722588,NULL,0),
(@PATH,2,-1398.1129,1431.0591,35.639256,NULL,0),
(@PATH,3,-1401.106,1430.0122,35.555923,NULL,0),
(@PATH,4,-1403.9358,1423.4948,35.555923,NULL,0),
(@PATH,5,-1404.2448,1395.625,35.555923,NULL,0),
(@PATH,6,-1406.974,1376.4445,35.555935,NULL,0),
(@PATH,7,-1412.8889,1366.2882,35.555935,NULL,0),
(@PATH,8,-1446.9166,1358.1754,35.555935,NULL,0),
(@PATH,9,-1479.6754,1349.5885,35.555935,NULL,0),
(@PATH,10,-1512.6007,1340.9723,35.555912,NULL,0),
(@PATH,11,-1545.6233,1331.4635,35.555935,NULL,0),
(@PATH,12,-1578.9254,1316.8889,35.555923,NULL,0),
(@PATH,13,-1603.4497,1312.6442,18.28202,NULL,0),
(@PATH,14,-1628.106,1308.6041,20.266262,NULL,0),
(@PATH,15,-1649.9219,1307.349,19.782322,NULL,0),
(@PATH,16,-1682.4462,1305.8646,19.782318,NULL,0),
(@PATH,17,-1689.481,1304.6354,19.782318,NULL,0),
(@PATH,18,-1692.3646,1297.5312,20.284113,NULL,0),
(@PATH,19,-1692.3646,1297.5312,20.284113,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,19,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 19 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376353;
SET @PATH := 34851 * 100 + 4;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1478.5085,1356.731,35.7226,NULL,0),
(@PATH,2,-1475.9166,1355.6216,35.639267,NULL,0),
(@PATH,3,-1473.3247,1354.5122,35.555935,NULL,0),
(@PATH,4,-1464.3611,1353.6111,35.555935,NULL,0),
(@PATH,5,-1456.9236,1359.3317,35.555935,NULL,0),
(@PATH,6,-1453.6685,1382.2344,35.86046,NULL,0),
(@PATH,7,-1472.6754,1390.3872,35.55591,NULL,0),
(@PATH,8,-1515.8281,1398.9791,35.555916,NULL,0),
(@PATH,9,-1540.9861,1399.3403,35.555916,NULL,0),
(@PATH,10,-1553.0798,1387.4688,35.57604,NULL,0),
(@PATH,11,-1560.1945,1364.8767,35.670723,NULL,0),
(@PATH,12,-1579.1562,1364.8698,35.749073,NULL,0),
(@PATH,13,-1583.474,1360.9688,35.998745,NULL,0),
(@PATH,14,-1583.474,1360.9688,35.998745,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,14,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 14 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376369;
SET @PATH := 34851 * 100 + 5;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1553.3905,1441.981,36.19169,NULL,0),
(@PATH,2,-1545.533,1436.9202,35.873802,NULL,0),
(@PATH,3,-1537.6754,1431.8594,35.555916,NULL,0),
(@PATH,4,-1508.5642,1420.9531,35.555916,NULL,0),
(@PATH,5,-1502.3629,1410.7413,35.55592,NULL,0),
(@PATH,6,-1499.8872,1397.2969,35.55591,NULL,0),
(@PATH,7,-1500.0226,1375.356,35.555912,NULL,0),
(@PATH,8,-1496.6858,1351.5295,35.555927,NULL,0),
(@PATH,9,-1474.1493,1349.4861,35.555935,NULL,0),
(@PATH,10,-1455.941,1353.3125,35.555935,NULL,0),
(@PATH,11,-1442.3351,1370.3281,35.555935,NULL,0),
(@PATH,12,-1443.8021,1397.6666,35.55591,NULL,0),
(@PATH,13,-1446.9774,1419.5747,35.55591,NULL,0),
(@PATH,14,-1463.3073,1441.8264,35.991337,NULL,0),
(@PATH,15,-1463.3073,1441.8264,35.991337,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,15,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 15 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376344;
SET @PATH := 34851 * 100 + 6;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1469.4896,1444.3473,35.722603,NULL,0),
(@PATH,2,-1476.8108,1439.6233,35.639256,NULL,0),
(@PATH,3,-1484.132,1434.8993,35.55591,NULL,0),
(@PATH,4,-1494.2188,1427.0209,35.55591,NULL,0),
(@PATH,5,-1513.0156,1419.2969,35.555916,NULL,0),
(@PATH,6,-1533.981,1421.5521,35.555916,NULL,0),
(@PATH,7,-1546.8733,1412.9844,35.555916,NULL,0),
(@PATH,8,-1555.7986,1380.9392,35.555916,NULL,0),
(@PATH,9,-1559.8629,1361.9514,35.555916,NULL,0),
(@PATH,10,-1564.8091,1348.467,35.555916,NULL,0),
(@PATH,11,-1565.9358,1326.4341,35.555916,NULL,0),
(@PATH,12,-1575.7101,1319.4514,35.65964,NULL,0),
(@PATH,13,-1603.9723,1314.3802,18.27019,NULL,0),
(@PATH,14,-1627.9861,1309.8611,20.290205,NULL,0),
(@PATH,15,-1656.349,1307.0781,19.782318,NULL,0),
(@PATH,16,-1675.7361,1314.0834,20.291834,NULL,0),
(@PATH,17,-1675.7361,1314.0834,20.291834,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,17,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 17 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));

-- Pathing for Panicked Citizen
SET @CGUID := 376349;
SET @PATH := 34851 * 100 + 7;
DELETE FROM `waypoint_path` WHERE `PathId`=@PATH;
INSERT INTO `waypoint_path` (`PathId`,`MoveType`,`Flags`,`Comment`) VALUES
(@PATH,1,0,'Panicked Citizen - On Respawn');
DELETE FROM `waypoint_path_node` WHERE `PathId` IN (@PATH);
INSERT INTO `waypoint_path_node` (`PathId`,`NodeId`,`PositionX`,`PositionY`,`PositionZ`,`Orientation`,`Delay`) VALUES
(@PATH,1,-1426.9183,1433.1615,35.7226,NULL,0),
(@PATH,2,-1432.875,1431.6459,35.639267,NULL,0),
(@PATH,3,-1438.8317,1430.1302,35.555935,NULL,0),
(@PATH,4,-1460.7048,1424.3368,35.55591,NULL,0),
(@PATH,5,-1484.4584,1424.6198,35.55591,NULL,0),
(@PATH,6,-1495.3212,1424.4445,35.55591,NULL,0),
(@PATH,7,-1519.1702,1424.1545,35.555916,NULL,0),
(@PATH,8,-1537.375,1418.9723,35.555916,NULL,0),
(@PATH,9,-1546.2639,1405.8125,35.555916,NULL,0),
(@PATH,10,-1542.0591,1392.9861,35.555916,NULL,0),
(@PATH,11,-1516.75,1390.3923,35.555916,NULL,0),
(@PATH,12,-1505.2778,1381.6024,35.555916,NULL,0),
(@PATH,13,-1500.9688,1364.6267,35.55591,NULL,0),
(@PATH,14,-1505.4479,1345.691,35.555935,NULL,0),
(@PATH,15,-1516.7188,1340.099,35.555916,NULL,0),
(@PATH,16,-1528.8368,1334.5591,35.55593,NULL,0),
(@PATH,17,-1530.0173,1325.1945,35.84444,NULL,0),
(@PATH,18,-1530.0173,1325.1945,35.84444,NULL,0);
-- Panicked Citizen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (-@CGUID) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(-@CGUID,0,0,0,11,0,100,0,0,0,0,0,0,53,0,@PATH,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On respawn - Self: Start path #', @PATH, ', walk, do not repeat, Passive')),
(-@CGUID,0,1,0,58,0,100,0,18,@PATH,0,0,0,41,1,@RESPAWN,0,0,0,0,1,0,0,0,0,0,0,0,0,CONCAT('On waypoint 18 of path ', @PATH, ' ended - Self: Despawn in 0.001 s respawn in 2 seconds'));
