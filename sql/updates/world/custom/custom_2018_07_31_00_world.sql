DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_drahga_devouring_flames',
'spell_drahga_devouring_flames_aoe');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(90949, 'spell_drahga_devouring_flames');
