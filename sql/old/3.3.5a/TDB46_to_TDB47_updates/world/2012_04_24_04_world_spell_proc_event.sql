 -- Rogue T9 2P - Should proc only from Rupture ticks.
DELETE FROM `spell_proc_event` WHERE `entry` IN(67209);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `procFlags`) VALUES
(67209, 0x01, 8, 0x100000, 0x50000);
