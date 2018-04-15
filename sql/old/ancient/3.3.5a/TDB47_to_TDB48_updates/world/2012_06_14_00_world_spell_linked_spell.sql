-- Fix Surge of Adrenaline
DELETE FROM `spell_linked_spell` WHERE `spell_effect`=68667;
INSERT INTO `spell_linked_spell` (`spell_trigger`,`spell_effect`,`type`,`comment`) VALUES
(-66683,68667,0, 'Icehowl - Surge of Adrenaline'),
(-67660,68667,0, 'Icehowl - Surge of Adrenaline');
