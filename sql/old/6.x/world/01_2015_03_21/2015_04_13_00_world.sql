DELETE FROM `spell_linked_spell` WHERE `spell_trigger` IN (34767, 34769);
INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `comment`) VALUES
(34767, 31726, 'Summon Charger - Blood Elf'),
(34769, 31726, 'Summon Warhorse - Blood Elf');
