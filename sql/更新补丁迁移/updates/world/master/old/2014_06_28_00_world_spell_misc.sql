delete from spell_linked_spell where spell_trigger = 5308 and spell_effect = 139958;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(5308, 139958, 0, 0, 0, 29725, 0, 0, 0, 0, 0, 0, 'Warrior - Sudden Death');

delete from spell_proc_event where entry = 29725;
INSERT INTO `spell_proc_event` (`entry`, `SchoolMask`, `SpellFamilyName`, `SpellFamilyMask0`, `SpellFamilyMask1`, `SpellFamilyMask2`, `SpellFamilyMask3`, `procFlags`, `procEx`, `ppmRate`, `CustomChance`, `Cooldown`, `effectmask`) VALUES 
(29725, 1, 4, 0, 0, 262144, 0, 20, 0, 0, 0, 0, 7);

delete from spell_trigger where spell_id = 29725 and spell_trigger = 52437;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(29725, 52437, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Warrior - Sudden Death');