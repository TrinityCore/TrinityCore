delete from spell_linked_spell where spell_trigger = '-57870';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(-57870, -57894, 0, 0, 1, 57870, 0, 0, 0, 0, 0, 0, 'Hunter - Glyph of Lesser Proportion Remove Aura');

delete from spell_linked_spell where spell_trigger = 57870;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(57870, 57894, 0, 0, 1, 57870, 0, 0, 0, 0, 0, 0, 'Hunter - Glyph of Lesser Proportion');

delete from spell_pet_auras where spellid = '-57894';
INSERT INTO `spell_pet_auras` (`petEntry`, `spellId`, `option`, `target`, `bp0`, `bp1`, `bp2`, `aura`, `comment`) VALUES 
(-1, -57894, 0, 2, 0, 0, 0, -57870, 'Hunter - Glyph of Lesser Proportion');

delete from spell_pet_auras where spellid = '57894';
INSERT INTO `spell_pet_auras` (`petEntry`, `spellId`, `option`, `target`, `bp0`, `bp1`, `bp2`, `aura`, `comment`) VALUES 
(-1, 57894, 0, 2, 0, 0, 0, 57870, 'Hunter - Glyph of Lesser Proportion');