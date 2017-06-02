-- Frozen Mountaineer
SET @ENTRY := 41763;
UPDATE `creature_template` SET `ScriptName` ='npc_frozen_mountaineer' WHERE `entry`=@ENTRY;
UPDATE `creature_template_addon` SET `auras`='' WHERE `entry`=@ENTRY;
DELETE from `creature_text` WHERE `CreatureID`=@ENTRY;
INSERT INTO `creature_text` (`CreatureID`, `GroupID`, `ID`, `Text`, `Type`, `Language`, `Probability`, `Emote`, `Duration`, `Sound`, `BroadcastTextId`, `comment`) VALUES
(@ENTRY, 0, 0, '%s gasps for air and shivers in the cold.', 16, 0, 100, 20, 0, 0, 41593, 'Frozen Mountaineer');

-- Icy Tomb SAI
SET @ENTRY := 41768;
UPDATE `creature_template` SET `AIName`="SmartAI", `flags_extra`=64 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,1,0,0,0,0,8,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Icy Tomb - On Reset - Set Reactstate Passive"),
(@ENTRY,0,1,0,6,0,100,1,0,0,0,0,45,1,1,0,0,0,0,19,41763,5,0,0,0,0,0,"Icy Tomb - On Death - Set Data 1 1 on target");

-- Water Spout SAI
SET @ENTRY := 41761;
UPDATE `creature_template` SET `AIName`="SmartAI", `InhabitType`=4, `flags_extra`=128 WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,8000,18000,22000,11,77885,0,0,0,0,0,1,0,0,0,0,0,0,0,"Water Spout - OOC - Cast 'Water Stream'");

-- Condition for source Quest show mark condition type Quest rewarded
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=19 AND `SourceGroup`=0 AND `SourceEntry`=25997 AND `SourceId`=0;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES
(19, 0, 25997, 0, 0, 8, 0, 25978, 0, 0, 0, 0, 0, '', 'Show quest mark on questgiver for quest Dark Iron Scheming if quest Entombed in Ice has been rewarded.'),
(19, 0, 25997, 0, 0, 8, 0, 25979, 0, 0, 0, 0, 0, '', 'Show quest mark on questgiver for quest Dark Iron Scheming if quest Dealing with the Surge has been rewarded.');

DELETE FROM `gossip_menu` WHERE `MenuID`=11682;
INSERT INTO `gossip_menu` (`MenuID`, `TextID`) VALUES (11682, 16345);

-- Pathing for Monann Coldforge Entry: 43384
SET @NPC := 307073;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5522.49,`position_y`=-1930.35,`position_z`=398.9774, `orientation`=0.4537856 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,0,0,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5518.66,-1928.455,399.2177,0,0,0,0,100,0),
(@PATH,2,-5510.91,-1926.205,399.2177,0,0,0,0,100,0),
(@PATH,3,-5507.41,-1925.205,399.2177,0,0,0,0,100,0),
(@PATH,4,-5507.41,-1921.955,399.2177,0,0,0,0,100,0),
(@PATH,5,-5511.83,-1921.56,398.958,1.605703,22000,0,476,100,0),
(@PATH,6,-5511.83,-1921.56,398.958,0,25000,0,21,100,0),
(@PATH,7,-5510.515,-1921.225,399.208,0,0,0,0,100,0),
(@PATH,8,-5506.265,-1923.225,399.208,0,0,0,0,100,0),
(@PATH,9,-5508.265,-1927.475,399.208,0,0,0,0,100,0),
(@PATH,10,-5514.2,-1928.89,398.958,0,0,0,0,100,0),
(@PATH,11,-5522.49,-1930.35,398.9774,0.4537856,20000,0,0,100,0);

-- Respawn Helm's Bed Surger
SET @CGUID := 304322;
SET @CGUID1 := 307027;
DELETE FROM `creature` WHERE `id`=41762;
INSERT INTO `creature` (`guid`, `id`, `map`, `zoneId`, `areaId`, `spawnMask`, `phaseId`, `PhaseGroup`, `modelid`, `equipment_id`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `currentwaypoint`, `curhealth`, `curmana`, `MovementType`, `npcflag`, `unit_flags`, `dynamicflags`, `VerifiedBuild`) VALUES
(@CGUID+0, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5669.751, -1862.565, 399.8657, 1.155607, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+7, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5610.573, -1865.416, 399.4626, 5.13934, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+9, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5639.946, -1888.886, 396.4976, 2.107552, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+10, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5615.873, -1914.267, 396.3925, 3.629547, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+11, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5675.296, -1904.372, 396.4886, 2.015625, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+12, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5700.633, -1900.952, 399.0114, 3.867587, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+13, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5681.731, -1947.516, 396.4861, 4.858893, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+16, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5641.102, -1927.602, 396.4861, 5.184005, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+17, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5575.928, -1925.872, 396.4137, 3.133996, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+19, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5707.853, -1956.87, 396.4976, 5.427558, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+21, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5590.827, -1948.583, 396.448, 1.192716, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+22, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5590.45, -1976.762, 396.4347, 2.748698, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+23, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5548.742, -1950.276, 396.4976, 0.5975769, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID+24, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5671.467, -1990.26, 396.3611, 5.660463, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+0, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5667.346, -1992.488, 396.2869, 2.601416, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+3, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5719.235, -1990.257, 396.4976, 4.106979, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+19, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5736.44, -1950.92, 398.4708, 1.258934, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+20, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5680.422, -2042.633, 396.386, 4.651815, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+24, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5769.359, -1974.04, 401.4739, 3.994661, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+25, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5742.633, -2036.312, 396.4976, 1.772768, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+28, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5717.647, -2056.196, 396.4976, 6.015036, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+29, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5672.636, -2074.722, 398.4598, 4.411019, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+30, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5694.443, -2086.331, 400.5424, 3.406474, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+31, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5644.933, -2047.221, 396.4445, 0.5479373, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+35, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5574.728, -2055.29, 396.4728, 2.093844, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+36, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5605.143, -2031.48, 396.277, 1.511136, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+40, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5584.254, -2013.192, 396.4546, 3.848937, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420),
(@CGUID1+41, 41762, 0, 0, 0, 1, 169, 0, 0, 0, -5545.497, -2002.751, 397.9317, 1.948765, 120, 8, 0, 1, 0, 1, 0, 0, 0, 23420);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 304380;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5715.347,`position_y`=-1285.99,`position_z`=390.1207 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,2,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,3,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,4,-5708.399,-1246.309,389.6016,0,0,1,0,100,0),
(@PATH,5,-5708.399,-1246.309,389.6016,0,0,1,0,100,0),
(@PATH,6,-5714.655,-1237.602,388.8025,0,0,1,0,100,0),
(@PATH,7,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,8,-5711.893,-1272.75,390.0777,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306745;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5866.543,`position_y`=-1109.323,`position_z`=381.5317 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5866.543,-1109.323,381.5317,0,0,1,0,100,0),
(@PATH,2,-5891.304,-1104.958,382.0053,0,0,1,0,100,0),
(@PATH,3,-5908.681,-1106.906,386.5114,0,0,1,0,100,0),
(@PATH,4,-5920.019,-1119.859,389.8581,0,0,1,0,100,0),
(@PATH,5,-5913.934,-1137.568,389.9782,0,0,1,0,100,0),
(@PATH,6,-5901.929,-1146.99,385.9181,0,0,1,0,100,0),
(@PATH,7,-5885.643,-1159.148,382.1496,0,0,1,0,100,0),
(@PATH,8,-5873.75,-1168.328,382.6564,0,0,1,0,100,0),
(@PATH,9,-5854.797,-1165.993,381.1606,0,0,1,0,100,0),
(@PATH,10,-5842.077,-1154.569,379.5258,0,0,1,0,100,0),
(@PATH,11,-5826.351,-1141.408,379.4123,0,0,1,0,100,0),
(@PATH,12,-5823.428,-1134.105,380.7233,0,0,1,0,100,0),
(@PATH,13,-5828.453,-1117.734,380.8938,0,0,1,0,100,0),
(@PATH,14,-5854.981,-1111.861,381.6089,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306746;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5795.042,`position_y`=-1081.163,`position_z`=384.5584 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5795.042,-1081.163,384.5584,0,0,1,0,100,0),
(@PATH,2,-5774.736,-1091.226,383.4236,0,0,1,0,100,0),
(@PATH,3,-5758.776,-1098.299,383.0758,0,0,1,0,100,0),
(@PATH,4,-5751.005,-1116.793,382.5779,0,0,1,0,100,0),
(@PATH,5,-5739.58,-1130.722,382.5506,0,0,1,0,100,0),
(@PATH,6,-5723.457,-1136.545,383.5298,0,0,1,0,100,0),
(@PATH,7,-5751.005,-1116.793,382.5779,0,0,1,0,100,0),
(@PATH,8,-5758.776,-1098.299,383.0758,0,0,1,0,100,0),
(@PATH,9,-5774.736,-1091.226,383.4236,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306777;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5742.963,`position_y`=-1249.083,`position_z`=384.6432 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5742.963,-1249.083,384.6432,0,0,1,0,100,0),
(@PATH,2,-5738.983,-1261.979,386.6171,0,0,1,0,100,0),
(@PATH,3,-5738.731,-1276.325,387.5499,0,0,1,0,100,0),
(@PATH,4,-5742.226,-1291.769,387.6749,0,0,1,0,100,0),
(@PATH,5,-5749.693,-1301.891,388.358,0,0,1,0,100,0),
(@PATH,6,-5762.46,-1302.306,387.7689,0,0,1,0,100,0),
(@PATH,7,-5773.908,-1302.446,386.854,0,0,1,0,100,0),
(@PATH,8,-5762.46,-1302.306,387.7689,0,0,1,0,100,0),
(@PATH,9,-5749.693,-1301.891,388.358,0,0,1,0,100,0),
(@PATH,10,-5742.226,-1291.769,387.6749,0,0,1,0,100,0),
(@PATH,11,-5738.731,-1276.325,387.5499,0,0,1,0,100,0),
(@PATH,12,-5738.983,-1261.979,386.6171,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306783;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5766.144,`position_y`=-1162.479,`position_z`=377.5511 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5766.144,-1162.479,377.5511,0,0,1,0,100,0),
(@PATH,2,-5789.021,-1176.429,375.3125,0,0,1,0,100,0),
(@PATH,3,-5801.693,-1188.995,377.2677,0,0,1,0,100,0),
(@PATH,4,-5808.819,-1207.913,377.8904,0,0,1,0,100,0),
(@PATH,5,-5804.083,-1225.991,378.8262,0,0,1,0,100,0),
(@PATH,6,-5785.128,-1229.493,377.0928,0,0,1,0,100,0),
(@PATH,7,-5769.268,-1235.165,377.9831,0,0,1,0,100,0),
(@PATH,8,-5751.658,-1237.061,380.6151,0,0,1,0,100,0),
(@PATH,9,-5739.147,-1231.196,382.9025,0,0,1,0,100,0),
(@PATH,10,-5728.825,-1219.927,385.0128,0,0,1,0,100,0),
(@PATH,11,-5721.422,-1205.715,383.4461,0,0,1,0,100,0),
(@PATH,12,-5718.646,-1187.306,382.0042,0,0,1,0,100,0),
(@PATH,13,-5715.497,-1167.271,382.3172,0,0,1,0,100,0),
(@PATH,14,-5713.429,-1147.677,384.0744,0,0,1,0,100,0),
(@PATH,15,-5720.075,-1136.651,383.9358,0,0,1,0,100,0),
(@PATH,16,-5749.646,-1151.609,379.835,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306798;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5825.663,`position_y`=-1058.991,`position_z`=392.2917 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5825.663,-1058.991,392.2917,0,0,1,0,100,0),
(@PATH,2,-5833.827,-1068.576,389.1699,0,0,1,0,100,0),
(@PATH,3,-5835.689,-1084.356,384.2365,0,0,1,0,100,0),
(@PATH,4,-5832.859,-1097.396,382.294,0,0,1,0,100,0),
(@PATH,5,-5833.827,-1068.576,389.1699,0,0,1,0,100,0),
(@PATH,6,-5825.663,-1058.991,392.2917,0,0,1,0,100,0),
(@PATH,7,-5823.924,-1047.877,393.3915,0,0,1,0,100,0),
(@PATH,8,-5831.094,-1036.976,394.9936,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306803;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5851.602,`position_y`=-1188.856,`position_z`=382.3286 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5851.602,-1188.856,382.3286,0,0,1,0,100,0),
(@PATH,2,-5858.625,-1186.17,383.188,0,0,1,0,100,0),
(@PATH,3,-5864.24,-1178.568,383.1997,0,0,1,0,100,0),
(@PATH,4,-5859.858,-1190.153,383.5593,0,0,1,0,100,0),
(@PATH,5,-5848.592,-1203.2,384.5098,0,0,1,0,100,0),
(@PATH,6,-5837.806,-1210.144,383.5767,0,0,1,0,100,0),
(@PATH,7,-5827.418,-1219.033,381.6001,0,0,1,0,100,0),
(@PATH,8,-5826.543,-1237.811,380.9523,0,0,1,0,100,0),
(@PATH,9,-5826.927,-1252.259,380.9523,0,0,1,0,100,0),
(@PATH,10,-5831.372,-1263.224,383.0304,0,0,1,0,100,0),
(@PATH,11,-5824.005,-1279.222,382.6616,0,0,1,0,100,0),
(@PATH,12,-5831.372,-1263.224,383.0304,0,0,1,0,100,0),
(@PATH,13,-5826.927,-1252.259,380.9523,0,0,1,0,100,0),
(@PATH,14,-5826.543,-1237.811,380.9523,0,0,1,0,100,0),
(@PATH,15,-5827.418,-1219.033,381.6001,0,0,1,0,100,0),
(@PATH,16,-5837.806,-1210.144,383.5767,0,0,1,0,100,0),
(@PATH,17,-5848.592,-1203.2,384.5098,0,0,1,0,100,0),
(@PATH,18,-5859.858,-1190.153,383.5593,0,0,1,0,100,0),
(@PATH,19,-5864.24,-1178.568,383.1997,0,0,1,0,100,0),
(@PATH,20,-5858.625,-1186.17,383.188,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306824;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5847.749,`position_y`=-1380.556,`position_z`=394.8813 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5847.749,-1380.556,394.8813,0,0,1,0,100,0),
(@PATH,2,-5849.337,-1366.879,393.1101,0,0,1,0,100,0),
(@PATH,3,-5847.759,-1351.507,391.5056,0,0,1,0,100,0),
(@PATH,4,-5845.444,-1340.125,389.5625,0,0,1,0,100,0),
(@PATH,5,-5844.009,-1328.102,388.5746,0,0,1,0,100,0),
(@PATH,6,-5847.759,-1351.507,391.5056,0,0,1,0,100,0),
(@PATH,7,-5849.337,-1366.879,393.1101,0,0,1,0,100,0),
(@PATH,8,-5847.749,-1380.556,394.8813,0,0,1,0,100,0),
(@PATH,9,-5850.45,-1393.993,396.3181,0,0,1,0,100,0),
(@PATH,10,-5859.995,-1415.417,401.1159,0,0,1,0,100,0),
(@PATH,11,-5850.45,-1393.993,396.3181,0,0,1,0,100,0);

-- Pathing for Frostmane Raider Entry: 41544
SET @NPC := 306802;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=-5714.655,`position_y`=-1237.602,`position_z`=388.8025 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES (@NPC,@PATH,10002,0,1,0, '77677');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_type`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-5714.655,-1237.602,388.8025,0,0,1,0,100,0),
(@PATH,2,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,3,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,4,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,5,-5715.198,-1301.186,391.1804,0,0,1,0,100,0),
(@PATH,6,-5708.863,-1318.491,392.3066,0,0,1,0,100,0),
(@PATH,7,-5707.151,-1348.247,394.9361,0,0,1,0,100,0),
(@PATH,8,-5708.863,-1318.491,392.3066,0,0,1,0,100,0),
(@PATH,9,-5715.198,-1301.186,391.1804,0,0,1,0,100,0),
(@PATH,10,-5715.347,-1285.99,390.1207,0,0,1,0,100,0),
(@PATH,11,-5711.893,-1272.75,390.0777,0,0,1,0,100,0),
(@PATH,12,-5707.205,-1259.45,390.106,0,0,1,0,100,0),
(@PATH,13,-5708.399,-1246.309,389.6016,0,0,1,0,100,0);
