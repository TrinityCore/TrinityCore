--
DELETE FROM `spell_proc` WHERE `SpellId`= 76613;
INSERT INTO `spell_proc` (`SpellId`, `SpellPhaseMask`, `AttributesMask`) VALUES
(76613, 0x00000002, 0x0000010 | 0x0000020);
