UPDATE `creature` SET `id`=61829, `MovementType`=1, `spawndist`=8 WHERE `id`=20725 AND `guid` BETWEEN 324851 AND 326752;
UPDATE `creature` SET `MovementType`=1, `spawndist`=8 WHERE `id`=61829;
UPDATE `creature_template` SET `InhabitType`=4 WHERE `entry` IN (61829, 50803, 50328, 1512);

SET @GUID  := 450000; -- 15 guid set by TC, gap for the rest of cata
DELETE FROM `creature` WHERE `guid` BETWEEN @GUID AND @GUID+15;
INSERT INTO `creature` (`guid`,`id`,`map`,`spawnMask`,`PhaseId`,`modelid`,`equipment_id`,`position_x`,`position_y`,`position_z`,`orientation`,`spawntimesecs`,`spawndist`,`currentwaypoint`,`curhealth`,`curmana`,`MovementType`) VALUES
(@GUID,63073,0,1,0,0,0,2200.868,279.685,38.976,5.99,180,0,0,375,0,0),
(@GUID+1,63069,0,1,0,0,0,2201.343,280.46,39.135,5.637,180,0,0,1,0,0),
(@GUID+2,50803,0,1,0,0,0,2445.499,1629.186,82.413,5.103,900,10,0,150,0,1),
(@GUID+3,73641,0,1,0,0,0,2252.514,298.59,33.69,5.343,180,0,0,110,0,0),
(@GUID+4,50328,0,1,0,0,0,1681.276,1456.449,136.872,0.09,900,10,0,113,0,1),
(@GUID+5,50930,0,1,0,0,0,1717.267,893.31,59.59,1.05,900,0,0,150,0,0),
(@GUID+6,50908,0,1,0,0,0,2973.443, 1112.685, 81.724, 5.274,900,0,0,180,0,0),
(@GUID+7,51044,0,1,0,0,0,2835.541,410.229,20.932,1.429,900,0,0,165,0,0),
(@GUID+8,61366,0,1,0,0,0,1824.718,268.085,60.235,0.13,180,10,0,8,0,1),
(@GUID+9,61366,0,1,0,0,0,2375.152,-1062.04,86.317,4.273,180,10,0,8,0,1),
(@GUID+10,61366,0,1,0,0,0,2813.115,391.26,19.884,2.117,180,10,0,8,0,1),
(@GUID+11,50763,0,1,0,0,0,2259.751,1317.584,33.858,0.055,900,0,0,135,0,0),
(@GUID+12,73640,0,1,0,0,0,2238.142,299.285,33.574,5.211,180,0,0,110,0,0),
(@GUID+13,63272,0,1,0,0,0,1857.135,1568.35,94.313,0.002,180,0,0,11494,0,0),
(@GUID+14,73644,0,1,0,0,0,2241.31,293.803,33.573,5.105,180,0,0,75,0,0);

DELETE FROM `creature_template_addon` WHERE `entry` IN (51044, 50908, 50930);
INSERT INTO `creature_template_addon` (`entry`,`bytes1`,`bytes2`,`auras`) VALUES
(51044,0,1,'133131'),
(50908,1,1,''),
(50930,0,1,'78677');

-- Shadowstalker SAI
SET @ENTRY := 50763;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,7000,9000,11,745,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowstalker - In Combat - Cast 'Web'"),
(@ENTRY,0,1,0,0,0,100,0,1000,5000,15000,17000,11,744,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shadowstalker - In Combat - Cast 'Poison'");

-- Bonechewer SAI
SET @ENTRY := 50803;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,18000,20000,11,3427,0,0,0,0,0,2,0,0,0,0,0,0,0,"Bonechewer - In Combat - Cast 'Infected Wound'");

-- Fangor SAI
SET @ENTRY := 50328;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,6000,9000,11,8281,0,0,0,0,0,2,0,0,0,0,0,0,0,"Fangor - In Combat - Cast 'Sonic Burst'");

-- Hibernus the Sleeper SAI
SET @ENTRY := 50930;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,5000,8000,11,5422,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hibernus the Sleeper - In Combat - Cast 'Lacerate'"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,87187,0,0,0,0,0,2,0,0,0,0,0,0,0,"Hibernus the Sleeper - In Aggro - Cast 'Feral Charge'");

-- Nighthowl SAI
SET @ENTRY := 50908;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,14000,16000,11,5781,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nighthowl - In Combat - Cast 'Threatening Growl'"),
(@ENTRY,0,1,0,4,0,100,0,0,0,0,0,11,75002,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nighthowl - In Aggro - Cast 'Leaping Rush'");

-- Plague SAI
SET @ENTRY := 51044;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,2000,4000,14000,16000,11,3149,0,0,0,0,0,1,0,0,0,0,0,0,0,"Plague - In Combat - Cast 'Furious Howl'"),
(@ENTRY,0,1,0,0,0,100,0,3000,5000,15000,18000,11,13443,0,0,0,0,0,2,0,0,0,0,0,0,0,"Plague - In Combat - Cast 'Rend'");
