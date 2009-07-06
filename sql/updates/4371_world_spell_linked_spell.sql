DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (48384, 48395, 48396);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(48384, 50170, 2, 'Improved Moonkin Form'),
(48395, 50171, 2, 'Improved Moonkin Form'),
(48396, 50172, 2, 'Improved Moonkin Form');