-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=18213 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18213, 0, 0, 0, 0, 0, 100, 0, 1000, 2000, 3400, 5800, 11, 39419, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, "Mire Hydra - IC - Cast 'Poison Spit'");
