-- Wazat SAI
SET @ENTRY := 19035;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,1,0,100,0,20000,40000,60000,80000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wazat - OOC - Say Text 0"),
(@ENTRY,0,1,0,1,0,100,0,60000,80000,80000,110000,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wazat - OOC - Say Text 1"),
(@ENTRY,0,2,0,1,0,100,0,110000,130000,150000,170000,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wazat - OOC - Say Text 2");
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Oh sweet, delicious, spotted eggs - you will be mine...",12,0,100,0,0,0,"Wazat"),
(@ENTRY,1,1,"If only I could get this blasted machine working!",12,0,100,0,0,0,"Wazat"),
(@ENTRY,2,2,"They look so delicious...",12,0,100,0,0,0,"Wazat");

-- Wazat pathing: 11365
SET @GUID := 68343;
SET @PATH := @GUID * 10;
UPDATE `creature` SET `MovementType`=2,`position_x`=-2428.169922,`position_y`=6885.750000,`position_z`=4.196100 WHERE `guid`=@GUID;
DELETE FROM `creature_addon` WHERE `guid`=@GUID;
INSERT INTO `creature_addon` (`guid`,`path_id`,`bytes2`,`mount`,`auras`) VALUES (@GUID,@PATH,1,0,'');
DELETE FROM `waypoint_data` WHERE `id`=@PATH;
INSERT INTO `waypoint_data` (`id`,`point`,`position_x`,`position_y`,`position_z`,`delay`,`move_flag`,`action`,`action_chance`,`wpguid`) VALUES
(@PATH,1,-2428.704590,6890.355469,4.297834,20000,0,0,100,0),
(@PATH,2,-2434.878418,6889.507813,4.266439,20000,0,0,100,0),
(@PATH,3,-2428.169922,6885.750000,4.196100,20000,0,0,100,0);

-- Windroc Matriarch SAI
SET @ENTRY := 19055;
SET @SPELL_EAGLE_CLAW := 30285; -- Eagle Claw
SET @SPELL_WING_BUFFET := 32914; -- Wing Buffet
UPDATE `creature_template` SET `AIName`='SmartAI',`InhabitType`=4,`spell1`=0 WHERE `entry`=@ENTRY; -- Always in air, of course - really? Albino Snake as mind control ability?
DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (@ENTRY,@ENTRY*100);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,53,0,@ENTRY,1,0,0,0,1,0,0,0,0,0,0,0, 'Windroc Matriarch - Start WP movement'),
(@ENTRY,0,1,0,1,0,100,1,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windroc Matriarch - On Spawn - Emote Text 0"),
(@ENTRY,0,2,0,40,0,100,0,3,@ENTRY,0,0,80,@ENTRY*100,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windroc Matriarch - Load script 1 at WP 3"),
(@ENTRY,0,3,0,0,0,100,0,4000,4000,6000,6000,11,@SPELL_EAGLE_CLAW,0,0,0,0,0,2,0,0,0,0,0,0,0,"Windroc Matriarch - In Combat - Cast Eagle Claw"),
(@ENTRY,0,4,0,0,0,100,0,7000,8000,11000,14000,11,@SPELL_WING_BUFFET,0,0,0,0,0,2,0,0,0,0,0,0,0,"Windroc Matriarch - In Combat - Cast Wing Buffet"),
-- Script 1
(@ENTRY*100,9,0,0,0,0,100,0,0,0,0,0,54,1000000000,0,0,0,0,0,1,0,0,0,0,0,0,0,'Windroc Matriarch - Script - Pause Path'),
(@ENTRY*100,9,1,0,0,0,100,1,0,0,0,0,2,14,0,0,0,0,0,1,0,0,0,0,0,0,0,"Windroc Matriarch - On Script - Set Faction Aggressive"),
(@ENTRY*100,9,2,0,0,0,100,0,0,0,0,0,19,256,0,0,0,0,0,1,0,0,0,0,0,0,0,'Windroc Matriarch - Script - Remove unit_flag OOC_NOT_ATTACKABLE'),
(@ENTRY*100,9,3,0,0,0,100,0,0,0,0,0,20,1,0,0,0,0,0,21,0,0,0,0,0,0,0,'Windroc Matriarch - Script - Attack Nearest Player');
-- Texts
DELETE FROM `creature_text` WHERE `entry`=@ENTRY;
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@ENTRY,0,0,"Emote blabla",16,0,100,0,0,0,"Windroc Matriarch");
-- Waypoints
DELETE FROM `waypoints` WHERE `entry`=@ENTRY;
INSERT INTO `waypoints` (`entry`,`pointid`,`position_x`,`position_y`,`position_z`,`point_comment`) VALUES
(@ENTRY,1,-2422.512695,6910.643555,20.124718,'Windroc Matriarch WP 1'),
(@ENTRY,2,-2420.722168,6901.208008,15.225160,'Windroc Matriarch WP 2'),
(@ENTRY,3,-2400.643066,6887.521973,-1.384245,'Windroc Matriarch WP 3');
