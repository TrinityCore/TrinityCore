UPDATE `spell_proc` SET `AttributesMask`=0x2 WHERE `SpellId` IN (
-324, -- Lightning Shield
-52127 -- Water Shield
);

-- Seal of Righteousness
DELETE FROM `spell_proc` WHERE `SpellId` =21084;
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(21084,  0, 0, 0x00000000, 0x00000000, 0x00000000, 0, 0x1, 0x2, 0x0, 0x2, 0, 0, 0, 0);
