DELETE FROM `spell_proc` WHERE `SpellId` IN (-80979, -46913, 46916, 76856, -12329);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`) VALUES
(-80979, 4, 0x00000080, 0, 0, 0x00001110, 1, 1, 0, 0, 0, 0),
(-46913, 4, 0, 0x00000400, 0, 0x00000010, 1, 2, 0, 0, 0, 0),
(46916, 4, 0x00200000, 0, 0, 0x00000010, 1, 1, 0, 2, 0, 1),
(76856, 0, 0, 0, 0, 0, 0, 1, 0, 16 | 32 | 64, 0, 0),
(-12329, 4, 0x00400000, 0x00000004, 0, 0x00001010, 1, 2, 0, 0, 0, 0);
