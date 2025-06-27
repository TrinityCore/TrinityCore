--
UPDATE `creature_template` SET `AIName`='SmartAI', `ScriptName`="" WHERE `entry` IN (19991);
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (19991) AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(19991, 0, 0, 0, 4, 0, 100, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - On Death - Say text 1'),
(19991, 0, 1, 0, 0, 0, 100, 0, 2000, 5000, 4000, 5000, 11, 15496, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - cast Cleave'),
(19991, 0, 2, 0, 0, 0, 100, 0, 5000, 10000, 8000, 12000, 11, 37577, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - debilitating-strike'),
(19991, 0, 3, 0, 0, 0, 100, 1, 15000, 20000, 10000, 15000, 11, 34932, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - IC - Bloodmaul Buzz'),
(19991, 0, 4, 5, 2, 0, 100, 1, 0, 20, 1, 1, 11, 8599, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - Heath pct - cast Enrage'),
(19991, 0, 5, 0, 61, 0, 100, 0, 0, 0, 0, 0, 1, 2, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,0,'Bloodmaul Brute - Heath pct - say text 3');
