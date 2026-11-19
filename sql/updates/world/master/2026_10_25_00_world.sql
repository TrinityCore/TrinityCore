DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dk_grip_of_the_dead', 'spell_dk_grip_of_the_dead_periodic', 'spell_dk_grip_of_the_dead_snare');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(43265, 'spell_dk_grip_of_the_dead'),
(273980, 'spell_dk_grip_of_the_dead_periodic'),
(52212, 'spell_dk_grip_of_the_dead_snare');
