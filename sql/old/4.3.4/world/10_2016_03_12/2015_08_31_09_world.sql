--
SET @CGUID := 68279; -- set by TDB team (3)
SET @OLDCGUID := 68279; -- set by TDB team (3)
SET @OGUID := 6134; -- set by TDB team (2)
SET @OLDOGUID := 6134; -- set by TDB team (2)

DELETE FROM `creature_addon` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
DELETE FROM `creature_addon` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+2;
INSERT INTO `creature_addon` (`guid`, `path_id`, `mount`, `bytes1`, `bytes2`, `emote`, `auras`) VALUES 
(@CGUID+0, 0, 0, 0x10000, 0x1, 0, '71312'),
(@CGUID+1, 0, 0, 0x10000, 0x1, 0, '71312'),
(@CGUID+2, 0, 0, 0x10000, 0x1, 0, '71312');

DELETE FROM `creature` WHERE `guid` BETWEEN @CGUID+0 AND @CGUID+2;
DELETE FROM `creature` WHERE `guid` BETWEEN @OLDCGUID+0 AND @OLDCGUID+2;
INSERT INTO `creature` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `spawntimesecs`, `spawndist`, `MovementType`) VALUES
(@CGUID+0, 36657, 571, 1, 1, 5630.028, 2082.906, 798.1375, 0, 120, 0, 0), -- Sunreaver War Mage (Area: 210)
(@CGUID+1, 36642, 571, 1, 1, 5630.374, 2087.88, 798.1375, 6.213372, 120, 0, 0), -- Myralion Sunblaze (Area: 210)
(@CGUID+2, 36657, 571, 1, 1, 5631.038, 2092.561, 798.1375, 6.143559, 120, 0, 0); -- Sunreaver War Mage (Area: 210)

DELETE FROM `gameobject` WHERE `guid` BETWEEN @OGUID+0 AND @OGUID+1;
DELETE FROM `gameobject` WHERE `guid` BETWEEN @OLDOGUID+0 AND @OLDOGUID+1;
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@OGUID+0, 202192, 571, 1, 1, 5628.946, 2079.644, 798.0542, 0.6457717, 0, 0, 0, 1, 120, 255, 1), -- Sunreaver Banner (Area: 210)
(@OGUID+1, 202192, 571, 1, 1, 5630.607, 2096.247, 798.0542, 5.881761, 0, 0, 0, 1, 120, 255, 1); -- Sunreaver Banner (Area: 210)
