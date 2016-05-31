-- Fix Preserved Holly item triggered spell to apply reindeer transformation also so Fa-la-la-la Ogri'La can be doable with it also, based on sniffs.
DELETE FROM `spell_linked_spell` WHERE `spell_trigger`=62061;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(62061,25860,0, 'Festive Holiday Mount');
