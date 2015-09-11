--
/*
SET @CGUID := 84210;
SET @OLDCGUID := 370474;
SET @OLDCGUID2 := 325984;
 
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+15;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+15;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID2+0 AND @OLDCGUID2+1;
INSERT INTO `creature` (`guid`, `id`, `map`, `SpawnMask`, `modelid`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 20212, 642, 3, 0, 7.305609, -0.095246, 34.51022, 3.159046, 7200, 0, 0),
(@CGUID+1, 20213, 641, 3, 0, 11.69965, 0.034146, 20.62076, 3.211406, 7200, 0, 0);
 
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+2, 37543, 530, 1, 1, 9633.195, -7136.578, 30.51368, 0, 120, 0, 0), -- 37543 (Area: 3665) 3.3.5a
(@CGUID+3, 37543, 530, 1, 1, 9648.338, -7119.096, 28.47594, 0, 120, 0, 0), -- 37543 (Area: 3665) 3.3.5a
(@CGUID+4, 37543, 530, 1, 1, 9665.38, -7136.049, 28.58942, 0, 120, 0, 0), -- 37543 (Area: 3665) 3.3.5a
(@CGUID+5, 37574, 530, 1, 1, 9568.38, -7194.522, 24.68986, 4.660029, 120, 0, 0), -- 37574 (Area: 0) 3.3.5a
(@CGUID+6, 37574, 530, 1, 1, 9530.643, -7189.838, 31.87009, 4.660029, 120, 0, 0), -- 37574 (Area: 0) 3.3.5a
(@CGUID+7, 37543, 530, 1, 1, 9530.571, -7220.372, 30.44205, 1.22173, 120, 0, 0), -- 37543 (Area: 0) 3.3.5a
(@CGUID+8, 37574, 530, 1, 1, 9520.098, -7188.818, 31.84313, 4.660029, 120, 0, 0), -- 37574 (Area: 0) 3.3.5a
(@CGUID+9, 37574, 530, 1, 1, 9676.034, -7346.333, 22.96401, 4.660029, 120, 0, 0), -- 37574 (Area: 3482) 3.3.5a
(@CGUID+10, 37574, 530, 1, 1, 9683.437, -7394.599, 24.14162, 4.660029, 120, 0, 0), -- 37574 (Area: 3482) 3.3.5a
(@CGUID+11, 37574, 530, 1, 1, 9532.216, -7239.835, 24.74386, 4.660029, 120, 0, 0), -- 37574 (Area: 3482) 3.3.5a
(@CGUID+12, 37574, 530, 1, 1, 9574.714, -7221.677, 23.17951, 4.660029, 120, 0, 0), -- 37574 (Area: 3482) 3.3.5a
(@CGUID+13, 37543, 530, 1, 1, 9648.606, -7151.55, 28.7944, 0, 120, 0, 0), -- 37543 (Area: 3482) 3.3.5a
(@CGUID+14, 37543, 530, 1, 1, 9467.849, -7269.604, 34.85052, 0, 120, 0, 0), -- 37543 (Area: 3482) 3.3.5a
(@CGUID+15, 37543, 530, 1, 1, 9467.499, -7287.613, 36.13566, 0, 120, 0, 0); -- 37543 (Area: 3482) 3.3.5a
 
DELETE FROM `creature_addon` WHERE `guid` IN (@CGUID, @CGUID+1);
DELETE FROM `creature_addon` WHERE `guid` IN (@OLDCGUID2, @OLDCGUID2+1);
INSERT INTO `creature_addon` (`guid`, `auras`) VALUES
(@CGUID+0, 66656), -- Parachute
(@CGUID+1, 66656); -- Parachute
*/
