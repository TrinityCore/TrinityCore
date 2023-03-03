delete from spell_linked_spell where spell_trigger in (88819, 88821); 

delete from spell_proc_event where entry in (88819, 88821); 
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(88821, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 7);

delete from spell_proc_check where entry in (88819, 88821);
INSERT INTO `spell_proc_check` (`entry`, `entry2`, `entry3`, `checkspell`, `hastalent`, `chance`, `target`, `effectmask`, `powertype`, `dmgclass`, `comment`) VALUES 
(88819, 0, 0, 25914, 0, 0, 0, 7, 0, 0, 'Paladin - OnCheckSpell - Holy Shock'),
(88821, 0, 0, 82327, 0, 0, 0, 7, 0, 0, 'Paladin - OnCheckSpell - Holy Radiance');

delete from spell_trigger where spell_id = 88819 and spell_trigger = 121129;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `comment`) VALUES 
(88819, 121129, 1, 0, 0, 0, 0, 0, 0, 7, 0, 0, 'Paladin - Daybreak');