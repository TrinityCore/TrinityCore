DELETE FROM `spell_proc_event` WHERE entry IN (70652,70756);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 70652, 0x00,  15, 0x00000008, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0), -- Item - Death Knight T10 Tank 4P Bonus
( 70756, 0x00,  10, 0x00200000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,   0,   0,   0); -- Item - Paladin T10 Holy 4P Bonus