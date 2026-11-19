-- 
DELETE FROM `creature_addon` WHERE `guid` IN (137507,137508);
INSERT INTO `creature_addon` (`guid`,`bytes2`,`auras`,`visibilityDistanceType`) VALUES
(137507,1,"48387",3),
(137508,1,"48387",3);
