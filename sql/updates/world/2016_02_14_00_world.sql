-- Disallow flight form while affected by no-mount shapeshift
DELETE FROM `spell_script_names` WHERE `spell_id` IN (-33943, 33943, 40120);
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES (-33943, "spell_dru_flight_form");
