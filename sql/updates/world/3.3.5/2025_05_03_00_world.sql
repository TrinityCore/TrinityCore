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
