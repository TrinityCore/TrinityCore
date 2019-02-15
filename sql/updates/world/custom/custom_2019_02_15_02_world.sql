DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_dk_anti_magic_shell_raid',
'spell_dk_anti_magic_shell_self',
'spell_dk_anti_magic_shell');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(48707, 'spell_dk_anti_magic_shell');
