DELETE FROM `spell_linked_spell` WHERE `spell_effect` IN (52418, -52418);

INSERT INTO `spell_linked_spell` (`spell_trigger`, `spell_effect`, `type`, `comment`) VALUES
(52415, 52418, 0, 'Carrying Seaforium - Add'),
(52410, -52418, 0, 'Carrying Seaforium - Remove');
