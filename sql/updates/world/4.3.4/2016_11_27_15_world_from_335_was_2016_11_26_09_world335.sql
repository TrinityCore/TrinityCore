/*
SET @CGUID := 86075;
SET @POOL := 32492;

DELETE FROM `pool_creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+6 AND `pool_entry` BETWEEN @Pool AND @Pool+6;
DELETE FROM `pool_creature` WHERE `guid` IN(21317,21318,21314,21324,21323,21325,21327) AND `pool_entry` BETWEEN @Pool AND @Pool+6;
INSERT INTO `pool_creature` (`guid`, `pool_entry`, `chance`, `description`) VALUES
(@CGUID+1, @Pool, 0, 'Silithyd Invader'),
(21317, @Pool, 0, 'Silithyd Hive Drone'),
(@CGUID+2, @Pool+1, 0, 'Silithyd Invader'),
(21318, @Pool+1, 0, 'Silithyd Hive Drone'),
(@CGUID+0, @Pool+2, 0, 'Silithyd Invader'),
(21314, @Pool+2, 0, 'Silithyd Hive Drone'),
(@CGUID+4, @Pool+3, 0, 'Silithyd Invader'),
(21324, @Pool+3, 0, 'Silithyd Hive Drone'),
(@CGUID+3, @Pool+4, 0, 'Silithyd Invader'),
(21323, @Pool+4, 0, 'Silithyd Hive Drone'),
(@CGUID+5, @Pool+5, 0, 'Silithyd Invader'),
(21325, @Pool+5, 0, 'Silithyd Hive Drone'),
(@CGUID+6, @Pool+6, 0, 'Silithyd Invader'),
(21327, @Pool+6, 0, 'Silithyd Hive Drone');
*/
