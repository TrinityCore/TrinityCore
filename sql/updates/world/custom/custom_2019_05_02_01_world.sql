DELETE FROM `spell_proc` WHERE `SpellId` IN (-64127);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `Chance`) VALUES
(-64127, 6, 0x00000001, 0x00000001, 0x00080000, 0x00004000, 4, 2, 0, 0, 0, 0, 100);
