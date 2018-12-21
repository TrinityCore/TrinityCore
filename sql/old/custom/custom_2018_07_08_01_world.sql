DELETE FROM `spell_proc` WHERE `spellId` IN (33603, 33604, 33605);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(33603, 7, 0x00000002, 0x0, 0x0, 0x00010000, 0x1, 0x1, 0x0, 0),
(33604, 7, 0x00000002, 0x0, 0x0, 0x00010000, 0x1, 0x1, 0x0, 32),
(33605, 7, 0x00000002, 0x0, 0x0, 0x00010000, 0x1, 0x1, 0x0, 32);
