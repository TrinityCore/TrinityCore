-- Proc Guardian Of The Elune 
DELETE FROM `spell_proc` WHERE `SpellId` IN (155578);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance` , `Cooldown`, `Charges`) VALUES
(155578, 0, 7, 0x0, 0x40, 0x0, 0x0, 0x10, 1, 2, 0x403, 0, 0, 0, 0, 0, 0);
