delete from spell_proc_event where entry in (144441, 144442);
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(144441, 0, 4, 33554432, 1024, 0, 0, 0, 0, 1, 0, 0, 7),
(144442, 0, 4, 536870912, 0, 0, 0, 0, 0, 0, 0, 0, 7);

delete from spell_trigger where spell_id = 144441;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(144441, 144442, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Item - Warrior T16 DPS 4P Bonus');