DELETE FROM `spell_proc` WHERE `SpellId` IN (-51632);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-51632, 8, 0x00000200 | 0x00000100 | 0x00000400, 0, 0, 0, 1 | 4, 2, 0, 0, 0, 0, 0);
