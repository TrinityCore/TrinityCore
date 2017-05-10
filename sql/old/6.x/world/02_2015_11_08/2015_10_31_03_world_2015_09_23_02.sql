-- 
SET @GUID1 := -78496;
SET @GUID2 := -52330;
UPDATE `creature` SET `position_x`= -4236.136230, `position_y`= 313.865417, `position_z`= 160.389038, `orientation`= 3.5595 WHERE `guid`= 78496;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry` IN (22317, 23188, 22253);
UPDATE `creature_template` SET `InhabitType`= 4 WHERE `entry`=23225;
DELETE FROM `creature` WHERE `guid` IN (132815, 132816, 132817) AND `id`=23188; -- remove wrong spawns
UPDATE `smart_scripts` SET `event_type`=25 WHERE `entryorguid`=23311 AND `source_type`=0 AND `id`=11; -- Fix an aura set by spawn instead of reset
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@GUID1, -52330, 23188, 22253) AND `source_type`=0;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (22317*100, 22317*100+1, 22317*100+2, 2318800, 2318801, 2318802, 2318803, 22253*100) AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@GUID1,0,0,0,1,0,100,0,2000,4000,12000,16000,12,23188,7,0,0,0,0,8,0,0,0,-4236.136230, 313.865417, 160.389038, 3.9795,"Netherwing Drake Escape Dummy - OOC - Summon Creature 'Dragonmaw Transporter'"),
(@GUID1,0,1,0,63,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Netherwing Drake Escape Dummy - Just created - Set active"),
(23188,0,0,0,54,0,100,0,0,0,0,0,87,2318800,2318801,2318802,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Just summoned  - action list"),
(2318800,9,0,0,0,0,100,0,0,0,0,0,53,1,231880,0,0,0,2,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Start Waypoint"),
(2318800,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Set Active On"),
(2318801,9,0,0,0,0,100,0,0,0,0,0,53,1,231881,0,0,0,2,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Start Waypoint"),
(2318801,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Set Active On"),
(2318802,9,0,0,0,0,100,0,0,0,0,0,53,1,231882,0,0,0,2,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Start Waypoint"),
(2318802,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Action list - Set Active On"),
(23188,0,1,0,58,0,100,0,27,231880,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - On Waypoint Finished - Despawn Instant"),
(23188,0,2,0,58,0,100,0,31,231881,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - On Waypoint Finished - Despawn Instant"),
(23188,0,3,0,58,0,100,0,25,231882,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - On Waypoint Finished - Despawn Instant"),
(23188,0,4,0,58,0,100,0,26,231883,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - On Waypoint Finished - Despawn Instant"),
(22253, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 7000, 7000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Cleave"),
(22253, 0, 1, 0, 0, 0, 100, 0, 5000, 7000, 8000, 10000, 11, 17547, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Mortal Strike"),
(22253, 0, 2, 0, 0, 0, 100, 0, 4000, 7000, 9000, 12000, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Uppercut"),
(@GUID2, 0, 0, 0, 0, 0, 100, 0, 3000, 5000, 7000, 7000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Cleave"),
(@GUID2, 0, 1, 0, 0, 0, 100, 0, 5000, 7000, 8000, 10000, 11, 17547, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Mortal Strike"),
(@GUID2, 0, 2, 0, 0, 0, 100, 0, 4000, 7000, 9000, 12000, 11, 10966, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Ascendant - IC - Cast Uppercut"),
(@GUID2,0,3,0,1,0,100,0,2000,5000,12000,16000,12,23188,7,0,0,0,0,8,0,0,0,-4933.316895, 31.134706, 61.772137, 0.480736,"Dragonmaw Ascendant - OOC - Summon Creature 'Dragonmaw Transporter'"),
(@GUID2,0,4,0,63,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Ascendant - Just created - Set active"),
(23188,0,5,0,54,0,100,0,0,0,0,0,80,2318803,2,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - Just summoned - action list"),
(2318803,9,0,0,0,0,100,0,0,0,0,0,53,1,231883,0,0,0,2,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - action list - Start Waypoint"),
(2318803,9,1,0,0,0,100,0,0,0,0,0,48,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonmaw Transporter - action list - Set Active On"),
(23188, 0, 6, 0, 0, 0, 100, 0, 3000, 5000, 7000, 7000, 11, 38861, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Transporter- IC - Aimed Shot"),
(23188, 0, 7, 0, 0, 0, 100, 0, 5000, 7000, 8000, 10000, 11, 19503, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Transporter - IC - Scatter Shot"),
(23188, 0, 8, 0, 0, 0, 100, 0, 4000, 7000, 9000, 12000, 11, 38859, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Transporter - IC - Serpent Sting"),
(23188, 0, 9, 0, 0, 0, 100, 0, 1000, 2000, 3000, 4000, 11, 38858, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Dragonmaw Transporter - IC - Shoot");

DELETE FROM conditions WHERE SourceTypeOrReferenceId=22 AND SourceEntry=23188;
INSERT INTO conditions (SourceTypeOrReferenceId, SourceGroup, SourceEntry, SourceId, ElseGroup, ConditionTypeOrReference, ConditionTarget, ConditionValue1, ConditionValue2, ConditionValue3, NegativeCondition, ErrorTextId, ScriptName, Comment) VALUES
(22, 1, 23188, 0, 0, 23, 0, 3939, 0, 0, 0, 0, '', 'Execute SmartAI for Dragonmaw Transporter if the area is 3759'),
(22, 6, 23188, 0, 0, 23, 0, 3759, 0, 0, 0, 0, '', 'Execute SmartAI for Dragonmaw Transporter if the area is 3759');

SET @PATH := 231880;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH,1,-4234.259,316.7951,194.5695, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,2,-4278.778,291.9364,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,3,-4315.755,272.5735,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,4,-4332.82,267.5372,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,5,-4354.233,260.8795,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,6,-4391.55,249.5022,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,7,-4429.059,238.4517,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,8,-4470.008,227.2337,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,9,-4489.761,222.9549,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,10,-4502.434,220.6088,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,11,-4528.817,218.5281,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,12,-4546.15,218.6741,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,13,-4595.704,217.5207,162.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,14,-4641.978,205.2794,147.0265, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,15,-4662.014,198.3955,118.6931, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,16,-4686.042,195.7724,92.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,17,-4720.744,183.9892,92.33202, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,18,-4745.649,173.8856,98.19311, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,19,-4756.257,154.736,105.7487, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,20,-4761.057,143.5172,108.3876, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,21,-4787.247,129.8356,110.6098, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,22,-4815.383,124.4918,109.6376, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,23,-4841.104,99.13585,116.1653, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,24,-4876.217,68.20888,99.16536, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,25,-4887.112,56.80024,92.74867, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,26,-4921.727,36.11827,73.94312, 'Dragonmaw Transporter'), -- 07:14:59
(@PATH,27,-4924.737,36.20354,61.87088, 'Dragonmaw Transporter'); -- 07:14:59
-- 0x1C09FC424016A500000019000022323C .go -4234.259 316.7951 194.5695
 
-- Pathing for Dragonmaw Transporter Entry: 23188 'TDB FORMAT'
SET @PATH := 231881;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH,1,-4235.772,310.6806,195.9172, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,2,-4266.868,305.2986,170.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,3,-4289.381,299.2866,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,4,-4313.463,296.8451,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,5,-4334.991,295.7913,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,6,-4355.52,290.1741,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,7,-4382.983,278.409,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,8,-4419.237,271.8036,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,9,-4448.44,268.7892,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,10,-4463.974,265.9718,169.0554, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,11,-4486.522,265.1359,165.4998, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,12,-4515.319,266.4659,154.3332, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,13,-4538.145,266.9955,143.7777, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,14,-4565.51,267.0066,134.7498, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,15,-4574.724,266.6996,130.4999, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,16,-4585.344,265.8585,125.2221, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,17,-4610.452,266.8059,114.0276, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,18,-4648.119,265.0245,89.41651, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,19,-4679.999,264.3499,80.02769, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,20,-4726.6,265.6508,91.11095, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,21,-4757.61,263.9644,96.61092, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,22,-4790.494,252.6213,107.7221, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,23,-4830.46,243.5237,113.6109, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,24,-4850.946,232.3608,114.611, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,25,-4865.539,204.393,115.9165, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,26,-4867.515,184.822,112.5276, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,27,-4869.98,147.345,96.99986, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,28,-4875.779,115.5371,89.69432, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,29,-4900.512,79.47276,79.22215, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,30,-4920.873,41.16504,69.30544, 'Dragonmaw Transporter'), -- 07:15:20
(@PATH,31,-4924.737,36.20354,61.87088, 'Dragonmaw Transporter'); -- 07:15:20
-- 0x1C09FC424016A5000000190000223259 .go -4235.772 310.6806 195.9172
 
-- Pathing for Dragonmaw Transporter Entry: 23188 'TDB FORMAT'
SET @PATH := 231882;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH,1,-4235.186,312.622,195.6112, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,2,-4234.272,312.2153,195.6112, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,3,-4293.566,245.1756,179.3634, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,4,-4305.508,238.4082,179.3634, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,5,-4329.843,217.8027,179.3634, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,6,-4362.729,186.0796,186.419, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,7,-4434.846,123.756,230.3912, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,8,-4459.073,85.18902,233.9189, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,9,-4482.534,56.35666,232.5023, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,10,-4493.029,34.64518,235.1689, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,11,-4503.293,2.772352,232.5856, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,12,-4536.873,-16.30306,224.7523, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,13,-4579.444,-18.38878,223.5301, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,14,-4611.417,9.642578,219.03, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,15,-4660.565,11.25814,228.7522, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,16,-4698.878,14.15853,227.3911, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,17,-4734.97,25.07422,223.0023, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,18,-4766.538,46.62153,220.8356, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,19,-4794.966,67.12045,197.8634, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,20,-4815.075,72.55089,183.6967, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,21,-4855.917,67.18316,133.6689, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,22,-4868.51,61.47526,116.2801, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,23,-4890.089,51.30317,92.11338, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,24,-4922.806,35.50499,72.91895, 'Dragonmaw Transporter'), -- 07:18:37
(@PATH,25,-4924.737,36.20354,61.87088, 'Dragonmaw Transporter'); -- 07:18:37
-- 0x1C09FC424016A50000001900002232FF .go -4235.186 312.622 195.6112
 
-- Pathing for Dragonmaw Transporter Entry: 23188 'TDB FORMAT'
SET @PATH := 231883;
DELETE FROM `waypoints` WHERE `entry`=@PATH;
INSERT INTO `waypoints` (`entry`, `pointid`, `position_x`, `position_y`, `position_z`, `point_comment`) VALUES
(@PATH,1,-4921.116,38.40239,62.79848, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,2,-4920.266,38.92785,62.79848, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,3,-4911.522,44.50662,65.54009, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,4,-4897.991,49.12988,69.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,5,-4854.699,71.66743,69.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,6,-4811.554,91.95888,69.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,7,-4782.642,107.2382,69.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,8,-4749.689,123.6898,102.4568, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,9,-4717.377,120.1987,102.5401, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,10,-4677.343,111.8249,122.37344, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,11,-4642.299,106.9923,122.62343, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,12,-4595.685,101.0696,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,13,-4568.682,107.7912,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,14,-4532.451,105.1658,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,15,-4502.495,109.315,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,16,-4478.215,118.6488,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,17,-4437.049,132.6271,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,18,-4401.484,131.5858,122.23454, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,19,-4360.693,156.9551,122.37343, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,20,-4324.191,184.9894,122.9568, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,21,-4299.081,216.2382,141.7901, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,22,-4292.715,227.4521,179.9077, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,23,-4281.613,263.6761,179.9077, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,24,-4260.6,294.3777,179.9077, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,25,-4240.507,326.8979,154.0465, 'Dragonmaw Transporter'), -- 07:15:14
(@PATH,26,-4240.507,326.8979,154.0465, 'Dragonmaw Transporter'); -- 07:15:14
-- 0x1C09FC424016A5000000190000223269 .go -4921.116 38.40239 62.79848
