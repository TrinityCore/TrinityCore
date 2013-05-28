-- Summoned Bloodwarder Mender SAI
SET @ENTRY := 20083;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,7,0,0,0,0,11,34815,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender - Just Created - Cast Teleport Effect'),
(@ENTRY,0,1,0,0,0,100,6,5000,5000,185000,185000,11,34809,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender - Combat - Cast Holy Fury'),
(@ENTRY,0,2,0,0,0,100,2,8000,8000,10000,14000,11,17194,0,0,0,0,0,2,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender (Normal) - Combat - Cast Mind Blast'),
(@ENTRY,0,3,0,0,0,100,4,8000,8000,10000,14000,11,17287,0,0,0,0,0,2,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender (Heroic) - Combat - Cast Mind Blast'),
(@ENTRY,0,4,0,2,0,100,7,0,30,0,0,11,35096,0,0,0,0,0,1,0,0,0,0,0,0,0,"Summoned Bloodwarder Mender - At 30% Health - Cast Greater Heal");

-- Summoned Bloodwarder Reservist SAI
SET @ENTRY := 20078;
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,63,0,100,7,0,0,0,0,11,34815,0,0,0,0,0,1,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender - Just Created - Cast Teleport Effect'),
(@ENTRY,0,1,0,0,0,100,6,4000,8000,10000,12000,11,34820,0,0,0,0,0,2,0,0,0,0,0,0,0,'Summoned Bloodwarder Mender - Combat - Cast Arcane Strike');
