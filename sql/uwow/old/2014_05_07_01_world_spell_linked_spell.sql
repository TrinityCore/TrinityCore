delete from spell_linked_spell where spell_trigger = 1706 and spell_effect = 124433;
delete from spell_linked_spell where spell_trigger = '-111759' and spell_effect = '-124433';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(1706, 124433, 0, 120581, 0, 0, 0, 0, 0, 0, 'Levitate - Glyph of the Heavens'),
(-111759, -124433, 0, 0, 0, 0, 0, 0, 0, 0, 'Remove Levitate - Remove Glyph of the Heavens');