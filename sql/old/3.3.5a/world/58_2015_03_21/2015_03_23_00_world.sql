--
DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (23214, 13819);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES
(23214, 31726, 'Summon Charger'),
(13819, 31726, 'Summon Warhorse');
