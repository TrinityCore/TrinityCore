--
DELETE FROM `spell_proc` WHERE `SpellId`=70656;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(70656, 0, 15, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
