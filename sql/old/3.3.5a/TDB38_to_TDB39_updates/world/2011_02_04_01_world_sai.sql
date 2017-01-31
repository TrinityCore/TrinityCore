-- Ferlynn Windsong "Valiance Keep" SAI (tested)
UPDATE `creature_template` SET `AIName`= 'SmartAI' WHERE `entry`=25282;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (25282);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25282,0,0,0,1,0,100,0,6000,6000,6000,6000,11,42611,2,0,0,0,0,10,103994,24921,0,0,0,0,0,'Fire at target every 6 sec');
