-- Add spell script
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_ulduar_proximity_mines';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63027, 'spell_ulduar_proximity_mines');
