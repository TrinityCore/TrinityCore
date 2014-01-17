DELETE FROM `spell_dbc` WHERE `Id` IN (38758,38665);
INSERT INTO `spell_dbc` (`Id`,`Comment`) VALUES
(38758, '[PH] Quest reward: Nether Gas In a Fel Fire Engine'),
(38665, '[PH] Quest reward: Exorcising the Trees');

DELETE FROM `disables` WHERE `sourceType`=1 AND `entry` IN (
10830, -- Exorcising the Trees
10850); -- Nether Gas In a Fel Fire Engine
