DELETE FROM `spell_proc` WHERE `SpellId`= -85113;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-85113, 5, 0x00000020, 0x00800000, 0, 0x00010000, 1, 2, 0, 0, 0, 0, 0);
