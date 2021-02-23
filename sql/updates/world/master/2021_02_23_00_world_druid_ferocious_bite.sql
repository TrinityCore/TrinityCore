-- Attach ferocious bite script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_ferocious_bite';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(22568,'spell_dru_ferocious_bite');
