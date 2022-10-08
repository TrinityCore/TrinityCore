delete from spell_proc_check where entry in (46915, 46916);
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(46915, 0, 0, 23881, 0, 0, 0, 7, 0, 0, 'Warrior - Bloodsurge'),
(46916, 0, 0, 100130, 0, 0, 0, 7, 0, 0, 'Warrior - Bloodsurge Trigger');

delete from spell_proc_event where entry in (46915, 46916);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(46915, 0, 4, 0, 0, 0, 0, 16, 1027, 0, 20, 0, 7),
(46916, 0, 4, 0, 0, 0, 0, 16, 1027, 0, 0, 0, 7);

delete from spell_trigger where spell_id = 46915;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `comment`) VALUES 
(46915, 46916, 1, 0, 0, 0, -500, -300, 0, 7, 0, 'Warrior - Bloodsurge');