-- Attach druid's gore spell script
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_skull_bash');
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(106839, 'spell_dru_skull_bash');
