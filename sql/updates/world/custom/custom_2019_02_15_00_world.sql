DELETE FROM `spell_proc` WHERE `SpellId` IN (-49219, -52284, 96171, 50371);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `Cooldown`, `Charges`, `ProcsPerMinute`, `Chance`) VALUES
(-52284, 0, 0, 0, 0, 0, 0, 0, 0, 0, 45000, 0, 0, 0),
(96171, 15, 0x00000008, 0, 0, 0, 2, 1, 0, 0, 0, 1, 0, 0),
(50371, 0, 0, 0, 0, 0, 0, 1, 0, 16 | 32 | 64, 0, 0, 0, 0);
