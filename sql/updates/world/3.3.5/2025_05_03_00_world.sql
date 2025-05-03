--
DELETE FROM `spell_scripts` WHERE `id` = 37013;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_gen_despawn_target' AND `spell_id` = 37013;
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(37013, 'spell_gen_despawn_target');

DELETE FROM `spell_scripts` WHERE `id` = 32348;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_mana_tombs_summon_arcane_fiends';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(32348, 'spell_mana_tombs_summon_arcane_fiends');

DELETE FROM `spell_scripts` WHERE `id` IN (29126,29137,29135,29136,29138,29139,46672,46671);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_midsummer_cleansing_flames_darnassus',
'spell_midsummer_cleansing_flames_stormwind',
'spell_midsummer_cleansing_flames_ironforge',
'spell_midsummer_cleansing_flames_orgrimmar',
'spell_midsummer_cleansing_flames_thunder_bluff',
'spell_midsummer_cleansing_flames_the_undercity',
'spell_midsummer_cleansing_flames_the_silvermoon',
'spell_midsummer_cleansing_flames_the_exodar');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29126, 'spell_midsummer_cleansing_flames_darnassus'),
(29137, 'spell_midsummer_cleansing_flames_stormwind'),
(29135, 'spell_midsummer_cleansing_flames_ironforge'),
(29136, 'spell_midsummer_cleansing_flames_orgrimmar'),
(29138, 'spell_midsummer_cleansing_flames_thunder_bluff'),
(29139, 'spell_midsummer_cleansing_flames_the_undercity'),
(46672, 'spell_midsummer_cleansing_flames_the_silvermoon'),
(46671, 'spell_midsummer_cleansing_flames_the_exodar');

DELETE FROM `spell_scripts` WHERE `id` = 52933;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_rampage_summon_zulaman_gods_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(52933, 'spell_zuldrak_rampage_summon_zulaman_gods_master');

DELETE FROM `spell_scripts` WHERE `id` = 51862;
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_breaking_through_summon_zulaman_gods_master';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51862, 'spell_zuldrak_breaking_through_summon_zulaman_gods_master');

DELETE FROM `spell_scripts` WHERE `id` IN (29182,29188);
DELETE FROM `spell_script_names` WHERE `ScriptName` IN (
'spell_temple_of_ahnqiraj_teleport_to_twin_emperors',
'spell_temple_of_ahnqiraj_teleport_to_final_chamber');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(29182, 'spell_temple_of_ahnqiraj_teleport_to_twin_emperors'),
(29188, 'spell_temple_of_ahnqiraj_teleport_to_final_chamber');

DELETE FROM `spell_scripts` WHERE `id` IN (51864,51889);
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_zuldrak_summon_nass';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(51864, 'spell_zuldrak_summon_nass'),
(51889, 'spell_zuldrak_summon_nass');

DELETE FROM `spell_scripts` WHERE `id` = 36327;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 21186 AND `source_type` = 0;
DELETE FROM `smart_scripts` WHERE `entryorguid` = -79409 AND `source_type` = 0 AND `id` = 2;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(21186,0,0,0,8,0,100,0,36327,0,0,0,0,11,36521,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Warder Target - On Spellhit 'Shoot Arcane Explosion Arrow' - Cast 'Summon Arcane Explosion'"),
(-79409,0,2,0,8,0,100,0,36327,0,0,0,0,11,36521,0,0,0,0,0,1,0,0,0,0,0,0,0,0,"Arcane Warder Target - On Spellhit 'Shoot Arcane Explosion Arrow' - Cast 'Summon Arcane Explosion'");

DELETE FROM `spell_scripts` WHERE `id` = 45030;
DELETE FROM `smart_scripts` WHERE `entryorguid` = 25003 AND `source_type` = 0 AND `id` = 3;
INSERT INTO `smart_scripts` (`entryorguid`,`source_type`,`id`,`link`,`event_type`,`event_phase_mask`,`event_chance`,`event_flags`,`event_param1`,`event_param2`,`event_param3`,`event_param4`,`event_param5`,`action_type`,`action_param1`,`action_param2`,`action_param3`,`action_param4`,`action_param5`,`action_param6`,`target_type`,`target_param1`,`target_param2`,`target_param3`,`target_param4`,`target_x`,`target_y`,`target_z`,`target_o`,`comment`) VALUES
(25003,0,3,0,8,0,100,0,45030,0,0,0,0,11,45088,0,0,0,0,0,7,0,0,0,0,0,0,0,0,"Emissary of Hate - On Spellhit 'Impale Emissary' - Cast 'Emissary of Hate Credit'");
