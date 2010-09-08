-- Add serverside spells place holders for future development
DELETE FROM `spell_dbc` WHERE `Id` IN (55805);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(44805, 'Aura used in creature_addon - serverside spell');

