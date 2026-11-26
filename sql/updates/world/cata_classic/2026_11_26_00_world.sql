DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_death_grip', 'spell_dk_death_grip_triggered');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(49576, 'spell_dk_death_grip'),
(49560, 'spell_dk_death_grip_triggered');
