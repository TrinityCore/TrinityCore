delete from spell_pet_auras where spellId = 147358;
INSERT INTO `spell_pet_auras` (`petEntry`, `spellId`, `option`, `target`, `targetaura`, `bp0`, `bp1`, `bp2`, `aura`, `casteraura`, `comment`) VALUES 
(510, 147358, 0, 0, 1, 0, 0, 0, 146976, 0, 'Символ вольного элементаля');

delete from spell_linked_spell where spell_trigger in (146976, -146976);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(146976, 147358, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Символ вольного элементаля'),
(-146976, -147358, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 'Снятие Символ вольного элементаля');