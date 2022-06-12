DELETE FROM `spell_proc` WHERE `SpellId` IN (-88820, 88819);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellTypeMask`, `SpellPhaseMask`, `Charges`) VALUES
(-88820, 10, 0x80000000 | 0x40000000, 0x0, 0x400, 0x2, 1, 0),
(88819, 10, 0x200000, 0x10000, 0x0, 0x1 |0x2, 1, 1);
