DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_sha_searing_bolt',
'spell_sha_lava_lash_script');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(3606, 'spell_sha_searing_bolt'),
(105792 , 'spell_sha_lava_lash_script');
