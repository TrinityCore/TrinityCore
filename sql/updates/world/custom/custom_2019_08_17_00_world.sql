DELETE FROM `spell_proc` WHERE `SpellId`= 26016;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(26016, 10, 0, 0x00008000 | 0x00040000, 0, 0, 1, 2, 0, 0);
