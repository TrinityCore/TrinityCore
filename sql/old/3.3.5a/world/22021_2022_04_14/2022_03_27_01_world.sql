--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 43392;

DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_fjord_mindless_abomination_ping_master';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(43393,'spell_fjord_mindless_abomination_ping_master');

UPDATE `creature_template` SET `AIName` = 'SmartAI', `ScriptName` = '' WHERE `entry` = 23575;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 23575 AND `source_type` = 0;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(23575,0,0,0,11,0,100,512,0,0,0,0,0,11,43393,0,0,0,0,0,23,0,0,0,0,0,0,0,0,"Mindless Abomination - On Spawn - Cast 'Ping Master'"),
(23575,0,1,0,29,0,100,512,1,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mindless Abomination - On Charm Break - Despawn"),
(23575,0,2,0,6,0,100,512,0,0,0,0,0,41,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Mindless Abomination - On Death - Despawn");

UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_mindless_abomination_explosion_fx_master' WHERE `ScriptName` = 'spell_mindless_abomination_explosion_fx_master';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_rivenwood_captives_not_on_quest' WHERE `ScriptName` = 'spell_rivenwood_captives_not_on_quest';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_rivenwood_captives_on_quest' WHERE `ScriptName` = 'spell_rivenwood_captives_on_quest';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_the_cleansing_shrine_cast' WHERE `ScriptName` = 'spell_the_cleansing_shrine_cast';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_the_cleansing_cleansing_soul' WHERE `ScriptName` = 'spell_the_cleansing_cleansing_soul';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_the_cleansing_mirror_image_script_effect' WHERE `ScriptName` = 'spell_the_cleansing_mirror_image_script_effect';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_the_cleansing_on_death_cast_on_master' WHERE `ScriptName` = 'spell_the_cleansing_on_death_cast_on_master';
UPDATE `spell_script_names` SET `ScriptName` = 'spell_fjord_the_way_to_his_heart_anuniaq_net' WHERE `ScriptName` = 'spell_the_way_to_his_heart_anuniaq_net';
