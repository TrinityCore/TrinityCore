-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_magmaw_lava_parasite_summon');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(77969, 'spell_magmaw_lava_parasite_summon');
