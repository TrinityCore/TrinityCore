DELETE FROM `spell_proc` WHERE `SpellId` = 51564;
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask2`, `SpellPhaseMask`) VALUES (51564, 11, 256, 16, 2); 

UPDATE `spell_proc` SET `Charges` = '2' WHERE `SpellId` = '53390';
