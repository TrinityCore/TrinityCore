delete from spell_linked_spell where spell_effect in (116524, -116524);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `removeMask`, `comment`) VALUES 
(121176, 116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Orb of Power'),
(121175, 116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Orb of Power'),
(121177, 116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Orb of Power'),
(121164, 116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Add Orb of Power'),
(-121176, -116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Orb of Power'),
(-121175, -116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Orb of Power'),
(-121177, -116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Orb of Power'),
(-121164, -116524, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Orb of Power');
