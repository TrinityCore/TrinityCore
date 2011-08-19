-- Add serverside spells place holders for future development
DELETE FROM `spell_dbc` WHERE `Id` IN (25347,45315,43236,43459,43499,44275,64689,50574);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(25347, 'Item_template serverside spell'),
(45315, 'Quest 11566 reward serverside spell'),
(43236, 'Quest 11288 reward serverside spell'),
(43459, 'Quest 11332 reward serverside spell'),
(43499, 'Quest 11250 reward serverside spell'),
(44275, 'Quest 11432 reward serverside spell'),
(64689, 'Quest 13854 and 13862 reward serverside spell'),
(50574, 'Quest 12597 reward serverside spell');
