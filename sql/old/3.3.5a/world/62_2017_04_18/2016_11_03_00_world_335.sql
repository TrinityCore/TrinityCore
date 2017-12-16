-- Savage Combat
DELETE FROM `spell_proc` WHERE `SpellId`=-51682;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-51682, 0, 8, 0x00000000, 0x00080000, 0x00000000, 0, 0x4, 0x2, 0x0, 0x2, 0, 0, 0, 0);
