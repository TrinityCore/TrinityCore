-- Arcane shot
DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_hun_arcane_shot','spell_hun_multi_shot');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(185358,'spell_hun_arcane_shot'),
(2643,'spell_hun_multi_shot');
