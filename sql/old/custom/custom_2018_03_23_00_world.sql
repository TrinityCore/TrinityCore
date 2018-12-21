DELETE FROM `spell_script_names` where `ScriptName` IN
('spell_sha_healing_rain',
'spell_sha_healing_rain_triggered');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(73920, 'spell_sha_healing_rain'),
(73921, 'spell_sha_healing_rain_triggered');
