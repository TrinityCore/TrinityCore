-- Add SAI support for Curator Thorius
SET @THORIUS := 8256;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@THORIUS;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@THORIUS;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@THORIUS,0,0,0,1,0,100,0,120000,120000,120000,120000,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0, 'Curator Thorius - OOC - Say 0');

-- Text for Curator Thorius
DELETE FROM `creature_text` WHERE `entry` IN (@THORIUS);
INSERT INTO `creature_text` (`entry`,`groupid`,`id`,`text`,`type`,`language`,`probability`,`emote`,`duration`,`sound`,`comment`) VALUES
(@THORIUS,0,0,'Poor Dorius. If I ever get my hands on those Dark Irons, so help me...',12,0,100,0,0,0,'Curator Thorius');

UPDATE `waypoint_data` SET `action`=0 WHERE `action`=2;
DELETE FROM `db_script_string` WHERE `entry`=2000005000;
DELETE FROM `waypoint_scripts` WHERE `dataint`=2000005000;
