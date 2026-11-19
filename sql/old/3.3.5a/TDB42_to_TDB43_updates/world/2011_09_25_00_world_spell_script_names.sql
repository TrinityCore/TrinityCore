DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_bloodlust';
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_heroism';
INSERT INTO `spell_script_names` (`spell_id`,`ScriptName`) VALUES
(2825,'spell_sha_bloodlust'),
(32182,'spell_sha_heroism');

