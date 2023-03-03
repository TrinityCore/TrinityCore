delete from spell_linked_spell where spell_effect = 147065;
delete from spell_linked_spell where spell_effect = '-147065';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(64843, 147065, 0, 147072, 0, 0, 0, 0, 0, 0, 'Priest - Glyph of Inspired Hymns'),
(64901, 147065, 0, 147072, 0, 0, 0, 0, 0, 0, 'Priest - Glyph of Inspired Hymns'),
(-64843, -147065, 0, 0, 0, 0, 0, 0, 0, 0, 'Priest - Remove Glyph of Inspired Hymns'),
(-64901, -147065, 0, 0, 0, 0, 0, 0, 0, 0, 'Priest - Remove Glyph of Inspired Hymns');