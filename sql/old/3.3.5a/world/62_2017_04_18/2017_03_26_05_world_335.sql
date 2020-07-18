DELETE FROM `spell_script_names` WHERE `ScriptName`='spell_gen_blade_warding';
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(64440, 'spell_gen_blade_warding');

-- no cooldown
UPDATE `spell_proc` SET `Cooldown`=0 WHERE `SpellId`=64440;
