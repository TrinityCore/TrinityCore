DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_warr_kill_or_be_killed', 'spell_warr_kill_or_be_killed_target', 'spell_warr_kill_or_be_killed_warrior');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(1265361, 'spell_warr_kill_or_be_killed'),
(1265641, 'spell_warr_kill_or_be_killed_target'),
(1265600, 'spell_warr_kill_or_be_killed_warrior');
