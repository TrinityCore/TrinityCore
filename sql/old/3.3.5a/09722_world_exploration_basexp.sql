-- Base XP for Levels 71 to 79
DELETE FROM `exploration_basexp` WHERE `level` IN (71,72,73,74,75,76,77,78,79);
INSERT INTO `exploration_basexp` (`level`,`basexp`) VALUES 
(71,1330),
(72,1370),
(73,1410),
(74,1440),
(75,1470),
(76,1510),
(77,1530),
(78,1600),
(79,1630);

