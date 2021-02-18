-- Set Tooth and Claw to proc on auto attack
DELETE FROM `spell_proc` WHERE `SpellId` IN (135288, 135286);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `DisableEffectsMask`, `ProcsPerMinute`, `Chance` , `Cooldown`, `Charges`) VALUES
(135288, 1, 0, 0x0, 0x0, 0x0, 0x0, 0x4, 1, 2, 0x403, 0, 2, 0, 20, 0, 0),
(135286, 0, 7, 0x800, 0x0, 0x0, 0x0, 0x10, 1, 2, 0x403, 0x8, 0, 0, 0, 0, 0);
