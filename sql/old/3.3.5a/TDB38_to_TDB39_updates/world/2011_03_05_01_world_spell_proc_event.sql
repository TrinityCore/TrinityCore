DELETE FROM `spell_proc_event` WHERE `entry` IN (71880,71892);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(71880,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,1,0,0), -- Item - Icecrown 25 Normal Dagger Proc
(71892,0x00,0,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,1,0,0); -- Item - Icecrown 25 Heroic Dagger Proc
