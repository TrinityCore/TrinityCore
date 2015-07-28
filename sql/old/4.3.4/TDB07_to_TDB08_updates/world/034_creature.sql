--
SET @OGUID = 358709;

DELETE FROM `creature` WHERE GUID BETWEEN @OGUID AND @OGUID+5;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `phaseId`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@OGUID, 35085, 1, 1, 1, 0, 2948.376, -4978.832, 126.1048, 6.049321, 120, 0, 0), -- 35085 (Foreman Fisk)
(@OGUID+1, 35087, 1, 1, 1, 0, 2922.034, -5009.597, 125.952, 2.007129, 120, 0, 0), -- 35087 (Malynea Skyreaver)
(@OGUID+2, 35088, 1, 1, 1, 0, 2915.091, -5011.899, 125.7454, 0.8028514, 120, 0, 0), -- 35088 (Custer Clubnik)
(@OGUID+3, 35091, 1, 1, 1, 0, 2945.523, -4980.338, 126.0305, 2.530727, 120, 0, 0), -- 35091 (Horzak Zignibble)
(@OGUID+4, 35526, 1, 1, 1, 0, 2909.204, -5032.953, 126.9903, 3.420845, 120, 0, 0), -- 35526 (Clubnik's Dozer)
(@OGUID+5, 36752, 1, 1, 1, 0, 2923.552, -5000.983, 126.5955, 1.343904, 120, 0, 0); -- 36752 (Private Worcester)
