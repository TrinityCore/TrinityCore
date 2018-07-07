DELETE FROM `spell_proc` WHERE `SpellId` IN (93400, 81093);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(93400, 7, 0, 0, 0x02000000, 0x00010000, 1, 1, 0, 8, 0, 1, 100),
(81093, 7, 0x00000004, 0, 0, 0x00010000, 1, 1, 0, 8, 0, 1, 100);
