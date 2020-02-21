DELETE FROM `spell_proc` WHERE `SpellId` IN (83727, 94003);
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`, `HitMask`, `AttributesMask`) VALUES
(83727, 1, 2, 0, 16),
(94003, 1, 2, 0, 16);
