UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (23801,24746,29594);

DELETE FROM `smart_scripts` WHERE `entryorguid` IN (23801,24746,29594);
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23801,0,0,0,6,0,100,1,0,0,0,0,85,25281,2,0,0,0,0,7,0,0,0,0,0,0,0,'Turkey - Cast Marker on death'),
(24746,0,0,0,6,0,100,1,0,0,0,0,85,25281,2,0,0,0,0,7,0,0,0,0,0,0,0,'Fjord Turkey - Cast Marker on death'),
(29594,0,0,0,6,0,100,1,0,0,0,0,85,25281,2,0,0,0,0,7,0,0,0,0,0,0,0,'Angry Turkey - Cast Marker on death');
