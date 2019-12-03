DELETE FROM `spell_proc` WHERE `SpellID` IN (-16958, 16958, 16961, -16952, 16952, 16954);
INSERT INTO `spell_proc` (`SpellId`, `SpellFamilyName`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`) VALUES
(16958, 0, 1, 2, 2),
(16961, 0, 1, 2, 2),
(16952, 0, 1, 2, 2),
(16954, 0, 1, 2, 2);
