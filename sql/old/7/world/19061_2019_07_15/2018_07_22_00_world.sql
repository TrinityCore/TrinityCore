DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_travel_form_dummy', 'spell_dru_travel_form');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(783, 'spell_dru_travel_form_dummy'),
(1066, 'spell_dru_travel_form'),
(33943, 'spell_dru_travel_form'),
(40120, 'spell_dru_travel_form'),
(165961, 'spell_dru_travel_form');

DELETE FROM `spell_linked_spell` WHERE `spell_trigger` = 165961 AND spell_effect = 126056;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(165961, 126056, 1, 'Stag Form - Sound Effect: Stag Form');
