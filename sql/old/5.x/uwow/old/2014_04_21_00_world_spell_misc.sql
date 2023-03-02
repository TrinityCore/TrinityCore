delete from spell_proc_event where entry = 58385;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(58385, 0, 0, 0, 0, 0, 0, 0, 65536, 0, 0, 0, 7);

delete from spell_proc_check where entry = 58385;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(58385, 0, 0, 1715, -115945, 0, 0, 7, 0, 0, 'Warrior - Glyph of Hamstring');