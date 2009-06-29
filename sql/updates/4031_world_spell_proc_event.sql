DELETE FROM `spell_proc_event` WHERE `entry` IN (51698, 51700, 51701);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 51698, 0x00,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   1), -- Honor Among Thieves
( 51700, 0x00,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   1), -- Honor Among Thieves
( 51701, 0x00,  0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   1); -- Honor Among Thieves