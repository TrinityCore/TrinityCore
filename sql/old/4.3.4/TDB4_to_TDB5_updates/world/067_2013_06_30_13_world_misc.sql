-- Opus already has SAI and text added
UPDATE `creature` SET `MovementType`=0 WHERE `guid`=4567;
DELETE FROM `creature_addon` WHERE `guid`=4567;
UPDATE `waypoint_data` SET `action`=0 WHERE `action` BETWEEN 5 AND 13;
DELETE FROM `waypoint_data` WHERE `id`=45670;
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000005001 AND 2000005009;
DELETE FROM `waypoint_scripts` WHERE `dataint` BETWEEN 2000005001 AND 2000005009;
DELETE FROM `db_script_string` WHERE `entry` BETWEEN 2000000107 AND 2000000109;

-- Add SAI support for Warp-Huntress Kula
SET @KULA := 32711;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@KULA;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@KULA; - 4.x
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@KULA;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@KULA,0,0,0,11,0,100,0,0,0,0,0,11,61616,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Warp-Huntress Kula -  On Spawn - Summon Backbiter');

-- Add SAI support for Thal'trak Proudtusk
SET @THALTRAK := 9082;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@THALTRAK;
-- DELETE FROM `creature_ai_scripts` WHERE `creature_id`=@THALTRAK; - 4.x
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@THALTRAK;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@THALTRAK,0,0,0,9,0,100,0,9,10,180000,180000,1,0,0,0,0,0,0,11,9079,10,0,0,0,0,0, 'Thal''trak Proudtusk -  Range - Say 0');

-- Text for Thal'trak Proudtusk
DELETE FROM `creature_text` WHERE `entry` IN (@THALTRAK);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@THALTRAK,0,0,'Well done, soldiers! At ease!',12,0,100,0,0,0,'Thal''trak Proudtusk');
