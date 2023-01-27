delete from spell_linked_spell where spell_trigger = '-125565';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(-125565, 144500, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Warrior T16 prot - Reckless Defense');

delete from spell_trigger where spell_id = 144500;
INSERT INTO `spell_trigger` (`spell_id`, `spell_trigger`, `spell_cooldown`, `option`, `target`, `caster`, `targetaura`, `bp0`, `bp1`, `bp2`, `effectmask`, `aura`, `chance`, `group`, `comment`) VALUES 
(144500, 144499, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 'Warrior T16 Protection 4P Bonus');