DELETE FROM `spell_proc_event` WHERE `entry` IN (53178,53179,62764,62765);
INSERT INTO `spell_proc_event` (`entry`,`SchoolMask`,`SpellFamilyName`,`SpellFamilyMask0`,`SpellFamilyMask1`,`SpellFamilyMask2`,`procFlags`,`procEx`,`ppmRate`,`CustomChance`,`Cooldown`) VALUES
(53178,0x00,9,0x00000000,0x10000000,0x00000000,0x00000000,0x00000000,0,100,0), -- GuardDog(Rank1)
(53179,0x00,9,0x00000000,0x10000000,0x00000000,0x00000000,0x00000000,0,100,0), -- GuardDog(Rank2)
(62764,0x00,9,0x00000000,0x10000000,0x00000000,0x00000000,0x00000000,0,100,0), -- Silverback(Rank1)
(62765,0x00,9,0x00000000,0x10000000,0x00000000,0x00000000,0x00000000,0,100,0); -- Silverback(Rank2)
