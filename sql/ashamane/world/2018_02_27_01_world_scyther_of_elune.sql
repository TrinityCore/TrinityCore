DELETE FROM `spell_script_names` WHERE scriptname IN ('spell_arti_dru_new_moon', 'spell_arti_dru_half_moon', 'spell_arti_dru_full_moon');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(202767, 'spell_arti_dru_new_moon'),
(202768, 'spell_arti_dru_half_moon'),
(202771, 'spell_arti_dru_full_moon');
