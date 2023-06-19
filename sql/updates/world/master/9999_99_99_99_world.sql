DELETE FROM `spell_script_names` WHERE `spell_id` IN (33076, 41635, 33110);
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(33076, 'spell_pri_prayer_of_mending_dummy'),
(41635, 'spell_pri_prayer_of_mending'),
(33110, 'spell_pri_prayer_of_mending_heal');
