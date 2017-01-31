-- 
DELETE FROM `creature_formations` WHERE `leaderGUID`=366728;
INSERT INTO `creature_formations` (`leaderGUID`, `memberGUID`, `dist`, `angle`, `groupAI`, `point_1`, `point_2`) VALUES 
(366728, 366728, 0, 0, 2, 0, 0),
(366728, 366739, 0, 0, 2, 0, 0),
(366728, 366727, 0, 0, 2, 0, 0);

DELETE FROM `creature_addon` WHERE `guid` IN (366739, 366727);
INSERT INTO `creature_addon` (`guid`,`path_id`,`mount`,`bytes1`,`bytes2`,`emote`,`auras`) VALUES 
(366739,0,0,0,1,0, ''),
(366727,0,0,0,1,0, '');

-- Magram Warden SAI
SET @ENTRY := 36134;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,4,0,100,1,0,0,0,0,11,8258,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Warden - On Aggro - Cast 'Devotion Aura' (No Repeat)"),
(@ENTRY,0,1,0,11,0,100,1,0,0,0,0,11,7165,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Warden - On Respawn - Cast 'Battle Stance' (No Repeat)"),
(@ENTRY,0,2,0,0,0,100,0,2000,4500,12000,14000,11,25710,0,0,0,0,0,2,0,0,0,0,0,0,0,"Magram Warden - In Combat - Cast 'Heroic Strike'"),
(@ENTRY,0,3,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Magram Warden - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,4,0,6,0,100,0,0,0,0,0,45,1,0,0,0,0,0,11,36137,100,0,0,0,0,0,"Magram Warden - On Just Died - Set Data 1 0");

-- Kolkar Prisoner SAI
SET @ENTRY := 36137;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,2,0,100,1,0,15,0,0,25,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Prisoner - Between 0-15% Health - Flee For Assist (No Repeat)"),
(@ENTRY,0,1,0,38,0,100,0,1,0,0,0,88,@ENTRY*100+00,@ENTRY*100+01,@ENTRY*100+02,0,0,0,1,0,0,0,0,0,0,0,"Kolkar Prisoner - On Data Set 1 0 - Run Random Script");

-- Actionlist SAI
SET @ENTRY := 3613700;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1256.915283,1051.419556,91.691681,2.778741,"On Script - Move To Position"),
(@ENTRY,9,1,0,0,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 3613701;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1276.356445,1026.592651,91.140945,2.778741,"On Script - Move To Position"),
(@ENTRY,9,1,0,0,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");

-- Actionlist SAI
SET @ENTRY := 3613702; 
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,9,0,0,0,0,100,0,0,0,0,0,69,0,0,0,0,0,0,8,0,0,0,-1263.007324,967.299744,90.557411,3.721225,"On Script - Move To Position"),
(@ENTRY,9,1,0,0,0,100,0,12000,12000,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"On Script - Despawn Instant");
