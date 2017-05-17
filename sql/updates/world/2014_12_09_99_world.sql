-- Apprentice Ralen SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=15941 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15941,0,0,1,8,0,100,0,27907,0,15000,15000,33,15941,0,0,0,0,0,7,0,0,0,0,0,0,0,"Apprentice Ralen - On Spellhit 'Disciplinary Rod' - Quest Credit 'Swift Discipline'"),
(15941,0,1,0,61,0,100,0,27907,0,15000,15000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apprentice Ralen - On Spellhit 'Disciplinary Rod' - Say Line 0");

-- Apprentice Meledor SAI
DELETE FROM `smart_scripts` WHERE `entryorguid`=15945 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15945,0,0,1,8,0,100,0,27907,0,15000,15000,33,15945,0,0,0,0,0,7,0,0,0,0,0,0,0,"Apprentice Meledor - On Spellhit 'Disciplinary Rod' - Quest Credit 'Swift Discipline'"),
(15945,0,1,0,61,0,100,0,27907,0,15000,15000,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Apprentice Meledor - On Spellhit 'Disciplinary Rod' - Say Line 0");
