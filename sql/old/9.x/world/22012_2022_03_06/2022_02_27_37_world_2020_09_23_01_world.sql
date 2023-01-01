--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 36478 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(36478,0,0,0,0,0,100,0,10000,15000,16000,20000,0,11,69056,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soulguard Watchman - In Combat - Cast 'Shroud of Runes'"),
(36478,0,1,2,2,0,100,1,0,50,0,0,0,11,69053,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soulguard Watchman - Between 0-50% Health - Cast 'Unholy Rage' (No Repeat)"),
(36478,0,2,0,61,0,100,0,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Soulguard Watchman - On Link - Say Line 0"),
-- Probably someone tried to make mobs in packs aggro together or?
(36478,0,3,0,4,0,100,0,0,0,0,0,0,39,20,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Soulguard Watchman - On Aggro - Call For Help");
