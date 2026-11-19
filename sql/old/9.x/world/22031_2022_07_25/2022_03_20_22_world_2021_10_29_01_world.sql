--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 22060;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 22060 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(22060,0,0,0,0,0,100,0,5000,7000,7000,10000,0,11,14873,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fenissa the Assassin - In Combat - Cast 'Sinister Strike'"),
(22060,0,1,0,0,0,100,0,10000,15000,15000,20000,0,11,38863,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Fenissa the Assassin - In Combat - Cast 'Gouge'"),
(22060,0,2,0,2,0,100,1,0,15,0,0,0,25,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"Fenissa the Assassin - Between 0-15% Health - Flee For Assist (No Repeat)");

UPDATE `creature_template_addon` SET `auras` = '30982 34189' WHERE `entry` = 22060;
UPDATE `creature_addon` SET `auras` = '30982 34189' WHERE `guid` IN (SELECT `guid` FROM `creature` WHERE `id` = 22060);
UPDATE `creature_template` SET `speed_walk` = 1 WHERE `entry` = 22060;
