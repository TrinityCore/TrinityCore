-- Fix and remove some Ango'rosh Souleater & Mauler spawns
DELETE FROM `creature_addon` WHERE `guid` IN (SELECT guid FROM creature WHERE id=18121);
UPDATE `creature_template_addon` SET `auras`= '35194' WHERE `entry`=18121;
DELETE FROM creature WHERE guid IN (64230,64242,64259,64229,64240);
UPDATE `creature` SET `spawndist`=5,`MovementType`=1,`position_x`=1819.455,`position_y`=8405.807,`position_z`=-8.42151 WHERE `guid`=64261;

-- Ango'rosh Shadowmage SAI
SET @ENTRY := 20444;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,0,0,2400,3800,11,9613,64,0,0,0,0,2,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - In Combat CMC - Cast 'Shadow Bolt'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,19000,11,9657,1,0,0,0,0,1,0,0,0,0,0,0,0,"Ango'rosh Shadowmage - In Combat - Cast 'Shadow Shell'");

-- Pathing for Ango'rosh Souleater Entry: 18121
SET @NPC := 64246;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1483.504,`position_y`=8615.958,`position_z`=-23.3291 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '35194');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1483.504,8615.958,-23.3291,0,0,0,0,100,0),
(@PATH,2,1502.414,8615.582,-27.77901,0,0,0,0,100,0),
(@PATH,3,1549.829,8613.372,-33.61022,0,0,0,0,100,0),
(@PATH,4,1595.268,8608.182,-32.85706,0,0,0,0,100,0),
(@PATH,5,1549.829,8613.372,-33.61022,0,0,0,0,100,0),
(@PATH,6,1502.414,8615.582,-27.77901,0,0,0,0,100,0);

-- Pathing for Ango'rosh Mauler Entry: 18120
SET @NPC := 64228;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1764.775,`position_y`=8621.494,`position_z`=3.295652 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1764.775,8621.494,3.295652,0,0,0,0,100,0),
(@PATH,2,1755.779,8625.817,4.385007,0,0,0,0,100,0),
(@PATH,3,1744.3,8627.528,6.188718,0,0,0,0,100,0),
(@PATH,4,1729.123,8630.341,6.311835,0,0,0,0,100,0),
(@PATH,5,1717.921,8632.591,8.065008,0,0,0,0,100,0),
(@PATH,6,1699.805,8628.589,12.01016,0,0,0,0,100,0),
(@PATH,7,1689.124,8621.329,12.50693,0,0,0,0,100,0),
(@PATH,8,1681.696,8611.765,12.6384,0,0,0,0,100,0),
(@PATH,9,1675.004,8605.295,12.36166,0,0,0,0,100,0),
(@PATH,10,1664.974,8601.517,10.78405,0,0,0,0,100,0),
(@PATH,11,1655.826,8594.225,8.950456,0,0,0,0,100,0),
(@PATH,12,1649.307,8586.103,8.346086,0,0,0,0,100,0),
(@PATH,13,1655.826,8594.225,8.950456,0,0,0,0,100,0),
(@PATH,14,1664.974,8601.517,10.78405,0,0,0,0,100,0),
(@PATH,15,1675.004,8605.295,12.36166,0,0,0,0,100,0),
(@PATH,16,1681.696,8611.765,12.6384,0,0,0,0,100,0),
(@PATH,17,1689.124,8621.329,12.50693,0,0,0,0,100,0),
(@PATH,18,1699.805,8628.589,12.01016,0,0,0,0,100,0),
(@PATH,19,1717.921,8632.591,8.065008,0,0,0,0,100,0),
(@PATH,20,1729.123,8630.341,6.311835,0,0,0,0,100,0),
(@PATH,21,1744.3,8627.528,6.188718,0,0,0,0,100,0),
(@PATH,22,1755.779,8625.817,4.385007,0,0,0,0,100,0),
(@PATH,23,1764.717,8621.615,3.358396,0,0,0,0,100,0),
(@PATH,24,1770.793,8609.967,0.8600597,0,0,0,0,100,0),
(@PATH,25,1778.085,8581.91,-7.021969,0,0,0,0,100,0),
(@PATH,26,1781.569,8556.616,-9.007608,0,0,0,0,100,0),
(@PATH,27,1791.778,8532.473,-16.78218,0,0,0,0,100,0),
(@PATH,28,1806.07,8517.046,-16.52869,0,0,0,0,100,0),
(@PATH,29,1812.219,8498.097,-19.58127,0,0,0,0,100,0),
(@PATH,30,1805.245,8477.743,-19.69052,0,0,0,0,100,0),
(@PATH,31,1809.99,8468.151,-16.3652,0,0,0,0,100,0),
(@PATH,32,1822.48,8447.891,-16.88681,0,0,0,0,100,0),
(@PATH,33,1809.99,8468.151,-16.3652,0,0,0,0,100,0),
(@PATH,34,1805.245,8477.743,-19.69052,0,0,0,0,100,0),
(@PATH,35,1812.219,8498.097,-19.58127,0,0,0,0,100,0),
(@PATH,36,1806.07,8517.046,-16.52869,0,0,0,0,100,0),
(@PATH,37,1791.797,8532.447,-16.83393,0,0,0,0,100,0),
(@PATH,38,1781.569,8556.616,-9.007608,0,0,0,0,100,0),
(@PATH,39,1778.085,8581.91,-7.021969,0,0,0,0,100,0),
(@PATH,40,1770.793,8609.967,0.8600597,0,0,0,0,100,0);

-- Pathing for Ango'rosh Mauler Entry: 18120
SET @NPC := 64223;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1394.517,`position_y`=8623.379,`position_z`=9.483105 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1394.517,8623.379,9.483105,0,0,0,0,100,0),
(@PATH,2,1367.01,8619.995,14.69728,0,0,0,0,100,0),
(@PATH,3,1348.54,8608.503,18.98279,0,0,0,0,100,0),
(@PATH,4,1330.298,8594.458,20.70809,0,0,0,0,100,0),
(@PATH,5,1312.62,8590.247,19.89278,0,0,0,0,100,0),
(@PATH,6,1271.029,8590.587,19.02531,0,0,0,0,100,0),
(@PATH,7,1312.62,8590.247,19.89278,0,0,0,0,100,0),
(@PATH,8,1330.298,8594.458,20.70809,0,0,0,0,100,0),
(@PATH,9,1348.514,8608.496,18.99512,0,0,0,0,100,0),
(@PATH,10,1367.01,8619.995,14.69728,0,0,0,0,100,0),
(@PATH,11,1394.517,8623.379,9.483105,0,0,0,0,100,0),
(@PATH,12,1409.568,8618.852,5.867712,0,0,0,0,100,0),
(@PATH,13,1424.441,8607.313,3.257421,0,0,0,0,100,0),
(@PATH,14,1441.44,8607.563,-2.581793,0,0,0,0,100,0),
(@PATH,15,1461.23,8614.597,-12.20679,0,0,0,0,100,0),
(@PATH,16,1484.593,8616.813,-23.64642,0,0,0,0,100,0),
(@PATH,17,1461.683,8614.68,-12.70679,0,0,0,0,100,0),
(@PATH,18,1441.522,8607.562,-2.717291,0,0,0,0,100,0),
(@PATH,19,1424.441,8607.313,3.257421,0,0,0,0,100,0),
(@PATH,20,1409.568,8618.852,5.867712,0,0,0,0,100,0);

-- Pathing for Ango'rosh Mauler Entry: 18120
SET @NPC := 64232;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1608.688,`position_y`=8551.909,`position_z`=-15.61611 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1608.688,8551.909,-15.61611,0,0,0,0,100,0),
(@PATH,2,1606.189,8568.754,-21.79966,0,0,0,0,100,0),
(@PATH,3,1608.48,8584.462,-29.34727,0,0,0,0,100,0),
(@PATH,4,1606.189,8568.754,-21.79966,0,0,0,0,100,0),
(@PATH,5,1608.679,8551.937,-15.42959,0,0,0,0,100,0),
(@PATH,6,1611.307,8535.476,-8.693747,0,0,0,0,100,0),
(@PATH,7,1615.581,8524.725,-6.334841,0,0,0,0,100,0),
(@PATH,8,1622.581,8518.366,-5.849367,0,0,0,0,100,0),
(@PATH,9,1631.158,8510.858,-6.801638,0,0,0,0,100,0),
(@PATH,10,1644.64,8504.219,-7.020604,0,0,0,0,100,0),
(@PATH,11,1654.69,8501.367,-6.633519,0,0,0,0,100,0),
(@PATH,12,1665.907,8502.825,-6.924901,0,0,0,0,100,0),
(@PATH,13,1672.206,8501.249,-7.81,0,0,0,0,100,0),
(@PATH,14,1677.826,8494.035,-8.564032,0,0,0,0,100,0),
(@PATH,15,1689.134,8484.7,-7.435247,0,0,0,0,100,0),
(@PATH,16,1700.158,8477,-6.369071,0,0,0,0,100,0),
(@PATH,17,1689.134,8484.7,-7.435247,0,0,0,0,100,0),
(@PATH,18,1677.826,8494.035,-8.564032,0,0,0,0,100,0),
(@PATH,19,1672.206,8501.249,-7.81,0,0,0,0,100,0),
(@PATH,20,1665.907,8502.825,-6.924901,0,0,0,0,100,0),
(@PATH,21,1654.69,8501.367,-6.633519,0,0,0,0,100,0),
(@PATH,22,1644.64,8504.219,-7.020604,0,0,0,0,100,0),
(@PATH,23,1631.158,8510.858,-6.801638,0,0,0,0,100,0),
(@PATH,24,1622.581,8518.366,-5.849367,0,0,0,0,100,0),
(@PATH,25,1615.581,8524.725,-6.334841,0,0,0,0,100,0),
(@PATH,26,1611.307,8535.476,-8.693747,0,0,0,0,100,0);

-- Pathing for Ango'rosh Mauler Entry: 18120
SET @NPC := 64239;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1643.826,`position_y`=8612.983,`position_z`=-31.12585 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1643.826,8612.983,-31.12585,0,0,0,0,100,0),
(@PATH,2,1636.367,8611.652,-28.45675,0,0,0,0,100,0),
(@PATH,3,1631.083,8610.185,-27.16004,0,0,0,0,100,0),
(@PATH,4,1624.009,8607.951,-25.66858,0,0,0,0,100,0),
(@PATH,5,1630.667,8610.061,-27.07753,0,0,0,0,100,0),
(@PATH,6,1636.367,8611.652,-28.45675,0,0,0,0,100,0),
(@PATH,7,1643.823,8612.983,-31.1251,0,0,0,0,100,0),
(@PATH,8,1653.174,8612.425,-33.30415,0,0,0,0,100,0),
(@PATH,9,1659.041,8606.214,-35.02015,0,0,0,0,100,0),
(@PATH,10,1663.339,8595.787,-39.44561,0,0,0,0,100,0),
(@PATH,11,1668.673,8580.869,-43.56666,0,0,0,0,100,0),
(@PATH,12,1672.773,8571.901,-45.45698,0,0,0,0,100,0),
(@PATH,13,1683.156,8565.985,-47.18433,0,0,0,0,100,0),
(@PATH,14,1706.897,8560.648,-45.62059,0,0,0,0,100,0),
(@PATH,15,1683.156,8565.985,-47.18433,0,0,0,0,100,0),
(@PATH,16,1672.773,8571.901,-45.45698,0,0,0,0,100,0),
(@PATH,17,1668.673,8580.869,-43.56666,0,0,0,0,100,0),
(@PATH,18,1663.339,8595.787,-39.44561,0,0,0,0,100,0),
(@PATH,19,1659.041,8606.214,-35.02015,0,0,0,0,100,0),
(@PATH,20,1653.174,8612.425,-33.30415,0,0,0,0,100,0);

-- Pathing for Ango'rosh Mauler Entry: 18120
SET @NPC := 64241;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=1654.654,`position_y`=8521.531,`position_z`=-53.58351 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,1654.654,8521.531,-53.58351,0,0,0,0,100,0),
(@PATH,2,1649.625,8510.094,-54.21131,0,0,0,0,100,0),
(@PATH,3,1648.938,8498.171,-53.83168,0,0,0,0,100,0),
(@PATH,4,1656.672,8485.056,-55.70977,0,0,0,0,100,0),
(@PATH,5,1668.375,8473.033,-58.77278,0,0,0,0,100,0),
(@PATH,6,1682.668,8469.868,-61.03103,0,0,0,0,100,0),
(@PATH,7,1693.718,8469.74,-60.3237,0,0,0,0,100,0),
(@PATH,8,1702.251,8470.647,-59.50084,0,0,0,0,100,0),
(@PATH,9,1715.028,8473.496,-57.46725,0,0,0,0,100,0),
(@PATH,10,1702.251,8470.647,-59.50084,0,0,0,0,100,0),
(@PATH,11,1693.747,8469.74,-60.23508,0,0,0,0,100,0),
(@PATH,12,1682.668,8469.868,-61.03103,0,0,0,0,100,0),
(@PATH,13,1668.375,8473.033,-58.77278,0,0,0,0,100,0),
(@PATH,14,1656.672,8485.056,-55.70977,0,0,0,0,100,0),
(@PATH,15,1648.938,8498.171,-53.83168,0,0,0,0,100,0),
(@PATH,16,1649.625,8510.094,-54.21131,0,0,0,0,100,0),
(@PATH,17,1654.654,8521.531,-53.58351,0,0,0,0,100,0),
(@PATH,18,1664.266,8535.215,-51.28564,0,0,0,0,100,0),
(@PATH,19,1673.347,8538.975,-49.83964,0,0,0,0,100,0),
(@PATH,20,1687.687,8539.301,-49.18303,0,0,0,0,100,0),
(@PATH,21,1698.444,8539.608,-48.25351,0,0,0,0,100,0),
(@PATH,22,1687.687,8539.301,-49.18303,0,0,0,0,100,0),
(@PATH,23,1673.364,8538.981,-49.88883,0,0,0,0,100,0),
(@PATH,24,1664.266,8535.215,-51.28564,0,0,0,0,100,0);
