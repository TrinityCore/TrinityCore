-- Add bristling fur spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` = 'spell_dru_bristling_fur';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(155835, 'spell_dru_bristling_fur');
