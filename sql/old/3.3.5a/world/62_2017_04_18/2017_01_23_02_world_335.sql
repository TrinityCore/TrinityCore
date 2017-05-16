DELETE FROM `spell_proc` WHERE `SpellId`=-7001;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(-7001, 0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x0, 0x0, 0x2, 0, 0, 0, 0);
