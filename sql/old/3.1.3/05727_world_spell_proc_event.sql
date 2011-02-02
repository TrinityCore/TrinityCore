-- *Judgement of Wisdom PPM based, not 100%. By Drevi.
DELETE FROM `spell_proc_event` WHERE `entry`=20186;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
( 20186, 0x01,   0, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,  15,   0,   0); -- Judgement of Wisdom
