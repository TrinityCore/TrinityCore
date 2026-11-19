--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_ahnkahet_combined_toxins' WHERE `ScriptName` = 'spell_combined_toxins';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_ahnkahet_shadow_blast' WHERE `ScriptName` = 'spell_shadow_blast';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_ahnkahet_shadow_sickle' WHERE `ScriptName` = 'spell_shadow_sickle';

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_ahnkahet_yogg_saron_whisper';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(58906,'spell_ahnkahet_yogg_saron_whisper'),
(58908,'spell_ahnkahet_yogg_saron_whisper'),
(58909,'spell_ahnkahet_yogg_saron_whisper'),
(58910,'spell_ahnkahet_yogg_saron_whisper');

DELETE FROM `creature_text` WHERE `CreatureID` = 31264;
UPDATE `creature_template` SET `AIName` = 'SmartAI' WHERE `entry` = 31264;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 31264 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` BETWEEN 3126400 AND 3126403 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(31264,0,0,0,60,0,100,0,300000,600000,300000,600000,0,88,3126400,3126403,0,0,0,0,1,0,0,0,0,0,0,0,0,"A Mysterious Voice - On Update - Run Random Script"),

(3126400,9,0,0,0,0,100,0,0,0,0,0,0,11,58906,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A Mysterious Voice - On Script - Cast 'Creature - Yogg-Saron Whisper'"),
(3126401,9,0,0,0,0,100,0,0,0,0,0,0,11,58908,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A Mysterious Voice - On Script - Cast 'Creature - Yogg-Saron Whisper'"),
(3126402,9,0,0,0,0,100,0,0,0,0,0,0,11,58909,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A Mysterious Voice - On Script - Cast 'Creature - Yogg-Saron Whisper'"),
(3126403,9,0,0,0,0,100,0,0,0,0,0,0,11,58910,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"A Mysterious Voice - On Script - Cast 'Creature - Yogg-Saron Whisper'");
