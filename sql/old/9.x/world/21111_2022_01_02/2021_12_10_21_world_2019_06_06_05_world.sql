-- Lieutenant Celeyne
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=23964;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23964 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23964,0,0,0,9,0,100,0,8,25,5000,5000,11,27577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Celeyne - In Range - Cast 'Intercept'"),
(23964,0,1,0,0,0,100,0,0,5,9000,14000,11,16856,0,0,0,0,0,2,0,0,0,0,0,0,0,"Lieutenant Celeyne - In Range - Cast 'Mortal Strike'");

-- Dragonflayer Guardian
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=27927;
DELETE FROM `smart_scripts` WHERE `entryorguid`=27927 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27927,0,0,0,0,0,100,0,4000,4000,15000,21000,11,48280,0,0,0,0,0,1,0,0,0,0,0,0,0,"Dragonflayer Guardian - In Combat - Cast 'Whirlwind'");

-- Dragonflayer Hunting Hound
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=23994;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23994 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23994,0,0,0,0,0,100,0,2000,6000,10000,15000,11,48287,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Hunting Hound - In Combat - Cast 'Powerful Bite'");

-- Ember Clutch Ancient
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=23870;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23870 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23870,0,0,0,0,0,100,0,3000,8000,9000,13000,11,12612,0,0,0,0,0,2,0,0,0,0,0,0,0,"Ember Clutch Ancient - In Combat - Cast 'Stomp'"),
(23870,0,1,0,2,0,100,1,0,30,0,0,11,42544,0,0,0,0,0,1,0,0,0,0,0,0,0,"Ember Clutch Ancient - At 30% HP - Cast 'Rejuvenation'");

-- Dragonflayer Handler
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=23871;
DELETE FROM `smart_scripts` WHERE `entryorguid`=23871 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23871,0,0,0,9,0,100,0,0,5,5000,7000,11,15496,0,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Handler - In Range - Cast 'Cleave'"),
(23871,0,1,0,9,0,100,0,0,20,9000,13000,11,6533,1,0,0,0,0,2,0,0,0,0,0,0,0,"Dragonflayer Handler - In Range - Cast 'Net'");
