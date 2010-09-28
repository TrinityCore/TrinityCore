-- Add serverside spells place holders for future development
DELETE FROM `spell_dbc` WHERE `Id` IN (11202,25359,40145,45767,71098);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(11202, 'Item 3776 spellid_1 serverside spell'),
(25359, 'Item 21293 spellid_2 serverside spell'),
(40145, 'Quest 11000 RewSpellCast serverside spell'),
(45767, 'Quest 11670 RewSpellCast serverside spell'),
(71098, 'Quest 24451 RewSpellCast serverside spell');
