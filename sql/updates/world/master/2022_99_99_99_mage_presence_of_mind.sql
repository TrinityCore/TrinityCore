DELETE FROM `spell_proc` WHERE `SpellId`=205025;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(205025, 0, 3, 0x20000008, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
