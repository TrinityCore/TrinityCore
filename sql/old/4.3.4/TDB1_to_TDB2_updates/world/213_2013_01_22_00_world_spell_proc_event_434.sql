-- Malfurion's Gift
DELETE FROM `spell_proc_event` WHERE `entry` IN ('92363', '92364');
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`)
VALUES
(92363, 0, 7, 0, 16, 0, 278528, 0, 0, 2, 0),
(92364, 0, 7, 0, 16, 0, 278528, 0, 0, 4, 0);
