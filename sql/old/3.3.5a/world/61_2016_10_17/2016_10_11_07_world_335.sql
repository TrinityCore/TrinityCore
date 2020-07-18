UPDATE `spell_proc` SET `Chance` = 0 WHERE `SpellId` = -51940;
DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_sha_earthliving_weapon';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(-51940, 'spell_sha_earthliving_weapon');
