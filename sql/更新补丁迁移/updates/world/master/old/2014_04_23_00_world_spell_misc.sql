delete from spell_proc_check where entry = 121467;
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(121467, 0, 0, 53600, 0, 0, 0, 7, 0, 0, 'Paladin - Alabaster Shield - On CheckSpell Shield of the Righteous');

delete from spell_proc_event where entry = 63222;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(63222, 0, 0, 0, 0, 0, 0, 0, 64, 0, 0, 0, 7);