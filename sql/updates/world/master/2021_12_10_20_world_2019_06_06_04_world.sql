-- Nerub'ar Warrior
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=25619;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25619 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25619,0,0,0,9,0,100,1,8,25,0,0,11,50347,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerub'ar Warrior - In Range - Cast 'Rush'");

-- Nerub'ar Web Lord
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=25294;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25294 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25294,0,0,0,0,0,100,0,8000,8000,16000,21000,11,50284,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Web Lord - In Combat - Cast 'Blinding Swarm'");

-- Nerub'ar Tunneler
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=25622;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25622 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25622,0,0,0,2,0,100,1,0,30,0,0,11,50364,0,0,0,0,0,1,0,0,0,0,0,0,0,"Nerub'ar Tunneler - At 30% HP - Cast 'Rock Shield'");

-- Nerub'ar Corpse Harvester
UPDATE creature_template SET `AIName`='SmartAI' WHERE `entry`=25445;
DELETE FROM `smart_scripts` WHERE `entryorguid`=25445 AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25445,0,0,0,0,0,100,0,2000,4000,12000,17000,11,45577,0,0,0,0,0,2,0,0,0,0,0,0,0,"Nerub''ar Corpse Harvester - In Combat - Cast 'Venom Spit'");
