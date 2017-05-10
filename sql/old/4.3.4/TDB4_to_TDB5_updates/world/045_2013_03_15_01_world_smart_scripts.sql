DELETE FROM `smart_scripts` WHERE `entryorguid`=30407 AND `source_type`=0;
INSERT INTO `smart_scripts`(`entryorguid`,`id`,`link`,`event_type`,`event_flags`,`event_phase_mask`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`target_type`,`comment`) VALUES
(30407,0,1,11,0,0,0,0,0,0,11,56726,0,1,'Captured Crusader - On Respawn - Apply Nerubian Webs (56726)'),
(30407,1,0,61,0,0,0,0,0,0,22,1,0,1,'Captured Crusader - Linked to id 0 - Set event phase to 1'),
(30407,2,0, 1,0,1,4000,4000,4000,4000,10,70,22,1,'Captured Crusader - Out of combat - Random emote'),
(30407,3,4, 8,0,1,56683,0,0,0,11,56687,0,7,'Captured Crusader - Spell hit of Grab Captured Crusader (56683) - Cast Ride Vehicle (56687)'),
(30407,4,5,61,0,1,0,0,0,0,1,0,0,1,'Captured Crusader - Linked to id 3 - Talk'),
(30407,5,0,61,0,1,0,0,0,0,22,2,0,1,'Captured Crusader - Linked to id 3 - Set event phase to 2'),
(30407,6,0, 1,0,2,8000,8000,8000,8000,1,1,0,1,'Captured Crusader - Out of combat - Talk'),
(30407,7,8,23,1,2,56687,0,0,0,1,2,0,1,'Captured Crusader - Aura Ride Vehicle (56687) removed - Talk'),
(30407,8,9,61,0,2,0,0,0,0,41,5000,0,1,'Captured Crusader - Linked to id 7 - Despawn'),
(30407,9,0,61,0,2,0,0,0,0,22,0,0,1,'Captured Crusader - Linked to id 7 - Set event phase to 0');
