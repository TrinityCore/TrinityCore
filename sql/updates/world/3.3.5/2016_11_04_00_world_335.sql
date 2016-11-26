-- Recklessness
UPDATE `spell_proc` SET `SpellTypeMask`=0x1, `SpellPhaseMask`=0x2, `AttributesMask`=0x8 WHERE `SpellId`=1719;

-- Sweeping Strikes
DELETE FROM `spell_proc` WHERE `SpellId`=12328;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(12328, 0, 4, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0);
