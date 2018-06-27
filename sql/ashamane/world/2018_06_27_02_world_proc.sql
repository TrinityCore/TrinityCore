UPDATE spell_proc SET SpellFamilyName = 7, SpellFamilyMask0 = 1 WHERE SpellId = 164545;
UPDATE spell_proc SET SpellFamilyName = 7, SpellFamilyMask0 = 2 WHERE SpellId = 164547;

DELETE FROM `spell_proc` WHERE `SpellId` IN (113043);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellFamilyMask1`, `SpellPhaseMask`, `Chance`) VALUES
(113043, 7, 16, 1, 4);
