delete from spell_linked_spell where spell_trigger in (49143, 49020) and spell_effect = '-51124';
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `hastalent`, `hastalent2`, `chance`, `cooldown`, `type2`, `hitmask`, `learnspell`, `comment`) VALUES 
(49143, -51124, 0, 0, 0, 0, 0, 0, 0, 0, 'DK -Remove Killing Machine'),
(49020, -51124, 0, 0, 0, 0, 0, 0, 0, 0, 'DK -Remove Killing Machine');