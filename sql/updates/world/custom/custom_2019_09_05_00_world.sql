DELETE FROM `spell_proc` WHERE `SpellId` IN (-53486, -84652);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellTypeMask`, `SpellPhaseMask`) VALUES
(-84652, 8, 0x2, 0x00800000, 1, 2);

UPDATE `spell_proc` SET `SpellFamilyName`= 11, `SpellFamilyMask0`= 0x00000001 WHERE `SpellId`= -82984;
