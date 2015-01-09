DELETE FROM `spell_script_names` WHERE `spell_id` IN (58387,20230,48438);
INSERT INTO `spell_script_names` (`spell_id` ,`ScriptName`) VALUES
(58387, 'spell_warr_glyph_of_sunder_armor'),
(20230, 'spell_warr_retaliation'),
(48438,'spell_dru_wild_growth');

DELETE FROM `spell_proc_event` WHERE `entry`=58387;
