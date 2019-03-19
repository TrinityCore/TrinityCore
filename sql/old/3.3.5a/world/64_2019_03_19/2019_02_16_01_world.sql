-- 
UPDATE `creature_template` SET `AIName`='SmartAI' WHERE `entry` IN (29486,24791,29479,23691,24681,23690,29487);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (29486,24791,29479,23691,24681,23690,29487) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23691,0,0,0,0,0,100,0,5000,9000,7000,12000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shoveltusk Stag - In Combat - Cast 'Gore'"),
(23691,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shoveltusk Stag - In Aggro - Cast 'Shoveltusk Charge'"),
(29479,0,0,0,0,0,100,0,5000,9000,7000,12000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shoveltusk Forager - In Combat - Cast 'Gore'"),
(29479,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shoveltusk Forager - In Aggro - Cast 'Shoveltusk Charge'"),
(24681,0,0,0,0,0,100,0,5000,9000,7000,12000,11,32019,0,0,0,0,0,2,0,0,0,0,0,0,0,"Island Shoveltusk - In Combat - Cast 'Gore'"),
(24681,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Island Shoveltusk - In Aggro - Cast 'Shoveltusk Charge'"),
(23690,0,0,0,0,0,100,0,3000,7000,9000,14000,11,42320,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shoveltusk - In Combat - Cast 'Head Butt'"),
(23690,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shoveltusk - In Aggro - Cast 'Shoveltusk Charge'"),
(24791,0,0,0,0,0,100,0,3000,7000,9000,14000,11,42320,0,0,0,0,0,2,0,0,0,0,0,0,0,"Shoveltusk Calf - In Combat - Cast 'Head Butt'"),
(24791,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Shoveltusk Calf - In Aggro - Cast 'Shoveltusk Charge'"),
(29486,0,0,0,0,0,100,0,3000,7000,9000,14000,11,42320,0,0,0,0,0,2,0,0,0,0,0,0,0,"Tamed Shoveltusk - In Combat - Cast 'Head Butt'"),
(29486,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Tamed Shoveltusk - In Aggro - Cast 'Shoveltusk Charge'"),
(29487,0,0,0,0,0,100,0,3000,7000,9000,14000,11,42320,0,0,0,0,0,2,0,0,0,0,0,0,0,"Wild Shoveltusk - In Combat - Cast 'Head Butt'"),
(29487,0,1,0,4,0,100,0,0,0,0,0,11,55860,0,0,0,0,0,1,0,0,0,0,0,0,0,"Wild Shoveltusk - In Aggro - Cast 'Shoveltusk Charge'");
