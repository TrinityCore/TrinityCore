-- Howling Fjord - Dereleict Strand

DELETE FROM `creature_addon` WHERE `guid` IN (118717, 118612, 118609);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(118717,0,0,8,1,0, ''),
(118612,0,0,0,1,27, ''),
(118609,0,0,0,1,27, '');

-- North Fleet Soldier SAI
SET @GUID := -118616;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,20000,20000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Set Flag Standstate Kneel"),
(@GUID,0,1,0,1,0,100,0,10000,10000,10000,10000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Remove Flag Standstate Kneel");

-- North Fleet Soldier SAI
SET @GUID := -118618;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,20000,20000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Set Flag Standstate Kneel"),
(@GUID,0,1,0,1,0,100,0,10000,10000,10000,10000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Remove Flag Standstate Kneel");

-- North Fleet Soldier SAI
SET @GUID := -118615;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,20000,20000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Set Flag Standstate Kneel"),
(@GUID,0,1,0,1,0,100,0,10000,10000,10000,10000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Remove Flag Standstate Kneel");

-- North Fleet Soldier SAI
SET @GUID := -118614;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,20000,20000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Set Flag Standstate Kneel"),
(@GUID,0,1,0,1,0,100,0,10000,10000,10000,10000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Remove Flag Standstate Kneel");

-- North Fleet Soldier SAI
SET @GUID := -118617;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=23793;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@GUID AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID,0,0,0,1,0,100,0,1000,1000,20000,20000,90,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Set Flag Standstate Kneel"),
(@GUID,0,1,0,1,0,100,0,10000,10000,10000,10000,91,8,0,0,0,0,0,1,0,0,0,0,0,0,0,"North Fleet Soldier - Out of Combat - Remove Flag Standstate Kneel");

SET @NPC := 118715;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1366.91,`position_y`=-6403.691,`position_z`=2.680478 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1366.91,-6403.691,2.680478,0,0,0,0,100,0),
(@PATH,2,1363.91,-6401.191,3.180478,0,0,0,0,100,0),
(@PATH,3,1361.41,-6399.191,3.680478,0,0,0,0,100,0),
(@PATH,4,1355.06,-6393.984,3.712503,0,0,0,0,100,0),
(@PATH,5,1364.06,-6401.234,3.212503,0,0,0,0,100,0),
(@PATH,6,1367.183,-6403.969,2.503129,0,0,0,0,100,0),
(@PATH,7,1379.433,-6410.219,2.003129,0,0,0,0,100,0),
(@PATH,8,1383.577,-6412.28,1.622055,0,0,0,0,100,0),
(@PATH,9,1400.694,-6411.621,1.439368,0,0,0,0,100,0),
(@PATH,10,1427.231,-6407.261,1.381301,0,0,0,0,100,0),
(@PATH,11,1438.388,-6408.347,1.346219,0,0,0,0,100,0),
(@PATH,12,1439.638,-6408.847,1.346219,0,0,0,0,100,0),
(@PATH,13,1441.138,-6410.347,1.596219,0,0,0,0,100,0),
(@PATH,14,1442.638,-6412.347,1.846219,0,0,0,0,100,0),
(@PATH,15,1444.79,-6415.361,2.014442,0,0,0,0,100,0),
(@PATH,16,1447.54,-6414.111,2.264442,0,0,0,0,100,0),
(@PATH,17,1450.79,-6412.611,3.014442,0,0,0,0,100,0),
(@PATH,18,1453.327,-6411.495,3.152454,0,0,0,0,100,0),
(@PATH,19,1456.827,-6403.495,2.402454,0,0,0,0,100,0),
(@PATH,20,1458.577,-6399.995,1.902454,0,0,0,0,100,0),
(@PATH,21,1459.675,-6397.563,2.077178,0,0,0,0,100,0),
(@PATH,22,1459.425,-6392.563,2.577178,0,0,0,0,100,0),
(@PATH,23,1459.175,-6389.563,3.327178,0,0,0,0,100,0),
(@PATH,24,1458.925,-6386.563,4.077178,0,0,0,0,100,0),
(@PATH,25,1458.675,-6382.813,4.327178,0,0,0,0,100,0),
(@PATH,26,1458.175,-6375.813,5.077178,0,0,0,0,100,0),
(@PATH,27,1457.925,-6372.063,5.577178,0,0,0,0,100,0),
(@PATH,28,1457.675,-6369.063,6.327178,0,0,0,0,100,0),
(@PATH,29,1457.675,-6366.063,7.077178,0,0,0,0,100,0),
(@PATH,30,1457.49,-6365.789,7.133235,0,0,0,0,100,0),
(@PATH,31,1457.49,-6365.289,7.133235,0,0,0,0,100,0),
(@PATH,32,1459.66,-6364.438,7.431883,0,0,0,0,100,0),
(@PATH,33,1459.776,-6364.708,7.375866,0,0,0,0,100,0),
(@PATH,34,1457.526,-6365.458,7.125866,0,0,0,0,100,0),
(@PATH,35,1457.776,-6367.458,6.875866,0,0,0,0,100,0),
(@PATH,36,1457.776,-6370.458,6.125866,0,0,0,0,100,0),
(@PATH,37,1458.026,-6373.458,5.375866,0,0,0,0,100,0),
(@PATH,38,1458.526,-6377.458,4.625866,0,0,0,0,100,0),
(@PATH,39,1459.026,-6384.208,4.375866,0,0,0,0,100,0),
(@PATH,40,1459.276,-6388.208,3.625866,0,0,0,0,100,0),
(@PATH,41,1459.526,-6391.208,3.125866,0,0,0,0,100,0),
(@PATH,42,1459.776,-6394.208,2.375866,0,0,0,0,100,0),
(@PATH,43,1459.735,-6397.894,1.937207,0,0,0,0,100,0),
(@PATH,44,1456.985,-6403.394,2.437207,0,0,0,0,100,0),
(@PATH,45,1455.985,-6405.644,2.937207,0,0,0,0,100,0),
(@PATH,46,1452.916,-6411.519,2.985259,0,0,0,0,100,0),
(@PATH,47,1448.666,-6413.519,2.485259,0,0,0,0,100,0),
(@PATH,48,1444.586,-6415.515,1.851662,0,0,0,0,100,0),
(@PATH,49,1442.836,-6412.265,1.851662,0,0,0,0,100,0),
(@PATH,50,1441.836,-6411.015,1.601662,0,0,0,0,100,0),
(@PATH,51,1439.836,-6408.765,1.601662,0,0,0,0,100,0),
(@PATH,52,1439.502,-6408.882,1.482241,0,0,0,0,100,0),
(@PATH,53,1438.502,-6408.882,1.232241,0,0,0,0,100,0),
(@PATH,54,1426.759,-6407.316,1.181526,0,0,0,0,100,0),
(@PATH,55,1400.52,-6411.691,1.317291,0,0,0,0,100,0),
(@PATH,56,1383.313,-6412.44,1.821733,0,0,0,0,100,0),
(@PATH,57,1376.313,-6408.69,2.071733,0,0,0,0,100,0);

SET @NPC := 108486;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1472.888,`position_y`=-6264.896,`position_z`=5.352096 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1472.888,-6264.896,5.352096,0,0,0,0,100,0),
(@PATH,2,1473.138,-6265.646,5.352096,0,0,0,0,100,0),
(@PATH,3,1471.138,-6276.396,5.852096,0,0,0,0,100,0),
(@PATH,4,1469.888,-6283.146,6.352096,0,0,0,0,100,0),
(@PATH,5,1468.638,-6290.896,6.852096,0,0,0,0,100,0),
(@PATH,6,1467.138,-6298.896,7.602096,0,0,0,0,100,0),
(@PATH,7,1467.035,-6299.166,7.627969,0,0,0,0,100,0),
(@PATH,8,1467.035,-6299.916,7.377969,0,0,0,0,100,0),
(@PATH,9,1467.035,-6308.916,8.12797,0,0,0,0,100,0),
(@PATH,10,1467.126,-6323.873,7.746972,0,0,0,0,100,0),
(@PATH,11,1471.376,-6329.373,7.246972,0,0,0,0,100,0),
(@PATH,12,1477.948,-6337.766,6.911916,5.416241,0,0,0,100,0),
(@PATH,13,1474.383,-6323.951,7.680174,0,0,0,0,100,0),
(@PATH,14,1472.883,-6318.451,8.180174,0,0,0,0,100,0),
(@PATH,15,1468.028,-6299.964,7.639977,0,0,0,0,100,0),
(@PATH,16,1469.528,-6292.964,7.139977,0,0,0,0,100,0),
(@PATH,17,1471.028,-6286.214,6.389977,0,0,0,0,100,0),
(@PATH,18,1472.528,-6278.714,6.139977,0,0,0,0,100,0),
(@PATH,19,1474.028,-6270.714,5.389977,0,0,0,0,100,0),
(@PATH,20,1474.964,-6266.524,5.035554,0,0,0,0,100,0),
(@PATH,21,1475.214,-6248.774,5.785554,0,0,0,0,100,0),
(@PATH,22,1475.268,-6247.398,5.807261,0,0,0,0,100,0),
(@PATH,23,1471.348,-6240.949,5.550797,2.094752,0,0,0,100,0);

SET @NPC := 101318;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1488.648,`position_y`=-6204.83,`position_z`=5.769119 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1488.648,-6204.83,5.769119,0,0,0,0,100,0),
(@PATH,2,1497.148,-6226.08,5.269119,0,0,0,0,100,0),
(@PATH,3,1500.011,-6233.605,5.060438,0,0,0,0,100,0),
(@PATH,4,1500.011,-6260.355,5.310438,0,0,0,0,100,0),
(@PATH,5,1500.011,-6265.355,5.810438,0,0,0,0,100,0),
(@PATH,6,1500.109,-6265.473,5.888788,0,0,0,0,100,0),
(@PATH,7,1500.109,-6266.973,6.138788,0,0,0,0,100,0),
(@PATH,8,1508.791,-6290.721,6.167375,0,0,0,0,100,0),
(@PATH,9,1507.291,-6299.471,6.667375,0,0,0,0,100,0),
(@PATH,10,1505.291,-6314.221,7.167375,0,0,0,0,100,0),
(@PATH,11,1505.904,-6314.034,7.007656,0,0,0,0,100,0),
(@PATH,12,1510.183,-6300.333,6.515838,0,0,0,0,100,0),
(@PATH,13,1510.183,-6293.333,6.015838,0,0,0,0,100,0),
(@PATH,14,1511.227,-6266.65,5.682878,0,0,0,0,100,0),
(@PATH,15,1508.227,-6241.15,6.182878,0,0,0,0,100,0),
(@PATH,16,1507.123,-6232.67,5.979321,0,0,0,0,100,0),
(@PATH,17,1502.351,-6201.641,6.309025,0,0,0,0,100,0),
(@PATH,18,1490.271,-6207.956,6.065028,0,0,0,0,100,0);

SET @NPC := 101307;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1570.567,`position_y`=-6265.962,`position_z`=6.703756 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1570.567,-6265.962,6.703756,0,0,0,0,100,0),
(@PATH,2,1571.317,-6266.712,6.453756,0,0,0,0,100,0),
(@PATH,3,1579.416,-6265.596,7.200127,0,0,0,0,100,0),
(@PATH,4,1578.416,-6266.596,7.200127,0,0,0,0,100,0),
(@PATH,5,1577.416,-6270.596,7.450127,0,0,0,0,100,0),
(@PATH,6,1577.416,-6274.846,7.700127,0,0,0,0,100,0),
(@PATH,7,1578.667,-6276.01,7.95574,0,0,0,0,100,0),
(@PATH,8,1579.167,-6278.51,8.20574,0,0,0,0,100,0),
(@PATH,9,1569.438,-6279.025,7.695375,0,0,0,0,100,0),
(@PATH,10,1566.438,-6278.525,7.195375,0,0,0,0,100,0),
(@PATH,11,1563.438,-6278.275,6.695375,0,0,0,0,100,0),
(@PATH,12,1539.938,-6275.525,6.195375,0,0,0,0,100,0),
(@PATH,13,1533.601,-6274.893,5.569158,0,0,0,0,100,0),
(@PATH,14,1522.351,-6284.643,5.819158,0,0,0,0,100,0),
(@PATH,15,1506.851,-6298.143,6.569158,0,0,0,0,100,0),
(@PATH,16,1506.571,-6298.359,6.857921,0,0,0,0,100,0),
(@PATH,17,1505.071,-6299.609,6.607921,0,0,0,0,100,0),
(@PATH,18,1498.321,-6301.609,7.357921,0,0,0,0,100,0),
(@PATH,19,1494.571,-6302.359,7.607921,0,0,0,0,100,0),
(@PATH,20,1490.071,-6303.859,8.357921,0,0,0,0,100,0),
(@PATH,21,1480.551,-6306.729,8.720417,0,0,0,0,100,0),
(@PATH,22,1469.551,-6319.479,8.220417,0,0,0,0,100,0),
(@PATH,23,1457.14,-6332.838,8.262967,0,0,0,0,100,0),
(@PATH,24,1444.39,-6333.088,7.512967,0,0,0,0,100,0),
(@PATH,25,1439.39,-6333.088,7.012967,0,0,0,0,100,0),
(@PATH,26,1434.39,-6333.088,6.512967,0,0,0,0,100,0),
(@PATH,27,1434.122,-6333.369,6.238153,0,0,0,0,100,0),
(@PATH,28,1433.122,-6333.369,6.238153,0,0,0,0,100,0),
(@PATH,29,1411.013,-6333.472,6.215061,0,0,0,0,100,0),
(@PATH,30,1412.691,-6340.484,6.268942,0,0,0,0,100,0),
(@PATH,31,1409.974,-6339.788,6.441183,0,0,0,0,100,0),
(@PATH,32,1407.367,-6339.119,6.361105,0,0,0,0,100,0),
(@PATH,33,1406.214,-6339.782,7.377893,0,0,0,0,100,0),
(@PATH,34,1406.561,-6340.945,7.394681,1.154748,5000,0,0,100,0),
(@PATH,35,1407.723,-6339.971,6.870447,0,0,0,0,100,0),
(@PATH,36,1428.595,-6309.238,6.015383,0,0,0,0,100,0),
(@PATH,37,1433.345,-6302.738,5.515383,0,0,0,0,100,0),
(@PATH,38,1433.623,-6302.414,5.622099,0,0,0,0,100,0),
(@PATH,39,1434.623,-6301.164,5.622099,0,0,0,0,100,0),
(@PATH,40,1445.623,-6292.664,5.872099,0,0,0,0,100,0),
(@PATH,41,1449.123,-6289.664,6.372099,0,0,0,0,100,0),
(@PATH,42,1465.615,-6277.031,6.045777,0,0,0,0,100,0),
(@PATH,43,1500.381,-6274.618,6.177592,0,0,0,0,100,0),
(@PATH,44,1509.881,-6267.618,5.927592,0,0,0,0,100,0),
(@PATH,45,1515.381,-6263.368,5.427592,0,0,0,0,100,0),
(@PATH,46,1530.381,-6252.118,6.177592,0,0,0,0,100,0),
(@PATH,47,1533.511,-6249.774,6.607514,0,0,0,0,100,0),
(@PATH,48,1537.261,-6246.524,6.857514,0,0,0,0,100,0),
(@PATH,49,1555.521,-6246.682,6.738133,0,0,0,0,100,0),
(@PATH,50,1562.639,-6250.232,6.456325,0,0,0,0,100,0);
