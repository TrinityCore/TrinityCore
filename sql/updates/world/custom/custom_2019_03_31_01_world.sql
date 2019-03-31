DELETE FROM `spell_proc` WHERE `SpellId` IN (74434);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(74434, 5, 0x00000100 | 0x20000000 | 0x00000008 | 0x00010000, 0x00000080, 0x00008000, 0x00010000 | 0x00004000 | 0x00000400, 7, 1, 0, 0, 0, 1, 100);
