-- Add prowl spell script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_dru_prowl';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(5215,'spell_dru_prowl');
