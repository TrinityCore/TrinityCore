-- Apparition of Fear
SET @ENTRY := 64368;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,12000,15000,11,125758,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Overwhelming Fear'),
(@ENTRY,0,1,0,2,0,100,0,0,40,22000,25000,11,125736,2,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Night Terrors at 40% HP');

-- Apparition of Terror
SET @ENTRY := 66100;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,0,5000,8000,18000,22000,11,130115,0,0,0,0,0,4,0,0,0,0,0,0,0,'Cast Grip of Fear'),
(@ENTRY,0,1,0,9,0,100,0,0,25,15000,25000,11,130120,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Unleashed Terror on Close');