DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_sha_earthquake',
'spell_sha_earthquake_damage');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(61882, 'spell_sha_earthquake'),
(77478, 'spell_sha_earthquake_damage');
