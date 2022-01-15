DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthquake';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthquake_tick';

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES 
(61882, 'spell_sha_earthquake'), -- Earthquake
(77478, 'spell_sha_earthquake_tick'); -- Earthquake
