DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_travel_form','spell_dru_travel_form_cancel');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(783, 'spell_dru_travel_form'),
(165961, 'spell_dru_travel_form_cancel'),
(1066, 'spell_dru_travel_form_cancel'),
(33943, 'spell_dru_travel_form_cancel'),
(40120, 'spell_dru_travel_form_cancel');
