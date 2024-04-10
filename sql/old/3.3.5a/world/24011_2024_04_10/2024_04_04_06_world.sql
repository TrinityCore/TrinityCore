SET @CGUID := 208509;

DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` BETWEEN 207174 AND 207209;
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` IN (130847, 130848, 130849, 130853, 130855, 130906, 130907, 130908, 130971);
DELETE FROM `spawn_group` WHERE `spawnType`=0 AND `spawnId` BETWEEN @CGUID+0 AND @CGUID+54;
INSERT INTO `spawn_group` (`groupId`, `spawnType`, `spawnId`) VALUES
(2, 0, @CGUID+34),
(2, 0, @CGUID+35),
(2, 0, @CGUID+36),
(2, 0, @CGUID+37),
(2, 0, @CGUID+38),
(2, 0, @CGUID+39),
(2, 0, @CGUID+40),
(2, 0, @CGUID+41),
(2, 0, @CGUID+42),
(2, 0, @CGUID+43),
(2, 0, @CGUID+44),
(2, 0, @CGUID+45),
(2, 0, @CGUID+46),
(2, 0, @CGUID+47),
(2, 0, @CGUID+48),
(2, 0, @CGUID+49),
(2, 0, @CGUID+50),
(2, 0, @CGUID+51),
(2, 0, @CGUID+52),
(2, 0, @CGUID+53),
(2, 0, @CGUID+54);
