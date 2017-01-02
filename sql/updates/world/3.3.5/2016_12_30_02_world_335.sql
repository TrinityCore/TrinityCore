UPDATE `spell_proc` SET `SpellFamilyMask2`=0, `AttributesMask`=`AttributesMask`|0x2 WHERE `SpellId`=-31571;
DELETE FROM `spell_proc` WHERE `SpellId` IN (57529, 57531);
INSERT INTO `spell_proc` (`SpellId`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `ProcFlags`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`, `ProcsPerMinute`, `Chance`, `Cooldown`, `Charges`) VALUES
(57529, 0, 3, 0x61400035, 0x00001000, 0x00000000, 0, 0x0, 0x1, 0x0, 0x8, 0, 0, 0, 0),
(57531, 0, 3, 0x61400035, 0x00001000, 0x00000000, 0, 0x0, 0x1, 0x0, 0x8, 0, 0, 0, 0);
