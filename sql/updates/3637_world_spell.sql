DELETE FROM `playercreateinfo_spell` WHERE Spell = 56816;
INSERT INTO `playercreateinfo_spell` (`race`, `class`, `Spell`, `Note`) VALUES
(0, 6, 56816, 'Rune Strike');

DELETE FROM `spell_proc_event` WHERE `entry`=56816;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(56816,	0x00,	0,	0x00000000,	0x00000000,	0x00000000,	0x00000000,	0x00000030,	0,	0,	0); -- Rune Strike