DELETE FROM `spell_script_names` WHERE `ScriptName` IN 
('spell_hun_glyph_of_kill_shot',
'spell_hun_camouflage',
'spell_hun_camouflage_duration',
'spell_hun_camouflage_triggered');

INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(63067, 'spell_hun_glyph_of_kill_shot'),
(51753, 'spell_hun_camouflage'),
(51755, 'spell_hun_camouflage_duration'),
(80325, 'spell_hun_camouflage_triggered');

DELETE FROM `spell_proc` WHERE `SpellId`= 63067;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(63067, 9, 0, 0x00800000, 0, 0x00000100, 1, 4, 0, 0, 0, 0, 100);
