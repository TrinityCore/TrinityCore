UPDATE `spell_proc` SET `SpellFamilyMask1`= 0x200 | 0x400, `ProcsPerMinute`= 0, `AttributesMask`= 0x2 WHERE `SpellId`= -12322;
DELETE FROM `spell_proc` WHERE `SpellId`= 12964;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`, `AttributesMask`) VALUES
(12964, 4, 7, 1, 0x8);
