DELETE FROM `spell_proc_event` WHERE `entry` IN (11213,12574,12575,12576,12577);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`) VALUES
(11213,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0), -- Arcane Concentration (Rank 1)
(12574,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0), -- Arcane Concentration (Rank 2)
(12575,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0), -- Arcane Concentration (Rank 3)
(12576,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0), -- Arcane Concentration (Rank 4)
(12577,0x00,3,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0,0,0); -- Arcane Concentration (Rank 5)
