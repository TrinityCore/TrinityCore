-- 
DELETE FROM `smart_scripts` WHERE `entryorguid`=18855 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(18855, 0, 0, 0, 0, 0, 100, 0, 500, 500, 3000, 3000, 11, 9053, 64, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, "Sunfury Magister - On Aggro - Cast 'Fireball' (No Repeat)"),
(18855, 0, 1, 0, 0, 0, 100, 0, 8000, 12000, 26000, 31000, 11, 35778, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sunfury Magister - In Combat - Cast 'Bloodcrystal Surge' (Phase 1) (No Repeat)"),
(18855, 0, 2, 0, 2, 0, 100, 513, 0, 15, 0, 0, 25, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, "Sunfury Magister - Between 0-15% Health - FLEE_FOR_ASSIST"),
(18855, 0, 3, 0, 1, 0, 50, 0, 10000, 20000, 15000, 30000, 11, 34397, 0, 0, 0, 0, 0, 19, 19421, 30, 0, 0, 0, 0, 0, "Sunfury Magister - Ooc - Cast Red Beam");
