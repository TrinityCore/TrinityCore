-- Spells
DELETE FROM `spell_script_names` WHERE `ScriptName` IN
('spell_ozuruk_rupture_summon');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(95669, 'spell_ozuruk_rupture_summon');
