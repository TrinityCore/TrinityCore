DELETE FROM `spell_proc` WHERE `SpellId` IN (89485, -57470);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(89485, 6, 0x00000200 | 0x00000800 | 0x00001000, 0x00000004, 0, 0x00004000, 2, 1, 0, 0, 0, 1, 100),
(-57470, 0, 0, 0, 0, 0, 2, 1, 0, 16, 0, 0, 0);
