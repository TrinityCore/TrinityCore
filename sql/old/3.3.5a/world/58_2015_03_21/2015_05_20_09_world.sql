--
SET @ENTRY := 18636;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Reset'),
(@ENTRY,0,1,0,9,0,100,6,0,8,0,0,11,30986,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cheap Shot on Close'),
(@ENTRY,0,2,0,67,0,100,6,9000,12000,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,3,0,0,0,100,6,2000,4500,12000,20000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison'),
(@ENTRY,0,4,0,0,0,100,6,8000,11000,22000,25000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

SET @ENTRY := 17695;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,25,0,100,6,0,0,0,0,11,30991,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Stealth on Reset'),
(@ENTRY,0,1,0,9,0,100,6,0,8,0,0,11,30986,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Cheap Shot on Close'),
(@ENTRY,0,2,0,67,0,100,6,9000,12000,0,0,11,30992,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Backstab'),
(@ENTRY,0,3,0,0,0,100,6,2000,4500,12000,20000,11,30981,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Crippling Poison'),
(@ENTRY,0,4,0,0,0,100,6,8000,11000,22000,25000,11,36974,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Wound Poison');

-- Void Traveler
SET @ENTRY := 19226;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `source_type`=0 AND `entryorguid`=@ENTRY;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,0,0,100,2,2000,4500,12000,20000,11,33783,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,1,0,0,0,100,4,2000,4500,12000,20000,11,39364,0,0,0,0,0,2,0,0,0,0,0,0,0,'Cast Empowering Shadows'),
(@ENTRY,0,2,0,0,0,100,6,5000,9000,18000,25000,11,33846,0,0,0,0,0,1,0,0,0,0,0,0,0,'Cast Shadow Nova');
