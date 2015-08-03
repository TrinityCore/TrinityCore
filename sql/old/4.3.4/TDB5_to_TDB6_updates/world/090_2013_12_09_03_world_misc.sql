-- Missing Mechagnome Laborer spawns
SET @GUID := 656;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+1,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+2,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+3,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0),
(@GUID+4,29389,571,1,1,0,1,7850.829,-1393.344,1534.143,5.88176,300,0,0,1,0,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7910.65,`position_y`=-1418.727,`position_z`=1534.705 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7910.65,-1418.727,1534.705,0,0,0,0,100,0),
(@PATH,2,7913.654,-1426.635,1534.705,0,0,0,0,100,0),
(@PATH,3,7920.053,-1414.188,1534.705,0,0,0,0,100,0),
(@PATH,4,7922.347,-1395.791,1534.705,0,0,0,0,100,0),
(@PATH,5,7920.222,-1386.216,1534.705,0,0,0,0,100,0),
(@PATH,6,7923.166,-1385.087,1534.705,0,0,0,0,100,0),
(@PATH,7,7916.864,-1385.485,1534.705,0,0,0,0,100,0),
(@PATH,8,7916.226,-1392.192,1534.705,0,0,0,0,100,0),
(@PATH,9,7911.995,-1404.557,1534.705,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+1;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7868.562,`position_y`=-1363.65,`position_z`=1534.059 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7868.562,-1363.65,1534.059,0,0,0,0,100,0),
(@PATH,2,7879.646,-1351.339,1534.705,0,0,0,0,100,0),
(@PATH,3,7868.222,-1355.34,1534.705,0,0,0,0,100,0),
(@PATH,4,7851.979,-1359.603,1534.705,0,0,0,0,100,0),
(@PATH,5,7840.327,-1375.057,1534.059,0,0,0,0,100,0),
(@PATH,6,7843.573,-1379.135,1534.059,0,0,0,0,100,0),
(@PATH,7,7830.217,-1389.011,1534.366,0,0,0,0,100,0),
(@PATH,8,7825.899,-1405.483,1534.705,0,0,0,0,100,0),
(@PATH,9,7846.697,-1416.326,1534.059,0,0,0,0,100,0),
(@PATH,10,7849.118,-1427.04,1534.059,0,0,0,0,100,0),
(@PATH,11,7848.421,-1411.426,1534.059,0,0,0,0,100,0),
(@PATH,12,7845.131,-1389.869,1534.059,0,0,0,0,100,0),
(@PATH,13,7859.611,-1375.139,1534.059,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+2;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7900.394,`position_y`=-1481.597,`position_z`=1532.27 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7900.394,-1481.597,1532.27,0,0,0,0,100,0),
(@PATH,2,7921.518,-1469.935,1532.267,0,0,0,0,100,0),
(@PATH,3,7939.954,-1444.368,1532.134,0,0,0,0,100,0),
(@PATH,4,7915.613,-1432.221,1535.256,0,0,0,0,100,0),
(@PATH,5,7939.954,-1444.368,1532.134,0,0,0,0,100,0),
(@PATH,6,7921.518,-1469.935,1532.267,0,0,0,0,100,0),
(@PATH,7,7900.394,-1481.597,1532.27,0,0,0,0,100,0),
(@PATH,8,7875.807,-1482.918,1532.255,0,0,0,0,100,0),
(@PATH,9,7872.38,-1464.144,1534.557,0,0,0,0,100,0),
(@PATH,10,7875.807,-1482.918,1532.255,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+3;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7857.495,`position_y`=-1330.407,`position_z`=1534.557 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7857.495,-1330.407,1534.557,0,0,0,0,100,0),
(@PATH,2,7853.63,-1310.692,1532.1,0,0,0,0,100,0),
(@PATH,3,7832.517,-1312.412,1532.386,0,0,0,0,100,0),
(@PATH,4,7814.14,-1322.234,1532.386,0,0,0,0,100,0),
(@PATH,5,7795.604,-1339.547,1532.251,0,0,0,0,100,0),
(@PATH,6,7817.405,-1356.497,1535.256,0,0,0,0,100,0),
(@PATH,7,7804.852,-1402.777,1535.256,0,0,0,0,100,0),
(@PATH,8,7782.151,-1408.093,1532.063,0,0,0,0,100,0),
(@PATH,9,7804.852,-1402.777,1535.256,0,0,0,0,100,0),
(@PATH,10,7817.405,-1356.497,1535.256,0,0,0,0,100,0),
(@PATH,11,7795.604,-1339.547,1532.251,0,0,0,0,100,0),
(@PATH,12,7814.14,-1322.234,1532.386,0,0,0,0,100,0),
(@PATH,13,7832.517,-1312.412,1532.386,0,0,0,0,100,0),
(@PATH,14,7853.63,-1310.692,1532.1,0,0,0,0,100,0);

-- Pathing for Mechagnome Laborer Entry: 29389
SET @NPC := @GUID+4;
SET @PATH := @NPC * 10;
UPDATE `creature` SET `spawndist`=0,`MovementType`=2,`position_x`=7309.224,`position_y`=-666.5821,`position_z`=784.8982 WHERE `guid`=@NPC;
DELETE FROM `creature_addon` WHERE `guid`=@NPC;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@NPC,@PATH,1,0, '');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`orientation`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,7309.224,-666.5821,784.8982,0,0,0,0,100,0),
(@PATH,2,7309.142,-656.5869,784.8982,0,0,0,0,100,0),
(@PATH,3,7309.335,-647.4516,784.8982,0,0,0,0,100,0),
(@PATH,4,7309.67,-640.1229,784.8982,0,0,0,0,100,0),
(@PATH,5,7309.579,-631.7067,785.1652,0,0,0,0,100,0),
(@PATH,6,7309.624,-623.5741,785.4073,0,0,0,0,100,0),
(@PATH,7,7309.579,-631.7067,785.1652,0,0,0,0,100,0),
(@PATH,8,7309.67,-640.1229,784.8982,0,0,0,0,100,0),
(@PATH,9,7309.335,-647.4516,784.8982,0,0,0,0,100,0),
(@PATH,10,7309.142,-656.5869,784.8982,0,0,0,0,100,0),
(@PATH,11,7309.224,-666.5821,784.8982,0,0,0,0,100,0),
(@PATH,12,7309.377,-678.6055,785.1129,0,0,0,0,100,0),
(@PATH,13,7309.483,-688.7038,785.1492,0,0,0,0,100,0),
(@PATH,14,7309.378,-678.7083,785.1492,0,0,0,0,100,0);

DELETE FROM `creature_addon` WHERE `guid` IN (114116,114097,114117,114118,114119,114120,114105,114108,114099,114122,114123,114106,114102,114114,114100,114107,114104,113873);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`emote`) VALUES 
(114116,1,233),(114097,1,233),(114117,1,233),(114118,1,233),
(114119,1,233),(114120,1,233),(114105,1,233),(114108,1,233),
(114099,1,233),(114122,1,233),(114123,1,69),(114106,1,69),
(114102,1,69),(114114,1,69),(114100,1,69),(114107,1,69),
(114104,1,69),(113873,1,69);

DELETE FROM `creature_template_addon` WHERE `entry`=29384;
INSERT INTO `creature_template_addon` (`entry`,`path_id`,`bytes2`,`emote`,`auras`) VALUES (29384,0,1,233, '');

UPDATE `creature` SET `modelid`=0,`spawndist`=0,`MovementType`=0 WHERE `id`=29424;
UPDATE `creature_template` SET `InhabitType`=4, `flags_extra`=`flags_extra`|128 WHERE `entry`=29424;

DELETE FROM `creature_addon` WHERE `guid` IN (113623,113875,114121,114103);
INSERT INTO `creature_addon` (`guid`,`bytes1`,`bytes2`) VALUES 
(113623,8,1),(113875,1,1),(114121,1,1),(114103,1,1);

DELETE FROM `creature_template_addon` WHERE `entry`=29370;
INSERT INTO `creature_template_addon` (`entry`,`bytes2`,`emote`,`auras`) VALUES (29370,1,375, '');

UPDATE `creature` SET `spawndist`=0,`MovementType`=0 WHERE `guid`=113377;
UPDATE `creature_template` SET InhabitType=4 WHERE `entry`=29368;

DELETE FROM `creature_addon` WHERE `guid` IN (100482);
DELETE FROM `creature_template_addon` WHERE `entry`=30001;
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES (30001,3,1, '55701');

-- Condition for spell targets
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceEntry` IN (54464,54430); 
INSERT INTO `conditions` (`SourceTypeOrReferenceId`, `SourceGroup`, `SourceEntry`, `SourceId`, `ElseGroup`, `ConditionTypeOrReference`, `ConditionTarget`, `ConditionValue1`, `ConditionValue2`, `ConditionValue3`, `NegativeCondition`, `ErrorType`, `ErrorTextId`, `ScriptName`, `Comment`) VALUES 
(13, 1, 54464, 0, 0, 31, 0, 3, 29424, 0, 0, 0, 0, '', 'Artificer''s Beam targets Stormforged Lightning Target'),
(13, 1, 54430, 0, 0, 31, 0, 3, 29424, 0, 0, 0, 0, '', 'Stormforged Beam targets Stormforged Lightning Target');
UPDATE `creature` SET `position_x`=8108.245,`position_y`=-291.4,`position_z`=871.0 WHERE `guid`=118561;

-- Stormforged Artificer SAI
SET @ENTRY := -114111;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114098;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114115;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114109;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114110;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114112;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -114101;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := 29376;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion");

-- Stormforged Magus SAI
SET @ENTRY := 29374;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud");

-- Stormforged Magus SAI
SET @ENTRY := -113879;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Stormforged Magus SAI
SET @ENTRY := -113874;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Stormforged Magus SAI
SET @ENTRY := -113876;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Stormforged Magus SAI
SET @ENTRY := -113878;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Stormforged Magus SAI
SET @ENTRY := -113881;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Stormforged Magus SAI
SET @ENTRY := -113880;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,1000,1000,605000,610000,11,12550,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - Out Of Combat - Cast Lightning Shield"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,35000,11,12550,33,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Shield"),
(@ENTRY,0,2,0,0,0,100,0,4000,9000,16000,19000,11,32193,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Magus - In Combat - Cast Lightning Cloud"),
(@ENTRY,0,3,0,1,0,100,0,4000,8000,17000,17000,11,54430,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Magus - OOC - Cast Stormforged Beam");

-- Missing Stormforged Artificer spawns
SET @GUID := 53927;
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+4;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`phaseMask`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,29376,571,1,1,0,1,8050.98633,-296.318359,868.735352,5.253441,300,0,0,1,0,0),
(@GUID+1,29376,571,1,1,0,1,8073.413,-296.032776,901.670532,5.375614,300,0,0,1,0,0);

-- Stormforged Artificer SAI
SET @ENTRY := -53927;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Stormforged Artificer SAI
SET @ENTRY := -53928;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,9,0,100,0,0,40,7000,9000,11,57580,0,0,0,0,0,5,0,0,0,0,0,0,0,"Stormforged Artificer - Between 0-40 Range - Cast Lightning Infusion"),
(@ENTRY,0,1,0,1,0,100,0,4000,4000,14000,14000,11,54464,0,0,0,0,0,1,0,0,0,0,0,0,0,"Stormforged Artificer - OOC - Cast Artificer's Beam");

-- Valduran the Stormborn SAI
SET @ENTRY := 29368;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,0,0,0,0,0,11,56220,0,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Reset - Cast Valduran's Channel"),
(@ENTRY,0,1,0,0,0,100,0,0,0,3400,4800,11,56326,64,0,0,0,0,2,0,0,0,0,0,0,0,"Valduran the Stormborn - Combat - Cast Lightning Bolt (CMC)"),
(@ENTRY,0,2,0,0,0,100,0,15000,18000,29000,33000,11,56322,1,0,0,0,0,1,0,0,0,0,0,0,0,"Valduran the Stormborn - Combat - Cast Spark Frenzy"),
(@ENTRY,0,3,0,0,0,100,0,3000,8000,23000,26000,11,56319,0,0,0,0,0,5,0,0,0,0,0,0,0,"Valduran the Stormborn - Combat - Cast Ball Lightning");

-- Snowdrift Jormungar SAI
SET @ENTRY := 29390;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,1000,3000,5000,7000,11,50293,0,0,0,0,0,5,0,0,0,0,0,0,0,"Snowdrift Jormungar - In Combat - Cast Corrosive Poison");
