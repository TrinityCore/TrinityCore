--
DELETE FROM `smart_scripts` WHERE `entryorguid` = 4968 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 496800 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(4968,0,0,0,4,0,100,0,0,0,0,0,0,4,5882,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Aggro - Play Sound 5882"),
(4968,0,1,0,0,0,100,0,0,0,2000,3500,0,11,20692,64,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Fireball'"),
(4968,0,2,0,0,0,100,0,4000,5000,45000,55000,0,11,20681,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Summon Water Elementals'"),
(4968,0,3,0,0,0,100,0,5000,9000,15000,17000,0,11,20679,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Fire Blast'"),
(4968,0,4,0,0,0,100,0,8000,12000,25000,28000,0,11,20680,0,0,0,0,0,4,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - In Combat - Cast 'Blizzard'"),
(4968,0,5,0,2,0,100,0,0,50,14000,21000,0,11,20682,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - Between 0-50% Health - Cast 'Teleport'"),

(4968,0,6,0,20,0,100,0,11142,0,0,0,0,80,496800,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Quest 'Survey Alcaz Island' Finished - Run Script"),

(4968,0,7,8,62,0,100,0,2465,0,0,0,0,11,23122,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Gossip Option 0 Selected - Cast 'Jaina's Autograph'"),
(4968,0,8,0,61,0,100,0,0,0,0,0,0,72,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Gossip Option 0 Selected - Close Gossip"),

(496800,9,0,0,0,0,100,0,0,0,0,0,0,66,0,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Set Orientation Invoker"),
(496800,9,1,0,0,0,100,0,0,0,0,0,0,83,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Remove Npc Flag Questgiver"),
(496800,9,2,0,0,0,100,0,2000,2000,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 0"),
(496800,9,3,0,0,0,100,0,5000,5000,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 1"),
(496800,9,4,0,0,0,100,0,6000,6000,0,0,0,1,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 2"),
(496800,9,5,0,0,0,100,0,6000,6000,0,0,0,1,3,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 3"),
(496800,9,6,0,0,0,100,0,7000,7000,0,0,0,1,4,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 4"),
(496800,9,7,0,0,0,100,0,6000,6000,0,0,0,1,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Say Line 5"),
(496800,9,8,0,0,0,100,0,4000,4000,0,0,0,5,5,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Play Emote 5"),
(496800,9,9,0,0,0,100,0,6000,6000,0,0,0,82,2,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Lady Jaina Proudmoore - On Script - Add Npc Flag Questgiver");
