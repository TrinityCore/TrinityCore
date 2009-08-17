DELETE FROM `spell_area` where spell in (40216,42016);

DELETE FROM `spell_linked_spell` WHERE spell_trigger = 40214;
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
( 40214, 40216, 2, 'Dragonmaw Illusion'),
( 40214, 42016, 2, 'Dragonmaw Illusion');
