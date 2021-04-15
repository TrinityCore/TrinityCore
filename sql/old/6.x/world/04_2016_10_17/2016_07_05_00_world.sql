-- Dark Siphon
DELETE FROM `conditions` WHERE `SourceTypeOrReferenceId`=13 AND `SourceGroup`=0 AND `SourceEntry`=165059;
INSERT INTO `conditions` (`SourceTypeOrReferenceId`,`SourceGroup`,`SourceEntry`,`SourceId`,`ElseGroup`,`ConditionTypeOrReference`,`ConditionTarget`,`ConditionValue1`,`ConditionValue2`,`ConditionValue3`,`ErrorTextId`,`ScriptName`,`Comment`) VALUES
(13,1,165059,0,0,31,0,3,81556 ,0,0,"","Dark Siphon – Cast only on K'ure.");

-- Decimatus SAI
SET @ENTRY := 81989;
UPDATE `creature_template` SET `AIName`="SmartAI" WHERE `entry`=@ENTRY;
DELETE FROM `smart_scripts` WHERE `entryorguid`=@ENTRY AND `source_type`=0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(@ENTRY,0,0,0,11,0,100,0,0,0,0,0,11,169869,34,0,0,0,0,1,0,0,0,0,0,0,0,"Decimatus - On Respawn - Cast Transformation Sickness on Self (Need Core Handler for Spell)"),
(@ENTRY,0,1,0,0,0,100,0,9000,11000,9000,11000,11,174011,0,0,0,0,0,5,0,0,0,0,0,0,0,"Decimatus - In Combat - Cast Neutralize - Need Core Handler."),
(@ENTRY,0,2,0,0,0,100,0,27000,27000,27000,27000,11,174016,1,0,0,0,0,1,0,0,0,0,0,0,0,"Decimatus - In Combat - Cast Decimate.");

-- spell_gen_decimatus_transformation_sickness
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_decimatus_transformation_sickness';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (169869,'spell_gen_decimatus_transformation_sickness');

-- spell_gen_azgalor_rain_of_fire_hellfire_citadel
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_azgalor_rain_of_fire_hellfire_citadel';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (189549,'spell_gen_azgalor_rain_of_fire_hellfire_citadel');

-- spell_gen_mark_of_kazrogal_hellfire
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_mark_of_kazrogal_hellfire';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (189512,'spell_gen_mark_of_kazrogal_hellfire');

-- spell_gen_anetheron_summon_towering_infernal
 DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_anetheron_summon_towering_infernal';
 INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
 (189491,'spell_gen_anetheron_summon_towering_infernal');
