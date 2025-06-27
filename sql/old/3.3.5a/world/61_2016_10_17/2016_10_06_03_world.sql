DELETE FROM `spell_proc` WHERE `SpellId` = 63057;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(63057, 0, 7, 0x00000000, 0x00040000, 0x00000000, 16384, 0x0, 0x2, 0, 0x0, 0, 0, 0, 0); -- Glyph of Barkskin

DELETE FROM `spell_script_names` WHERE `ScriptName` IN ('spell_dru_barkskin','spell_dru_glyph_of_barkskin');
INSERT INTO `spell_script_names` (`spell_id`, `ScriptName`) VALUES
(22812, 'spell_dru_barkskin'),
(63057, 'spell_dru_glyph_of_barkskin');
