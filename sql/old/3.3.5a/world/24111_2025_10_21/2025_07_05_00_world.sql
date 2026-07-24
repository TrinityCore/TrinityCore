--
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27958;

DELETE FROM `smart_scripts` WHERE `entryorguid` = 27958 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27958,0,0,0,11,0,100,0,0,0,0,0,0,11,50186,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Parading Pink Elekk - On Spawn - Cast 'Parading Pink Elekk Life Aura'"),
(27958,0,1,0,60,0,100,1,0,5000,0,0,0,11,36440,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Parading Pink Elekk - On Update - Cast 'Drunk Invisibility (Pink)' (No Repeat)"),
(27958,0,2,0,11,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Parading Pink Elekk - On Spawn - Start Follow Owner");

DELETE FROM `spell_script_names` WHERE `spell_id` = 50186 AND `ScriptName` = 'spell_gen_despawn_aura';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(50186,'spell_gen_despawn_aura');

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_brewfest_botm_pink_elekk';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(42264,'spell_brewfest_botm_pink_elekk');

-- This one is based only on comments
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 27867;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27867 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 2786700 AND 2786701 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27867,0,0,0,11,0,100,0,0,0,0,0,0,87,2786700,2786701,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Spawn - Run Random Script"),

(2786700,9,0,0,0,0,100,0,0,0,0,0,0,11,49757,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Script - Cast 'BOTM - Woodland Brew - Squirrel Love Aura'"),
(2786700,9,1,0,0,0,100,0,0,0,0,0,0,29,0,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Script - Start Follow Owner"),
(2786700,9,2,0,0,0,100,0,10000,10000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Script - Despawn"),

(2786701,9,0,0,0,0,100,0,2000,2000,0,0,0,11,49764,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Script - Cast 'BOTM - Woodland Brew - Squirrel Hate'"),
(2786701,9,1,0,0,0,100,0,0,0,0,0,0,114,0,0,0,0,0,0,1,0,0,0,0,30,30,0,0,"Woodland Squirrel - On Script - Move Offset"),
(2786701,9,2,0,0,0,100,0,5000,5000,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Woodland Squirrel - On Script - Despawn");

--
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_brewfest_botm_nauseous';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49869,'spell_brewfest_botm_nauseous');
