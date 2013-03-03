-- Add serverside spells place holders for future development
DELETE FROM `spell_dbc` WHERE `Id` IN (42876,44987,48803,68496,72958,32780,45453);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(42876, 'Quest 9275 reward serverside spell'),
(44987, 'Quest 11521 reward serverside spell'),
(48803, 'Quest 12214 reward serverside spell'),
(68496, 'Item_template serverside spell'),
(72958, 'Item_template serverside spell'),
(32780, 'Quest 10040 reward serverside spell'),
(45453, 'Quest 11587 reward serverside spell');
