--
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_brewfest_botm_internal_combustion');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49738,'spell_brewfest_botm_internal_combustion');

--
UPDATE `creature_template` SET `scale` = 1, `AIName` = 'SmartAI' WHERE `entry` = 27870;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 27870 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 2787000 AND `source_type` = 9;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(27870,0,0,0,11,0,100,0,0,0,0,0,0,80,2787000,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wild Flower - On Spawn - Run Script"),

(2787000,9,0,0,0,0,100,0,3000,3000,0,0,0,11,49801,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Wild Flower - On Script - Cast 'BOTM - Flowery Brew - Grow'");

--
UPDATE `spell_dbc` SET `ProcChance` = 101, `Effect1` = 6, `EffectImplicitTargetA1` = 1, `EffectApplyAuraName1` = 26 WHERE `Id` = 61370;

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_brewfest_botm_bloated');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(49822,'spell_brewfest_botm_bloated');

--
UPDATE `spell_script_names` SET `ScriptName` = 'spell_brewfest_botm_teach_language' WHERE `ScriptName` = 'spell_item_teach_language';
