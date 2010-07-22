-- Add serverside spells place holders for future development
DELETE FROM `spell_dbc` WHERE `Id` IN (70878);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(38406, 'Quest 10721 RewSpellCast serverside spell');
