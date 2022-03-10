DELETE FROM `spell_proc` WHERE `SpellId` IN (55640, 75171);
INSERT INTO `spell_proc` (`SpellId`, `SpellTypeMask`, `SpellPhaseMask`, `Cooldown`) VALUES
(55640, 0x1 | 0x2, 0x1, 60000),
(75171, 0x1 | 0x2, 0x1, 64000);
