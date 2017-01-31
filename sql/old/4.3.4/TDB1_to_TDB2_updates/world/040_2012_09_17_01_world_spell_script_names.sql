DELETE FROM `spell_proc_event` WHERE `entry` IN (48492,48494,48495);
DELETE FROM `spell_script_names` WHERE `spell_id` IN(-5217, -5229);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(-5217, "spell_dru_tiger_s_fury"),
(-5229, "spell_dru_enrage");
