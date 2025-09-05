DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_lock_and_load', 'spell_hun_lock_and_load_remove');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(194595, 'spell_hun_lock_and_load'),
(19434, 'spell_hun_lock_and_load_remove');
