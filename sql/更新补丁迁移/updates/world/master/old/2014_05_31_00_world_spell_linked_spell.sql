delete from spell_linked_spell where spell_trigger = '-125042';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(-125042, -61648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 'Hunter - Remove Glyph of Aspect of the Beast');

delete from spell_linked_spell where spell_trigger = 125042;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(125042, 61648, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 'Hunter - Glyph of Aspect of the Beast');