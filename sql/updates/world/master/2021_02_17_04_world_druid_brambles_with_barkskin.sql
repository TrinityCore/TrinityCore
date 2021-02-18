-- Add brambles spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_brambles', 'spell_dru_barkskin');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(203953, 'spell_dru_brambles'),
(22812, 'spell_dru_barkskin');
