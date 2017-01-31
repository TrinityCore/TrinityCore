--
SET @CGUID = 358715;
DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID AND @CGUID+3;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID, 43708, 1, 1, 1, 1, 2941.93, -4997.47, 166.1603, 0, 120, 0, 0), -- 43708 (Beezle Spinspark) 
(@CGUID+1, 35195, 1, 1, 1, 1, 2546.958, -4861.799, 145.879, 0.3665192, 120, 0, 0), -- 35195 (Labor Captain Grabbit) 
(@CGUID+2, 35194, 1, 1, 1, 1, 2551.742, -4851.749, 145.8674, 5.235988, 120, 0, 0), -- 35194 (Ag'tor Bloodfist) 
(@CGUID+3, 36873, 1, 1, 1, 1, 3540.194, -5131.965, 85.45117, 1.867502, 120, 0, 0); -- 36873 (High Priestess Silthera) 
