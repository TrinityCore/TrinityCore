--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_ruins_of_ahnqiraj_itch', 'spell_temple_of_ahnqiraj_itch');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(25185, 'spell_ruins_of_ahnqiraj_itch'),
(26077, 'spell_temple_of_ahnqiraj_itch');

UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 15325;
DELETE FROM `smart_scripts` WHERE `entryorguid` IN (15325,15236) AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(15325,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,25185,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Hive'Zara Wasp - In Combat - Cast 'Itch'"),
(15236,0,0,0,0,0,100,0,5000,10000,10000,15000,0,11,26077,0,0,0,0,0,2,0,0,0,0,0,0,0,0,"Vekniss Wasp - In Combat - Cast 'Itch'");
