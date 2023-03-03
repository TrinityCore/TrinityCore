delete from areatrigger_data where entry = 347;
INSERT INTO `areatrigger_actions` (`entry`, `id`, `moment`, `actionType`, `targetFlags`, `spellId`, `maxCharges`, `chargeRecoveryTime`, `comment`) VALUES 
(347, 0, 0, 0, 4, 83559, 0, 0, 'Hunter Glyph on owner player enter'),
(347, 1, 1, 1, 4, 83559, 0, 0, 'Hunter - Glyph of Black Ice - on owner player exit');

delete from areatrigger_data where entry = 347;
INSERT INTO `areatrigger_data` (`entry`, `visualId`, `radius`, `radius2`, `activationDelay`, `updateDelay`, `maxCount`, `comment`) VALUES 
(347, 1, 9.75, 0, 0, 0, 0, 'Hunter - Glyph of Black Ice');

delete from spell_linked_spell where spell_trigger = 13810 and spell_effect = 122243;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `caster`, `target`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(13810, 122243, 0, 0, 0, 109263, 0, 0, 0, 0, 0, 0, 'Hunter - Glyph of Black Ice');